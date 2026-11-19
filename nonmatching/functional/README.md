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
