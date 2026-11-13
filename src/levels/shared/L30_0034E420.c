#include "common.h"

/* localdecomp:start func_L30_0034E420 */
extern void func_003C2F58(void *, s32, void *);
void func_L30_0034E420(void *a0, void *a1) {
    u8 *s = *(u8 **)((u8 *)a0 + 104);
    if (*(s32 *)(s + 20) == 1) {
        func_003C2F58(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 4) {
        func_003C2F58(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 3) {
        func_003C2F58(a0, 1, a1);
    }
    if (*(s32 *)(s + 20) == 2) {
        func_003C2F58(a0, 1, a1);
    }
}
/* localdecomp:end func_L30_0034E420 */

/* localdecomp:start func_L30_0034E4D0 */
extern s32 D_L30_001DD4F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD4F0, 4");
extern s32 D_L30_001DD500[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD500, 4");
extern s32 D_L30_001DD510[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD510, 4");
extern s32 D_L30_001DD520[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD520, 4");
s32 func_L30_0034E4D0(void *a0, u32 a1) {
    u8 *s = *(u8 **)((u8 *)a0 + 104);
    if (a1 >= 3) {
        return 0;
    }
    if (*(s32 *)(s + 20) == 1) {
        return D_L30_001DD4F0[a1];
    }
    if (*(s32 *)(s + 20) == 4) {
        return D_L30_001DD500[a1];
    }
    if (*(s32 *)(s + 20) == 3) {
        return D_L30_001DD510[a1];
    }
    if (*(s32 *)(s + 20) == 2) {
        return D_L30_001DD520[a1];
    }
    return 0;
}
/* localdecomp:end func_L30_0034E4D0 */

INCLUDE_ASM("asm/levels", func_L30_0034E548);

/* localdecomp:start func_L30_0034E710 */
#include "vu0.h"
extern s32 D_L30_001DD58C; __asm__(".extern D_L30_001DD58C, 4");
extern s32 D_L30_001DD530; __asm__(".extern D_L30_001DD530, 4");
extern s32 D_L30_001DD534; __asm__(".extern D_L30_001DD534, 4");
extern f32 D_L30_001DD54C; __asm__(".extern D_L30_001DD54C, 4");
extern s32 D_L30_001DD550; __asm__(".extern D_L30_001DD550, 4");
extern s32 D_L30_001DD568; __asm__(".extern D_L30_001DD568, 4");
extern s32 D_L30_001DD56C; __asm__(".extern D_L30_001DD56C, 4");
extern f32 D_L30_001DD574; __asm__(".extern D_L30_001DD574, 4");
extern s32 D_L30_001DD578; __asm__(".extern D_L30_001DD578, 4");
extern f32 D_L30_001DD5C8; __asm__(".extern D_L30_001DD5C8, 4");
extern f32 D_L30_001DD5CC; __asm__(".extern D_L30_001DD5CC, 4");
extern f32 D_L30_001DD5D0; __asm__(".extern D_L30_001DD5D0, 4");
extern f32 D_L30_001DD5D4; __asm__(".extern D_L30_001DD5D4, 4");
extern f32 D_L30_001DD5D8; __asm__(".extern D_L30_001DD5D8, 4");
extern f32 D_L30_001DD5DC; __asm__(".extern D_L30_001DD5DC, 4");
extern f32 D_L30_001DD5E0; __asm__(".extern D_L30_001DD5E0, 4");
typedef struct { s16 a, b; f32 c; s32 d, e, f; void *g; } S_0034E710;
extern S_0034E710 D_L30_001E1240 __attribute__((section(".sdata")));
extern S_0034E710 D_L30_001E1260 __attribute__((section(".sdata")));
extern void func_L30_0034E548(void *, void *);
extern void func_L30_0034E8A8(void *, void *);
extern void func_L03_0034B218(void *, s32, s32, f32, s32, void *);
extern void func_003C2880(void *);
extern s32 func_L01_00445F40(u8 *, s32);
extern void func_003C7DD8(void *);
void func_L30_0034E710(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 t;
    f32 x, y, z;
    if (D_L30_001DD58C == 0) {
        D_L30_001DD58C = 1;
        func_L03_0034B218(&D_L30_001E1240, D_L30_001DD530, D_L30_001DD534, D_L30_001DD54C, D_L30_001DD550, func_L30_0034E548);
        func_L03_0034B218(&D_L30_001E1260, D_L30_001DD568, D_L30_001DD56C, D_L30_001DD574, D_L30_001DD578, func_L30_0034E8A8);
    }
    qzero(s);
    t = *(s32 *)(s + 0x14);
    if (t < 1 || t > 5 || *(s32 *)(s + 0x18) <= 0) {
        func_003C2880(a0);
        return;
    }
    if (t == 1) {
        func_L01_00445F40(a0, 0x15D5);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD5D4 * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    } else if (t == 2) {
        func_L01_00445F40(a0, 0x1C7C);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD5D8 * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    } else if (t == 3) {
        func_L01_00445F40(a0, 0x1C7D);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD5DC * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    } else if (t == 4) {
        func_L01_00445F40(a0, 0x1C7E);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD5E0 * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    }
    func_003C7DD8(a0);
    a0[0x40] = 0;
    a0[0x41] = 0;
    *(u16 *)(a0 + 0x34) &= 0xFFFA;
    if (*(s32 *)(s + 0x24) >= 0) {
        *(s32 *)(s + 0x24) = (*(s32 *)(s + 0x24) * 5 + 2) / 6;
    }
    x = D_L30_001DD5C8;
    y = D_L30_001DD5CC;
    z = D_L30_001DD5D0;
    *(f32 *)(a0 + 0xF0) = x;
    *(f32 *)(a0 + 0xF4) = y;
    *(f32 *)(a0 + 0xF8) = z;
}
/* localdecomp:end func_L30_0034E710 */

INCLUDE_ASM("asm/levels", func_L30_0034E8A8);
