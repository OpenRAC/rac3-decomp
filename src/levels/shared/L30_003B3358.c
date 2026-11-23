#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003B3358;

/* localdecomp:start func_L30_003B3358 */
#include "vu0.h"

extern s32 D_L30_001DEC5C;
extern s32 D_L30_001DEC60;
extern s32 D_L30_001DEC64;
extern s32 D_L30_001DEC68;
extern s32 D_L30_001DEC6C;
extern s32 D_L30_001DEC70;
extern f32 D_L30_001DEC74;
extern s32 D_L30_001DEC78;
extern s32 D_L30_001DEC7C;
extern s32 D_L30_001DEC80;
extern s32 D_L30_001DEC84;
extern s32 D_L30_001DEC88;
extern f32 D_L30_001DEC8C;
extern f32 D_L30_001DEC90;
extern s32 D_L30_001DEC94;
extern s32 D_L30_001DEC98;
extern s32 D_L30_001DEC9C;
extern f32 D_L30_001DECA0;
extern f32 D_L30_001DECA4;
__asm__(".extern D_L30_001DEC5C, 4");
__asm__(".extern D_L30_001DEC60, 4");
__asm__(".extern D_L30_001DEC64, 4");
__asm__(".extern D_L30_001DEC68, 4");
__asm__(".extern D_L30_001DEC6C, 4");
__asm__(".extern D_L30_001DEC70, 4");
__asm__(".extern D_L30_001DEC74, 4");
__asm__(".extern D_L30_001DEC78, 4");
__asm__(".extern D_L30_001DEC7C, 4");
__asm__(".extern D_L30_001DEC80, 4");
__asm__(".extern D_L30_001DEC84, 4");
__asm__(".extern D_L30_001DEC88, 4");
__asm__(".extern D_L30_001DEC8C, 4");
__asm__(".extern D_L30_001DEC90, 4");
__asm__(".extern D_L30_001DEC94, 4");
__asm__(".extern D_L30_001DEC98, 4");
__asm__(".extern D_L30_001DEC9C, 4");
__asm__(".extern D_L30_001DECA0, 4");
__asm__(".extern D_L30_001DECA4, 4");
extern u8 *D_L30_0021F098[];


extern void func_00382580(void *, f32, f32);
extern u8 *func_L30_004437E8(void *, s32, s32, s32, f32, f32);

void func_L30_003B3358(void *pos) {
    V_003B3358 v;
    u8 *p;
    s32 i;

    for (i = 0; i < D_L30_001DEC94; i++) {
        func_00382580(&v, D_L30_001DECA0, D_L30_001DECA0 * 0.5f);
        v.y = -fabs_asm(v.y);
        vec_add_ba(&v, &v, pos);
        p = func_L30_004437E8(&v, D_L30_001DEC98, D_L30_001DEC9C, (D_L30_001DEC78 * 5 + 2) / 6,
                              D_L30_001DECA4, D_L30_001DECA4 * 0.4f);
        if (p != 0) {
            p[2] = D_L30_0021F098[0x5B][2];
        }
    }
    func_L30_004437E8(pos, D_L30_001DEC5C, D_L30_001DEC68, (D_L30_001DEC78 * 5 + 2) / 6,
                      D_L30_001DEC74 * 0.65f, D_L30_001DEC74 * 0.1f);
    p = func_L30_004437E8(pos, D_L30_001DEC60, D_L30_001DEC6C, (D_L30_001DEC78 * 5 + 2) / 6,
                          D_L30_001DEC74 * 1.75f, D_L30_001DEC74 * 0.4f);
    if (p != 0) {
        p[2] = D_L30_0021F098[0x61][2];
    }
    func_L30_004437E8(pos, D_L30_001DEC64, D_L30_001DEC70, (D_L30_001DEC78 * 5 + 2) / 6,
                      D_L30_001DEC74 * 1.35f, D_L30_001DEC74 * 0.15f);
    p = func_L30_004437E8(pos, D_L30_001DEC80, D_L30_001DEC88, (D_L30_001DEC7C * 5 + 2) / 6,
                          D_L30_001DEC8C, D_L30_001DEC90);
    if (p != 0) {
        p[2] = D_L30_0021F098[0x5B][2];
    }
    p = func_L30_004437E8(pos, D_L30_001DEC84, D_L30_001DEC88, (D_L30_001DEC7C * 5 + 2) / 6,
                          D_L30_001DEC8C * 0.7f, D_L30_001DEC90);
    if (p != 0) {
        p[2] = D_L30_0021F098[0x5C][4];
    }
}
/* localdecomp:end func_L30_003B3358 */

