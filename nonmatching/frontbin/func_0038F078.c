#include "common.h"

/* func_0038F078, first byte draft (wave 13 r27; fresh entry, written from retail): the front end's text
 * draw with alignment (switch on 0..8, jump table jtbl_0031C070), colour codes 8..15, per-glyph alpha
 * colours, texture page changes (func_00389D00), shadow pass and kerning, and the GIF tag finish.
 * 519 diff naive (599 of retail's 601 instructions), 139 aligned differing lines. Still differs: retail
 * spills the shadow x offset (f16 to 0x4C) and keeps the y offset in f31, here the reverse; the colour-code
 * block re-reads str[i] and indexes D_001D5B48 from its gp address (and the char is masked with andi 0xFF
 * for the 0 and 0x20 tests) where this C reuses the first load; register choices in the alpha and texture
 * page blocks; the 1.0f constant/compare is scheduled before the 0.25f products in retail. */

/* localdecomp:start func_0038F078 */
typedef struct { s32 c[4]; } C4_0038F078;
typedef int Q_0038F078 __attribute__((mode(TI)));
__asm__(".extern D_001D5B40, 1");
__asm__(".extern D_001D5B41, 1");
__asm__(".extern D_001D5B48, 8");
__asm__(".extern D_001D5B38, 4");
__asm__(".extern D_001D5B3C, 4");
__asm__(".extern D_001DA050_g, 4");
extern u8 D_001D5B40;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 *D_001D5B38;
extern s32 *D_001D5B3C;
extern u8 *D_001DA050_g;
extern u8 *D_001DA050_0038F078;
__asm__(".extern D_001DA050_0038F078, 16");
extern u8 *D_001D55C0_0038F078[];
extern u8 D_001D77E0[];
extern void func_0038DED0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 func_0038E0A8(u8 *p, s32 off, s32 *out);
extern unsigned long func_00389D00(s32, s32, s32, s32, s32);
extern s32 func_0038B850(s32, s32, s32, s32, void *, unsigned long, s32, f32, f32, f32, f32);

