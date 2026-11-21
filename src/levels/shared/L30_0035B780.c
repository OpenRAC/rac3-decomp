#include "common.h"

/* localdecomp:start func_L30_0035B780 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L30_0035ADB8(void *);
extern s32 func_L01_00516FD8(s32, char *);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00517340(s32, s32, s32, s32, s32);
extern s32 func_L01_00516558(s32, f32 *, f32 *);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L30_0034CA78(void);
extern s32 func_L30_00358360(void *);
extern s32 func_0011B2E8();
extern char D_L30_001DDC68[];
extern char D_L30_001DDC70[];
extern char D_L30_001DDC78[];
extern char D_L30_001E1460[8];
extern char D_L30_001E1468[8];
extern char D_L30_001E1470[8];
extern char D_L30_001E1478[8];
extern f32 D_L30_001E1410;
__asm__(".extern D_L30_001E1410, 16");
extern f32 D_L30_001E1414;
__asm__(".extern D_L30_001E1414, 16");
extern f32 D_L30_001E1418;
__asm__(".extern D_L30_001E1418, 16");
extern f32 D_L30_001E141C;
__asm__(".extern D_L30_001E141C, 16");
extern f32 D_L30_001E1420;
__asm__(".extern D_L30_001E1420, 16");
extern f32 D_L30_001E1424;
__asm__(".extern D_L30_001E1424, 16");
typedef struct { u8 p0[0xE4]; s32 wE4; s32 wE8; u8 pEC[0x24]; s32 w110; s32 w114; s32 w118; s32 w11C; s32 w120; s32 w124; s32 w128; s32 w12C; } S_35B780;
typedef struct { u8 p0[0x1B04]; s32 w1B04; s32 w1B08; u8 p1B0C[0xD44]; s32 w2850; } G_35B780;
extern G_35B780 D_L30_001A4BE0[];
extern f32 D_L30_001DDAD8;
__asm__(".extern D_L30_001DDAD8, 4");
extern s32 D_L30_001DDB10;
__asm__(".extern D_L30_001DDB10, 4");
extern s32 D_L30_001DDB14;
__asm__(".extern D_L30_001DDB14, 4");
extern s32 D_L30_001DDB18;
__asm__(".extern D_L30_001DDB18, 4");
extern s32 D_L30_001DDB1C;
__asm__(".extern D_L30_001DDB1C, 4");
extern s32 D_L30_001DDB20;
__asm__(".extern D_L30_001DDB20, 4");
extern s32 D_L30_001DDB24;
__asm__(".extern D_L30_001DDB24, 4");
extern s32 D_L30_001DDB28;
__asm__(".extern D_L30_001DDB28, 4");
extern f32 D_L30_001DDB2C;
__asm__(".extern D_L30_001DDB2C, 4");
extern f32 D_L30_001DDB30;
__asm__(".extern D_L30_001DDB30, 4");
extern f32 D_L30_001DDB3C;
__asm__(".extern D_L30_001DDB3C, 4");
extern f32 D_L30_001DDB40;
__asm__(".extern D_L30_001DDB40, 4");
extern f32 D_L30_001DDB44;
__asm__(".extern D_L30_001DDB44, 4");
extern f32 D_L30_001DDB48;
__asm__(".extern D_L30_001DDB48, 4");
extern f32 D_L30_001DDB4C;
__asm__(".extern D_L30_001DDB4C, 4");
extern f32 D_L30_001DDB50;
__asm__(".extern D_L30_001DDB50, 4");
extern s32 D_L30_001DDB54;
__asm__(".extern D_L30_001DDB54, 4");
extern f32 D_L30_001DDB58;
__asm__(".extern D_L30_001DDB58, 4");
extern f32 D_L30_001DDB60;
__asm__(".extern D_L30_001DDB60, 4");
extern f32 D_L30_001DDB6C;
__asm__(".extern D_L30_001DDB6C, 4");
extern f32 D_L30_001DDB70;
__asm__(".extern D_L30_001DDB70, 4");
extern f32 D_L30_001DDB7C;
__asm__(".extern D_L30_001DDB7C, 4");
extern f32 D_L30_001DDB88;
__asm__(".extern D_L30_001DDB88, 4");
extern s32 D_L30_001DDB8C;
__asm__(".extern D_L30_001DDB8C, 4");
extern f32 D_L30_001DDB9C;
__asm__(".extern D_L30_001DDB9C, 4");
extern f32 D_L30_001DDBAC;
__asm__(".extern D_L30_001DDBAC, 4");
extern f32 D_L30_001DDBB0;
__asm__(".extern D_L30_001DDBB0, 4");
extern s32 D_L30_001DDBC0;
__asm__(".extern D_L30_001DDBC0, 4");
extern s32 D_L30_001DDBC4;
__asm__(".extern D_L30_001DDBC4, 4");
extern s32 D_L30_001DDBC8;
__asm__(".extern D_L30_001DDBC8, 4");
extern s32 D_L30_001DDBCC;
__asm__(".extern D_L30_001DDBCC, 4");
extern s32 D_L30_001DDBD0;
__asm__(".extern D_L30_001DDBD0, 4");
extern s32 D_L30_001DDBD4;
__asm__(".extern D_L30_001DDBD4, 4");
extern f32 D_L30_001DDBDC;
__asm__(".extern D_L30_001DDBDC, 4");
extern f32 D_L30_001DDBE4;
__asm__(".extern D_L30_001DDBE4, 4");
extern s32 D_L30_001DDBEC;
__asm__(".extern D_L30_001DDBEC, 4");
extern s32 D_L30_001DDBF0;
__asm__(".extern D_L30_001DDBF0, 4");
extern f32 D_L30_001DDBF4;
__asm__(".extern D_L30_001DDBF4, 4");
extern f32 D_L30_001DDC00;
__asm__(".extern D_L30_001DDC00, 4");
extern f32 D_L30_001DDC04;
__asm__(".extern D_L30_001DDC04, 4");
extern f32 D_L30_001DDC14;
__asm__(".extern D_L30_001DDC14, 4");
extern s32 D_L30_001DDC44;
__asm__(".extern D_L30_001DDC44, 4");

void func_L30_0035B780(u8 *a0) {
    S_35B780 *s;
    G_35B780 *g;
    G_35B780 *h;
    G_35B780 *h2;
    s32 w;
    f32 t;
    f32 r;
    s32 v;
    s32 v2;
    s32 v3;
    s32 q1;
    s32 q2;
    s32 q3;
    s32 n;
    s32 i;
    s32 k;
    s32 c0;
    s32 c1;
    f32 pos[2];

    s = *(S_35B780 **)(a0 + 0x68);
    func_L01_00516AA0(0x100012, 1, 1);
    if (D_L30_001DDC44 != 0) {
        func_L30_0035ADB8(a0);
    }
    g = D_L30_001A4BE0;
    w = g->w1B08;
    if (s->w128 != w) {
        s->w128 = w;
        s->w12C = D_L30_001DDB54;
    }
    if (g->w1B04 != 0) {
        func_L01_00516AA0(0x100013, 1, 1);
        t = func_0038D0B0((f32)s->w12C * 1.5707964f / (f32)D_L30_001DDB54);
        v = func_0038DBD8(D_L30_001DDB1C, D_L30_001DDB20, t);
        func_0011B2E8(D_L30_001E1460, D_L30_001DDC68, g->w1B08);
        func_L01_00516FD8(0x100019, D_L30_001E1460);
        func_L01_005170B8(0x100019, v);
        func_L01_00517538(0x100019, D_L30_001DDB6C + D_L30_001DDB50 * t, D_L30_001DDB70 + D_L30_001DDB50 * t);
        switch (g->w1B04) {
        case 1:
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f + D_L30_001DDB40, 1.0f - D_L30_001DDB30 - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB3C + (D_L30_001DDB44 - D_L30_001DDB3C) * t, D_L30_001DDAD8 * (D_L30_001DDB3C + (D_L30_001DDB44 - D_L30_001DDB3C) * t));
            func_L01_00517190(0x100015, 0xED94);
            break;
        case 2:
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f, 1.0f - D_L30_001DDB30 - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * t, D_L30_001DDAD8 * (D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * t));
            func_L01_00517190(0x100015, 0xED97);
            break;
        case 3:
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f, 1.0f - D_L30_001DDB30 - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * t, D_L30_001DDAD8 * (D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * t));
            func_L01_00517190(0x100015, 0xED96);
            break;
        case 4:
            func_L01_00516470(0x100015, D_L30_001DDB2C + D_L30_001DDB4C * 0.5f + D_L30_001DDB58, 1.0f - D_L30_001DDB30 - D_L30_001DDB48 * 0.5f);
            func_L01_00517538(0x100015, D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * t, D_L30_001DDAD8 * (D_L30_001DDB60 + (D_L30_001DDB44 - D_L30_001DDB60) * t));
            func_L01_00517190(0x100015, 0xED95);
            break;
        }
    } else {
        func_L01_00516AA0(0x100013, 1, 0);
    }
    func_0038CAD0(&s->w12C);
    if (s->w120 != s->wE4) {
        s->w120 = s->wE4;
        s->w124 = D_L30_001DDB8C;
    }
    t = func_0038D0B0((f32)s->w124 * 1.5707964f / (f32)D_L30_001DDB8C);
    v2 = func_0038DBD8(D_L30_001DDB1C, D_L30_001DDB18, t);
    func_0011B2E8(D_L30_001E1468, D_L30_001DDC68, s->wE4);
    func_L01_00516FD8(0x100021, D_L30_001E1468);
    func_L01_005170B8(0x100021, v2);
    func_L01_00517538(0x100021, D_L30_001DDBAC + D_L30_001DDB88 * t, D_L30_001DDBB0 + D_L30_001DDB88 * t);
    func_0011B2E8(D_L30_001E1470, D_L30_001DDC68, s->wE8);
    func_L01_00516FD8(0x100022, D_L30_001E1470);
    func_L01_005170B8(0x100022, v2);
    func_L01_00517538(0x100022, D_L30_001DDBAC + D_L30_001DDB88 * t, D_L30_001DDBB0 + D_L30_001DDB88 * t);
    func_L01_00517538(0x10001C, D_L30_001DDB9C + (D_L30_001DDB7C - D_L30_001DDB9C) * t, D_L30_001DDAD8 * (D_L30_001DDB9C + (D_L30_001DDB7C - D_L30_001DDB9C) * t));
    func_0038CAD0(&s->w124);
    if (D_L30_001E1414 <= 0.0f) {
        func_L01_00516AA0(0x100023, 1, 0);
    } else {
        func_L01_00516AA0(0x100023, 1, 1);
        func_L01_00517538(0x100026, D_L30_001E1410 * D_L30_001DDBE4 / D_L30_001E1414, D_L30_001DDBDC);
        q1 = func_0038DBD8(D_L30_001DDBC0, D_L30_001DDBCC, D_L30_001E1410 / D_L30_001E1414);
        func_L01_00517340(0x100026, q1, D_L30_001DDBC0, q1, D_L30_001DDBC0);
        func_L01_00517538(0x100027, D_L30_001E1418 * D_L30_001DDBE4 / D_L30_001E141C, D_L30_001DDBDC);
        q2 = func_0038DBD8(D_L30_001DDBC4, D_L30_001DDBD0, D_L30_001E1418 / D_L30_001E141C);
        func_L01_00517340(0x100027, q2, D_L30_001DDBC4, q2, D_L30_001DDBC4);
        func_L01_00517538(0x100028, D_L30_001E1420 * D_L30_001DDBE4 / D_L30_001E1424, D_L30_001DDBDC);
        q3 = func_0038DBD8(D_L30_001DDBC8, D_L30_001DDBD4, D_L30_001E1420 / D_L30_001E1424);
        func_L01_00517340(0x100028, q3, D_L30_001DDBC8, q3, D_L30_001DDBC8);
    }
    n = func_L30_0034CA78() + 5;
    k = func_L30_0034CA78();
    h = D_L30_001A4BE0;
    r = (f32)h->w2850 / ((f32)k * 20.0f + 100.0f);
    v3 = func_0038DBD8(D_L30_001DDBEC, D_L30_001DDBF0, r);
    for (i = 0; i < 10; i++) {
        func_L01_00516AA0(0x10002E + i, 1, i < n);
    }
    func_L01_00516558(0x100038, &pos[0], &pos[1]);
    func_L01_00516470(0x100038, D_L30_001DDB2C + D_L30_001DDBF4 + D_L30_001DDC00 + (f32)n * D_L30_001DDC14, pos[1]);
    h2 = D_L30_001A4BE0;
    func_L01_00517538(0x10002D, (f32)h2->w2850 / 200.0f * 10.0f * D_L30_001DDC14, D_L30_001DDC04);
    func_L01_00517340(0x10002D, D_L30_001DDBEC, v3, D_L30_001DDBEC, v3);
    if (0.8f < r) {
        func_L01_00517190(0x10002B, 0xED8E);
    } else if (0.6f < r) {
        func_L01_00517190(0x10002B, 0xED8F);
    } else if (0.4f < r) {
        func_L01_00517190(0x10002B, 0xED90);
    } else if (0.2f < r) {
        func_L01_00517190(0x10002B, 0xED91);
    } else {
        func_L01_00517190(0x10002B, 0xED92);
    }
    k = func_L30_00358360(a0);
    c1 = s->w11C;
    c0 = k / 50;
    if (c0 < c1) {
        func_L01_005170B8(0x10003D, func_0038DBD8(D_L30_001DDB28, D_L30_001DDB1C, (f32)(c1 - c0) / (f32)c1));
    } else if (c0 < s->w118) {
        func_L01_005170B8(0x10003D, func_0038DBD8(D_L30_001DDB14, D_L30_001DDB28, (f32)(s->w118 - c0) / (f32)(s->w118 - c1)));
    } else if (c0 < s->w114) {
        func_L01_005170B8(0x10003D, func_0038DBD8(D_L30_001DDB24, D_L30_001DDB14, (f32)(s->w114 - c0) / (f32)(s->w114 - s->w118)));
    } else if (c0 < s->w110) {
        func_L01_005170B8(0x10003D, func_0038DBD8(D_L30_001DDB10, D_L30_001DDB24, (f32)(s->w110 - c0) / (f32)(s->w110 - s->w114)));
    } else {
        func_L01_005170B8(0x10003D, func_0038DBD8(D_L30_001DDB20, D_L30_001DDB10, (f32)(600 - c0) / (f32)(600 - s->w110)));
    }
    if (k <= 0x8C9E) {
        func_0011B2E8(D_L30_001E1478, D_L30_001DDC70, k / 3000, k / 50 % 60);
    } else {
        func_0011B2E8(D_L30_001E1478, D_L30_001DDC78);
    }
    func_L01_00516FD8(0x10003D, D_L30_001E1478);
}
/* localdecomp:end func_L30_0035B780 */
