package namgen

import (
	"strings"
	"testing"
)

func TestGenerateStandard(t *testing.T) {
	names, err := Generate("", Options{Count: 3})
	if err != nil {
		t.Fatalf("Generate failed: %v", err)
	}
	if len(names) != 3 {
		t.Fatalf("expected 3 names, got %d", len(names))
	}
}

func TestGenerateDragons(t *testing.T) {
	seed := int64(12345)
	names, err := Generate("fantasy-dragons", Options{Count: 2, Seed: &seed})
	if err != nil {
		t.Fatalf("Generate failed: %v", err)
	}
	if len(names) != 2 {
		t.Fatalf("expected 2 names, got %d", len(names))
	}
	if names[0] != "Rthyin" {
		t.Errorf("expected 'Rthyin', got %s", names[0])
	}
}

func TestGenerateRegexMatch(t *testing.T) {
	names, err := Generate("fantasy-dragons", Options{Count: 3, Match: "^[A-Z][a-z]+th$"})
	if err != nil {
		t.Fatalf("Generate failed: %v", err)
	}
	for _, n := range names {
		if !strings.HasSuffix(n, "th") {
			t.Errorf("expected name ending with 'th', got: %s", n)
		}
	}
}

func TestGenerateCompose(t *testing.T) {
	names, err := Generate("", Options{
		Count:    2,
		Compose:  "fantasy-dragons,places-castles",
		Template: "{1} of {2}",
	})
	if err != nil {
		t.Fatalf("Generate failed: %v", err)
	}
	for _, n := range names {
		if !strings.Contains(n, " of ") {
			t.Errorf("expected composed name with ' of ', got: %s", n)
		}
	}
}
