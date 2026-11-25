#include "common.h"

/* localdecomp:start func_L29_003D34E8 */
#include "vu0.h"
typedef int s128_003D34E8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x70];
    s32 w70;
    u8 pad74[0xA];
    u8 b7E;
    u8 pad7F;
    s32 w80;
    u8 pad84[4];
    f32 f88;
    s32 w8C;
    vu0_v4 v90;
    vu0_v4 vA0;
    f32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    s32 wC0;
} P_003D34E8;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[0x13];
    u16 h34;
    u8 pad36[0x32];
    P_003D34E8 *p68;
    u8 pad6C[0x8C];
    f32 fF8;
} M_003D34E8;
extern u8 *D_L29_001DFB1C;
extern u8 D_001A30B0[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void (**func_L01_0043B548(s32, s32))(u8 *);
extern f32 (**func_L01_0043B568(s32, s32, s32))(u8 *);
extern void func_L01_00445438(void *, void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);

void func_L29_003D34E8(M_003D34E8 *self) {
    P_003D34E8 *s1;
    vu0_v4 d;
    f32 t0, t1;
    f32 ang, hf, f20, f21, f22, f23, g0, g1, g2, f1;
    u8 *s0;
    u8 *s0b;
    u8 *e;
    s32 a0;
    s32 a1;

    s1 = self->p68;
    switch (self->b20) {
    case 0:
        s1->fB4 = 0.0f;
        s1->wC0 = -1;
        *(s128_003D34E8 *)&s1->vA0 = *(s128_003D34E8 *)&self->pos;
        ang = func_0038DAB8(self->fF8, s1->w80 != 0 ? 4.71238899f : 1.57079637f);
        d.x = func_0038D098(ang) * s1->fBC;
        d.y = func_0038D0B0(ang) * s1->fBC;
        d.z = 0.0f;
        vec_add_ba(&self->pos, &self->pos, &d);
        *(s128_003D34E8 *)&s1->v90 = *(s128_003D34E8 *)&self->pos;
        if (s1->w70 >= 0) {
            s1->fB8 = s1->fB8 * 0.020000001f;
            s1->fB0 = s1->fB0 * 0.020000001f;
            if (s1->w70 > 0) {
                void (**tt)(u8 *) = func_L01_0043B548(0x19E1, 0x6C);
                s1->w70 = -1;
                s1->b7E = 2;
                (*tt)((u8 *)self);
                return;
            }
        }
        s1->f88 = 0.0f;
        if (s1->w8C >= 0) {
            s0 = D_L29_001DFB1C + (s1->w8C << 8);
            hf = (*func_L01_0043B568(*(s16 *)(s0 + 0xAA), 6, 4))(s0) * s1->fBC;
            s1->f88 = hf;
            func_L01_00445438(&self->pos, &s1->v90, &s1->vA0, hf / s1->fBC);
            func_L01_004450F0(self, 1, -1);
        } else {
            *(s128_003D34E8 *)&self->pos = *(s128_003D34E8 *)&s1->vA0;
            self->h34 = self->h34 | 2;
        }
        break;
    case 1:
        if (s1->w8C == -1) {
            return;
        }
        s0b = D_L29_001DFB1C + (s1->w8C << 8);
        f23 = (*func_L01_0043B568(*(s16 *)(s0b + 0xAA), 6, 4))(s0b) * s1->fBC;
        if (s1->f88 != f23) {
            a0 = s1->wC0;
            if (a0 == -1 || (e = D_001A30B0 + (a0 << 7), *(void **)(e + 0xDC) != self) || e[0xD0] == 0) {
                s1->wC0 = func_003A52A0(0, 4, self);
            }
            f20 = s1->fB0;
            if (f23 < s1->f88) {
                f20 = -f20;
            }
            if (s1->fB4 != 0.0f) {
                g0 = fabs_asm(f23 - s1->f88);
                g1 = fabs_asm(s1->fB4);
                f22 = g0 / g1;
                t0 = 0.0f;
                t1 = 0.0f;
                if (func_L01_004461B8(&t0, &t1, s1->fB0 * -0.5f, g1, -g0) > 0) {
                    if (t0 > 0.0f && f22 < t0) {
                        f20 = -f20;
                    }
                }
            }
            s1->fB4 = s1->fB4 + f20;
            if (s1->fB4 > s1->fB8) {
                s1->fB4 = s1->fB8;
            }
            if (s1->fB4 < -s1->fB8) {
                s1->fB4 = -s1->fB8;
            }
            s1->f88 = s1->f88 + s1->fB4;
            if (s1->f88 > s1->fBC) {
                s1->f88 = s1->fBC;
            }
            if (s1->f88 < 0.0f) {
                s1->f88 = 0.0f;
            }
            if ((s1->fB4 < 0.0f && s1->f88 < f23) || (s1->fB4 > 0.0f && s1->f88 > f23)) {
                s1->f88 = f23;
            }
            func_L01_00445438(&self->pos, &s1->v90, &s1->vA0, s1->f88 / s1->fBC);
        } else {
            s1->fB4 = 0.0f;
            a1 = s1->wC0;
            if (a1 != -1) {
                e = D_001A30B0 + (a1 << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_003A4F28(a1);
                }
            }
            s1->wC0 = -1;
        }
        break;
    }
}
/* localdecomp:end func_L29_003D34E8 */

/* localdecomp:start func_L29_003D3930 */
typedef struct { u8 p0[4]; f32 f4; u8 p8[0x20]; s32 f28; u8 p2C[0x34]; f32 f60; f32 f64; } S_3930_S;
typedef struct { u8 p0[0x80]; s32 f80; u8 p84[8]; s32 f8C; u8 p90[0x20]; f32 fB0; u8 pB4[4]; f32 fB8; f32 fBC; } S_3930_D;
typedef struct { u8 p0[0x68]; void *f68; } S_3930_O;
void func_L29_003D3930(S_3930_O *a0, S_3930_O *a1) {
    S_3930_D *d = a0->f68;
    S_3930_S *s = a1->f68;
    d->f80 = 0;
    if (s->f4 != -1.0f) {
        if (s->f4 < 0.0f) {
            d->f80 = 1;
            d->fBC = -s->f4;
        } else {
            d->fBC = s->f4;
        }
    }
    if (s->f64 >= 0.0f) d->fB0 = s->f64; else d->fB0 = 0.01f;
    if (s->f60 >= 0.0f) d->fB8 = s->f60; else d->fB8 = 1.75f;
    d->f8C = s->f28;
}
/* localdecomp:end func_L29_003D3930 */
