const fs = require('fs');
const fsp = require('fs/promises');
const path = require('path');
const crypto = require('crypto');

let writeQueue = Promise.resolve();

function resolveDataDir() {
  if (process.env.NAMGEN_DM_DATA_DIR) {
    return path.resolve(process.env.NAMGEN_DM_DATA_DIR);
  }
  const cwd = process.cwd();
  const monoAppDir = path.join(cwd, 'apps', 'web');
  if (fs.existsSync(path.join(monoAppDir, 'package.json'))) {
    return path.join(monoAppDir, '.namgen-dm');
  }
  return path.join(cwd, '.namgen-dm');
}

function getVaultFilePath() {
  return path.join(resolveDataDir(), 'vault.json');
}

function getMarkdownDir() {
  return path.join(resolveDataDir(), 'markdown');
}

function slugify(str) {
  return String(str || 'campaign')
    .toLowerCase()
    .replace(/[^a-z0-9]+/g, '-')
    .replace(/^-+|-+$/g, '') || 'campaign';
}

function createId(prefix = 'id') {
  return `${prefix}_${crypto.randomBytes(4).toString('hex')}`;
}

function createStarterCampaign() {
  const now = new Date().toISOString();
  const id = 'camp_silver_marches';
  return {
    id,
    name: 'Shadows of the Silver Marches',
    setting: 'Forgotten Realms Frontier',
    partyLevelTier: 1,
    pinnedGenerators: [
      'dungeon_and_dragons-humans',
      'dungeon_and_dragons-elfs',
      'dungeon_and_dragons-dwarfs',
      'dungeon_and_dragons-tieflings',
      'places-inns',
      'places-dungeons',
      'fantasy-goblins',
      'weapons-swords',
    ],
    party: [
      { id: 'pc_1', name: 'Kaelen Thorne', player: 'Alex', classLevel: 'Fighter 3', ac: 18, maxHp: 28, hp: 28, tempHp: 0, initBonus: 2, passivePerc: 13, conditions: [] },
      { id: 'pc_2', name: 'Lyra Silverleaf', player: 'Sam', classLevel: 'Wizard 3', ac: 13, maxHp: 18, hp: 18, tempHp: 0, initBonus: 3, passivePerc: 14, conditions: [] },
      { id: 'pc_3', name: 'Bram Ironfoot', player: 'Jordan', classLevel: 'Cleric 3', ac: 17, maxHp: 24, hp: 24, tempHp: 0, initBonus: 0, passivePerc: 16, conditions: [] },
      { id: 'pc_4', name: 'Vex Nightwhisper', player: 'Casey', classLevel: 'Rogue 3', ac: 15, maxHp: 21, hp: 21, tempHp: 0, initBonus: 4, passivePerc: 15, conditions: [] },
    ],
    combat: {
      round: 1,
      turnIndex: 0,
      combatants: [],
    },
    codex: [
      {
        id: 'codex_inn_1',
        kind: 'place',
        title: 'The Copper Lantern Inn',
        subtitle: 'Tavern & Inn • Crossroads Ward',
        status: 'Visited',
        tags: ['tavern', 'hub', 'silver-marches'],
        summary: 'Warm peat hearth with birch smoke, spiced river trout stew, and loose tongues after midnight.',
        dmNotes: 'Barkeep is an ex-Harper scout who pays 15 gp for goblin ear-tallies or missing caravan manifests.',
        data: null,
        createdAt: now,
      },
      {
        id: 'codex_npc_1',
        kind: 'npc',
        title: 'Seraphina Vance',
        subtitle: 'Human Cartographer & Relic Broker',
        status: 'Ally',
        tags: ['human', 'quest-giver'],
        summary: 'Quick-witted surveyor wearing ink-stained brass spectacles; speaks in rapid clipped phrases.',
        dmNotes: 'Secretly knows the sunken watchtower vault holds an infernal ledger tying the town bailiff to smugglers.',
        data: null,
        createdAt: now,
      },
    ],
    sessionNotes: [
      {
        id: 'sess_1',
        title: 'Session 1 — The Sunken Watchtower',
        date: now.slice(0, 10),
        content: `# Session 1: The Sunken Watchtower\n\n## Party Hook\n- [[Seraphina Vance]] offered 120 gp to recover a brass astrolabe from the flooded watchtower north of [[The Copper Lantern Inn]].\n\n## Prep Reminders\n- [ ] Check Passive Perception (16 max) against goblin lookouts on the ridge.\n- [ ] Roll weather table when crossing the stone ford.\n`,
      },
    ],
    updatedAt: now,
  };
}

