#include "common.h"

/* NTSC-U counterpart of func_L09_003F1600 (src/levels/09_tyhrranosis/L09_003F1600.c) */
/* localdecomp:start func_L09_003EF778 */
#include "vu0.h"

typedef struct { u8 _p0[0x10]; u8 *p10; } G_003F1600;

extern G_003F1600 D_L09_00220098;
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L09_003EF778(void *arg) {
    u8 *self = arg;
    vu0_v4 v;
    vu0_v4 c;
    vu0_v4 w;
    f32 scale;
    s32 i;

    scale = *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    func_003886E8(&w, self + 0xE0, 4.0f);
    for (i = 9; i >= 0; i--) {
        s32 color = 0x7F668A90;
        f32 a = func_0037E2A8();
        f32 size = scale * 210000.0f;
        f32 hi, lo, t, sn, len;
        s32 k;
        u8 *p;

        sn = func_00388960(a);
        hi = scale * 4.0f;
        lo = hi * 0.5f;
        v.x = sn * func_0037E250(lo, hi);
        v.y = func_00388978(a) * func_0037E250(lo, hi);
        v.z = func_0037E250(-3.0f, 3.0f) * scale;
        *(s32 *)&v.w = 0;
        vec_add_ab(&v, self + 0x10, &v);
        vec_add_ab(&v, &w, &v);
        func_0037E2F0(&c, 0.0031250002794f, 0.00520833348855f);
        if (func_0037E1D8(4) != 0) {
            color = 0x7F426066;
        }
        k = func_0037E208(-2, 2);
        len = scale * 2.5f * 210000.0f;
        t = func_0037E250(-0.3f, -1.0f);
        p = func_L01_00472438(&v, &c, 0x46, k, color, 0x426066, size, len, t, 0);
        if (p != 0) {
            p[2] = *D_L09_00220098.p10;
            p[3] = func_0037E1D8(2) ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L09_003EF778 */
