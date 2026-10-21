#include "common.h"

typedef int s128_3D8F20 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_003D9510);

/* localdecomp:start func_L01_003D9540 */
extern s32 D_L01_001D673C_003D9540;
s32 func_L01_003D9540(void) {
    return D_L01_001D673C_003D9540;
}
/* localdecomp:end func_L01_003D9540 */

INCLUDE_ASM("asm/levels", func_L01_003D9548);

INCLUDE_ASM("asm/levels", func_L01_003D9FD0);

INCLUDE_ASM("asm/levels", func_L01_003DA3F0);

INCLUDE_ASM("asm/levels", func_L01_003DA6E8);

/* localdecomp:start func_L01_003DAAE0 */
extern void func_003C2F58(void *, s32, s128_3D8F20 *);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L01_003DAAE0(void *m) {
    s128_3D8F20 v;
    func_003C2F58(m, 14, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
    func_003C2F58(m, 15, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
}
/* localdecomp:end func_L01_003DAAE0 */

INCLUDE_ASM("asm/levels", func_L01_003DABC8);

INCLUDE_ASM("asm/levels", func_L01_003DB200);

INCLUDE_ASM("asm/levels", func_L01_003DB3F8);

INCLUDE_ASM("asm/levels", func_L01_003DB428);

INCLUDE_ASM("asm/levels", func_L01_003DB588);

INCLUDE_ASM("asm/levels", func_L01_003DB680);

INCLUDE_ASM("asm/levels", func_L01_003DB768);

INCLUDE_ASM("asm/levels", func_L01_003DBC60);

INCLUDE_ASM("asm/levels", func_L01_003DBC80);

INCLUDE_ASM("asm/levels", func_L01_003DC268);

INCLUDE_ASM("asm/levels", func_L01_003DC400);

INCLUDE_ASM("asm/levels", func_L01_003DC690);

INCLUDE_ASM("asm/levels", func_L01_003DC780);

INCLUDE_ASM("asm/levels", func_L01_003DCAA0);

LINKER_REMNANT("asm/levels", func_L01_003DD0F0);

INCLUDE_ASM("asm/levels", func_L01_003DD0F8);

INCLUDE_ASM("asm/levels", func_L01_003DD9C8);

INCLUDE_ASM("asm/levels", func_L01_003DDDA8);

/* localdecomp:start func_L01_003DE198 */
extern u8 *func_00382348(void);

void func_L01_003DE198(void) {
    u8 *p = func_00382348();
    if (p != 0 && (u8)(p[14] - 1) < 2) {
        p[14] = 2;
    }
}
/* localdecomp:end func_L01_003DE198 */

INCLUDE_ASM("asm/levels", func_L01_003DE1D8);

INCLUDE_ASM("asm/levels", func_L01_003DE418);

/* localdecomp:start func_L01_003DE488 */

extern void func_L01_003DE418(u8 *, u128_t *);
extern void func_L01_003DE510(u128_t *, u8 *, s32, s32, f32, f32, f32);
extern void func_L01_00409B08(u128_t *, s32, s32);

void func_L01_003DE488(u8 *m) {
    u128_t a;
    u128_t b;
    u8 *t;

    t = *(u8 **)(m + 104);
    if (t != 0) {
        func_L01_003DE418(m, &a);
        b = *(u128_t *)(m + 16);
        func_L01_003DE510(&b, t + 16, 0x1030FF, 4, 0.0f, 0.85f, 0.25f);
        func_L01_00409B08(&a, 0x2040FF, 0);
    }
}
/* localdecomp:end func_L01_003DE488 */

INCLUDE_ASM("asm/levels", func_L01_003DE510);

INCLUDE_ASM("asm/levels", func_L01_003DEB40);

INCLUDE_ASM("asm/levels", func_L01_003DEC20);

INCLUDE_ASM("asm/levels", func_L01_003DEDF8);

INCLUDE_ASM("asm/levels", func_L01_003DEF68);

INCLUDE_ASM("asm/levels", func_L01_003DEFE8);

INCLUDE_ASM("asm/levels", func_L01_003DF1B0);

INCLUDE_ASM("asm/levels", func_L01_003DF558);

INCLUDE_ASM("asm/levels", func_L01_003DF620);

INCLUDE_ASM("asm/levels", func_L01_003DF7A8);

INCLUDE_ASM("asm/levels", func_L01_003DF8B8);

INCLUDE_ASM("asm/levels", func_L01_003DF8C0);

INCLUDE_ASM("asm/levels", func_L01_003E0058);

INCLUDE_ASM("asm/levels", func_L01_003E01B8);
