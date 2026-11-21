#include "common.h"

/* NTSC-U counterpart of func_L01_0042EBF0 (src/levels/shared/L01_0042DB28.c) */
#include "vu0.h"
extern s32 D_001D545C;
extern u8 D_00142CA0[];
extern u8 D_00142CA0[];
extern s32 D_001D545C;
extern u8 D_00142CA0[];
extern s32 D_001D545C;

/* localdecomp:start func_L01_0042BDE0 */
typedef struct {
    u8 pad0[4];
    u16 flags;
    u16 id;
    s16 sub;
    u8 padA[4];
    u16 w;
    s16 h;
    s16 ox;
    s16 oy;
    u8 pad16[2];
    f32 fx;
    f32 fy;
    f32 ang;
    s32 on;
} E_0042EBF0;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} T_0042EBF0;

typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[0x18 - 0xC];
    s32 w18;
    u8 pad1C[4];
    E_0042EBF0 *list;
    s32 w24;
    u8 pad28[4];
    s32 w2C;
    T_0042EBF0 e[8];
    u8 padB0[4];
    f32 scale[61];
    s32 a[61];
    s32 b[61];
    u8 pad390[0x410 - 0x390];
    s32 level;
    s32 cur;
    u8 pad418[0x42C - 0x418];
    s32 w42C;
} G_0042EBF0;

typedef struct {
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
} R_0042EBF0;

typedef struct {
    s16 h0;
    s16 h2;
} I_0042EBF0;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
} X_0042EBF0;

typedef struct {
    f32 v[4];
} Q_0042EBF0;

typedef struct {
    s16 y0;
    s16 y1;
    s16 x0;
    s16 x1;
    s16 cx;
    s16 ty;
    s16 padC[2];
    s16 c;
    s16 d;
    s16 pad14[4];
} L_0042EBF0;

extern G_0042EBF0 D_L01_001F4020_0042BDE0;

