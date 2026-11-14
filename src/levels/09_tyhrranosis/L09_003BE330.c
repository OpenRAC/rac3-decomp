#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L09_003BE330);

INCLUDE_ASM("asm/levels", func_L09_003BE450);

INCLUDE_ASM("asm/levels", func_L09_003BE5D0);

INCLUDE_ASM("asm/levels", func_L09_003BE910);

INCLUDE_ASM("asm/levels", func_L09_003BEB30);

INCLUDE_ASM("asm/levels", func_L09_003BEC20);

INCLUDE_ASM("asm/levels", func_L09_003BED10);

INCLUDE_ASM("asm/levels", func_L09_003BEDA8);

/* localdecomp:start func_L09_003BEF00 */
/* PAL port of the NTSC-U match src/us/levels/func_L09_003BD680.c */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(void *, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L09_003BC790(void *, s32, s32, s32, s32);
extern s32 func_L09_003BD560(void *, s32, s32, s32, s32);

extern u8 D_001A4C60[];

s32 func_L09_003BEF00(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s16 *h = (s16 *)(p + 0xD34);

    if (*(unsigned long *)(p + 0xD40) & 0x50000) {
        p[0xD42] &= 0xFE;
        func_L01_004450F0(a0, 0xD, -1);
        func_L01_00445188(a0, 1);
        return 0;
    }
    if (func_0038CB00(p + 0xD38)) {
        func_L09_003BC790(a0, a1, a2, a3, 1);
        return 0;
    }
    if (func_0038CF38(a0 + 0x10, D_001A4C60) > 25.0f) {
        *h = 0;
        return 1;
    }
    if ((*h)++ >= 500) {
        *h = 0;
        return 1;
    }
    if (p[0xD42] & 2) {
        func_L09_003BD560(a0, a1, a2, a3, 1);
    }
    return 0;
}
/* localdecomp:end func_L09_003BEF00 */

INCLUDE_ASM("asm/levels", func_L09_003BF038);

INCLUDE_ASM("asm/levels", func_L09_003BF0E0);
