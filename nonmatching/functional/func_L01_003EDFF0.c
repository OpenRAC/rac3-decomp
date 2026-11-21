/* functional: high. Per-frame update of the hero-linked camera follower (PAL version of the NTSC-U draft func_L01_003EC0B0, rechecked against PAL asm: PAL callees, gp slots and constants): when the target is lost or unavailable it clears the counter and re-aims the hero camera; otherwise (counter < 2) it derives yaw/pitch/roll offsets of the tracked point against the follow axis, seeds the follower object's motion blocks, then (counter < 0xA8) feeds the offsets to the six camera-offset setters and sets D_001A4E18 = 10 */
#include "vu0.h"
typedef struct {
    u8 prefix[0x20]; vu0_v4 axis; u8 p30[0x50]; vu0_v4 position;
    u8 p90[8]; f32 angle; u8 p9c[0x1680 - 0x9c]; u8 camera[0x4c]; f32 speed;
} Hero_EDFF0;
extern Hero_EDFF0 D_001A4BE0;
extern u8 D_001A6120[];
extern s32 D_001A4E18[];
extern u8 *D_001D52FC;
extern char *D_L01_001DF804;
extern s32 D_001DFB48_sda;
__asm__(".extern D_001DFB48_sda, 4");
extern u8 *D_001DF804_sda;
__asm__(".extern D_001DF804_sda, 4");
extern s32 func_L01_003EDD88(void *);
extern void func_L01_003E8AD8(void *);
extern s32 func_L01_003E8B28(void *);
extern s32 func_00461860(s32, s32);
extern void func_L01_00412FE0(void *, void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);   /* as its file declares it */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8E70(s32);
extern void func_L01_003E8C28(s32, f32, f32);
extern void func_L01_003E8C70(s32, s32, f32, f32);
extern void func_L01_003E8D48(s32, f32);
extern void func_L01_003E8D80(s32, s32);
extern void func_L01_003E8CE0(s32, f32, f32, f32);
void func_L01_003EDFF0(u8 *m) {
    u8 *owner = (u8 *)D_L01_001E2A40 + *(s32 *)(m + 0x94) * 0x460;
    u8 *state = owner + 0x150;
    u8 *d = *(u8 **)(D_L01_001DF804 + *(s16 *)(m + 0x84) * 32 + 28);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 f, g, t;
    u8 *obj, *sub, *move, *rot, *misc, *other, *in;
    s32 m1;

    if (!func_L01_003EDD88(m)) {
        if (*(s32 *)(d + 0x20)) *(s16 *)(d + 0x26) = 1;
        *(s32 *)(d + 0x20) = 0;
        func_L01_003E8AD8(m);
        func_0038CF68(a, (f32 *)&D_001A4BE0.axis, D_001A4BE0.speed);
        vec_add_ba(a, a, &D_001A4BE0.position);
        func_L01_00412FE0((u8 *)&D_001A4BE0 + 0x1540, a, D_001A4BE0.angle, 0.0f);
        return;
    }
    if (func_L01_003E8B28(m) <= 0) {
        if (*(s32 *)(d + 0x20)) *(s16 *)(d + 0x26) = 1;
        *(s32 *)(d + 0x20) = 0;
        return;
    }
    m1 = func_00461860(4, 0);
    if ((*(s32 *)(D_001D52FC + 0x1A0) & m1) && D_001DFB48_sda >= 11) {
        if (*(s32 *)(d + 0x20)) *(s16 *)(d + 0x26) = 1;
        *(s32 *)(d + 0x20) = 0;
        func_L01_003E8AD8(m);
        func_L01_00412FE0(D_001A6120, D_001A6120 - 0x14C0, *(f32 *)(D_001A6120 - 0x14A8), 0.0f);
        return;
    }
    if (*(s32 *)(d + 0x20) < 2) {
        if (*(f32 *)(d + 0x2C) == 0.0f && *(f32 *)(d + 0x30) == 0.0f) {
            in = D_001DF804_sda;
            *(f32 *)(d + 0x2C) = *(f32 *)(in + *(s16 *)(m + 0x84) * 32 + 0x14);
            *(f32 *)(d + 0x30) = *(f32 *)(in + *(s16 *)(m + 0x84) * 32 + 0x18);
        }
        in = (u8 *)D_L01_001DF804 + *(s16 *)(m + 0x84) * 32;
        f = func_0038D160(*(f32 *)(state + 0x40) - *(f32 *)(in + 0), *(f32 *)(state + 0x44) - *(f32 *)(in + 4));
        if (0.034906585f < func_0038DBA0(*(f32 *)(d + 0x30), f)) *(f32 *)(d + 0x44) = func_0038DB00(*(f32 *)(d + 0x30), f);
        in = (u8 *)D_L01_001DF804 + *(s16 *)(m + 0x84) * 32;
        a[0] = *(f32 *)(in + 0);
        a[1] = *(f32 *)(in + 4);
        a[3] = 0.0f;
        a[2] = *(f32 *)(in + 8);
        vec_sub_ab(b, a, state + 0x40);
        f = func_0038CE68(b, state + 0x80);
        func_0038CE20(c, state + 0x80, f);
        vec_sub_ab(e, b, c);
        g = func_0038CEA8(e);
        t = *(f32 *)(d + 0x2C);
        f = -f;
        *(f32 *)(d + 0x38) = g;
        *(f32 *)(d + 0x3C) = f;
        if (fabs_asm(t) == 1.5707964f) {
            *(s32 *)(d + 0x40) = 0;
        } else {
            f = func_0038D0B0(t);
            f = f / func_0038D098(t);
            *(f32 *)(d + 0x40) = *(f32 *)(d + 0x3C) - *(f32 *)(d + 0x38) * f;
        }
        obj = *(u8 **)(owner + 0x50);
        *(vu0_q *)(obj + 0x30) = *(vu0_q *)a;
        sub = *(u8 **)(obj + 0x70);
        move = sub + 0x180;
        rot = sub + 0x20;
        misc = sub + 0x60;
        other = sub + 0x210;
        *(f32 *)(move + 0x2C) = *(f32 *)(d + 0x38);
        *(f32 *)(move + 0x30) = *(f32 *)(d + 0x3C);
        *(f32 *)(rot + 0x28) = *(f32 *)(d + 0x44);
        *(f32 *)(misc + 0xD0) = *(f32 *)(d + 0x40);
        func_0038CE20(c, state + 0x80, -*(f32 *)(move + 0x30));
        vec_add_ba(sub + 0xB0, state + 0x40, c);
        vec_sub_ab(sub + 0x180, a, sub + 0xB0);
        *(vu0_q *)(sub + 0x190) = *(vu0_q *)(sub + 0x180);
        func_0038CE20(c, state + 0x80, -*(f32 *)(misc + 0xD0));
        vec_add_ba(sub + 0xA0, state + 0x40, c);
        *(vu0_q *)(sub + 0x110) = *(vu0_q *)(sub + 0xA0);
        *(vu0_q *)(sub + 0xC0) = *(vu0_q *)(state + 0x40);
        *(vu0_q *)(sub + 0x60) = *(vu0_q *)(state + 0x40);
        *(vu0_q *)sub = *(vu0_q *)(obj + 0x30);
        *(vu0_q *)(sub + 0x230) = *(vu0_q *)(obj + 0x30);
        *(s32 *)(other + 0x30) = 0;
        *(s32 *)(rot + 0x14) = 0;
        *(f32 *)(rot + 4) = *(f32 *)(misc + 0xD0);
        *(f32 *)(rot + 0xC) = *(f32 *)(rot + 0x14);
        *(f32 *)(rot + 8) = *(f32 *)(move + 0x30);
        *(s16 *)(rot + 2) = 0;
        *(f32 *)(rot + 0x18) = *(f32 *)(rot + 0x14);
        *(f32 *)(rot + 0x10) = *(f32 *)(rot + 0x14);
    }
    *(s32 *)(d + 0x20) = *(s32 *)(d + 0x20) + 1;
    if (*(s32 *)(d + 0x20) >= 0xA8) *(s32 *)(d + 0x20) = 0xA7;
    if (*(f32 *)(d + 0x38) != 0.0f) {
        func_L01_003E8BD0(*(s32 *)(m + 0x94), 0, *(f32 *)(d + 0x38), 0.003f);
        func_L01_003E8E70(*(s32 *)(m + 0x94));
    }
    if (*(f32 *)(d + 0x3C) != 0.0f) func_L01_003E8C28(*(s32 *)(m + 0x94), *(f32 *)(d + 0x3C), 0.003f);
    if (*(f32 *)(d + 0x40) != 0.0f) func_L01_003E8C70(*(s32 *)(m + 0x94), 0, *(f32 *)(d + 0x40), 0.005f);
    if (*(f32 *)(d + 0x28) != 0.0f) func_L01_003E8D48(*(s32 *)(m + 0x94), *(f32 *)(d + 0x28) * 0.017453292f);
    if (*(s16 *)(d + 0x24) == 0) func_L01_003E8D80(*(s32 *)(m + 0x94), 0);
    if (*(f32 *)(d + 0x44) != 0.0f) func_L01_003E8CE0(*(s32 *)(m + 0x94), *(f32 *)(d + 0x44), 60.0f, 60.0f);
    D_001A4E18[0] = 10;
}
