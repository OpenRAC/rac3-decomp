#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003E75B0 */
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044C3C0(void *, void *, void *, void *, f32, f32, void *, f32, f32, s32);
extern void func_003C48A8(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L09_003E7DA8(u8 *);
extern u8 D_001D9B60[] __attribute__((section(".sdata")));
extern s32 D_001ED940[];
typedef struct { u8 pad[0x1DC]; s16 f1DC; } H_003E75B0;
extern H_003E75B0 D_001A4BE0;
extern vu0_v4 D_001A4C60;

void func_L09_003E75B0(u8 *a0) {
    u8 *v;
    u8 *pos;
    s32 n;
    s32 i;
    f32 d;
    vu0_v4 old;
    vu0_v4 diff;
    u8 buf[32];
    vu0_v4 tgt;

    pos = a0 + 0x10;
    v = *(u8 **)(a0 + 0x68);
    old = *(vu0_v4 *)(a0 + 0x10);
    if (v[0x2F] == 0) {
        vec_sub_ba(&diff, a0 + 0x10, v + 0x10);
        if (v[0x2E] == 0 && func_0038CE68(a0 + 0xC0, &diff) < 0.0f) {
            d = func_0038DB00(func_0038D160(*(f32 *)(v + 0x10) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(v + 0x14) - *(f32 *)(a0 + 0x14)),
                              *(f32 *)(a0 + 0xF8));
            if (d > 0.0104719764f) {
                d = 0.0104719764f;
            } else if (d < -0.0104719764f) {
                d = -0.0104719764f;
            }
            *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), d);
        }
    } else {
        if (v[0x2F] == 1) {
            func_L01_0044C3C0(pos, a0 + 0xC0, v + 0x10, v + 0x28, 0.003f, 0.003f, D_001D9B60, 0.0f, 0.0f, 0);
            func_003C48A8(a0 + 0xC0, a0 + 0xF0);
        } else {
            func_L01_0044C3C0(pos, a0 + 0xC0, v + 0x10, v + 0x28, 0.003f, 0.003f, D_001D9B60, 0.0f, 7.0f, 0);
            func_003C48A8(a0 + 0xC0, a0 + 0xF0);
        }
    }
    func_0038CF68(a0 + 0xC0, a0 + 0xC0, 1.0f);
    func_0038CE20(v, a0 + 0xC0, *(f32 *)(v + 0x24));
    vec_add_ab(a0 + 0x10, v, a0 + 0x10);
    if (v[0x2F] == 0) {
        func_L01_00446748(buf, a0, v[0x2E] ? 0x1090001 : 0x1010001, (f32)*(s16 *)(v + 0x2C));
        if (func_003D3CB0(&old, a0 + 0x10, 0, *(void **)(a0 + 0xB8), buf) != 0
            || func_003D4D00(a0 + 0x10, 0, 0.1f, *(void **)(a0 + 0xB8), buf) != 0) {
            func_003A52A0(0, 0, a0);
            func_L01_003303B8(a0 + 0x10, 0, 5, 5, 5, 5, 10, 1, 0.8f, 0.0f, 0.0f, 2.0f,
                0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003C2880(a0);
        } else {
            goto miss;
        }
    } else {
        n = func_003D4D00(a0 + 0x10, 1, 1.0f, a0, 0);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (D_001ED940[i] == *(s32 *)(v + 0x20)) {
                    if (v[0x2F] == 2) {
                        func_0038CE20(&tgt, *(u8 **)(a0 + 0xB8) + 0xC0, 10.0f);
                        tgt.w = 5627.9248f;
                    } else {
                        func_0038CE20(&tgt, *(u8 **)(a0 + 0xB8) + 0xC0, 4.0f);
                        tgt.w = 5627.9248f;
                    }
                    func_L01_00446760(&diff, a0, 1, &tgt, (f32)*(s16 *)(v + 0x2C));
                    if (v[0x2F] == 2) {
                        D_001A4BE0.f1DC = 0;
                    }
                    func_L01_00446978((void *)D_001ED940[i], &diff);
                    func_003A52A0(0, 0, a0);
                    func_L01_003303B8(a0 + 0x10, 0, 5, 5, 5, 5, 10, 1, 0.8f, 0.0f, 0.0f, 2.0f,
                        0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                        0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                    func_003C2880(a0);
                    return;
                }
            }
        }
        if (func_003D3CB0(&old, a0 + 0x10, 0, *(void **)(a0 + 0xB8), 0) != 0
            || func_L01_003FB640(a0 + 0x10, 0, 0.1f, *(void **)(a0 + 0xB8)) != 0) {
            func_L01_00446748(&diff, a0, 0x10000, (f32)*(s16 *)(v + 0x2C));
            func_003D4D00(a0 + 0x10, 0, 1.7f, a0, &diff);
            func_003A52A0(0, 0, a0);
            func_L01_003303B8(a0 + 0x10, 0, 5, 5, 5, 5, 10, 1, 0.8f, 0.0f, 0.0f, 2.0f,
                0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003C2880(a0);
        } else {
            goto miss;
        }
    }
    return;
miss:
    if (*(u8 **)(v + 0x20) != 0 && *(s16 *)(*(u8 **)(v + 0x20) + 0xAA) == 0 && v[0x2F] == 2) {
        *(vu0_v4 *)(v + 0x10) = D_001A4C60;
    }
    func_L09_003E7DA8(a0);
}
/* localdecomp:end func_L09_003E75B0 */

