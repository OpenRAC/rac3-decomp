/* NTSC-U draft (2026-11-14, Claude worker): C of func_L29_003D18C0, the NTSC-U twin of func_L29_003D34E8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/29_tyhrranosis_ranger_missions/L29_003D34E8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"

/* NTSC-U counterpart of func_L29_003D34E8 (src/levels/29_tyhrranosis_ranger_missions/L29_003D34E8.c) */
#include "vu0.h"

/* localdecomp:start func_L29_003D18C0 */
typedef int s128_003D18C0 __attribute__((mode(TI)));
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
} P_003D18C0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[0x13];
    u16 h34;
    u8 pad36[0x32];
    P_003D18C0 *p68;
    u8 pad6C[0x8C];
    f32 fF8;
} M_003D18C0;
extern u8 *D_L29_001DFB1C;
extern u8 D_001A30B0[];
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void (**func_L01_00438468(s32, s32))(u8 *);
extern f32 (**func_L01_00438488(s32, s32, s32))(u8 *);
extern void func_L01_00442300(void *, void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00443080(f32 *, f32 *, f32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);

void func_L29_003D18C0(M_003D18C0 *self) {
    P_003D18C0 *s1;
    vu0_v4 d;
    f32 t0, t1;
    f32 ang, hf, f20, f21, f22, f23, g0, g1, g2, f1;
    u8 *s0;
    u8 *s0b;
    u8 *e;
    s32 a0;

    s1 = self->p68;
    switch (self->b20) {
    case 0:
        s1->fB4 = 0.0f;
        s1->wC0 = -1;
        *(s128_003D18C0 *)&s1->vA0 = *(s128_003D18C0 *)&self->pos;
        ang = func_00389380(self->fF8, s1->w80 != 0 ? 4.71238899f : 1.57079637f);
        d.x = func_00388960(ang) * s1->fBC;
        d.y = func_00388978(ang) * s1->fBC;
        d.z = 0.0f;
        vec_add_ba(&self->pos, &self->pos, &d);
        *(s128_003D18C0 *)&s1->v90 = *(s128_003D18C0 *)&self->pos;
        if (s1->w70 >= 0) {
            s1->fB8 = s1->fB8 * 0.0166666675f;
            s1->fB0 = s1->fB0 * 0.0166666675f;
            if (s1->w70 > 0) {
                void (**tt)(u8 *) = func_L01_00438468(0x19E1, 0x6C);
                s1->w70 = -1;
                s1->b7E = 2;
                (*tt)((u8 *)self);
                return;
            }
        }
        s1->f88 = 0.0f;
        if (s1->w8C >= 0) {
            s0 = D_L29_001DFB1C + (s1->w8C << 8);
            hf = (*func_L01_00438488(*(s16 *)(s0 + 0xAA), 6, 4))(s0) * s1->fBC;
            s1->f88 = hf;
            func_L01_00442300(&self->pos, &s1->v90, &s1->vA0, hf / s1->fBC);
            func_L01_00441FB8(self, 1, -1);
        } else {
            self->h34 = self->h34 | 2;
            *(s128_003D18C0 *)&self->pos = *(s128_003D18C0 *)&s1->vA0;
        }
        break;
    case 1:
        if (s1->w8C == -1) {
            return;
        }
        s0b = D_L29_001DFB1C + (s1->w8C << 8);
        f23 = (*func_L01_00438488(*(s16 *)(s0b + 0xAA), 6, 4))(s0b) * s1->fBC;
        if (s1->f88 != f23) {
            a0 = s1->wC0;
            if (a0 == -1 || (e = D_001A30B0 + (a0 << 7), *(void **)(e + 0xDC) != self) || e[0xD0] == 0) {
                s1->wC0 = func_0039FE80(0, 4, self);
            }
            f20 = s1->fB0;
            if (f23 < s1->f88) {
                f20 = -f20;
            }
            f21 = 0.0f;
            if (s1->fB4 != f21) {
                f22 = fabs_asm(f23 - s1->f88) / fabs_asm(s1->fB4);
                t0 = f21;
                t1 = f21;
                if (func_L01_00443080(&t0, &t1, s1->fB0 * -0.5f, fabs_asm(s1->fB4), -fabs_asm(f23 - s1->f88)) > 0) {
                    if (f21 < t0 && f22 < s1->fB4) {
                        f20 = -f20;
                    }
                }
            }
            g0 = s1->fB4 + f20;
            s1->fB4 = g0;
            if (s1->fB8 < g0) {
                s1->fB4 = s1->fB8;
            }
            if (s1->fB4 < -s1->fB8) {
                s1->fB4 = -s1->fB8;
            }
            g1 = s1->f88 + s1->fB4;
            s1->f88 = g1;
            if (s1->fBC < g1) {
                s1->f88 = s1->fBC;
            }
            if (s1->f88 < 0.0f) {
                s1->f88 = 0.0f;
            }
            f1 = 0.0f;
            if (s1->fB4 < f1) {
                if (s1->f88 < f23) {
                    s1->f88 = f23;
                }
            } else if (f1 < s1->fB4) {
                if (f23 < s1->f88) {
                    s1->f88 = f23;
                }
            }
            func_L01_00442300(&self->pos, &s1->v90, &s1->vA0, s1->f88 / s1->fBC);
        } else {
            s1->fB4 = 0.0f;
            a0 = s1->wC0;
            if (a0 != -1) {
                e = D_001A30B0 + (a0 << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_0039FB08(a0);
                }
            }
            s1->wC0 = -1;
        }
        break;
    }
}
/* localdecomp:end func_L29_003D18C0 */