extern u8 D_L01_001D7190_0042BDE0;
extern f32 D_L01_001D7194_0042BDE0;
extern s32 D_L01_001D7198_0042BDE0;
extern s32 D_L01_001D719C_0042BDE0;
extern s32 D_L01_001D71A0_0042BDE0;
extern s32 D_L01_001D71A4_0042BDE0;
extern s32 D_L01_001D71A8_0042BDE0;
extern s32 D_L01_001D71AC_0042BDE0;
extern s32 D_L01_001D71B0_0042BDE0;
extern s32 D_L01_001D71B4_0042BDE0;
extern u8 D_L01_001D71B8_0042BDE0;
extern u8 D_L01_001D71B9_0042BDE0;
extern s32 D_L01_001D71BC_0042BDE0;
extern f32 D_L01_001D71C0_0042BDE0;
extern f32 D_L01_001D71C4_0042BDE0;
extern Q_0042EBF0 D_L01_001D71C8_0042BDE0;
__asm__(".extern D_L01_001D7190_0042BDE0, 1");
__asm__(".extern D_L01_001D7194_0042BDE0, 4");
__asm__(".extern D_L01_001D7198_0042BDE0, 4");
__asm__(".extern D_L01_001D719C_0042BDE0, 4");
__asm__(".extern D_L01_001D71A0_0042BDE0, 4");
__asm__(".extern D_L01_001D71A4_0042BDE0, 4");
__asm__(".extern D_L01_001D71A8_0042BDE0, 4");
__asm__(".extern D_L01_001D71B8_0042BDE0, 1");
__asm__(".extern D_L01_001D71B9_0042BDE0, 1");
__asm__(".extern D_L01_001D71BC_0042BDE0, 4");
__asm__(".extern D_L01_001D71C0_0042BDE0, 4");
__asm__(".extern D_L01_001D71C4_0042BDE0, 4");
extern s32 D_L01_001E10E8;
extern I_0042EBF0 *D_L01_001DFDA0;
extern X_0042EBF0 *D_L01_001DFDA4;
extern f32 D_L01_001F40D4[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern u8 D_001A4BE0[];

extern void func_003A3EF0(s32, unsigned long);
extern void func_003A3FB0(s32, s32, s32, s32);
extern s32 func_00392108(s32, s32);
extern unsigned long func_003921D8(s32);
extern void func_L01_0041F008(s32, s32, s32, s32, long, s32);
extern void func_00392DD8(f32, f32, f32, f32, f32, s32, s32, unsigned long);
extern void func_L01_0041E1B0(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0042E2C0(s32, u8 *);
extern s32 func_0011A264(void *, s32, s32);
extern void func_0038C8F8(void *, unsigned long, char *, s32);
extern f32 func_00389380(f32, f32);
extern s32 func_L01_0042CFB8(f32 *x, f32 *y);
extern void func_L01_0042E820(f32 x, f32 y, f32 *u, f32 *v, s32 level, s32 m);
extern void func_L01_0041E750(f32, f32, f32, f32, f32, s32, s32, unsigned long, s32, void *);
extern void func_L01_0042E980(f32, f32, f32, f32, f32);
extern void func_L01_0042ECC8(f32, f32, f32, f32, f32);

void func_L01_0042BDE0(s32 flag) {
    s32 x0, y0, x1, y1;
    s32 ia, ib, ic, w, hh;
    s32 q1, q2, q3, q4;
    s32 u, v;
    s32 ax, ay, bx, by;
    s32 id;
    long lo, clut, t0;
    unsigned long tex;
    f32 s, k;
    f32 sc;
    s32 i, ii, j, slot, m;
    u8 *p;
    R_0042EBF0 *spr;

    if (D_L01_001D7190_0042BDE0 != 0) return;
    if (D_L01_001F4020_0042BDE0.w24 == 0) return;
    if (D_L01_001F4020_0042BDE0.cur >= 61) return;
    if (D_L01_001F4020_0042BDE0.cur < 0) return;

    s = D_L01_001F4020_0042BDE0.scale[D_L01_001F4020_0042BDE0.cur];
    k = D_L01_001D7194_0042BDE0;
    ia = k * 0.65f + (1.0f - s) * k;
    ib = s * (f32)(D_L01_001F4020_0042BDE0.a[D_L01_001F4020_0042BDE0.cur] >> 15);
    w = s * 512.0f;
    hh = s * 8192.0f;
    ic = s * (f32)((D_L01_001F4020_0042BDE0.b[D_L01_001F4020_0042BDE0.cur] >> 15) - ia);
    x0 = 0x1000;
    y0 = 0x800;
    x0 -= ib;
    x1 = x0 + hh;
    y0 -= ic;
    y1 = y0 + hh;
    q1 = (x0 + w - 1) / w;
    q2 = (0x2000 - x1 + w - 1) / w;
    u = (q1 + q2) * 512 + 0x2000;
    q3 = (y0 + w - 1) / w;
    q4 = (0x2000 - y1 + w - 1) / w;
    v = (q3 + q4) * 512 + 0x2000;
    ax = x0 - w * q1;
    bx = x1 + w * q2;
    ay = y0 - w * q3;
    by = y1 + w * q4;
    func_003A3EF0(8, 0);
    func_003A3EF0(0x47, 0);
    if (flag) {
        func_003A3FB0(D_L01_001D7198_0042BDE0, D_L01_001D71A0_0042BDE0, D_L01_001D719C_0042BDE0, D_L01_001D71A4_0042BDE0);
    }
    tex = func_003921D8(func_00392108(0xE999, D_L01_001F4020_0042BDE0.cur));
    if (D_L01_001D71B8_0042BDE0 != 0) {
        *(s32 *)(D_L01_001E10E8 + 0) = 0x10000005;
        *(s32 *)(D_L01_001E10E8 + 4) = 0;
        *(s32 *)(D_L01_001E10E8 + 8) = 0;
        *(s32 *)(D_L01_001E10E8 + 0xC) = 0x50000005;
        D_L01_001E10E8 += 0x10;
        p = (u8 *)D_L01_001E10E8;
        *(long *)(p + 0) = 0x7400000000008001UL;
        *(long *)(p + 8) = 0x5353106;
        *(long *)(p + 0x10) = tex;
        *(long *)(p + 0x18) = 342;
        *(long *)(p + 0x20) = D_L01_001D71A8_0042BDE0 | ((long)D_L01_001D71AC_0042BDE0 << 8) | ((long)D_L01_001D71B0_0042BDE0 << 16) | ((long)D_L01_001D71B4_0042BDE0 << 24);
        *(long *)(p + 0x28) = 0;
        *(long *)(p + 0x30) = (ax + D_001D4BD0 - 8) | ((long)(ay + D_001D4BD4 - 8) << 16) | ((long)D_L01_001F4020_0042BDE0.w18 << 32);
        *(long *)(p + 0x38) = u | ((long)v << 16);
        *(long *)(p + 0x40) = (bx + D_001D4BD0 - 8) | ((long)(by + D_001D4BD4 - 8) << 16) | ((long)D_L01_001F4020_0042BDE0.w18 << 32);
        *(long *)(p + 0x48) = 0;
        D_L01_001E10E8 = D_L01_001E10E8 + 0x50;
    }
    func_003A3EF0(8, 5);
    func_003A3EF0(0x47, 0x60B);
    *(s32 *)(D_L01_001E10E8 + 0) = 0x10000005;
    *(s32 *)(D_L01_001E10E8 + 4) = 0;
    *(s32 *)(D_L01_001E10E8 + 8) = 0;
    *(s32 *)(D_L01_001E10E8 + 0xC) = 0x50000005;
    lo = (D_L01_001F4020_0042BDE0.w42C >> 8) | 0x25320000;
    clut = ((long)(s32)((tex >> 37) & 0x3FFF) << 37) | 0x640000000UL;
    t0 = lo | clut | 0x8000000000000000UL;
    D_L01_001E10E8 += 0x10;
    p = (u8 *)D_L01_001E10E8;
    *(long *)(p + 0) = 0x7400000000008001UL;
    *(long *)(p + 8) = 0x5353106;
    *(long *)(p + 0x10) = t0;
    *(long *)(p + 0x18) = 342;
    *(long *)(p + 0x20) = D_L01_001D71A8_0042BDE0 | ((long)D_L01_001D71AC_0042BDE0 << 8) | ((long)D_L01_001D71B0_0042BDE0 << 16) | ((long)D_L01_001D71B4_0042BDE0 << 24);
    *(long *)(p + 0x28) = 0;
    *(long *)(p + 0x30) = (x0 + D_001D4BD0 - 8) | ((long)(y0 + D_001D4BD4 - 8) << 16) | ((long)D_L01_001F4020_0042BDE0.w18 << 32);
    *(long *)(p + 0x38) = 0x20002000;
    *(long *)(p + 0x40) = (x1 + D_001D4BD0 - 8) | ((long)(y1 + D_001D4BD4 - 8) << 16) | ((long)D_L01_001F4020_0042BDE0.w18 << 32);
    *(long *)(p + 0x48) = 0;
    D_L01_001E10E8 = D_L01_001E10E8 + 0x50;
    func_003A3EF0(0x47, 0x360B);

    if (D_L01_001F4020_0042BDE0.w2C != 0 && D_L01_001F4020_0042BDE0.w8 != 0) {
        s32 dx = x1 - x0;
        s32 dy = y1 - y0;
        for (slot = 0; slot < 8; slot++) {
            s32 c = D_L01_001F4020_0042BDE0.e[slot].a;
            if (c >= 0) {
                s32 col = c % 16;
                s32 row = c / 16;
                func_L01_0041F008(x0 + col * dx / 16, y0 + row * dy / 16,
                                  x0 + (col + 1) * dx / 16, y0 + (row + 1) * dy / 16, 0x20000000, 1);
            }
        }
    }
    func_L01_0042BC68();
    if (D_L01_001F4020_0042BDE0.list != 0) {
        spr = (R_0042EBF0 *)0x70000000;
        sc = (D_L01_001F4020_0042BDE0.scale[D_L01_001F4020_0042BDE0.cur] + D_L01_001F4020_0042BDE0.scale[D_L01_001F4020_0042BDE0.cur] + 5.0f) / 13.0f;
        for (i = 0; !(D_L01_001F4020_0042BDE0.list[i].flags & 4); i++) {
            f32 mul;
            f32 fw, fh, bx0, by0, px, py, sel, ss;
            X_0042EBF0 *t;
            s32 n;
            if (D_L01_001F4020_0042BDE0.list[i].on == 0) continue;
            n = D_L01_001F4020_0042BDE0.list[i].id;
            if (n == 0) continue;
            if (D_L01_001F4020_0042BDE0.list[i].flags & 1) continue;
            mul = 1.0f;
            if (D_L01_001F4020_0042BDE0.list[i].flags & 0x80) mul = 1.5f;
            id = func_00392108(n, D_L01_001F4020_0042BDE0.list[i].sub);
            t = &D_L01_001DFDA4[D_L01_001DFDA0[id].h2];
            bx0 = x0;
            by0 = y0;
            fw = x1 - x0;
            fh = y1 - y0;
            px = bx0 + D_L01_001F4020_0042BDE0.list[i].fx * fw;
            py = by0 + D_L01_001F4020_0042BDE0.list[i].fy * fh;
            if (D_L01_001D71B9_0042BDE0 != 0 && i == D_L01_001D71BC_0042BDE0) {
                px = bx0 + D_L01_001D71C0_0042BDE0 * fw;
                py = by0 + D_L01_001D71C4_0042BDE0 * fh;
            }
            sel = sc;
            if (D_L01_001F4020_0042BDE0.list[i].flags & 0x200) sel = D_L01_001F4020_0042BDE0.scale[D_L01_001F4020_0042BDE0.cur];
            ss = mul * sel;
            spr[i].x0 = px - ss * (f32)(1 << (t->b6 + 3));
            spr[i].x1 = (f32)spr[i].x0 + ss * (f32)(1 << (t->b6 + 4));
            spr[i].y0 = py - ss * (f32)(1 << (t->b7 + 3));
            spr[i].y1 = (f32)spr[i].y0 + ss * (f32)(1 << (t->b7 + 4));
        }
        for (ii = 0; !(D_L01_001F4020_0042BDE0.list[ii + 1].flags & 4); ii++) {
            if (D_L01_001F4020_0042BDE0.list[ii].on == 0 || D_L01_001F4020_0042BDE0.list[ii].id == 0 || (D_L01_001F4020_0042BDE0.list[ii].flags & 3)) continue;
            for (j = ii + 1; !(D_L01_001F4020_0042BDE0.list[j].flags & 4); j++) {
                s32 o0, o1, o2, o3;
                s32 dax, day, dbx, dby;
                if ((o0 = spr[j].x1 - spr[ii].x0) <= 0) continue;
                if ((o1 = spr[ii].x1 - spr[j].x0) <= 0) continue;
                if ((o2 = spr[j].y1 - spr[ii].y0) <= 0) continue;
                if ((o3 = spr[ii].y1 - spr[j].y0) <= 0) continue;
                if (D_L01_001F4020_0042BDE0.list[j].on == 0 || D_L01_001F4020_0042BDE0.list[j].id == 0 || (D_L01_001F4020_0042BDE0.list[j].flags & 3)) continue;
                dax = 0;
                day = 0;
                dbx = 0;
                dby = 0;
                if (o0 <= o1 && o0 <= o2 && o0 <= o3) {
                    dax = o0 >> 1;
                    dbx = dax - o0;
                } else if (o1 <= o2 && o1 <= o3) {
                    dbx = o1 >> 1;
                    dax = dbx - o1;
                } else if (o2 <= o3) {
                    day = o2 >> 1;
                    dby = day - o2;
                } else {
                    dby = o3 >> 1;
                    day = dby - o3;
                }
                spr[ii].x0 += dax;
                spr[ii].x1 += dax;
                spr[ii].y0 += day;
                spr[ii].y1 += day;
                spr[j].x0 += dbx;
                spr[j].x1 += dbx;
                spr[j].y0 += dby;
                spr[j].y1 += dby;
            }
        }
        for (m = 0; !(D_L01_001F4020_0042BDE0.list[m].flags & 4); m++) {
            u16 fl;
            s32 n6, sub;
            f32 ss;
            if (D_L01_001F4020_0042BDE0.list[m].on == 0) continue;
            fl = D_L01_001F4020_0042BDE0.list[m].flags;
            if (fl & 1) continue;
            n6 = D_L01_001F4020_0042BDE0.list[m].id;
            sub = D_L01_001F4020_0042BDE0.list[m].sub;
            if (n6 == 0) continue;
            if (fl & 0x40) {
                func_L01_0041F008(spr[m].x0 - 0x20, spr[m].y0 - 0x20, spr[m].x1 + 0x20, spr[m].y1 + 0x20, 0x80000000, 1);
            }
            if (D_L01_001F4020_0042BDE0.list[m].flags & 0x200) ss = D_L01_001F40D4[D_L01_001F4020_0042BDE0.cur];
            else ss = sc;
            if (D_L01_001F4020_0042BDE0.list[m].flags & 0x100) {
                f32 sz = ss * 256.0f;
                f32 cx = (f32)(spr[m].x0 + spr[m].x1) * 0.5f;
                f32 cy = (f32)(spr[m].y0 + spr[m].y1) * 0.5f;
                f32 ang = D_L01_001F4020_0042BDE0.list[m].ang;
                func_00392DD8(cx, cy, sz, sz, ang, 0x20, 0x20, func_003921D8(func_00392108(n6, sub)));
            } else {
                s32 col = func_L01_0042BCF8(D_L01_001F4020_0042BDE0.list[m].id, D_L01_001F4020_0042BDE0.list[m].sub);
                func_L01_0041E1B0(func_00392108(n6, sub), spr[m].x0 + 0x10, spr[m].y0 + 0x10, spr[m].x1 - spr[m].x0 + 0x10, spr[m].y1 - spr[m].y0 + 0x10, 0x80, 0);
                func_L01_0041E1B0(func_00392108(n6, sub), spr[m].x0, spr[m].y0, spr[m].x1 - spr[m].x0, spr[m].y1 - spr[m].y0, 0x80, col);
            }
            if (D_L01_001F4020_0042BDE0.list[m].flags & 0x10) {
                s32 lw, lh, ox, oy, lx, ly, lx2;
                char buf[0x50];
                L_0042EBF0 lab;
                lw = (s16)D_L01_001F4020_0042BDE0.list[m].w;
                lh = D_L01_001F4020_0042BDE0.list[m].h;
                ox = D_L01_001F4020_0042BDE0.list[m].ox;
                oy = D_L01_001F4020_0042BDE0.list[m].oy;
                if (ox == 0) {
                    lx = ((spr[m].x0 + spr[m].x1) >> 5) - lw / 2;
                } else if (ox > 0) {
                    lx = (spr[m].x1 >> 4) - lw / 2 + ox;
                } else {
                    lx = (spr[m].x0 >> 4) - lw / 2 + ox;
                }
                if (oy == 0) {
                    ly = ((spr[m].y0 + spr[m].y1) >> 5) - lh / 2;
                } else if (oy > 0) {
                    ly = (spr[m].y1 >> 4) - lh / 2 + oy;
                } else {
                    ly = (spr[m].y0 >> 4) - lh / 2 + oy;
                }
                lx2 = lx + lw;
                func_L01_0041F008(lx, ly, lx2, ly + lh * 2, 0x40000000, 0);
                func_L01_0042E2C0(m, (u8 *)buf);
                func_0011A264(&lab, 0, sizeof(lab));
                lab.y0 = ly;
                lab.y1 = ly + lh;
                lab.x0 = lx;
                lab.x1 = lx2;
                lab.cx = lx + lw / 2;
                lab.ty = ly + 4;
                lab.c = 0xF;
                lab.d = 0x11;
                func_0038C8F8(&lab, 0x80FFA888, buf, -1);
            }
        }
    }
    if (D_001D545C == D_L01_001F4020_0042BDE0.cur) {
        s32 hid, c;
        f32 ang, sz, a2;
        f32 pos[2];
        s32 cols[4];
        Q_0042EBF0 uv;
        u8 *h;
        s32 st;
        hid = func_00392108(0xE99A, 3);
        sc = (D_L01_001F4020_0042BDE0.scale[D_L01_001F4020_0042BDE0.cur] * 4.0f + 10.0f) * 0.75f / 13.0f;
        h = D_001A4BE0;
        ang = *(f32 *)(h + 0x98);
        st = *(s32 *)(h + 0x25CC) == 0xF;
        if (st) ang = func_00389380(ang, 1.5707964f);
        if (D_001D545C == 0xC) ang = func_00389380(ang, 3.1415927f);
        if (!((s32 (*)(f32, f32, f32 *, f32 *, s32))func_L01_0042CFB8)(*(f32 *)(h + 0x80), *(f32 *)(h + 0x84), &pos[0], &pos[1], D_001D545C)) {
            func_L01_0042E820(*(f32 *)(h + 0x80), *(f32 *)(h + 0x84), &pos[0], &pos[1], D_001D545C, -1);
        }
        pos[0] = (f32)x0 + pos[0] * (f32)(x1 - x0);
        pos[1] = (f32)y0 + pos[1] * (f32)(y1 - y0);
        c = func_L01_0042BCF8(0xE99A, 3) | 0x80000000;
        cols[0] = c;
        cols[1] = c;
        cols[2] = c;
        cols[3] = c;
        uv = D_L01_001D71C8_0042BDE0;
        sz = sc * 256.0f;
        a2 = ang - 1.5707964f;
        func_L01_0041E750(pos[0] + 32.0f, pos[1] + 32.0f, sz, sz, a2, 0x20, 0x20, func_003921D8(hid), 0, &uv);
        func_L01_0041E750(pos[0], pos[1], sz, sz, a2, 0x20, 0x20, func_003921D8(hid), 0, cols);
    }
    if (D_00142CA0[5] != 0 && D_L01_001F4020_0042BDE0.level == 0x1C) {
        func_L01_0042E980(x0, x1, y0, y1, 2.5f);
    }
    if (D_001D545C == D_L01_001F4020_0042BDE0.cur) {
        func_L01_0042ECC8(x0, x1, y0, y1, 2.5f);
    }
    func_003A3FB0(0, D_001D4BC0 - 1, 0, D_001D4BC4 - 1);
}
/* localdecomp:end func_L01_0042BDE0 */
