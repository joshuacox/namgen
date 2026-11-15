#!/usr/bin/env python3
"""
Namespace & Registry Availability Checker (Zero Third-Party Dependencies)

Two-stage cross-filtering pipeline for candidate product/game names:
  Stage 1 (All candidates):
    1. DNS delegation (.com, .io, .dev, .org via Google / Cloudflare DoH NS lookup)
    2. Domain registry availability (IANA RDAP + Identity Digital RDAP + port-43 WHOIS fallback)
    3. GitHub global account/org handle + reserved-route verification
    4. Package registries: NPM, PyPI (PEP 503), and Crates.io (Cargo CDN Sparse Index RFC 2789)
    5. Optional offline USPTO bulk CSV scan (--uspto-csv)

  Stage 2 (Top namespace survivors, configurable via --store-limit):
    6. Commercial game/software title collision checks on Steam Store & Apple App Store
"""

from __future__ import annotations

import argparse
import concurrent.futures
import csv
import json
import os
import re
import socket
import sys
import threading
import time
import urllib.error
import urllib.parse
import urllib.request
from dataclasses import asdict, dataclass, field
from pathlib import Path

USER_AGENT = os.environ.get(
    "NAME_CHECKER_UA",
    "deckmoba-namespace-checker/1.1 (local-cli; +https://iana.org)",
)

DEFAULT_TLDS = ("com", "io", "dev", "org")

WHOIS_SERVERS: dict[str, str] = {
    "com": "whois.verisign-grs.com",
    "org": "whois.pir.org",
    "dev": "whois.nic.google",
    "io": "whois.nic.io",
}

WHOIS_NOT_FOUND_PATTERNS = re.compile(
    r"(no match for|not found|domain not found|no entries found|"
    r"no data found|status:\s*free|status:\s*available|is available for registration)",
    re.IGNORECASE,
)

DEFAULT_CANDIDATES: list[tuple[str, str, str]] = [
    ("Hexgrid", "Arcane/Cyberpunk", "/HEKS-grid/"),
    ("Sigilcast", "Arcane/Cyberpunk", "/SIJ-il-kast/"),
    ("Neonpakt", "Arcane/Cyberpunk", "/NEE-on-pakt/"),
    ("Runeframe", "Arcane/Cyberpunk", "/ROON-fraym/"),
    ("Voidstack", "Arcane/Cyberpunk", "/VOYD-stak/"),
    ("Bellumancy", "Classical Etymology", "/BEL-uh-man-see/"),
    ("Animacraft", "Classical Etymology", "/AN-ih-muh-kraft/"),
    ("Locuspact", "Classical Etymology", "/LOH-kus-pakt/"),
    ("Mytharch", "Classical Etymology", "/MITH-ark/"),
    ("Aegisdeck", "Classical Etymology", "/EE-jis-dek/"),
    ("Deckbrawl", "Punchy Portmanteaus", "/DEK-brawl/"),
    ("Managerie", "Punchy Portmanteaus", "/muh-NAJ-uh-ree/"),
    ("Mobadeck", "Punchy Portmanteaus", "/MOH-buh-dek/"),
    ("Spellclash", "Punchy Portmanteaus", "/SPEL-klash/"),
    ("Summonrift", "Punchy Portmanteaus", "/SUM-un-rift/"),
    ("Draftlane", "Functional Minimalist", "/DRAFT-layn/"),
    ("Cardrift", "Functional Minimalist", "/KARD-rift/"),
    ("Deckarena", "Functional Minimalist", "/DEK-uh-ree-nuh/"),
    ("Pactline", "Functional Minimalist", "/PAKT-lyn/"),
    ("Castlane", "Functional Minimalist", "/KAST-layn/"),
    ("Vexora", "Sovereign Neologisms", "/vek-SOR-uh/"),
    ("Kaelith", "Sovereign Neologisms", "/KAY-lith/"),
    ("Zynthar", "Sovereign Neologisms", "/ZIN-thar/"),
    ("Orvaxis", "Sovereign Neologisms", "/or-VAK-sis/"),
    ("Thalorix", "Sovereign Neologisms", "/THAL-uh-riks/"),
]


