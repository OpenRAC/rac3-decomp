/* func_L24_0034CD58: 7 differences, all one instruction's position (level 24, file L24_0034CD58.c; its vec_add needs
   -mvu0-use-vf0-vf2 on that file's line, which keeps func_L24_0034D110 matching but is not committed with this near
   miss; @ps2as). The projectile update (state 1: move, trail, bounds and lifetime checks, impact with func_003D3CB0 /
   func_L01_00446760 / func_003D4D00; state 2: the 30-argument burst func_L01_003303B8; the shared dead and alive
   tails) matches except that retail sets the low half of the burst's 0x1010001 argument (`ori $v0,$v0,1`) after the
   store of 0x4040FF to the stack, this C before the other constants' ori. Tried: every position of the four float
   parameters in func_L01_003303B8's prototype (27 variants), the constant in a local, written as 0x1010000 | 1. */
#include "common.h"
#include "vu0.h"
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(f32 *, s32, f32, void *, void *);
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L24_0034D110(u8 *);
extern void func_L24_0034D2C8(u8 *, f32 *, f32 *);
typedef struct {
    u8 p0[0x18];
    s32 x18;
    u8 p1C[4];
    vu0_v4 x20;
} S_34CD58;
extern S_34CD58 D_L24_001E8F40;

void func_L24_0034CD58(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v[4];
    f32 w[4];
    u8 c[0x30];
    s32 t;
    f32 *pv;
    vu0_v4 *g;

    switch (obj[0x20]) {
    case 1:
        pv = v;
        *(vu0_q *)pv = *(vu0_q *)(obj + 0x10);
        vec_add_ba(obj + 0x10, s, obj + 0x10);
        func_L01_004C8688(*(s32 *)(s + 0x20), s, 0);
        *(vu0_q *)(*(u8 **)(s + 0x18) + 0x10) = *(vu0_q *)(obj + 0x10);
        *(f32 *)(*(u8 **)(s + 0x18) + 0x2C) = *(f32 *)(*(u8 **)(s + 0x18) + 0x2C) * 1.036f;
        if (0.06f < *(f32 *)(*(u8 **)(s + 0x18) + 0x2C)) {
            *(f32 *)(*(u8 **)(s + 0x18) + 0x2C) = 0.06f;
        }
        if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10)
            || *(f32 *)(obj + 0x14) < 2.0f || 1021.0f < *(f32 *)(obj + 0x14)
            || *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
            func_L01_004C8668(*(s32 *)(s + 0x20));
            if (*(u8 **)(s + 0x18) != 0) {
                func_003C2880(*(u8 **)(s + 0x18));
            }
            goto dead;
        }
        *(s32 *)(s + 0x14) = *(s32 *)(s + 0x14) + 1;
        if (func_003D3CB0(pv, obj + 0x10, 0, *(void **)(s + 0x1C), 0) != 0) {
            g = &D_L24_001E8F40.x20;
            *(vu0_v4 *)(obj + 0x10) = *g;
            obj[0x20] = 2;
            *(vu0_q *)w = *(vu0_q *)s;
            func_0038CE20(w, w, 3.0f);
            w[3] = 5627.9248f;
            func_L01_00446760(c, obj, 0x10001, w, *(f32 *)(s + 0x24));
            c[0x18] = 0;
            c[0x19] = 1;
            *(u16 *)(c + 0x1A) = *(u16 *)(obj + 0xAA);
            t = D_L24_001E8F40.x18;
            if (t != 0) {
                if (t != *(s32 *)(s + 0x1C)) {
                    func_003D4D00((f32 *)g, 0, 0.3f, obj, c);
                }
            } else {
                func_003D4D00((f32 *)g, 0, 0.6f, obj, c);
            }
        }
        if (*(s32 *)(s + 0x14) < 0x97) {
            goto alive;
        }
        goto dead;
    case 2:
        func_L01_003303B8(obj + 0x10, 0, 15, 5, 15, 20, 0, 1, 0.25f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 1, 0, 0x1010001, 0, 0x1010FF, 0x4040FF, 0x407FFF, 0x20FF, 0x20FF, 0xFF3000, 0x7F2020FF, 0x280000FF, 0xFF2034, 0);
        func_L01_004C8668(*(s32 *)(s + 0x20));
        if (*(u8 **)(s + 0x18) != 0) {
            func_003C2880(*(u8 **)(s + 0x18));
            *(u8 **)(s + 0x18) = 0;
        }
        goto dead;
    default:
        goto alive;
    }
dead:
    func_003C2880(obj);
    return;
alive:
    func_L01_00404A10(func_L24_0034D110, obj);
    *(vu0_q *)w = *(vu0_q *)(obj + 0x10);
    func_L24_0034D2C8(obj, w, v);
}
