#include "common.h"

/* NTSC-U counterpart of func_L22_00343C18 (src/levels/22_mylon/L22_00343800.c) */
#include "vu0.h"
extern u8 D_L22_001D66B0_00343338[8];
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E1D8(s32);

/* localdecomp:start func_L22_00343338 */
typedef struct {
    vu0_v4 vel;
    u16 x10;
    s16 x12;
    void *x14;
    s32 x18;
    s32 x1C;
    f32 x20;
    u8 *x24;
    f32 x28;
} S_343C18v;

extern u8 D_L22_001D66B0_00343338[8];
extern u8 *D_L22_001E9858_00343338[];
extern vu0_v4 D_L22_001E9860_00343338[];
extern void func_L22_00342F20(vu0_v4 *, s32, s32);
extern u8 *func_0037E0B8(s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_00388990(f32);
extern f32 func_00389410(f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_003883C8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003BD360(void *);

void func_L22_00343338(u8 *p) {
    vu0_v4 np;
    vu0_v4 v10;
    vu0_v4 dir;
    u8 info[0x30];
    vu0_v4 v60;
    S_343C18v *st;
    u8 *t;
    u8 *h;
    void *o;
    u8 *r;
    f32 a;
    f32 k;
    f32 sz;
    s32 hit;
    s32 n;
    s32 i;

    st = *(S_343C18v **)(p + 0x68);
    switch (p[0x20]) {
    case 0:
        *(u16 *)(p + 0x96) += 1;
        t = st->x24;
        if (t != 0) {
            r = func_0037E0B8((s32)t);
            if (t[0x20] == 0xFE) {
                st->x24 = 0;
            } else if (t[0x20] == 0xFD) {
                st->x24 = 0;
            } else if (r != 0 && *(f32 *)r <= 0.0f) {
                st->x24 = 0;
            } else if (*(u16 *)(p + 0x96) >= 6) {
                dir = *(vu0_v4 *)(t + 0x10);
                dir.z += *(f32 *)(t + 0xC) * 0.0009765625f;
                vec_sub_ba(&dir, &dir, p + 0x10);
                func_00388830(&dir, &dir, 1.0f);
                func_00388830(&v10, st, 1.0f);
                a = func_00389410(func_00388990(func_00388730(&dir, &v10)) + 1.5707964f);
                k = 1.0f;
                if (st->x28 < a) {
                    k = st->x28 / a;
                }
                func_003BEB58(&dir, &v10, &dir, k);
                func_00388830(st, &dir, func_00388770(st));
            }
        }
        vec_add_ba(&np, p + 0x10, st);
        if (st->x12 < 12) {
            st->x12++;
        }
        func_L01_00443628(info, p, 0x10001, D_L22_001D66B0_00343338, st->x18);
        o = st->x14;
        func_L01_004C76B8();
        hit = func_003CE740(p + 0x10, &np, 0, o, info);
        if (hit != 0) {
            h = D_L22_001E9858_00343338[0];
            if (h != 0 && *(s16 *)(h + 0xAA) == 0x186D && h[0x20] != 2 && h[0x20] != 5) {
                h[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit != 0) {
            *(s32 *)(p + 0x98) = 0;
            *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(p, 1);
            func_L01_00441FB8(p, 1, -1);
            func_L22_00342F20(D_L22_001E9860_00343338, 0xA, 1);
        } else if (func_003883C8(&st->x10) != 0) {
            *(s32 *)(p + 0x98) = 0;
            *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(p, 1);
            func_L01_00441FB8(p, 1, -1);
        } else {
            v10 = *(vu0_v4 *)(p + 0x10);
            func_003886E8(&dir, st, 0.2f);
            for (i = 0; i < 5; i++) {
                sz = func_0037E250(0.1f, 0.3f) * st->x20;
                n = func_0037E1D8(0xFF);
                func_L01_00440A88(&v60, 0.0f, 0.1f);
                vec_add_ba(&v60, &v60, &v10);
                func_L01_0046C468(&v60, D_L22_001D66B0_00343338, 0xF, st->x1C, n, 0x20, 0, sz * 210000.0f, sz * 0.2f * 210000.0f, 0.0f, 0);
                vec_add_ab(&v10, &v10, &dir);
            }
        }
        *(vu0_v4 *)(p + 0x10) = np;
        break;
    case 1:
        if (--st->x12 == -1) {
            func_003BD360(p);
        }
        break;
    }
}
/* localdecomp:end func_L22_00343338 */
