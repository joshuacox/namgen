# namgen-go

Official Go client bindings for `namgen`, the fast fantasy and sci-fi name generator.

## Installation

```bash
go get github.com/joshuacox/namgen/go
```

## Usage

```go
package main

import (
	"fmt"
	"log"

	"github.com/joshuacox/namgen/go"
)

func main() {
	// Simple standard generator
	names, err := namgen.Generate(namgen.Options{
		Count: 5,
	})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Names:", names)

	// Specialized generator with regex filtering
	dragons, err := namgen.Generate(namgen.Options{
		Generator: "dragons",
		Count:     3,
		Match:     "^Dr.*",
	})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Dragon names:", dragons)

	// Name composition
	composed, err := namgen.Generate(namgen.Options{
		Compose: []string{"fantasy-dwarves", "fantasy-elves"},
		Count:   2,
	})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Composed names:", composed)
}
```

## Binary Resolution

The Go package automatically looks for the `namgen` executable in:
1. Custom path set via `namgen.SetBinaryPath("/path/to/namgen")`
2. `./namgen` or `../namgen`
3. Current system `PATH`
4. Node.js fallback via `wasm/namgen-cli.js`