class HostRateLimiter:
    """Thread-safe per-host minimum-interval rate limiter to avoid 429/403 blocks."""

    def __init__(self, intervals: dict[str, float], default_interval: float = 0.06) -> None:
        self._intervals = intervals
        self._default = default_interval
        self._locks: dict[str, threading.Lock] = {}
        self._last_call: dict[str, float] = {}
        self._global_lock = threading.Lock()

    def wait(self, host_key: str) -> None:
        with self._global_lock:
            lock = self._locks.setdefault(host_key, threading.Lock())
            min_interval = self._intervals.get(host_key, self._default)
        with lock:
            now = time.monotonic()
            elapsed = now - self._last_call.get(host_key, 0.0)
            if elapsed < min_interval:
                time.sleep(min_interval - elapsed)
            self._last_call[host_key] = time.monotonic()


RATE_LIMITER = HostRateLimiter(
    {
        "crates.io": 1.05,  # Fallback API only; primary uses index.crates.io CDN
        "index.crates.io": 0.04,
        "registry.npmjs.org": 0.04,
        "pypi.org": 0.04,
        "dns.google": 0.02,
        "cloudflare-dns.com": 0.02,
        "rdap.verisign.com": 0.08,
        "rdap.identitydigital.services": 0.08,
        "pubapi.registry.google": 0.08,
        "rdap.publicinterestregistry.org": 0.08,
        "api.github.com": 0.15,
        "github.com": 0.08,
        "whois.verisign-grs.com": 0.5,
        "whois.nic.io": 0.6,
        "whois.nic.google": 0.5,
        "whois.pir.org": 0.5,
        "store.steampowered.com": 0.25,
        "itunes.apple.com": 0.45,
    },
    default_interval=0.06,
)

_GITHUB_REST_LOCK = threading.Lock()
_GITHUB_REST_EXHAUSTED = False


@dataclass
class DomainStatus:
    tld: str
    dns_status: str  # NXDOMAIN | DELEGATED | NOERROR_NO_NS | SERVFAIL | ERROR
    registry_status: str  # AVAILABLE | TAKEN | UNKNOWN
    available: bool | None  # True, False, or None if indeterminate
    detail: str = ""


@dataclass
class CandidateReport:
    name: str
    slug: str
    archetype: str
    syllables: int
    pronunciation: str
    domains: dict[str, DomainStatus] = field(default_factory=dict)
    github_handle: str = "UNKNOWN"
    github_exact_repos: int | None = None
    npm: str = "UNKNOWN"
    pypi: str = "UNKNOWN"
    crates: str = "UNKNOWN"
    stores_checked: bool = False
    steam_exact_hits: list[str] = field(default_factory=list)
    appstore_exact_hits: list[str] = field(default_factory=list)
    uspto_csv_hits: list[str] = field(default_factory=list)
    score: float = 0.0
    tm_signal: str = "UNCHECKED"
    recommendation: str = ""


def normalize_slug(name: str) -> str:
    cleaned = re.sub(r"[^a-z0-9-]+", "-", name.strip().lower()).strip("-")
    return re.sub(r"-{2,}", "-", cleaned)


def compact_alnum(name: str) -> str:
    return re.sub(r"[^a-z0-9]+", "", name.lower())


def estimate_syllables(word: str) -> int:
    w = re.sub(r"[^a-z]", "", word.lower())
    if not w:
        return 1
    if len(w) <= 3:
        return 1
    w = re.sub(r"(?:[^laeiouy]es|ed|[^laeiouy]e)$", "", w)
    w = re.sub(r"^y", "", w)
    groups = re.findall(r"[aeiouy]{1,2}", w)
    return max(1, len(groups))


def generate_pronunciation_sigil(name: str) -> str:
    """Heuristic phonetic respelling sigil when none is supplied in input."""
    w = re.sub(r"[^a-zA-Z]", "", name).lower()
    if not w:
        return f"/{name}/"
    # Split into rough pronounceable chunks around vowel nuclei
    parts = re.findall(r"[^aeiouy]*[aeiouy]+(?:[^aeiouy](?=[^aeiouy]|$))?[^aeiouy]*", w)
    if not parts:
        return f"/{w.upper()}/"
    styled = [parts[0].upper()] + [p.lower() for p in parts[1:]]
    return "/" + "-".join(styled) + "/"