function createDefaultVault() {
  const starter = createStarterCampaign();
  return {
    version: 1,
    activeCampaignId: starter.id,
    campaigns: [starter],
  };
}

function renderCampaignMarkdown(campaign) {
  const lines = [];
  lines.push(`# ${campaign.name}`);
  lines.push('');
  lines.push(`- **Setting**: ${campaign.setting || 'Custom D&D Campaign'}`);
  lines.push(`- **Party Tier**: Tier ${campaign.partyLevelTier || 1}`);
  lines.push(`- **Last Updated**: ${campaign.updatedAt || new Date().toISOString()}`);
  lines.push('');

  if (Array.isArray(campaign.party) && campaign.party.length > 0) {
    lines.push('## Party Roster');
    lines.push('| Hero | Player | Class / Level | AC | Max HP | Passive Perception |');
    lines.push('| :--- | :--- | :--- | :---: | :---: | :---: |');
    for (const pc of campaign.party) {
      lines.push(`| [[${pc.name}]] | ${pc.player || '-'} | ${pc.classLevel || '-'} | ${pc.ac} | ${pc.maxHp} | ${pc.passivePerc} |`);
    }
    lines.push('');
  }

  if (Array.isArray(campaign.codex) && campaign.codex.length > 0) {
    lines.push('## Campaign Codex');
    for (const entry of campaign.codex) {
      lines.push(`### [[${entry.title}]] (${entry.kind}${entry.status ? ` — ${entry.status}` : ''})`);
      if (entry.subtitle) lines.push(`*${entry.subtitle}*`);
      if (entry.summary) lines.push('', entry.summary);
      if (entry.dmNotes) lines.push('', `> **DM Notes:** ${entry.dmNotes}`);
      if (Array.isArray(entry.tags) && entry.tags.length > 0) {
        lines.push('', `Tags: ${entry.tags.map((t) => `\`#${t}\``).join(' ')}`);
      }
      lines.push('');
    }
  }

  if (Array.isArray(campaign.sessionNotes) && campaign.sessionNotes.length > 0) {
    lines.push('## Session Journal');
    for (const note of campaign.sessionNotes) {
      lines.push(`### ${note.title} (${note.date || ''})`);
      lines.push('');
      lines.push(note.content || '');
      lines.push('');
    }
  }

  return lines.join('\n');
}

async function atomicWriteFile(targetPath, content) {
  await fsp.mkdir(path.dirname(targetPath), { recursive: true });
  const tmpPath = `${targetPath}.${crypto.randomBytes(4).toString('hex')}.tmp`;
  await fsp.writeFile(tmpPath, content, 'utf8');
  await fsp.rename(tmpPath, targetPath);
}

async function syncCampaignMarkdown(campaign) {
  const mdDir = getMarkdownDir();
  const filename = `${slugify(campaign.name)}-${campaign.id}.md`;
  const mdPath = path.join(mdDir, filename);
  await atomicWriteFile(mdPath, renderCampaignMarkdown(campaign));
  return mdPath;
}

async function readVaultUnsafe() {
  const vaultFile = getVaultFilePath();
  if (!fs.existsSync(vaultFile)) {
    const initial = createDefaultVault();
    await atomicWriteFile(vaultFile, JSON.stringify(initial, null, 2));
    for (const c of initial.campaigns) {
      await syncCampaignMarkdown(c);
    }
    return initial;
  }
  const raw = await fsp.readFile(vaultFile, 'utf8');
  const parsed = JSON.parse(raw);
  if (!parsed || !Array.isArray(parsed.campaigns) || parsed.campaigns.length === 0) {
    const fallback = createDefaultVault();
    await atomicWriteFile(vaultFile, JSON.stringify(fallback, null, 2));
    return fallback;
  }
  return parsed;
}

async function writeVaultUnsafe(vault) {
  const vaultFile = getVaultFilePath();
  await atomicWriteFile(vaultFile, JSON.stringify(vault, null, 2));
}

function withWriteLock(fn) {
  const next = writeQueue.then(fn, fn);
  writeQueue = next.catch(() => {});
  return next;
}

async function getVault() {
  return withWriteLock(async () => readVaultUnsafe());
}

function getVaultInfo() {
  return {
    dataDir: resolveDataDir(),
    vaultFile: getVaultFilePath(),
    markdownDir: getMarkdownDir(),
  };
}

