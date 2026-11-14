#include "common.h"

/* NTSC-U counterpart of func_L10_00407D40 (src/levels/10_zeldrin_starport/L10_00407D40.c) */
#include "vu0.h"

/* localdecomp:start func_L10_004048F0 */
typedef int u128_t_407D40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_407D40;
typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[1];
} G_407D40;
extern G_407D40 D_L10_001E5F80;
extern u8 *D_L10_002387F0[];
extern u8 D_L10_001D6AE0_004048F0[4];
extern u8 D_L10_001D6AE4_004048F0[4];
extern u8 D_L10_001D6AE8_004048F0[4];
extern s32 D_001D545C;
__asm__(".extern D_L10_001D6AE0_004048F0, 4");
extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_003A26D0(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00421438(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L01_004210C0(void);
extern void func_L01_00420F18(void *, f32, f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 D_L10_001D6C58_004048F0[8];
extern u8 D_L10_001D6C98_004048F0[8];
extern u8 D_L10_001D6CC0_004048F0[8];
extern u8 *D_L10_001D6C50_004048F0;
extern f32 D_L10_001D6C2C_004048F0;
extern f32 D_L10_001DECD0;
__asm__(".extern D_L10_001D6C58_004048F0, 8");
__asm__(".extern D_L10_001D6C98_004048F0, 8");
__asm__(".extern D_L10_001D6CC0_004048F0, 8");
__asm__(".extern D_L10_001DECD0, 4");
extern void func_L03_0040E698(s32, s32);
extern void func_L08_00403E80(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L10_00404678(void *);
extern f32 func_0037E250(f32, f32);
extern void func_L01_004282C0(s32, s32);
extern void func_L10_00404020(s32, s32, f32);
extern void func_L10_003E38B8(float);
extern void func_L04_004C61D8(void);
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_004048F0(void) {
    s32 i;
    u8 *o;
    s32 t;
    s32 i2;
    u8 **p;
    G_407D40 *g;
    V4_407D40 d;

    func_L01_00420D88();
    for (i = 0; i < D_L10_001E5F80.count; i++) {
        o = D_L10_001E5F80.mobys[i];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0xE29) {
            *(u16 *)(o + 0x34) |= 0x800;
        }
        if (*(s16 *)(o + 0xAA) == 0xD54) {
            o[0x63] = 0;
            for (i2 = 0; D_L10_002387F0[i2] != 0; i2++) {
                if (D_L10_002387F0[i2][0x63] != 0) {
                    D_L10_002387F0[i2][0x63] = 1;
                }
            }
            func_003A04A0(o, 0);
            func_L01_004026A0(func_003A26D0, o);
        }
        if (o == 0) {
            continue;
        }
        t = *(s16 *)(o + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(o + 0x68) != 0) {
                func_L01_0044EB38(o, *(u8 **)(o + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.06108652800321579f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_0044EB38(o, D_L10_001D6AE0_004048F0, 0x80505080, 0x80404038, 0.03199770301580429f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(o, D_L10_001D6AE4_004048F0, 0x8080AAAA, 0x80464646, 0.03781547024846077f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(o, D_L10_001D6AE8_004048F0, 0x80AAAAFF, 0x80646496, 0.11053752899169922f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, o);
        }
    }
    if (D_001D545C == 0xA) {
        g = &D_L10_001E5F80;
        if (g->mode == 1) {
            func_L03_0040E698(0x1BE, 0x29E);
        } else if (g->mode == 2) {
            func_L01_004210C0();
            if (g->timer == 0xE1A) {
                qzero(&d);
                d.z += 2.0f;
                func_L08_00403E80(3, &d, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
            } else if (g->timer == 0xC9E) {
                qzero(&d);
                d.z += 1.0f;
                func_L08_00403E80(4, &d, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
            }
            D_L10_001D6C50_004048F0 = D_L10_001D6C58_004048F0;
            func_L10_00404678(D_L10_001D6C98_004048F0);
        } else if (g->mode == 3) {
            if ((g->timer % 50 == 0 && func_0037E1D8(2) == 0) || g->timer == 0x1E || g->timer == 0x113 || g->timer == 0x1C2) {
                *(u128_t_407D40 *)&d = 0;
                d.x = 20.0f;
                d.z = 2.0f;
                func_L01_00420F18(&d, 15.0f, 0.1f, func_0037E250(2.0f, 5.0f));
            }
        } else if (g->mode == 5) {
            f32 f;
            if (g->timer == 1) {
                func_L01_004282C0(2, 0);
            }
            f = 1.0f;
            if (g->timer >= 0x29E) {
                f = 0.8f;
            }
            func_L10_00404020(0, 1, f);
        } else if (g->mode == 6) {
            func_L10_003E38B8(4096.0f);
            if (g->timer == 0xF) {
                d = *(V4_407D40 *)(g->mobys[0] + 0x10);
                func_L01_0032FE90(&d, 0, 0, 0, 0, 5, 0, 0, 3.0f, 0.0f, 0.0f, 2.0f,
                                  0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            if (g->timer >= 0x64) {
                if (g->timer == 0x64) {
                    D_L10_001D6C2C_004048F0 = 9999.0f;
                }
                func_L10_00404020(0, 1, 1.0f);
            }
            if (D_L10_001E5F80.timer >= 0x1CC) {
                D_L10_001DECD0 = (f32)(D_L10_001E5F80.timer - 0x1CC) / 240.0f;
            }
        } else if (g->mode == 7) {
            func_L04_004C61D8();
            D_L10_001D6C50_004048F0 = D_L10_001D6C58_004048F0;
            func_L10_00404678(D_L10_001D6CC0_004048F0);
        }
    }
}
/* localdecomp:end func_L10_004048F0 */
