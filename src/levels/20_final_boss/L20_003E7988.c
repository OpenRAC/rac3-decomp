#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L20_003E7988 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DF168;
__asm__(".extern D_L20_001DF168, 4");
extern void func_L20_003E6150(u8 *a0, f32 size);

void func_L20_003E7988(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);

    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DF168, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DF168, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DF168, 2.0f, 0.1f);
    }
    func_L20_003E6150(p, D_L20_001DF168);
}
/* localdecomp:end func_L20_003E7988 */

/* localdecomp:start func_L20_003E7A70 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003E5C28.c */
#include "vu0.h"

extern f32 D_L20_001DF178;
__asm__(".extern D_L20_001DF178, 4");
extern s32 D_L20_001DF170;
__asm__(".extern D_L20_001DF170, 4");
extern s32 D_L20_001DF174;
__asm__(".extern D_L20_001DF174, 4");
extern f32 D_L20_001DF17C;
__asm__(".extern D_L20_001DF17C, 4");
extern f32 D_L20_001DF180;
__asm__(".extern D_L20_001DF180, 4");
extern f32 D_L20_001DF184;
__asm__(".extern D_L20_001DF184, 4");
extern u32 D_L20_001DF188;
__asm__(".extern D_L20_001DF188, 4");
extern u32 D_L20_001DF18C;
__asm__(".extern D_L20_001DF18C, 4");
extern u8 D_L20_001E2E00[];
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 e, f32 f, f32 g);

void func_L20_003E7A70(u8 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *p;
    s32 col;
    s32 i;
    f32 nb;
    f32 pf;

    p = *(u8 **)(a0 + 0x68);
    col = func_0038DBD8(D_L20_001DF170, D_L20_001DF174, func_0038D0B0(D_L20_001DF178) * 0.5f + 0.5f);
    nb = func_0038DAB8(D_L20_001DF178, func_003824E0(D_L20_001DF17C, D_L20_001DF180) * 0.017453292f * 0.020000001f);
    pf = *(f32 *)p;
    D_L20_001DF178 = nb;
    func_003D9508(a0 + 0x10, 0x43, col, 1, 2.25f, -0.1f, pf);
    func_003D9508(a0 + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -*(f32 *)(p + 4));
    func_003D9508(a0 + 0x10, 0x4B, 0x7FFFFFFF, 3, 2.0f, 0.025f, -*(f32 *)p);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(d, D_L20_001E2E00, a0 + 0x10);
        func_0038D890(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, d, *(f32 *)(p + 0xD10 + i * 4));
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) + 0.03f;
        if (*(f32 *)(p + 0x2C) > 2.5f) {
            *(f32 *)(p + 0x2C) = 2.5f;
        }
        func_0038CF68(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, *(f32 *)(p + 0x2C));
        vec_add_ab(e, p + 0xC50 + i * 0x10, a0 + 0x10);
        *(u128_t *)g = *(u128_t *)(a0 + 0x10);
        func_L01_0040A8C0((u128_t *)e, (u128_t *)g, 0x12, 1, D_L20_001DF188, D_L20_001DF188, D_L20_001DF18C, D_L20_001DF18C, D_L20_001DF184, 3.0f, *(f32 *)(p + 0xD40));
    }
    *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) - func_003824E0(0.025f, 0.035f);
    if (*(f32 *)(p + 0xD40) <= -8.0f) {
        *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) + 8.0f;
    }
}
/* localdecomp:end func_L20_003E7A70 */

/* localdecomp:start func_L20_003E7D00 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E7D00;

typedef struct {
    f32 f0;                     /* 0x000 */
    f32 f4;                     /* 0x004 */
    u8 pad8[0xC - 0x8];
    f32 fC;                     /* 0x00C */
    u8 pad10[0x14 - 0x10];
    s16 h14;                    /* 0x014 */
    s16 h16;                    /* 0x016 */
    s16 h18;                    /* 0x018 */
    s16 h1A;                    /* 0x01A */
    s32 i1C;                    /* 0x01C */
    s16 timer;                  /* 0x020 */
    s16 h22;                    /* 0x022 */
    u8 pad24[0x2C - 0x24];
    f32 f2C;                    /* 0x02C */
    u8 pad30[0xC50 - 0x30];
    V4_003E7D00 q[12];          /* 0xC50 */
    f32 r[12];                  /* 0xD10 */
} V_003E7D00;

