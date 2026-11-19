/* near miss (34 places, canonical level 01): func_L01_0042EBF0, 0x1258, written from retail by e14
 * (2026-11-17, first pass, ~1 h): 345 of 1174 aligned rows left (dl.py), all sections laid out in retail
 * order; the remaining rows are mostly register allocation/scheduling, not structure.
 * What is settled: callees by catalogue name (func_00396968/func_00396A38/func_003A9440/func_003A9500/
 * func_00397638/func_00391130/func_0038DAB8 are the level copies of front-end functions);
 * func_L01_00421738's 5th argument is 64-bit (retail builds 0x80000000 zero-extended: ori+dsll), so it is
 * declared unsigned long here; func_00391130's 2nd argument likewise (0x80FFA888); func_L01_0042FE48 is
 * called through a cast pointer with (hero x, hero y, &pos[0], &pos[1], D_001D545C) since its definition
 * later in the file takes two pointers; D_L01_001D7190..71C4 need early `.extern` (gp outside delay slots),
 * D_L01_001D71AC/B0/B4 none (lui form); the flag block's identical arms are lesson 25/35 (z = 0.0f before,
 * both if/else written out; the y one is cross-jumped, leaving retail's dead `li $v0, 1`);
 * x0/y0/x1/y1 are spilled scalars at 0x70..0x7C (x0 = 0x1000 then x0 -= ib keeps the constant pseudo).
 * Open, in order of size: (1) first block: w/q1..q4 register choice (retail keeps w in $v1, q's in $t0/$a3);
 * (2) the second GIF packet: retail computes the TEX0 word (dsrl32 tex,5 / 0x25320000 / 1<<63) before the
 * header stores, mine after; (3) e[8] loop: retail computes c/16*dy twice in two mults and %16 via sll/subu
 * order differently; (4) last list loop: retail spills i at 0x80($sp) and keeps &G in $s7, the scratchpad
 * rect pointer in $s2, n6 in $s1 (mine: &G in $fp, i in a register); the 0x200 scale reads D_L01_001F4054
 * (another spelling of G.scale, lesson 64); (5) section 4's re-materialised &G (lui $6 in a bne delay slot)
 * also suggests a different spelling there. Check with tools/check.py under the file's own flags. */
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

#define GG (*(G_0042EBF0 *)&D_L01_001F3FA0)

