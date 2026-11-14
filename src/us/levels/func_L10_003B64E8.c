#include "common.h"

/* NTSC-U counterpart of func_L10_003B85A0 (src/levels/10_zeldrin_starport/L10_003B5B48.c): 0.02 -> 0.0166667; 8 -> 10; 0.01 -> 0.00833333; 12 -> 14 */
/* localdecomp:start func_L10_003B64E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B85A0;
__asm__(".extern D_L10_001DE7A4, 4");
__asm__(".extern D_L10_001DE7A8, 4");
extern f32 D_L10_001DE7A4;
extern f32 D_L10_001DE7A8;
extern u8 D_001A30B0[];
extern u8 D_L10_001D66B0_003B64E8[8];
extern s32 func_L10_003B69C8(u8 *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E2A8(void);
extern void func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_L10_003B6E18(void *, s32);
extern int func_L10_003B7028(u8 *, void *, s32);
extern void func_L02_0034ECF8(void *);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L10_003B64E8(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    V4_3B85A0 a;
    V4_3B85A0 b;
    u8 *e;
    s32 h;
    s32 t;

    if (m[0x20] == 0 && func_L10_003B69C8(m) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x338) != 0 && m[0x95] != 4) {
        {
            s32 k = *(s32 *)(p + 0x34C);
            if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != *(u8 **)(p + 0x2DC) || e[0xD0] == 0) {
                *(s32 *)(p + 0x34C) = func_0039FE80(7, 4, *(u8 **)(p + 0x2DC));
            }
        }
        func_L01_0044B860(m, p + 0x340, p + 0x344, D_L10_001DE7A4, D_L10_001DE7A8 * 0.017453292f * 0.0166666675f, -1.0f);
        t = m[0x43];
        if (t != 0xE) {
            if (t != 0xD) {
                func_003BE4F0(m, 0xD, 0, 10);
            }
        }
        p[0x171] = 0xFF;
        p[0x172] = 0xFF;
        *(f32 *)(p + 0x1BC) = 2.0f;
        *(f32 *)(p + 0x1B8) = 2.0f;
        func_003BDA38(*(u8 **)(p + 0x2DC), 1, &a);
        func_003BDA38(*(u8 **)(p + 0x2DC), 2, &b);
        func_L01_00466F98(&a, D_L10_001D66B0_003B64E8, 0xE, 0x40, 0x406080, (s32)func_0037E2A8(), 73500.0f, 200.0f, 0.95f, 0.00833333377f, 0.0f);
        func_L01_00466F98(&b, D_L10_001D66B0_003B64E8, 0xE, 0x40, 0x406080, (s32)func_0037E2A8(), 73500.0f, 200.0f, 0.95f, 0.00833333377f, 0.0f);
    } else {
        h = *(s32 *)(p + 0x34C);
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_0039FB08(h);
            }
        }
        p[0x171] = 0x11;
        *(s32 *)(p + 0x34C) = -1;
        p[0x172] = 0x11;
        *(f32 *)(p + 0x1BC) = 0.75f;
        *(f32 *)(p + 0x1B8) = 0.2f;
    }
    func_003BDA38(m, 0, *(u8 **)(p + 0x2DC) + 0x10);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF0) = *(f32 *)(m + 0xF0);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF4) = *(f32 *)(m + 0xF4);
    func_00388BD0(*(u8 **)(p + 0x2DC) + 0xC0, *(u8 **)(p + 0x2DC) + 0xF0);
    if (p[0x3E] == 2) {
        func_L10_003B6E18(m, 0);
        return 1;
    }
    if (func_L10_003B7028(m, p + 0x160, 0) != 0) {
        func_L02_0034ECF8(m);
    }
    func_L01_0044F5E8(m, p + 0x30, 0);
    if (p[0x5F] != 0) {
        if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_004538E0(m, 5);
            }
        }
        if (m[0x95] == 0) {
            func_L01_004539A8(m, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_004539A8(m, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_004538E0(m, 3);
            }
        }
        if (m[0x95] == 0) {
            func_L01_004539A8(m, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_004539A8(m, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L10_003B64E8 */