def http_get(
    url: str,
    headers: dict[str, str] | None = None,
    timeout: float = 8.0,
    method: str = "GET",
) -> tuple[int, bytes, dict[str, str]]:
    parsed = urllib.parse.urlparse(url)
    RATE_LIMITER.wait(parsed.netloc)

    req_headers = {"User-Agent": USER_AGENT}
    if headers:
        req_headers.update(headers)

    req = urllib.request.Request(url, headers=req_headers, method=method)
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            body = b"" if method == "HEAD" else resp.read(262_144)
            return resp.status, body, {k.lower(): v for k, v in resp.headers.items()}
    except urllib.error.HTTPError as exc:
        body = b""
        try:
            if method != "HEAD" and exc.fp:
                body = exc.fp.read(65_536)
        except Exception:
            pass
        hdrs = {k.lower(): v for k, v in exc.headers.items()} if exc.headers else {}
        return exc.code, body, hdrs
    except Exception:
        return 0, b"", {}


def load_iana_rdap_bootstrap() -> dict[str, str]:
    """Fetch IANA RFC 9224 RDAP bootstrap + verified registry RDAP endpoints."""
    mapping: dict[str, str] = {
        "com": "https://rdap.verisign.com/com/v1",
        "io": "https://rdap.identitydigital.services/rdap",
        "org": "https://rdap.publicinterestregistry.org/rdap",
        "dev": "https://pubapi.registry.google/rdap",
    }
    status, body, _ = http_get("https://data.iana.org/rdap/dns.json", timeout=8.0)
    if status == 200 and body:
        try:
            data = json.loads(body.decode("utf-8", errors="replace"))
            for entry in data.get("services", []):
                if len(entry) >= 2 and entry[1]:
                    base_url = entry[1][0].rstrip("/")
                    for tld in entry[0]:
                        mapping[tld.lower()] = base_url
        except Exception:
            pass
    return mapping


def discover_whois_server(tld: str) -> str | None:
    if tld in WHOIS_SERVERS:
        return WHOIS_SERVERS[tld]
    try:
        RATE_LIMITER.wait("whois.iana.org")
        with socket.create_connection(("whois.iana.org", 43), timeout=6.0) as sock:
            sock.sendall(f"{tld}\r\n".encode("ascii"))
            chunks: list[bytes] = []
            while chunk := sock.recv(4096):
                chunks.append(chunk)
        text = b"".join(chunks).decode("utf-8", errors="replace")
        m = re.search(r"^whois:\s*(\S+)", text, re.MULTILINE | re.IGNORECASE)
        if m:
            WHOIS_SERVERS[tld] = m.group(1).strip()
            return WHOIS_SERVERS[tld]
    except Exception:
        pass
    return None


def query_whois_port43(domain: str, tld: str) -> tuple[str, str]:
    server = discover_whois_server(tld)
    if not server:
        return "UNKNOWN", "no-whois-server"
    RATE_LIMITER.wait(server)
    query = f"domain {domain}\r\n" if server == "whois.verisign-grs.com" else f"{domain}\r\n"
    try:
        with socket.create_connection((server, 43), timeout=7.0) as sock:
            sock.sendall(query.encode("ascii", errors="ignore"))
            chunks: list[bytes] = []
            total = 0
            while total < 32_768:
                chunk = sock.recv(4096)
                if not chunk:
                    break
                chunks.append(chunk)
                total += len(chunk)
        resp = b"".join(chunks).decode("utf-8", errors="replace")
        if not resp.strip():
            return "UNKNOWN", "empty-whois"
        if re.search(r"(rate limit|exceeded|try again later|quota)", resp, re.IGNORECASE):
            return "UNKNOWN", "whois-rate-limited"
        if WHOIS_NOT_FOUND_PATTERNS.search(resp):
            return "AVAILABLE", f"whois:{server}:not-found"
        if re.search(r"(domain name:|registrar:|creation date:|registry domain id:)", resp, re.IGNORECASE):
            return "TAKEN", f"whois:{server}:registered"
        return "UNKNOWN", f"whois:{server}:ambiguous"
    except Exception as exc:
        return "UNKNOWN", f"whois-err:{type(exc).__name__}"


