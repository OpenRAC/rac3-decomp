/* func_L03_003B6F98 (levels, src/levels/shared/L03_003B68D8.c): near miss, 28 differences (tools/check.py,
   level 03) with the file's flags (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as),
   measured on upstream 59c6db4f (NM-R18, 2026-11-23); also 28 at levels 05, 08, 13, 22 and 24, with and
   without --no-context. The NM-R14 form (b's 0xFF0000 mask inside b's pack) measures 31 there.

   A PAL port of the NTSC-U draft of func_L03_003B5390. Everything but the colour-fade block matches.
   What this form fixes: writing each alpha in two steps, `al = a >> 24; al -= o->h96 * 5;`, makes the
   srl write the alpha's own register (retail's `srl $t1; subu $t1, $t1, ...`), puts h96 in $v0 as
   retail does, and with one `al` for both chains computes them one after the other, as retail does.
   NM-R18 (31 -> 28): b's `& 0xFF0000` taken into a local `c` before a's pack. sched1 (-fsched-verbose=5)
   picked b's mask before a's because the shared 0xFF0000 constant dies at whichever mask comes last
   in RTL order, and the insn that kills a register wins the register-weight tie. With `c` first, a's
   mask comes first and b's mask reuses the constant's register, as retail's `and $t0, $a1, $t0` does.
   What still differs (28): register choice. Retail keeps -1 in $a0, b in $a1, 0xFF0000 in $t0, a's
   0xFF00 mask in $a3 and both alphas in $t1, and computes b's 0xFF00/0xFF masks after a's final or;
   gcc puts -1 in $a1, b in $a0, 0xFF0000 in $a3, the alpha in $t2, and schedules b's 0xFF00 mask
   early. From the .lreg dump: local-alloc gives b (5 refs, live from its load to its 0xFF mask) a
   higher priority than the -1 qty (tied to the second slt), so b takes $a0. Retail's order needs b's
   last use later; b's masks feed the first call's $a2 and so outrank a's in sched1 priority.
   Tried (NM-R18): precomputing any other subset of b's masks, or one of a's, into locals (28 or 29);
   separate alpha locals in all six statement orders (30, the chains overlap); h96 * 5 in a named local
   at four places x b loaded first or late x one- or two-step alpha (31 or 34; 123 when b and the fade
   local both come after a's pack); all 24 declaration orders of a, b, al and c (28, insensitive).
   Tried (NM-R14): a separate alpha local for b (30, but its chain then overlaps a's, unlike retail);
   b loaded before or after a's chain, h96 * 5 in a local set first or after the loads, s32 colour
   words with u32 shifts (30 or 31, insensitive); the clamp as `al <= -1` (34 with the one-step alpha);
   ?: clamps inside the pack (89); every other association of the four-way or (81-83; left-associated,
   as here, is the only one that keeps retail's three masks); `(c & 0xFF0000) | (c & 0xFFFF)` (81),
   `(c & 0xFFFFFF) | (al << 24)` (83); new result locals for the packed colours (49); -ang in a local (34).
   Earlier attempts are in nonmatching/README.md's row. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L03_003B6F98 */
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; f32 f3C; } S_003B6F98;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_003B6F98 *st; u8 p6C[0x96 - 0x6C]; u16 h96; } O_003B6F98;
extern f32 func_003C4138(void *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003B6DF8(u8 *, s32, s32, s32, f32, f32, f32);
__asm__(".extern D_L03_001DEA6C, 4");
extern f32 D_L03_001DEA6C;
__asm__(".extern D_L03_001DEA64, 4");
extern f32 D_L03_001DEA64;
__asm__(".extern D_L03_001DEA68, 4");
extern f32 D_L03_001DEA68;
__asm__(".extern D_L03_001DEA74, 4");
extern u32 D_L03_001DEA74;
__asm__(".extern D_L03_001DEA78, 4");
extern u32 D_L03_001DEA78;
__asm__(".extern D_L03_001DEA7C, 4");
extern s32 D_L03_001DEA7C;
__asm__(".extern D_L03_001DEA80, 4");
extern s32 D_L03_001DEA80;
__asm__(".extern D_L03_001DEA84, 4");
extern f32 D_L03_001DEA84;

void func_L03_003B6F98(void *self) {
    O_003B6F98 *o = (O_003B6F98 *)self;
    S_003B6F98 *st;
    f32 ang;
    u32 a;
    u32 b;
    s32 al;
    u32 c;

    st = o->st;
    if (func_003C4138(&st->f38, st->f3C, D_L03_001DEA6C) == 0.0f) {
        if (st->f3C == D_L03_001DEA64) {
            st->f3C = D_L03_001DEA68;
        } else {
            st->f3C = D_L03_001DEA64;
        }
    }
    ang = func_0038DAB8(0.0f, st->f34 * 0.017453292f);
    if (o->b20 == 6) {
        a = D_L03_001DEA74;
        b = D_L03_001DEA78;
        al = a >> 24;
        al -= o->h96 * 5;
        if (al < 0) {
            al = 0;
        }
        c = b & 0xFF0000;
        a = (al << 24) | (a & 0xFF0000) | (a & 0xFF00) | (a & 0xFF);
        al = b >> 24;
        al -= o->h96 * 5;
        if (al < 0) {
            al = 0;
        }
        b = (al << 24) | c | (b & 0xFF00) | (b & 0xFF);
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA80, b, 1, st->f38, D_L03_001DEA84, -ang);
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA7C, a, 1, st->f38, D_L03_001DEA84, ang);
    } else {
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA80, D_L03_001DEA78, 1, st->f38, D_L03_001DEA84, -ang);
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA7C, D_L03_001DEA74, 1, st->f38, D_L03_001DEA84, ang);
    }
    st->f34 = st->f34 + 1.0f;
    if (st->f34 > 359.0f) {
        st->f34 = 0.0f;
    } else if (st->f34 < 0.0f) {
        st->f34 = 359.0f;
    }
}
/* localdecomp:end func_L03_003B6F98 */
