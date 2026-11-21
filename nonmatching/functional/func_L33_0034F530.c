/* functional: high. Written from PAL asm, every block read against it (init, free flight with collision, attached-to-owner follow, rope-length clamp, final lerps). Needs file flag -mvu0-use-vf0-vf2; not byte-identical (191 diffs, same frame size). Omitted retail's always-true &D_L33_001E17F0 != 0 test; st is read only when owner non-null (retail reads it in a delay slot). func_00129950 is libgcc float-to-unsigned. */
#include "common.h"
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern u32 func_00129950(f32);
extern f32 D_L33_001DD598;
extern f32 D_L33_001DD754;
extern f32 D_L33_001DD750;
extern f32 D_L33_001DD75C;
extern f32 D_L33_001DD758;
extern f32 D_L33_001DD748;
extern f32 D_L33_001DD730;
extern f32 D_L33_001DD734;
extern f32 D_L33_001DD728;
extern f32 D_L33_001DD724;
extern s32 D_L33_001DD710;
extern s32 D_L33_001DD714;
extern s32 D_L33_001DD718;
extern s32 D_L33_001DD71C;
extern u8 D_L33_001E9600[];

void func_L33_0034F530(u8 *a, u8 *b) {
    u8 *c;
    u8 *st;
    s32 n;
    f32 life, fade, prog, dx, dz;
    f32 t[4] __attribute__((aligned(16)));
    f32 q[4] __attribute__((aligned(16)));

    if (b == 0) {
        return;
    }
    c = *(u8 **)b;
    st = c ? *(u8 **)(c + 0x68) : 0;
    if (c == 0) {
        if (!(b[9] & 2)) {
            return;
        }
    }
    life = func_003C4088(D_L33_001DD754, D_L33_001DD750, (f32)*(u16 *)(b + 0xA) * 0.0000152587890625f);
    if (b[9] & 1) {
        f32 ang, ang2;
        n = (s32)(D_L33_001DD598 / life);
        b[8] = (n / 4) + 1;
        *(s16 *)(a + 0xA) = b[8] * 4;
        *(f32 *)(b + 0xC) = func_0038DB48(func_003824E0(-*(f32 *)(st + 0xB4), *(f32 *)(st + 0xB4)));
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(c, 1, a + 0x10);
        if (*(f32 *)(a + 0x10) < *(f32 *)(c + 0x10)) {
            *(f32 *)(b + 0xC) = func_0038DAB8(*(f32 *)(b + 0xC), 3.1415927f);
        }
        *(vu0_q *)(a + 0x20) = *(vu0_q *)(a + 0x10);
        t[0] = func_0038D098(ang) * D_L33_001DD748;
        t[2] = func_0038D0B0(ang) * D_L33_001DD748;
        t[1] = 0.0f;
        vec_add_ab(a + 0x10, a + 0x10, t);
        *(f32 *)(a + 0x1C) = func_003824E0(D_L33_001DD75C, D_L33_001DD758);
    }
    prog = 1.0f - (f32)*(s16 *)(a + 0xA) * 0.25f / (f32)b[8];
    fade = func_003C4088(D_L33_001DD730, D_L33_001DD734, prog);
    if (!(b[9] & 2)) {
        t[0] = func_0038D098(*(f32 *)(b + 0xC)) * life;
        t[2] = func_0038D0B0(*(f32 *)(b + 0xC)) * life;
        t[1] = 0.0f;
        vec_add_ab(q, a + 0x10, t);
        if (func_003D3CB0(a + 0x10, q, 1, c, 0) != 0) {
            b[9] |= 2;
            c = *(u8 **)(D_L33_001E9600 + 0x18);
            *(u8 **)b = c;
            if (c != 0) {
                *(f32 *)(b + 0xC) = *(f32 *)(c + 0x10);
                *(u16 *)(b + 0xA) = func_00129950(*(f32 *)(c + 0x18) * 32.0f);
            }
        } else {
            *(f32 *)(a + 0x10) = q[0];
            *(f32 *)(a + 0x18) = q[2];
        }
    } else if (c != 0) {
        dx = *(f32 *)(c + 0x10) - *(f32 *)(b + 0xC);
        dz = *(f32 *)(c + 0x18) - (f32)*(u16 *)(b + 0xA) * 0.03125f;
        *(f32 *)(a + 0x20) += dx;
        *(f32 *)(a + 0x10) += dx;
        *(f32 *)(a + 0x28) += dz;
        *(f32 *)(a + 0x18) += dz;
        *(f32 *)(b + 0xC) = *(f32 *)(c + 0x10);
        *(u16 *)(b + 0xA) = func_00129950(*(f32 *)(c + 0x18) * 32.0f);
    }
    if (fade < func_0038CF00(a + 0x10, a + 0x20)) {
        vec_sub_ba(t, a + 0x20, a + 0x10);
        func_0038CF68(t, t, fade);
        vec_add_ab(a + 0x20, a + 0x10, t);
    }
    *(f32 *)(a + 0x2C) = func_003C4088(D_L33_001DD724, D_L33_001DD728, prog);
    *(s32 *)(a + 4) = func_0038DBD8(D_L33_001DD710, D_L33_001DD714, prog);
    *(s32 *)(a + 0xC) = func_0038DBD8(D_L33_001DD718, D_L33_001DD71C, prog);
}
