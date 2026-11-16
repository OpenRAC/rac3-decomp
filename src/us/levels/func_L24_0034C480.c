#include "common.h"

/* NTSC-U counterpart of func_L24_0034D2C8 (src/levels/24_insomniac_museum/L24_0034D2C8.c) */
/* localdecomp:start func_L24_0034C480 */
#include "vu0.h"
/* from rac3-decomp's func_L01_0035BC18 (level 1), the same spark trail */
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; vu0_v4 *vel; } M_34D2C8;
extern u8 *D_L24_0021EFD8_0034C480[];
extern u8 *D_L24_0021F0AC_0034C480[];
extern vu0_v4 D_001A4EC0;
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(f32 *, f32);
extern u8 *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L24_0034C480(M_34D2C8 *m, vu0_v4 *pa, vu0_v4 *pb) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v30;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 *vel;
    f32 len;
    s32 n;
    s32 i;
    s32 color;
    s32 x;
    u8 *p;
    a = *pa;
    vel = m->vel;
    b = *pb;
    len = func_00388770(vel);
    n = (s32)(len / 0.1f);
    c = b;
    vec_sub_ab(&d, &a, &b);
    func_00388830(&d, &d, len / (f32)n);
    v60 = D_001A4EC0;
    for (i = 0; i < n; i++) {
        s32 life = (s32)func_L01_00440918(1.0f, 3.0f);
        s32 r;
        s32 size;
        s32 color;
        u8 *p;
        f32 s = func_0037E250(0.1f, 0.2f) * 0.0166666675359f;
        func_003886E8(&v30, &v60, -s);
        r = func_0037E208(2, 4);
        if (func_0013D3E0() & 2) {
            size = 0x40;
            color = 0x7F0000FF;
        } else {
            size = 0x60;
            color = 0x7F0000FF;
        }
        p = func_L01_00466F98(&c, &v30, r, size, color, life, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&c, &c, &d);
        if (p != 0) {
            p[2] = *D_L24_0021EFD8_0034C480[0x5C / 4];
            p[3] = (size == 0x40) ? 0x48 : 0x44;
        }
    }
    func_003886E8(&v70, vel, -0.0333333350718f);
    color = 0x7F1010FF;
    func_003BF6A8(&v70.x, 0.0333333350718f);
    v70.z += 0.0333333350718f;
    if (func_0037E1D8(2)) color = 0x7F2020FF;
    x = func_0037E208(10, 20);
    p = func_L01_00462190(&m->pos, &v70, color, 0xFF, x, 0, -1, -1, 0, 73500.0f);
    if (p != 0) {
        *(f32 *)(p + 0x2C) = 0.00166666670702f;
        p[2] = *D_L24_0021F0AC_0034C480[0];
    }
}
/* localdecomp:end func_L24_0034C480 */
