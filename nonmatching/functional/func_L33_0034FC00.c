/* functional: high. Written from PAL asm, every block read against it. Needs file flag -mvu0-use-vf0-vf2; not byte-identical (180 diffs, same frame size). Retail computes hi = e + (e + k) (the add is repeated in the jal delay slot); kept. Init returns early with a[0xA]=0 when the owner has no state. */
#include "common.h"
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 D_L33_001DD814;
extern f32 D_L33_001DD848;
extern f32 D_L33_001DD844;
extern f32 D_L33_001DD820;
extern s32 D_L33_001DD818;
extern s32 D_L33_001DD81C;
extern f32 D_L33_001DD838;
extern f32 D_L33_001DD834;
extern f32 D_L33_001DD830;

void func_L33_0034FC00(u8 *a, u8 *b) {
    u8 *c;
    u8 *st;
    u16 hw;
    f32 k, e, h, x, rnd;
    f32 v0[4] __attribute__((aligned(16)));
    f32 v1[4] __attribute__((aligned(16)));
    f32 v2[4] __attribute__((aligned(16)));
    f32 v3[4] __attribute__((aligned(16)));

    if (b == 0) {
        return;
    }
    c = *(u8 **)b;
    if (c == 0) {
        return;
    }
    if (*(s32 *)(b + 4) == 0) {
        return;
    }
    if (*(u16 *)(b + 0xA) & 1) {
        st = *(u8 **)(c + 0x68);
        if (st == 0) {
            *(s16 *)(a + 0xA) = 0;
            return;
        }
        x = D_L33_001DD814 * *(f32 *)(c + 0xC) * 0.0009765625f;
        func_00382580(v0, x, x);
        *(vu0_q *)v1 = *(vu0_q *)v0;
        if (func_0038CE68(v1, st) < 0.0f) {
            func_L02_003BA9F8(v1, st, v3, v2);
            func_0038CE20(v3, v3, -1.0f);
            vec_add_ab(v1, v3, v2);
        }
        vec_add_ba(a + 0x10, v0, c + 0x10);
        v1[0] = v1[0] * D_L33_001DD848;
        func_0038CF68(v1, v1, D_L33_001DD844);
        *(f32 *)(b + 0x14) = v1[2];
        *(f32 *)(b + 0x10) = v1[0];
        *(f32 *)(b + 0x1C) = func_003C4088(D_L33_001DD820, -D_L33_001DD820, v1[2] / D_L33_001DD844 * 0.5f + 0.5f);
        rnd = func_003824E0(0.0f, 1.0f);
        *(s32 *)(a + 4) = func_0038DBD8(D_L33_001DD818, D_L33_001DD81C, rnd);
        *(f32 *)(a + 0xC) = func_003824E0(D_L33_001DD838, D_L33_001DD834);
    }
    *(f32 *)(b + 0x14) += *(f32 *)(b + 0x1C);
    *(f32 *)(a + 0x10) += *(f32 *)(b + 0x10);
    *(f32 *)(a + 0x18) += *(f32 *)(b + 0x14);
    *(s32 *)(a + 4) = (*(s32 *)(a + 4) & 0xFFFFFF) |
        ((s32)((f32)*(s16 *)(a + 0xA) / (f32)*(s16 *)(b + 8) * 128.0f) << 24);
    hw = *(u16 *)(b + 0xE);
    k = D_L33_001DD830 * (f32)*(s16 *)(b + 8) * (f32)(hw >> 8) * 0.00390625f;
    e = (f32)(hw & 0xFF);
    h = e + (e + k);
    x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
    *(s8 *)(a + 8) = (s32)func_003C4088(e, h, x);
    *(f32 *)(a + 0xC) = *(f32 *)(a + 0xC) * ((f32)*(s16 *)(a + 0xA) / (f32)(*(s16 *)(a + 0xA) + 1));
}
