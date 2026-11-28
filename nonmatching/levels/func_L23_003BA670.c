/* Wave 13 (r30, 2026-11-28) replaces the earlier draft of this function (k6 Opus near miss (2026-11-26)). */
/* PAL near miss (wave 13 r30, 2026-11-28): 30 differences (wave10/p10/check.py, level 23, with the divs row
 * 'func_L23_003BA670 0 2' injected: retail has no nop before the first div.s and two before the second), from the k6
 * draft (71 without the row, 265 with it). Changes: case 2 adds the random value to the zeroed p0.y
 * (p0.y += ..., x stays 0) and case 3 assigns it to p0.y (the draft set x and y = -x: two words too many per loop);
 * 0.120000005f (retail 0x3DF5C290); case 1 reads the 0x34 flags before storing D_L23_001DE134 and writes them
 * after; case 3's end reads the D_L23_001D6764 table pointer before its two stores.
 * Left: saved-register roles inside the particle loops (retail: case 2 &p0 = s4, 6 = s5; case 3 &p0 = s6, 6 = s5,
 * &vel = s4; here p0's address is one pseudo shared by both cases), the (x * 5 + 2) temporaries in v1 instead of
 * s0, the order of self->0x24 / self->0x2C loads before case 3's loop, two sqc2 stores after case 3's vadd and
 * copy, and two argument moves before func_L23_00453470. The draft's two names for D_L23_001DEC40 (one with a
 * $gp size hint) are kept as the draft has them. */
#include "common.h"

/* localdecomp:start func_L23_003BA670 */
#include "vu0.h"
typedef struct { u8 pad0[0x28]; u8 *x28; } Fx_003BA670;
typedef struct { u8 pad0[0x20]; f32 x20; u8 pad24[4]; s32 x28; s32 x2C; } Snd_003BA670;
extern s32 D_L23_001DEC40_003BA670;
__asm__(".extern D_L23_001DEC40_003BA670, 4");
extern s32 D_L23_001DEC40;
extern s32 D_L23_001DE134;
__asm__(".extern D_L23_001DE134, 16");
extern u8 D_L23_001FDA3C[];
__asm__(".extern D_L23_001FDA3C, 16");
extern Fx_003BA670 *D_L23_001FB440[];
extern Snd_003BA670 D_L23_001E1A40;
extern u8 D_001A4BE0_003BA670[];
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern void func_L23_003BAEC8(void *);
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
extern void func_L23_00453470(void *, void *, s32, u32, s32, f32, f32, f32);