def check_dns_doh(domain: str) -> str:
    q = urllib.parse.quote(domain)
    endpoints = [
        (f"https://dns.google/resolve?name={q}&type=NS", {}),
        (f"https://cloudflare-dns.com/dns-query?name={q}&type=NS", {"Accept": "application/dns-json"}),
    ]
    for url, hdrs in endpoints:
        status, body, _ = http_get(url, headers=hdrs, timeout=6.0)
        if status == 200 and body:
            try:
                data = json.loads(body.decode("utf-8", errors="replace"))
                rcode = data.get("Status")
                if rcode == 3:
                    return "NXDOMAIN"
                if rcode == 0:
                    if data.get("Answer"):
                        return "DELEGATED"
                    return "NOERROR_NO_NS"
                if rcode == 2:
                    return "SERVFAIL"
            except Exception:
                continue
    return "ERROR"


def check_domain(slug: str, tld: str, rdap_map: dict[str, str]) -> DomainStatus:
    domain = f"{slug}.{tld}"
    dns_state = check_dns_doh(domain)

    if dns_state == "DELEGATED":
        return DomainStatus(
            tld=tld,
            dns_status=dns_state,
            registry_status="TAKEN",
            available=False,
            detail="Active NS delegation",
        )

    reg_status = "UNKNOWN"
    detail = ""
    rdap_base = rdap_map.get(tld)
    if rdap_base:
        rdap_url = f"{rdap_base}/domain/{urllib.parse.quote(domain)}"
        code, _, _ = http_get(rdap_url, headers={"Accept": "application/rdap+json, application/json"})
        if code == 200:
            reg_status, detail = "TAKEN", "RDAP 200"
        elif code == 404:
            reg_status, detail = "AVAILABLE", "RDAP 404"
        else:
            detail = f"RDAP {code}"

    if reg_status == "UNKNOWN":
        reg_status, whois_detail = query_whois_port43(domain, tld)
        detail = f"{detail}; {whois_detail}".strip("; ")

    if reg_status == "TAKEN" or dns_state == "SERVFAIL":
        avail: bool | None = False
    elif reg_status == "AVAILABLE" and dns_state in ("NXDOMAIN", "NOERROR_NO_NS"):
        avail = True
    else:
        avail = None

    return DomainStatus(
        tld=tld,
        dns_status=dns_state,
        registry_status=reg_status,
        available=avail,
        detail=detail,
    )


def check_github(slug: str, github_token: str | None, search_repos: bool = False) -> tuple[str, int | None]:
    global _GITHUB_REST_EXHAUSTED
    api_headers = {"Accept": "application/vnd.github+json"}
    if github_token:
        api_headers["Authorization"] = f"Bearer {github_token}"

    handle_state = "UNKNOWN"
    use_rest = bool(github_token) or not _GITHUB_REST_EXHAUSTED

    if use_rest:
        code, body, hdrs = http_get(f"https://api.github.com/users/{urllib.parse.quote(slug)}", headers=api_headers)
        if code == 200:
            acct_type = "Account"
            try:
                acct_type = json.loads(body.decode("utf-8", errors="replace")).get("type", "Account")
            except Exception:
                pass
            handle_state = f"TAKEN:{acct_type}"
        elif code == 404:
            web_code, _, _ = http_get(
                f"https://github.com/{urllib.parse.quote(slug)}",
                headers={"User-Agent": "Mozilla/5.0"},
                method="HEAD",
            )
            if web_code == 404:
                handle_state = "AVAILABLE"
            elif web_code == 200:
                handle_state = "RESERVED"
            else:
                handle_state = "AVAILABLE?"
        elif code in (403, 429):
            if not github_token and hdrs.get("x-ratelimit-remaining") == "0":
                with _GITHUB_REST_LOCK:
                    _GITHUB_REST_EXHAUSTED = True

    if handle_state == "UNKNOWN":
        web_code, _, _ = http_get(
            f"https://github.com/{urllib.parse.quote(slug)}",
            headers={"User-Agent": "Mozilla/5.0"},
            method="HEAD",
        )
        if web_code == 404:
            handle_state = "AVAILABLE"
        elif web_code == 200:
            handle_state = "TAKEN"
        else:
            handle_state = f"UNKNOWN({web_code})"

    exact_repos: int | None = None
    if search_repos and (bool(github_token) or not _GITHUB_REST_EXHAUSTED):
        q = urllib.parse.quote(f"{slug} in:name")
        s_code, s_body, _ = http_get(
            f"https://api.github.com/search/repositories?q={q}&per_page=20",
            headers=api_headers,
        )
        if s_code == 200 and s_body:
            try:
                items = json.loads(s_body.decode("utf-8", errors="replace")).get("items", [])
                target = compact_alnum(slug)
                exact_repos = sum(1 for it in items if compact_alnum(it.get("name", "")) == target)
            except Exception:
                pass

    return handle_state, exact_repos


