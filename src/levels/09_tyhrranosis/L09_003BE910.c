#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BE330.c, which this file was cut from */
extern s32 func_0038CB00(void *);

/* localdecomp:start func_L09_003BE910 */
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern s32 func_0038CB00(void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_003CCC20(u8 *, f32 *, f32 *, f32, u8);
typedef struct {
    u8 pad[0xD0];
    f32 v[4];
} S_003BE910;
extern S_003BE910 D_1A4BE0;

void func_L09_003BE910(u8 *a0, s32 a1, f32 *a2) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E009C + (*(s32 *)(p + 0xCD0) << 8);
    f32 v0[4];
    f32 v1[4];
    f32 m[4];
    f32 ang;
    s32 i;
    s32 has;
    if (func_0038CB00(p + 0xD36) == 0)
        return;
    i = 0;
    has = a2 != 0;
    for (; i < (a1 ? 2 : 1); i++) {
        func_003C2F58(e, i == 0 ? 9 : 0xD, v0);
        func_003C2F58(e, i == 0 ? 0xA : 0xE, v1);
        if (a2 == 0) {
            if (a1 != 0) {
                ang = func_0038DAB8(func_0038D160(v1[0] - v0[0], v1[1] - v0[1]),
                                    i == 0 ? -0.43633232f : 0.43633232f);
            } else {
                ang = func_0038D160(v1[0] - v0[0], v1[1] - v0[1]);
            }
        } else {
            ang = func_0038D160(a2[0] - v0[0], a2[1] - v0[1]);
        }
        func_00382760(m, 1.2f, ang,
                      func_0038D160(func_0038CF38(v1, D_1A4BE0.v), D_1A4BE0.v[2] - v1[2]));
        if (*(s16 *)(p + 0xD5A) == -1)
            *(s16 *)(p + 0xD5A) = func_003A52A0(0, 4, e);
        func_L01_003CCC20(a0, v1, m, p[0x46], has);
    }
    *(s16 *)(p + 0xD36) = 2;
}
/* localdecomp:end func_L09_003BE910 */

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

/* localdecomp:start func_L09_003BEDA8 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(u8 *, u8);
extern s32 func_0038CB00(void *);
extern void func_L09_003BC790(u8 *, s32, s32, s32, s32);
extern void func_L09_003BD560(u8 *, s32, s32, s32, s32);
extern void func_L09_003BD8A8(u8 *, s32, s32, s32);

s32 func_L09_003BEDA8(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (p[0xD42] & 1) {
        p[0xD42] &= ~1;
        func_L01_004450F0(a0, 0xC, -1);
        func_L01_00445188(a0, 1);
    } else if (a4 != -1 && (*(s16 *)(p + 0xD34))++ >= (s32)((f32)a4 * 50.0f)) {
        func_L09_003BC790(a0, a1, a2, a3, 0);
        func_L01_004450F0(a0, 0xF, -1);
        func_L01_00445188(a0, 1);
    } else if (func_0038CB00(p + 0xD38) != 0) {
        func_L09_003BC790(a0, a1, a2, a3, 0);
    } else if (p[0xD42] & 2) {
        func_L09_003BD560(a0, a1, a2, a3, 0);
    } else {
        func_L09_003BD8A8(a0, a1, a2, a3);
    }
    return 1;
}
/* localdecomp:end func_L09_003BEDA8 */

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

/* localdecomp:start func_L09_003BF0E0 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(u8 *, u8);
extern s32 func_L09_003BEF00(u8 *, s32, s32, s32);
extern void func_L09_003BD560(u8 *, s32, s32, s32, s32);
extern s32 func_00382468(s32);
extern void func_003A4F28(s32);
extern f32 func_0038CF38(void *, void *);
extern u8 D_1A4C60[];

s32 func_L09_003BF0E0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 *a4, s32 *a5, s32 a6) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 t;
    if (a0[0x20] == 0x10) {
        if (a0[0xBC] == 1) {
            if (func_L09_003BEF00(a0, a1, a2, a3) != 0) {
                *(s16 *)(p + 0xD58) = func_00382468(a6);
                func_L01_004450F0(a0, 10, -1);
                ((void (*)(u8 *, s32))func_L01_00445188)(a0, a4[*(s16 *)(p + 0xD58)]);
            }
            return 1;
        } else if (a0[0xBC] == 2) {
            if (p[0xD42] & 2) {
                func_L09_003BD560(a0, a1, a2, a3, 1);
                return 1;
            }
        }
    }
    if (a0[0x20] == 10) {
        if (a0[0xBC] == 1) {
            func_L01_004450F0(a0, 0xD, -1);
            func_L01_00445188(a0, 1);
            return 1;
        }
        if (a0[0xBC] == a4[*(s16 *)(p + 0xD58)]) {
            t = a5[*(s16 *)(p + 0xD58)];
            if (a0[0xBC] != 7 ? p[0xD2E] >= t : p[0xD2D] >= t) {
                if (*(s16 *)(p + 0xD5A) != -1) {
                    func_003A4F28(*(s16 *)(p + 0xD5A));
                    *(s16 *)(p + 0xD5A) = -1;
                }
                if (func_0038CF38(a0 + 0x10, D_1A4C60) > 25.0f) {
                    func_L01_004450F0(a0, 10, -1);
                    func_L01_00445188(a0, 2);
                } else {
                    func_L01_004450F0(a0, 0x10, -1);
                    func_L01_00445188(a0, 2);
                }
            } else if (p[0xD42] & 1) {
                if (*(s16 *)(p + 0xD5A) != -1) {
                    func_003A4F28(*(s16 *)(p + 0xD5A));
                    *(s16 *)(p + 0xD5A) = -1;
                }
                func_L01_004450F0(a0, 0x10, -1);
                func_L01_00445188(a0, 2);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L09_003BF0E0 */
