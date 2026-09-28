#!/usr/bin/env python3
import subprocess
import json
import re
import os
from concurrent.futures import ThreadPoolExecutor

CATEGORY_METADATA = {
    'real': {'name': 'Real-World Cultures', 'desc': 'Historical and modern real-world cultures, nations, and languages.'},
    'miscellaneous': {'name': 'Miscellaneous & Lore', 'desc': 'Quirky names, bands, guilds, potions, spells, taverns, vehicles, and concepts.'},
    'fantasy': {'name': 'Fantasy Races & Beings', 'desc': 'Classic and exotic fantasy races, mythical creatures, and magical beings.'},
    'places': {'name': 'Places & Geography', 'desc': 'Castles, dungeons, forests, islands, mountains, temples, plazas, and realms.'},
    'descriptions': {'name': 'Narrative Descriptions', 'desc': 'Rich procedural narrative blocks for characters, planets, battles, Pokémon, and backstories.'},
    'star_wars': {'name': 'Star Wars Universe', 'desc': 'Alien species, factions, and character names from the Star Wars universe.'},
    'star_wars_the_old_republic': {'name': 'Star Wars: The Old Republic', 'desc': 'Species and organizations from SWTOR (Chiss, Cathar, Sith, etc.).'},
    'towns_and_cities': {'name': 'Towns & Cities', 'desc': 'Steampunk, fantasy, historical, and regional urban settlements.'},
    'pets': {'name': 'Pets & Animals', 'desc': 'Beloved domestic pets, companions, marine mammals, reptiles, and birds.'},
    'pop_culture': {'name': 'Pop Culture & Comics', 'desc': 'Anime, comics, superhero teams, Homestuck, kaiju, and fiction generators.'},
    'pathfinder': {'name': 'Pathfinder RPG', 'desc': 'Ancestries, heritages, and species from the Pathfinder tabletop RPG.'},
    'star_trek': {'name': 'Star Trek', 'desc': 'Vulcans, Klingons, Romulans, Cardassians, Ferengi, and galactic species.'},
    'weapons': {'name': 'Weapons', 'desc': 'Swords, bows, staffs, shotguns, daggers, firearms, and fantasy armaments.'},
    'armour': {'name': 'Armour', 'desc': 'Helmets, shields, gauntlets, pauldrons, cloaks, and defensive gear.'},
    'dungeon_and_dragons': {'name': 'Dungeons & Dragons', 'desc': 'Core and expanded player character races for D&D adventures.'},
    'elder_scrolls': {'name': 'The Elder Scrolls', 'desc': 'Races and peoples of Tamriel (Altmer, Bosmer, Dunmer, Khajiit, Nord, etc.).'},
    'warhammer': {'name': 'Warhammer Fantasy', 'desc': 'Factions of the Old World: Empire, Dwarfs, High Elfs, Daemons of Chaos, Skaven.'},
    'warhammer_40k': {'name': 'Warhammer 40,000', 'desc': 'Grimdark far future: Space Marines, Necrons, Eldar, Orks, Chaos, Tau.'},
    'world_of_warcraft': {'name': 'World of Warcraft', 'desc': 'Playable races of Azeroth: Blood Elf, Draenei, Tauren, Worgen, Troll, etc.'},
    'world_of_warcraft_pets': {'name': 'World of Warcraft Pets', 'desc': 'Hunter pets and companion beasts from World of Warcraft.'},
    'game_of_thrones': {'name': 'Game of Thrones', 'desc': 'Houses, free cities, Dothraki, Valyrian, and Westerosi character names.'},
    'legend_of_zelda': {'name': 'The Legend of Zelda', 'desc': 'Gorons, Zoras, Gerudos, Dekus, Koroks, and Hyrulean deities.'},
    'mass_effect': {'name': 'Mass Effect', 'desc': 'Asari, Turian, Krogan, Salarian, and galactic citadel species.'},
    'wildstar': {'name': 'WildStar', 'desc': 'Nexus inhabitants: Aurin, Chua, Draken, Granok, Mechari, Mordesh.'},
    'halo': {'name': 'Halo Universe', 'desc': 'Forerunners, Sangheili (Elites), Kig-Yar (Jackals), Mgalekgolo (Hunters).'},
    'military': {'name': 'Military & Phonetic', 'desc': 'NATO phonetic, Royal Navy, US Armed Forces call-signs, and communications.'},
    'destiny': {'name': 'Destiny Universe', 'desc': 'Guardians and enemies: Awoken, Exo, Cabal, Fallen, Hive, Vex.'},
    'doctor_who': {'name': 'Doctor Who', 'desc': 'Daleks, Time Lords, Ice Warriors, Silurians, Sontarans, and Gallifreyans.'},
    'dragon_ball': {'name': 'Dragon Ball Universe', 'desc': 'Saiyans, Frieza Clan, Hakaishins, Namekians, and martial artists.'},
    'final_fantasy': {'name': 'Final Fantasy', 'desc': 'Elezen, Lalafell, Miqo\'te, Roegadyn, and Hyur from Eorzea.'},
    'rift': {'name': 'Rift Universe', 'desc': 'Bahmi, Eth, Kelari, Mathosian, and Telaran races.'},
    'lord_of_the_rings': {'name': 'Lord of the Rings', 'desc': 'Elves, Dwarves, Hobbits, Maiar, and peoples of Middle-earth.'},
    'lord_of_the_rings_online': {'name': 'Lord of the Rings Online', 'desc': 'Beornings, Dale-folk, and LOTRO specific cultural lineages.'},
    'guild_wars': {'name': 'Guild Wars', 'desc': 'Asura, Charr, Norn, and Sylvari from the world of Tyria.'},
    'harry_potter': {'name': 'Harry Potter Universe', 'desc': 'Goblins, Dragon species, Hippogriffs, House-elves, and magical beasts.'},
    'inheritance_cycle': {'name': 'Inheritance Cycle', 'desc': 'Dragons, Elves, Dwarves, and Urgals from the world of Alagaësia.'},
    'diablo': {'name': 'Diablo Universe', 'desc': 'Angels of High Heavens, Demons of the Burning Hells, Nephalem, Khazra.'},
    'dragon_age': {'name': 'Dragon Age', 'desc': 'Dwarfs, Elfs, and Qunari from the world of Thedas.'},
    'eve_online': {'name': 'EVE Online', 'desc': 'Caldari, Gallente, Amarr, and Minmatar pilot genealogies in New Eden.'},
    'the_witcher': {'name': 'The Witcher Universe', 'desc': 'Witchers, Nilfgaardians, Dryads, Dwarfs, Elfs, and Northern Realms peoples.'}
}

