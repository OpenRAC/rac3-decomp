#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L31_003ABC08 */
/* Ps2EeAs only uses $gp for these if it knows their size before the use. */
__asm__(".extern D_L31_001DEAB8, 4");
__asm__(".extern D_L31_001DEACC, 4");
__asm__(".extern D_L31_001DEAD0, 4");
__asm__(".extern D_L31_001DEAE0, 4");
__asm__(".extern D_L31_001DEAE4, 4");
__asm__(".extern D_L31_001DEAE8, 4");
extern s32 D_L31_001DEAB8;
extern s32 D_L31_001DEACC;
extern s32 D_L31_001DEAD0;
extern f32 D_L31_001DEAE0;
extern s32 D_L31_001DEAE4;
extern s32 D_L31_001DEAE8;
extern u8 D_L31_001E1CF0[] __attribute__((section(".sdata")));
extern void func_L31_003ABF70(u8 *);
extern void func_L31_003ABD70(u8 *, u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, u8 *);
/* L36_003A7F38.c declares it (f32, u8 *, s32, s32, s32, void *): the same registers; this order gives retail's argument loads */
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern f32 func_L03_0034B148(s32 a0, s32 a1, f32 f);
extern s32 func_0038CAD0(u8 *);
extern void func_003C2880(void *);
extern void func_L30_0034C8A8(u8 *, u8 *);

void func_L31_003ABC08(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 st = a0[0x20];

    switch (st) {
    case 0:
        func_L31_003ABF70(a0);
        break;
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            if (*(s32 *)(s + 0x10) > 0) {
                func_L01_00446780(a0, a0 + 0x10, 1, 0, 1, 0, *(f32 *)(s + 0x24), (f32)*(s32 *)(s + 0x10), 1.0f);
            }
            if (*(s16 *)(a0 + 0xAA) == 0x1B1D) {
                func_003A52A0(0, 0, a0);
            }
            if (D_L31_001DEAE8 == 0) {
                func_L03_0034B218(D_L31_001E1CF0, D_L31_001DEACC, D_L31_001DEAD0, D_L31_001DEAE0, D_L31_001DEAE4, (void *)func_L31_003ABD70);
                D_L31_001DEAE8 = st;
            }
            *(s32 *)(s + 0x14) = D_L31_001DEAB8;
        }
        a0[0x23] = (s32)(func_L03_0034B148(D_L31_001DEAB8 - *(s32 *)(s + 0x14), D_L31_001DEAB8, 0.0f) * 128.0f);
        if (func_0038CAD0(s + 0x14) != 0) {
            func_003C2880(a0);
        } else {
            func_L30_0034C8A8(D_L31_001E1CF0, a0);
        }
        break;
    }
}
/* localdecomp:end func_L31_003ABC08 */

INCLUDE_ASM("asm/levels", func_L31_003ABD70);
