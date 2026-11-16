#include "common.h"

/* NTSC-U counterpart of func_L09_003E0360 (src/levels/shared/L09_003DF890.c) */
#include "vu0.h"
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; vu0_v4 *vel; } M_003E0360;
typedef struct { u8 p0[1]; u8 b1; u8 p2[0xEE]; } T_003E0360;
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388770(void *);
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);

/* localdecomp:start func_L09_003DE818 */
#include "vu0.h"

extern f32 D_L09_001DF0B4;
__asm__(".extern D_L09_001DF0B4, 4");
extern u8 D_001425C0[];
extern T_003E0360 D_L09_002C5E80[];
extern u8 *D_L09_00220098[];
extern u8 *D_L09_0022016C[];
extern u8 D_001A4EC0[];
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_0046DCB8(void *, void *, s32, s32, s32, s32, s32, f32, s32, f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(f32 *, f32);
extern u8 *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
void func_L09_003DE818(M_003E0360 *m, vu0_v4 *pa, vu0_v4 *pb) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v30;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 v60;
    vu0_v4 *vel;
    f32 len;
    f32 sc;
    s32 n;
    s32 i;
    sc = D_L09_001DF0B4 * 210000.0f;
    a = *pa;
    vel = m->vel;
    b = *pb;
    len = func_00388770(vel);
    n = (s32)(len / 0.1f);
    c = b;
    vec_sub_ab(&d, &a, &b);
    func_00388830(&d, &d, len / (f32)n);
    for (i = 0; i < 10; i++) {
        s32 life = (s32)func_L01_00440918(1.0f, 3.0f);
        s32 r;
        s32 size;
        s32 color;
        u8 *p;
        u8 v;
        T_003E0360 *e;
        T_003E0360 *e2;
        f32 s = func_0037E250(0.1f, 0.3f) * 0.01666666753590107f;
        func_003886E8(&v30, D_001A4EC0, -s);
        r = func_0037E208(6, 0xC);
        if (func_0013D3E0() & 2) {
            size = 0x40;
            color = 0x306FFF;
            e = &D_L09_002C5E80[D_001425C0[0x2F]];
            if (e->b1 == 0) color = 0xFFFF;
        } else {
            size = 0x60;
            color = 0x2020FF;
            e2 = &D_L09_002C5E80[D_001425C0[0x2F]];
            if (e2->b1 == 0) color = 0x207F7F;
        }
        p = func_L01_0046DCB8(&c, &v30, r, color, life, size, 0, sc, 0, sc * 0.05f, 0.0f);
        vec_add_ab(&c, &c, &d);
        if (p != 0) {
            if (func_0037E1D8(2))
                p[2] = D_L09_00220098[0x184 / 4][4];
            else
                p[2] = D_L09_00220098[0x184 / 4][5];
            p[3] = (size == 0x40) ? 0x48 : 0x44;
        }
    }
    {
        s32 color;
        s32 x;
        u8 *p;
        func_003886E8(&v60, vel, -0.033333335071802139f);
        color = 0x7F80DFFF;
        func_003BF6A8(&v60.x, 0.10000000894069672f);
        v60.z += 0.050000004470348358f;
        if (func_0037E1D8(2)) color = 0x7F407FFF;
        x = func_0037E208(10, 20);
        p = func_L01_00462190(&m->pos, &v60, color, 0xFF, x, 0, -1, -1, 0, 94500.0f);
        if (p != 0) {
            *(f32 *)(p + 0x2C) = 0.0016666667070239782f;
            p[2] = *D_L09_0022016C[0];
        }
    }
}
/* localdecomp:end func_L09_003DE818 */
