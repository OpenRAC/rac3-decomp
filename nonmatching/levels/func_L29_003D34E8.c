/* func_L29_003D34E8: 71 diff (PAL port of the NTSC-U draft; builds with "-mvu0-use-vf0-vf2" added to its file's line, needs a cut file; contains a `switch` that compiles to compares).
/* b37 W8: reproduced 71 diff; also tried: copy of the target for the clamp tail (coalesced, 71), fabs product in a local (85) */
 * PAL constants: 0.020000001f instead of 1/60, callees frontbin func_0038DAB8/0038D098/0038D0B0 and level func_L01_0043B548/0043B568/00445438/004450F0/004461B8, func_003A52A0/003A4F28.
 * Needed: divs_nops row (2 2 0), `a1` instead of `a0` in the else arm (150 -> 127), copy of vA0 before `h34 |= 2` (127 -> 124), `if (fB4 != 0.0f) { f21 = 0.0f; ...` (124 -> 71).
 * Left: the FP callee-saved registers of case 1: retail target=$f23 zero=$f21 ratio=$f22 step=$f20, ours target=$f21 zero=$f22 ratio=$f23 (priority order; declaration order and the
 * placement of the zero do not change it), and the f88 clamp tail built on it. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L29_003D34E8 */
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
                f21 = 0.0f;
                f22 = fabs_asm(f23 - s1->f88) / fabs_asm(s1->fB4);
                t0 = f21;
                t1 = f21;
                if (func_L01_004461B8(&t0, &t1, s1->fB0 * -0.5f, fabs_asm(s1->fB4), -fabs_asm(f23 - s1->f88)) > 0) {
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