/* localdecomp:start func_L30_003B3600 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B3600;
typedef struct {
    V4_003B3600 v[4];
    s32 rgba[4];
    f32 uv[8];
    u8 gif[0x20];
} __attribute__((aligned(16))) P_003B3600;
typedef struct { f32 mtx[3][4]; } C_003B3600;
extern C_003B3600 D_L30_001E2100;
extern V4_003B3600 D_001D7AD0[4];
extern void func_003D93B0(void *, s32, s32, long);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L30_003B3600(V4_003B3600 *pos, s32 a1, s32 rgba, s32 a3,
                       f32 size, f32 sy, f32 sz, f32 dx, f32 angle, s32 axis) {
    P_003B3600 pkt;
    V4_003B3600 m[4];
    V4_003B3600 off;
    s32 i;

    func_003D93B0(&pkt, a1, a3, 0x80);
    pkt.rgba[3] = rgba;
    pkt.rgba[2] = rgba;
    pkt.rgba[1] = rgba;
    pkt.rgba[0] = rgba;
    pkt.uv[0] = 0.0f;
    pkt.uv[1] = 0.0f;
    pkt.uv[2] = 0.0f;
    pkt.uv[3] = 1.0f;
    pkt.uv[4] = 1.0f;
    pkt.uv[5] = 0.0f;
    pkt.uv[6] = 1.0f;
    pkt.uv[7] = 1.0f;
    m[3] = *pos;
    m[0] = *(V4_003B3600 *)D_L30_001E2100.mtx[2];
    m[1] = *(V4_003B3600 *)D_L30_001E2100.mtx[0];
    m[2] = *(V4_003B3600 *)D_L30_001E2100.mtx[1];
    func_0038CE20(&off, &m[0], dx);
    vec_add_ab(&m[3], &m[3], &off);
    if (angle != 0.0f) {
        V4_003B3600 ax = { angle, 0.0f, 0.0f, 0.0f };
        V4_003B3600 ay = { 0.0f, angle, 0.0f, 0.0f };
        V4_003B3600 az = { 0.0f, 0.0f, angle, 0.0f };
        V4_003B3600 rot;
        V4_003B3600 r[3];

        switch (axis) {
        case 0:
            rot = ax;
            break;
        case 1:
            rot = ay;
            break;
        case 2:
            rot = az;
            break;
        }
        func_0038D308(r, &rot);
        func_0038D5F0(m, m, r);
    }
    func_0038CE20(&m[1], &m[1], sy);
    func_0038CE20(&m[2], &m[2], sz);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&pkt.v[i], &D_001D7AD0[i], size);
        func_0038D028(&pkt.v[i], &pkt.v[i], m);
    }
    func_003D2DA0(&pkt, 0, 0);
}
/* localdecomp:end func_L30_003B3600 */

/* localdecomp:start func_L30_003B3810 */
typedef struct {
    s16 h0;
    u8 pad2[0x2];
    f32 f4;
    f32 f8;
    u8 bC;
    u8 bD;
    u8 bE;
} P_003B3810;

