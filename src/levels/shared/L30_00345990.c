#include "common.h"

/* localdecomp:start func_L30_00345990 */
__asm__(".extern D_L30_001DF2C0, 16");
extern s32 D_L30_001DF2C0;
typedef int u128_00345990 __attribute__((mode(TI)));
extern s32 func_L05_00328FF8(u8 *);
extern void func_003A52A0(s32, s32, u8 *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_L30_00343798(u8 *, f32);

void func_L30_00345990(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 t;
    s32 n;
    f32 f;

    if (v[0x1B8] == 0 && func_L05_00328FF8(a0) && *(s16 *)(a0 + 0xAA) == 0x1745) {
        func_003A52A0(0, 0, a0);
    }
    n = *(s32 *)(v + 0x190);
    t = (D_L30_001DF2C0 + *(s32 *)(v + 0x188)) % (n * 2 + *(s32 *)(v + 0x17C));
    if (t < *(s32 *)(v + 0x17C)) {
        a0[0x20] = 0x11;
        f = 1.0f - func_L03_0034B148(t, *(s32 *)(v + 0x17C), 0.0f);
        *(f32 *)(v + 0x1A4) = 1.0f;
        *(f32 *)(v + 0x1A8) = 1.0f;
        *(f32 *)(v + 0x160) = f;
        func_L30_00343798(a0, f);
        if (*(s32 *)(v + 0x198) == 1) {
            *(s32 *)(v + 0x198) = 2;
        }
        if (*(s32 *)(v + 0x198) == 0) {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        }
        return;
    }
    t -= *(s32 *)(v + 0x17C);
    if (t < n) {
        a0[0x20] = 0x12;
        *(u128_00345990 *)(v + 0x130) = *(u128_00345990 *)(v + 0x150);
        f = 1.0f - func_L03_0034B148(t, *(s32 *)(v + 0x190), 0.0f);
        *(f32 *)(v + 0x160) = f;
        *(f32 *)(v + 0x1A4) = 1.0f - f;
        *(f32 *)(v + 0x1A8) = 1.0f - f;
        if (f > 0.75f) {
            if (*(s32 *)(v + 0x198) == 2) {
                *(s32 *)(v + 0x198) = 1;
            }
            if (*(s32 *)(v + 0x198) == 0) {
                *(s32 *)(a0 + 0x98) = 0;
            }
        }
        return;
    }
    a0[0x20] = 0x10;
    *(u128_00345990 *)(v + 0x130) = *(u128_00345990 *)(v + 0x140);
    *(f32 *)(v + 0x160) = 1.0f - func_L03_0034B148(t - n, *(s32 *)(v + 0x190), 0.0f);
    *(f32 *)(v + 0x1A4) = *(f32 *)(v + 0x160);
    *(f32 *)(v + 0x1A8) = *(f32 *)(v + 0x160);
    if (*(f32 *)(v + 0x160) > 0.25f) {
        if (*(s32 *)(v + 0x198) == 1) {
            *(s32 *)(v + 0x198) = 2;
        }
        if (*(s32 *)(v + 0x198) == 0) {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        }
    }
}
/* localdecomp:end func_L30_00345990 */

/* localdecomp:start func_L30_00345B68 */
extern s32 func_L05_00328FF8(u8 *);
extern void func_003A52A0(s32, s32, u8 *);
void func_L30_00345B68(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 19 && v[440] == 0 && func_L05_00328FF8(a0) && *(s16 *)(a0 + 170) == 5957) {
        func_003A52A0(0, 0, a0);
    }
}
/* localdecomp:end func_L30_00345B68 */

INCLUDE_ASM("asm/levels", func_L30_00345BD0);

INCLUDE_ASM("asm/levels", func_L30_00346080);
