/* functional: high. Written from PAL asm, every block read against it. Needs file flag -mvu0-use-vf0-vf2 (vec_add_ab); not byte-identical (173 diffs). */
#include "common.h"
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L30_0034DBA0(s32, s32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern f32 D_L33_001DD704;
extern f32 D_L33_001DD700;
extern f32 D_L33_001DD6F8;
extern s32 D_L33_001DD6C4;
extern s32 D_L33_001DD6C8;
extern s32 D_L33_001DD760;
extern f32 D_L33_001DD6E8;
extern f32 D_L33_001DD6EC;
extern f32 D_L33_001DD6D4;
extern f32 D_L33_001DD708;
extern f32 D_L33_001DD6D0;
extern f32 D_L33_001DD6CC;
extern f32 D_L33_001DD6E4;

void func_L33_0034F250(u8 *a, u8 *b) {
    u8 *c;
    u8 *st;
    u16 hw;
    f32 k, e, x, ang, ang2, spread, ratio, size;
    f32 t[4] __attribute__((aligned(16)));
    f32 col[4] __attribute__((aligned(16)));

    if (b == 0) {
        return;
    }
    c = *(u8 **)b;
    if (c == 0) {
        return;
    }
    st = *(u8 **)(c + 0x68);
    if (*(s32 *)(b + 4) == 0) {
        return;
    }
    if (*(u16 *)(b + 0xA) & 1) {
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        spread = func_003824E0(D_L33_001DD704, D_L33_001DD700);
        ang2 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(c, 1, a + 0x10);
        t[0] = func_0038D098(ang2) * D_L33_001DD6F8;
        t[2] = func_0038D0B0(ang2) * D_L33_001DD6F8;
        t[1] = 0.0f;
        vec_add_ab(a + 0x10, a + 0x10, t);
        *(f32 *)(b + 0x18) = spread * func_0038D098(ang);
        *(f32 *)(b + 0x1C) = spread * func_0038D0B0(ang);
        *(s32 *)(a + 4) = func_L30_0034DBA0(D_L33_001DD6C4, D_L33_001DD6C8);
        *(f32 *)(a + 0xC) = func_003C4088(D_L33_001DD6E8, D_L33_001DD6EC, (f32)*(s32 *)(st + 0xA8) / (f32)D_L33_001DD760);
    }
    *(f32 *)(a + 0x10) += *(f32 *)(b + 0x18);
    *(f32 *)(b + 0x1C) += D_L33_001DD6D4;
    *(f32 *)(a + 0x18) += *(f32 *)(b + 0x1C);
    size = *(f32 *)(a + 0xC);
    ratio = (f32)*(s16 *)(a + 0xA) / (f32)(*(s16 *)(a + 0xA) + 1);
    *(f32 *)(a + 0xC) = size * (1.0f - D_L33_001DD708 * (1.0f - ratio));
    func_L33_00344F88(col, *(s32 *)(a + 4));
    ratio = (f32)*(s16 *)(a + 0xA) / (f32)(*(s16 *)(a + 0xA) + 1);
    col[0] *= D_L33_001DD6D0;
    col[1] *= D_L33_001DD6CC;
    col[3] *= ratio;
    func_L33_003453C8(a + 4, col);
    hw = *(u16 *)(b + 0xE);
    k = D_L33_001DD6E4 * (f32)*(s16 *)(b + 8) * (f32)(hw >> 8) * 0.00390625f;
    e = (f32)(hw & 0xFF);
    x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
    *(s8 *)(a + 8) = (s32)func_003C4088(e, e + k, x);
}
