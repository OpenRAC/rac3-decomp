/* near miss (level 10, Zeldrin Starport): 13 differences, the same scheduling tie as func_L10_003C8428: among the stack arguments of func_L01_003303B8 retail loads 0x1000000 (lui $v1) before the colour stores and the constant 1 after the first two, this C loads the 1 first; every other instruction is retail's. Needs -mvu0-use-vf0-vf2 ... @ps2as and include/vu0.h on src/levels/10_zeldrin_starport/L10_003C7378.c; checked with --flags */
#include "common.h"

/* localdecomp:start func_L10_003C7378 */
#include "vu0.h"
typedef int u128_t_3C7378 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C7378;
__asm__(".extern D_L10_001DE8F8, 4");
__asm__(".extern D_L10_001DE8FC, 4");
extern f32 D_L10_001DE8F8;
extern f32 D_L10_001DE8FC;
extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C7378(u8 *m) {
    V4_3C7378 p;
    V4_3C7378 a;
    u128_t_3C7378 z;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0x7F, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00452460(m, 0x1EBE, 0);
        z = 0;
        *(u128_t_3C7378 *)&a = z;
        a.z = D_L10_001DE8F8;
        p = a;
        func_0038CE20(&p, &p, 5.05025f);
        *(u128_t_3C7378 *)&a = z;
        a.z = -0.14000002f;
        func_L02_003E2E38(m, &p, 0.1f, &a, 0x14, 0, 0, 0.18000001f, 2.525125f, 20.0f, 1.0f);
        func_0038CE20(&p, &p, *(f32 *)(m + 0x2C));
        func_0038D000(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_L01_003303B8(&p, 0, 0, 0, 0, 2, 5, 0, D_L10_001DE8FC * 5.05025f * 0.19801f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C7378 */
