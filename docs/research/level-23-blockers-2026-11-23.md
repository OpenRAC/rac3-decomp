# Level 23's last three functions, 2026-11-23

Level 23 (Holostar Studios, Clank) has 168 of its 171 PAL functions in C once the batch 13 PR (`func_L23_00406AC0`) lands. This note records why the last three are still assembly, how close the C got, and the change that could unblock them. Only exact matches go into `src/`, so nothing here is linked.

| Function | File | Best C | Blocker |
| --- | --- | --- | --- |
| `func_L23_003099D0` | `L23_003098F8.c` | `nonmatching/levels/func_L23_003099D0.c`: 337 words differ (842 against 842), 721 of 842 equal when aligned | one vadd stored twice |
| `func_L23_003B9B88` | `L23_003B94C8.c` | none kept | VU0 sequences the vu0.h helpers do not produce |
| `func_L23_003BA670` | `L23_003B94C8.c` | none kept | the same as its twin `func_L23_003B9B88` |

## func_L23_003099D0

A particle effect for the Clank sections: it picks a slot by `owner == hero.hero_moby`, then runs a state machine on `self[0x20]` that spawns and fades particles and sparkles.

**Earlier assessment.** This function was first thought to need hardcoded addresses, because it reads `lui %hi(D_1A4BE0)` plus offsets 0x25C0 and 0x25E4. Those are fields of the hero struct (`include/structs/hero.h`: `hero_moby` and `body_kind`), and `src/levels/10_zeldrin_starport/L10_003831C8.c` already reads them that way. So legal C can reach them.

**Build needs.** The vu0.h helpers fail to compile with `L23_003098F8.c`'s flags (`vf17 was spilled for class VU_REGS`). The function needs a file line of its own: `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`, like `L23_00374F78.c`.

**The blocker.** Retail does one `vadd` and stores the result twice: at 0x309C18/0x309C20, and at 0x30A1BC/0x30A1D8, where the second store sits in a `bc1t` delay slot. No helper in `include/vu0.h` stores a result twice, and two helper calls are not merged by the compiler. `vec_add_ab` followed by a quadword copy or `vec_copy` costs one extra `lqc2` at each site, and the second store moves.

`src/levels/shared/L01_00462978.c` does a vadd with two stores as one inline asm string. Separate vu0 asm statements in the vu0.h helper style come closer (717 of 842 equal when aligned), but they are new inline asm, which the matching rules do not allow, and they still do not match. An exact match needs a two-destination helper in `include/vu0.h`, which is the maintainers' decision.

**Findings that carry over:**

- **No alias needed.** `D_001D6160` and `D_001DEC40` are reached through both `$gp` and `lui`. That is ps2as giving a load or store in a branch delay slot the `$gp` form, so one declaration covers both.
- **Float constants.** These are one unit-in-the-last-place (ULP) off, or simply different, from the obvious values: 0.039473683f (not 0.04), 0.27999998f, 0.0024000001f, 0.020000001f, ±0.120000005f, and 315000.0f (not 313000.0f).
- **Register allocation.** Separate studies, not merged into the draft, gave retail's prologue: slot in `$17`, v in `$19`, self in `$20`, and frame 0x140. Three changes did it:
  - the loop-1 colour locals moved inside loop 1;
  - one counter per loop;
  - a `pos` local scoped to state 1's body only. Global allocation otherwise gives `self + 0x10` the register ahead of slot.
- **Other differences.** Listed in the draft's header, with offsets.

## func_L23_003B9B88 and func_L23_003BA670

These two functions are twins in `L23_003B94C8.c`: 575 and 577 lines of assembly with the same code apart from addresses. Both mix FPU work with VU0 `vadd.xyz` and `vsub.xyz`. One `vsub` loads its operand straight from a hero-struct field (`lqc2 $vf2, 0x1A4C60`).

At 0x3BAB88 in `func_L23_003BA670`, retail does a `vadd` into `$vf2`, then reloads `$vf1` and stores it to the stack. Only after that does it store `$vf2`, with FPU moves interleaved. The vu0.h helpers each emit their loads, operation and store together, so they cannot produce this interleaving.

An earlier round concluded that these two also need an `include/vu0.h` change. Its drafts were not kept, so there is no C for them here.

## What would unblock them

A maintainer decision on `include/vu0.h`:

- **For `func_L23_003099D0`:** a helper that adds two vectors and stores the result to two destinations.
- **For the twins:** helpers whose load, operation and store are separate statements, so the compiler can schedule other instructions between them.

With that in place, the draft above is the starting point for `func_L23_003099D0`.