def check_npm(slug: str) -> str:
    code, _, _ = http_get(
        f"https://registry.npmjs.org/{urllib.parse.quote(slug)}",
        headers={"Accept": "application/vnd.npm.install-v1+json"},
    )
    if code == 404:
        return "AVAILABLE"
    if code == 200:
        return "TAKEN"
    return f"UNKNOWN({code})"


def check_pypi(slug: str) -> str:
    pep503 = re.sub(r"[-_.]+", "-", slug).lower()
    code, _, _ = http_get(f"https://pypi.org/pypi/{urllib.parse.quote(pep503)}/json")
    if code == 404:
        return "AVAILABLE"
    if code == 200:
        return "TAKEN"
    return f"UNKNOWN({code})"


def _sparse_crate_path(crate_name: str) -> str:
    n = crate_name.lower()
    if len(n) == 1:
        return f"1/{n}"
    if len(n) == 2:
        return f"2/{n}"
    if len(n) == 3:
        return f"3/{n[0]}/{n}"
    return f"{n[:2]}/{n[2:4]}/{n}"


def check_crates(slug: str) -> str:
    """Query Crates.io via RFC 2789 CDN sparse index (checking both '-' and '_' variants)."""
    variants = {slug.lower(), slug.lower().replace("-", "_"), slug.lower().replace("_", "-")}
    saw_404 = False
    for var in variants:
        path = _sparse_crate_path(var)
        code, _, _ = http_get(f"https://index.crates.io/{path}", method="HEAD")
        if code == 200:
            return "TAKEN"
        if code == 404:
            saw_404 = True
    if saw_404:
        return "AVAILABLE"

    # Fallback to Crates.io REST API if CDN check failed
    code, _, _ = http_get(f"https://crates.io/api/v1/crates/{urllib.parse.quote(slug)}")
    if code == 404:
        return "AVAILABLE"
    if code == 200:
        return "TAKEN"
    return f"UNKNOWN({code})"


def check_steam_store(name: str) -> list[str]:
    q = urllib.parse.quote(name)
    code, body, _ = http_get(f"https://store.steampowered.com/api/storesearch/?term={q}&l=english&cc=US")
    hits: list[str] = []
    if code == 200 and body:
        try:
            items = json.loads(body.decode("utf-8", errors="replace")).get("items", [])
            target = compact_alnum(name)
            for item in items:
                title = item.get("name", "")
                comp = compact_alnum(title)
                if comp == target or comp.startswith(target):
                    hits.append(title)
        except Exception:
            pass
    return hits[:3]


def check_apple_appstore(name: str) -> list[str]:
    q = urllib.parse.quote(name)
    code, body, _ = http_get(f"https://itunes.apple.com/search?term={q}&entity=software&country=US&limit=10")
    hits: list[str] = []
    if code == 200 and body:
        try:
            results = json.loads(body.decode("utf-8", errors="replace")).get("results", [])
            target = compact_alnum(name)
            for item in results:
                title = item.get("trackName", "")
                primary = re.split(r"[:\-–—]", title)[0]
                if compact_alnum(primary) == target or compact_alnum(title) == target:
                    hits.append(title)
        except Exception:
            pass
    return hits[:3]


