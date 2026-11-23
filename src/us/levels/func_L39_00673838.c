#include "common.h"

/* NTSC-U counterpart of func_L39_006761D0 (src/levels/shared/L39_00675908.c) */
typedef struct S_00675830 {
    u8 pad0[0x48];
    s16 h48;
    s16 h4A;
    u8 pad4C[0xC];
    s32 w58;
    s32 w5C;
    u8 pad60[0x10];
    s32 w70;
    s32 w74;
    s32 w78;
    u8 pad7C[0x14];
} S_00675830;
extern S_00675830 D_L39_00498BD0[];
extern u8 *func_L39_006197C0(s32);
#include "vu0.h"
typedef struct S_E_00675908 {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} S_E_00675908;
extern S_E_00675908 D_L39_00484160[];
extern s32 D_L39_0024BE40;
extern S_E_00675908 **D_L39_0024BE48[] __attribute__((section(".sdata")));
extern s32 D_L39_00246680_00673838[2];
typedef struct Rooms_00675908 {
    u8 pad0[0x18A0];
    u8 arr[4][0xB50];
} Rooms_00675908;
typedef struct World_00675908 {
    u8 pad0[0x1FCA8];
    Rooms_00675908 rooms;
} World_00675908;
extern World_00675908 *D_L39_00242BD0;
extern s32 func_L39_00674788(s32);

/* localdecomp:start func_L39_00673838 */
typedef struct {
    u8 pad0[0x50];
    s32 x50;
    s32 x54;
    s32 x58;
    u8 pad5C[0x14];
    u8 st[2];
    u8 pad72[2];
    s32 sel;
    u8 pad78[0x90 - 0x78];
} S_006761D0;

typedef struct {
    u8 pad0[2];
    s16 msg;
    u8 pad4[4];
    u8 b8;
    u8 pad9[0x1E - 9];
    s16 h1E;
    u8 pad20;
    s8 alt;
    u8 pad22[0x80 - 0x22];
} E80_006761D0;

typedef struct {
    u8 pad0[0x24DA4];
    s32 w24DA4;
} G_006761D0;

extern s32 D_L39_00241298_00673838;
extern s32 *D_L39_002412A0;
extern E80_006761D0 D_L39_0049C950[];
extern u8 D_L39_00483AC0[];
extern u8 D_L39_0049C400[];
extern char D_L39_002466C0_00673838[];
extern s32 D_L39_002466E4_00673838;
extern s32 D_L39_002466E8_00673838;
extern s32 D_L39_002466EC;
extern s32 D_L39_002466F4;
extern s32 D_L39_002466F8;
extern s32 D_L39_002466FC;
extern s32 D_L39_002466AC;
extern s32 D_L39_002466B0;
extern s32 D_L39_002466B4_00673838;
extern s32 D_L39_002466B8_00673838;
extern s32 D_L39_002466C4_00673838;
extern s32 D_L39_002466C8_00673838;
extern s32 D_L39_002466CC_00673838;
extern s32 D_L39_002466D0_00673838;
extern s32 D_L39_002466D4_00673838;
extern s32 D_L39_002466D8_00673838;
extern s32 D_L39_002466E0;
extern s32 D_L39_002466F0;
extern s32 D_L39_00246700;
extern f32 D_L39_00246704;
extern s32 D_L39_00246708;
extern f32 D_L39_0024670C;
extern s32 D_L39_00246710;
extern s32 D_L39_00246714;
__asm__(".extern D_L39_00246680_00673838, 8");
__asm__(".extern D_L39_00242BD0, 4");
__asm__(".extern D_L39_002412A0, 16");
__asm__(".extern D_L39_002466E4_00673838, 16");
__asm__(".extern D_L39_002466E8_00673838, 16");
__asm__(".extern D_L39_002466EC, 16");
__asm__(".extern D_L39_002466F4, 16");
__asm__(".extern D_L39_002466F8, 16");
__asm__(".extern D_L39_002466FC, 16");
__asm__(".extern D_L39_002466AC, 4");
__asm__(".extern D_L39_002466B0, 4");
__asm__(".extern D_L39_002466B4_00673838, 4");
__asm__(".extern D_L39_002466B8_00673838, 4");
__asm__(".extern D_L39_002466C4_00673838, 4");
__asm__(".extern D_L39_002466C8_00673838, 4");
__asm__(".extern D_L39_002466CC_00673838, 4");
__asm__(".extern D_L39_002466D0_00673838, 4");
__asm__(".extern D_L39_002466D4_00673838, 4");
__asm__(".extern D_L39_002466D8_00673838, 4");
__asm__(".extern D_L39_002466E0, 4");
__asm__(".extern D_L39_002466F0, 4");
__asm__(".extern D_L39_00246700, 4");
__asm__(".extern D_L39_00246704, 4");
__asm__(".extern D_L39_00246708, 4");
__asm__(".extern D_L39_0024670C, 4");
__asm__(".extern D_L39_00246710, 4");
__asm__(".extern D_L39_00246714, 4");

