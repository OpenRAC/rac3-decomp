#include "common.h"

/* NTSC-U counterpart of func_L40_004272D0 (src/levels/shared/L40_004272D0.c) */
extern f32 func_L01_0040C018(void *a, void *b);
extern u8 *func_L39_0061B038(void *);

/* localdecomp:start func_L40_004269C0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004272D0;
typedef struct {
    u8 pad0[0x1F8];
    f32 a[1];
} D_004272D0;
typedef struct {
    u8 pad0[0x80];
    u8 j80[0x60];
    f32 fE0;
    f32 fE4;
    f32 fE8;
    u8 padEC[0x200 - 0xEC];
    V_004272D0 p200;
    V_004272D0 p210;
    u8 pad220[0x10];
    u8 *m230;
    u8 pad234[0x274 - 0x234];
    f32 f274;
    f32 f278;
    s32 f27C;
    u8 pad280[0x2A0 - 0x280];
    s32 f2A0;
} P_004272D0;

extern D_004272D0 D_L40_003573E0;
extern u8 D_L40_003BFF60[];
extern f32 *func_0037E0B8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L40_004269C0(u8 *a0) {
    V_004272D0 pos;
    V_004272D0 old;
    V_004272D0 d;
    u32 buf[2];
    P_004272D0 *v;
    f32 *dmg;
    u8 *g;
    u8 *r;
    f32 f;
    f32 s;
    s32 x;

    v = *(P_004272D0 **)(a0 + 0x68);
    if (v->m230 != 0 && v->f2A0 == 0) {
        g = 0;
        dmg = func_0037E0B8(v->m230);
        pos = *(V_004272D0 *)(v->m230 + 0x10);
        r = func_L39_0061B038(v->m230);
        if (r != 0 && (r[3] & 0xF) == 0) {
            g = r;
        }
        f = 0.0f;
        if (dmg != 0 && g != 0) {
            func_003886E8(&d, v->m230 + 0xE0, dmg[4] * -0.4f);
            vec_add_ab(&pos, &pos, &d);
            {
                u8 *p = g + 0x19E4;
                u8 *b;
                s32 m;
                s32 k;
                s32 n;
                s32 i;
                long t;

                t = *p;
                x = 0;
                if (t != 0) {
                    n = *p;
                    m = n + 1;
                    k = ((s32)p - n) & 7;
                    b = (u8 *)buf;
                    for (i = 0; i < 40; i += 5) {
                        *b++ = D_L40_003BFF60[m + ((k + i) & 7) * 255];
                    }
                    buf[0] ^= (u32)p;
                    buf[1] ^= buf[0];
                    x = buf[1];
                }
            }
            if ((x ^ 4) == 0 || g[0x24FD] != 0) {
                f = -0.25f;
            }
        }
        old = pos;
        if (func_L01_0040C018(&v->p210, &pos) < 0.0001f) {
            if (dmg != 0) {
                pos = *(V_004272D0 *)(v->m230 + 0x10);
                func_003886E8(&d, v->m230 + 0xE0, dmg[4] + f);
            } else {
                v->p200.x = ((f32 *)v->m230)[0] * 0.0009765625f;
                v->p200.y = ((f32 *)v->m230)[1] * 0.0009765625f;
                v->p200.z = ((f32 *)v->m230)[2] * 0.0009765625f;
                v->p200.w = 0.0f;
                goto store;
            }
        } else {
            vec_sub_ab(&d, &pos, &v->p210);
            f = 1.0f;
            s = D_L40_003573E0.a[v->f27C] * 4.5f;
            if (s < f) {
                s = f;
            }
            func_003886E8(&d, &d, s);
            if (g != 0) {
                if (f < d.z) {
                    d.z = f;
                } else if (d.z < -1.0f) {
                    d.z = -1.0f;
                }
            }
        }
        vec_add_ab(&pos, &pos, &d);
store:
        v->p210 = old;
        v->p200 = pos;
        func_003BDA38(a0, 0, &d);
        v->fE0 = -func_00388A28(func_00388800(&v->p200, &d), d.z - v->p200.z);
        v->fE8 = func_00389380(func_00388A28(d.x - v->p200.x, d.y - v->p200.y),
                               -(*(f32 *)(a0 + 0xF8) - 1.5707964f));
        if (0.61086524f < v->fE0) {
            v->fE0 = 0.61086524f;
        }
        if (v->fE0 < -0.61086524f) {
            v->fE0 = -0.61086524f;
        }
    } else {
        qzero(&v->fE0);
    }
    func_L01_0044B5C8(a0, v->j80, 0, v->f274 + D_L40_003573E0.a[v->f27C] * 0.009f,
                      v->f278);
}
/* localdecomp:end func_L40_004269C0 */
