# MetalForgeVST Factory Tone Library Roadmap

## Product direction
Sound quality and range take priority over download size. Cover influential electric-guitar sounds from 1980s metal to contemporary heavy music. Artist references are descriptive inspirations, not endorsements or exact recreations.

## Core categories
- Traditional heavy metal / NWOBHM: Judas Priest, Iron Maiden, King Diamond
- Thrash / speed: Metallica, Slayer, Megadeth, Exodus, Testament, Forbidden
- Death / grind: Death, Carcass, Napalm Death, Sepultura
- Groove / industrial: Pantera, Fear Factory, Machine Head, Godflesh, Rammstein, Ministry
- Melodic death / modern metal: In Flames, Sylosis, Lamb of God, Gojira, Crownshift
- Progressive / technical: Nevermore, Meshuggah, Opeth, Dream Theater
- Metalcore / contemporary: Killswitch Engage, Trivium, Architects, Jinjer, Spiritbox
- Hard rock / alternative: Alice in Chains, Alter Bridge, Stone Sour, Avenged Sevenfold
- Electric clean / atmospheric: The Cure, The Police, Tears for Fears, U2, R.E.M., Van Halen, King Diamond, Three Days Grace, Bruce Springsteen 'I'm on Fire' atmosphere

## Preset design
For each family, develop useful rhythm, lead, solo, clean (when relevant), and ambient variations. Organize by era, subgenre, gain level, tuning, guitar pickup, and playing role. Ensure meaningful differences rather than superficial EQ-only duplicates.

## DSP milestones
1. Stable JUCE VST3/standalone build and input/output metering
2. Oversampled nonlinear amp stages, tone stacks, noise gate, EQ
3. Cabinet WAV IR import and factory cabinet IR selection
4. Modulation, delay, convolution/algorithmic reverb, ambience
5. Preset serialization, browsing, tagging and favorites
6. Factory content creation, level matching, QA, performance optimization

## Content and licensing
Create or properly license every bundled IR, sample, and graphic. Do not distribute commercial third-party IRs without permission. Artist-inspired labels should avoid implying endorsement.

## Status
Planning specification only. Counts and library size remain flexible; none of the proposed presets, amps, or IRs should be represented as implemented until tested.
