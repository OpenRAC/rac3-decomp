/* PAL near miss: 70 differing words with the owning file's flags and
 * divs_nops row 0 2. P02 retail audit corrected the sound-call argument order,
 * exact PAL constants, effect-table layout and the VU copy of the position.
 * Preserves this variant's Y-only jitter. Not promoted.
 * Shares draft type names with B9B88: consolidate declarations before integration.
 */
#include "common.h"
/* localdecomp:start func_L23_003BA670 */
#include "vu0.h"
typedef struct { s32 w0; f32 f4; s32 w8; u8 padC[4]; V4 v10; u8 v20[0x10]; } Vars_3B9B88;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; u8 *p24; u8 pad28[4]; f32 f2C; u8 pad30[4];
    u16 h34; u8 pad36[0x68 - 0x36]; Vars_3B9B88 *vars; u8 pad6C[0x96 - 0x6C]; u16 h96;
    u8 pad98[0xA8 - 0x98]; u8 bA8; u8 padA9[0xC0 - 0xA9]; u8 m[0x30];
} Moby_3B9B88;
extern u8 *D_L23_001FB440[];
extern u8 D_L23_001FDA3C[];
typedef struct {
    u8 pad[0x20];
    f32 f20;
    s32 w24, w28, w2C;
} Effect_3B9B88;
extern Effect_3B9B88 D_L23_001E1A40;
extern s32 D_L23_001DE134;
extern s32 D_L23_001DEC40;
extern u8 D_001A4C60[];
extern void func_L23_003BAEC8(Moby_3BA3E8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A4FF8(u8 *, s32, void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044F450(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern s32 func_L01_004561B8(u8 *);
extern u8 *func_L23_00453470(void *, void *, s32, s32, float, float, s32, float);
extern s32 func_L01_00463378(void *, void *, void *, u32, u32, s32, s32, s32, s32);

void func_L23_003BA670(void *arg)
{
    Moby_3B9B88 *self = arg;
    Vars_3B9B88 *v = self->vars;
    u8 *r;
    u8 *snd;
    V4 a;
    V4 b;
    V4 c;
    V4 d;
    f32 sc;
    f32 t;
    s32 i;
    s32 col;
    s32 r1;
    s32 r2;
    u16 *p;
    u8 *e;
    u16 val;

    if (v->w0 < 0) {
        return;
    }
    switch (self->b20) {
    case 0:
        func_L23_003BAEC8((Moby_3BA3E8 *)self);
        break;
    case 1:
        r = (u8 *)func_L01_00447490(self, -1, 0);
        if (r == 0) {
            break;
        }
        if (D_L23_001DEC40 >= D_L23_001DE134 && 3.0f < *(f32 *)(r + 0x2C)) {
            snd = *(u8 **)(D_L23_001FB440[D_L23_001FDA3C[0]] + 0x28);
            func_003A4FF8(snd + 0x20, 0x10, self, 0, 0x400);
            D_L23_001DE134 = D_L23_001DEC40 + 0x19;
            self->h34 &= 0xFFEF;
            vec_sub_ab(&v->v10, &self->pos, D_001A4C60);
            func_0038CF68(&v->v10, &v->v10, 0.120000005f);
            v->v10.z = -0.080000005f;
            func_L01_004450F0(self, 2, -1);
        }
        self->bA8 = 0xFF;
        break;
    case 2: {
        f32 sc;
        if (func_L01_004561B8((u8 *)self)) {
            snd = *(u8 **)(D_L23_001FB440[D_L23_001FDA3C[0]] + 0x28);
            v->w8 = func_003A4FF8(snd, 0x14, self, 0, 0x400);
            D_L23_001E1A40.w2C = 0;
            D_L23_001E1A40.f20 = 0.1f;
            D_L23_001E1A40.w28 = 0xFA;
        }
        func_003A52A0(0, 0, self);
        v->v10.z += -0.004f;
        vec_add_ab(&self->pos, &self->pos, &v->v10);
        func_L01_0044F450(self, v->v20);
        sc = self->f2C * 3.5f / *(f32 *)(self->p24 + 0x24);
        for (i = 7; i >= 0; i--) {
            qzero(&a);
            a.y += func_003824E0(-sc, sc);
            func_0038D000(&a, &a, self->m);
            vec_add_ab(&a, &a, &self->pos);
            qzero(&b);
            b.x = func_L01_00443A18(0.0f, 0.020000001f);
            b.y = func_L01_00443A18(0.0f, 0.020000001f);
            b.z = func_003824E0(0.0f, 0.020000001f);
            b.w = 1.5f;
            qzero(&c);
            c.w = func_003824E0(1.5f, 3.0f);
            col = func_0038DBD8(0x80202020, 0x80707070, (f32)(func_0013D3E0() * func_0013D3E0()));
            r1 = ((func_00382468(0x14) + 0x1E) * 5 + 2) / 6;
            r2 = ((func_00382468(0xA) + 0x1E) * 5 + 2) / 6;
            func_L01_00463378(&a, &b, &c, col, 0x40606060, 1, r1, r2, -1);
        }
        if (self->pos.z <= v->f4) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    }
    case 3: {
        f32 sc;
        if (func_L01_004561B8((u8 *)self)) {
            D_L23_001E1A40.f20 = 0.5f;
            D_L23_001E1A40.w28 = 0x32;
            self->pos.z = v->f4;
            if (v->w8 >= 0) {
                func_003A4F28(v->w8);
                v->w8 = -1;
            }
        }
        sc = self->f2C * 3.5f / *(f32 *)(self->p24 + 0x24);
        for (i = 7; i >= 0; i--) {
            V4 P;
            qzero(&a);
            a.y = func_003824E0(-sc, sc);
            a.x += func_L01_00443A18(0.0f, 2.0f);
            a.y += func_L01_00443A18(0.0f, 2.0f);
            func_0038D000(&a, &a, self->m);
            vec_add_ab(&a, &a, &self->pos);
            vec_copy(&P, &self->pos);
            a.z = v->f4;
            vec_sub_ab(&b, &a, &P);
            b.x = func_L01_00443A18(0.0f, 10.0f);
            b.y = func_L01_00443A18(0.0f, 10.0f);
            b.z = func_003824E0(1.0f, sc * 4.0f);
            t = func_003824E0(0.020000001f, 0.080000005f);
            func_0038CF68(&b, &b, t + t);
            b.w = 0.5f;
            qzero(&c);
            c.w = func_003824E0(1.5f, 3.0f);
            col = func_0038DBD8(0x80202020, 0x80707070, (f32)(func_0013D3E0() * func_0013D3E0()));
            r1 = ((func_00382468(0xA) + 0x14) * 5 + 2) / 6;
            r2 = ((func_00382468(0xA) + 0x1E) * 5 + 2) / 6;
            func_L01_00463378(&a, &b, &c, col, 0x40606060, 0x11, r1, r2, -1);
            if (self->h96 < 4) {
                d.x = func_L01_00443A18(0.020000001f, 0.080000005f) * 2.0f;
                d.y = func_L01_00443A18(0.020000001f, 0.080000005f) * 2.0f;
                d.z = func_003824E0(0.020000001f, 0.080000005f) * 2.0f;
                d.w = func_003824E0(1.5f, 3.0f) * 0.125f;
                func_L23_00453470(&a, &d, 0, 0x80606060, d.w, v->f4 - 1.0f, func_00382498(1, 2), 0.004f);
            }
        }
        if (self->h96 >= 0x22) {
            self->h34 |= 0x43;
            *(s32 *)((u8 *)self + 0x98) = 0;
            p = D_L23_001D6764[v->w0];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->w0])) {
                e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
                if (e == 0) {
                    break;
                }
                e[0x1E] |= 4;
                p++;
            }
        }
        break;
    }
    default:
        break;
    }
    self->h96++;
}
/* localdecomp:end func_L23_003BA670 */
