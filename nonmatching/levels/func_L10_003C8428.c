/* near miss (level 10, Zeldrin Starport): 13 differences, one scheduling tie in the stack arguments of func_L01_003303B8: retail loads 0x1000000 (lui $v1) first and the 1 for the second stack slot (addiu $v0,$zero,1) after the first two colour stores, this C loads the 1 first; every other instruction is retail's. In src/levels/10_zeldrin_starport/L10_003C7C28.c (-mvu0-use-vf0-vf2 ... @ps2as, include/vu0.h), after the blocks that declare func_003A52A0, func_L01_00447490, func_L01_00451FE0, func_0038CE20 and the others it uses. Tried: prototype orders (floats first, last, after the first int), the float argument as a local at three places, narrower and unsigned stack argument types */
#include "common.h"

/* localdecomp:start func_L10_003C8428 */
#include "vu0.h"
typedef int u128_t_3C8428 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C8428;
__asm__(".extern D_L10_001DE948, 4");
__asm__(".extern D_L10_001DE94C, 4");
__asm__(".extern D_L10_001DE950, 4");
__asm__(".extern D_L10_001DE954, 4");
extern f32 D_L10_001DE948;
extern f32 D_L10_001DE94C;
extern f32 D_L10_001DE950;
extern f32 D_L10_001DE954;
extern void func_0038D000(void *, void *, void *);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C8428(u8 *m) {
    V4_3C8428 p;
    V4_3C8428 a;
    u128_t_3C8428 z;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 7, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        z = 0;
        *(u128_t_3C8428 *)&a = z;
        a.x = D_L10_001DE948;
        a.y = D_L10_001DE94C;
        a.z = D_L10_001DE950;
        p = a;
        func_0038CE20(&p, &p, 6.016847f);
        *(u128_t_3C8428 *)&a = z;
        a.z = -0.14000002f;
        func_L02_003E2E38(m, &p, 0.1f, &a, 0x14, 0, 0, 0.18000001f, *(f32 *)(m + 0x2C) * 9.02527f, 20.0f, 1.0f);
        func_0038CE20(&p, &p, *(f32 *)(m + 0x2C));
        func_0038D000(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_L01_003303B8(&p, 0, 0, 0, 0, 2, 5, 0, D_L10_001DE954 * 6.016847f * *(f32 *)(m + 0x2C), 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C8428 */