extern s32 D_L30_001DEC28;
__asm__(".extern D_L30_001DEC28, 4");
extern u8 D_L30_001DECA8;
__asm__(".extern D_L30_001DECA8, 1");
extern s32 D_L30_001DECAC;
__asm__(".extern D_L30_001DECAC, 4");
extern s32 D_L30_001DECB0;
__asm__(".extern D_L30_001DECB0, 4");
extern s32 D_L30_001DECB4;
__asm__(".extern D_L30_001DECB4, 4");
extern f32 D_L30_001DECB8;
__asm__(".extern D_L30_001DECB8, 4");
extern f32 D_L30_001DECBC;
__asm__(".extern D_L30_001DECBC, 4");
extern f32 D_L30_001DECC0;
__asm__(".extern D_L30_001DECC0, 4");
extern f32 D_L30_001DECC4;
__asm__(".extern D_L30_001DECC4, 4");
extern u8 D_L30_001DECC8;
__asm__(".extern D_L30_001DECC8, 1");
extern s32 D_L30_001DECCC;
__asm__(".extern D_L30_001DECCC, 4");
extern f32 D_L30_001DECD0;
__asm__(".extern D_L30_001DECD0, 4");
extern f32 D_L30_001DECD4;
__asm__(".extern D_L30_001DECD4, 4");
extern u8 D_L30_001DECD8;
__asm__(".extern D_L30_001DECD8, 1");
extern u8 D_L30_001DECD9;
__asm__(".extern D_L30_001DECD9, 1");
extern s32 D_L30_001DECDC;
__asm__(".extern D_L30_001DECDC, 4");
extern f32 D_L30_001DECE0;
__asm__(".extern D_L30_001DECE0, 4");
extern f32 D_L30_001DECE4;
__asm__(".extern D_L30_001DECE4, 4");
extern f32 D_L30_001DECE8;
__asm__(".extern D_L30_001DECE8, 4");
extern void func_L30_003B3600(V4_003B3600 *pos, s32 a1, s32 rgba, s32 a3,
                              f32 size, f32 sy, f32 sz, f32 dx, f32 angle, s32 axis);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038DB48(f32);

void func_L30_003B3810(u8 *a0) {
    P_003B3810 *p = *(P_003B3810 **)(a0 + 0x68);
    s32 i;
    s32 c;
    f32 y;

    c = func_0038DBD8(D_L30_001DECB0, D_L30_001DECB4, (f32)p->h0 / (f32)D_L30_001DEC28) | (p->bC << 24);
    for (i = 0; D_L30_001DECA8 != 0 && i < D_L30_001DECAC; i++) {
        y = D_L30_001DECB8 - p->f8 * D_L30_001DECC0;
        func_L30_003B3600((V4_003B3600 *)(a0 + 0x10), 0x3D, c, 1, y, 1.0f, D_L30_001DECBC, 0.0f, func_0038DB48(p->f4 * D_L30_001DECC4 + (f32)i), 2);
    }
    c = (p->bD << 24) | D_L30_001DECCC;
    y = D_L30_001DECD0 - p->f8 * D_L30_001DECD4;
    if (D_L30_001DECC8 != 0) {
        func_L30_003B3600((V4_003B3600 *)(a0 + 0x10), 0x39, c, 1, y, 1.0f, 1.0f, 0.0f, p->f4, 0);
    }
    c = (p->bE << 24) | D_L30_001DECDC;
    y = D_L30_001DECE0 - p->f8 * D_L30_001DECE4;
    if (D_L30_001DECD8 != 0) {
        func_L30_003B3600((V4_003B3600 *)(a0 + 0x10), 0x44, c, 1, y, 1.0f, 1.0f, 0.0f, p->f4 * D_L30_001DECE8, 0);
    }
    if (D_L30_001DECD9 != 0) {
        func_L30_003B3600((V4_003B3600 *)(a0 + 0x10), 0x44, c, 1, y, 1.0f, 1.0f, 0.0f, p->f4 * D_L30_001DECE8, 2);
    }
}
/* localdecomp:end func_L30_003B3810 */