def main():
    repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    os.chdir(repo_root)

    print("Parsing generators from namgen --help...")
    help_out = subprocess.check_output(['./namgen', '--help'], text=True)
    lines = help_out.splitlines()

    generators = []
    in_gen = False
    for line in lines:
        if 'Specialized Generators:' in line:
            in_gen = True
            continue
        if not in_gen or not line.strip():
            continue
        m = re.match(r'^\s*(--[a-zA-Z0-9_\-]+)\s+(.*)$', line)
        if m:
            flag = m.group(1)
            desc = m.group(2)
            gen_id = flag[2:]
            
            # Determine category and friendly name
            parts = gen_id.split('-')
            cat = parts[0]
            sub = parts[1] if len(parts) > 1 else parts[0]
            
            # Friendly name formatting
            clean_sub = sub.replace('_', ' ').title()
            
            aliases = []
            if gen_id == 'lord_of_the_rings-elfs':
                aliases = ['elf', 'lotr-elf', 'lord-of-the-rings-elfs']
                
            cat_meta = CATEGORY_METADATA.get(cat, {'name': cat.replace('_', ' ').title(), 'desc': f'Generators for {cat}.'})
            
            generators.append({
                'id': gen_id,
                'flag': flag,
                'category': cat,
                'categoryName': cat_meta['name'],
                'name': clean_sub,
                'aliases': aliases,
                'description': desc,
                'samples': []
            })

    print(f"Loaded {len(generators)} generators. Generating live samples with namgen...")

    def fetch_samples(gen):
        try:
            res = subprocess.check_output(['./namgen', gen['flag'], '-c', '3'], text=True, stderr=subprocess.DEVNULL)
            samples = [s.strip() for s in res.strip().splitlines() if s.strip()]
            gen['samples'] = samples
        except Exception as e:
            gen['samples'] = []
        return gen

    with ThreadPoolExecutor(max_workers=8) as ex:
        generators = list(ex.map(fetch_samples, generators))

    # Sort generators by categoryName, then name
    generators.sort(key=lambda g: (g['categoryName'], g['name']))

    # Write generators.json
    out_path = os.path.join(repo_root, 'web', 'data', 'generators.json')
    with open(out_path, 'w', encoding='utf-8') as f:
        json.dump(generators, f, indent=2, ensure_ascii=False)
    print(f"Wrote {len(generators)} generators to {out_path}")

    # Build categories list
    cats_map = {}
    for g in generators:
        cid = g['category']
        if cid not in cats_map:
            cats_map[cid] = {
                'id': cid,
                'name': g['categoryName'],
                'description': CATEGORY_METADATA.get(cid, {}).get('desc', ''),
                'count': 0
            }
        cats_map[cid]['count'] += 1

    categories = sorted(cats_map.values(), key=lambda c: -c['count'])
    cat_path = os.path.join(repo_root, 'web', 'data', 'categories.json')
    with open(cat_path, 'w', encoding='utf-8') as f:
        json.dump(categories, f, indent=2, ensure_ascii=False)
    print(f"Wrote {len(categories)} categories to {cat_path}")

    # Load sample adjectives and nouns for interactive combinator
    adj_file = os.path.join(repo_root, 'assets', 'adjectives', 'adjectives.list')
    noun_file = os.path.join(repo_root, 'assets', 'nouns', 'nouns.list')
    
    with open(adj_file) as f:
        adjs = [line.strip() for line in f if line.strip()][:150]
    with open(noun_file) as f:
        nouns = [line.strip() for line in f if line.strip()][:150]

    words_path = os.path.join(repo_root, 'web', 'data', 'words.json')
    with open(words_path, 'w', encoding='utf-8') as f:
        json.dump({'adjectives': adjs, 'nouns': nouns}, f, indent=2)
    print(f"Wrote {len(adjs)} adjectives and {len(nouns)} nouns to {words_path}")

if __name__ == '__main__':
    main()
