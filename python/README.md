# namgen (Python)

Official Python bindings and CLI wrapper for **namgen**, the fast procedural fantasy and real-world name generator with 900+ modules.

## Installation

```bash
pip install .
```

## Usage

```python
import namgen

# Standard adjective-noun combination
names = namgen.generate(count=3)
print(names)
# ['clean-thornhill', 'shady-brannigan', 'laudable-grennan']

# Specialized procedural generators
dragons = namgen.generate('fantasy-dragons', count=3)
print(dragons)

# Deterministic seeding
seed_names = namgen.generate('fantasy-dragons', count=2, seed=12345)
print(seed_names)

# Regex pattern filtering & length bounds
filtered = namgen.generate('fantasy-dragons', count=5, match=r'^[A-Z][a-z]+th$', min_len=5, max_len=8)
print(filtered)

# Composition & templates
rulers = namgen.generate(compose='fantasy-dragons,places-castles', template='{1} of {2}', count=2)
print(rulers)

# Structured JSON format
data = namgen.generate('fantasy-elfs', count=3, format='json')
print(data)
```