extern u8 D_L01_001D7190;
extern f32 D_L01_001D7194;
extern s32 D_L01_001D7198;
extern s32 D_L01_001D719C;
extern s32 D_L01_001D71A0;
extern s32 D_L01_001D71A4;
extern s32 D_L01_001D71A8;
extern s32 D_L01_001D71AC;
extern s32 D_L01_001D71B0;
extern s32 D_L01_001D71B4;
extern u8 D_L01_001D71B8;
extern u8 D_L01_001D71B9;
extern s32 D_L01_001D71BC;
extern f32 D_L01_001D71C0;
extern f32 D_L01_001D71C4;
extern Q_0042EBF0 D_L01_001D71C8;
__asm__(".extern D_L01_001D7190, 1");
__asm__(".extern D_L01_001D7194, 4");
__asm__(".extern D_L01_001D7198, 4");
__asm__(".extern D_L01_001D719C, 4");
__asm__(".extern D_L01_001D71A0, 4");
__asm__(".extern D_L01_001D71A4, 4");
__asm__(".extern D_L01_001D71A8, 4");
__asm__(".extern D_L01_001D71B8, 1");
__asm__(".extern D_L01_001D71B9, 1");
__asm__(".extern D_L01_001D71BC, 4");
__asm__(".extern D_L01_001D71C0, 4");
__asm__(".extern D_L01_001D71C4, 4");
extern s32 D_L01_001E1068;
extern s32 D_L01_001E11A0;
extern f32 D_L01_001E11A4;
extern I_0042EBF0 *D_L01_001DFD20;
extern X_0042EBF0 *D_L01_001DFD24;
extern f32 D_L01_001F4054[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern u8 D_001A4BE0[];

extern void func_003A9440(s32, unsigned long);
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_00396968(s32, s32);
extern unsigned long func_00396A38(s32);
extern void func_L01_00421738(s32, s32, s32, s32, unsigned long, s32);
extern void func_L01_0042EA78(void);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, unsigned long);
extern void func_L01_004208E0(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00431150(s32, char *);
extern s32 func_0011A264(void *, s32, s32);
extern void func_00391130(void *, unsigned long, char *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_0042FE48();
extern void func_L01_004316B0(f32, f32, f32 *, f32 *, s32, s32);
extern void func_L01_00420E80(f32, f32, f32, f32, f32, s32, s32, unsigned long, s32, void *);
extern void func_L01_00431810(f32, f32, f32, f32, f32);
extern void func_L01_00431B58(f32, f32, f32, f32, f32);

void func_L01_0042EBF0(s32 flag) {
    s32 x0, y0, x1, y1;
    s32 ia, ib, ic, w, hh;
    s32 q1, q2, q3, q4;
    s32 u, v;
    s32 ax, ay, bx, by;
    s32 xx, yy;
    s32 id;
    unsigned long tex;
    f32 s, k;
    f32 sc;
    s32 i, j;
    u8 *p;
    R_0042EBF0 *spr;

    if (D_L01_001D7190 != 0) return;
    if (GG.w24 == 0) return;
    if (GG.cur >= 61) return;
    if (GG.cur < 0) return;

    s = GG.scale[GG.cur];
    k = D_L01_001D7194;
    ia = k * 0.65f + (1.0f - s) * k;
    ib = s * (f32)(GG.a[GG.cur] >> 15);
    w = s * 512.0f;
    hh = s * 8192.0f;
    ic = s * (f32)((GG.b[GG.cur] >> 15) - ia);
    x0 = 0x1000;
    y0 = 0x800;
    x0 -= ib;
    x1 = x0 + hh;
    y0 -= ic;
    y1 = y0 + hh;
    q1 = (x0 + w - 1) / w;
    q2 = (w + 0x2000 - x1 - 1) / w;
    u = (q1 + q2) * 512 + 0x2000;
    q3 = (y0 + w - 1) / w;
    q4 = (w + 0x2000 - y1 - 1) / w;
    v = (q3 + q4) * 512 + 0x2000;
    ax = x0 - w * q1;
    bx = x1 + w * q2;
    ay = y0 - w * q3;
    by = y1 + w * q4;
    func_003A9440(8, 0);
    func_003A9440(0x47, 0);
    if (flag) {
        f32 m = D_L01_001E11A4;
        f32 z = 0.0f;
        f32 t = (f32)D_L01_001D719C * m + 0.5f;
        if (D_L01_001E11A0 == 1) { xx = t + z; } else { xx = t + z; }
        z = 0.0f;
        t = (f32)D_L01_001D71A4 * m + 0.5f;
        if (D_L01_001E11A0 == 1) { yy = t + z; } else { yy = t + z; }
        func_003A9500(D_L01_001D7198, D_L01_001D71A0, xx, yy);
    }
    tex = func_00396A38(func_00396968(0xE999, GG.cur));
    if (D_L01_001D71B8 != 0) {
        *(s32 *)(D_L01_001E1068 + 0) = 0x10000005;
        *(s32 *)(D_L01_001E1068 + 4) = 0;
        *(s32 *)(D_L01_001E1068 + 8) = 0;
        *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000005;
        p = (u8 *)D_L01_001E1068 + 0x10;
        D_L01_001E1068 = (s32)p;
        *(long *)(p + 0) = 0x7400000000008001UL;
        *(long *)(p + 8) = 0x5353106;
        *(long *)(p + 0x10) = tex;
        *(long *)(p + 0x18) = 342;
        *(long *)(p + 0x20) = D_L01_001D71A8 | ((long)D_L01_001D71AC << 8) | ((long)D_L01_001D71B0 << 16) | ((long)D_L01_001D71B4 << 24);
        *(long *)(p + 0x28) = 0;
        *(long *)(p + 0x30) = (ax + D_001D4BD0 - 8) | ((long)(ay + D_001D4BD4 - 8) << 16) | ((long)GG.w18 << 32);
        *(long *)(p + 0x38) = u | ((long)v << 16);
        *(long *)(p + 0x40) = (bx + D_001D4BD0 - 8) | ((long)(by + D_001D4BD4 - 8) << 16) | ((long)GG.w18 << 32);
        *(long *)(p + 0x48) = 0;
        D_L01_001E1068 = D_L01_001E1068 + 0x50;
    }
    func_003A9440(8, 5);
    func_003A9440(0x47, 0x60B);
    *(s32 *)(D_L01_001E1068 + 0) = 0x10000005;
    *(s32 *)(D_L01_001E1068 + 4) = 0;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000005;
    p = (u8 *)D_L01_001E1068 + 0x10;
    D_L01_001E1068 = (s32)p;
    *(long *)(p + 0) = 0x7400000000008001UL;
    *(long *)(p + 8) = 0x5353106;
    *(long *)(p + 0x10) = (GG.w42C >> 8) | 0x25320000 | ((long)(s32)((tex >> 37) & 0x3FFF) << 37) | 0x640000000UL | 0x8000000000000000UL;
    *(long *)(p + 0x18) = 342;
    *(long *)(p + 0x20) = D_L01_001D71A8 | ((long)D_L01_001D71AC << 8) | ((long)D_L01_001D71B0 << 16) | ((long)D_L01_001D71B4 << 24);
    *(long *)(p + 0x28) = 0;
    *(long *)(p + 0x30) = (x0 + D_001D4BD0 - 8) | ((long)(y0 + D_001D4BD4 - 8) << 16) | ((long)GG.w18 << 32);
    *(long *)(p + 0x38) = 0x20002000;
    *(long *)(p + 0x40) = (x1 + D_001D4BD0 - 8) | ((long)(y1 + D_001D4BD4 - 8) << 16) | ((long)GG.w18 << 32);
    *(long *)(p + 0x48) = 0;
    D_L01_001E1068 = D_L01_001E1068 + 0x50;
    func_003A9440(0x47, 0x360B);

    if (GG.w2C != 0 && GG.w8 != 0) {
        s32 dx = x1 - x0;
        s32 dy = y1 - y0;
        for (i = 0; i < 8; i++) {
            s32 c = GG.e[i].a;
            if (c >= 0) {
                func_L01_00421738(x0 + c % 16 * dx / 16, y0 + c / 16 * dy / 16,
                                  x0 + (c % 16 * dx + dx) / 16, y0 + (c / 16 * dy + dy) / 16, 0x20000000, 1);
            }
        }
    }
    func_L01_0042EA78();
    spr = (R_0042EBF0 *)0x70000000;
    if (GG.list != 0) {
        sc = (GG.scale[GG.cur] + GG.scale[GG.cur] + 5.0f) / 13.0f;
        for (i = 0; !(GG.list[i].flags & 4); i++) {
            if (GG.list[i].on != 0 && GG.list[i].id != 0 && !(GG.list[i].flags & 1)) {
                f32 mul;
                f32 fw, fh, bx0, by0, px, py, ss;
                X_0042EBF0 *t;
                mul = 1.0f;
                if (GG.list[i].flags & 0x80) mul = 1.5f;
                id = func_00396968(GG.list[i].id, GG.list[i].sub);
                bx0 = x0;
                by0 = y0;
                fw = x1 - x0;
                fh = y1 - y0;
                px = bx0 + GG.list[i].fx * fw;
                py = by0 + GG.list[i].fy * fh;
                t = &D_L01_001DFD24[D_L01_001DFD20[id].h2];
                if (D_L01_001D71B9 != 0 && i == D_L01_001D71BC) {
                    px = bx0 + D_L01_001D71C0 * fw;
                    py = by0 + D_L01_001D71C4 * fh;
                }
                ss = sc;
                if (GG.list[i].flags & 0x200) ss = GG.scale[GG.cur];
                ss = mul * ss;
                spr[i].x0 = px - ss * (f32)(1 << (t->b6 + 3));
                spr[i].x1 = (f32)spr[i].x0 + ss * (f32)(1 << (t->b6 + 4));
                spr[i].y0 = py - ss * (f32)(1 << (t->b7 + 3));
                spr[i].y1 = (f32)spr[i].y0 + ss * (f32)(1 << (t->b7 + 4));
            }
        }
        for (i = 0; !(GG.list[i + 1].flags & 4); i++) {
            if (GG.list[i].on == 0 || GG.list[i].id == 0 || (GG.list[i].flags & 3)) continue;
            for (j = i + 1; !(GG.list[j].flags & 4); j++) {
                R_0042EBF0 *ra = &spr[i];
                R_0042EBF0 *rb = &spr[j];
                s32 o0, o1, o2, o3;
                s32 dax, day, dbx, dby;
                if ((o0 = rb->x1 - ra->x0) <= 0) continue;
                if ((o1 = ra->x1 - rb->x0) <= 0) continue;
                if ((o2 = rb->y1 - ra->y0) <= 0) continue;
                if ((o3 = ra->y1 - rb->y0) <= 0) continue;
                if (GG.list[j].on == 0 || GG.list[j].id == 0 || (GG.list[j].flags & 3)) continue;
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
                ra->x0 += dax;
                ra->x1 += dax;
                ra->y0 += day;
                ra->y1 += day;
                rb->x0 += dbx;
                rb->x1 += dbx;
                rb->y0 += dby;
                rb->y1 += dby;
            }
        }
        for (i = 0; !(GG.list[i].flags & 4); i++) {
            u16 fl;
            s32 n6, sub;
            R_0042EBF0 *r;
            f32 ss;
            if (GG.list[i].on == 0) continue;
            fl = GG.list[i].flags;
            if (fl & 1) continue;
            n6 = GG.list[i].id;
            sub = GG.list[i].sub;
            if (n6 == 0) continue;
            r = &spr[i];
            if (fl & 0x40) {
                func_L01_00421738(r->x0 - 0x20, r->y0 - 0x20, r->x1 + 0x20, r->y1 + 0x20, 0x80000000, 1);
            }
            if (GG.list[i].flags & 0x200) ss = D_L01_001F4054[GG.cur];
            else ss = sc;
            if (GG.list[i].flags & 0x100) {
                f32 sz = ss * 256.0f;
                f32 cx = (f32)(r->x0 + r->x1) * 0.5f;
                f32 cy = (f32)(r->y0 + r->y1) * 0.5f;
                f32 ang = GG.list[i].ang;
                func_00397638(cx, cy, sz, sz, ang, 0x20, 0x20, func_00396A38(func_00396968(n6, sub)));
            } else {
                s32 col = func_L01_0042EB08(GG.list[i].id, GG.list[i].sub);
                func_L01_004208E0(func_00396968(n6, sub), r->x0 + 0x10, r->y0 + 0x10, r->x1 - r->x0 + 0x10, r->y1 - r->y0 + 0x10, 0x80, 0);
                func_L01_004208E0(func_00396968(n6, sub), r->x0, r->y0, r->x1 - r->x0, r->y1 - r->y0, 0x80, col);
            }
            if (GG.list[i].flags & 0x10) {
                s32 lw, lh, ox, oy, lx, ly, lx2;
                char buf[0x50];
                L_0042EBF0 lab;
                lw = (s16)GG.list[i].w;
                ox = GG.list[i].ox;
                oy = GG.list[i].oy;
                lh = GG.list[i].h;
                if (ox == 0) {
                    lx = ((r->x0 + r->x1) >> 5) - lw / 2;
                } else {
                    lx = ((ox > 0 ? r->x1 : r->x0) >> 4) - lw / 2 + ox;
                }
                if (oy == 0) {
                    ly = ((r->y0 + r->y1) >> 5) - lh / 2;
                } else {
                    ly = ((oy > 0 ? r->y1 : r->y0) >> 4) - lh / 2 + oy;
                }
                lx2 = lx + lw;
                func_L01_00421738(lx, ly, lx2, ly + lh * 2, 0x40000000, 0);
                func_L01_00431150(i, buf);
                func_0011A264(&lab, 0, sizeof(lab));
                lab.y0 = ly;
                lab.y1 = ly + lh;
                lab.x0 = lx;
                lab.x1 = lx2;
                lab.cx = lx + lw / 2;
                lab.ty = ly + 4;
                lab.c = 0xF;
                lab.d = 0x11;
                func_00391130(&lab, 0x80FFA888, buf, -1);
            }
        }
    }
    if (D_001D545C == GG.cur) {
        s32 hid;
        f32 ang, sz, a2;
        f32 pos[2];
        s32 cols[4];
        Q_0042EBF0 uv;
        u8 *h = D_001A4BE0;
        hid = func_00396968(0xE99A, 3);
        sc = (GG.scale[GG.cur] * 4.0f + 10.0f) * 0.75f / 13.0f;
        ang = *(f32 *)(h + 0x98);
        if (*(s32 *)(h + 0x25CC) == 0xF) ang = func_0038DAB8(ang, 1.5707964f);
        if (D_001D545C == 0xC) ang = func_0038DAB8(ang, 3.1415927f);
        if (!((s32 (*)(f32, f32, f32 *, f32 *, s32))func_L01_0042FE48)(*(f32 *)(h + 0x80), *(f32 *)(h + 0x84), &pos[0], &pos[1], D_001D545C)) {
            func_L01_004316B0(*(f32 *)(h + 0x80), *(f32 *)(h + 0x84), &pos[0], &pos[1], D_001D545C, -1);
        }
        pos[0] = (f32)x0 + pos[0] * (f32)(x1 - x0);
        pos[1] = (f32)y0 + pos[1] * (f32)(y1 - y0);
        cols[3] = cols[0] = cols[1] = cols[2] = func_L01_0042EB08(0xE99A, 3) | 0x80000000;
        uv = D_L01_001D71C8;
        sz = sc * 256.0f;
        a2 = ang - 1.5707964f;
        func_L01_00420E80(pos[0] + 32.0f, pos[1] + 32.0f, sz, sz, a2, 0x20, 0x20, func_00396A38(hid), 0, &uv);
        func_L01_00420E80(pos[0], pos[1], sz, sz, a2, 0x20, 0x20, func_00396A38(hid), 0, cols);
    }
    if (D_00142CA0[5] != 0 && GG.level == 0x1C) {
        func_L01_00431810(x0, x1, y0, y1, 2.5f);
    }
    if (D_001D545C == GG.cur) {
        func_L01_00431B58(x0, x1, y0, y1, 2.5f);
    }
    func_003A9500(0, D_001D4BC0 - 1, 0, D_001D4BC4 - 1);
}
