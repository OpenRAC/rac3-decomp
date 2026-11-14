/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003A2258, the NTSC-U twin of func_L01_003A39A0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0039E1B0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_003A39A0 (src/levels/shared/L01_0039E1B0.c) */
/* localdecomp:start func_L01_003A2258 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct Moby_3A2258 Moby_3A2258;
typedef struct Ctx_3A2258 Ctx_3A2258;
typedef struct { u8 p[0x24]; f32 f24; } Tbl_3A2258;

struct Moby_3A2258 {
    u8 pad0[0x10];
    union { u128_t q; struct { f32 x, y, z, w; } f; } v10;
    u8 pad20[0x4];
    Tbl_3A2258 *pTbl;
    u8 pad28[0x4];
    f32 f2C;
    u8 pad30[0x4];
    u16 h34;
    u8 pad36[0xD];
    u8 b43;
    u8 pad44[0x24];
    Ctx_3A2258 *pCtx;
    u8 pad6C[0x10];
    s16 h7C;
    u8 pad7E[0x1A];
    s32 w98;
    u8 pad9C[0xE];
    s16 hAA;
    u8 padAC[0x4];
    u8 bB0;
    u8 padB1[0x1];
    u16 hB2;
    u8 padB4[0x44];
    f32 fF8;
    u8 padFC[0x4];
};
struct Ctx_3A2258 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x2];
    u8 b38;
    u8 b39;
    u8 pad3A[0x4];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 b44;
    u8 pad45[0x13];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x3];
    u8 b5E;
    u8 b5F;
    u8 pad60[0x10];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    f32 f9C;
    f32 fA0;
    u8 padA4[0x18];
    u8 *pBC;
    u8 padC0[0xB0];
    u8 b170;
    u8 b171;
    u8 b172;
    u8 pad173[0x3];
    u8 b176;
    u8 pad177[0x19];
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    f32 f1A0;
    u8 pad1A4[0x4];
    u8 b1A8;
    u8 b1A9;
    s16 h1AA;
    u8 pad1AC[0x2B];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    s32 w1DC;
    u8 pad1E0[0x30];
    f32 f210;
    u8 pad214[0x2C];
    s32 w240;
    u8 pad244[0xA];
    u8 b24E;
    u8 b24F;
    u8 pad250[0x90];
    s32 w2E0;
    s16 h2E4;
    s16 h2E6;
    s32 w2E8;
    u8 pad2EC[0x4];
    s32 w2F0;
    s32 w2F4;
    s32 w2F8;
    u8 pad2FC[0x4];
    u8 b300[0x80];
    u128_t q380;
    u8 pad390[0x14];
    s32 w3A4;
    u8 pad3A8[0x4];
    s32 w3AC;
    u8 pad3B0[0x4];
    s32 w3B4;
    u8 pad3B8[0x8];
    s32 w3C0;
    u8 pad3C4[0x14];
    s32 w3D8;
    s32 w3DC;
    u8 pad3E0[0x10];
    Moby_3A2258 *a3F0[8];
    u8 pad410[0x8];
    s32 w418;
    s32 w41C;
    f32 f420;
    u8 pad424[0xC];
};

extern s32 D_001D545C;
extern s32 D_L01_001D67AC;
extern u8 D_001BBC40[];
extern Moby_3A2258 *D_L01_001E009C;
extern Moby_3A2258 *D_L01_001E00A0;
extern Moby_3A2258 *D_001E00A0_sda;
__asm__(".extern D_001E00A0_sda, 4");
extern s32 func_0037E1D8(s32);
extern void func_003BD360(Moby_3A2258 *);
extern void func_L01_004A6DF8(Moby_3A2258 *, s32);
extern void func_L01_00458A70(Moby_3A2258 *, f32, f32, f32, f32);
extern void *func_L01_00438468(s32, s32);
extern void func_L01_00441FB8(Moby_3A2258 *, s32, s32);
extern void func_003BE4F0(Moby_3A2258 *, s32, s32, s32);
extern void func_L01_003A30C8(Moby_3A2258 *);

/* Moby init: resets the state block, picks up to 8 nearby objects and chooses the first animation. */
/* Float literals carry 9 significant digits: this gcc rounds shorter decimals one ulp off. */
s32 func_L01_003A2258(Moby_3A2258 *self) {
    Ctx_3A2258 *s;
    Moby_3A2258 *o;
    s32 n;
    s32 i;

    s = self->pCtx;
    if (D_001D545C == 1 && self->bB0 != 0xFF && (u16)(self->hB2 - 0x5E) < 2 &&
        (D_001BBC40[self->bB0 + (D_001D545C << 4)] & 0x80)) {
        func_003BD360(self);
        return 1;
    }
    D_L01_001D67AC = 0;
    if (func_0037E1D8(2) != 0) {
        self->h34 |= 0x8000;
    }
    self->f2C = self->pTbl->f24;
    s->b3F = 0;
    if (s->w3C0 == 0) {
        self->h7C = 0x7FF;
    } else {
        self->h7C = 0;
    }
    s->w418 = 0;
    s->w2F0 = 0;
    s->w2F4 = 0;
    s->w3DC = 0;
    for (i = 0; i < 8; i++) {
        s->a3F0[i] = 0;
    }
    n = 0;
    o = D_L01_001E009C;
    if (o < D_L01_001E00A0) {
        do {
            if (o->hAA == 0x1BAF || o->hAA == 0x1E8D) {
                s->a3F0[n] = o;
                o->w98 = 0;
                o->h34 = (o->h34 | 0x41) & 0xEFFF;
                func_L01_004A6DF8(o, 1);
                n++;
                if (n >= 8) {
                    break;
                }
            }
            o++;
        } while (o < D_001E00A0_sda);
    }
    s->q380 = self->v10.q;
    s->f420 = self->fF8;
    s->f190 = 0.5f;
    s->f194 = 0.5f;
    s->b1D7 = 1;
    s->b170 = 0xF;
    s->b1A8 = 4;
    s->f19C = 0.150000006f;
    s->b171 = 5;
    s->b172 = 5;
    if (func_0037E1D8(2) != 0) {
        s->b176 = 9;
    }
    s->b1A9 = 1;
    s->b1DB = 0xFF;
    s->b1D8 = 1;
    s->b1D9 = 1;
    s->b1DA = 0;
    s->f1A0 = self->v10.f.z - 10.0f;
    s->w1DC = s->w3D8;
    if (D_001D545C == 0xC) {
        s->h1AA = 0x280B;
    }
    s->f210 = 1.0f;
    s->f74 = 0.5f;
    s->pBC = s->b300;
    s->f70 = 0.699999988f;
    s->f78 = 0.649999976f;
    s->f7C = 1.0f;
    s->f80 = 1.48352981f;
    s->fA0 = 0.34906584f;
    s->f9C = 0.00272222236f;
    func_L01_00458A70(self, 0.00777777797f, 0.100000009f, 0.0139626348f, 0.418879062f);
    s->b58 = 0x14;
    s->b5A = 0xE;
    if (s->h34 == 0) {
        s->h34 = 5;
        s->f30 = 5.0f;
    }
    s->f40 = 2.0f;
    s->b38 = 1;
    s->b39 = 1;
    s->b3E = 1;
    s->b5E = 0;
    s->b5F = 0;
    s->w2E0 = 0;
    s->h2E4 = 0;
    s->h2E6 = 0;
    s->w2E8 = 0;
    s->w3A4 = 0;
    if (s->w240 > 0) {
        void **p = (void **)func_L01_00438468(0x19E1, 0x6C);

        s->w240 = -1;
        if (self->b43 != 0) {
            func_003BE4F0(self, 0, 0, 0);
        }
        s->b24E = 0x12;
        s->b24F = 8;
        ((void (*)(Moby_3A2258 *))*p)(self);
    } else if (s->w3B4 != 0) {
        func_L01_00441FB8(self, 0x10, 6);
        self->w98 = 0;
        self->h34 = (self->h34 | 0x41) & 0xEFFF;
        func_L01_004A6DF8(self, 1);
    } else if (s->w41C != 0) {
        func_L01_003A30C8(self);
    } else if (s->w3AC != -1 && s->w2F8 == 0) {
        func_L01_00441FB8(self, 1, 5);
        if (self->b43 != 0) {
            func_003BE4F0(self, 0, 0, 0);
        }
    } else {
        func_L01_00441FB8(self, 2, 0);
        if (self->b43 != 0) {
            func_003BE4F0(self, 0, 0, 0);
        }
        if (s->w2F8 != -1) {
            func_L01_00441FB8(self, 4, -1);
            if (self->b43 != 8) {
                func_003BE4F0(self, 8, 0, 0);
            }
        }
    }
    if (s->w3C0 != 0) {
        return 0;
    }
    if (s->b44 < 5) {
        s->b44 = 5;
    }
    return 0;
}
/* localdecomp:end func_L01_003A2258 */
