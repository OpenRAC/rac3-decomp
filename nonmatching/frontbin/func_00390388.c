/* Near miss of func_00390388 with its file's own flags: tools/check.py reports 179 diff
   (the version it replaces: 510).
   What differs: 179 diffs (down from 509). Still differs in three places, all of them Ps2EeAs-
   vs-ee-as artefacts, not C-level ones: (1) the flag word at 0x001D5B94 - retail loads it with
   `lui $v1,0x1d / lw $v1,0x5b94($v1)` in the middle of the prologue (words 10-11); mine emits
   the same two words but the scheduler sinks them to just before the first branch (words
   22-23). Retail's early slot is gcc's single %gp-relative load expanded to lui/lw by the
   single-pass Ps2EeAs; bin/ee-as.exe has no such expansion, and gcc's 2-word constant-address
   form (`*(s32 *)0x001D5B94`, the wiki's "constant-address globals"...
*/

/* US draft of func_00390388 (rac3-uya-decomp func_0038BB50, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00390388 */
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
__asm__(".extern D_001D5B41, 1");
extern s32 D_001D5B48[2];
__asm__(".extern D_001D5B48, 8");
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0038E0A8(u8 *p, s32 off, s32 *out);
extern s32 func_0038E548_00390388(u8 *, s32, f32);
extern void func_0038E7E8_00390388(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_00390388(B_38BB50 *b, long ca, u8 **strs, s32 n, s16 sel, long cb, s32 *outx, s32 *outy, f32 scale) {
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

    if (*(s32 *)0x001D5B94 != 1 && !(b->h12 & 0x10)) {
        func_003A9500(b->h4, b->h6 - 1, b->h0, b->h2 - 1);
    }
    first = 1;
    D_001D5B41 = 1;
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
                    pos += func_0038E0A8(s, pos, &c1);
                    {
                        G_38BB50 *g = (G_38BB50 *)(c1 * 8 + *(u32 *)0x1D55C4);
                        if (g->w1 & 0x1F800000) {
                            f32 f = (f32)(s32)(((g->w0 >> 25) + 2) & 0xFC) * quarter;
                            if (first) first = 0;
                            else w -= f;
                            w += (f32)(((*(G_38BB50 **)0x1D55C4)[c1].w1 >> 23) & 0x3F) * scale;
                            func_0038E0A8(s, pos + 1, &c2);
                            if (c2 >= 0x10) {
                                w += (f32)((((*(G_38BB50 **)0x1D55C4)[c1].w1 >> 29) + 2) & 0xFC) * 0.25f * scale;
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
                wpx = func_0038E548_00390388(lines[i] + starts[i], len, 1.0f);
                if (b->hC < wpx) b->hC = wpx;
                if (!(b->h12 & 4)) {
                    u16 fl;
                    D_001D5B48[0] = ca;
                    D_001D5B5C[0] = cb;
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
                        func_0038E7E8_00390388(x, yy, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                    } else {
                        if (fl & 1) {
                            func_0038E7E8_00390388((f32)(b->h8 - (wpx >> 1)), (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        } else {
                            func_0038E7E8_00390388((f32)b->h8, (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
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
    if (*(s32 *)0x001D5B94 != 1 && !(b->h12 & 0x10)) {
        func_003A9500(0, D_001D4BC0[0] - 1, 0, D_001D4BC4[0] - 1);
    }
}
/* localdecomp:end func_00390388 */
