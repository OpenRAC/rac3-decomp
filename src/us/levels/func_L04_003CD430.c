#include "common.h"

/* NTSC-U counterpart of func_L04_003CF2B8 (src/levels/04_marcadia/L04_003CE760.c) */
#include "vu0.h"

typedef struct { u8 pad[0x50]; f32 f50; u8 pad2[0x9C]; } T_3CE7C8;
extern void func_003886E8(f32 *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(f32 *, void *, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L04_003CD430 */
extern void func_00388550(void *, void *, s32);
extern f32 func_0037E2A8(void);
extern void func_00388BF0(void *, void *);
extern s32 func_003894A0(s32, s32, f32);
extern void func_003D41E0(void *, s32, f32, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E250(f32, f32);

void func_L04_003CD430(u8 *obj) {
    vu0_v4 r;
    vu0_v4 a;
    vu0_v4 p;
    vu0_v4 m1[4];
    vu0_v4 m2[4];
    vu0_v4 m3[4];
    u8 *v = *(u8 **)(obj + 0x68);
    f32 t;
    f32 k0;
    f32 k1;
    s32 i;
    s32 col;

    func_003886E8((f32 *)&a, obj + 0xC0, -0.1f);
    a.z = a.z - 0.15f;
    qzero(&r);
    r.z = func_0037E2A8();
    func_00388BF0(m1, &r);
    func_00388550(m2, m1, 0x40);
    func_00388550(m3, m1, 0x40);
    if (obj[0x20] == 0x13) {
        if (*(s32 *)(v + 0x2F4) >= 7)
            return;
        t = (f32)*(s32 *)(v + 0x2F4) / 6.0f;
        k1 = 1.0f - t * 0.5f;
        k0 = 1.0f - t * 0.9f;
        func_003886E8((f32 *)&m1[0], &m1[0], func_0037E250(0.9f, 1.1f) * 0.55f * k0);
        func_003886E8((f32 *)&m1[1], &m1[1], func_0037E250(0.9f, 1.1f) * 0.55f * k0);
        func_003886E8((f32 *)&m1[2], &m1[2], func_0037E250(0.8f, 1.2f) * 0.45f * k1);
        func_003886E8((f32 *)&m2[0], &m2[0], func_0037E250(0.9f, 1.1f) * 0.3f * k0);
        func_003886E8((f32 *)&m2[1], &m2[1], func_0037E250(0.9f, 1.1f) * 0.3f * k0);
        func_003886E8((f32 *)&m2[2], &m2[2], func_0037E250(0.8f, 1.2f) * 0.9f * k1);
        func_003886E8((f32 *)&m3[0], &m3[0], func_0037E250(0.9f, 1.1f) * 0.15f * k0);
        func_003886E8((f32 *)&m3[1], &m3[1], func_0037E250(0.9f, 1.1f) * 0.15f * k0);
        func_003886E8((f32 *)&m3[2], &m3[2], func_0037E250(0.8f, 1.2f) * k1);
    } else {
        func_003886E8((f32 *)&m1[0], &m1[0], func_0037E250(0.9f, 1.1f) * 0.55f);
        func_003886E8((f32 *)&m1[1], &m1[1], func_0037E250(0.9f, 1.1f) * 0.55f);
        func_003886E8((f32 *)&m1[2], &m1[2], func_0037E250(0.8f, 1.2f) * 0.45f);
        func_003886E8((f32 *)&m2[0], &m2[0], func_0037E250(0.9f, 1.1f) * 0.3f);
        func_003886E8((f32 *)&m2[1], &m2[1], func_0037E250(0.9f, 1.1f) * 0.3f);
        func_003886E8((f32 *)&m2[2], &m2[2], func_0037E250(0.8f, 1.2f) * 0.9f);
        func_003886E8((f32 *)&m3[0], &m3[0], func_0037E250(0.9f, 1.1f) * 0.15f);
        func_003886E8((f32 *)&m3[1], &m3[1], func_0037E250(0.9f, 1.1f) * 0.15f);
        func_003886E8((f32 *)&m3[2], &m3[2], func_0037E250(0.8f, 1.2f));
    }
    for (i = 0; i < 2; i++) {
        func_003BDA38(obj, i + 1, &p);
        vec_sub_ab(&m1[3], &p, &m1[2]);
        vec_add_ab(&m1[3], &m1[3], &a);
        func_003D41E0(m1, 0x1E, 0.0f, 0x7F00307F, 5, 1);
        vec_sub_ab(&m2[3], &p, &m2[2]);
        vec_add_ab(&m2[3], &m2[3], &a);
        func_003D41E0(m2, 0x1E, 0.0f, 0x7F00607F, 5, 1);
        vec_sub_ab(&m3[3], &p, &m3[2]);
        vec_add_ab(&m3[3], &m3[3], &a);
        func_003D41E0(m3, 0x1E, 0.0f, 0x7F00307F, 6, 1);
    }
    if (obj[0x20] == 0x11) {
        if (*(s32 *)(v + 0x2F4) >= 16)
            return;
        t = (f32)*(s32 *)(v + 0x2F4) / 15.0f;
        k0 = t * -0.70000005f + 1.2f;
        k1 = t * 1.6f + 0.15f;
        func_00388830(&m1[0], &m1[0], k0 * func_0037E250(0.95f, 1.05f));
        func_00388830(&m1[1], &m1[1], k0 * func_0037E250(0.95f, 1.05f));
        func_00388830(&m1[2], &m1[2], k1 * func_0037E250(0.95f, 1.05f));
        if (t < 0.8f)
            col = 0x7F20307F;
        else
            col = func_003894A0(0x7F20307F, 0x7F000000, (t - 0.8f) * 5.0f);
        for (i = 0; i < 2; i++) {
            func_003BDA38(obj, i + 1, &p);
            vec_sub_ab(&m1[3], &p, &m1[2]);
            vec_add_ab(&m1[3], &m1[3], &a);
            func_003D41E0(m1, 0x1E, 0.0f, col, 4, 1);
        }
    }
}
/* localdecomp:end func_L04_003CD430 */
