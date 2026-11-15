/* func_L12_003D3338: 4 diff with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as). Still differs: gcc orders the four float/byte stores to a1+0xCC, +0xC8, +0x81, +0xB8 as c8, b8, cc, 81 where retail has cc, 81, c8, b8 with the halfword load of +0x34 between; tried source orders (stores around the lh load, lh first, lh after the e7 store): the same 4 diff. Rest matches. */
#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt003D1AA8;

extern u8 D_L12_001DEF14;
__asm__(".extern D_L12_001DEF14, 4");
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern Vt003D1AA8 *func_L01_0043B548(s32 a0, s32 a1);
extern void func_003C3938(void *a0, s32 a1, s32 a2);

s32 func_L12_003D3338(u8 *a0, u8 *a1) {
    Vt003D1AA8 *vt;
    s16 h;
    u8 *p = *(u8 **)(a0 + 0x24);

    *(f32 *)(a0 + 0x2C) = *(f32 *)(p + 0x24) + *(f32 *)(p + 0x24);
    *(f32 *)(a1 + 0xCC) = 2.0f;
    a1[0x81] = 0xFF;
    h = *(s16 *)(a1 + 0x34);
    *(f32 *)(a1 + 0xC8) = 2.0f;
    a1[0xB8] = 0xFF;
    a1[0xE7] = 1;
    if (h == 0) {
        *(s16 *)(a1 + 0x34) = 30;
        *(f32 *)(a1 + 0x30) = 30.0f;
    }
    *(f32 *)(a1 + 0x40) = 0.6f;
    a1[0x38] = 2;
    a1[0x64] = 1;
    a1[0x3E] = 3;
    a1[0x39] = 0;
    a1[0x3F] = 0;
    if (a1[0x44] == 0) {
        a1[0x44] = D_L12_001DEF14;
    }
    *(f32 *)(a1 + 0x274) = *(f32 *)(a0 + 0xF8);
    *(s32 *)(a1 + 0x278) = 0;
    func_0038CB78(a1 + 0x160, 0, 0x80);
    func_0038CB78(a1 + 0x1E0, 0, 0x80);
    if (*(s32 *)(a1 + 0x150) > 0) {
        vt = func_L01_0043B548(6625, 108);
        *(s32 *)(a1 + 0x150) = -1;
        func_003C3938(a0, 0, 0);
        a1[0x15E] = 7;
        vt->f0(a0);
        return 0;
    }
    func_L01_004450F0(a0, 1, -1);
    return 1;
}
