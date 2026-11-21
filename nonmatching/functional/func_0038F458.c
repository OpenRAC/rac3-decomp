/* functional: high. Written from the PAL assembly; 577 words differ (regalloc/scheduling/frame). Four-corner-colour sibling of func_0038EBC8: like retail it rewrites the caller's colors[4] (64-bit RGBAQ) per glyph, and an optional drop shadow (shade[4] = shadow_color, offset dx,dy) is drawn first with func_0038BC30. Prototype inferred from register use (a0 colors, a1 str, a2 len, a3 align, t0 shadow, t1 shadow_color, f12-f17 x,y,sx,sy,dx,dy); no matched caller. Uses 38E7A0.c context. */
typedef int Q_0038F458 __attribute__((mode(TI)));
extern u8 D_001D5B40, D_001D5B41;
extern s32 D_001D5B48[];
extern s32 *D_001D5B38;
extern s32 *D_001D5B3C;
extern u8 *D_001D55C0;
extern u8 *D_001DA050;
extern Q_0038F458 D_001D77E0;
extern void func_0038E2B0(void);
extern void func_003A97F8(s32, unsigned long);
extern unsigned long func_0038A0E0(s32, s32, s32, s32, s32);
extern s32 func_0038BC30(s32 u, s32 v, s32 w, s32 h, long *c, long t1, s32 flag, f32 x, f32 y, f32 fw, f32 fh);

