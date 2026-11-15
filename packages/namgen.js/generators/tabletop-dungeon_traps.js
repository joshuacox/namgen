(function(root) {
  var triggers = [
    "Stepping onto a mosaic tile warm to the touch",
    "Pulling a brass sconce shaped like a sleeping hound",
    "Disturbing the silver dust resting on a pedestal",
    "Uttering any metallic metal's name in a low whisper",
    "Breaking an almost-invisible spider-silk tripwire",
    "Rotating an iron sundial counter to the room's torches",
    "Opening the centermost drawer of a lacquered reliquary",
    "Extinguishing the blue flame inside a brazier",
    "Placing more than forty pounds upon the velvet rug",
    "Crossing the chalk boundary without holding an iron coin",
    "Plucking the lowest harp string on a bronze statue",
    "Touching a doorknob coated in sweet-smelling amber resin",
    "Prying loose a gemstone set within an owl statue's eye",
    "Reading aloud the mirror-reversed inscription above the arch"
  ];
  var hazards = [
    "drops interlocking portcullises while vents hiss amber sleep-gas",
    "reverses gravity for five seconds across the center corridor",
    "awakens four wall-mounted stone crossbows loaded with barbed nets",
    "floods the sunken trench with knee-deep oil and sparks a flint wheel",
    "projects three mocking arcane duplicates that shatter into shards",
    "slides the flagstones sideways toward a pit of stinging rust-mites",
    "rings a deafening gong that summons oozes from ceiling grates",
    "seals both exits and slowly warms the copper floor plates",
    "unleashes a swinging crescent pendulum disguised inside shadow",
    "transmutes footwear metal into dead-weight lead for three rounds",
    "snuffs all mundane torches and unleashes blinding phosphor flashes",
    "tilts the staircase treads flat into a greased chute",
    "activates a magnetic lodestone ceiling that yanks steel gear skyward",
    "splits the archway down its seam to release pressurized frost-steam"
  ];
  var clues = [
    "(Tell: faint scorch arcs radiate from the masonry joints; Bypass: wedge copper spikes beneath the rim.)",
    "(Tell: the dust forms concentric ripples whenever wind blows; Bypass: speak the mason's cipher etched on the lintel.)",
    "(Tell: dead scarabs litter the western threshold; Bypass: disarm from beneath the loose floorboard on the right.)",
    "(Tell: iron filings cling inexplicably to the ceiling ribs; Bypass: coat metal gear in wax or jam the counterweight chain.)",
    "(Tell: one lantern sputters at twice the cadence of the others; Bypass: extinguish all lights before crossing.)",
    "(Tell: dry straw stuffed into two wall nozzles hints at prior jam attempts; Bypass: counter-weight the central plate with 20 lbs.)",
    "(Tell: hair-thin grooves score both marble jambs at waist height; Bypass: crawl below knee height or block the gear slot.)",
    "(Tell: a skeletal hand clutches an unmelted tallow key; Bypass: hold the bronze lever down while allies pass.)",
    "(Tell: faint chime resonance echoes when boots tap the third step; Bypass: hop the prime-numbered stones only.)",
    "(Tell: ancient thief-cant scratches mark 'DO NOT BREATHE'; Bypass: hold breath for 12 seconds after disabling the catch.)",
    "(Tell: oil sheen pools along the baseboard grout; Bypass: jam the flint striker wheel with damp cloth.)",
    "(Tell: a small drainage grate smells sharply of brine; Bypass: drain the pressure cistern behind the tapestry.)"
  ];
  function pick(arr) { return arr[Math.floor(Math.random() * arr.length)]; }
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["tabletop-dungeon_traps"] = function() {
    return pick(triggers) + " " + pick(hazards) + " " + pick(clues);
  };
})(typeof window !== "undefined" ? window : globalThis);
