#include "common.h"

/* localdecomp:start func_L39_005DC4C0 */
extern u8 *D_L39_0024BF5C;
extern void func_L01_004512E8(u8 *, s32 *, s32 *);

s32 func_L39_005DC4C0(s32 i, s32 *a, s32 *b) {
    s32 r;

    *a = 0;
    r = 0;
    *b = 0;
    if (i >= 0) {
        r = 1;
        func_L01_004512E8(D_L39_0024BF5C + (i << 8), a, b);
    }
    return r;
}
/* localdecomp:end func_L39_005DC4C0 */

/* localdecomp:start func_L39_005DC508 */
typedef struct {
    u8 pad60[0x60];
    s32 f60[8];
    u8 pad80[0x28];
    s32 fA8[8];
} S_005DC508_e;

typedef struct {
    u8 pad[0x20C];
    S_005DC508_e *f20C;
} S_005DC508_t;

extern S_005DC508_t D_L39_00352940_005DC508;
extern u8 *D_L39_0024BF5C;
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern f32 func_L01_0040E548(void *, void *);

s32 func_L39_005DC508(void *a0, s32 a1, s32 a2) {
    s32 r;
    s32 i;
    s32 j;

    r = a1 == a2;
    if (r == 0) {
        for (j = 0; j < 8; j++) {
            u8 *p = D_L39_0024CE20[j];
            if (p != 0 && *(s32 *)(p + 0x2548) == a2) {
                if (func_L01_0040E548(p + 0xA0, a0) < 1225.0f) {
                    r = 1;
                    break;
                }
            }
        }
        for (i = 0; i < 8; i++) {
            if (D_L39_00352940_005DC508.f20C->f60[i] >= 0 && D_L39_00352940_005DC508.f20C->fA8[i] == a2) {
                if (func_L01_0040E548(D_L39_0024BF5C + (D_L39_00352940_005DC508.f20C->f60[i] << 8) + 0x10, a0) < 2500.0f) {
                    r = 1;
                    break;
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_005DC508 */

/* localdecomp:start func_L39_005DC648 */
typedef struct {
    u8 p0[0x40]; s32 f40; s32 f44; u8 p48[0x18]; s32 f60[8]; u8 p80[8]; s32 f88; s32 f8C;
} S_005DC648_inner;
typedef struct { u8 p0[0x20C]; S_005DC648_inner *f20C; } S_005DC648_t;
typedef struct { u8 p0[8]; struct { u8 p0[0x10]; s32 (*f10)(void *, s32); } *f8; u8 p0C[0x44]; s32 f50; } S_005DC648_obj;
typedef struct { u8 p0[4]; s32 f4; u8 p8[8]; } S_005DC648_g;
typedef struct { u8 r, g, b, a; u8 pad[12]; } S_005DC648_c;

extern S_005DC648_t D_L39_00352940_005DC648;
extern S_005DC648_g D_L39_0024CD50[];
extern u8 D_L39_0049A018[];
extern u8 D_L39_0049A008[];
extern u8 D_L39_0049A010[];
extern u8 D_L39_00499FF0[];
extern u8 D_L39_00499FF8[];
extern u8 D_L39_002438EC;
extern s32 D_L39_00245D00;

extern s32 func_003B43B0(s32);
extern s32 func_L39_005DBEE8(s32, s32, s32);
extern s32 func_L39_00602240(s32);
extern s32 func_L01_004D2110(s32);
extern s32 func_L01_00518D40(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E51F8(s32);
extern s32 func_003E5360(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, u32);
extern s32 func_L01_00517538(s32, f32, f32);
extern void *func_003E6C08();
extern void *func_003E6DE8(void *);
extern S_005DC648_obj *func_003E6378(void *, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516728(s32, f32, f32);
extern s32 func_L01_00516C78_005DC648(s32, s32, s32);
extern s32 func_L01_005168F0(s32, f32);
extern s32 func_003E6FF0(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern f32 func_L39_005DD390(s32);
extern s32 func_L39_005DC4C0(s32, s32 *, s32 *);
extern s32 func_L39_005DBF90(s32);

void func_L39_005DC648(s32 arg0) {
    f32 x0, y0, x1, y1, x2, y2;
    S_005DC648_obj *o;
    void *g;
    S_005DC648_g *list;
    s32 i;

    func_L39_005DBEE8(func_003B43B0(0), func_L39_00602240(0), 0);
    D_L39_002438EC = 1;
    func_L01_004D2110(1);
    func_L39_005DBEE8(func_003B43B0(0), func_L39_00602240(0), 0);
    func_L01_00518D40(0x50000);
    func_003B5060(0x50001);
    func_003B5060(0x50002);
    func_003B5060(0x50003);
    func_003B5060(0x50004);
    func_003B5060(0x50005);
    func_003E51F8(0x50006);
    func_003E51F8(0x50007);
    func_003E51F8(0x50009);
    func_003E51F8(0x5000A);
    func_003E51F8(0x5000B);
    func_003E51F8(0x5000C);
    func_003E51F8(0x5000D);
    func_003E51F8(0x5000E);
    func_003E51F8(0x5000F);
    func_003E51F8(0x50010);
    func_003E51F8(0x50011);
    func_003E51F8(0x50012);
    func_003E51F8(0x50008);
    func_003E51F8(0x50013);
    func_003E51F8(0x50014);
    func_003E51F8(0x50015);
    func_003E51F8(0x50016);
    func_003E51F8(0x50017);
    func_003E51F8(0x50018);
    func_003E51F8(0x50019);
    func_003E51F8(0x5001A);
    func_003E51F8(0x5001B);
    func_003E51F8(0x5001C);
    func_003E51F8(0x5001D);
    func_003E51F8(0x5001E);
    func_003E51F8(0x5001F);
    func_003E51F8(0x50020);
    func_003E51F8(0x50021);
    func_003E51F8(0x50022);
    func_003E5360(0x50023);
    func_003E5360(0x50024);
    func_L01_00516470(0x50006, 0.5f, 0.52f);
    func_L01_005170B8(0x50006, (D_L39_0049A018[3] << 24) | (D_L39_0049A018[2] << 16) | (D_L39_0049A018[1] << 8) | D_L39_0049A018[0]);
    func_L01_00517538(0x50006, 0.8f, 0.7f);
    list = D_L39_0024CD50;
    if (list->f4) g = list;
    else g = func_003E6C08();
    o = func_003E6378(func_003E6DE8(g), 0x50006);
    if (o == 0 || o->f8->f10(o, D_L39_00245D00) == 0) {
        o = 0;
    }
    o->f50 = func_003B43B0(0);
    func_L01_00517190(0x50006, 1);
    func_L01_00516FD8(0x50023, func_00381FF0(0x12A5));
    func_L01_00516FD8(0x50024, func_00381FF0(0x12A6));
    func_L01_005170B8(0x50023, 0x8066CCFF);
    func_L01_005170B8(0x50024, 0x8066CCFF);
    func_L01_00516470(0x50023, 0.5f, 0.9f);
    func_L01_00516470(0x50024, 0.5f, 0.14f);
    func_L01_00516AA0(0x50023, 1, 0);
    func_L01_00516AA0(0x50024, 1, 0);
    func_L01_00516AA0(0x50023, 0x40, 1);
    func_L01_00516AA0(0x50024, 0x40, 1);
    func_L01_00516470(0x50007, 0.0f, 0.0f);
    func_L01_005170B8(0x50007, (D_L39_0049A008[3] << 24) | (D_L39_0049A008[2] << 16) | (D_L39_0049A008[1] << 8) | D_L39_0049A008[0]);
    func_L01_00517538(0x50007, 0.075f, 0.093f);
    func_L01_00517190(0x50007, 0xED1C);
    func_L01_00516AA0(0x50007, 1, 1);
    func_L01_00516470(0x50008, 0.0f, 0.0f);
    func_L01_005170B8(0x50008, (D_L39_0049A010[3] << 24) | (D_L39_0049A010[2] << 16) | (D_L39_0049A010[1] << 8) | D_L39_0049A010[0]);
    func_L01_00517538(0x50008, 0.05f, 0.062000003f);
    func_L01_00517190(0x50008, 0xED1C);
    func_L01_00516AA0(0x50008, 1, 1);
    func_L39_005DC4C0(D_L39_00352940_005DC648.f20C->f40, (s32 *)&x0, (s32 *)&y0);
    func_L01_00516470(0x50009, x0, y0);
    func_L01_00517538(0x50009, 0.05f, 0.062000003f);
    func_L01_00516AA0(0x50009, 1, 1);
    func_L01_00516AA0(0x50009, 0x40, 1);
    func_L01_00516728(0x50009, 0.002f, 0.002f);
    func_L01_00516C78_005DC648(0x50009, 3, 3);
    func_L01_00517190(0x50009, 0xED33);
    func_L01_005168F0(0x50009, func_L39_005DD390(D_L39_00352940_005DC648.f20C->f40));
    if (D_L39_00352940_005DC648.f20C->f88 == 0) {
        func_L01_005170B8(0x50009, 0x60000000 | (D_L39_00499FF0[2] << 16) | (D_L39_00499FF0[1] << 8) | D_L39_00499FF0[0]);
    } else {
        func_L01_005170B8(0x50009, 0x60000000 | (D_L39_00499FF8[2] << 16) | (D_L39_00499FF8[1] << 8) | D_L39_00499FF8[0]);
    }
    func_L39_005DC4C0(D_L39_00352940_005DC648.f20C->f44, (s32 *)&x1, (s32 *)&y1);
    func_L01_00516470(0x5000A, x1, y1);
    func_L01_00517538(0x5000A, 0.05f, 0.062000003f);
    func_L01_00516AA0(0x5000A, 1, 1);
    func_L01_00516AA0(0x5000A, 0x40, 1);
    func_L01_00516728(0x5000A, 0.002f, 0.002f);
    func_L01_00516C78_005DC648(0x5000A, 3, 3);
    func_L01_00517190(0x5000A, 0xED33);
    func_L01_005168F0(0x5000A, func_L39_005DD390(D_L39_00352940_005DC648.f20C->f44));
    func_L01_005170B8(0x5000A, 0x60000000 | (D_L39_00499FF8[2] << 16) | (D_L39_00499FF8[1] << 8) | D_L39_00499FF8[0]);
    if (D_L39_00352940_005DC648.f20C->f8C == 0) {
        func_L01_005170B8(0x5000A, 0x60000000 | (D_L39_00499FF0[2] << 16) | (D_L39_00499FF0[1] << 8) | D_L39_00499FF0[0]);
    } else {
        func_L01_005170B8(0x5000A, 0x60000000 | (D_L39_00499FF8[2] << 16) | (D_L39_00499FF8[1] << 8) | D_L39_00499FF8[0]);
    }
    i = 0x5000B;
    do {
        if (func_L39_005DC4C0(D_L39_00352940_005DC648.f20C->f60[i - 0x5000B], (s32 *)&x2, (s32 *)&y2) != 0) {
            func_L01_00516470(i, x2, y2);
            func_L01_00516AA0(i, 1, 1);
        } else {
            func_L01_00516AA0(i, 1, 0);
        }
        func_L01_00517538(i, 0.05f, 0.062000003f);
        func_L01_00516C78_005DC648(i, 3, 3);
        func_L01_00516AA0(i, 0x40, 1);
        func_L01_00516728(i, 0.002f, 0.002f);
        func_L01_00517190(i, 0xED34);
        i++;
    } while (i <= 0x50012);
    i = 0x5001B;
    do {
        func_L01_00517538(i, 0.05f, 0.062000003f);
        func_L01_00516AA0(i, 1, 0);
        func_L01_00516AA0(i, 0x40, 1);
        func_L01_00516728(i, 0.002f, 0.002f);
        func_L01_00516C78_005DC648(i, 3, 3);
        func_L01_00517190(i, 0xED36);
        i++;
    } while (i <= 0x50022);
    i = 0x50013;
    do {
        func_L01_00517538(i, 0.035f, 0.0434f);
        func_L01_00516AA0(i, 1, 0);
        func_L01_00516AA0(i, 0x40, 1);
        func_L01_00516728(i, 0.002f, 0.002f);
        func_L01_00516C78_005DC648(i, 3, 3);
        func_L01_00517190(i, 0xED35);
        i++;
    } while (i <= 0x5001A);
    func_003E8630(0x50001, 0x50006);
    func_003E8630(0x50001, 0x50007);
    func_003E8630(0x50001, 0x50008);
    func_003E8630(0x50001, 0x50009);
    func_003E8630(0x50001, 0x5000A);
    for (i = 0x5000B; i <= 0x50012; i++) {
        func_003E8630(0x50002, i);
    }
    for (i = 0x5001B; i <= 0x50022; i++) {
        func_003E8630(0x50003, i);
    }
    for (i = 0x50013; i <= 0x5001A; i++) {
        func_003E8630(0x50004, i);
    }
    func_003E8630(0x50005, 0x50023);
    func_003E8630(0x50005, 0x50024);
    func_003E8630(0x50000, 0x50001);
    func_003E8630(0x50000, 0x50002);
    func_003E8630(0x50000, 0x50003);
    func_003E8630(0x50000, 0x50004);
    func_003E8630(0x50000, 0x50005);
    func_003E8348(0x17, 0x50000);
    func_003E6FF0(arg0, 1);
    func_L39_005DBF90(-1);
    func_L01_004D2110(0);
}
/* localdecomp:end func_L39_005DC648 */

/* localdecomp:start func_L39_005DD258 */
typedef struct {
    u8 pad[136];
    s32 f88[2];
} S_005DD258;

extern S_005DD258 *D_L39_00352B4C[];

long func_L39_005DD258(u8 *a0) {
    s32 v = *(s32 *)(a0 + 0x2548);
    S_005DD258 *p = D_L39_00352B4C[0];
    long r;

    if (p->f88[0] == v) {
        r = 0;
    } else if (p->f88[1] == v) {
        r = 1;
    } else if (v) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_005DD258 */

/* localdecomp:start func_L39_005DD290 */
typedef struct {
    u8 pad40[0x40];
    s32 f40[8];
    s32 f60[8];
    u8 pad80[0x28];
    s32 fA8[8];
} S_005DD290_e;

typedef struct {
    u8 pad[0x20C];
    S_005DD290_e *f20C;
} S_005DD290_t;

typedef struct {
    u8 pad[0xC60];
    s32 fC60;
    s32 fC64;
} S_005DD290_g;

extern S_005DD290_t D_L39_00352940;
extern u8 *D_L39_0024BF5C;
extern long func_L39_005DD258(u8 *);
extern void func_L01_004512E8(u8 *, s32 *, s32 *);

void func_L39_005DD290(u8 *a0, s32 *a1, s32 *a2) {
    S_005DD290_g *g = *(S_005DD290_g **)(a0 + 0x2558);
    s32 idx = g->fC64;
    u8 *p;

    if (idx >= 0 && D_L39_00352940.f20C->fA8[idx] == *(s32 *)(a0 + 0x2548)) {
        p = D_L39_0024BF5C + (D_L39_00352940.f20C->f60[idx] << 8);
    } else {
        (*(S_005DD290_g **)(a0 + 0x2558))->fC64 = -1;
        (*(S_005DD290_g **)(a0 + 0x2558))->fC60 = ((s32 (*)(u8 *))func_L39_005DD258)(a0);
        p = D_L39_0024BF5C + (D_L39_00352940.f20C->f40[(*(S_005DD290_g **)(a0 + 0x2558))->fC60] << 8);
    }
    func_L01_004512E8(p, a1, a2);
}
/* localdecomp:end func_L39_005DD290 */

/* localdecomp:start func_L39_005DD370 */
__asm__(".extern D_001D81E0_sda, 4");
extern float D_001D81E0_sda;
extern float func_0038DAB8(float, float);

float func_L39_005DD370(void *m) {
    return func_0038DAB8(*(float *)((char *)m + 0xF8), D_001D81E0_sda);
}
/* localdecomp:end func_L39_005DD370 */

/* localdecomp:start func_L39_005DD390 */
extern u8 *D_L39_0024BF5C;
extern float func_L39_005DD370(void *);
float func_L39_005DD390(s32 a0) {
    float r = 0.0f;
    if (a0 >= 0) r = func_L39_005DD370(D_L39_0024BF5C + (a0 << 8));
    return r;
}
/* localdecomp:end func_L39_005DD390 */