async function createCampaign({ name, setting = 'Custom D&D 5e Realm', partyLevelTier = 1 }) {
  return withWriteLock(async () => {
    const vault = await readVaultUnsafe();
    const now = new Date().toISOString();
    const campaign = {
      id: createId('camp'),
      name: String(name || 'Untitled Campaign').trim() || 'Untitled Campaign',
      setting: String(setting || 'Custom D&D 5e Realm').trim(),
      partyLevelTier: Number(partyLevelTier) || 1,
      pinnedGenerators: [
        'dungeon_and_dragons-humans',
        'dungeon_and_dragons-elfs',
        'dungeon_and_dragons-dwarfs',
        'places-inns',
        'places-dungeons',
        'fantasy-goblins',
      ],
      party: [],
      combat: { round: 1, turnIndex: 0, combatants: [] },
      codex: [],
      sessionNotes: [
        {
          id: createId('sess'),
          title: 'Session 1 Notes',
          date: now.slice(0, 10),
          content: `# Session 1 — ${String(name || 'Campaign Start').trim()}\n\n## Opening Scene\n- \n`,
        },
      ],
      updatedAt: now,
    };
    vault.campaigns.push(campaign);
    vault.activeCampaignId = campaign.id;
    await writeVaultUnsafe(vault);
    await syncCampaignMarkdown(campaign);
    return vault;
  });
}

async function saveCampaign(updatedCampaign) {
  return withWriteLock(async () => {
    const vault = await readVaultUnsafe();
    const idx = vault.campaigns.findIndex((c) => c.id === updatedCampaign.id);
    const stamped = {
      ...updatedCampaign,
      updatedAt: new Date().toISOString(),
    };
    if (idx >= 0) {
      vault.campaigns[idx] = stamped;
    } else {
      vault.campaigns.push(stamped);
    }
    vault.activeCampaignId = stamped.id;
    await writeVaultUnsafe(vault);
    await syncCampaignMarkdown(stamped);
    return vault;
  });
}

async function setActiveCampaign(campaignId) {
  return withWriteLock(async () => {
    const vault = await readVaultUnsafe();
    if (vault.campaigns.some((c) => c.id === campaignId)) {
      vault.activeCampaignId = campaignId;
      await writeVaultUnsafe(vault);
    }
    return vault;
  });
}

async function deleteCampaign(campaignId) {
  return withWriteLock(async () => {
    const vault = await readVaultUnsafe();
    if (vault.campaigns.length <= 1) {
      throw new Error('Cannot delete the only remaining campaign.');
    }
    vault.campaigns = vault.campaigns.filter((c) => c.id !== campaignId);
    if (vault.activeCampaignId === campaignId) {
      vault.activeCampaignId = vault.campaigns[0].id;
    }
    await writeVaultUnsafe(vault);
    return vault;
  });
}

async function getCampaignById(campaignId) {
  const vault = await getVault();
  return vault.campaigns.find((c) => c.id === campaignId) || null;
}

const MASKED_SECRET = '••••••••';

const DEFAULT_SETTINGS = {
  provider: 'ollama',
  baseUrl: 'http://127.0.0.1:11434',
  model: '',
  apiKey: '',
  customHeaders: {},
  temperature: 0.75,
  numCtx: 8192,
  githubToken: '',
  usptoCsvPath: '',
  preferCppBinary: true,
};

function getSettingsFilePath() {
  return path.join(resolveDataDir(), 'settings.json');
}

function getOracleRunsDir() {
  return path.join(resolveDataDir(), 'oracle-runs');
}

function sanitizeSettings(raw) {
  const s = raw && typeof raw === 'object' ? raw : {};
  return {
    provider: s.provider === 'openai' ? 'openai' : 'ollama',
    baseUrl: String(s.baseUrl || DEFAULT_SETTINGS.baseUrl).trim().replace(/\/+$/, ''),
    model: String(s.model || '').trim(),
    apiKey: String(s.apiKey || ''),
    customHeaders: s.customHeaders && typeof s.customHeaders === 'object' && !Array.isArray(s.customHeaders)
      ? s.customHeaders
      : {},
    temperature: Number.isFinite(Number(s.temperature))
      ? Math.max(0, Math.min(2, Number(s.temperature)))
      : DEFAULT_SETTINGS.temperature,
    numCtx: Number.isFinite(Number(s.numCtx))
      ? Math.max(512, Math.min(131072, Math.round(Number(s.numCtx))))
      : DEFAULT_SETTINGS.numCtx,
    githubToken: String(s.githubToken || '').trim(),
    usptoCsvPath: String(s.usptoCsvPath || '').trim(),
    preferCppBinary: s.preferCppBinary !== undefined ? Boolean(s.preferCppBinary) : true,
  };
}