void func_0038F078(unsigned long *colors, u8 *str, s32 len, s32 align, s32 shadow, unsigned long shcol,
                   f32 x, f32 y, f32 scale, f32 scale2, f32 sdx, f32 sdy) {
    C4_0038F078 cur;
    C4_0038F078 base;
    unsigned long shcols[4];
    s32 idx;
    s32 idx2;
    s32 ok;
    s32 first;
    s32 page;
    unsigned long tex;
    s32 mode;
    s32 w, h;
    s32 i;
    s32 n;
    u8 *p;
    E_389D18 *g;
    f32 q, q2;
    f32 kern;
    f32 gw, gh, adv, lead, yoff, dx, dy;

    mode = 0;
    q2 = scale2 * 0.25f;
    q = scale * 0.25f;
    base.c[0] = colors[0];
    base.c[1] = colors[1];
    base.c[2] = colors[2];
    base.c[3] = colors[3];
    cur = base;
    ok = 1;
    first = 1;
    page = -1;
    tex = 0;
    shcols[0] = shcol;
    shcols[1] = shcol;
    shcols[2] = shcol;
    shcols[3] = shcol;
    kern = 0.0f;
    if (scale == 1.0f && scale2 == 1.0f) {
        if (D_001D5B40 != 0) {
            mode = 1;
        } else {
            mode = 0;
        }
    }
    func_0038DED0();
    func_003A9440(0x47, 0x33001);
    if (D_001D5B41 == 0) {
        D_001D5B48[0] = colors[0];
    }
    switch (align) {
    case 0:
        break;
    case 1:
        x -= (f32)(func_0038E548(str, len, scale) >> 1);
        break;
    case 2:
        x -= (f32)func_0038E548(str, len, scale);
        break;
    case 3:
        y -= (f32)(func_0038E3C8(str, len, scale2) >> 1);
        break;
    case 4:
        w = func_0038E548(str, len, scale);
        h = func_0038E3C8(str, len, scale2);
        x -= (f32)(w >> 1);
        y -= (f32)(h >> 1);
        break;
    case 5:
        w = func_0038E548(str, len, scale);
        h = func_0038E3C8(str, len, scale2);
        x -= (f32)w;
        y -= (f32)(h >> 1);
        break;
    case 6:
        y -= (f32)func_0038E3C8(str, len, scale2);
        break;
    case 7:
        w = func_0038E548(str, len, scale);
        h = func_0038E3C8(str, len, scale2);
        y -= (f32)h;
        x -= (f32)(w >> 1);
        break;
    case 8:
        w = func_0038E548(str, len, scale);
        h = func_0038E3C8(str, len, scale2);
        x -= (f32)w;
        y -= (f32)h;
        break;
    }
    p = D_001DA050_0038F078;
    n = 0;
    D_001DA050_g = p + 0x20;
    for (i = 0; ok && i != len; i++) {
        u8 c = str[i];

        if (c == 0) {
            ok = 0;
        } else if ((u8)(c - 8) < 8) {
            if (D_001D5B42 != 0) {
                s32 k;
                s32 rgb = D_001D5B48[str[i] - 8] & 0xFFFFFF;

                for (k = 0; k < 4; k++) {
                    cur.c[k] = (s32)(colors[k] & 0xFF000000) | rgb;
                }
            }
        } else if (c == 0x20) {
            x += (f32)(((((E_389D18 *)D_001D55C4[0])[0x20].w4 >> 29) + 2) & 0xFC) * q +
                 (f32)((((E_389D18 *)D_001D55C4[0])[0x20].w4 >> 23) & 0x3F) * scale;
            kern = 0.0f;
        } else {
            i += func_0038E0A8(str, i, &idx);
            g = &((E_389D18 *)D_001D55C4[0])[idx];
            if (g->w4 & 0x1F800000) {
                s32 k;

                if (idx < 0x20) {
                    for (k = 0; k < 4; k++) {
                        s32 a = (u32)cur.c[k] >> 24;

                        if (a >= 0x41) {
                            colors[k] = 0x80C0C0C0;
                        } else if (a >= 0x21) {
                            colors[k] = (s32)((((a - 0x20) * 3 + 0x20) << 24) | 0xC0C0C0);
                        } else {
                            colors[k] = (u32)((cur.c[k] & 0xFF000000) | 0xC0C0C0);
                        }
                    }
                } else {
                    for (k = 0; k < 4; k++) {
                        colors[k] = cur.c[k];
                    }
                }
                if ((*(u16 *)g & 0xF) != page) {
                    u8 *font = D_001D55C0_0038F078[0];
                    s32 a, b;

                    page = *(u16 *)g & 0xF;
                    a = font[page * 2 + 0x10];
                    b = font[page * 2 + 0x11];
                    tex = func_00389D00(D_001D5B38[a], D_001D5B3C[b], *(s16 *)(font + a * 4 + 0x50),
                                        *(s16 *)(font + a * 4 + 0x52), font[a + 0x40] == 0x14 ? 0x14 : 0x13);
                }
                gw = (f32)((g->w4 >> 23) & 0x3F) * scale;
                gh = (f32)((g->w4 >> 17) & 0x3F) * scale2;
                lead = (f32)(s32)(((g->w0 >> 25) + 2) & 0xFC) * q;
                adv = (kern + (f32)(((g->w4 >> 29) + 2) & 0xFC)) * q + (f32)((g->w4 >> 23) & 0x3F) * scale;
                h = (g->w4 >> 9) & 0xFF;
                if (h < 0x80) {
                    yoff = (f32)h * q2;
                } else {
                    yoff = ((f32)h - 256.0f) * q2;
                }
                if (first) {
                    first = 0;
                } else {
                    x -= lead;
                }
                dx = x + kern;
                dy = y + yoff;
                if (idx >= 0x21 && shadow != 0) {
                    if (func_0038B850(((u16 *)g)[1] & 0x1FF, g->w4 & 0x1FF, (g->w4 >> 23) & 0x3F,
                                      (g->w4 >> 17) & 0x3F, shcols, tex, mode, dx + sdx, dy + sdy, gw, gh)) {
                        n++;
                    }
                }
                x += adv;
                if (func_0038B850(((u16 *)g)[1] & 0x1FF, g->w4 & 0x1FF, (g->w4 >> 23) & 0x3F,
                                  (g->w4 >> 17) & 0x3F, colors, tex, mode, dx, dy, gw, gh)) {
                    n++;
                }
                kern = 0.0f;
                if ((g->w0 & 0xFFF0) && i != len) {
                    func_0038E0A8(str, i + 1, &idx2);
                    if (idx2 != 0) {
                        K_389D18 *kk = (K_389D18 *)((u8 *)D_001D55C4[1] + ((g->w0 >> 2) & 0x3FFC));
                        s32 r = 0;

                        if (kk != 0) {
                            for (; kk->end == 0; kk++) {
                                if (kk->ch == idx2) {
                                    r = kk->adj;
                                    break;
                                }
                            }
                        }
                        kern = (f32)r * q;
                    }
                }
            }
        }
    }
    if (n != 0) {
        *(u32 *)(p + 0xC) = (n * 8 + 1) | 0x50000000;
        *(u32 *)(p + 0x0) = (n * 8 + 1) | 0x10000000;
        *(u32 *)(p + 0x4) = 0;
        *(u32 *)(p + 0x8) = 0;
        *(Q_0038F078 *)(p + 0x10) = *(Q_0038F078 *)D_001D77E0;
        *(u32 *)(p + 0x10) = n | 0x8000;
        func_003A9440(8, 5);
    } else {
        D_001DA050_0038F078 -= 0x20;
    }
}
/* localdecomp:end func_0038F078 */
