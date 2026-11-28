/* func_L23_003B9B88 (Claude wave 13 second pass r41, 2026-11-28). Replaces the earlier draft of this function (Claude wave 13 r21 near miss (2026-11-28); replaces the draft from k6 Opus near miss (2026-11-26)). */
/* PAL near miss (wave 13 opus r41, 2026-11-28): 4 differences (build/codex/wave10/p10/check.py, level 23, the
 * file's flags) with the divs_nops row 'func_L23_003B9B88 0 2' injected (--divs 0,2, not committed); the wr21 near
 * was 32 under the same check. Changed against it (the same changes in its twin func_L23_003BA670): (1) both particle
 * calls fully inline as the matched sibling func_L23_003A8028 (L23_003A6688.c) writes them, so the (x * 5 + 2)
 * temporaries build in s0 as retail; (2) case 2 passes the particle position through a pointer local set at the
 * top of its loop (pp = &p0) to func_0038D000 and func_L01_00463378 (retail's hoisted &p0 in s4 shared by both
 * calls, divisor 6 in s5); (3) case 3 passes it to func_L23_00453470 through a pointer local set before its loop
 * (pq = &p0): retail's s6, which leaves func_L01_00463378's &p0 to an addiu a0, sp, 0x10 and gives retail's
 * self->0x24-first loop head; (4) func_L23_00453470 with its real prototype (u8 *(void *, void *, s32, s32, float,
 * float, s32, float), L23_00453470.c) and the random index as its 7th argument.
 * Left (4 words, case 3): retail stores the copy (sqc2 vf1, 0x50(sp)) before the sum (sqc2 vf2, 0x10(sp)) and loads
 * the copy back before the p0.z store; vu0.h's vec_add_ab/vec_copy memory operands are BLKmode (vu0_v4), and gcc
 * 2.95 treats BLKmode stack accesses at different offsets as conflicting, so with either statement order one of
 * retail's two reorderings crosses a dependence: a helper-form wall under the fixed vu0.h, not a C wording
 * (copy before the add 7, p0.z before the copy 5 tried). */
