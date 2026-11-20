#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00421730);

/* localdecomp:start func_L01_00421738 */
extern long *D_L01_001E1068;
__asm__(".extern D_L01_001E1068, 16");
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
__asm__(".extern D_001D4BD0, 16");
__asm__(".extern D_001D4BD4, 16");

void func_L01_00421738(s32 a0, s32 a1, s32 a2, s32 a3, long p4, s32 p5) {
    long *q;
    *(s32 *)((u8 *)D_L01_001E1068 + 0) = 0x10000003;
    *(s32 *)((u8 *)D_L01_001E1068 + 4) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 8) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 12) = 0x50000003;
    q = D_L01_001E1068;
    D_L01_001E1068 = q + 2;
    q[2] = 0x4400000000008001L;
    q[3] = 0x4410;
    q[4] = 70;
    q[5] = p4;
    if (p5 != 0) {
        q[6] = (a0 + D_001D4BD0 - 8) | ((long)(a1 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000L;
        q[7] = (a2 + D_001D4BD0 - 8) | ((long)(a3 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000L;
    } else {
        q[6] = ((a0 << 4) + D_001D4BD0 - 16) | ((long)((a1 << 4) + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000L;
        q[7] = ((a2 << 4) + D_001D4BD0 - 16) | ((long)((a3 << 4) + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000L;
    }
    D_L01_001E1068 = D_L01_001E1068 + 6;
}
/* localdecomp:end func_L01_00421738 */

LINKER_REMNANT("asm/levels", func_L01_004218C8);

/* localdecomp:start func_L01_00421988 */
__asm__(".extern D_L01_001D6A08, 4");
__asm__(".extern D_L01_001D6A0C, 4");
__asm__(".extern D_L01_001D6A10, 4");
__asm__(".extern D_L01_001D6A14, 4");
__asm__(".extern D_L01_001D6A18, 4");
extern s32 D_L01_001D6A08;
extern s32 D_L01_001D6A0C;
extern f32 D_L01_001D6A10;
extern s32 D_L01_001D6A14;
extern s32 D_L01_001D6A18;
extern u8 func_L01_00422338(void);
extern u8 func_L01_00421A30(void);
extern void func_L01_00436070(void *, void *, s32);
extern void func_L01_00448248(s32 *, s32, s32);

void func_L01_00421988(s32 mode, s32 a1, s32 a2, f32 f) {
    if (D_L01_001D6A08 == 0 || (D_L01_001D6A0C != 2 && mode == 2)) {
        D_L01_001D6A0C = mode;
        func_L01_00436070(func_L01_00422338, func_L01_00421A30, 1);
    }
    if (mode == D_L01_001D6A0C) {
        D_L01_001D6A14 = a1;
        D_L01_001D6A18 = a2;
        D_L01_001D6A10 = f;
        func_L01_00448248(&D_L01_001D6A08, 10, 2);
    }
}
/* localdecomp:end func_L01_00421988 */

INCLUDE_ASM("asm/levels", func_L01_00421A30);

/* localdecomp:start func_L01_00422338 */
__asm__(".extern D_L01_001D6A08, 4");
__asm__(".extern D_L01_001D6808, 1");
extern u8 D_L01_001D6808;
extern s32 D_L01_001D6694[] __attribute__((section(".sdata")));
extern s32 func_0038CAD0(void *);
extern void func_L01_004360B8(s32);

u8 func_L01_00422338(void) {
    s32 v = D_L01_001D6694[0];
    if (v == 0 || v == 7) {
        if (func_0038CAD0(&D_L01_001D6A08)) {
            func_L01_004360B8(1);
        }
    }
    return D_L01_001D6808;
}
/* localdecomp:end func_L01_00422338 */

/* localdecomp:start func_L01_00422388 */
extern void func_L01_00422388(void);

extern s32 D_L01_001D6A3C;
void func_L01_00422388(void) {
    *(u8 *)&D_L01_001D6A3C = 1;
}
/* localdecomp:end func_L01_00422388 */
