#include "common.h"

/* NTSC-U counterpart of func_L39_006D9328 (src/levels/39_multiplayer_menu/L39_006D8E90.c) */
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;
extern Obj_006DA090 *D_L39_0024D860;

/* localdecomp:start func_L39_006D67D0 */
__asm__(".extern D_L39_0024D860, 16");
extern Obj_006DA090 *D_L39_0024D860;
typedef struct {
    u8 f0;
    u8 pad1[3];
    u8 f4[0x18];
    s32 f1C;
    u8 pad20[0x2C];
    u8 f4C[0x28];
    u32 f74;
    u32 f78;
    u8 f7C;
} S_006D9328;
typedef struct {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
} Loc_006D9328;
typedef struct {
    u8 pad00;
    u8 f1;
    u8 pad02[6];
    s32 f8;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x13];
    s32 *f30;
    u8 pad34[0x1C];
    s32 f50;
} G_006D9328;
typedef struct {
    u8 pad00[0x2DC];
    s32 f2DC;
} P_006D9328;
typedef union { u32 w[2]; u8 b[8]; } B_006D9328;

s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017EB28(void *, void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
extern u8 D_001A5E50[];
extern u16 D_L39_00249FF8[];
extern u8 D_00197E48[];
__asm__(".extern D_L39_0024BAC8, 16");
extern u32 D_L39_0024BAC8;
__asm__(".extern D_001D59B0_sda_006D67D0, 4");
__asm__(".extern D_L39_00240590, 16");
__asm__(".extern D_L39_00240598, 16");
__asm__(".extern D_L39_002405A0, 16");
__asm__(".extern D_L39_00241241, 16");
__asm__(".extern D_L39_00241240, 16");
extern u8 D_L39_00240590;
extern u8 D_L39_00240598;
extern u8 D_L39_002405A0;
extern u8 D_L39_00241240;
extern u8 D_L39_00241241;
extern u8 D_001D59B0_sda_006D67D0;

static __inline__ void hide_006D9328(u8 *slot, B_006D9328 *buf, u32 v, s32 size, s32 step) {
    u8 *q = slot;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*slot == 0) {
        *slot = D_001D59B0_sda_006D67D0 = D_L39_00241240 + 1;
    } else {
        s32 t = *slot;
        *slot = D_L39_00241241;
        D_L39_00241241 = t;
    }
    if (size == 1) {
        buf->b[4] = v;
    } else {
        buf->w[1] = ~v;
    }
    v = buf->w[1];
    key = ((u32 *)&D_L39_00241240)[((u32)slot * D_L39_0024BAC8) % 8];
    k = ((u32)q - *q) & 7;
    buf->w[0] = (u32)q ^ key;
    buf->w[1] = ((v & 0xFFFF) | (v << 16)) ^ key;
    m = *q + 1;
    d = buf->b;
    for (i = 0; i < step * 8; i += step) {
        s32 o = ((k + i) & 7) * 4;

        (&D_L39_00241240)[m + o] = *d++;
    }
}

void *func_L39_006D67D0(S_006D9328 *arg0, s32 arg1) {
    Loc_006D9328 loc;
    G_006D9328 *g;
    P_006D9328 *p;
    s32 r;
    s32 x;
    void *ret;

    g = (G_006D9328 *)D_L39_0024D860;
    x = g->f50;
    loc.f00 = D_L39_00249FF8[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = arg1;
    arg0->f0 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EB28(&loc, D_00197E48, 0));
    p = (P_006D9328 *)D_001A5E50;
    while (arg0->f0 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x40;
            if (g->f14 == 0) {
                g->f14 = 0x40;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if (func_L39_006D5F80((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f0 = 0;
    ret = 0;
    if (r != 0) {
        u32 poly = 0xF12477CD;
        if (arg0->f1C == -0x3DD) {
            g->f10 = 0x3B;
            if (g->f14 == 0) {
                g->f14 = 0x3B;
            }
            r = 0;
        } else if (arg0->f1C != 0) {
            g->f10 = 0x3C;
            if (g->f14 == 0) {
                g->f14 = 0x3C;
            }
            r = 0;
        }
        if (r != 0) {
            ret = arg0->f4;
            if (*g->f30 == arg1) {
                s32 crc = -1;
                u8 *s = arg0->f4C;
                u8 *c;
                s32 j;
                B_006D9328 buf;

                poly = ~poly << 4;
                for (c = s; c < s + 0x28; c++) {
                    crc ^= *c;
                    for (j = 7; j >= 0; j--) {
                        if (crc & 1) {
                            crc = (crc >> 1) ^ poly;
                        } else {
                            crc >>= 1;
                        }
                    }
                }
                crc ^= 0x1725DFAD;

                hide_006D9328(&D_L39_00240590, &buf, *(u32 *)(s + 0x28) ^ (crc & 0xFFFF), 4, 5);
                hide_006D9328(&D_L39_00240598, &buf, *(u32 *)(s + 0x2C) ^ ((crc >> 16) & 0xFFFF), 4, 5);
                hide_006D9328(&D_L39_002405A0, &buf, s[0x30] == (crc & 0xFF), 1, 3);
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006D67D0 */