def scan_uspto_bulk_csv(csv_path: Path, candidates: list[tuple[str, str, str]]) -> dict[str, list[str]]:
    targets = {compact_alnum(name): name for name, _, _ in candidates}
    matches: dict[str, list[str]] = {name: [] for name, _, _ in candidates}
    if not csv_path.is_file():
        print(f"[warn] USPTO CSV file not found: {csv_path}", file=sys.stderr)
        return matches

    print(f"[info] Scanning local USPTO bulk CSV: {csv_path} ...", file=sys.stderr)
    with csv_path.open("r", encoding="utf-8", errors="replace", newline="") as fh:
        reader = csv.DictReader(fh)
        for row in reader:
            mark = (
                row.get("mark_id_char")
                or row.get("mark_identification")
                or row.get("word_mark")
                or ""
            ).strip()
            if not mark:
                continue
            comp = compact_alnum(mark)
            if comp in targets:
                cand_name = targets[comp]
                if len(matches[cand_name]) < 5:
                    serial = row.get("serial_no") or row.get("serial_number") or "?"
                    matches[cand_name].append(f"{mark} (SN:{serial})")
    return matches


def score_and_recommend(report: CandidateReport, tlds: tuple[str, ...]) -> None:
    pts = 0.0
    tld_weights = {"com": 30.0, "io": 12.0, "dev": 10.0, "org": 8.0}
    for tld in tlds:
        w = tld_weights.get(tld, 8.0)
        ds = report.domains.get(tld)
        if ds and ds.available is True:
            pts += w
        elif ds and ds.available is None:
            pts += w * 0.25

    if report.github_handle.startswith("AVAILABLE"):
        pts += 15.0
    if report.npm == "AVAILABLE":
        pts += 5.0
    if report.pypi == "AVAILABLE":
        pts += 5.0
    if report.crates == "AVAILABLE":
        pts += 5.0

    market_hits = len(report.steam_exact_hits) + len(report.appstore_exact_hits) + len(report.uspto_csv_hits)
    if report.uspto_csv_hits:
        pts -= 25.0
        report.tm_signal = f"HIGH_RISK ({report.uspto_csv_hits[0]})"
    elif market_hits > 0:
        pts -= min(15.0, market_hits * 7.5)
        sample = (report.steam_exact_hits + report.appstore_exact_hits)[0]
        report.tm_signal = f"COLLISION ({sample})"
    elif report.stores_checked:
        pts += 10.0
        report.tm_signal = "CLEAR_PROXY (verify USPTO/WIPO)"
    else:
        report.tm_signal = "SKIPPED_LOW_RANK"

    report.score = round(max(0.0, min(100.0, pts)), 1)

    free_tlds = [f".{t}" for t in tlds if report.domains.get(t) and report.domains[t].available is True]
    best_tld = free_tlds[0] if free_tlds else None
    gh_rec = (
        f"github.com/{report.slug}"
        if report.github_handle.startswith("AVAILABLE")
        else f"github.com/{report.slug}-game"
    )
    dom_rec = f"{report.slug}{best_tld}" if best_tld else f"play{report.slug}.com"
    report.recommendation = f"`{dom_rec}` + `{gh_rec}`"


def evaluate_stage1(
    name: str,
    archetype: str,
    pronunciation: str,
    tlds: tuple[str, ...],
    rdap_map: dict[str, str],
    github_token: str | None,
    search_repos: bool,
    uspto_hits: list[str],
) -> CandidateReport:
    slug = normalize_slug(name)
    sigil = pronunciation or generate_pronunciation_sigil(name)
    sigil_parts = [p for p in sigil.strip("/").split("-") if p]
    syl_count = len(sigil_parts) if pronunciation and sigil_parts else estimate_syllables(name)
    report = CandidateReport(
        name=name,
        slug=slug,
        archetype=archetype,
        syllables=syl_count,
        pronunciation=sigil,
        uspto_csv_hits=uspto_hits,
    )

    with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
        dom_futs = {tld: pool.submit(check_domain, slug, tld, rdap_map) for tld in tlds}
        gh_fut = pool.submit(check_github, slug, github_token, search_repos)
        npm_fut = pool.submit(check_npm, slug)
        pypi_fut = pool.submit(check_pypi, slug)
        crates_fut = pool.submit(check_crates, slug)

        for tld, fut in dom_futs.items():
            report.domains[tld] = fut.result()
        report.github_handle, report.github_exact_repos = gh_fut.result()
        report.npm = npm_fut.result()
        report.pypi = pypi_fut.result()
        report.crates = crates_fut.result()

    score_and_recommend(report, tlds)
    return report