void func_L23_003BA670(u8 *self)
{
    vu0_v4 p0;
    vu0_v4 vel;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 tmp;
    u8 *v = *(u8 **)(self + 0x68);
    u8 *t;
    s32 i2;
    s32 i3;
    f32 r2;
    f32 r3;
    s32 col;
    s32 n;

    if (*(s32 *)v < 0) {
        return;
    }
    switch (self[0x20]) {
    case 0:
        func_L23_003BAEC8(self);
        break;
    case 1:
        t = (u8 *)func_L01_00447490(self, -1, 0);
        if (t != 0) {
            if (D_L23_001DEC40_003BA670 >= D_L23_001DE134 && *(f32 *)(t + 0x2C) > 3.0f) {
                func_003A4FF8(D_L23_001FB440[D_L23_001FDA3C[0]]->x28 + 0x20, 0x10, (s32)self, 0, 0x400);
                {
                    u16 fl = *(u16 *)(self + 0x34);
                    D_L23_001DE134 = D_L23_001DEC40 + 0x19;
                    *(u16 *)(self + 0x34) = fl & ~0x10;
                }
                vec_sub_ba(v + 0x10, self + 0x10, D_001A4BE0_003BA670 + 0x80);
                func_0038CF68(v + 0x10, v + 0x10, 0.120000005f);
                *(f32 *)(v + 0x18) = -0.080000006f;
                func_L01_004450F0(self, 2, -1);
            }
            self[0xA8] = 0xFF;
        }
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            *(s32 *)(v + 8) = func_003A4FF8(D_L23_001FB440[D_L23_001FDA3C[0]]->x28, 0x14, (s32)self, 0, 0x400);
            D_L23_001E1A40.x2C = 0;
            D_L23_001E1A40.x20 = 0.1f;
            D_L23_001E1A40.x28 = 0xFA;
        }
        func_003A52A0(0, 0, self);
        *(f32 *)(v + 0x18) += -0.004f;
        vec_add_ab(self + 0x10, self + 0x10, v + 0x10);
        func_L01_0044F450(self, v + 0x20);
        r2 = *(f32 *)(self + 0x2C) * 3.5f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
        for (i2 = 0; i2 < 8; i2++) {
            qzero(&p0);
            p0.y += func_003824E0(-r2, r2);
            func_0038D000(&p0, &p0, self + 0xC0);
            vec_add_ab(&p0, &p0, self + 0x10);
            qzero(&vel);
            vel.x = func_L01_00443A18(0.0f, 0.020000001f);
            vel.y = func_L01_00443A18(0.0f, 0.020000001f);
            vel.z = func_003824E0(0.0f, 0.020000001f);
            vel.w = 1.5f;
            qzero(&c);
            c.w = func_003824E0(1.5f, 3.0f);
            n = func_0013D3E0();
            n *= func_0013D3E0();
            col = func_0038DBD8(0x80202020, 0x80707070, (f32)n);
            n = ((func_00382468(0x14) + 0x1E) * 5 + 2) / 6;
            func_L01_00463378(&p0, &vel, &c, col, 0x40606060, 1, n, ((func_00382468(0xA) + 0x1E) * 5 + 2) / 6, -1);
        }
        if (*(f32 *)(self + 0x18) <= *(f32 *)(v + 4)) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0) {
            D_L23_001E1A40.x28 = 0x32;
            D_L23_001E1A40.x20 = 0.5f;
            *(f32 *)(self + 0x18) = *(f32 *)(v + 4);
            if (*(s32 *)(v + 8) >= 0) {
                func_003A4F28(*(s32 *)(v + 8));
                *(s32 *)(v + 8) = -1;
            }
        }
        r3 = *(f32 *)(self + 0x2C) * 3.5f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
        for (i3 = 0; i3 < 8; i3++) {
            qzero(&p0);
            p0.y = func_003824E0(-r3, r3);
            p0.x += func_L01_00443A18(0.0f, 2.0f);
            p0.y += func_L01_00443A18(0.0f, 2.0f);
            func_0038D000(&p0, &p0, self + 0xC0);
            vec_add_ab(&p0, &p0, self + 0x10);
            vec_copy(&tmp, self + 0x10);
            p0.z = *(f32 *)(v + 4);
            vec_sub_ba(&vel, &p0, &tmp);
            vel.x = func_L01_00443A18(0.0f, 10.0f);
            vel.y = func_L01_00443A18(0.0f, 10.0f);
            vel.z = func_003824E0(1.0f, r3 * 4.0f);
            func_0038CF68(&vel, &vel, func_003824E0(0.020000001f, 0.080000006f) * 2.0f);
            qzero(&c);
            vel.w = 0.5f;
            c.w = func_003824E0(1.5f, 3.0f);
            n = func_0013D3E0();
            n *= func_0013D3E0();
            col = func_0038DBD8(0x80202020, 0x80707070, (f32)n);
            n = ((func_00382468(0xA) + 0x14) * 5 + 2) / 6;
            func_L01_00463378(&p0, &vel, &c, col, 0x40606060, 0x11, n, ((func_00382468(0xA) + 0x1E) * 5 + 2) / 6, -1);
            if (*(u16 *)(self + 0x96) < 4) {
                f32 z;

                d.x = func_L01_00443A18(0.020000001f, 0.080000006f) * 2.0f;
                d.y = func_L01_00443A18(0.020000001f, 0.080000006f) * 2.0f;
                d.z = func_003824E0(0.020000001f, 0.080000006f) * 2.0f;
                d.w = func_003824E0(1.5f, 3.0f) * 0.125f;
                z = *(f32 *)(v + 4) - 1.0f;
                func_L23_00453470(&p0, &d, 0, 0x80606060, func_00382498(1, 2), d.w, z, 0.004f);
            }
        }
        if (*(u16 *)(self + 0x96) >= 0x22) {
            u16 *p;
            u8 *e;
            u16 **list = D_L23_001D6764;

            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) |= 0x43;
            p = list[*(s32 *)v];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[*(s32 *)v])) {
                e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
                if (e == 0)
                    break;
                e[0x1E] |= 4;
                p++;
            }
        }
        break;
    }
    (*(u16 *)(self + 0x96))++;
}
/* localdecomp:end func_L23_003BA670 */
