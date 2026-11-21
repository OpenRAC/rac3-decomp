# Functional C

C that behaves like the retail function without matching its bytes, for OpenRAC's native port
only: the matching build never reads it, `src/` never holds it, and the progress report never
counts it. Each function is listed in [`../functional.tsv`](../functional.tsv).

- One file per function, named after it. The first line says how close it is:
  `/* functional: high|medium|low. <what differs from retail and why it does not matter> */`.
- **`gate` column:** `pending` until the functional gate has run the function against retail from
  captured game states and reported which blocks ran. A row is done only when every block either
  ran in the gate or was read against the disassembly and justified; a bare "same" is not enough
  (on rac2, 28 rows that gated same still had slips in blocks the states never ran).
- Library and system code the port answers itself (boot_elf below 0x00140000: stdio, RPC, kernel,
  timers, pad, memory card, MPEG) is not backfilled; neither are padding words, fragments of a
  neighbour or hand-written VU0 code.
- When a function matches, its match goes in `src/` and its row and file here are removed.

## The gate

`python3 tools/fcheck.py check NAME nonmatching/functional/NAME.c --program boot_elf|frontbin`
runs a function's C against retail from captured states of the boot, the title and the main menu
(OpenRAC's test-only interpreter; `tools/fcheck.py capture NAME` takes the states first) and says
which of retail's blocks the states ran. `python3 tools/fcheck.py gate --write` fills the `gate`
column for every row. A `same-partial` row becomes `same-read` once its unrun blocks have been
read against retail and listed in the C, `/* fcheck-read: RANGE,... */`, as the verdict prints
them. The script's docstring has the details.

### Made-up calls (`--fuzz N`)

A function no captured state calls, or one whose states leave blocks unrun, can be run from made-up
calls: `check NAME FILE --fuzz 24`, `gate --fuzz 24`. A captured state (the function's own, any
state of a level that has it, the menus' for a boot function) is rewritten to call it with made-up
arguments: a live moby whose update it is (or a copy of another class's live moby made its own),
scratch buffers that point at one another as a tree (never aliasing), the constants its branches
test and the floats it loads. Calls on which retail does not agree with itself, or whose only
differences come from the made-up values (stores into the stack, misaligned accesses, accesses
past RAM), are left out. The verdict has its own word, `same-fuzz` or `differs-fuzz`, with the
blocks the made-up calls ran and how many they added: on a row without states it is the gate
cell, on one with states it follows the real verdict (`; fuzz: ...`). It is evidence for inputs the
game may never make, never `same`: a `differs-fuzz` is a lead to read against retail, and a
`same-fuzz` row still needs its blocks read or real states before it is done.
`$RAC3_FCHECK_FUZZ_MB` caps the interpreter's memory on a made-up call (default 3072; keep jobs
times it under the machine's memory).

### Spawning a moby (not built)

Some moby updates run only for classes a capture never meets (later levels, progress the scripts
do not reach). The plan: in a level run (`openrac-boot`), write a moby record into a free slot of
the live moby array at some field (`--write`), copied from a live moby, its update (+0x64) the
function, its class (+0xAA) and pvars (+0x68) from that class's placement in the level's data,
and capture the update's calls (`--capture`) as the game's own loop makes them, frame after
frame. That needs what this repository does not yet have: the moby array's bounds and how the
loop walks it, the placements' format, and whether the class's data is loaded in that level
(otherwise its class pointer is another class's).
