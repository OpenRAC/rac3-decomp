#include "common.h"

/* NTSC-U counterpart of func_003A62D0 (src/frontbin/3A6178.c): 1/60 for 0.02, no 50 to 60 Hz scaling of the f40 count */
/* localdecomp:start func_U_003A0EB0 */
typedef int u128_t_003A0EB0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V_003A0EB0;
typedef struct {
    V_003A0EB0 v;
    u128_t_003A0EB0 q10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C;
} T_003A0EB0;
extern s32 D_U_001D6FA0[2];
__asm__(".extern D_U_001D6FA0, 8");
extern s32 D_U_001DA090[2];
extern s32 D_U_002257B4[];
extern void func_U_003BD9A0();
extern void func_U_003888F0();
extern s32 func_U_003894A0(s32, s32, f32);
extern void func_U_003886E8(f32 *, void *, f32);
extern void func_U_003A0D58(void *, void *, s32, f32, f32, f32, s32);
extern void func_U_003A2EE0_003A0EB0(void *, s32);
extern f32 func_U_0037E250(f32, f32);
extern s32 func_U_0037E208(s32, s32);
extern void func_U_003A2E40(s32, u8 *);
extern f32 func_U_0037E2A8(void);
/* from the NTSC decomp's func_003A0EB0 */
void func_U_003A0EB0(void *op, s32 idx, s32 flag) {
    u8 *o = (u8 *)op;
    f32 m0[4];
    f32 v[4];
    f32 m1[16];
    T_003A0EB0 t;
    V_003A0EB0 *e;
    f32 s;
    f32 f24, f28, f27, f25, f22, f23, f26, f21;
    s32 i20, i21, c1, c2, x;
    func_U_003BD9A0(o, 0, m1);
    e = &((V_003A0EB0 *)D_U_001D6FA0)[idx];
    func_U_003888F0(m0, e, m1);
    s = (f32)o[0x95] * 0.0078125f * e->w;
    f24 = s * 0.0599999987f + 0.0599999987f;
    i20 = s * 5.0f + 25.0f;
    f25 = s * 0.0399999991f + 0.0399999991f;
    f22 = s * 0.375f + 0.375f;
    f27 = s * 0.0249999911f + 0.174999997f;
    i21 = s * 5.0f + 15.0f;
    f28 = s * 0.0f + 0.0749999955f;
    f23 = s * 0.099999994f + 0.099999994f;
    f26 = s * 0.0249999985f + 0.0249999985f;
    f21 = s * 0.0749999955f + 0.0749999955f;
    c1 = func_U_003894A0(0x40204080, 0x40205080, s);
    c2 = func_U_003894A0(-1, -1, s);
    if (flag == 0 && (s8)o[0x95] >= 0) {
        c1 = (c1 & 0xFFFFFF) | ((((c1 >> 24) * o[0x95]) >> 7) << 24);
        c2 = (c2 & 0xFFFFFF) | ((((c2 >> 24) * o[0x95]) >> 7) << 24);
    }
    func_U_003886E8(v, m1, -f24);
    func_U_003A0D58(m0, v, i20, f22, f23, f21, c1);
    if (idx == 0) {
        func_U_003886E8(v, m1, -f25);
        func_U_003A0D58(m0, v, i21, f27, f26, f28, c2);
    }
    func_U_003A2EE0_003A0EB0(o, 0x3F3F3F);
    x = func_U_003894A0(0x2F7F, 0x7F7F, func_U_0037E250(0.0f, 1.0f));
    *(u128_t_003A0EB0 *)&t.v = *(u128_t_003A0EB0 *)m0;
    t.f2C = x;
    t.f30 = x;
    t.v.x += func_U_0037E250(-0.0250000004f, 0.0250000004f);
    t.v.y += func_U_0037E250(-0.0250000004f, 0.0250000004f);
    t.v.z += func_U_0037E250(-0.0250000004f, 0.0250000004f);
    t.q10 = *(u128_t_003A0EB0 *)D_U_001DA090;
    t.f24 = func_U_0037E2A8();
    t.f20 = func_U_0037E250(90.0f, 180.0f) * 0.0174532924f * 0.0166666675f;
    t.f4C = 5;
    t.f3C = 1;
    if (flag != 0) {
        t.f38 = t.f34 = func_U_0037E208(0x28, 0x38);
        t.f40 = t.f44 = func_U_0037E208(0x32, 0x3C);
        t.f28 = func_U_0037E250(0.800000012f, 1.5f);
        if (o[0x95] >= 0x41) func_U_003A2E40((s32)o, (u8 *)&t);
    } else {
        t.f38 = t.f34 = func_U_0037E208(0x1F, 0x3F);
        t.f40 = t.f44 = func_U_0037E208(0x46, 0x5A);
        t.f28 = func_U_0037E250(1.0f, 2.0f);
        t.f3C |= ((D_U_002257B4[0] & 1) + 1) << 1;
        func_U_003A2E40((s32)o, (u8 *)&t);
    }
}
/* localdecomp:end func_U_003A0EB0 */
