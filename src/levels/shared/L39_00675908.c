#include "common.h"

/* declared by functions of L39_00675830.c, which this file was cut from */
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
extern S_00675830 D_L39_00498B10[];
extern u8 D_L39_00246510[8];
extern u8 *func_L39_0061BF38(s32);
extern s32 func_L39_005C42E8(s32, s32);
extern void func_L39_00674F50(u8 *);

/* localdecomp:start func_L39_00675908 */
#include "vu0.h"

typedef struct S_Q_00675908 {
    u8 pad0[0x148];
    f32 f148;
    f32 f14C;
    u8 pad150[0x70];
    u32 w1C0;
    u32 w1C4;
    u8 pad1C8[4];
    s32 w1CC;
    u8 pad1D0[8];
    s32 w1D8;
} S_Q_00675908;

typedef struct S_S_00675908 {
    u8 pad0[0x19E6];
    u8 b19E6;
    u8 pad19E7[0x2A];
    u8 b1A11;
    u8 pad1A12[0xA92];
    u8 b24A4;
    u8 pad24A5[0x8F];
    S_Q_00675908 *q2534;
    u8 pad2538[0xC];
    s32 w2544;
} S_S_00675908;

typedef struct S_P_00675908 {
    u8 pad0[0x64];
    s32 w64;
    u8 pad68[4];
    s32 w6C;
    u8 b70;
    u8 b71;
    u8 pad72[2];
    s32 w74;
    union {
        s32 w;
        s8 b[4];
    } u78;
    s32 w7C;
    u8 pad80[0x10];
} S_P_00675908;

typedef struct S_E_00675908 {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} S_E_00675908;