def evaluate_stage2_stores(report: CandidateReport, tlds: tuple[str, ...]) -> None:
    report.steam_exact_hits = check_steam_store(report.name)
    report.appstore_exact_hits = check_apple_appstore(report.name)
    report.stores_checked = True
    score_and_recommend(report, tlds)


def fmt_flag(val: bool | None | str) -> str:
    if val is True or (isinstance(val, str) and val.startswith("AVAILABLE")):
        return "FREE"
    if val is False or (isinstance(val, str) and (val.startswith("TAKEN") or val == "RESERVED")):
        return "TAKEN"
    return "?"


def render_markdown_table(reports: list[CandidateReport], tlds: tuple[str, ...]) -> str:
    tld_headers = " | ".join(f".{t}" for t in tlds)
    lines = [
        f"| Rank | Score | Name | Lexical Archetype | Syl | Pronunciation Sigil | {tld_headers} | GitHub | NPM / PyPI / Crates | Market / TM Proxy | Sovereign GitHub/DNS Recommendation |",
        "| ---: | ----: | :--- | :--- | :-: | :--- | "
        + " | ".join(":--:" for _ in tlds)
        + " | :----: | :-----------------: | :---------------- | :---------------------------------- |",
    ]
    for idx, r in enumerate(reports, start=1):
        tld_cells = " | ".join(fmt_flag(r.domains[t].available) for t in tlds)
        pkg_cell = f"{fmt_flag(r.npm)}/{fmt_flag(r.pypi)}/{fmt_flag(r.crates)}"
        gh_cell = fmt_flag(r.github_handle)
        if r.github_exact_repos is not None:
            gh_cell += f" ({r.github_exact_repos}r)"
        lines.append(
            f"| {idx} | {r.score:.0f} | **{r.name}** | {r.archetype} | {r.syllables} | `{r.pronunciation}` | "
            f"{tld_cells} | {gh_cell} | {pkg_cell} | {r.tm_signal} | {r.recommendation} |"
        )
    return "\n".join(lines)


def load_candidates(args: argparse.Namespace) -> list[tuple[str, str, str]]:
    if args.names:
        return [(n.strip(), "Custom", generate_pronunciation_sigil(n.strip())) for n in args.names if n.strip()]
    if args.input:
        path = Path(args.input)
        rows: list[tuple[str, str, str]] = []
        with path.open("r", encoding="utf-8", newline="") as fh:
            first_line = fh.readline()
            fh.seek(0)
            if "," in first_line:
                reader = csv.reader(fh)
                for parts in reader:
                    if not parts or not parts[0].strip() or parts[0].strip().startswith("#"):
                        continue
                    if parts[0].strip().lower() == "name":
                        continue
                    name = parts[0].strip()
                    arch = parts[1].strip() if len(parts) > 1 and parts[1].strip() else "Unclassified"
                    pron = parts[2].strip() if len(parts) > 2 and parts[2].strip() else generate_pronunciation_sigil(name)
                    rows.append((name, arch, pron))
            else:
                for raw in fh:
                    line = raw.strip()
                    if line and not line.startswith("#"):
                        rows.append((line, "Unclassified", generate_pronunciation_sigil(line)))
        return rows
    return list(DEFAULT_CANDIDATES)