/* localdecomp:start func_L30_003B3A30 */
#include "vu0.h"
extern u8 *D_L30_0021F098[];
extern void func_00382580(void *, f32, f32);
extern s32 D_L30_001DECF4;
__asm__(".extern D_L30_001DECF4, 4");
extern s32 D_L30_001DECF8;
__asm__(".extern D_L30_001DECF8, 4");
extern f32 D_L30_001DECFC;
__asm__(".extern D_L30_001DECFC, 4");
extern f32 D_L30_001DED00;
__asm__(".extern D_L30_001DED00, 4");
extern f32 D_L30_001DED04;
__asm__(".extern D_L30_001DED04, 4");
extern s32 func_00382498(s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00470C78(u8 *position, s32 life, s32 colour, s32 a3, s32 spin, void *velocity, s32 t2,
                             s32 t3, s16 arg8, s32 arg9, f32 size, f32 start_size);

void func_L30_003B3A30(u8 *moby, s32 n) {
    V_003B3358 a;
    V_003B3358 b;
    V_003B3358 d;
    V_003B3358 c;
    vu0_q qb, qc, qr;
    u8 *p;
    s32 r;
    s32 i;

    for (i = 0; i < n; i++) {
        r = func_00382498(D_L30_001DECF4 - 5, D_L30_001DECF4);
        func_00382580(&a, D_L30_001DECFC * 0.7f, D_L30_001DECFC);
        a.y = -fabs_asm(a.y);
        func_00382580(&b, D_L30_001DED00 * 0.7f, D_L30_001DED00);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %3\n\tsqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(a), "=m"(c) : "m"(a), "m"(*(vu0_v4 *)(moby + 0x10)) : "vf1", "vf2");
        __asm__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=j"(qb), "=j"(qc) : "m"(b), "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qb), "j"(qc));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qr));
        vec_sub_ab(&d, &b, &a);
        func_0038CF68(&d, &d, func_0038CEA8(&d) / (f32)r * 1.3f);
        p = func_L01_00470C78((u8 *)&a, (r * 5 + 2) / 6, D_L30_001DECF8, 0, 1, &d, 0, 0, 6, 0,
                              D_L30_001DED04 * 0.25f, D_L30_001DED04);
        if (p != 0) {
            p[2] = D_L30_0021F098[0x5C][1];
        }
    }
}
/* localdecomp:end func_L30_003B3A30 */

/* localdecomp:start func_L30_003B3BD0 */
#include "vu0.h"
extern u8 *D_L30_0021F098[];
extern void func_00382580(void *, f32, f32);
extern s32 D_L30_001DED0C;
__asm__(".extern D_L30_001DED0C, 4");
extern s32 D_L30_001DED10;
__asm__(".extern D_L30_001DED10, 4");
extern s32 D_L30_001DED14;
__asm__(".extern D_L30_001DED14, 4");
extern s32 D_L30_001DED18;
__asm__(".extern D_L30_001DED18, 4");
extern f32 D_L30_001DED1C;
__asm__(".extern D_L30_001DED1C, 4");
extern f32 D_L30_001DED20;
__asm__(".extern D_L30_001DED20, 4");
extern f32 D_L30_001DED24;
__asm__(".extern D_L30_001DED24, 4");
extern f32 D_L30_001DED28;
__asm__(".extern D_L30_001DED28, 4");
extern f32 D_L30_001DED2C;
__asm__(".extern D_L30_001DED2C, 4");
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L30_003B3BD0(u8 *moby, s32 n) {
    V_003B3358 a;
    V_003B3358 b;
    u8 *p;
    s32 life;
    s32 i;

    for (i = 0; i < n; i++) {
        func_00382580(&a, 0.1f, 1.5f);
        func_0038CF68(&b, &a, func_003824E0(D_L30_001DED1C * 0.7f, D_L30_001DED1C) * 0.020000001f);  /* 0x3CA3D70B: PAL's 50 Hz frame step (NTSC-U's twin has 1/60) */
        b.y = -fabs_asm(b.y);
        if (func_00382468(3)) {
            b.z = fabs_asm(b.z);
        }
        func_00382580(&a, 0.1f, 1.5f);
        vec_add_ab(&a, &a, moby + 0x10);
        life = (func_00382498(D_L30_001DED14, D_L30_001DED18) * 5 + 2) / 6;
        p = func_L01_00474078(&a, &b, life, D_L30_001DED20, D_L30_001DED24, D_L30_001DED28, D_L30_001DED2C,
                              D_L30_001DED0C, D_L30_001DED10,
                              (func_00382498(D_L30_001DED14 - 5, D_L30_001DED14) * 5 + 2) / 6, 0);
        if (p != 0) {
            p[2] = D_L30_0021F098[0x62][0];
        }
    }
}
/* localdecomp:end func_L30_003B3BD0 */