#include "common.h"
/* localdecomp:start func_L23_003B9B88 */
#include "vu0.h"
#include "structs/hero.h"
typedef struct { u8 pad0[0x28]; u8 *x28; } Fx_003B9B88;
typedef struct { u8 pad0[0x20]; f32 x20; u8 pad24[4]; s32 x28; s32 x2C; } Snd_003B9B88;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 state;
    u8 pad21[3];
    u8 *x24;
    u8 pad28[4];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3BA3E8 *vars;
    u8 pad6C[0x2A];
    u16 x96;
    s32 x98;
    u8 pad9C[0xC];
    u8 xA8;
    u8 padA9[0x17];
    V4 m[3];
} Moby_003B9B88;
extern struct Hero D_001A4BE0;
extern s32 D_L23_001DEC40;
extern s32 D_L23_001DE134;
__asm__(".extern D_L23_001DE134, 16");
extern u8 D_L23_001FDA3C[];
__asm__(".extern D_L23_001FDA3C, 16");
extern Fx_003B9B88 *D_L23_001FB440[];
extern Snd_003B9B88 D_L23_001E1A40;
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern void func_L23_003BA3E8(Moby_3BA3E8 *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A4FF8(u8 *, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_0044F450(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_0013D3E0(void);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00382468(s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003A4F28(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L23_00453470(void *, void *, s32, s32, float, float, s32, float);

void func_L23_003B9B88(Moby_003B9B88 *self)
{
    vu0_v4 p0;
    vu0_v4 vel;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 tmp;
    vu0_v4 *pp;
    vu0_v4 *pq;
    Vars_3BA3E8 *v = self->vars;
    u8 *t;
    s32 i2;
    s32 i3;
    f32 r2;
    f32 r3;

    if (v->id < 0) {
        return;
    }
    switch (self->state) {
    case 0:
        func_L23_003BA3E8((Moby_3BA3E8 *)self);
        break;
    case 1:
        t = (u8 *)func_L01_00447490(self, -1, 0);
        if (t != 0) {
            if (D_L23_001DEC40 >= D_L23_001DE134 && *(f32 *)(t + 0x2C) > 3.0f) {
                func_003A4FF8(D_L23_001FB440[D_L23_001FDA3C[0]]->x28 + 0x20, 0x10, (s32)self, 0, 0x400);
                D_L23_001DE134 = D_L23_001DEC40 + 0x19;
                self->x34 &= ~0x10;
                vec_sub_ba(v->pad10, &self->pos, &D_001A4BE0.pos);
                func_0038CF68(v->pad10, v->pad10, 0.120000005f);
                ((V4 *)v->pad10)->z = -0.080000006f;
                func_L01_004450F0(self, 2, -1);
            }
            self->xA8 = 0xFF;
        }
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            v->x8 = func_003A4FF8(D_L23_001FB440[D_L23_001FDA3C[0]]->x28, 0x14, (s32)self, 0, 0x400);
            D_L23_001E1A40.x2C = 0;
            D_L23_001E1A40.x20 = 0.1f;
            D_L23_001E1A40.x28 = 0xFA;
        }
        func_003A52A0(0, 0, self);
        ((V4 *)v->pad10)->z += -0.004f;
        vec_add_ab(&self->pos, &self->pos, v->pad10);
        func_L01_0044F450(self, v->x20);
        r2 = self->scale * 3.5f / *(f32 *)(self->x24 + 0x24);
        for (i2 = 0; i2 < 8; i2++) {
            pp = &p0;
            qzero(&p0);
            p0.x = func_003824E0(-r2, r2);
            p0.y = -p0.x;
            func_0038D000(pp, pp, self->m);
            vec_add_ab(&p0, &p0, &self->pos);
            qzero(&vel);
            vel.x = func_L01_00443A18(0.0f, 0.020000001f);
            vel.y = func_L01_00443A18(0.0f, 0.020000001f);
            vel.z = func_003824E0(0.0f, 0.020000001f);
            vel.w = 1.5f;
            qzero(&c);
            c.w = func_003824E0(1.5f, 3.0f);
            func_L01_00463378(pp, &vel, &c, func_0038DBD8(0x80202020, 0x80707070, (f32)(func_0013D3E0() * func_0013D3E0())), 0x40606060, 1, ((func_00382468(0x14) + 0x1E) * 5 + 2) / 6, ((func_00382468(0xA) + 0x1E) * 5 + 2) / 6, -1);
        }
        if (((V4 *)&self->pos)->z <= v->x4) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0) {
            D_L23_001E1A40.x28 = 0x32;
            D_L23_001E1A40.x20 = 0.5f;
            ((V4 *)&self->pos)->z = v->x4;
            if (v->x8 >= 0) {
                func_003A4F28(v->x8);
                v->x8 = -1;
            }
        }
        r3 = self->scale * 3.5f / *(f32 *)(self->x24 + 0x24);
        pq = &p0;
        for (i3 = 0; i3 < 8; i3++) {
            qzero(&p0);
            p0.x = func_003824E0(-r3, r3);
            p0.y = -p0.x;
            p0.x += func_L01_00443A18(0.0f, 2.0f);
            p0.y += func_L01_00443A18(0.0f, 2.0f);
            func_0038D000(&p0, &p0, self->m);
            vec_add_ab(&p0, &p0, &self->pos);
            vec_copy(&tmp, &self->pos);
            p0.z = v->x4;
            vec_sub_ba(&vel, &p0, &tmp);
            vel.x = func_L01_00443A18(0.0f, 10.0f);
            vel.y = func_L01_00443A18(0.0f, 10.0f);
            vel.z = func_003824E0(1.0f, r3 * 4.0f);
            func_0038CF68(&vel, &vel, func_003824E0(0.020000001f, 0.080000006f) * 2.0f);
            qzero(&c);
            vel.w = 0.5f;
            c.w = func_003824E0(1.5f, 3.0f);
            func_L01_00463378(&p0, &vel, &c, func_0038DBD8(0x80202020, 0x80707070, (f32)(func_0013D3E0() * func_0013D3E0())), 0x40606060, 0x11, ((func_00382468(0xA) + 0x14) * 5 + 2) / 6, ((func_00382468(0xA) + 0x1E) * 5 + 2) / 6, -1);
            if (self->x96 < 4) {
                f32 z;

                d.x = func_L01_00443A18(0.020000001f, 0.080000006f) * 2.0f;
                d.y = func_L01_00443A18(0.020000001f, 0.080000006f) * 2.0f;
                d.z = func_003824E0(0.020000001f, 0.080000006f) * 2.0f;
                d.w = func_003824E0(1.5f, 3.0f) * 0.125f;
                z = v->x4 - 1.0f;
                func_L23_00453470(pq, &d, 0, 0x80606060, d.w, z, func_00382498(1, 2), 0.004f);
            }
        }
        if (self->x96 >= 0x22) {
            u16 *p;
            u8 *e;

            self->x98 = 0;
            self->x34 |= 0x43;
            p = D_L23_001D6764[v->id];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
                e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
                if (e == 0)
                    break;
                e[0x1E] |= 4;
                p++;
            }
        }
        break;
    }
    self->x96++;
}
/* localdecomp:end func_L23_003B9B88 */
