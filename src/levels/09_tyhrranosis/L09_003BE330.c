#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BE330 */
extern s32 func_0038CB00(void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C3FC0(void *, void *);
extern void func_0038D750(void *, s32, f32);

s32 func_L09_003BE330(u8 *a0, void *a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (p[0xD41] == 0) {
        p[0xD41] = 2;
        *(s16 *)(p + 0xD3A) = 50;
        *(f32 *)(p + 0xD3C) = 0.02f;
    }
    if (func_0038CB00(p + 0xD3A) != 0 || p[0xD41] == 1) {
        p[0xD41] = 1;
        return 1;
    }
    if (p[0xD41] == 2) {
        *(f32 *)(p + 0xC30) = func_003C3BE8(-(*(f32 *)(a0 + 0x18) - 332.0f + -2.0f), 0.0f,
                                            (f32)*(s16 *)(p + 0xD3A) * *(f32 *)(p + 0xD3C));
        func_0038CE20(p + 0xC30, p + 0xC30, 1024.0f);
        if (a1 != 0)
            func_003C3FC0(p + 0xC50, a1);
        else
            func_0038D750(p + 0xC50, 1, -0.017453292f);
    }
    return 0;
}
/* localdecomp:end func_L09_003BE330 */

INCLUDE_ASM("asm/levels", func_L09_003BE450);

INCLUDE_ASM("asm/levels", func_L09_003BE5D0);

INCLUDE_ASM("asm/levels", func_L09_003BE910);

/* localdecomp:start func_L09_003BEB30 */
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern u8 D_L09_001E2B80[];
__asm__(".extern D_L09_001E2B80, 16");
extern void func_L09_003BC450(u8 *, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);

s32 func_L09_003BEB30(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E009C + (*(s32 *)(p + 0xCD0) << 8);
    u8 *g;
    p[0xD42] &= ~1;
    func_L09_003BC450(a0, a1, a2, a3, 0);
    *(s16 *)(p + 0xD38) = (f32)func_00382498(5, 10) * 50.0f;
    *(s16 *)(p + 0xD30) = (f32)func_00382498(15, 25) * 50.0f;
    *(s16 *)(p + 0xD34) = 0;
    p[0xD40] = 0;
    g = D_L09_001E2B80;
    if (*(u8 **)(g + 0x144) == e)
        *(u8 **)(g + 0x144) = 0;
    if (*(u8 **)(g + 0x144) == 0) {
        *(u8 **)(g + 0x144) = a0;
        *(s32 *)(g + 0x148) = 0;
    }
    return 1;
}
/* localdecomp:end func_L09_003BEB30 */

/* localdecomp:start func_L09_003BEC20 */
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern u8 D_L09_001E2B80[];
__asm__(".extern D_L09_001E2B80, 16");
extern void func_L09_003BC450(u8 *, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);

s32 func_L09_003BEC20(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E009C + (*(s32 *)(p + 0xCD0) << 8);
    u8 *g;
    p[0xD42] &= ~1;
    func_L09_003BC450(a0, a1, a2, a3, a4);
    *(s16 *)(p + 0xD38) = (f32)func_00382498(5, 10) * 50.0f;
    *(s16 *)(p + 0xD30) = (f32)func_00382498(15, 25) * 50.0f;
    *(s16 *)(p + 0xD34) = 0;
    p[0xD40] = 1;
    g = D_L09_001E2B80;
    if (*(u8 **)(g + 0x144) == a0)
        *(u8 **)(g + 0x144) = 0;
    if (*(u8 **)(g + 0x144) == 0) {
        *(u8 **)(g + 0x144) = e;
        *(s32 *)(g + 0x148) = 0;
    }
    return 1;
}
/* localdecomp:end func_L09_003BEC20 */

/* localdecomp:start func_L09_003BED10 */
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern u8 D_L09_001E2B80[];
__asm__(".extern D_L09_001E2B80, 16");
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(u8 *, u8);

s32 func_L09_003BED10(u8 *a0) {
    u8 *p;
    u8 *g;
    u8 *e;
    s32 idx;
    if (a0[0x20] != 11)
        return 0;
    p = *(u8 **)(a0 + 0x68);
    idx = *(s32 *)(p + 0xCD0);
    g = D_L09_001E2B80;
    e = D_L09_001E009C + (idx << 8);
    p[0xD40] = 0;
    if (*(u8 **)(g + 0x144) == e)
        *(u8 **)(g + 0x144) = 0;
    if (*(u8 **)(g + 0x144) == 0) {
        *(u8 **)(g + 0x144) = a0;
        *(s32 *)(g + 0x148) = 0;
    }
    func_L01_004450F0(a0, 1, a0[0x95] + 1);
    func_L01_00445188(a0, 0);
    return 1;
}
/* localdecomp:end func_L09_003BED10 */

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

/* localdecomp:start func_L09_003BF038 */
extern s32 func_L09_003BEDA8(u8 *, s32, s32, s32, s32);
extern void func_L09_003BC790(u8 *, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(u8 *, u8);

s32 func_L09_003BF038(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0xE) {
        func_L09_003BEDA8(a0, a1, a2, a3, a4);
        return 1;
    } else if (a0[0x20] == 0xF) {
        func_L09_003BEDA8(a0, a1, a2, a3, -1);
        return 1;
    } else if (a0[0x20] == 0x15) {
        if (p[0xD42] & 2) {
            func_L09_003BC790(a0, a1, a2, a3, 0);
            *(s16 *)(p + 0xD34) = 0;
            func_L01_004450F0(a0, 0xE, -1);
            func_L01_00445188(a0, 1);
            return 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L09_003BF038 */

INCLUDE_ASM("asm/levels", func_L09_003BF0E0);