/* localdecomp:start func_L30_003B3D70 */
typedef struct {
    u8 p0[0x20];
    f32 x20;
    u8 p24[4];
    s32 x28;
    s32 x2C;
} S_003B3D70;
typedef struct {
    s16 h0;
    u8 p2[2];
    f32 f4;
    f32 f8;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} V_003B3D70;

__asm__(".extern D_L30_001DED08, 4");
__asm__(".extern D_L30_001DECF0, 4");
__asm__(".extern D_L30_001DED34, 4");
__asm__(".extern D_L30_001DED30, 4");
__asm__(".extern D_L30_001DEC28, 4");
__asm__(".extern D_L30_001DECEC, 4");
__asm__(".extern D_L30_001DED38, 4");
__asm__(".extern D_L30_001DED3C, 4");
extern s32 D_L30_001DED08;
extern s32 D_L30_001DECF0;
extern s32 D_L30_001DED34;
extern f32 D_L30_001DED30;
extern s32 D_L30_001DEC28;
extern f32 D_L30_001DECEC;
extern f32 D_L30_001DED38;
extern f32 D_L30_001DED3C;
extern S_003B3D70 D_L30_001E22C0;
extern void func_L30_003B3358(void *);
extern void func_L30_003B3BD0(u8 *, s32);
extern void func_L30_003B3A30(u8 *, s32);
extern void func_L30_003B3810();
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern s32 func_0038CB00(void *);
extern void func_003C2880(void *);

void func_L30_003B3D70(u8 *moby) {
    V_003B3D70 *v = *(V_003B3D70 **)(moby + 0x68);
    f32 h;
    f32 a;
    f32 b;

    switch (moby[0x20]) {
    case 0:
        func_L30_003B3358(moby + 0x10);
        func_L30_003B3BD0(moby, D_L30_001DED08);
        func_L30_003B3A30(moby, D_L30_001DECF0);
        D_L30_001E22C0.x20 = D_L30_001DED30;
        D_L30_001E22C0.x28 = (D_L30_001DED34 * 5 + 2) / 6;
        D_L30_001E22C0.x2C = 0;
        func_L01_004450F0(moby, 1, -1);
        v->h0 = (D_L30_001DEC28 * 5 + 2) / 6;
        break;
    case 1:
        h = v->h0;
        a = h / (h + 1.5f);
        b = h / (h + D_L30_001DECEC);
        v->f4 += D_L30_001DED38;
        v->f8 += D_L30_001DED3C;
        v->bC = v->bC * b;
        v->bD = v->bD * b;
        v->bE = v->bE * a;
        v->bF = v->bF * b;
        func_L01_00404A10(func_L30_003B3810, moby);
        if (func_0038CB00(v)) {
            func_L01_004450F0(moby, 2, -1);
        }
        break;
    case 2:
        func_003C2880(moby);
        break;
    }
}
/* localdecomp:end func_L30_003B3D70 */
