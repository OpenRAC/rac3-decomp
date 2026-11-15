#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L31_003ABC08.c, which this file was cut from */
extern s32 func_L01_004561B8(u8 *);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern s32 func_0038CAD0(u8 *);
extern void func_L30_0034C8A8(u8 *, u8 *);
extern void func_L01_004450F0(u8 *m, s32 a, s32 b);

/* localdecomp:start func_L31_003AC410 */
/* Ps2EeAs only uses $gp for these if it knows their size before the use; D_L31_001DF340 gets
   no hint: retail reaches it through $gp only in a delay slot. */
__asm__(".extern D_L31_001DEB00, 4");
__asm__(".extern D_L31_001DEB04, 4");
__asm__(".extern D_L31_001DEB14, 4");
__asm__(".extern D_L31_001DEB18, 4");
__asm__(".extern D_L31_001DEB24, 4");
__asm__(".extern D_L31_001DEB28, 1");
extern s32 D_L31_001DEB00;
extern s32 D_L31_001DEB04;
extern f32 D_L31_001DEB14;
extern s32 D_L31_001DEB18;
extern s32 D_L31_001DEB24;
extern u8 D_L31_001DEB28;
extern s32 D_L31_001DF340;
extern u8 D_L31_001E1D10[] __attribute__((section(".sdata")));
extern u8 D_001A4C60[];
extern void func_L31_003AC578(u8 *, u8 *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern s32 func_0038CAD0(u8 *);
extern void func_L30_0034C8A8(u8 *, u8 *);

void func_L31_003AC410(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        *(f32 *)(a0 + 0x14) = *(f32 *)(D_001A4C60 + 4);
        *(f32 *)(a0 + 0x48) = 0.5f;
        if (D_L31_001DEB28 == 0) {
            D_L31_001DEB28 = 1;
            func_L03_0034B218(D_L31_001E1D10, D_L31_001DEB00, D_L31_001DEB04, D_L31_001DEB14, D_L31_001DEB18, (void *)func_L31_003AC578);
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(a0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            if (D_L31_001DF340 >= 11) {
                func_003A52A0(0, 0, a0);
            }
            *(s32 *)(s + 4) = D_L31_001DEB24;
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
        }
        if (func_0038CAD0(s + 4) == 0 && D_L31_001DF340 > D_L31_001DEB24) {
            func_L30_0034C8A8(D_L31_001E1D10, a0);
        }
        break;
    }
}
/* localdecomp:end func_L31_003AC410 */

INCLUDE_ASM("asm/levels", func_L31_003AC578);
