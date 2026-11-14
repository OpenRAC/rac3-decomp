#include "common.h"

/* NTSC-U counterpart of func_L39_00593468 (src/levels/shared/L39_00593468.c) */
/* localdecomp:start func_L39_005921C0 */
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

extern s32 func_003898C0(u8 *p, s32 off, s32 *out);
extern s32 func_00389D18(u8 *, s32, f32);
extern void func_00389FB8(f32 x, f32 y, s32 a, s32 b, s32 c, f32 sx, f32 sy, s32 d, s32 e, f32 f, f32 g, unsigned long h);
extern void func_003A3FB0(s32, s32, s32, s32);

extern s32 D_L39_002412A8;
extern s32 D_L39_00240480, D_L39_00240484, D_L39_00240488, D_L39_0024048C;
__asm__(".extern D_L39_00240480, 16");
__asm__(".extern D_L39_00240484, 16");
__asm__(".extern D_L39_00240488, 16");
__asm__(".extern D_L39_0024048C, 16");
extern s32 D_L39_002415CC;
__asm__(".extern D_L39_002415CC, 16");
extern u8 *D_L39_002415D0;
__asm__(".extern D_L39_002415D0, 16");
extern s32 D_L39_0024BBA0;
extern s16 D_L39_0024BBA8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BBA8, 24");
extern s16 D_L39_0024BBC0_005921C0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BBC0_005921C0, 24");
extern s16 D_L39_0024BBD8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BBD8, 24");
extern s16 D_L39_0024BBF0[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BBF0, 24");
extern u8 D_001D7118_sda_005921C0;
__asm__(".extern D_001D7118_sda_005921C0, 1");
extern u8 D_001D7119_sda_005921C0;
__asm__(".extern D_001D7119_sda_005921C0, 1");
extern u8 D_001D711A_sda_005921C0;
__asm__(".extern D_001D711A_sda_005921C0, 1");
extern s32 D_001D7120_sda_005921C0[] __attribute__((section(".sdata")));
__asm__(".extern D_001D7120_sda_005921C0, 4");
extern s32 D_001D7140_sda_005921C0;
__asm__(".extern D_001D7140_sda_005921C0, 4");

void func_L39_005921C0(void *arg, f32 sx, f32 sy, long color, char *text, s32 len, unsigned long arg6) {
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
    if (D_L39_002412A8 != 1 && !(s->flags & 0x10)) {
        s32 a = (s32)((f32)D_L39_00240488 - (f32)D_L39_00240480 * 0.5f);
        s32 b = (s32)((f32)D_L39_0024048C - (f32)D_L39_00240484 * 0.5f);
        func_003A3FB0(s->left + a, s->right - 1 + a, s->top + b, s->bottom - 1 + b);
    }
    D_001D7119_sda_005921C0 = 1;
    if ((u8)(s->flags ^ 1) & 1) {
        width = s->right - s->x;
    } else {
        s32 r = s->right - s->x;
        s32 l = s->x - s->left;
        if (r < l) l = r;
        width = l * 2;
    }
    nlines = 0;
    col = 0;
    fitted = 0;
    tried = 0;
    width0 = width;
    lastx = 0.0f;
    while (D_001D7140_sda_005921C0 != 2) {
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
                    if (D_001D711A_sda_005921C0 != 0 && (u8)(str[i] - 8) < 8) col = str[i] - 8;
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
                        i += func_003898C0(str, i, &idx);
                        e = (G_00593468 *)(idx * 8 + D_L39_002415CC);
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
                                func_003898C0(str, i + 1, &idx2);
                                nx = idx2;
                                if (nx != 0) {
                                    x += adv + kern;
                                    if (e->w0 & 0xFFF0) {
                                        K_00593468 *kp = (K_00593468 *)(D_L39_002415D0 + ((e->w0 >> 2) & 0x3FFC));
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
                if (D_001D711A_sda_005921C0 != 0 && (f32)width <= x) {
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
    if (D_001D7140_sda_005921C0 != 0) {
        if (D_001D7140_sda_005921C0 == 1) {
            D_L39_0024BBA0 = nlines;
            for (j = 0; j < nlines && j < 12; j++) {
                D_L39_0024BBA8[j] = starts[j];
                D_L39_0024BBC0_005921C0[j] = ends[j];
                D_L39_0024BBD8[j] = colors[j];
            }
        } else {
            nlines = D_L39_0024BBA0;
            for (m = 0; m < nlines && m < 12; m++) {
                starts[m] = D_L39_0024BBA8[m];
                ends[m] = D_L39_0024BBC0_005921C0[m];
                colors[m] = D_L39_0024BBD8[m];
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
        if (D_001D7140_sda_005921C0 != 2) w = func_00389D18(str + starts[k], n, sx);
        if (D_001D7140_sda_005921C0 != 0) {
            if (D_001D7140_sda_005921C0 == 1) {
                D_L39_0024BBF0[k] = w;
            } else {
                w = D_L39_0024BBF0[k];
            }
        }
        if (s->maxw < w) s->maxw = w;
        if (!(s->flags & 4)) {
            f32 fx;
            f32 fy;
            u16 fl;
            u8 saved;
            D_001D7120_sda_005921C0[0] = color;
            fy = (f32)y;
            fl = s->flags;
            fx = (f32)s->x;
            if (fl & 1) fx -= (f32)(w >> 1);
            saved = D_001D7118_sda_005921C0;
            if (fl & 8) {
                fx += (f32)s->dx * 0.0625f;
                fy += (f32)s->dy * 0.0625f;
                D_001D7118_sda_005921C0 = 0;
            }
            func_00389FB8(fx, fy, D_001D7120_sda_005921C0[colors[k]], (s32)(str + starts[k]), n, sx, sy, 0, (s->flags >> 5) & 1,
                          (f32)s->f18, (f32)s->f1A, arg6);
            D_001D7118_sda_005921C0 = saved;
        }
        if (len > 0) {
            len -= n;
            if (len <= 0) break;
        }
    }
    D_001D7119_sda_005921C0 = 0;
    if (D_L39_002412A8 != 1 && !(s->flags & 0x10)) {
        func_003A3FB0(0, D_L39_00240480 - 1, 0, D_L39_00240484 - 1);
    }
    D_001D7140_sda_005921C0 = 0;
}
/* localdecomp:end func_L39_005921C0 */
