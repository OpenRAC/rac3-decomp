/* functional: high. Written from PAL asm, every block read against it (init when flag bit0 set, collision bounce with 0.74 damping, colour-flash call, final lerps). Not byte-identical (frame layout/regs); needs file flag -mvu0-use-vf0-vf2. func_L30_0034CB68 purpose unknown. */
#include "common.h"
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L30_0034DBA0(s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern void func_L30_0034CB68(void *, void *, s32, s32, void *, s32, f32, f32);
extern f32 D_L33_001DD688;
extern f32 D_L33_001DD68C;
extern f32 D_L33_001DD690;
extern f32 D_L33_001DD694;
extern f32 D_L33_001DD6AC;
extern f32 D_L33_001DD6A4;
extern f32 D_L33_001DD6B8;
extern f32 D_L33_001DD6BC;
extern f32 D_L33_001DD6C0;
extern f32 D_L33_001DD580;
extern f32 D_L33_001DD584;
extern f32 D_L33_001DD598;
extern f32 D_L33_001DD5E0;
extern f32 D_L33_001DD5E4;
extern f32 D_L33_001DD5E8;
extern s32 D_L33_001DD634;
extern f32 D_L33_001DD70C;
extern s32 D_L33_001DD660[];
extern s32 D_L33_001DD670[];
extern s32 D_L33_001DD640[];
extern s32 D_L33_001DD650[];
extern u8 D_L33_001E9600[];

void func_L33_0034EE00(u8 *a, u8 *b) {
    u8 *c;
    u8 *st;
    u16 hw;
    f32 k, e, g, h, x, ang, rad, rnd, spread, ca;
    f32 t[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 col[4] __attribute__((aligned(16)));
    f32 diff[4] __attribute__((aligned(16)));
    s32 idx;

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
    hw = *(u16 *)(b + 0xE);
    k = D_L33_001DD688 * (f32)*(s16 *)(b + 8) * (f32)(hw >> 8) * 0.00390625f;
    e = (f32)(hw & 0xFF);
    g = func_003C4088(D_L33_001DD690, D_L33_001DD68C, (f32)*(u8 *)(b + 0xC) * 0.00390625f);
    if (*(u16 *)(b + 0xA) & 1) {
        rnd = func_003824E0(-D_L33_001DD6AC, D_L33_001DD6AC);
        ca = func_0038DAB8(*(f32 *)(st + 0xA0), rnd);
        spread = func_003824E0(D_L33_001DD6BC, D_L33_001DD6B8);
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(c, 1, a + 0x10);
        t[0] = func_0038D098(ang) * D_L33_001DD6A4;
        t[2] = func_0038D0B0(ang) * D_L33_001DD6A4;
        t[1] = 0.0f;
        vec_add_ab(a + 0x10, a + 0x10, t);
        *(f32 *)(a + 0x14) += D_L33_001DD6C0;
        *(f32 *)(b + 0x10) = spread * func_0038D098(ca);
        if (fabs_asm(func_0038DB00(D_L33_001DD580, *(f32 *)(c + 0xF8))) <
            fabs_asm(func_0038DB00(D_L33_001DD584, *(f32 *)(c + 0xF8)))) {
            *(f32 *)(b + 0x10) = -*(f32 *)(b + 0x10);
        }
        *(f32 *)(b + 0x14) = spread * func_0038D0B0(ca);
        idx = *(s32 *)(st + 0xA4);
        *(s32 *)(b + 0x18) = func_L30_0034DBA0(D_L33_001DD670[idx], D_L33_001DD660[idx]);
        idx = *(s32 *)(st + 0xA4);
        *(s32 *)(b + 0x1C) = func_L30_0034DBA0(D_L33_001DD650[idx], D_L33_001DD640[idx]);
        *(u16 *)(b + 8) = *(u16 *)(b + 8) + (s32)(D_L33_001DD598 / spread);
        *(s16 *)(a + 0xA) = *(u16 *)(b + 8);
    }
    *(vu0_q *)pos = *(vu0_q *)(a + 0x10);
    pos[0] += *(f32 *)(b + 0x10);
    pos[2] += *(f32 *)(b + 0x14);
    if (func_003D3CB0(a + 0x10, pos, 1, c, 0) != 0 && *(s32 *)(D_L33_001E9600 + 0x18) != 0) {
        f32 z = pos[2];
        f32 d = *(f32 *)(b + 0x10) * 0.74f;
        pos[0] = *(f32 *)(a + 0x10) + d;
        if (*(f32 *)(a + 0x14) <= *(f32 *)(D_L33_001E9600 + 0x24)) {
            pos[2] = z - d;
        } else {
            pos[2] = z + d;
        }
        func_L33_00344F88(col, *(s32 *)(b + 0x1C));
        col[0] += D_L33_001DD5E0;
        col[1] += D_L33_001DD5E4;
        col[2] += D_L33_001DD5E8;
        func_L33_003453C8(b + 0x1C, col);
        vec_sub_ab(diff, pos, a + 0x10);
        if (D_L33_001DD634 < (s32)*(u8 *)(a + 7)) {
            func_L30_0034CB68(*(void **)b, diff, 1, -1, a + 0x10, 0, (f32)*(u8 *)(st + 0x24), D_L33_001DD70C);
        }
    }
    *(vu0_q *)(a + 0x10) = *(vu0_q *)pos;
    h = e + k;
    x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
    *(f32 *)(a + 0xC) = func_003C4088(D_L33_001DD694, g, x);
    x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
    *(s32 *)(a + 4) = func_0038DBD8(*(s32 *)(b + 0x18), *(s32 *)(b + 0x1C), x);
    x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
    *(s8 *)(a + 8) = (s32)func_003C4088(e, h, x);
}
