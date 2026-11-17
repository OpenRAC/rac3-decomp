/* NTSC-U draft (2026-11-14, Claude worker): C of func_L43_0041EED8, the NTSC-U twin of func_L43_0041F848, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as + divs row 'func_L43_0041EED8 0 2 0'" (src/levels/shared/L43_0041F848.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_41EED8;
typedef struct { f32 f0; f32 f4; } E_41EED8;
typedef struct { u8 p0[0x68]; E_41EED8 *p68; u8 p6C[0x94]; } T_41EED8;
typedef struct {
    u8 p0[0x80];
    s32 w80;
    u8 p84[4];
    f32 f88;
    s32 w8C;
    V4_41EED8 v90;
    V4_41EED8 vA0;
    f32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    s32 wC0;
} S_41EED8;
typedef struct {
    u8 p0[0x10];
    V4_41EED8 pos;
    u8 b20;
    u8 p21[0xF];
    u8 b30;
    u8 p31[0x68 - 0x31];
    S_41EED8 *st;
    u8 p6C[0xF8 - 0x6C];
    f32 fF8;
} O_41EED8;

extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00442300(void *, void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00443080(f32 *, f32 *, f32, f32, f32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_005F0988(s32);

static __inline__ void qcopy_41EED8(void *dst, void *src) {
    *(u128_t *)dst = *(u128_t *)src;
}

/* localdecomp:start func_L43_0041EED8 */
extern T_41EED8 *D_001DCCCC_sda;
__asm__(".extern D_001DCCCC_sda, 4");
extern u8 D_L43_001FE1A0[];
__asm__(".extern D_L43_001FE1A0, 16");

void func_L43_0041EED8(O_41EED8 *o) {
    S_41EED8 *st;
    V4_41EED8 tmp;
    f32 ang;
    f32 tgt;
    f32 step;
    f32 ratio;
    f32 dist;
    f32 spd;
    f32 a;
    f32 b;
    s32 h;
    u8 *e;

    st = o->st;
    switch (o->b20) {
    case 0:
        st->fB4 = 0.0f;
        st->wC0 = -1;
        qcopy_41EED8(&st->vA0, &o->pos);
        ang = func_00389380(o->fF8, st->w80 != 0 ? 4.712389f : 1.5707964f);
        tmp.x = func_00388960(ang) * st->fBC;
        tmp.y = func_00388978(ang) * st->fBC;
        tmp.z = 0.0f;
        vec_add_ab(&o->pos, &o->pos, &tmp);
        qcopy_41EED8(&st->v90, &o->pos);
        st->fB8 = st->fB8 * 0.016666668f;
        st->fB0 = st->fB0 * 0.016666668f;
        o->b30 = 0xFF;
        st->f88 = 0.0f;
        if (st->w8C >= 0) {
            st->f88 = D_001DCCCC_sda[st->w8C].p68->f4 * st->fBC;
        }
        func_L01_00442300(&o->pos, &st->v90, &st->vA0, st->f88 / st->fBC);
        func_L01_00441FB8(o, 1, -1);
        break;
    case 1:
        if (st->w8C != -1) {
            tgt = D_001DCCCC_sda[st->w8C].p68->f4 * st->fBC;
            if (st->f88 != tgt) {
                h = st->wC0;
                if (h == -1) {
                    st->wC0 = func_L39_005F0CE0(0, 4, o);
                } else {
                    e = D_L43_001FE1A0 + (h << 7);
                    if (*(void **)(e + 0xDC) != (void *)o || e[0xD0] == 0) {
                        st->wC0 = func_L39_005F0CE0(0, 4, o);
                    }
                }
                step = st->fB0;
                if (tgt < st->f88) {
                    step = -step;
                }
                if (st->fB4 != 0.0f) {
                    dist = fabs_asm(tgt - st->f88);
                    spd = fabs_asm(st->fB4);
                    ratio = dist / spd;
                    a = 0.0f;
                    b = 0.0f;
                    if (func_L01_00443080(&a, &b, st->fB0 * -0.5f, spd, -dist) > 0) {
                        if (0.0f < a && ratio < a) {
                            step = -step;
                        }
                    }
                }
                st->fB4 = st->fB4 + step;
                if (st->fB8 < st->fB4) {
                    st->fB4 = st->fB8;
                }
                if (st->fB4 < -st->fB8) {
                    st->fB4 = -st->fB8;
                }
                st->f88 = st->f88 + st->fB4;
                if (st->fBC < st->f88) {
                    st->f88 = st->fBC;
                }
                if (st->f88 < 0.0f) {
                    st->f88 = 0.0f;
                }
                if (st->fB4 < 0.0f && st->f88 < tgt) {
                    st->f88 = tgt;
                }
                if (0.0f < st->fB4 && tgt < st->f88) {
                    st->f88 = tgt;
                }
                func_L01_00442300(&o->pos, &st->v90, &st->vA0, st->f88 / st->fBC);
            } else {
                st->fB4 = 0.0f;
                h = st->wC0;
                if (h != -1) {
                    e = D_L43_001FE1A0 + (h << 7);
                    if (*(void **)(e + 0xDC) == (void *)o && e[0xD0] != 0) {
                        func_L39_005F0988(h);
                    }
                }
                st->wC0 = -1;
            }
        }
        break;
    }
}
/* localdecomp:end func_L43_0041EED8 */