async function readSettingsUnsafe() {
  const filePath = getSettingsFilePath();
  if (!fs.existsSync(filePath)) {
    return { ...DEFAULT_SETTINGS };
  }
  try {
    const raw = await fsp.readFile(filePath, 'utf8');
    return sanitizeSettings(JSON.parse(raw));
  } catch {
    return { ...DEFAULT_SETTINGS };
  }
}

async function getSettings() {
  return withWriteLock(async () => readSettingsUnsafe());
}

async function saveSettings(partial) {
  return withWriteLock(async () => {
    const current = await readSettingsUnsafe();
    const p = partial && typeof partial === 'object' ? partial : {};
    const merged = sanitizeSettings({
      ...current,
      ...p,
      apiKey: (p.apiKey === undefined || p.apiKey === MASKED_SECRET) ? current.apiKey : p.apiKey,
      githubToken: (p.githubToken === undefined || p.githubToken === MASKED_SECRET) ? current.githubToken : p.githubToken,
    });
    await atomicWriteFile(getSettingsFilePath(), JSON.stringify(merged, null, 2));
    return merged;
  });
}

function maskSettingsForClient(settings) {
  const s = sanitizeSettings(settings);
  return {
    ...s,
    apiKey: s.apiKey ? MASKED_SECRET : '',
    githubToken: s.githubToken ? MASKED_SECRET : '',
    hasApiKey: Boolean(s.apiKey),
    hasGithubToken: Boolean(s.githubToken),
    hasEnvGithubToken: Boolean(process.env.GITHUB_TOKEN),
  };
}

function safeOracleRunId(id) {
  return String(id || '').replace(/[^a-zA-Z0-9_-]/g, '');
}

async function listOracleRuns() {
  const dir = getOracleRunsDir();
  if (!fs.existsSync(dir)) return [];
  const entries = await fsp.readdir(dir);
  const runs = [];
  for (const name of entries) {
    if (!name.endsWith('.json')) continue;
    try {
      const raw = await fsp.readFile(path.join(dir, name), 'utf8');
      const data = JSON.parse(raw);
      runs.push({
        id: data.id,
        title: data.title || 'Untitled Oracle Scan',
        pitch: data.pitch || '',
        createdAt: data.createdAt || '',
        totalCandidates: data.stats?.total ?? (data.results?.length || 0),
        cleanSweepCount: data.stats?.cleanSweep ?? 0,
        highScoreCount: data.stats?.highScore ?? 0,
        topSurvivors: (data.results || []).slice(0, 5).map((r) => ({
          name: r.name,
          score: r.score,
          archetype: r.archetype,
        })),
      });
    } catch {}
  }
  runs.sort((a, b) => String(b.createdAt).localeCompare(String(a.createdAt)));
  return runs;
}

async function getOracleRun(id) {
  const safeId = safeOracleRunId(id);
  if (!safeId) return null;
  const target = path.join(getOracleRunsDir(), `${safeId}.json`);
  if (!fs.existsSync(target)) return null;
  try {
    const raw = await fsp.readFile(target, 'utf8');
    return JSON.parse(raw);
  } catch {
    return null;
  }
}

async function saveOracleRun(runObj) {
  return withWriteLock(async () => {
    const dir = getOracleRunsDir();
    await fsp.mkdir(dir, { recursive: true });
    const id = safeOracleRunId(runObj?.id) || createId('oracle');
    const payload = {
      ...runObj,
      id,
      createdAt: runObj?.createdAt || new Date().toISOString(),
    };
    await atomicWriteFile(path.join(dir, `${id}.json`), JSON.stringify(payload, null, 2));
    return payload;
  });
}

async function deleteOracleRun(id) {
  return withWriteLock(async () => {
    const safeId = safeOracleRunId(id);
    if (!safeId) return false;
    const target = path.join(getOracleRunsDir(), `${safeId}.json`);
    if (!fs.existsSync(target)) return false;
    await fsp.unlink(target);
    return true;
  });
}

module.exports = {
  getVault,
  getVaultInfo,
  createCampaign,
  saveCampaign,
  setActiveCampaign,
  deleteCampaign,
  getCampaignById,
  renderCampaignMarkdown,
  slugify,
  MASKED_SECRET,
  DEFAULT_SETTINGS,
  getSettings,
  saveSettings,
  maskSettingsForClient,
  listOracleRuns,
  getOracleRun,
  saveOracleRun,
  deleteOracleRun,
};