/* localdecomp:start func_L09_003E7BC0 */
extern vu0_v4 D_001A4CB0;

extern void *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(void *);

u8 *func_L09_003E7BC0(s32 a0, vu0_v4 *pos, vu0_v4 *rot, u8 *a3, s16 a4, s32 a5, s32 a6, s32 a7) {
    u8 *o;
    u8 *v;
    u8 *p;
    vu0_v4 m;

    o = func_003C24B0(0x1C0C, 0x80);
    if (o != 0) {
        o[0x30] = 0xFF;
        *(s32 *)(o + 0xB8) = a0;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 0.4f;
        v = *(u8 **)(o + 0x68);
        *(vu0_v4 *)(o + 0x10) = *pos;
        *(vu0_v4 *)v = *rot;
        *(u8 **)(v + 0x20) = a3;
        *(f32 *)(v + 0x24) = func_0038CEA8(rot);
        *(s16 *)(v + 0x2C) = a4;
        v[0x2E] = a5;
        if (a7 != 0) {
            v[0x2F] = 2;
        } else if (a6 != 0) {
            v[0x2F] = 1;
        } else {
            v[0x2F] = 0;
        }
        p = *(u8 **)(v + 0x20);
        if (p != 0 && *(s16 *)(p + 0xAA) == 0 && v[0x2F] != 2) {
            *(vu0_v4 *)(v + 0x10) = D_001A4CB0;
        } else if (p != 0) {
            *(vu0_v4 *)(v + 0x10) = *(vu0_v4 *)(p + 0x10);
        }
        func_0038CF68(&m, rot, 1.0f);
        *(vu0_v4 *)(o + 0xC0) = m;
        func_0038CE90(o + 0xD0, o + 0xC0, D_001D9B60);
        func_0038CF68(o + 0xD0, o + 0xD0, 1.0f);
        func_0038CE90(o + 0xE0, o + 0xD0, o + 0xC0);
        *(f32 *)(o + 0xCC) = *(f32 *)(o + 0xDC) = *(f32 *)(o + 0xEC) = 0.0f;
        func_003C48A8(o + 0xC0, o + 0xF0);
        func_003C7C38(o);
    }
    return o;
}
/* localdecomp:end func_L09_003E7BC0 */

/* localdecomp:start func_L09_003E7DA8 */
extern s32 D_L09_001DF2A8;
__asm__(".extern D_L09_001DF2A8, 4");
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0046E078(u8 *, void *, f32 *, s32 *, s32);

void func_L09_003E7DA8(u8 *a0) {
    u8 *p;
    f32 r0;
    f32 pos[4];
    f32 vel[4];
    p = *(u8 **)(a0 + 0x68);
    r0 = func_0038CEA8(p);
    vel[0] = func_003824E0(-1.0f, -0.9f) * r0;
    vel[1] = func_003824E0(-0.05f, 0.05f) * r0;
    vel[2] = func_003824E0(-0.05f, 0.05f) * r0;
    vec_sub_ab(pos, a0 + 0x10, p);
    func_L01_0046E078(a0, pos, vel, &D_L09_001DF2A8, 1);
}
/* localdecomp:end func_L09_003E7DA8 */
