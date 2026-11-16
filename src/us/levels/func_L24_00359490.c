#include "common.h"

/* NTSC-U counterpart of func_L24_0035A580 (src/levels/24_insomniac_museum/L24_0035A580.c) */
/* localdecomp:start func_L24_00359490 */
#include "vu0.h"

typedef int u128_35A580 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35A580;
typedef struct {
    u8 pad0[0x44];
    u8 f44;
    u8 pad45[0x160 - 0x45];
    V4_35A580 v160;
    V4_35A580 v170;
    u8 pad180[0x196 - 0x180];
    s16 f196;
    u8 pad198[0x1AC - 0x198];
    f32 f1AC;
    u8 pad1B0[0x10];
    u8 f1C0[0x10];
} S_35A580;
typedef struct {
    u8 pad0[0x10];
    V4_35A580 pos;
    u8 state;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0x68 - 0x36];
    S_35A580 *vars;
    u8 pad6C[0xC0 - 0x6C];
    V4_35A580 vC0;
    V4_35A580 vD0;
    V4_35A580 vE0;
} O_35A580;

extern void func_L24_00359460(void *, f32);
extern s32 func_L24_003A3290(void *, void *, void *, f32);
extern void func_L24_003A3790(void *, void *);
extern f32 func_00388800(void *, void *);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern void func_003BF2F8(void *, void *, f32);
extern void func_00389118(void *, void *, void *);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_00443648(void *, void *, s32, s32, f32, f32, f32, s32, s32);
extern s32 func_L01_004435E8(void *);
extern f32 D_L24_001DD600_00359490, D_L24_001DD604_00359490, D_L24_001DD608, D_L24_001DD60C, D_L24_001DD610_00359490;
__asm__(".extern D_L24_001DD600_00359490, 4");
__asm__(".extern D_L24_001DD604_00359490, 4");
__asm__(".extern D_L24_001DD608, 4");
__asm__(".extern D_L24_001DD60C, 4");
__asm__(".extern D_L24_001DD610_00359490, 4");
extern s32 D_L24_001DD68C;
__asm__(".extern D_L24_001DD68C, 4");
extern u8 *D_L24_0021F034_00359490[];
extern void *D_L24_001ECFC0_00359490[];

s32 func_L24_00359490(O_35A580 *self) {
    S_35A580 *s;
    V4_35A580 q;
    V4_35A580 v;
    V4_35A580 w;
    V4_35A580 t;
    s32 ret;
    f32 ang;
    f32 f;
    s32 cnt;
    s32 i;
    u8 *rr;

    s = self->vars;
    ret = 1;
    func_L24_00359460(self, -s->v170.z);
    vec_sub_ab(&self->pos, &self->pos, &s->v170);
    if ((u32)(self->state - 9) < 2) {
        q = self->pos;
        if (func_L24_003A3290(s->f1C0, self, &s->v160, -1e13f) & 0xA) {
            ret = 0;
        }
        ang = func_00388800(&q, &self->pos) * D_L24_001DD610_00359490;
        if (s->f196 >= 11) {
            v = self->pos;
            func_003BF6A8(&v, 0.2f);
            *(u128_35A580 *)&t = 0;
            t.z = func_0037E250(0.25f, 1.0f) * 0.0166666675f;
            w = t;
            f = func_0037E250(0.3f, 1.0f) * 210000.0f;
            rr = func_L01_0046C468(&v, &w, func_0037E208(0x23, 0x3C), 0x128090A0, func_0037E1D8(2) == 0 ? -1 : 1, 8, 0, f, f, 0, 0.0f);
            if (rr != 0) {
                rr[2] = D_L24_0021F034_00359490[0][0];
                rr[3] = 0x44;
            }
        }
    } else {
        func_L24_003A3790(s->f1C0, self);
        ang = s->f1AC;
    }
    self->f34 |= 0x100;
    func_003BF2F8(&q, &self->vD0, ang);
    func_00389118(&self->vC0, &self->vC0, &q);
    func_00389118(&self->vE0, &self->vE0, &q);
    *(u128_35A580 *)&w = 0;
    w.x = D_L24_001DD600_00359490;
    w.z = D_L24_001DD604_00359490;
    w.w = 1.0f;
    v = w;
    func_003888C8(&s->v170, &v, &self->vC0);
    s->v170.z += D_L24_001DD608;
    func_L24_00359460(self, s->v170.z);
    w = self->pos;
    vec_add_ab(&self->pos, &self->pos, &s->v170);
    if (self->state != 9) {
        return ret;
    }
    w.z += D_L24_001DD608;
    cnt = func_L01_00443648(self, &w, 0x8010001, 0, D_L24_001DD60C, (f32)s->f44, 1.0f, 1, 0);
    if (s->f196 < D_L24_001DD68C - (D_L24_001DD68C >> 2)) {
        for (i = 0; i < cnt; i++) {
            if (func_L01_004435E8(D_L24_001ECFC0_00359490[i]) == 0) {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L24_00359490 */
