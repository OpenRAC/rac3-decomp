/* func_0038FA18 (PAL frontbin, src/frontbin/38E0A8.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division -mno-split-addresses @ps2as), ported from boot_elf's func_0038FDF8
   (src/boot_elf/text/38FDF8.c). MATCH with split addresses (tools/check.py --mode S), as 38FDF8.c
   has; 244 diff with this file's -mno-split-addresses. 38E0A8.c as a whole cannot take split
   addresses (the frontbin build grows by 24 bytes, NO MATCH; tested 2026-11-21).
   The cut it needs: a file at 0x38FA18 without -mno-split-addresses (`-mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division @ps2as`), and one at 0x390388 (func_00390388 onwards) with
   38E0A8.c's present flag line. That cut moves the markers of another contributor's claimed
   functions (func_00391328, func_003914A0, func_00391678, func_00392260) into the new file at
   0x390388, so it is not made.
   The NTSC-U twin (func_0038B1E8) has other bytes (266 diff; config/us/map.tsv: differs). */
/* localdecomp:start func_0038FA18 */
/* from the NTSC decomp's func_0038FD40 */
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 fl; s16 h14, h16, h18, h1A; } O_0038FDF8;
typedef struct { s16 key; s8 val; u8 end; } K_0038FDF8;
typedef struct { u32 w0, w4; } G_0038FDF8;
/* Ps2EeAs uses $gp for these only if it knows their size before the first use. */
__asm__(".extern D_001D5B40, 1");
__asm__(".extern D_001D5B41, 1");
__asm__(".extern D_001D5B42, 1");
__asm__(".extern D_001D5B48, 8");
__asm__(".extern D_001D5B68, 4");
__asm__(".extern D_001D5B6C, 1");
extern s32 D_001D5B94;
extern u8 D_001D5B40, D_001D5B41, D_001D5B42, D_001D5B6C;
extern s32 D_001D5B48[2];
extern s32 D_001D5B68;
extern s32 D_001D9C80;
extern u16 D_001D9C88_0038FA18[12] __attribute__((section(".sdata")));
extern u16 D_001D9CA0_0038FA18[12] __attribute__((section(".sdata")));
extern u16 D_001D9CB8_0038FA18[12] __attribute__((section(".sdata")));
extern s16 D_001D9CD0_0038FA18[12] __attribute__((section(".sdata")));
extern G_0038FDF8 *D_001D55C4_0038FA18;
extern s32 D_001D55C8;
extern s32 D_001D4BC0_0038FA18, D_001D4BC4_0038FA18;
extern s32 func_0038E0A8(u8 *p, s32 off, s32 *out);
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0038E548(u8 *str, s32 len, f32 scale);
extern void func_0038E7E8_0038FA18(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
static __inline__ s32 kern_0038FDF8(K_0038FDF8 *k, s32 c) {
    if (k != 0) {
        for (; k->end == 0; k++) {
            if (k->key == c) return k->val;
        }
    }
    return 0;
}
void func_0038FA18(s32 box, long color, s32 str, s32 len, unsigned long flags64, s32 a5, f32 scale, f32 scale2) {
    O_0038FDF8 *o = (O_0038FDF8 *)box;
    u8 *text = (u8 *)str;
    s16 st[0x50], en[0x50], sty[0x50];
    s32 code, ncode;
    s32 keep, squeezed, w_full, next;
    s32 lines, pos, w;
    s32 brk;
    u8 first, cont, retry;
    s32 style, ln;
    f32 last_x, adv, adv_k, x, kern, q;
    first = 1;
    q = scale * 0.25f;
    kern = 0.0f;
    code = 0;
    if (D_001D5B94 != 1 && !(o->fl & 0x10)) func_003A9500(o->h4, o->h6 - 1, o->h0, o->h2 + 3);
    D_001D5B41 = 1;
    if (((u8)o->fl ^ 1) & 1) {
        w = o->h6 - o->h8;
    } else {
        s32 right = o->h6 - o->h8;
        s32 left = o->h8 - o->h4;
        if (right < left) left = right;
        w = left * 2;
    }
    lines = 0;
    style = 0;
    keep = D_001D5B6C;
    squeezed = 0;
    last_x = 0.0f;
    w_full = w;
    if (D_001D5B68 != 2) {
        do {
            lines = 0;
            cont = 1;
            first = 1;
            pos = 0;
            while (cont != 0 && pos != len) {
                if (text[pos] == 0 || lines >= 0x4F) {
                    cont = 0;
                } else {
                    s32 go;
                    x = 0.0f;
                    ln = lines;
                    st[ln] = pos;
                    next = lines + 1;
                    sty[ln] = style;
                    brk = pos;
                    go = 1;
                    while (go != 0 && x < (f32)w) {
                        if (text[pos] == 0x20 || text[pos] < 0x10) brk = pos;
                        if (D_001D5B42 != 0 && (u8)(text[pos] - 8) < 8) style = text[pos] - 8;
                        if (text[pos] == 0) {
                            cont = 0;
                            go = 0;
                            pos--;
                        } else if (text[pos] == 1) {
                            go = 0;
                            pos--;
                        } else {
                            G_0038FDF8 *g;
                            pos += func_0038E0A8(text, pos, &code);
                            g = (G_0038FDF8 *)((code << 3) + (s32)D_001D55C4_0038FA18);
                            if (g->w4 & 0x1F800000) {
                                f32 lead = (f32)(s32)(((g->w0 >> 25) + 2) & 0xFC) * q;
                                adv_k = (kern + (f32)(((g->w4 >> 29) + 2) & 0xFC)) * q + (f32)((g->w4 >> 23) & 0x3F) * scale;
                                adv = (f32)((g->w4 >> 23) & 0x3F) * scale;
                                if (first) first = 0;
                                else x -= lead;
                                if (pos != len && (func_0038E0A8(text, pos + 1, &ncode), ncode != 0)) {
                                    u32 e0 = g->w0;
                                    x += adv_k + kern;
                                    if (e0 & 0xFFF0) {
                                        K_0038FDF8 *k = (K_0038FDF8 *)((u8 *)D_001D55C8 + ((e0 >> 2) & 0x3FFC));
                                        kern = (f32)kern_0038FDF8(k, ncode);
                                        kern *= q;
                                    } else {
                                        kern = 0.0f;
                                    }
                                } else {
                                    x += adv;
                                }
                            }
                        }
                        pos++;
                    }
                    if (D_001D5B42 != 0 && (f32)w <= x) {
                        if (code >= 8) { if (code <= 15) style = code - 8; }
                    }
                    en[ln] = brk;
                    if ((s16)brk == st[ln]) {
                        if (x < (f32)w) en[ln] = pos;
                        else if ((s16)brk + 1 < pos) en[ln] = pos - 2;
                        else if ((s16)brk < pos) en[ln] = pos - 1;
                        else en[ln] = pos;
                    }
                    pos = en[ln];
                    if (text[pos] == 0x20 || text[pos] < 0x10) en[ln]--;
                    lines = next;
                    last_x = x;
                }
                pos++;
            }
            retry = 0;
            if (keep == 0 && lines >= 2) {
                if (squeezed == 0) {
                    f32 quarter = (f32)(w >> 2);
                    if (last_x < quarter) {
                        squeezed = lines;
                        retry = 1;
                        w = w - (w - (s32)last_x) / (lines + 1);
                    }
                } else if (squeezed < lines) {
                    retry = 1;
                    w = w_full;
                    keep = 1;
                }
            }
            if (retry == 0) break;
            if (D_001D5B68 == 2) break;
        } while (1);
    }
    if (D_001D5B68 != 0) {
        if (D_001D5B68 == 1) {
            s32 i;
            D_001D9C80 = lines;
            for (i = 0; i < lines && i < 12; i++) {
                D_001D9C88_0038FA18[i] = st[i];
                D_001D9CA0_0038FA18[i] = en[i];
                D_001D9CB8_0038FA18[i] = sty[i];
            }
        } else {
            s32 i;
            lines = D_001D9C80;
            for (i = 0; i < lines && i < 12; i++) {
                st[i] = D_001D9C88_0038FA18[i];
                en[i] = D_001D9CA0_0038FA18[i];
                sty[i] = D_001D9CB8_0038FA18[i];
            }
        }
    }
    {
        s32 i, n, lw, y;
        o->hC = 0;
        y = o->hA;
        o->hE = lines * o->h10;
        if (o->fl & 2) y -= (s16)o->hE >> 1;
        for (i = 0; i < lines; i++, y += o->h10) {
            if (y + o->h10 < o->h0) continue;
            if (o->h2 < y) break;
            n = en[i] - st[i] + 1;
            if (len > 0 && len < n) n = len;
            lw = 0;
            if (D_001D5B68 != 2) lw = func_0038E548(text + st[i], n, scale);
            if (D_001D5B68 != 0) {
                if (D_001D5B68 == 1) D_001D9CD0_0038FA18[i] = lw;
                else lw = D_001D9CD0_0038FA18[i];
            }
            if (o->hC < lw) o->hC = lw;
            if (!(o->fl & 4)) {
                f32 fx, fy;
                u8 save;
                D_001D5B48[0] = (s32)color;
                fy = (f32)y;
                fx = (f32)o->h8;
                if (o->fl & 1) fx -= (f32)(lw >> 1);
                save = D_001D5B40;
                if (o->fl & 8) {
                    fx += (f32)o->h14 * 0.0625f;
                    fy += (f32)o->h16 * 0.0625f;
                    D_001D5B40 = 0;
                }
                func_0038E7E8_0038FA18(fx, fy, D_001D5B48[sty[i]], text + st[i], n, scale, scale2, 0, (o->fl >> 5) & 1, flags64, (f32)o->h18, (f32)o->h1A);
                D_001D5B40 = save;
            }
            if (len > 0) {
                len -= n;
                if (len <= 0) break;
            }
        }
    }
    D_001D5B41 = 0;
    if (D_001D5B94 != 1 && !(o->fl & 0x10)) func_003A9500(0, D_001D4BC0_0038FA18 - 1, 0, D_001D4BC4_0038FA18 - 1);
    D_001D5B68 = 0;
}
/* localdecomp:end func_0038FA18 */
