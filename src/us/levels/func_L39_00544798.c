#include "common.h"

/* NTSC-U counterpart of func_L39_00545028 (src/levels/shared/L39_00544580.c) */
#include "vu0.h"
extern f32 func_003893C8(f32, f32);

/* localdecomp:start func_L39_00544798 */
typedef int u128_00545028 __attribute__((mode(TI)));
typedef struct { u8 pad[0x100]; f32 f100; } Q_00545028;
typedef struct {
    u8 pad0[0x110];
    f32 f110;
    f32 f114;
    u8 pad118[0x320 - 0x118];
    s16 f320;
    u8 pad322[0x2534 - 0x322];
    Q_00545028 *f2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 f2544;
} P_00545028;
typedef struct { u8 pad0[0x2D8]; P_00545028 *f2D8; } T_00545028;
typedef struct {
    u8 pad0[0xA0];
    u8 mA0[0x40];
    u8 mE0[0x40];
    u8 m120[0x40];
    u8 m160[0x40];
    u128_00545028 m1A0[4];
    u128_00545028 m1E0[4];
    u8 pad220[0x2B4 - 0x220];
    f32 f2B4;
    u8 pad2B8[0x2C0 - 0x2B8];
    f32 f2C0;
    f32 f2C4;
    f32 f2C8;
    u8 pad2CC[0x350 - 0x2CC];
    f32 f350;
    u8 pad354[0x384 - 0x354];
    T_00545028 *f384;
    f32 f388;
    f32 f38C;
    f32 f390;
    f32 f394;
    f32 f398;
    f32 f39C;
    f32 f3A0;
    f32 f3A4;
    f32 f3A8;
    u8 pad3AC[0x3BC - 0x3AC];
    s32 f3BC;
} O_00545028;

typedef struct { u8 pad[0xA4]; u8 fA4[4]; } G_00545028;
extern G_00545028 D_001A5990;
extern s32 D_001A5AB0[][8];
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L39_00544568(u8 *);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00389018(void *, s32, f32);
extern f32 func_L01_004455F0(f32 *pos, f32 target, f32 *vel, f32 a, f32 b, f32 c, s32 mode);
extern void func_003BEA80(void *, void *);

void func_L39_00544798(u8 *a) {
    O_00545028 *o = *(O_00545028 **)(a + 0x68);
    P_00545028 *p;
    Q_00545028 *q;
    P_00545028 *r;
    f32 x = 0.0f;
    f32 y = 0.0f;
    f32 z = 0.0f;
    f32 f;
    f32 m;
    f32 d;
    f32 sgn;
    s32 b;
    f32 k;
    f32 t;
    f32 v;

    if (o->f384 != 0) {
        p = o->f384->f2D8;
        if (p != 0) {
            q = p->f2534;
        }
        if (o->f384->f2D8 == 0) {
            func_003BEBF8(&o->f390, 0.04363323375582695f, 0.0024240685161203146f);
        } else {
            f = p->f110;
            m = fabs_asm(f);
            if (o->f384 != 0 && p != 0 && p->f320 > 0) {
                f = 0.0f;
            }
            if (f > 0.0f) {
                y = m * -0.6f;
            } else if (f < 0.0f) {
                x = m * -0.6f;
            }
            z = f * 0.3f;

            f = o->f384->f2D8->f114;
            if (o->f384 != 0 && o->f384->f2D8 != 0 && o->f384->f2D8->f320 > 0) {
                f = 0.0f;
            }
            m = fabs_asm(f);
            if (f > 0.0f) {
                d = m * 0.5f;
                y += d;
                x += d;
            } else if (f < 0.0f) {
                d = m * -0.6f;
                y += d;
                x += d;
            }

            r = o->f384->f2D8;
            b = D_001A5990.fA4[r->f2544];
            sgn = 1.0f;
            if (D_001A5AB0[b][r->f2544] != 0) {
                sgn = -1.0f;
            }
            if (b == 0) {
                sgn = 1.0f;
            }
            f = q->f100 * sgn;
            if (o->f384 != 0 && o->f384->f2D8 != 0 && o->f384->f2D8->f320 > 0) {
                f = 0.0f;
            }
            m = fabs_asm(f);
            if (f > 0.0f) {
                y += m * -0.6f;
                x += m * 0.5f;
            } else if (f < 0.0f) {
                y += m * 0.5f;
                x += m * -0.6f;
            }
            if (y > 0.5f) {
                y = 0.5f;
            }
            if (y < -0.6f) {
                y = -0.6f;
            }
            if (x > 0.5f) {
                x = 0.5f;
            }
            if (x < -0.6f) {
                x = -0.6f;
            }
            z += f * 0.3f;
            if (z > 0.3f) {
                z = 0.3f;
            }
            if (z < -0.3f) {
                z = -0.3f;
            }
            if (o->f3BC == 0) {
                t = y;
                y = x;
                x = t;
            }
        }
        func_L39_00544568(a);
    }
    k = 0.02908882312476635f;
    o->f388 = func_003893C8(o->f388, o->f390);
    o->f38C = func_00389380(o->f38C, o->f390);
    func_00389018(o->mA0, 2, o->f388);
    func_00389018(o->mE0, 2, o->f38C);
    func_003BEBF8(&o->f394, y, k);
    func_003BEBF8(&o->f39C, x, k);
    func_00389018(o->m120, 1, o->f394);
    func_00389018(o->m160, 1, o->f39C);
    v = func_00389380(o->f350, o->f2B4);
    func_L01_004455F0(&o->f2C4, -v, &o->f3A4, 0.019999999552965164f, 0.15000000596046448f, k, 0);
    func_L01_004455F0(&o->f2C8, o->f3BC != 0 ? -z : z, &o->f3A8, 0.00800000037997961f, 0.20000000298023224f, k, 0);
    func_003BEA80(o->m1A0, &o->f2C0);
    o->m1E0[0] = o->m1A0[0];
}
/* localdecomp:end func_L39_00544798 */
