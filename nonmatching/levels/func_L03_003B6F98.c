/* Near miss, 34 diff rows with the file's flags and context (Opus helper, 2026-11-20): the file-ready form of the
   PAL port (D_L03_ names, an in-file prototype of func_L03_003B6DF8 with u8 *; without it check.py's context sees no
   prototype and promotes the floats). Everything but the colour-fade block matches. Left: register allocation and
   schedule of the two alpha chains (retail: h96 in $v0, -1 in $a0, 0xFF0000 in $t0, b in $a1, both alphas in $t1,
   neg.s $f14 between the chains; gcc: h96 in $a0, -1 in $a2, b in $a3, alpha in $t2). Tried without change (34):
   a fade local computed before or after the loads, an unsigned alpha with a (s32) test, (h96 << 2) + h96, b loaded
   before a. Worse: separate alpha locals for a and b (30 rows, but both chains live at once, unlike retail), globals
   read directly (49), a static inline fade helper (48), masks or-ed low byte first (88), shifted byte fields (86).
   The parameter is void * (cast to the typed struct inside) because the file's matched C declares it that
   way; the cast changes no byte.
   Re-measured 2026-11-21 (task #2809): 34 differences (tools/check.py) at level 03 with the file's line. Tried
   again: each chain's colour loaded just before its alpha (34), the alpha as `(s32)(a >> 24) - h96 * 5` with a
   u32 shift-back (34), the low byte or-ed first with a ?: clamp (88), (a & 0xFF0000) or-ed before the alpha (29, but that or
   order is not retail's: retail or-s alpha << 24 with a & 0xFF0000 first), separate alpha locals with both
   clamps before both packs (30, both chains interleaved, unlike retail). Retail computes chain a, then chain
   b, with the alpha of both in $t1 and h96 in $v0; every wording here keeps both chains live at once. */
/* NM-R7 (2026-11-22): 34 differences (tools/check.py, level 03, the file's flags), unchanged after 5 more wordings (nonmatching/README.md). */
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
        al = (a >> 24) - (o->h96 * 5);
        if (al < 0) {
            al = 0;
        }
        a = (al << 24) | (a & 0xFF0000) | (a & 0xFF00) | (a & 0xFF);
        al = (b >> 24) - (o->h96 * 5);
        if (al < 0) {
            al = 0;
        }
        b = (al << 24) | (b & 0xFF0000) | (b & 0xFF00) | (b & 0xFF);
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