extern S_E_00675908 D_L39_004840A0[];
extern u8 D_L39_004997E0[];
extern s32 D_L39_0024BD40;
extern S_E_00675908 **D_L39_0024BD48[] __attribute__((section(".sdata")));
extern S_E_00675908 D_L39_002464E0 __attribute__((section(".sdata")));
extern s32 D_L39_002410F8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CFD8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CFC8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CFB8[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B9C8;
extern u8 D_L39_00246510[8];
extern s32 D_L39_00246500[2];
extern f32 D_L39_00246528;
typedef struct Rooms_00675908 {
    u8 pad0[0x18A0];
    u8 arr[4][0xB50];
} Rooms_00675908;
typedef struct World_00675908 {
    u8 pad0[0x1FCA8];
    Rooms_00675908 rooms;
} World_00675908;
extern World_00675908 *D_L39_00242A50;
__asm__(".extern D_L39_00246510, 8");
__asm__(".extern D_L39_00246500, 8");
__asm__(".extern D_L39_00246528, 4");
__asm__(".extern D_L39_00242A50, 4");

extern s32 func_L39_005C42E8(s32, s32);
extern void func_L39_00677148(s32);
extern s32 func_L39_00677170(s32);
extern void func_L39_00677130(s32);
extern void func_L39_00677120(s32);
extern s32 func_L01_0040E020(void *);
extern void func_L39_00605AA8(u8 *, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_L39_005F3548(s32, s32, s32);
extern s32 func_003934B8(s32);
extern void func_L39_0063E3D0(void *, s32);

/* reads a byte value stored scrambled through the D_L39_004997E0 tables */
static __inline__ u32 decode_00675908(u8 *kp) {
    u8 buf[8];
    u8 b;
    s32 b1;
    s32 k;
    u8 *d;
    u32 base;

    if (*kp == 0) {
        return 0;
    }
    b = *kp;
    b1 = b + 1;
    d = buf;
    base = ((u32)kp - b) & 7;
    for (k = 0; k < 40; k += 5) {
        *d++ = D_L39_004997E0[b1 + ((base + k) & 7) * 255];
    }
    ((u32 *)buf)[0] ^= (u32)kp;
    ((u32 *)buf)[1] ^= ((u32 *)buf)[0];
    return ((u32 *)buf)[1];
}

void func_L39_00675908(S_P_00675908 *p) {
    s32 i = (S_00675830 *)p - D_L39_00498B10 - 8;
    S_S_00675908 *s = (S_S_00675908 *)func_L39_0061BF38(i);
    S_Q_00675908 *q;
    s32 flag = 0;
    s32 g;
    s32 h;
    s32 cur;
    f32 ang;
    f32 len;
    f32 x;
    f32 y;
    u8 *t;

    if (D_L39_004840A0[s->w2544].w0 != 0 || (decode_00675908(&s->b19E6) ^ 0x14) == 0) {
        flag = 1;
    }
    t = &p->b70;
    g = 1;
    func_L39_00677148(i);
    if (func_L39_00677170(i) == 0 || flag) g = 0;
    if (!flag && (s->q2534->w1C0 & (func_L39_005C42E8(8, s->w2544) | 2))) {
        if (D_L39_00246510[i] == 0) {
            D_L39_00246510[i] = 4;
            func_L39_00674F50((u8 *)s);
        }
    } else if (!flag && (s->q2534->w1C0 & 0x10)) {
        if (func_L01_0040E020(&D_L39_00246510[i])) {
            func_L39_00674F50((u8 *)s);
        }
    }
    if (g && D_L39_00242A50 != 0) {
        Rooms_00675908 *rooms = &D_L39_00242A50->rooms;
        func_L39_00605AA8(rooms->arr[i], 2);
    }
    p->w7C = 0x96;
    p->w6C = 0x18;
    if (!flag && func_0038CB00(&s->b24A4) != 0 && g) {
        s->q2534->w1CC = 2;
    }
    q = s->q2534;
    x = q->f148;
    y = q->f14C;
    len = sqrt_asm(x * x + y * y);
    if (len != 0.0f) {
        x /= len;
        y /= len;
    }
    ang = func_0038D160(x, y);
    if ((p->u78.w >> 24) == 0) {
        if ((s->q2534->w1C4 & 0xF000) || len < 0.5f || --p->u78.w == -1) {
            p->w74 = -1;
            p->u78.w = 0x10000FF;
        }
    }
    h = 0;
    cur = p->w74;
    if (p->u78.b[3] == 1 && (s->q2534->w1C0 & 0x10) && g) {
        q = s->q2534;
        if (len > 0.9f) {
            f32 pi = 3.1415927f;
            f32 n = (f32)D_L39_0024BD40;
            f32 a22 = ang + pi + pi + 1.5707964f + pi / n;
            f32 a20 = (f32)cur * 6.2831855f / n - pi;
            f32 a21 = a22 * (n / 6.2831855f);
            if (cur == -1 || func_0038DBA0(a20, func_0038DB00(ang, 1.5707964f)) > 0.5890486f) {
                s32 n2 = (s32)a21;
                s32 r = n2 % D_L39_0024BD40;
                if ((r ^ 1) & 1) {
                    f32 fr = a21 - (f32)n2;
                    if (fr > 0.8f) r++;
                    else if (fr < 0.2f) r--;
                    r = (r + D_L39_0024BD40) % D_L39_0024BD40;
                }
                h = -1;
                p->w74 = r;
                D_L39_00246528 = func_0038DB48(a22 - ((f32)r * 0.7853982f + 0.3926991f));
                if (D_L39_00246528 > 0.0f) h = 1;
            }
        } else {
            if (q->w1D8 == 0 && (q->w1C4 & 0xF000)) {
                s32 c2 = cur;
                if (q->w1C4 & 0x1000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.w10 : D_L39_0024BD48[i][D_L39_00246500[i]][c2].w10;
                }
                if (s->q2534->w1C4 & 0x4000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.w14 : D_L39_0024BD48[i][D_L39_00246500[i]][c2].w14;
                }
                if (s->q2534->w1C4 & 0x8000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.w8 : D_L39_0024BD48[i][D_L39_00246500[i]][c2].w8;
                }
                if (s->q2534->w1C4 & 0x2000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.wC : D_L39_0024BD48[i][D_L39_00246500[i]][c2].wC;
                }
                p->w74 = c2;
            }
        }
        if (D_L39_0024BD48[i][D_L39_00246500[i]][p->w74].w0 == 0) {
            if (h != 0) {
                s32 nx = (p->w74 + h) % D_L39_0024BD40;
                if (D_L39_0024BD48[i][D_L39_00246500[i]][nx].w0 != 0) p->w74 = nx;
            }
        }
    }
    if (p->w74 != cur) {
        t[1] = 0;
        func_L39_005F3548(3, 0, 0);
    } else {
        if (t[1] < 8) t[1]++;
    }
    if ((s->q2534->w1C0 & 0x10) == 0 && !flag) {
        if (t[0] == 0 || --t[0] == 0) {
            if (p->w74 >= 0) {
                s32 e = D_L39_0024BD48[i][D_L39_00246500[i]][p->w74].w18;
                if (e != 0) {
                    switch (e) {
                    case -1:
                        s->b1A11 = 2;
                        break;
                    case -2:
                        D_L39_002410F8[s->w2544] = 2;
                        break;
                    case -3:
                        D_L39_002410F8[s->w2544] = 1;
                        break;
                    case -4:
                        D_L39_002410F8[s->w2544] = 0;
                        break;
                    default:
                        func_L39_0063E3D0(s, e);
                        break;
                    }
                }
            }
        }
        func_L39_00677130(i);
        func_L39_00677120(i);
    } else {
        if (t[0] < 8) t[0]++;
    }
    if (t[0] == 0 || flag) {
        D_L39_0024CFD8[i] = p->w74;
        D_L39_0024CFC8[i] = p->u78.w;
        func_003934B8(p->w64);
        p->w6C = -6;
        D_L39_0024CFB8[i] = D_L39_0024B9C8;
    }
}
/* localdecomp:end func_L39_00675908 */

/* localdecomp:start func_L39_006761D0 */
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

extern s32 D_L39_00241118;
extern s32 *D_L39_00241120;
extern E80_006761D0 D_L39_0049C890[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_0049C340[];
extern char D_L39_00246540[];
extern s32 D_L39_00246564;
extern s32 D_L39_00246568;
extern s32 D_L39_0024656C;
extern s32 D_L39_00246574;
extern s32 D_L39_00246578;
extern s32 D_L39_0024657C;
extern s32 D_L39_0024652C;
extern s32 D_L39_00246530;
extern s32 D_L39_00246534;
extern s32 D_L39_00246538;
extern s32 D_L39_00246544;
extern s32 D_L39_00246548;
extern s32 D_L39_0024654C;
extern s32 D_L39_00246550;
extern s32 D_L39_00246554;
extern s32 D_L39_00246558;
extern s32 D_L39_00246560;
extern s32 D_L39_00246570;
extern s32 D_L39_00246580;
extern f32 D_L39_00246584;
extern s32 D_L39_00246588;
extern f32 D_L39_0024658C;
extern s32 D_L39_00246590;
extern s32 D_L39_00246594;
__asm__(".extern D_L39_00246500, 8");
__asm__(".extern D_L39_00242A50, 4");
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_00246564, 16");
__asm__(".extern D_L39_00246568, 16");
__asm__(".extern D_L39_0024656C, 16");
__asm__(".extern D_L39_00246574, 16");
__asm__(".extern D_L39_00246578, 16");
__asm__(".extern D_L39_0024657C, 16");
__asm__(".extern D_L39_0024652C, 4");
__asm__(".extern D_L39_00246530, 4");
__asm__(".extern D_L39_00246534, 4");
__asm__(".extern D_L39_00246538, 4");
__asm__(".extern D_L39_00246544, 4");
__asm__(".extern D_L39_00246548, 4");
__asm__(".extern D_L39_0024654C, 4");
__asm__(".extern D_L39_00246550, 4");
__asm__(".extern D_L39_00246554, 4");
__asm__(".extern D_L39_00246558, 4");
__asm__(".extern D_L39_00246560, 4");
__asm__(".extern D_L39_00246570, 4");
__asm__(".extern D_L39_00246580, 4");
__asm__(".extern D_L39_00246584, 4");
__asm__(".extern D_L39_00246588, 4");
__asm__(".extern D_L39_0024658C, 4");
__asm__(".extern D_L39_00246590, 4");
__asm__(".extern D_L39_00246594, 4");

extern s32 func_00393620(void *, s32 *, s32 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003AEC40(u8 *, s32, f32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_00120884(char *);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00381FF0(s32);
extern void func_L01_00514380_006761D0(void);
extern void func_L01_004126C8(void);
extern void func_00391240(s32, s32, unsigned long, char *, s32, s32, f32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);

/* v advanced by the layout's step for the player count: one player, two, three or four */
static __inline__ s32 bymode_006761D0(s32 v, s32 one, s32 two, s32 more) {
    if (*D_L39_00241120 >= 2) {
        if (*D_L39_00241120 >= 3) {
            return v + more;
        }
        return v + two;
    }
    return v + one;
}

/* the entry an item id stands for: its alternative when the flag bit for it is set */
static __inline__ E80_006761D0 *item_006761D0(u8 *s, s32 id) {
    if (func_L39_00648AE0(s, id)) {
        return &D_L39_0049C890[D_L39_0049C890[id].alt];
    }
    return &D_L39_0049C890[id];
}

s32 func_L39_006761D0(S_006761D0 *self) {
    s32 idx = (S_00675830 *)self - D_L39_00498B10 - 8;
    u8 *s2 = func_L39_0061BF38(idx);
    char buf[80];
    u32 hb[2];
    s32 px, py;
    s32 w;
    s32 tx, ty;
    s32 single;
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

    if (idx != D_L39_00241118) {
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
    func_00393620(self, &px, &py);
    for (i = 0; i < D_L39_0024BD40; i++) {
        f32 fi = (f32)i;
        func_0038DAB8((fi + fi) * 3.1415927f / (f32)D_L39_0024BD40 - 3.1415927f, 1.5707964f);
        if (self->sel == i) {
            if (D_L39_0024BD48[idx][D_L39_00246500[idx]][i].w0 != 0 && D_L39_00242A50 != 0) {
                f32 f = fi;
                if (f > 7.0f) {
                    f -= 8.0f;
                }
                {
                    Rooms_00675908 *rooms = &D_L39_00242A50->rooms;
                    func_003AEC40(rooms->arr[idx], 1, f);
                }
            }
        }
        if (D_L39_0024BD48[idx][D_L39_00246500[idx]][i].w0 != 0 && D_L39_00242A50 != 0) {
            ((G_006761D0 *)D_L39_00242A50)->w24DA4 = func_L39_00677170(idx) ? (s32)((f32)w * 0.5f) : 0;
        }
    }
    tx = 0;
    ty = 0;
    if (*D_L39_00241120 >= 2) {
        if (*D_L39_00241120 >= 3) {
            tx = D_L39_00246534;
            ty = D_L39_00246538;
        } else {
            tx = D_L39_0024652C;
            ty = D_L39_00246530;
        }
    }
    sel = self->sel;
    if (sel >= 0) {
        if (D_L39_0024BD48[idx][D_L39_00246500[idx]][sel].w0 != 0) {
            if (D_L39_004840A0[*(s32 *)(s2 + 0x2544)].w0 == 0) {
                id = D_L39_0024BD48[idx][D_L39_00246500[idx]][sel].w18;
                ok = 1;
                switch (id) {
                case -1:
                case -2:
                case -3:
                case -4:
                    ok = 0;
                    break;
                }
                single = *D_L39_00241120 == 1;
                if (ok && id > 0) {
                    e = &D_L39_0049C890[id];
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
                                *dst++ = D_L39_00483A00[t * 209 + m];
                            } while (j < 24);
                            aa = hb[0] ^ (u32)kp;
                            bb = hb[1] ^ aa;
                            hb[0] = aa;
                            qq = (bb >> 16) / (((bb ^ (bb >> 16)) << 16) + 1);
                            hb[1] = qq;
                            hx = *(u16 *)(hb + 1);
                        }
                        cnt = (s16)hx;
                        cur = item_006761D0(s2, D_L39_0024BD48[idx][D_L39_00246500[idx]][sel].w18)->h1E;
                        func_00120048(buf, D_L39_00246540, cnt);
                        if (cnt != 0) {
                            col = func_0038DBD8(0x8066CCFF, 0x8066CCFF, a * b);
                        } else {
                            col = func_0038DBD8(0x4040FF, 0x804040FF, a * b);
                        }
                        y1 = 0;
                        y2 = 0;
                        x1 = 0;
                        x2 = 0;
                        if (*D_L39_00241120 >= 2) {
                            if (*D_L39_00241120 >= 3) {
                                y1 = D_L39_0024654C;
                                y2 = D_L39_00246550;
                                x1 = D_L39_00246554;
                                x2 = D_L39_00246558;
                            } else {
                                y1 = D_L39_00246544;
                                y2 = D_L39_00246548;
                            }
                        }
                        alpha = col & 0xFF000000;
                        if (*D_L39_00241120 >= 3 && single) {
                            s32 yy = y1 + 0x64;
                            s32 xx = x1 + 0x69;
                            s32 xx2;
                            func_00391240(px + xx, py + yy + 0x14, alpha & 0x80000000, buf, -1, 0x1E, 0.5f);
                            func_00391240(px + xx, py + yy + 0x12, col, buf, -1, 0x1E, 0.5f);
                            y = y2 + 0x64;
                            xx2 = x2 + 0x69;
                            func_00120048(buf, D_L39_00246540, cur);
                            func_00391240(px + xx2, py + y + 0x26, alpha & 0x80000000, buf, -1, 0x1E, 0.5f);
                            func_00391240(px + xx2, py + y + 0x24, col, buf, -1, 0x1E, 0.5f);
                            {
                                s32 r0 = D_L39_00246564 + 0x86;
                                s32 r1 = D_L39_0024656C + 0x86;
                                s32 r2 = D_L39_00246560 + 0x69;
                                s32 r3 = D_L39_00246568 + 0x69;
                                func_0038AF30(py + 2 + r0, py + 2 + r1, px + r2 + 2, px + r3 + 2, alpha & 0x80000000);
                            }
                            {
                                s32 r0 = D_L39_00246564 + 0x86;
                                s32 r1 = D_L39_0024656C + 0x86;
                                s32 r2 = D_L39_00246560 + 0x69;
                                s32 r3 = D_L39_00246568 + 0x69;
                                func_0038AF30(py + r0, py + r1, px + r2, px + r3, col);
                            }
                        }
                        if (D_L39_0049C890[D_L39_0024BD48[idx][0][sel].w18].b8 != 0) {
                            f32 frac;
                            s32 bit;
                            u16 hx2;
                            u8 *p2;
                            u8 *kp2;
                            u32 n, m, base, t, aa, bb, qq;
                            p2 = (u8 *)(D_L39_0024BD48[idx][0][sel].w18 + (u32)s2);
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
                                    *dst++ = D_L39_0049C340[m + t * 129];
                                } while (j < 24);
                                aa = hb[0] ^ (u32)kp2;
                                bb = hb[1] ^ aa;
                                hb[0] = aa;
                                qq = (bb >> 16) / (((bb ^ (bb >> 16)) << 16) + 1);
                                hb[1] = qq;
                                hx2 = *(u16 *)(hb + 1);
                            }
                            frac = (s16)hx2;
                            sh = D_L39_0024BD48[idx][0][sel].w18;
                            {
                                /* func_L39_00648AE0's body */
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
                                        *dst++ = D_L39_00483A00[t * 209 + m];
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
                                s32 r0 = D_L39_00246574 + 0x86;
                                s32 r1 = D_L39_0024657C + 0x86;
                                s32 r2 = D_L39_00246570 + 0x69;
                                s32 r3 = D_L39_00246578 + 0x69;
                                func_0038AF30(py + r0, py + r1, px + r2, px + r3 + (s32)(frac / 3.0f * 92.0f), alpha | 0x6EC8FF);
                            }
                        }
                    }
                }
                col2 = func_0038DBD8(0x8066CCFF, 0x8066CCFF, a * b);
                split = 0;
                {
                    s32 named = 0;
                    s32 msg;
                    switch (D_L39_0024BD48[idx][D_L39_00246500[idx]][sel].w18) {
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
                        msg = item_006761D0(s2, D_L39_0024BD48[idx][D_L39_00246500[idx]][sel].w18)->msg;
                        break;
                    }
                    str = (char *)func_00381FF0(msg);
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
                            (D_L39_0024BD48[idx][D_L39_00246500[idx]][sel].w18 <= 0 ||
                             item_006761D0(s2, D_L39_0024BD48[idx][D_L39_00246500[idx]][sel].w18)->h1E == 0) &&
                            split != 0) {
                            y -= 0x19;
                        } else {
                            y -= 0x23;
                        }
                        wrap = 0x50;
                        scale = 0.0f;
                        if (*D_L39_00241120 >= 2) {
                            if (*D_L39_00241120 >= 3) {
                                wrap = D_L39_00246580;
                                scale = D_L39_00246584;
                            } else {
                                wrap = D_L39_00246588;
                                scale = D_L39_0024658C;
                            }
                        }
                        alpha2 = col2 & 0xFF000000;
                        if (split != 0 && single) {
                            {
                                s32 x = tx + 0x69;
                                func_L01_00514380_006761D0();
                                func_00391240(px + x + 2, y + ty + 2, (u32)(alpha2 & 0x80000000), str, split, wrap, scale);
                                func_L01_004126C8();
                                func_00391240(px + x, y + ty, (unsigned long)col2, str, split, wrap, scale);
                            }
                            /* line height of the 1-, 2- and 3/4-player layouts */
                            y = bymode_006761D0(y, 0x10, 0xC, 0xC);
                            {
                                s32 x = tx + 0x69;
                                func_L01_00514380_006761D0();
                                func_00391240(px + x + 2, y + ty + 2, (u32)(alpha2 & 0x80000000), (char *)q, -1, wrap, scale);
                                func_L01_004126C8();
                                func_00391240(px + x, y + ty, (unsigned long)col2, (char *)q, -1, wrap, scale);
                            }
                        } else {
                            s32 x;
                            s32 dy;
                            dy = 0xC;
                            if (*D_L39_00241120 >= 2) {
                                if (*D_L39_00241120 >= 3) {
                                    dy = D_L39_00246590;
                                } else {
                                    dy = D_L39_00246594;
                                }
                            }
                            if (single) {
                                func_L01_00514380_006761D0();
                                x = tx + 0x69;
                                func_00391240(px + x + 2, y + ty + dy + 2, (u32)(alpha2 & 0x80000000), str, -1, wrap, scale);
                                func_L01_004126C8();
                                func_00391240(px + x, y + ty + dy, col2, str, -1, wrap, scale);
                            }
                        }
                    }
                }
            }
        }
    }
    return self->x58;
}
/* localdecomp:end func_L39_006761D0 */