typedef struct {
    u8 pad0[0x80];
    f32 x;                      /* 0x80 */
    f32 y;                      /* 0x84 */
} G_003E7D00;

extern void func_003C2880(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern u8 *func_L20_003EB388_003E7D00(void *, void *, f32 *, f32, s32);
extern void func_L20_003E6378(void *);
extern s32 func_0038CB00(void *);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_00382538(void);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_00382580(void *, f32, f32);
extern u8 *func_L01_004735F0(void *, void *, s32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L20_003E6D30(u8 *m);
extern void func_L20_003E6F88(u8 *);
extern void func_L20_003E7988(u8 *p);
extern void func_L20_003E7A70(u8 *a0);
extern s32 D_L20_001DFD40;
extern G_003E7D00 D_001A4BE0_003E7D00;
__asm__(".extern D_L20_001E2E00, 16");
extern s32 D_L20_001DF164;
__asm__(".extern D_L20_001DF164, 4");

void func_L20_003E7D00(u8 *p) {
    V_003E7D00 *v = *(V_003E7D00 **)(p + 0x68);
    V4_003E7D00 pos;
    V4_003E7D00 dir;
    V4_003E7D00 a;
    u8 *e;
    s32 i;
    s32 j;
    s32 k;

    *(u16 *)(p + 0x96) += 1;
    if (*(u16 *)(p + 0x96) >= 0x7E) {
        func_003C2880(p);
        return;
    }
    if ((D_L20_001DFD40 & 7) == (((s32)p >> 8) & 7)) {
        pos = *(V4_003E7D00 *)(p + 0x10);
        a.x = func_0038D098(func_0038DAB8(func_0038D160(D_001A4BE0_003E7D00.x - *(f32 *)(p + 0x10),
                                                        D_001A4BE0_003E7D00.y - *(f32 *)(p + 0x14)),
                                          func_L01_00443A18(5.0f, 25.0f) * 0.017453292f));
        a.y = func_0038D0B0(func_0038DAB8(func_0038D160(D_001A4BE0_003E7D00.x - *(f32 *)(p + 0x10),
                                                        D_001A4BE0_003E7D00.y - *(f32 *)(p + 0x14)),
                                          func_L01_00443A18(5.0f, 25.0f) * 0.017453292f));
        a.z = 0.0f;
        func_0038CF68(&dir, &a, func_003824E0(10.0f, 15.0f) * 0.020000001f);
        func_L01_004AAC98(0x14, 0, p, 0x1AFD);
        func_L20_003EB388_003E7D00(p, &pos, &dir.x, 45.0f, 0);
    }
    v->f0 = func_0038DAB8(v->f0, 0.034906588f);
    v->f4 = func_0038DAB8(v->f4, 0.10471976f);
    switch (p[0x20]) {
    case 0:
        for (i = 0; i < 12; i++) {
            v->r[i] = func_003824E0(0.017453294f, 0.05235988f);
            v->f2C = 2.0f;
            pos.x = func_0038D098(*(f32 *)(p + 0xF8));
            pos.y = func_0038D0B0(*(f32 *)(p + 0xF8));
            pos.z = 0.0f;
            vec_sub_ba(&dir, ((f32 *)&D_L20_001E2E00), p + 0x10);
            func_0038CF68(&dir, &dir, 1.0f);
            func_0038CE90(&v->q[i], &pos, &dir);
            func_0038CF68(&v->q[i], &v->q[i], v->f2C);
            func_0038D890(&v->q[i], &v->q[i], &dir, func_00382538());
        }
        func_L20_003E6378(p);
        v->timer = (v->i1C * 5 + 2) / 6;
        p[0x20] = 2;
        v->fC = 2.5f;
        v->h18 = 1;
        v->h1A = 1;
        break;
    case 2:
        if (func_0038CB00(&v->timer)) {
            p[0x20] = 3;
            v->timer = (v->h14 * 5 + 2) / 6;
            func_L20_003E6378(p);
        }
        break;
    case 3:
        if (func_0038CB00(&v->timer)) {
            if (v->h16 != 0) {
                p[0x20] = 2;
                v->timer = 4;
            } else {
                v->timer = 4;
            }
        } else if (v->h22 == 0) {
            func_L20_003E6378(p);
        }
        break;
    }
    for (j = 0; j < 1; j++) {
        vu0_q qx, qy, qd;

        func_00382580(&pos, 0.025f, 0.15f);
        __asm__("lqc2 %0, %1" : "=j"(qx) : "m"(*(vu0_v4 *)(p + 0x10)));
        vec_add_ba(&pos, &pos, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qy) : "m"(pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qd) : "j"(qx), "j"(qy));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(qd));
        func_0038CF68(&dir, &dir, 0.015000001f);
        e = func_L01_004735F0(&pos, &dir, 0xC, 3.0f);
        if (e != 0) {
            *(u32 *)(e + 4) = 0xFF2020FF;
        }
    }
    for (k = 0; k < 1; k++) {
        vu0_q qx, qy, qd;

        func_00382580(&pos, 0.025f, 0.15f);
        __asm__("lqc2 %0, %1" : "=j"(qx) : "m"(*(vu0_v4 *)(p + 0x10)));
        vec_add_ba(&pos, &pos, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qy) : "m"(pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qd) : "j"(qx), "j"(qy));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(qd));
        func_0038CF68(&dir, &dir, 0.015000001f);
        e = func_L01_004735F0(&pos, &dir, 0xC, 1.5f);
        if (e != 0) {
            *(u32 *)(e + 4) = 0x7FFFFFFF;
        }
    }
    func_L01_00404A10(func_L20_003E7988, p);
    func_L01_00404A10(func_L20_003E7A70, p);
    if (v->h22 != 0) {
        func_L20_003E6D30(p);
        if (D_L20_001DF164 < v->h22) {
            func_L01_00404A10(func_L20_003E6F88, p);
        }
    }
}
/* localdecomp:end func_L20_003E7D00 */

