# namgen-rs

Official Rust client bindings for `namgen`, the ultra-fast fantasy and sci-fi name generator library.

## Installation

Add to your `Cargo.toml`:

```toml
[dependencies]
namgen = { path = "../rust" } # Or from crates.io
```

Ensure `libnamgen.so` (Linux), `libnamgen.dylib` (macOS), or `namgen.dll` (Windows) is available in your dynamic library search path (e.g. `LD_LIBRARY_PATH=.`).

## Usage

```rust
use namgen::{generate, markov};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Generate 5 Elven names with seed determinism
    let elves = generate("fantasy-elves", 5, 42)?;
    for name in elves {
        println!("Elf: {}", name);
    }

    // Synthesize 3 novel dragon names using a character 3-gram Markov model
    let dragons = markov("fantasy-dragons", 3, 3, 42)?;
    for name in dragons {
        println!("Novel Dragon: {}", name);
    }

    Ok(())
}
```
