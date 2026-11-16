/* NTSC-U draft (Claude wave C4): C of func_L07_003AACA8, the NTSC-U twin of func_L07_003AC500, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_003AACA8", whose code is not the PAL one).
 * Worker's note: flags: needs @ps2as (float constants 0.3f/0.01f/0.03f/0.7853982f/1.5707964f/0.2617994f/1.6f as lui/ori/mtc1; the PAL line has none; no vu0 flag needed, qzero and V4 copies compile without it); with the PAL line alone 82 aligned words differ. With @ps2as 10 ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003AACA8 */
typedef union {
    vu0_q q;
    f32 f[4];
} V4_003AACA8;

typedef struct {
    u8 pad0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
} T_003AACA8;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x3E - 0x36];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x5E - 0x44];
    u8 b5E;
    u8 pad5F;
    u8 b60;
    u8 pad61[0x70 - 0x61];
    u8 b70[0x130 - 0x70];
    f32 f130;
    f32 f134;
    u8 pad138[0x140 - 0x138];
    T_003AACA8 *p140;
    s16 h144;
    u8 pad146[0x188 - 0x146];
    s32 w188;
    u8 pad18C[0x228 - 0x18C];
    s32 w228;
    u8 pad22C[0x240 - 0x22C];
    s32 w240;
    u8 pad244[0x260 - 0x244];
    u8 b260[0x2A8 - 0x260];
    f32 f2A8;
    u8 pad2AC[0x2C8 - 0x2AC];
    f32 f2C8;
    u8 pad2CC[0x2E0 - 0x2CC];
    u8 b2E0[0x344 - 0x2E0];
    f32 f344;
    u8 pad348[0x360 - 0x348];
    u8 b360[0x3C4 - 0x360];
    f32 f3C4;
    f32 f3C8;
    u8 pad3CC[0x3E0 - 0x3CC];
    u8 b3E0[0x56C - 0x3E0];
    f32 f56C;
} S_003AACA8;

typedef struct {
    u8 pad0[0x10];
    V4_003AACA8 v10;
    u8 b20;
    u8 pad21[0x31 - 0x21];
    u8 b31;
    u8 pad32[0x68 - 0x32];
    S_003AACA8 *p68;
    u8 pad6C[0x6F - 0x6C];
    u8 b6F;
    u8 pad70[0xF8 - 0x70];
    f32 fF8;
} O_003AACA8;

extern u8 D_L07_001D66B0[];
extern u8 D_L07_001E1EC0[];
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L07_00332CB8(s32, f32, f32);
extern void func_L03_0032D348(void *);
extern s32 func_L01_0032FE90(f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L07_00330E70(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00443938(void *, void *, s32, void *, void *, f32);
extern void func_L07_00330A18(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389410(f32);
extern f32 func_00388800(void *, void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L07_0044F0E8(void *, s32, void *, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_00443648(void *, void *, s32, f32, f32, f32, s32, s32, s32);

void func_L07_003AACA8(O_003AACA8 *a) {
    S_003AACA8 *s;
    V4_003AACA8 v;
    f32 f;
    f32 d;

    s = a->p68;
    if (a->b20 == 1) {
        return;
    }
    f = s->f30;
    if (func_L01_0044FCD0(a, s->b70, 0, 0, 0) != 0) {
        func_L07_00332CB8(s->w240, f, s->f30);
        s->w188 = s->w188 & ~0x10;
        func_L03_0032D348(a);
    }
    if (s->f30 <= 0.0f) {
        v.q = a->v10.q;
        v.f[2] = v.f[2] + s->f40;
        func_L01_0032FE90(v.f, 0, 10, 5, 4, 10, 15, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                          0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                          0x280000FF, 0x3064FF, 0);
        func_L01_0044ED60(a, 0x7FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L07_00330E70(a);
        func_0039FE80(8, 0, a);
        return;
    }
    if (s->w228 == 1) {
        qzero(&v);
        func_L01_00443938(a, a, 0x10000, &v, &v, (f32)s->h34);
    } else if (s->b5E != 0 || s->b60 != 0 || s->b3E == 2) {
        func_L07_00330E70(a);
        return;
    }
    func_L07_00330A18(a);
    if ((s->w188 & 0x10) != 0) {
        d = func_00388A28(s->f130 - a->v10.f[0], s->f134 - a->v10.f[1]);
        d = func_003893C8(d, a->fF8);
        s->f2C8 = d;
        if (d > 1.5707964f) {
            s->f2C8 = 1.5707964f;
        } else if (d < -1.5707964f) {
            s->f2C8 = -1.5707964f;
        }
    } else {
        s->f2C8 = 0.0f;
    }
    func_L01_0044B5C8(a, s->b260, 2, 0.01f, 0.3f);
    s->f344 = s->f56C;
    func_L01_0044B5C8(a, s->b2E0, 3, 0.03f, 0.3f);
    if (s->h144 == 1) {
        func_003BDA38(a, 4, &v);
        d = func_00388A28(s->p140->f10 - v.f[0], s->p140->f14 - v.f[1]);
        d = func_00389410(d - s->f2A8 - a->fF8);
        s->f3C8 = d;
        if (d > 0.7853982f) {
            s->f3C8 = 0.7853982f;
        } else if (d < -0.7853982f) {
            s->f3C8 = -0.7853982f;
        }
        d = func_00388A28(func_00388800(&v, (u8 *)s->p140 + 0x10), s->p140->f18 - v.f[2]);
        d = -d;
        s->f3C4 = d;
        if (d > 0.2617994f) {
            s->f3C4 = 0.2617994f;
        } else if (d < -0.2617994f) {
            s->f3C4 = -0.2617994f;
        }
    }
    func_L01_0044B5C8(a, s->b360, 4, 0.03f, 0.3f);
    func_L07_0044F0E8(a, 5, s->b3E0, 2.5f);
    if (a->b31 != 0 && func_L01_0040C018(D_L07_001E1EC0, &a->v10) < 576.0f) {
        func_L01_00444188(a);
        a->b6F = 0x16;
    }
    func_L01_00443648(a, &a->v10, 0x8000000, 1.6f, 1.0f, 1.0f, 0, 1, 0);
}
/* localdecomp:end func_L07_003AACA8 */
