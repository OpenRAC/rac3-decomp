/* NTSC-U draft (Claude wave K): C of func_L39_005DEA20, the NTSC-U twin of func_L39_005E0FC8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L39_005DEA20", whose code is not the PAL one).
 * Worker's note: first draft, 74 aligned words with @ps2as (the PAL line lacks it), 448 vs 451 words; NEEDS divs row 'func_L39_005DEA20 2 1'. Whole body decoded: three modes on D_L39_002417C0->w180 (1 / 0 / other), each sets up the same 0x30010-0x30017 widget slots via ...
 */
#include "common.h"

/* localdecomp:start func_L39_005DEA20 */
typedef struct G_005DEA20 {
    s32 w0;
    s32 w4;
    u8 pad8[0x20C - 0x8];
    u8 *p20C;
    s32 w210;
} G_005DEA20;

extern u8 *D_L39_002417C0;
extern s32 *D_L39_002412A0;
extern G_005DEA20 D_L39_00352A40;
extern s32 D_001A5F78[];
extern s32 D_L39_0024C680;
extern s32 D_L39_0024C684;
extern s32 D_L39_0024C690;
extern s32 D_L39_0024C698;
extern u8 D_L39_0024C6A0[];
extern u8 D_L39_0024C6A8[];
extern u8 D_L39_0024C6B0[];
extern u8 D_L39_00243AB0[];
extern u8 D_L39_00243AB8[];
extern u8 D_L39_00243AC8[];
extern u8 D_L39_00243AD8[];
extern u8 D_L39_00243AE0[];
extern u8 D_L39_002B5CF0[];

extern void func_L01_005131A0(s32, s32);
extern void func_L01_00512480(s32, f32, f32);
extern void func_L01_00513548(s32, f32, f32);
extern void func_L01_00512AB0(s32, s32, s32);
extern void func_L01_005130C8(s32, s32);
extern void func_L01_00512FE8(s32, void *);
extern s32 func_L01_00513698(void);
extern void func_00120048(void *, void *, ...);
extern void func_L39_005DE958(s32, s32);

void func_L39_005DEA20(void) {
    u8 *g;
    u8 *q;
    s32 mode;
    s32 i;
    s32 t;
    s32 mn;
    s32 sc;
    u8 *buf;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;

    mode = *(s32 *)(D_L39_002417C0 + 0x180);
    if (mode == 1) {
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
        func_00120048(D_L39_0024C6A0, D_L39_00243AB0, *(s32 *)(*(u8 **)&D_L39_00352A40.w210 + 0xC));
        func_00120048(D_L39_0024C6A8, D_L39_00243AB0, *(s32 *)(*(u8 **)&D_L39_00352A40.w210 + 8));
    } else if (mode == 0) {
        func_L01_005131A0(0x3000F, 0xED33);
        if (*(f32 *)(D_L39_00352A40.p20C + 0x148) != *(f32 *)(D_L39_00352A40.p20C + 0x128)) {
            D_L39_0024C680 = 0x3C;
        }
        if (*(f32 *)(D_L39_00352A40.p20C + 0x14C) != *(f32 *)(D_L39_00352A40.p20C + 0x12C)) {
            D_L39_0024C684 = 0x3C;
        }
        func_L39_005DE958(0, 0x60FF0000);
        func_L39_005DE958(1, 0x600000FF);
        f21 = *(f32 *)(D_L39_00352A40.p20C + 0x14C) / *(f32 *)(D_L39_00352A40.p20C + 0x10C);
        f22 = *(f32 *)(D_L39_00352A40.p20C + 0x148) / *(f32 *)(D_L39_00352A40.p20C + 0x108);
        func_L01_00513548(0x30011, f21 * 0.18f, 0.02f);
        func_L01_00513548(0x30010, f22 * 0.18f, 0.02f);
        func_L01_005130C8(0x30010, D_L39_0024C690);
        func_L01_005130C8(0x30011, D_L39_0024C698);
        func_L01_00512AB0(0x3000C, 1, 1);
        func_L01_00512AB0(0x30011, 1, 1);
        func_L01_00512AB0(0x30010, 1, 1);
        func_L01_00512AB0(0x30012, 1, 0);
        func_L01_00512AB0(0x30013, 1, 0);
        func_L01_00512AB0(0x30014, 1, 0);
        func_L01_00512AB0(0x30015, 1, 0);
        func_L01_00512AB0(0x30017, 1, 0);
    } else {
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
        g = (u8 *)&D_L39_00352A40;
        buf = D_L39_002B5CF0 + i * 16;
        func_00120048(buf, D_L39_00243AB8, *(s16 *)(g + i * 4 + 0x18) - *(s16 *)(g + i * 2 + 0x198), *(s8 *)(D_L39_002417C0 + 0x197));
        func_L01_00512480(0x30017, 0.78f, 0.06f);
        func_L01_00513548(0x30017, 0.6f, 0.7f);
        func_L01_00512FE8(0x30017, buf);
    }
    if (*D_L39_002412A0 < 3) {
        func_L01_00512AB0(0x3000C, 1, 0);
    }
    t = D_L39_00352A40.w0 - (D_001A5F78[0] - D_L39_00352A40.w4);
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
