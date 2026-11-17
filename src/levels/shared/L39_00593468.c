#include "common.h"

/* localdecomp:start func_L39_00593468 */
typedef struct {
    s16 top;    /* 0x00 */
    s16 bottom; /* 0x02 */
    s16 left;   /* 0x04 */
    s16 right;  /* 0x06 */
    s16 x;      /* 0x08 */
    s16 y;      /* 0x0A */
    s16 maxw;   /* 0x0C */
    s16 height; /* 0x0E */
    s16 lineh;  /* 0x10 */
    u16 flags;  /* 0x12 */
    s16 dx;     /* 0x14 */
    s16 dy;     /* 0x16 */
    s16 f18;    /* 0x18 */
    s16 f1A;    /* 0x1A */
} S_00593468;
typedef struct { u32 w0; u32 w4; } G_00593468;
typedef struct { s16 ch; s8 adj; u8 end; } K_00593468;

extern s32 func_0038E0A8(u8 *p, s32 off, s32 *out);
extern s32 func_0038E548(u8 *, s32, f32);
extern void func_0038E7E8(f32 x, f32 y, s32 a, s32 b, s32 c, f32 sx, f32 sy, s32 d, s32 e, f32 f, f32 g, unsigned long h);
extern void func_003A9500(s32, s32, s32, s32);

extern s32 D_L39_00241128;
extern s32 D_L39_00240300, D_L39_00240304, D_L39_00240308, D_L39_0024030C;
__asm__(".extern D_L39_00240300, 16");
__asm__(".extern D_L39_00240304, 16");
__asm__(".extern D_L39_00240308, 16");
__asm__(".extern D_L39_0024030C, 16");
extern s32 D_L39_0024144C;
__asm__(".extern D_L39_0024144C, 16");
extern u8 *D_L39_00241450;
__asm__(".extern D_L39_00241450, 16");
extern s32 D_L39_0024BAA0;
extern s16 D_L39_0024BAA8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BAA8, 24");
extern s16 D_L39_0024BAC0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BAC0, 24");
extern s16 D_L39_0024BAD8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BAD8, 24");
extern s16 D_L39_0024BAF0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BAF0, 24");
extern u8 D_001D7118_sda;
__asm__(".extern D_001D7118_sda, 1");
extern u8 D_001D7119_sda;
__asm__(".extern D_001D7119_sda, 1");
extern u8 D_001D711A_sda;
__asm__(".extern D_001D711A_sda, 1");
extern s32 D_001D7120_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D7120_sda, 4");
extern s32 D_001D7140_sda;
__asm__(".extern D_001D7140_sda, 4");
extern u8 D_001D7144_sda;
__asm__(".extern D_001D7144_sda, 1");

