/* near miss (level 7, Annihilation Nation), newly reconstructed 2026-11-16.
   With the owning file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division,
   default assembler) the best wording found (one VU0 asm block per sequence,
   not this file's j-form C, which needs -mvu0-use-vf0-vf2 even to compile) is
   32 differences: retail's c.lt.s sits
   inside the VU0 sequence (needs the j-form, which needs -mvu0-use-vf0-vf2) and
   retail keeps "jal func_L01_0045AA30; nop" (needs Ps2EeAs). This j-form C
   (vec_add_ab / vec_sub_ba from include/vu0.h) matches in tools/check.py with
   --flags=-mvu0-use-vf0-vf2 --as ps2as. Proposed whole-file change, not yet
   built: L07_003CC2B0.c line "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as", #include "vu0.h" in its prelude, and
   __asm__(".extern D_L07_001DE6F0, 8"); after the declaration in the
   func_L07_003CD9F8 block (without it Ps2EeAs turns that $gp access into
   lui/addiu and 003CD9F8 differs by 59 words). In a --no-context whole-file
   test that also matches the drafts func_L07_003CDB30 and func_L07_003CDC80.
   Deferred because another agent held a reservation in the file. The existing
   divs_nops row "func_L07_003CD7E0 2 0 0" is correct. */
#include "vu0.h"

typedef int Q_003CD7E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CD7E0;
typedef struct {
    u8 pad0[0x10];
    V4_003CD7E0 pos;
    u8 pad20[0x22];
    u8 b42;
    u8 pad43[0x7D];
    V4_003CD7E0 v[1];
} S_003CD7E0;

extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_L01_0045AA30(void *, void *);

void func_L07_003CD7E0(S_003CD7E0 *o, s32 id, s32 idx, s32 n, f32 x, f32 k, f32 h, f32 lo,
                       f32 hi, f32 mid) {
    V4_003CD7E0 a;
    V4_003CD7E0 b;
    V4_003CD7E0 d;
    f32 t;
    f32 g;

    if (o->b42 == id && lo <= x && x < hi) {
        *(Q_003CD7E0 *)&a = *(Q_003CD7E0 *)&o->pos;
        func_0038CF68(&b, &o->v[idx], (f32)n * k / (hi - lo));
        vec_add_ab(&a, &a, &b);
        if (x < 16.0f) {
            t = (x - lo) / (mid - lo);
        } else {
            t = 1.0f - (x - mid) / (hi - mid);
        }
        g = func_003C3D30(&a, 0, 0, 0.5f);
        a.z = func_003C3BE8(g, g + h, t);
        vec_sub_ba(&d, &a, &o->pos);
        func_L01_0045AA30(o, &d);
    }
}
