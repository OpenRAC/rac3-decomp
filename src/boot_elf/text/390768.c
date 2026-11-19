#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E518.c's earlier functions */
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
extern s32 *D_001D55C4[];
extern u8 D_001D5B42;

typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 fl; s16 h14, h16, h18, h1A; } O_0038B1E8;
typedef struct { s16 key; s8 val; u8 end; } K_0038B1E8;
extern s32 D_001D5B94;
extern u8 D_001D5B41, D_001D5B42, D_001D5B40;
extern s32 D_001D5B68;
extern s32 D_001D5B48[2];
extern s32 D_001D9C80;
extern u16 D_001D9C88[4], D_001D9CA0[4], D_001D9CB8[4], D_001D9CD0[4];
extern s32 D_001D55C4_0038FD40;
extern s32 D_001D55C8_0038FD40;
extern s32 D_001D4BC0_0038FD40, D_001D4BC4_0038FD40;
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E928_0038FD40(u8 *, s32, f32);
extern void func_0038EBC8_0038FD40(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E928_00390768(u8 *, s32, f32);
extern void func_0038EBC8_00390768(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
/* localdecomp:start func_00390768 */
extern s32 D_001D5B94_00390768 __attribute__((section(".data")));
__asm__(".extern D_001D5B41, 1");
__asm__(".extern D_001D5B48, 8");
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
void func_00390768(B_38BB50 *b, long ca, u8 **strs, s32 n, s16 sel, long cb, s32 *outx, s32 *outy, f32 scale) {
    s16 starts[80];
    s16 ends[80];
    s16 colors[80];
    u8 *lines[80];
    s32 c1, c2;
    s32 lim;
    s32 first;
    s32 nlines;
    s32 j;
    f32 quarter, width;

    if (D_001D5B94_00390768 != 1 && !(b->h12 & 0x10)) {
        func_003A98B8(b->h4, b->h6 - 1, b->h0, b->h2 - 1);
    }
    first = 1;
    D_001D5B41 = 1;
    lim = -1;
    quarter = scale * 0.25f;
    if (((u8)b->h12 ^ 1) & 1) {
        width = (f32)(b->h6 - b->h8);
    } else {
        s32 r = b->h6 - b->h8;
        s32 l = b->h8 - b->h4;
        if (r < l) l = r;
        width = (f32)l;
        width *= 2.0f;
    }
    j = 0;
    do {
        nlines = 0;
        for (; j < n; j++) {
            u8 *s = strs[j];
            s32 pos = 0;
            while (s[pos] != 0 && nlines < 0x4F) {
                s32 k = nlines;
                s32 brk;
                f32 w;
                lines[k] = s;
                starts[k] = pos;
                {
                    s16 *cp = colors + k;
                    if (sel < 0) *cp = 0;
                    else if (sel != j) *cp = 0;
                    else *cp = 5;
                }
                w = 0.0f;
                brk = pos;
                while (w < width) {
                    u8 c = s[pos];
                    if (c == 0x20 || c < 0x10 || c == 0x2F) brk = pos;
                    if (s[pos] < 2) break;
                    pos += func_0038E488(s, pos, &c1);
                    if (((G_38BB50 *)D_001D55C4[0])[c1].w1 & 0x1F800000) {
                        f32 f = (f32)(s32)(((((G_38BB50 *)D_001D55C4[0])[c1].w0 >> 25) + 2) & 0xFC) * quarter;
                        if (first) first = 0;
                        else w -= f;
                        w += (f32)((((G_38BB50 *)D_001D55C4[0])[c1].w1 >> 23) & 0x3F) * scale;
                        func_0038E488(s, pos + 1, &c2);
                        if (c2 >= 0x10) {
                            w += (f32)(((((G_38BB50 *)D_001D55C4[0])[c1].w1 >> 29) + 2) & 0xFC) * 0.25f * scale;
                        }
                    }
                    pos++;
                }
                ends[k] = brk;
                if (ends[k] == starts[k]) ends[k] = pos;
                pos = ends[k];
                if (s[pos] == 0x20 || s[pos] < 0x10) ends[k]--;
                nlines++;
                if (s[pos] == 0) break;
                pos++;
                if (pos == lim) break;
            }
        }
    } while (0);
    {
        s32 y, i;
        {
            s32 t = nlines * b->h10;
            b->hC = 0;
            b->hE = t;
            y = b->hA;
            if (b->h12 & 2) y -= t >> 1;
        }
        for (i = 0; i < nlines; i++) {
            if (y + b->h10 >= b->h0 && b->h2 >= y) {
                s32 len = ends[i] - starts[i] + 1;
                s32 wpx;
                if (lim > 0 && lim < len) len = lim;
                wpx = func_0038E928_00390768(lines[i] + starts[i], len, 1.0f);
                if (b->hC < wpx) b->hC = wpx;
                if (!(b->h12 & 4)) {
                    u16 fl;
                    D_001D5B48[0] = ca;
                    D_001D5B5C[0] = cb;
                    fl = b->h12;
                    if (fl & 8) {
                        f32 x, yy;
                        if (fl & 1) {
                            x = (f32)(b->h8 - (wpx >> 1)) + (f32)b->h14 * 0.0625f;
                        } else {
                            x = (f32)b->h8 + (f32)b->h14 * 0.0625f;
                        }
                        yy = (f32)y + (f32)b->h16 * 0.0625f;
                        if (colors[i] == 5) {
                            *outx = b->h8;
                            *outy = (s32)yy + (s32)((f32)b->h10 * 0.5f - 0.5f);
                        }
                        func_0038EBC8_00390768(x, yy, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                    } else {
                        if (fl & 1) {
                            func_0038EBC8_00390768((f32)(b->h8 - (wpx >> 1)), (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        } else {
                            func_0038EBC8_00390768((f32)b->h8, (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        }
                        if (colors[i] == 5) {
                            *outx = b->h8;
                            *outy = y + (s32)((f32)b->h10 * 0.5f - 0.5f);
                        }
                    }
                }
                if (lim > 0) {
                    lim -= len;
                    if (lim <= 0) break;
                }
            }
            y += b->h10;
        }
    }
    D_001D5B41 = 0;
    if (D_001D5B94_00390768 != 1 && !(b->h12 & 0x10)) {
        func_003A98B8(0, D_001D4BC0[0] - 1, 0, D_001D4BC4[0] - 1);
    }
}
/* localdecomp:end func_00390768 */