void func_L39_00593468(void *arg, f32 sx, f32 sy, long color, char *text, s32 len, unsigned long arg6) {
    S_00593468 *s = (S_00593468 *)arg;
    u8 *str = (u8 *)text;
    s16 starts[504];
    s16 ends[504];
    s16 colors[504];
    s32 idx;
    s32 idx2;
    f32 q;
    f32 kern;
    s32 width;
    s32 fitted;
    s32 tried;
    s32 width0;
    s32 nlines;
    s32 col;
    f32 lastx;
    s32 done;
    s32 first = 1;
    s32 k;
    s32 j;
    s32 m;
    s32 y;

    q = sx * 0.25f;
    kern = 0.0f;
    idx = 0;
    if (D_L39_00241128 != 1 && !(s->flags & 0x10)) {
        s32 a = (s32)((f32)D_L39_00240308 - (f32)D_L39_00240300 * 0.5f);
        s32 b = (s32)((f32)D_L39_0024030C - (f32)D_L39_00240304 * 0.5f);
        func_003A9500(s->left + a, s->right - 1 + a, s->top + b, s->bottom - 1 + b);
    }
    D_001D7119_sda = 1;
    if ((u8)(s->flags ^ 1) & 1) {
        width = s->right - s->x;
    } else {
        s32 r = s->right - s->x;
        s32 l = s->x - s->left;
        if (r < l) l = r;
        width = l * 2;
    }
    fitted = D_001D7144_sda;
    tried = 0;
    width0 = width;
    nlines = 0;
    col = 0;
    lastx = 0.0f;
    while (D_001D7140_sda != 2) {
        s32 ok;
        s32 i;
        nlines = 0;
        ok = 1;
        first = 1;
        for (i = 0; ok && i != len; i++) {
            if (str[i] == 0) {
                ok = 0;
            } else if (nlines >= 499) {
                ok = 0;
            } else {
                f32 x;
                s32 brk;
                s32 cont;
                s32 next;
                starts[nlines] = i;
                next = nlines + 1;
                colors[nlines] = col;
                x = 0.0f;
                brk = i;
                cont = 1;
                while (x < (f32)width) {
                    u8 c;
                    if (str[i] == ' ' || str[i] < 0x10) brk = i;
                    if (D_001D711A_sda != 0 && (u8)(str[i] - 8) < 8) col = str[i] - 8;
                    c = str[i];
                    if (c == 0) {
                        ok = 0;
                        cont = 0;
                        i--;
                    } else if (c == 1) {
                        cont = 0;
                        i--;
                    } else {
                        G_00593468 *e;
                        s32 nx;
                        i += func_0038E0A8(str, i, &idx);
                        e = (G_00593468 *)(idx * 8 + D_L39_0024144C);
                        if (e->w4 & 0x1F800000) {
                            f32 b = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * q;
                            f32 adv = (kern + (f32)(((e->w4 >> 29) + 2) & 0xFC)) * q + (f32)((e->w4 >> 23) & 0x3F) * sx;
                            f32 w = (f32)((e->w4 >> 23) & 0x3F) * sx;
                            if (first) {
                                first = 0;
                            } else {
                                x -= b;
                            }
                            if (i != len) {
                                func_0038E0A8(str, i + 1, &idx2);
                                nx = idx2;
                                if (nx != 0) {
                                    x += adv + kern;
                                    if (e->w0 & 0xFFF0) {
                                        K_00593468 *kp = (K_00593468 *)(D_L39_00241450 + ((e->w0 >> 2) & 0x3FFC));
                                        s32 r;
                                        if (kp != 0) {
                                            s32 j2;
                                            for (j2 = 0; kp[j2].end == 0; j2++) {
                                                if (kp[j2].ch == nx) {
                                                    r = kp[j2].adj;
                                                    goto found;
                                                }
                                            }
                                        }
                                        r = 0;
                                    found:
                                        kern = (f32)r;
                                        kern = kern * q;
                                    } else {
                                        kern = 0.0f;
                                    }
                                } else {
                                    x += w;
                                }
                            } else {
                                x += w;
                            }
                        }
                    }
                    i++;
                    if (!cont) break;
                }
                if (D_001D711A_sda != 0 && (f32)width <= x) {
                    if (idx >= 8) {
                        if (idx <= 15) col = idx - 8;
                    }
                }
                ends[nlines] = brk;
                if (ends[nlines] == starts[nlines]) {
                    if (x < (f32)width) {
                        ends[nlines] = i;
                    } else if (ends[nlines] + 1 < i) {
                        ends[nlines] = i - 2;
                    } else if (ends[nlines] < i) {
                        ends[nlines] = i - 1;
                    } else {
                        ends[nlines] = i;
                    }
                }
                i = ends[nlines];
                if (str[i] == ' ' || str[i] < 0x10) ends[nlines]--;
                nlines = next;
                lastx = x;
            }
        }
        done = 0;
        if (fitted == 0 && nlines >= 2) {
            if (tried == 0) {
                if (lastx < (f32)(width >> 2)) {
                    tried = nlines;
                    done = 1;
                    width -= (width - (s32)lastx) / (nlines + 1);
                }
            } else if (tried < nlines) {
                done = 1;
                width = width0;
                fitted = 1;
            }
        }
        if (!done) break;
    }
    if (D_001D7140_sda != 0) {
        if (D_001D7140_sda == 1) {
            D_L39_0024BAA0 = nlines;
            for (j = 0; j < nlines && j < 12; j++) {
                D_L39_0024BAA8[j] = starts[j];
                D_L39_0024BAC0[j] = ends[j];
                D_L39_0024BAD8[j] = colors[j];
            }
        } else {
            nlines = D_L39_0024BAA0;
            for (m = 0; m < nlines && m < 12; m++) {
                starts[m] = D_L39_0024BAA8[m];
                ends[m] = D_L39_0024BAC0[m];
                colors[m] = D_L39_0024BAD8[m];
            }
        }
    }
    s->maxw = 0;
    s->height = nlines * s->lineh;
    y = s->y;
    if (s->flags & 2) y -= s->height >> 1;
    for (k = 0; k < nlines; k++, y += s->lineh) {
        s32 n;
        s32 w;
        if (y + s->lineh < s->top) continue;
        if (s->bottom < y) break;
        n = ends[k] - starts[k] + 1;
        if (len > 0 && len < n) n = len;
        w = 0;
        if (D_001D7140_sda != 2) w = func_0038E548(str + starts[k], n, sx);
        if (D_001D7140_sda != 0) {
            if (D_001D7140_sda == 1) {
                D_L39_0024BAF0[k] = w;
            } else {
                w = D_L39_0024BAF0[k];
            }
        }
        if (s->maxw < w) s->maxw = w;
        if (!(s->flags & 4)) {
            f32 fx;
            f32 fy;
            u16 fl;
            u8 saved;
            D_001D7120_sda[0] = color;
            fy = (f32)y;
            fl = s->flags;
            fx = (f32)s->x;
            if (fl & 1) fx -= (f32)(w >> 1);
            saved = D_001D7118_sda;
            if (fl & 8) {
                fx += (f32)s->dx * 0.0625f;
                fy += (f32)s->dy * 0.0625f;
                D_001D7118_sda = 0;
            }
            func_0038E7E8(fx, fy, D_001D7120_sda[colors[k]], (s32)(str + starts[k]), n, sx, sy, 0, (s->flags >> 5) & 1,
                          (f32)s->f18, (f32)s->f1A, arg6);
            D_001D7118_sda = saved;
        }
        if (len > 0) {
            len -= n;
            if (len <= 0) break;
        }
    }
    D_001D7119_sda = 0;
    if (D_L39_00241128 != 1 && !(s->flags & 0x10)) {
        func_003A9500(0, D_L39_00240300 - 1, 0, D_L39_00240304 - 1);
    }
    D_001D7140_sda = 0;
}
/* localdecomp:end func_L39_00593468 */

