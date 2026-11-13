/* near miss (level 10, Zeldrin Starport): 64 differences, all register numbering: the instruction sequence is retail's, but retail gives the particle lifetime $s0, the random count $s1 and the colour $s2 (this C: $s2, $s0, $s1), and in the tail keeps &q in a new $s1 and the count in $s0. Statement-order search over the seven lines before the spawn call (200 tries), the arguments inline, and reading the 0x68 block before the vector copy (80) did not help. Needs -mvu0-use-vf0-vf2 ... @ps2as and include/vu0.h on src/levels/10_zeldrin_starport/L10_00359EA0.c; checked with --flags */
#include "common.h"

/* localdecomp:start func_L10_00359EA0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_359EA0;
typedef struct { u8 pad0[0x10]; u8 *f10; } S_359EA0;
__asm__(".extern D_L10_001DD760, 4");
__asm__(".extern D_L10_001DD768, 4");
__asm__(".extern D_L10_001DD76C, 4");
__asm__(".extern D_L10_001DD770, 4");
__asm__(".extern D_L10_001DD774, 4");
__asm__(".extern D_L10_001DD778, 4");
__asm__(".extern D_L10_001DD77C, 4");
__asm__(".extern D_L10_001DD780, 4");
__asm__(".extern D_L10_001DD784, 4");
__asm__(".extern D_L10_001DD788, 4");
__asm__(".extern D_L10_001DD78C, 4");
extern s32 D_L10_001DD760;
extern s32 D_L10_001DD768;
extern s32 D_L10_001DD76C;
extern s32 D_L10_001DD770;
extern s32 D_L10_001DD774;
extern s32 D_L10_001DD778;
extern f32 D_L10_001DD77C;
extern f32 D_L10_001DD780;
extern f32 D_L10_001DD784;
extern f32 D_L10_001DD788;
extern f32 D_L10_001DD78C;
extern S_359EA0 D_L10_0021EB98;
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00470668(void *, void *, s32, f32);

void func_L10_00359EA0(u8 *m, V4_359EA0 *pos, V4_359EA0 *c, f32 s) {
    V4_359EA0 p;
    V4_359EA0 q;
    s32 t;
    u8 a;
    s32 i;
    s32 col;
    s32 life;
    s32 r;
    f32 s0;
    f32 s1;
    u8 *e;

    p = *pos;
    t = **(s32 **)(m + 0x68);
    if (t < 50) {
        a = (s32)((f32)t * 127.0f / 50.0f);
    } else {
        a = 0x7F;
    }
    for (i = 0; i < D_L10_001DD760; i++) {
        func_00382580(&q, D_L10_001DD784 * s * 0.5f, D_L10_001DD784 * s);
        vec_add_ab(&q, &q, c);
        func_0038CF68(&q, &q, func_003824E0(D_L10_001DD788 * 0.5f * s, D_L10_001DD788 * s) * 0.020000001f);
        if (func_00382468(4) != 0) {
            col = D_L10_001DD778;
        } else {
            col = D_L10_001DD770;
        }
        life = (D_L10_001DD768 * 5 + 2) / 6;
        col |= a << 24;
        r = func_00382498(-2, 2);
        s0 = D_L10_001DD77C * s * 210000.0f;
        s1 = D_L10_001DD780 * s * 210000.0f;
        e = func_L01_00475C60(&p, &q, life, r, col, D_L10_001DD774, 0, s0, s1,
                              func_003824E0(D_L10_001DD78C * 0.3f, D_L10_001DD78C));
        if (e != 0) {
            e[2] = *D_L10_0021EB98.f10;
            e[3] = func_00382468(2) ? 0x48 : 0x44;
        }
    }
    if (func_00382468(6) == 0) {
        life = (func_00382498(D_L10_001DD76C - 5, D_L10_001DD76C) * 5 + 2) / 6;
        func_L01_00470668(&p, &q, life, func_003824E0(40.0f, 80.0f) * 0.00040000002f);
    }
}
/* localdecomp:end func_L10_00359EA0 */
