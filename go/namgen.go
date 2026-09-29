package namgen

import (
	"bytes"
	"encoding/json"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strconv"
	"strings"
)

// Options configures the namgen execution parameters.
type Options struct {
	Count      int
	Seed       *int64
	Unique     bool
	Format     string
	Match      string
	MinLen     int
	MaxLen     int
	Compose    string
	Template   string
	Executable string
}

func findBinary(custom string) (string, []string, error) {
	if custom != "" {
		if _, err := os.Stat(custom); err == nil {
			return custom, nil, nil
		}
	}

	// Check relative to current working directory or binary
	localCandidates := []string{
		"./namgen",
		"../namgen",
		"../../namgen",
	}
	for _, cand := range localCandidates {
		abs, err := filepath.Abs(cand)
		if err == nil {
			if info, err := os.Stat(abs); err == nil && !info.IsDir() {
				return abs, nil, nil
			}
		}
	}

	// Check system PATH
	if p, err := exec.LookPath("namgen"); err == nil {
		return p, nil, nil
	}

	// Fallback to node wasm/namgen-cli.js
	wasmCandidates := []string{
		"./wasm/namgen-cli.js",
		"../wasm/namgen-cli.js",
		"../../wasm/namgen-cli.js",
	}
	for _, cand := range wasmCandidates {
		abs, err := filepath.Abs(cand)
		if err == nil {
			if _, err := os.Stat(abs); err == nil {
				if nodePath, err := exec.LookPath("node"); err == nil {
					return nodePath, []string{abs}, nil
				}
			}
		}
	}

	return "", nil, fmt.Errorf("namgen executable not found on PATH or in repository")
}

// Generate invokes namgen and returns a slice of generated name strings.
func Generate(generator string, opts Options) ([]string, error) {
	bin, prefixArgs, err := findBinary(opts.Executable)
	if err != nil {
		return nil, err
	}

	args := append([]string{}, prefixArgs...)

	if generator != "" {
		if strings.HasPrefix(generator, "--") {
			args = append(args, generator)
		} else {
			args = append(args, "--"+generator)
		}
	}

	if opts.Count > 0 && opts.Count != 24 {
		args = append(args, "-c", strconv.Itoa(opts.Count))
	}

	if opts.Seed != nil {
		args = append(args, "-S", strconv.FormatInt(*opts.Seed, 10))
	}

	if opts.Unique {
		args = append(args, "-u")
	}

	if opts.Match != "" {
		args = append(args, "-m", opts.Match)
	}

	if opts.MinLen > 0 {
		args = append(args, "--min-len", strconv.Itoa(opts.MinLen))
	}

	if opts.MaxLen > 0 {
		args = append(args, "--max-len", strconv.Itoa(opts.MaxLen))
	}

	if opts.Compose != "" {
		args = append(args, "--compose", opts.Compose)
	}

	if opts.Template != "" {
		args = append(args, "--template", opts.Template)
	}

	if opts.Format == "json" {
		args = append(args, "--json")
	} else if opts.Format == "csv" {
		args = append(args, "--csv")
	} else if opts.Format == "slug" {
		args = append(args, "--slug")
	}

	cmd := exec.Command(bin, args...)
	var stdout, stderr bytes.Buffer
	cmd.Stdout = &stdout
	cmd.Stderr = &stderr

	if err := cmd.Run(); err != nil {
		return nil, fmt.Errorf("namgen execution error: %v (stderr: %s)", err, stderr.String())
	}

	output := strings.TrimSpace(stdout.String())
	if opts.Format == "json" {
		var list []string
		if err := json.Unmarshal([]byte(output), &list); err != nil {
			return nil, fmt.Errorf("failed to parse json output: %v", err)
		}
		return list, nil
	}

	var names []string
	for _, line := range strings.Split(output, "\n") {
		trimmed := strings.TrimSpace(line)
		if trimmed != "" {
			names = append(names, trimmed)
		}
	}
	return names, nil
}