extern s32 func_0038EDE8(void *, s32 *, s32 *);
extern f32 func_00389380(f32, f32);
extern void func_003A9698(u8 *, s32, f32);
extern s32 func_L39_00646268(u8 *, s32);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_00120884(char *);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_0037DF98(s32);
extern void func_L01_005103A8_00673838(void);
extern void func_L01_00410098(void);
extern void func_0038CA08(s32, s32, unsigned long, char *, s32, s32, f32);
extern void func_003867F8(s32, s32, s32, s32, unsigned long);

/* v advanced by the layout's step for the player count: one player, two, three or four */
static __inline__ s32 bymode_006761D0(s32 v, s32 one, s32 two, s32 more) {
    if (*D_L39_002412A0 >= 2) {
        if (*D_L39_002412A0 >= 3) {
            return v + more;
        }
        return v + two;
    }
    return v + one;
}

/* the entry an item id stands for: its alternative when the flag bit for it is set */
static __inline__ E80_006761D0 *item_006761D0(u8 *s, s32 id) {
    if (func_L39_00646268(s, id)) {
        return &D_L39_0049C950[D_L39_0049C950[id].alt];
    }
    return &D_L39_0049C950[id];
}

s32 func_L39_00673838(S_006761D0 *self) {
    s32 idx = (S_00675830 *)self - D_L39_00498BD0 - 8;
    u8 *s2 = func_L39_006197C0(idx);
    char buf[80];
    u32 hb[2];
    s32 px, py;
    s32 w;
    s32 tx, ty;
    u32 alpha, alpha2;
    s32 col;
    s32 col2, ok;
    E80_006761D0 *e;
    s32 i, sel, id, split, wrap, y;
    s32 y1, y2, x1, x2;
    s32 cnt, cur, sh;
    char *str;
    u8 *q;
    f32 a, b, scale;
    u8 *st;

    if (idx != D_L39_00241298_00673838) {
        return self->x58;
    }
    st = self->st;
    a = (f32)st[0] * 0.125f;
    if (a > 1.0f) {
        a = 1.0f;
    } else if (a < 0.0f) {
        a = 0.0f;
    }
    b = (f32)st[1] * 0.125f;
    if (b > 1.0f) {
        b = 1.0f;
    } else if (b < 0.0f) {
        b = 0.0f;
    }
    px = self->x50;
    py = self->x54;
    w = (s32)(a * 128.0f);
    func_0038EDE8(self, &px, &py);
    for (i = 0; i < D_L39_0024BE40; i++) {
        f32 fi = (f32)i;
        func_00389380((fi + fi) * 3.1415927f / (f32)D_L39_0024BE40 - 3.1415927f, 1.5707964f);
        if (self->sel == i) {
            if (D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][i].w0 != 0 && D_L39_00242BD0 != 0) {
                f32 f = fi;
                if (f > 7.0f) {
                    f -= 8.0f;
                }
                {
                    Rooms_00675908 *rooms = &D_L39_00242BD0->rooms;
                    func_003A9698(rooms->arr[idx], 1, f);
                }
            }
        }
        if (D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][i].w0 != 0 && D_L39_00242BD0 != 0) {
            ((G_006761D0 *)D_L39_00242BD0)->w24DA4 = func_L39_00674788(idx) ? (s32)((f32)w * 0.5f) : 0;
        }
    }
    tx = 0;
    ty = 0;
    if (*D_L39_002412A0 >= 2) {
        if (*D_L39_002412A0 >= 3) {
            tx = D_L39_002466B4_00673838;
            ty = D_L39_002466B8_00673838;
        } else {
            tx = D_L39_002466AC;
            ty = D_L39_002466B0;
        }
    }
    sel = self->sel;
    if (sel >= 0) {
        if (D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][sel].w0 != 0) {
            if (D_L39_00484160[*(s32 *)(s2 + 0x2544)].w0 == 0) {
                id = D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][sel].w18;
                ok = 1;
                switch (id) {
                case -1:
                case -2:
                case -3:
                case -4:
                    ok = 0;
                    break;
                }
                if (ok && id > 0) {
                    e = &D_L39_0049C950[id];
                    if ((e->b8 != 0 || id == 12) && e->h1E != 0) {
                        u16 hx;
                        u8 *p;
                        u8 *kp;
                        u32 n, m, base, t, aa, bb, qq;
                        p = (u8 *)(id + (u32)s2);
                        p += 0x1A52;
                        kp = p;
                        if (*kp == 0) {
                            hx = 0;
                        } else {
                            u8 *dst;
                            s32 j;
                            n = *kp;
                            m = n + 1;
                            base = ((u32)kp - n) & 7;
                            dst = (u8 *)hb;
                            j = 0;
                            do {
                                t = (base + j) & 7;
                                j += 3;
                                *dst++ = D_L39_00483AC0[t * 209 + m];
                            } while (j < 24);
                            aa = hb[0] ^ (u32)kp;
                            bb = hb[1] ^ aa;
                            hb[0] = aa;
                            qq = (bb >> 16) / (((bb ^ (bb >> 16)) << 16) + 1);
                            hb[1] = qq;
                            hx = *(u16 *)(hb + 1);
                        }
                        cnt = (s16)hx;
                        cur = item_006761D0(s2, D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][sel].w18)->h1E;
                        func_00120048(buf, D_L39_002466C0_00673838, cnt);
                        if (cnt != 0) {
                            col = func_003894A0(0x8066CCFF, 0x8066CCFF, a * b);
                        } else {
                            col = func_003894A0(0x4040FF, 0x804040FF, a * b);
                        }
                        y1 = 0;
                        y2 = 0;
                        x1 = 0;
                        x2 = 0;
                        if (*D_L39_002412A0 >= 2) {
                            if (*D_L39_002412A0 >= 3) {
                                y1 = D_L39_002466CC_00673838;
                                y2 = D_L39_002466D0_00673838;
                                x1 = D_L39_002466D4_00673838;
                                x2 = D_L39_002466D8_00673838;
                            } else {
                                y1 = D_L39_002466C4_00673838;
                                y2 = D_L39_002466C8_00673838;
                            }
                        }
                        alpha = col & 0xFF000000;
                        if (*D_L39_002412A0 >= 3) {
                            s32 yy = y1 + 0x64;
                            s32 xx = x1 + 0x69;
                            s32 xx2;
                            s32 yy2;
                            func_0038CA08(px + xx, py + yy + 0x14, alpha & 0x80000000, buf, -1, 0x1E, 0.5f);
                            func_0038CA08(px + xx, py + yy + 0x12, col, buf, -1, 0x1E, 0.5f);
                            yy2 = y2 + 0x64;
                            xx2 = x2 + 0x69;
                            func_00120048(buf, D_L39_002466C0_00673838, cur);
                            func_0038CA08(px + xx2, py + yy2 + 0x26, alpha & 0x80000000, buf, -1, 0x1E, 0.5f);
                            func_0038CA08(px + xx2, py + yy2 + 0x24, col, buf, -1, 0x1E, 0.5f);
                            {
                                s32 r0 = D_L39_002466E4_00673838 + 0x86;
                                s32 r1 = D_L39_002466EC + 0x86;
                                s32 r2 = D_L39_002466E0 + 0x69;
                                s32 r3 = D_L39_002466E8_00673838 + 0x69;
                                func_003867F8(py + 2 + r0, py + 2 + r1, px + r2 + 2, px + r3 + 2, alpha & 0x80000000);
                            }
                            {
                                s32 r0 = D_L39_002466E4_00673838 + 0x86;
                                s32 r1 = D_L39_002466EC + 0x86;
                                s32 r2 = D_L39_002466E0 + 0x69;
                                s32 r3 = D_L39_002466E8_00673838 + 0x69;
                                func_003867F8(py + r0, py + r1, px + r2, px + r3, col);
                            }
                        }
                        if (D_L39_0049C950[D_L39_0024BE48[idx][0][sel].w18].b8 != 0) {
                            f32 frac;
                            s32 bit;
                            u16 hx2;
                            u8 *p2;
                            u8 *kp2;
                            u32 n, m, base, t, aa, bb, qq;
                            p2 = (u8 *)(D_L39_0024BE48[idx][0][sel].w18 + (u32)s2);
                            p2 += 0x1A62;
                            kp2 = p2;
                            if (*kp2 == 0) {
                                hx2 = 0;
                            } else {
                                u8 *dst;
                                s32 j;
                                n = *kp2;
                                m = n + 1;
                                base = ((u32)kp2 - n) & 7;
                                dst = (u8 *)hb;
                                j = 0;
                                do {
                                    t = (base + j) & 7;
                                    j += 3;
                                    *dst++ = D_L39_0049C400[m + t * 129];
                                } while (j < 24);
                                aa = hb[0] ^ (u32)kp2;
                                bb = hb[1] ^ aa;
                                hb[0] = aa;
                                qq = (bb >> 16) / (((bb ^ (bb >> 16)) << 16) + 1);
                                hb[1] = qq;
                                hx2 = *(u16 *)(hb + 1);
                            }
                            frac = (s16)hx2;
                            sh = D_L39_0024BE48[idx][0][sel].w18;
                            {
                                /* func_L39_00646268's body */
                                u8 *p3 = s2 + 0x1A41;
                                u16 hx3;
                                if (*p3 == 0) {
                                    hx3 = 0;
                                } else {
                                    u32 n = *p3, m, base, t, aa, bb, qq;
                                    u8 *dst;
                                    s32 j;
                                    m = n + 1;
                                    base = ((u32)p3 - n) & 7;
                                    dst = (u8 *)hb;
                                    j = 0;
                                    do {
                                        t = (base + j) & 7;
                                        j += 3;
                                        *dst++ = D_L39_00483AC0[t * 209 + m];
                                    } while (j < 24);
                                    aa = hb[0] ^ (u32)p3;
                                    bb = hb[1] ^ aa;
                                    hb[0] = aa;
                                    qq = (bb >> 16) / (((bb ^ (bb >> 16)) << 16) + 1);
                                    hb[1] = qq;
                                    hx3 = *(u16 *)(hb + 1);
                                }
                                bit = ((s16)hx3 >> sh) & 1;
                            }
                            if (bit) {
                                frac = 3.0f;
                            }
                            if (frac > 3.0f) {
                                frac = 3.0f;
                            }
                            {
                                s32 r0 = D_L39_002466F4 + 0x86;
                                s32 r1 = D_L39_002466FC + 0x86;
                                s32 r2 = D_L39_002466F0 + 0x69;
                                s32 r3 = D_L39_002466F8 + 0x69;
                                func_003867F8(py + r0, py + r1, px + r2, px + r3 + (s32)(frac / 3.0f * 92.0f), alpha | 0x6EC8FF);
                            }
                        }
                    }
                }
                col2 = func_003894A0(0x8066CCFF, 0x8066CCFF, a * b);
                split = 0;
                {
                    s32 named = 0;
                    s32 msg;
                    switch (D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][sel].w18) {
                    case -1:
                        msg = 0x1163;
                        break;
                    case -2:
                        msg = 0x1357;
                        named = 1;
                        break;
                    case -3:
                        msg = 0x1358;
                        named = 1;
                        break;
                    case -4:
                        msg = 0x1359;
                        named = 1;
                        break;
                    default:
                        msg = item_006761D0(s2, D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][sel].w18)->msg;
                        break;
                    }
                    str = (char *)func_0037DF98(msg);
                    if (str != 0 && func_00120884(str) != 0) {
                        {
                            s32 len;
                            s32 j;
                            q = str;
                            len = func_00120884(str);
                            for (j = 0; j < len; j++) {
                                q++;
                                if (*q == '-') {
                                    q++;
                                    split = j + 2;
                                    break;
                                }
                            }
                            if (split == 0) {
                                q = str;
                                for (j = split; j < len; j++) {
                                    q++;
                                    if (*q == ' ') {
                                        q++;
                                        split = j + 1;
                                        break;
                                    }
                                }
                            }
                        }
                        y = py + 0x64;
                        if (named == 0 &&
                            (D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][sel].w18 <= 0 ||
                             item_006761D0(s2, D_L39_0024BE48[idx][D_L39_00246680_00673838[idx]][sel].w18)->h1E == 0) &&
                            split != 0) {
                            do { y -= 0x19; } while (0);
                        } else {
                            y -= 0x23;
                        }
                        wrap = 0x50;
                        scale = 0.0f;
                        if (*D_L39_002412A0 >= 2) {
                            if (*D_L39_002412A0 >= 3) {
                                wrap = D_L39_00246700;
                                scale = D_L39_00246704;
                            } else {
                                wrap = D_L39_00246708;
                                scale = D_L39_0024670C;
                            }
                        }
                        alpha2 = col2 & 0xFF000000;
                        if (split != 0) {
                            {
                                s32 x = tx + 0x69;
                                func_L01_005103A8_00673838();
                                func_0038CA08(px + x + 2, y + ty + 2, (u32)(alpha2 & 0x80000000), str, split, wrap, scale);
                                func_L01_00410098();
                                func_0038CA08(px + x, y + ty, (unsigned long)col2, str, split, wrap, scale);
                            }
                            /* line height of the 1-, 2- and 3/4-player layouts */
                            y = bymode_006761D0(y, 0x10, 0xC, 0xC);
                            {
                                s32 x = tx + 0x69;
                                func_L01_005103A8_00673838();
                                func_0038CA08(px + x + 2, y + ty + 2, (u32)(alpha2 & 0x80000000), (char *)q, -1, wrap, scale);
                                func_L01_00410098();
                                func_0038CA08(px + x, y + ty, (unsigned long)col2, (char *)q, -1, wrap, scale);
                            }
                        } else {
                            s32 x;
                            s32 dy;
                            dy = 0xC;
                            if (*D_L39_002412A0 >= 2) {
                                if (*D_L39_002412A0 >= 3) {
                                    dy = D_L39_00246710;
                                } else {
                                    dy = D_L39_00246714;
                                }
                            }
                            func_L01_005103A8_00673838();
                            x = tx + 0x69;
                            func_0038CA08(px + x + 2, y + ty + dy + 2, (u32)(alpha2 & 0x80000000), str, -1, wrap, scale);
                            func_L01_00410098();
                            func_0038CA08(px + x, y + ty + dy, col2, str, -1, wrap, scale);
                        }
                    }
                }
            }
        }
    }
    return self->x58;
}
/* localdecomp:end func_L39_00673838 */
