#include "common.h"

/* NTSC-U counterpart of func_L39_005E0FC8 (src/levels/shared/L40_004B3670.c) */
/* localdecomp:start func_L39_005DEA20 */
typedef struct H_005E0FC8 {
    s16 a;
    s16 b;
} H_005E0FC8;

typedef struct G_005E0FC8 {
    s32 w0;
    s32 w4;
    u8 pad8[0x10];
    H_005E0FC8 x18[96];
    s16 h198[58];
    u8 *p20C;
    s32 *p210;
} G_005E0FC8;

extern u8 *D_L39_002417C0;
__asm__(".extern D_L39_002417C0, 16");
extern s32 *D_L39_002412A0;
extern G_005E0FC8 D_L39_00352A40;
extern s32 D_001A5F78[];
__asm__(".extern D_L39_0024C680, 16");
__asm__(".extern D_L39_0024C690, 16");
extern s32 D_L39_0024C680[2];
extern long D_L39_0024C690[2] __attribute__((section(".sdata")));
extern u8 D_L39_0024C6A0[] __attribute__((section(".sdata")));
extern u8 D_L39_0024C6A8[] __attribute__((section(".sdata")));
extern u8 D_L39_0024C6B0[] __attribute__((section(".sdata")));
extern u8 D_L39_00243AB0[];
extern u8 D_L39_00243AB8[];
extern u8 D_L39_00243AC8[];
extern u8 D_L39_00243AD8[];
extern u8 D_L39_00243AE0[];
extern u8 D_L39_002B5CF0[];

extern s32 func_L01_005131A0(s32, s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L01_00512FE8(s32, void *);
extern s32 func_L01_00513698(void);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_005DE958(s32, long);

void func_L39_005DEA20(void)
{
    s32 mode;
    s32 i;
    s32 t;
    s32 e;
    s32 mn;
    s32 sc;
    u8 *buf;
    s32 c;
    s32 d;
    f32 vol11;
    f32 vol10;

    mode = *(s32 *)(D_L39_002417C0 + 0x180);
    if (mode == 1) {
        G_005E0FC8 *g = &D_L39_00352A40;

        func_L01_005131A0(0x3000F, 0xED5B);
        func_L01_00512480(0x30012, 0.83f, 0.08f);
        func_L01_00512480(0x30013, 0.74f, 0.08f);
        func_L01_00512480(0x30014, 0.825f, 0.062f);
        func_L01_00512480(0x30015, 0.74f, 0.062f);
        func_L01_00513548(0x30012, 0.073f, 0.055f);
        func_L01_00513548(0x30013, 0.073f, 0.055f);
        func_L01_00513548(0x30014, 0.7f, 0.75f);
        func_L01_00513548(0x30015, 0.7f, 0.75f);
        func_L01_00512AB0(0x3000C, 1, 1);
        func_L01_00512AB0(0x30011, 1, 0);
        func_L01_00512AB0(0x30010, 1, 0);
        func_L01_00512AB0(0x30012, 1, 1);
        func_L01_00512AB0(0x30013, 1, 1);
        func_L01_00512AB0(0x30014, 1, 1);
        func_L01_00512AB0(0x30015, 1, 1);
        func_L01_00512AB0(0x30017, 1, 0);
        func_00120048(D_L39_0024C6A0, D_L39_00243AB0, g->p210[3]);
        func_00120048(D_L39_0024C6A8, D_L39_00243AB0, g->p210[2]);
    } else if (mode == 0) {
        G_005E0FC8 *g;

        func_L01_005131A0(0x3000F, 0xED33);
        g = &D_L39_00352A40;
        if (*(f32 *)(g->p20C + 0x128) != *(f32 *)(g->p20C + 0x148)) {
            D_L39_0024C680[0] = 0x3C;
        }
        if (*(f32 *)(g->p20C + 0x12C) != *(f32 *)(g->p20C + 0x14C)) {
            D_L39_0024C680[1] = 0x3C;
        }
        func_L39_005DE958(0, 0x60FF0000);
        func_L39_005DE958(1, 0x600000FF);
        vol11 = *(f32 *)(g->p20C + 0x14C) / *(f32 *)(g->p20C + 0x10C);
        vol10 = *(f32 *)(g->p20C + 0x148) / *(f32 *)(g->p20C + 0x108);
        func_L01_00513548(0x30011, vol11 * 0.18f, 0.02f);
        func_L01_00513548(0x30010, vol10 * 0.18f, 0.02f);
        func_L01_005130C8(0x30010, D_L39_0024C690[0]);
        func_L01_005130C8(0x30011, D_L39_0024C690[1]);
        func_L01_00512AB0(0x3000C, 1, 1);
        func_L01_00512AB0(0x30011, 1, 1);
        func_L01_00512AB0(0x30010, 1, 1);
        func_L01_00512AB0(0x30012, 1, 0);
        func_L01_00512AB0(0x30013, 1, 0);
        func_L01_00512AB0(0x30014, 1, 0);
        func_L01_00512AB0(0x30015, 1, 0);
        func_L01_00512AB0(0x30017, 1, 0);
    } else {
        G_005E0FC8 *g;

        func_L01_005131A0(0x3000F, 0xED3B);
        func_L01_00512AB0(0x3000C, 1, 1);
        func_L01_00512AB0(0x30011, 1, 0);
        func_L01_00512AB0(0x30010, 1, 0);
        func_L01_00512AB0(0x30012, 1, 0);
        func_L01_00512AB0(0x30013, 1, 0);
        func_L01_00512AB0(0x30014, 1, 0);
        func_L01_00512AB0(0x30015, 1, 0);
        func_L01_00512AB0(0x30017, 1, 1);
        i = func_L01_00513698();
        g = &D_L39_00352A40;
        d = g->x18[i].a - g->h198[i];
        buf = D_L39_002B5CF0 + i * 16;
        c = *(s8 *)(D_L39_002417C0 + 0x197);
        func_00120048(buf, D_L39_00243AB8, d, c);
        func_L01_00512480(0x30017, 0.78f, 0.06f);
        func_L01_00513548(0x30017, 0.6f, 0.7f);
        func_L01_00512FE8(0x30017, buf);
    }
    if (*D_L39_002412A0 < 3) {
        func_L01_00512AB0(0x3000C, 1, 0);
    }
    e = D_001A5F78[0] - D_L39_00352A40.w4;
    t = D_L39_00352A40.w0 - e;
    if (t < 0) {
        t = 0;
    }
    mn = t / 60000;
    sc = t % 60000 / 1000;
    func_00120048(D_L39_0024C6B0, D_L39_00243AC8, mn < 10 ? D_L39_00243AD8 : D_L39_00243AE0, mn, sc < 10 ? D_L39_00243AD8 : D_L39_00243AE0, sc);
    func_L01_00512FE8(0x30016, D_L39_0024C6B0);
    func_L01_00512480(0x30016, 0.77f, 0.12f);
    func_L01_00513548(0x30016, 0.55f, 0.7f);
    if (*D_L39_002412A0 >= 3) {
        if (D_L39_00352A40.w0 != -1) {
            func_L01_00512AB0(0x30016, 1, 1);
        } else {
            func_L01_00512AB0(0x30016, 1, 0);
        }
    } else {
        func_L01_00512AB0(0x30016, 1, 0);
        func_L01_00512AB0(0x30017, 1, 0);
    }
}
/* localdecomp:end func_L39_005DEA20 */