/* localdecomp:start func_L20_003E8288 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_003E8288;
extern s32 D_L20_001DF190;
__asm__(".extern D_L20_001DF190, 4");
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L20_001D7C50[4];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

/* the same shape as func_L36_0037CF50 */
void func_L20_003E8288(u8 *a0, f32 size) {
    Q_003E8288 q;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 p;
    vu0_v4 z;
    vu0_v4 c;               /* c, t, w: unused here; func_L36_0037CF50 uses them in its */
    vu0_v4 t;               /* shrink branch, and retail's frame keeps their 0x30 bytes */
    vu0_v4 w;
    s32 i;
    s32 n;

    func_003D93B0(&q, D_L20_001DF190, 1, 0x80);
    q.gif = (0x8000L << 24) | 0x4A;
    p = *(vu0_v4 *)(a0 + 0x10);
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    vec_sub_ab(&d, (vu0_v4 *)D_L20_001E2E80, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE90(&e, &d, &D_001A4EC0);
    func_0038CF68(&e, &e, 1.0f);
    func_0038CE90(&f, &e, &d);
    func_0038CE20(&z, &d, 0.05f);
    vec_add_ab(&p, &p, &z);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L20_001D7C50[i], size);
        func_0038D028(&q.v[i], &q.v[i], &d);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    for (n = 0; n < 4; n++) {
        func_00389478(&q.v[n], &q.uv[n][0], &q.uv[n][1]);
    }
    func_003D93B0(&q, -1, 1, 0x80);
    q.gif = (0x8000L << 22) | 0x54;
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003E8288 */

/* localdecomp:start func_L20_003E84B0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E84B0;
typedef struct {
    u8 pad0[0x8];
    s32 i8;                 /* 0x08 */
    u8 padC[0x22 - 0xC];
    s16 count;              /* 0x22 */
    s32 color;              /* 0x24 */
    u8 idx[4];              /* 0x28 */
    u8 pad2C[4];
    struct {
        V4_003E84B0 pos[32];    /* +0x000 */
        V4_003E84B0 vel[32];    /* +0x200 */
        V4_003E84B0 g[8][4];    /* +0x400 */
        V4_003E84B0 rot;        /* +0x600 */
    } set[2];               /* 0x30, 0x640 */
} S_003E84B0;

