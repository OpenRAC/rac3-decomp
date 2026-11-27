# The cross-game function index

`tools/xgame_index.py` indexes every function of rac1-decomp, rac2-decomp, rac3-decomp and
rac4-decomp, matched or not, so that a rac3 function still in assembly can be looked up against the
C the other games already have for the same engine routine. [sister-twins.md](sister-twins.md)
finds only twins whose masked words are (nearly) equal. This index also ranks routines that were
edited between games: an extra branch, other constants, a moved call. Examples are
`func_L01_0044AF78` = rac2's `SpawnExplosionEffects` (src/pal/game/002AC718-blast.c),
`func_L01_00455550` = rac2's `moby_update_positional_gravity_motion` and `func_L39_00548648` = rac2's
`beam_draw_ring_and_core`.

## Building it

    python3 tools/xgame_index.py build            # about 15 s on 10 cores: build/xgame_index.sqlite

`config/xgame_index.json` lists what is read. For each game and version it gives the progress
report, the source folders of other versions to leave out, and where the dumps are. The games are
found in the OpenRAC games folder: `--games DIR`, else `$OPENRAC_GAMES`, else the folder this
checkout sits in (`OpenRAC/games/rac3/decomp`), else `~/Projects/RAC/OpenRAC/games`. rac3's `src/`
and report come from this checkout. Its `baserom/` and `asm/` come from here, or from the games
folder's rac3 when this checkout has none (a worktree). Each other game's working tree is read as
it is, so pull it first.

A function counts as matched under the rule `tools/sister_twins.py` uses. An active C definition
in `src/` names it, by its address name or a readable name from `config/names*.tsv`. No asm marker
names it. A later version of a game (rac2 PAL, rac4 PAL) keeps only the functions whose code
differs from the earlier version's function of the same name. Rebuild after a pull. The index is
not committed.

## The fingerprints

Every function is fingerprinted from its retail bytes, in ways that do not depend on addresses,
register allocation or constants:

| Kind | What it compares |
|---|---|
| `ops` | the opcode sequence without registers or immediates. A move, a load-immediate and a `$sp` load or store are one token each, whatever their width (`sd` and `sq` saves compare equal). Branch-likely folds into its branch, and branches are marked forward or backward |
| `cfg` | the basic blocks in order: how each one ends, where its successors are (next, forward, back, out) and its length class |
| `calls` | the calls in order. Each is the number of integer and float argument registers set before it; tail calls and `jalr` are marked |
| `consts` | float constants (`lui`+`mtc1`), 32-bit integers (`lui`+`ori`), immediates over 16, `andi` masks and `slti` bounds |
| `offs` | the field offsets of loads and stores. Relocated `%lo` halves and `$sp`/`$gp` slots are left out |
| `frame` | the stack frame size |
| key | the relocation-masked words of `tools/twin_mask.py`. Equal keys mean identical code, and the score is then 1 |

A query takes 120 candidates from a MinHash of the opcode 4-grams, restricted to 0.4 to 2.5 times
the instruction count. It scores each kind from 0 to 1: sequence alignment for `ops`, `cfg` and
`calls`, Jaccard for `consts` and `offs`. The combined score weighs them 0.40, 0.20, 0.15, 0.10,
0.10 and 0.05. A kind that is empty on both sides drops out. The exact `ops` alignment runs only
on the best candidates of an order-blind first pass, so a query takes under a second even for
10 KB functions.

## Querying

    python3 tools/xgame_index.py query func_L01_0044AF78            # a name (rac3's first)
    python3 tools/xgame_index.py query rac2:func_002B2A10 -n 5      # game:name
    python3 tools/xgame_index.py query asm/levels/01_veldin/nonmatchings/text/func_0044AF78.s

Matched counterparts are listed first, each with its score per kind and the definition's
`file:first-last`, then a few unmatched ones with their `.s`.

## The sweep

    python3 tools/xgame_index.py sweep            # build/xgame_sweep.tsv, about 10 s

This writes one row per rac3 PAL function still in assembly (16 bytes and more), largest first:

- `best_*`: its best matched counterpart in any game, rac3's other levels included;
- `xgame_*`: its best one in another game.

Each side has a score, a game, a function, its C (`path:first-last`) and the score per kind.

How far to trust a score (from spot checks, 2026-11-27):

| Score | Reading |
|---|---|
| 0.80 and more | the same routine; port the C |
| 0.70 to 0.80 | the same routine with edits (more calls, other constants); a good starting point |
| 0.60 to 0.70 | often the same routine, heavily edited, but sometimes only a function built the same way. Read it first |
| under 0.60 | rarely useful |

A counterpart's C is a start, not a match. Rename its callees and globals to rac3's names, carry
over its declarations, and check it in rac3's file with `tools/check.py` (see sister-twins.md, "A
twin is a start, not a match").