/* localdecomp:start func_L39_00593E40 */
/* from the frontbin twin func_00390388 (nonmatching/frontbin/func_00390388.c draft) */
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_00593E40;
typedef struct { u32 w0, w1; } G_00593E40;
extern s32 D_L39_00242844;
__asm__(".extern D_L39_00242844, 16");
__asm__(".extern D_001D7120_sda, 8");
__asm__(".extern D_001D7119_sda, 1");
void func_L39_00593E40(B_00593E40 *b, f32 scale, long ca, u8 **strs, s32 n, s16 sel, long cb, s32 *outx, s32 *outy) {
    s16 starts[500];
    s16 ends[500];
    s16 colors[500];
    u8 *lines[500];
    s32 c1, c2;
    s32 lim;
    s32 first;
    s32 nlines;
    s32 j;
    f32 quarter, width;

    if (D_L39_00241128 != 1 && !(b->h12 & 0x10)) {
        func_003A9500(b->h4, b->h6 - 1, b->h0, b->h2 - 1);
    }
    first = 1;
    D_001D7119_sda = 1;
    lim = -1;
    quarter = scale * 0.25f;
    if ((*(u8 *)&b->h12 ^ 1) & 1) {
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
            while (s[pos] != 0 && nlines < 0x1F3) {
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
                    pos += func_0038E0A8(s, pos, &c1);
                    {
                        if (((G_00593E40 *)D_L39_0024144C)[c1].w1 & 0x1F800000) {
                            f32 f = (f32)(s32)(((((G_00593E40 *)D_L39_0024144C)[c1].w0 >> 25) + 2) & 0xFC) * quarter;
                            if (first) first = 0;
                            else w -= f;
                            w += (f32)((((G_00593E40 *)D_L39_0024144C)[c1].w1 >> 23) & 0x3F) * scale;
                            func_0038E0A8(s, pos + 1, &c2);
                            if (c2 >= 0x10) {
                                w += (f32)(((((G_00593E40 *)D_L39_0024144C)[c1].w1 >> 29) + 2) & 0xFC) * 0.25f * scale;
                            }
                        }
                    }
                    pos++;
                }
                ends[k] = brk;
                if ((s16)brk == starts[k]) ends[k] = pos;
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
                wpx = func_0038E548(lines[i] + starts[i], len, 1.0f);
                if (b->hC < wpx) b->hC = wpx;
                if (!(b->h12 & 4)) {
                    u16 fl;
                    D_L39_00242844 = cb;
                    D_001D7120_sda[0] = ca;
                    fl = b->h12;
                    if (fl & 8) {
                        f32 x, yy;
                        u16 hx;
                        if (fl & 1) {
                            x = (f32)(b->h8 - (wpx >> 1)) + (f32)b->h14 * 0.0625f;
                            hx = b->h8;
                        } else {
                            x = (f32)b->h8 + (f32)b->h14 * 0.0625f;
                            hx = b->h8;
                        }
                        yy = (f32)y + (f32)b->h16 * 0.0625f;
                        if (colors[i] == 5) {
                            *outx = (s16)hx;
                            *outy = (s32)yy + (s32)((f32)b->h10 * 0.5f - 0.5f);
                        }
                        ((void (*)(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32))func_0038E7E8)(x, yy, D_001D7120_sda[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                    } else {
                        if (fl & 1) {
                            ((void (*)(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32))func_0038E7E8)((f32)(b->h8 - (wpx >> 1)), (f32)y, D_001D7120_sda[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        } else {
                            ((void (*)(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32))func_0038E7E8)((f32)b->h8, (f32)y, D_001D7120_sda[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
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
    D_001D7119_sda = 0;
    if (D_L39_00241128 != 1 && !(b->h12 & 0x10)) {
        func_003A9500(0, D_L39_00240300 - 1, 0, D_L39_00240304 - 1);
    }
}
/* localdecomp:end func_L39_00593E40 */