def main() -> int:
    parser = argparse.ArgumentParser(description="Verify candidate names across DNS, RDAP/WHOIS, GitHub, packages, and stores.")
    parser.add_argument("names", nargs="*", help="Candidate names to test (overrides default starter list).")
    parser.add_argument("-i", "--input", help="Path to TXT or CSV (name,archetype[,pronunciation]) file.")
    parser.add_argument("--tlds", default=",".join(DEFAULT_TLDS), help="Comma-separated TLDs (default: com,io,dev,org).")
    parser.add_argument("-w", "--workers", type=int, default=10, help="Concurrent candidates in Stage 1 (default: 10).")
    parser.add_argument(
        "--store-limit",
        type=int,
        default=120,
        help="Max top Stage-1 namespace survivors checked against Steam & App Store (0 = all, default: 120).",
    )
    parser.add_argument("--top", type=int, default=0, help="Limit printed/saved Markdown matrix to top N rows (0 = all).")
    parser.add_argument("--github-repo-search", action="store_true", help="Also query GitHub repository search API.")
    parser.add_argument("--uspto-csv", help="Optional path to local USPTO bulk case_file.csv for mark matching.")
    parser.add_argument("--json", dest="json_out", help="Write full structured results to JSON file.")
    parser.add_argument("--md", dest="md_out", help="Write Markdown survival matrix to file.")
    args = parser.parse_args()

    tlds = tuple(t.strip().lstrip(".").lower() for t in args.tlds.split(",") if t.strip())
    candidates = load_candidates(args)
    if not candidates:
        print("No candidates provided.", file=sys.stderr)
        return 1

    github_token = os.environ.get("GITHUB_TOKEN")
    print(f"[stage 1] Loading IANA RDAP bootstrap & checking {len(candidates)} candidate(s) across DNS/RDAP/GitHub/Packages...", file=sys.stderr)
    rdap_map = load_iana_rdap_bootstrap()
    uspto_map = (
        scan_uspto_bulk_csv(Path(args.uspto_csv), candidates)
        if args.uspto_csv
        else {name: [] for name, _, _ in candidates}
    )

    reports: list[CandidateReport] = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=max(1, args.workers)) as executor:
        future_to_name = {
            executor.submit(
                evaluate_stage1,
                name,
                archetype,
                pronunciation,
                tlds,
                rdap_map,
                github_token,
                args.github_repo_search,
                uspto_map.get(name, []),
            ): name
            for name, archetype, pronunciation in candidates
        }
        done_count = 0
        for fut in concurrent.futures.as_completed(future_to_name):
            done_count += 1
            rep = fut.result()
            reports.append(rep)
            if done_count % 50 == 0 or done_count == len(candidates) or len(candidates) <= 30:
                print(
                    f"[stage 1: {done_count}/{len(candidates)}] latest={rep.name:<16} stage1_score={rep.score:5.1f}",
                    file=sys.stderr,
                )

    # Sort after Stage 1 to select top namespace survivors for Stage 2 store checks
    reports.sort(key=lambda r: (-r.score, r.syllables, r.name.lower()))
    stage2_pool = reports if args.store_limit == 0 else reports[: args.store_limit]
    print(f"[stage 2] Checking Steam & Apple App Store software collisions for top {len(stage2_pool)} candidate(s)...", file=sys.stderr)

    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as executor:
        s2_futs = [executor.submit(evaluate_stage2_stores, rep, tlds) for rep in stage2_pool]
        s2_done = 0
        for fut in concurrent.futures.as_completed(s2_futs):
            fut.result()
            s2_done += 1
            if s2_done % 25 == 0 or s2_done == len(stage2_pool) or len(stage2_pool) <= 25:
                print(f"[stage 2: {s2_done}/{len(stage2_pool)}] store checks completed", file=sys.stderr)

    reports.sort(key=lambda r: (-r.score, r.syllables, r.name.lower()))
    display_reports = reports[: args.top] if args.top > 0 else reports
    md_table = render_markdown_table(display_reports, tlds)
    print(md_table)

    if args.md_out:
        Path(args.md_out).write_text(md_table + "\n", encoding="utf-8")
        print(f"[info] Saved Markdown report ({len(display_reports)} rows) to {args.md_out}", file=sys.stderr)

    if args.json_out:
        payload = [asdict(r) for r in reports]
        Path(args.json_out).write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
        print(f"[info] Saved JSON report ({len(reports)} total records) to {args.json_out}", file=sys.stderr)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
