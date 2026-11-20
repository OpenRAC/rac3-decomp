#include "common.h"

/* NTSC-U counterpart of func_003C2990 (src/boot_elf/text/3C2990.c): no 50 Hz f48 = 0.8333333f case */
/* localdecomp:start func_U_003C2898 */
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870_003A70C8;
typedef struct {
    u8 pad[0x24]; T_3A1870_003A70C8 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870_003A70C8;
extern void func_U_003C2C50();
extern u32 D_U_001DA51C;
extern void func_U_0038CEA0();
typedef struct { u8 p[0x10]; u8 b10; s8 b11; } M_003C2898;
typedef struct { u8 p0[0x6]; u8 b6; u8 p7[5]; u8 bC; u8 pD; u8 bE; u8 bF; s32 w10; u8 p14[0x10]; f32 f24; u8 p28[0x18]; s32 w40; u16 h44; u8 p46; u8 b47; M_003C2898 *w48; } Def_003C2898;
typedef struct {
    u8 p0[0x21]; u8 b21; u8 b22; u8 b23; Def_003C2898 *w24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34; s16 h36; long d38; u8 p40[8]; f32 f48; f32 f4C; u8 p50[0x11]; u8 b61; u8 b62; u8 b63; s32 w64; u8 p68[4]; u8 b6C; u8 b6D; u8 b6E; u8 b6F; s32 w70; s32 w74; s32 w78; u8 p7C[2]; u8 b7E; u8 p7F[0x19]; s32 w98; u8 p9C[8]; u8 bA4; u8 bA5; u8 bA6; u8 bA7; u8 bA8; u8 pA9; s16 hAA; s32 wAC; u8 pB0[0xD]; u8 bBD;
} P_003C2898;
extern u8 D_U_002DB210[];
extern s16 D_U_002DB030[];
extern s32 D_U_002DD210[];
extern s32 D_U_002DAB80[];
extern Def_003C2898 *D_U_002DA7C0[];

void func_U_003C2898(O_3A1870_003A70C8 *obj, s32 id)
{
    P_003C2898 *p = (P_003C2898 *)obj;
    u8 slot;
    s32 w;
    func_U_0038CEA0(p, 0, 0x100);
    slot = D_U_002DB210[id];
    p->b23 = 128;
    p->b22 = slot;
    p->bA8 = 255;
    p->b21 = 255;
    p->b61 = 255;
    p->b62 = 255;
    w = (((s32)p - (s32)D_U_001DA51C) >> 8) << 16;
    p->d38 = 0x0040404000000000L;
    p->h36 = 0x7F80;
    p->hAA = id;
    p->b6E = 0;
    p->b6C = 255;
    p->bA4 = 127;
    p->bA6 = 128;
    p->b6D = 255;
    p->bA5 = 127;
    p->wAC = w;
    p->bA7 = 128;
    if (D_U_002DB030[p->b22] != id) {
        p->h34 |= 5;
        p->w24 = 0;
        p->w98 = 0;
        p->w64 = D_U_002DD210[p->b22];
        if (!p->w64) p->h34 |= 2;
    } else {
        p->w64 = D_U_002DAB80[p->b22];
        if (!p->w64) p->h34 |= 2;
        p->w24 = D_U_002DA7C0[p->b22];
        p->b62 = p->w24->bE;
        p->h34 |= p->w24->h44;
        p->w98 = p->w24->w10;
        p->f2C = p->w24->f24;
        p->f48 = 1.0f;
        p->f4C = 1.0f;
        if (p->w24->w40) {
            p->h34 |= 0x10;
            p->w78 = p->w24->w40;
        }
        if (p->w24->bF) {
            p->b6F = 24;
            p->h34 |= 0x400;
            p->w70 = 0;
            p->w74 = 0;
            p->bBD = 0;
        }
        if (p->w24->b6) p->b63 = 24;
        if (p->w24->w48) {
            func_U_003C2C50(p);
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
}
/* localdecomp:end func_U_003C2898 */
