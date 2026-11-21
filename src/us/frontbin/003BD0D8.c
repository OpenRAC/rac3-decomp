#include "common.h"

/* NTSC-U counterpart of func_003C25D8 (src/frontbin/3C25D8.c): no 0.8333333f (50/60 Hz) fallback for f48 */
/* localdecomp:start func_U_003BD0D8 */
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
extern void func_U_003BD490();
extern void func_U_00388440();
typedef struct { u8 p0[0x10]; u8 b10; s8 b11; } R_3C25D8;
typedef struct {
    u8 p0[0x6]; u8 b6; u8 p7[5]; u8 bC; u8 pD; u8 bE; u8 bF; s32 w10; u8 p14[0x10]; f32 f24;
    u8 p28[0x18]; s32 w40; u16 h44; u8 p46; u8 b47; R_3C25D8 *w48;
} S_3C25D8;
typedef struct {
    u8 p0[0x21]; u8 b21; u8 b22; u8 b23; S_3C25D8 *w24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34;
    s16 h36; long d38; u8 p40[8]; f32 f48; f32 f4C; u8 p50[0x11]; u8 b61; u8 b62; u8 b63; s32 w64;
    u8 p68[4]; u8 b6C; u8 b6D; u8 b6E; u8 b6F; s32 w70; s32 w74; s32 w78; u8 p7C[2]; u8 b7E;
    u8 p7F[0x19]; s32 w98; u8 p9C[8]; u8 bA4; u8 bA5; u8 bA6; u8 bA7; u8 bA8; u8 pA9; s16 hAA;
    s32 wAC; u8 pB0[0xD]; u8 bBD; u8 pBE[0x42];
} P_3C25D8;
extern u8 D_U_002D7210[];
extern s16 D_U_002D7030[];
extern s32 D_U_002D9210[];
extern s32 D_U_002D6B80[];
extern S_3C25D8 *D_U_002D67C0[];
extern u32 D_U_001DA51C;
__asm__(".extern D_U_001DA51C, 16");
void func_U_003BD0D8(O_3A1870 *arg0, s32 idx) {
    P_3C25D8 *p = (P_3C25D8 *)arg0;
    S_3C25D8 *s;
    u8 c;
    func_U_00388440(p, 0, 0x100);
    p->b22 = D_U_002D7210[idx];
    c = p->b22;
    p->b23 = 0x80;
    p->bA8 = 0xFF;
    p->b21 = 0xFF;
    p->b61 = 0xFF;
    p->b62 = 0xFF;
    p->d38 = 0x40404000000000;
    p->h36 = 0x7F80;
    p->wAC = ((s32)((u32)p - D_U_001DA51C) >> 8) << 16;
    p->hAA = idx;
    p->b6E = 0;
    p->b6C = 0xFF;
    p->bA4 = 0x7F;
    p->bA6 = 0x80;
    p->b6D = 0xFF;
    p->bA5 = 0x7F;
    p->bA7 = 0x80;
    if (D_U_002D7030[c] != idx) {
        p->h34 |= 5;
        p->w24 = 0;
        p->w98 = 0;
        p->w64 = D_U_002D9210[p->b22];
        if (p->w64 == 0) p->h34 |= 2;
        return;
    }
    p->w64 = D_U_002D6B80[c];
    if (p->w64 == 0) p->h34 |= 2;
    s = D_U_002D67C0[p->b22];
    p->w24 = s;
    p->b62 = s->bE;
    p->h34 |= s->h44;
    p->w98 = s->w10;
    p->f2C = s->f24;
    p->f48 = 1.0f;
    p->f4C = 1.0f;
    if (s->w40) {
        p->h34 |= 0x10;
        p->w78 = s->w40;
    }
    if (p->w24->bF) {
        p->b6F = 0x18;
        p->h34 |= 0x400;
        p->w70 = 0;
        p->w74 = 0;
        p->bBD = 0;
    }
    if (p->w24->b6) p->b63 = 0x18;
    if (p->w24->w48) {
        func_U_003BD490(p);
        if (p->w24->w48->b10 >= 2) p->h34 &= ~2;
        if (p->w24->bC == 1) {
            if (p->w24->w48->b10 < 2) {
                p->f48 = 0.0f;
                if (p->w24->w48->b11 < 0) p->h34 |= 0x40;
            }
        }
    }
    p->b7E |= p->w24->b47;
}
/* localdecomp:end func_U_003BD0D8 */