/* colors: four 64-bit corner colours (RGBAQ), rewritten per glyph like retail does */
void func_0038F458(f32 x, f32 y, f32 sx, f32 sy, long *colors, u8 *str, s32 len, s32 align,
                   s32 shadow, long shadow_color, f32 dx, f32 dy) {
    E_389B98 *e;
    K_389D18 *k;
    u32 *pkt;
    s32 base[4];
    long shade[4];
    unsigned long tex;
    f32 qx, qy, kern, gw, gh, bear, adv, yoff, px, py;
    s32 idx, nx, ok, first, page, snap, i, j, count, r, a, c, v, w, h, rgb;
    u8 *tbl;

    qy = sy * 0.25f;
    qx = sx * 0.25f;
    base[0] = (s32)colors[0];
    base[1] = (s32)colors[1];
    base[2] = (s32)colors[2];
    base[3] = (s32)colors[3];
    snap = 0;
    ok = 1;
    first = 1;
    page = -1;
    tex = 0;
    kern = 0.0f;
    shade[0] = shadow_color;
    shade[1] = shadow_color;
    shade[2] = shadow_color;
    shade[3] = shadow_color;
    if (sx == 1.0f && sy == 1.0f) {
        snap = D_001D5B40 != 0;
    }
    func_0038E2B0();
    func_003A97F8(0x47, 0x33001);
    if (D_001D5B41 == 0) D_001D5B48[0] = (s32)colors[0];
    switch (align) {
    case 1:
        x -= (f32)(func_0038E928(str, len, sx) >> 1);
        break;
    case 2:
        x -= (f32)func_0038E928(str, len, sx);
        break;
    case 3:
        y -= (f32)(func_0038E7A8(str, len, sy) >> 1);
        break;
    case 4:
        w = func_0038E928(str, len, sx);
        h = func_0038E7A8(str, len, sy);
        x -= (f32)(w >> 1);
        y -= (f32)(h >> 1);
        break;
    case 5:
        w = func_0038E928(str, len, sx);
        h = func_0038E7A8(str, len, sy);
        x -= (f32)w;
        y -= (f32)(h >> 1);
        break;
    case 6:
        y -= (f32)func_0038E7A8(str, len, sy);
        break;
    case 7:
        w = func_0038E928(str, len, sx);
        h = func_0038E7A8(str, len, sy);
        y -= (f32)h;
        x -= (f32)(w >> 1);
        break;
    case 8:
        w = func_0038E928(str, len, sx);
        h = func_0038E7A8(str, len, sy);
        x -= (f32)w;
        y -= (f32)h;
        break;
    }

    pkt = (u32 *)D_001DA050;
    count = 0;
    D_001DA050 = (u8 *)pkt + 0x20;
    for (i = 0; ok && i != len; i++) {
        c = str[i];
        if (c == 0) {
            ok = 0;
            continue;
        }
        if ((u32)(c - 8) < 8) {
            /* colour escape 8..15: keep each corner's alpha, take RGB from the palette */
            if (D_001D5B42 != 0) {
                rgb = D_001D5B48[c - 8] & 0xFFFFFF;
                for (j = 0; j < 4; j++)
                    base[j] = (s32)(colors[j] & 0xFF000000) | rgb;
            }
            continue;
        }
        if (c == 0x20) {
            e = &((E_389B98 *)D_001D55C4[0])[0x20];
            bear = (f32)(s32)(((e->w4 >> 29) + 2) & 0xFC) * qx;
            kern = 0.0f;
            x += bear + (f32)(s32)((e->w4 >> 23) & 0x3F) * sx;
            continue;
        }
        i += func_0038E488(str, i, &idx);
        e = &((E_389B98 *)D_001D55C4[0])[idx];
        if ((e->w4 & 0x1F800000) == 0) continue;
        if (idx < 0x20) {
            /* icon glyphs: fixed grey, alpha from the text colour */
            for (j = 0; j < 4; j++) {
                a = (u32)base[j] >> 24;
                if (a > 0x40)
                    colors[j] = 0x80C0C0C0UL;
                else if (a <= 0x20)
                    colors[j] = (unsigned long)(u32)(((u32)base[j] & 0xFF000000) | 0xC0C0C0);
                else
                    colors[j] = (long)(s32)(((((a - 0x20) * 3) + 0x20) << 24) | 0xC0C0C0);
            }
        } else {
            for (j = 0; j < 4; j++)
                colors[j] = base[j];
        }
        if ((s32)(e->w0 & 0xF) != page) {
            s32 b0, b1;
            page = e->w0 & 0xF;
            tbl = D_001D55C0;
            b0 = tbl[0x10 + page * 2];
            b1 = tbl[0x11 + page * 2];
            tex = func_0038A0E0(D_001D5B38[b0], D_001D5B3C[b1], *(s16 *)(tbl + 0x50 + b0 * 4),
                                *(s16 *)(tbl + 0x52 + b0 * 4), tbl[0x40 + b0] == 0x14 ? 0x14 : 0x13);
        }
        gw = (f32)(s32)((e->w4 >> 23) & 0x3F) * sx;
        gh = (f32)(s32)((e->w4 >> 17) & 0x3F) * sy;
        bear = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * qx;
        adv = (kern + (f32)(s32)(((e->w4 >> 29) + 2) & 0xFC)) * qx + (f32)(s32)((e->w4 >> 23) & 0x3F) * sx;
        v = (e->w4 >> 9) & 0xFF;
        if (v < 0x80)
            yoff = (f32)v * qy;
        else
            yoff = ((f32)v - 256.0f) * qy;
        if (first)
            first = 0;
        else
            x -= bear;
        px = x + kern;
        py = y + yoff;
        if (idx >= 0x21 && shadow != 0) {
            r = func_0038BC30((e->w0 >> 16) & 0x1FF, e->w4 & 0x1FF, (e->w4 >> 23) & 0x3F, (e->w4 >> 17) & 0x3F,
                              shade, tex, snap, px + dx, py + dy, gw, gh);
            if (r) count++;
        }
        x += adv;
        r = func_0038BC30((e->w0 >> 16) & 0x1FF, e->w4 & 0x1FF, (e->w4 >> 23) & 0x3F, (e->w4 >> 17) & 0x3F,
                          colors, tex, snap, px, py, gw, gh);
        kern = 0.0f;
        if (r) count++;
        if ((e->w0 & 0xFFF0) == 0) continue;
        if (i == len) continue;
        func_0038E488(str, i + 1, &nx);
        if (nx == 0) continue;
        k = (K_389D18 *)((u8 *)D_001D55C8 + ((e->w0 >> 2) & 0x3FFC));
        r = 0;
        if (k != 0) {
            for (; k->end == 0; k++) {
                if (k->ch == nx) {
                    r = k->adj;
                    break;
                }
            }
        }
        kern = (f32)r * qx;
    }

    if (count != 0) {
        v = count * 8 + 1;
        pkt[3] = v | 0x50000000;
        pkt[0] = v | 0x10000000;
        pkt[1] = 0;
        pkt[2] = 0;
        *(Q_0038F458 *)(pkt + 4) = D_001D77E0;
        pkt[4] = count | 0x8000;
        func_003A97F8(8, 5);
    } else {
        D_001DA050 -= 0x20;
    }
}
