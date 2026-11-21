/* functional: high. Verified against PAL asm: all gp globals, offsets, callee order, delay-slot stores; draft raw VU0 asm replaced by vec_add_ba. Compiles with file flag -mvu0-use-vf0-vf2; not byte-identical (register naming/scheduling). */
#include "common.h"
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 D_L33_001DDBF4;
extern f32 D_L33_001DDBF8;
extern f32 D_L33_001DDBFC;
extern f32 D_L33_001DDC00;
extern f32 D_L33_001DDC08;
extern f32 D_L33_001DDC10;
extern f32 D_L33_001DDBE4;
extern f32 D_L33_001DDBD0;
extern s32 D_L33_001DDBE0;
extern s32 D_L33_001DDBDC;
extern s32 D_L33_001DDBD8;
extern s32 D_L33_001DDBD4;

void func_L33_00353540(u8 *a, u8 *b) {
    u8 *c;
    u16 hw;
    f32 k, e, g, h, r, x, ang, rad;
    f32 t[4] __attribute__((aligned(16)));

    if (b == 0) {
        return;
    }
    c = *(u8 **)b;
    if (c != 0 && *(s32 *)(b + 4) != 0) {
        hw = *(u16 *)(b + 0xE);
        k = D_L33_001DDBF4 * (f32)*(s16 *)(b + 8) * (f32)(hw >> 8) * 0.00390625f;
        e = (f32)(hw & 0xFF);
        g = func_003C4088(D_L33_001DDBFC, D_L33_001DDBF8, (f32)*(u8 *)(b + 0xC) * 0.00390625f);
        if (*(u16 *)(b + 0xA) & 1) {
            ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
            rad = func_003824E0(0.0f, *(f32 *)(c + 0xC) * 0.00048828125f);
            t[0] = func_0038D098(ang) * rad;
            t[2] = func_0038D0B0(ang) * rad;
            t[1] = 0.0f;
            vec_add_ba(a + 0x10, c + 0x10, t);
            r = func_003824E0(-D_L33_001DDC10, D_L33_001DDC10);
            *(f32 *)(a + 0x14) += r;
            *(f32 *)(b + 0x14) = func_003824E0(0.0f, D_L33_001DDC08);
            *(s32 *)(b + 0x18) = func_0038DBD8(D_L33_001DDBE0, D_L33_001DDBDC, func_003824E0(0.0f, 1.0f));
            *(s32 *)(b + 0x1C) = func_0038DBD8(D_L33_001DDBD8, D_L33_001DDBD4, func_003824E0(0.0f, 1.0f));
        }
        *(f32 *)(b + 0x14) += D_L33_001DDBE4;
        h = e + k;
        *(f32 *)(a + 0x18) += *(f32 *)(b + 0x14);
        x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
        *(f32 *)(a + 0xC) = func_003C4088(D_L33_001DDC00, g, x);
        x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
        *(s32 *)(a + 4) = func_0038DBD8(*(s32 *)(b + 0x18), *(s32 *)(b + 0x1C), x);
        x = func_L03_0034B148(*(s16 *)(b + 8) - *(s16 *)(a + 0xA), *(s16 *)(b + 8), D_L33_001DDBD0);
        *(s32 *)(a + 4) = (*(s32 *)(a + 4) & 0xFFFFFF) + ((s32)(x * 128.0f) << 24);
        x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
        *(s8 *)(a + 8) = (s32)func_003C4088(e, h, x);
    }
}
