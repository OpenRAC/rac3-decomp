#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003B4350);

/* localdecomp:start func_L10_003B4600 */
extern void func_0038A238(s32);
extern void func_L01_0042B068(s32, s32);
extern void func_003864C0(s32);
extern f32 D_L10_001DEC50;
extern u8 D_L10_001DECE4;
extern u8 D_L10_001DECE5;
extern u8 D_L10_001DECE6;
extern f32 D_L10_001DECE8;
extern f32 D_L10_001DECEC;
extern f32 D_L10_001DECF0;
extern f32 D_L10_001DECF4;

void func_L10_003B4600(void) {
    func_0038A238(5);
    func_L01_0042B068(2, 0);
    D_L10_001DEC50 = 1.5f;
    D_L10_001DECE4 = 1;
    D_L10_001DECE5 = 1;
    D_L10_001DECE6 = 1;
    D_L10_001DECE8 = 262144.0f;
    D_L10_001DECEC = 524288.0f;
    D_L10_001DECF0 = 255.0f;
    D_L10_001DECF4 = 249.0f;
    func_003864C0(0);
}
/* localdecomp:end func_L10_003B4600 */

INCLUDE_ASM("asm/levels", func_L10_003B4698);

/* localdecomp:start func_L10_003B5690 */
extern s32 D_L10_001E0420;
extern f32 D_L10_001E0424;
extern s32 func_00396968(void *, s32);
extern void func_00396E50(s32, s32, s32, s32, s32, s32 *);

static __inline__ s32 scale_3B5690(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)((f32)(s32)v * D_L10_001E0424 + 0.5f + (D_L10_001E0420 == 1 ? z0 : z1));
}

void func_L10_003B5690(u8 *a0, s32 color, f32 x0, f32 x1, f32 y0, f32 y1) {
    s32 c[4];
    f32 w = x1 - x0;
    f32 h = y1 - y0;

    c[0] = color;
    c[1] = color;
    c[2] = color;
    c[3] = color;
    func_00396E50(func_00396968(a0 + 0xED1C, 0), (s32)y0, scale_3B5690(x0), (s32)h,
                  scale_3B5690(w), c);
}
/* localdecomp:end func_L10_003B5690 */

INCLUDE_ASM("asm/levels", func_L10_003B57A8);