extern s32 D_L20_001DF200;
__asm__(".extern D_L20_001DF200, 4");
extern s32 D_L20_001DF204;
__asm__(".extern D_L20_001DF204, 4");
extern f32 D_L20_001DF1D8;
__asm__(".extern D_L20_001DF1D8, 4");
extern f32 D_L20_001DF1DC;
__asm__(".extern D_L20_001DF1DC, 4");
extern f32 D_L20_001DF1F0;
__asm__(".extern D_L20_001DF1F0, 4");
extern s32 D_L20_001DF1F8;
__asm__(".extern D_L20_001DF1F8, 4");
extern s32 D_L20_001DF1FC;
__asm__(".extern D_L20_001DF1FC, 4");
extern s32 D_L20_001DF1E4;
__asm__(".extern D_L20_001DF1E4, 4");
extern s32 D_L20_001DF1E8;
__asm__(".extern D_L20_001DF1E8, 4");
extern u8 D_L20_001E2E00[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_00382468(s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void vcopy_003E84B0(V4_003E84B0 *d, V4_003E84B0 *s)
{
    *(vu0_q *)d = *(vu0_q *)s;
}

/* the two-set version of func_L11_003AF6B8 */
void func_L20_003E84B0(u8 *p) {
    V4_003E84B0 a[32];
    V4_003E84B0 b[32];
    S_003E84B0 *s;
    s32 n1;
    s32 n2;
    s32 r;
    f32 h;
    f32 f;
    s32 i;
    s32 j0;
    s32 j1;
    s32 col0;
    s32 row0;
    s32 col1;
    s32 row1;
    s32 pt0;
    s32 br0;
    s32 pt1;
    s32 br1;

    n1 = (D_L20_001DF200 * 5 + 2) / 6;
    n2 = (D_L20_001DF204 * 5 + 2) / 6;
    *(f32 *)(p + 0x1C) = 1.0f;
    s = *(S_003E84B0 **)(p + 0x68);
    r = func_00382498(n1, n2);
    s->i8 = (s16)r;
    s->count = r;
    h = func_003824E0(4.0f, 5.0f);
    for (i = 0; i < 32; i++) {
        f = (f32)i / 31.0f;
        f = (0.5f - f) * h;
        if (i < 3 || i > 28) {
            qzero(&a[i]);
            qzero(&b[i]);
        } else {
            func_L01_00443B88(&a[i], 0.0f, D_L20_001DF1D8);
            func_L01_00443B88(&b[i], 0.0f, D_L20_001DF1DC * 0.020000001f);
        }
        a[i].w = 1.0f;
        a[i].y += f;
    }
    for (j0 = 0; j0 < 32; j0++) {
        V4_003E84B0 t;

        if (j0 == 0 || j0 == 31) {
            vcopy_003E84B0(&s->set[0].pos[j0], &a[j0]);
            vcopy_003E84B0(&s->set[0].vel[j0], &b[j0]);
        } else {
            vec_add_ab(&t, &a[j0 - 1], &a[j0]);
            vec_add_ab(&t, &t, &a[j0 + 1]);
            func_0038CE20(&s->set[0].pos[j0], &t, 0.333f);
            vec_add_ba(&t, &b[j0 - 1], &b[j0]);
            vec_add_ba(&t, &t, &b[j0 + 1]);
            func_0038CE20(&s->set[0].vel[j0], &t, 0.333f);
        }
    }
    for (j1 = 0; j1 < 32; j1++) {
        V4_003E84B0 t;

        if (j1 == 0 || j1 == 31) {
            vcopy_003E84B0(&s->set[1].pos[j1], &a[j1]);
            vcopy_003E84B0(&s->set[1].vel[j1], &b[j1]);
        } else {
            vec_add_ab(&t, &a[j1 - 1], &a[j1]);
            vec_add_ab(&t, &t, &a[j1 + 1]);
            func_0038CE20(&s->set[1].pos[j1], &t, 0.333f);
            vec_add_ba(&t, &b[j1 - 1], &b[j1]);
            vec_add_ba(&t, &t, &b[j1 + 1]);
            func_0038CE20(&s->set[1].vel[j1], &t, 0.333f);
        }
    }
    {
        /* scratch vectors of the grids and of set 0's bolt (C++ block scope: freed for set 1's) */
        V4_003E84B0 t;
        V4_003E84B0 u;

        {
            for (col0 = 0; col0 < 4; col0++) {
                s32 k;

                func_L01_00443B88(&t, D_L20_001DF1D8, D_L20_001DF1D8);
                k = (s32)func_003824E0((f32)col0 * 6.0f, (f32)(col0 + 1) * 6.0f) + 4;
                s->idx[col0] = k;
                vcopy_003E84B0(&s->set[0].g[0][col0], &s->set[0].pos[k]);
                vcopy_003E84B0(&s->set[0].g[4][col0], &s->set[0].vel[k]);
                for (row0 = 1; row0 < 4; row0++) {
                    func_L01_00443B88(&u, 0.1f, 0.1f);
                    func_L01_00443B88(&s->set[0].g[row0 + 4][col0], 0.0f, D_L20_001DF1DC * 0.020000001f);
                    vec_add_ab(&s->set[0].g[row0][col0], &s->set[0].g[row0 - 1][col0], &t);
                    vec_add_ab(&s->set[0].g[row0][col0], &s->set[0].g[row0][col0], &u);
                }
            }
            for (col1 = 0; col1 < 4; col1++) {
                s32 k;

                func_L01_00443B88(&t, D_L20_001DF1D8, D_L20_001DF1D8);
                k = (s32)func_003824E0((f32)col1 * 6.0f, (f32)(col1 + 1) * 6.0f) + 4;
                s->idx[col1] = k;
                vcopy_003E84B0(&s->set[1].g[0][col1], &s->set[1].pos[k]);
                vcopy_003E84B0(&s->set[1].g[4][col1], &s->set[1].vel[k]);
                for (row1 = 1; row1 < 4; row1++) {
                    func_L01_00443B88(&u, 0.1f, 0.1f);
                    func_L01_00443B88(&s->set[1].g[row1 + 4][col1], 0.0f, D_L20_001DF1DC * 0.020000001f);
                    vec_add_ab(&s->set[1].g[row1][col1], &s->set[1].g[row1 - 1][col1], &t);
                    vec_add_ab(&s->set[1].g[row1][col1], &s->set[1].g[row1][col1], &u);
                }
            }
        }
        if (func_0038CF38((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00) >= 4.0f) {
            V4_003E84B0 m[4];

            s->set[0].rot.z = *(f32 *)(p + 0xF8);
            s->set[0].rot.y = *(f32 *)(p + 0xF4);
            s->set[0].rot.y += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
            s->set[0].rot.x = func_00382538();
            func_0038D328(m, &s->set[0].rot);
            m[3] = *(V4_003E84B0 *)(p + 0x10);
            for (pt0 = 0; pt0 < 32; pt0 += 8) {
                s32 color;

                func_0038D028(&t, &s->set[0].pos[pt0], m);
                vcopy_003E84B0(&u, &s->set[0].vel[pt0]);
                u.w = D_L20_001DF1F0;
                color = func_00382468(2) ? D_L20_001DF1F8 : D_L20_001DF1FC;
                func_L01_00463378(&t, &u, &u, D_L20_001DF1E4, D_L20_001DF1E8, pt0 >> 1, 15,
                                  ((func_00382468(10) + 20) * 5 + 2) / 6, color);
            }
            for (br0 = 0; br0 < 2; br0++) {
                s32 color;

                func_0038D028(&t, &s->set[0].g[3][br0], m);
                vcopy_003E84B0(&u, &s->set[0].g[7][br0]);
                u.w = D_L20_001DF1F0;
                color = func_00382468(2) ? D_L20_001DF1F8 : D_L20_001DF1FC;   /* unused: branches pass D_L20_001DF1FC */
                func_L01_00463378(&t, &u, &u, D_L20_001DF1E4, D_L20_001DF1E8, s->idx[br0] >> 1, 15,
                                  ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DF1FC);
            }
        }
    }
    if (func_0038CF38((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00) >= 4.0f) {
        V4_003E84B0 m[4];
        V4_003E84B0 t;
        V4_003E84B0 u;

        s->set[1].rot.z = *(f32 *)(p + 0xF8);
        s->set[1].rot.y = *(f32 *)(p + 0xF4);
        s->set[1].rot.y += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
        s->set[1].rot.x = func_00382538();
        func_0038D328(m, &s->set[1].rot);
        m[3] = *(V4_003E84B0 *)(p + 0x10);
        for (pt1 = 0; pt1 < 32; pt1 += 8) {
            s32 color;

            func_0038D028(&t, &s->set[1].pos[pt1], m);
            vcopy_003E84B0(&u, &s->set[1].vel[pt1]);
            u.w = D_L20_001DF1F0;
            color = func_00382468(2) ? D_L20_001DF1F8 : D_L20_001DF1FC;
            func_L01_00463378(&t, &u, &u, D_L20_001DF1E4, D_L20_001DF1E8, pt1 >> 1, 15,
                              ((func_00382468(10) + 20) * 5 + 2) / 6, color);
        }
        for (br1 = 0; br1 < 2; br1++) {
            s32 color;

            func_0038D028(&t, &s->set[1].g[3][br1], m);
            vcopy_003E84B0(&u, &s->set[1].g[7][br1]);
            u.w = D_L20_001DF1F0;
            color = func_00382468(2) ? D_L20_001DF1F8 : D_L20_001DF1FC;   /* unused: branches pass D_L20_001DF1FC */
            func_L01_00463378(&t, &u, &u, D_L20_001DF1E4, D_L20_001DF1E8, s->idx[br1] >> 1, 15,
                              ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DF1FC);
        }
    }
}
/* localdecomp:end func_L20_003E84B0 */

/* localdecomp:start func_L20_003E8E68 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E8E68;
typedef struct {
    u8 pad0[0x8];
    s32 i8;                 /* 0x08 */
    u8 padC[0x22 - 0xC];
    s16 count;              /* 0x22 */
    s32 color;              /* 0x24 */
    u8 idx[4];              /* 0x28 */
    u8 pad2C[4];
    struct {
        V4_003E8E68 v[64];      /* +0x000: 4..26 positions, 36..58 velocities */
        V4_003E8E68 sel[4];     /* +0x400 */
        V4_003E8E68 g[7][4];    /* +0x440 */
        u8 pad600[0x10];
    } set[2];               /* 0x30, 0x640 */
} S_003E8E68;

extern s32 func_0038DBD8(s32, s32, f32);
extern s32 D_L20_001DF208;
__asm__(".extern D_L20_001DF208, 4");
extern s32 D_L20_001DF20C;
__asm__(".extern D_L20_001DF20C, 4");
extern s32 D_L20_001DF1AC;
__asm__(".extern D_L20_001DF1AC, 4");
extern s32 D_L20_001DF1B0;
__asm__(".extern D_L20_001DF1B0, 4");
extern s32 D_L20_001DF1B4;
__asm__(".extern D_L20_001DF1B4, 4");

static __inline__ void step_003E8E68(S_003E8E68 *s, s32 n) {
    if (s->count != 0) {
        s32 k;
        s32 i;
        s32 j;

        s->count--;
        for (k = 0; k < 23; k++) {
            vec_add_ab(&s->set[n].v[k + 4], &s->set[n].v[k + 4], &s->set[n].v[k + 36]);
        }
        for (i = 0; i < 4.0f; i++) {
            /* column i of the grid, addressed from the block base as an integer */
            V4_003E8E68 *c = (V4_003E8E68 *)(i * 16 + (u32)s) + n * 0x61;
            for (k = 0; k < 3; k++) {
                vec_add_ab(&c[0x47 + k * 4], &c[0x47 + k * 4], &c[0x57 + k * 4]);
            }
        }
        for (j = 0; j < 4; j++) {
            s->set[n].sel[j] = ((V4_003E8E68 *)(s->idx[j] * 16 + (u32)s) + n * 0x61)[3];
        }
    }
}

void func_L20_003E8E68(u8 *m) {
    S_003E8E68 *s = *(S_003E8E68 **)(m + 0x68);

    step_003E8E68(s, 0);
    if (D_L20_001DF208 < s->count) {
        s->color = func_0038DBD8(D_L20_001DF1B0, D_L20_001DF1AC,
                                 (f32)(s->count - D_L20_001DF208) / (f32)(s->i8 - D_L20_001DF208));
    } else if (D_L20_001DF20C < s->count) {
        s->color = func_0038DBD8(D_L20_001DF1B4, D_L20_001DF1B0,
                                 (f32)(s->count - D_L20_001DF20C) / (f32)(D_L20_001DF208 - D_L20_001DF20C));
    } else {
        s->color = 0;
    }
    step_003E8E68(s, 1);
}
/* localdecomp:end func_L20_003E8E68 */
