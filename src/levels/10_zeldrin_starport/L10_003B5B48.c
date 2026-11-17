#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003B5B48);

INCLUDE_ASM("asm/levels", func_L10_003B64C8);

/* localdecomp:start func_L10_003B85A0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B85A0;
__asm__(".extern D_L10_001DE774, 4");
__asm__(".extern D_L10_001DE778, 4");
extern f32 D_L10_001DE774;
extern f32 D_L10_001DE778;
extern u8 D_001A30B0[];
extern u8 D_L10_001D66B0[8];
extern s32 func_L10_003B8A80(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_00382538(void);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L10_003B8ED0(void *, s32);
extern int func_L10_003B90E0(u8 *, void *, s32);
extern void func_L02_0034FD58(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L10_003B85A0(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    V4_3B85A0 a;
    V4_3B85A0 b;
    u8 *e;
    s32 h;
    s32 t;

    if (m[0x20] == 0 && func_L10_003B8A80(m) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x338) != 0 && m[0x95] != 4) {
        {
            s32 k = *(s32 *)(p + 0x34C);
            if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != *(u8 **)(p + 0x2DC) || e[0xD0] == 0) {
                *(s32 *)(p + 0x34C) = func_003A52A0(7, 4, *(u8 **)(p + 0x2DC));
            }
        }
        func_L01_0044EAE0(m, p + 0x340, p + 0x344, D_L10_001DE774, D_L10_001DE778 * 0.017453292f * 0.020000001f, -1.0f);
        t = m[0x43];
        if (t != 0xE) {
            if (t != 0xD) {
                func_003C3A10(m, 0xD, 0, 8);
            }
        }
        p[0x171] = 0xFF;
        p[0x172] = 0xFF;
        *(f32 *)(p + 0x1BC) = 2.0f;
        *(f32 *)(p + 0x1B8) = 2.0f;
        func_003C2F58(*(u8 **)(p + 0x2DC), 1, &a);
        func_003C2F58(*(u8 **)(p + 0x2DC), 2, &b);
        func_L01_0046A610(&a, D_L10_001D66B0, 0xC, 0x40, 0x406080, (s32)func_00382538(), 73500.0f, 200.0f, 0.95f, 0.010000001f, 0.0f);
        func_L01_0046A610(&b, D_L10_001D66B0, 0xC, 0x40, 0x406080, (s32)func_00382538(), 73500.0f, 200.0f, 0.95f, 0.010000001f, 0.0f);
    } else {
        h = *(s32 *)(p + 0x34C);
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        p[0x171] = 0x11;
        *(s32 *)(p + 0x34C) = -1;
        p[0x172] = 0x11;
        *(f32 *)(p + 0x1BC) = 0.75f;
        *(f32 *)(p + 0x1B8) = 0.2f;
    }
    func_003C2F58(m, 0, *(u8 **)(p + 0x2DC) + 0x10);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF0) = *(f32 *)(m + 0xF0);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF4) = *(f32 *)(m + 0xF4);
    func_0038D308(*(u8 **)(p + 0x2DC) + 0xC0, *(u8 **)(p + 0x2DC) + 0xF0);
    if (p[0x3E] == 2) {
        func_L10_003B8ED0(m, 0);
        return 1;
    }
    if (func_L10_003B90E0(m, p + 0x160, 0) != 0) {
        func_L02_0034FD58(m);
    }
    func_L01_00452860(m, p + 0x30, 0);
    if (p[0x5F] != 0) {
        if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_00456BD0(m, 5);
            }
        }
        if (m[0x95] == 0) {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_00456BD0(m, 3);
            }
        }
        if (m[0x95] == 0) {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L10_003B85A0 */

INCLUDE_ASM("asm/levels", func_L10_003B8A80);

LINKER_REMNANT("asm/levels", func_L10_003B8EC0);

/* localdecomp:start func_L10_003B8ED0 */
void func_003C2880(s32);
void func_L01_004443E8(void *, s32, s32);

void func_L10_003B8ED0(void *arg0, s32 arg1) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x2DC);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x2DC) = 0;
    }
    if (((*(f32 *)((u8 *)temp_s0 + 0x30)) <= 0.0f) && (arg1 == 0)) {
        func_L01_004443E8(arg0, 0, 3);
    }
}
/* localdecomp:end func_L10_003B8ED0 */

/* localdecomp:start func_L10_003B8F50 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);

void func_L10_003B8F50(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 value;

    func_0038CAD0(p + 0x2D0);
    func_0038CB00(p + 0x2D4);
    value = *(u16 *)(a0 + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(a0 + 0x96) = value + 1;
    }
    func_L01_00451DF8(a0, p + 0x240, 1, 1, 2.5f);
}
/* localdecomp:end func_L10_003B8F50 */
