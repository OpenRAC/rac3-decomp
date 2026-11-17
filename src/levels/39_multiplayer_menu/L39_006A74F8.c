#include "common.h"

typedef struct S_006A5FE0 {
    u8 pad0[0x2B1];
    u8 f2B1;
    u8 pad1[6];
    s32 f2B8;
    s32 f2BC[576];
    s32 fBBC[1];
} S_006A5FE0;

typedef struct S_006A6108 {
    u8 pad0[0xCBC];
    u8 f_CBC;
    u8 pad1[7];
    s32 f_CC4;
    s32 f_CC8[1];
    u8 pad2[0x8FC];
    s32 f_15C8[1];
} S_006A6108;

typedef struct S_L39_006A6078 {
    u8 pad0[0x16CC];
    s32 f16CC;
    s32 f16D0[11];
    s32 f16FC[1];
} S_L39_006A6078;

/* localdecomp:start func_L39_006A74F8 */
typedef struct V_006A74F8 {
    u8 pad0[0x44];
    void (*f44)(void *, s32, f32, f32);
} V_006A74F8;

typedef struct O_006A74F8 {
    u8 pad0[0x60];
    V_006A74F8 *f60;
} O_006A74F8;

typedef struct C_006A74F8 {
    u8 b[0x16];
} C_006A74F8;

typedef struct N_006A74F8 {
    u8 pad0[0x150];
    s32 f150[8];
    u8 pad1[0x17C - 0x170];
    s16 f17C;
    u8 pad2[0x188 - 0x17E];
    C_006A74F8 f188;
} N_006A74F8;

typedef struct H_006A74F8 {
    u8 pad0[0x94];
    s32 f94;
    u8 pad1[0xE0 - 0x98];
    s32 fE0;
    u8 pad2[0x284 - 0xE4];
    s32 f284;
} H_006A74F8;

typedef struct G_006A74F8 {
    u8 pad0[0x30];
    s32 *f30;
    u8 pad1[8];
    s32 f3C;
    u8 pad2[8];
    s32 f48;
    s32 f4C;
} G_006A74F8;

typedef struct K_006A74F8 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad1[8];
    s32 f18;
    u8 pad2[0x18];
    s32 f34;
    u8 pad3[0x40];
    s32 f78;
    u8 pad4[0x82];
    u8 fFE[0x72];
    s32 f170;
    s32 f174;
    u8 pad5[0x634 - 0x178];
    s32 f634;
} K_006A74F8;

typedef struct S_006A74F8 {
    u8 pad0[0x114];
    O_006A74F8 *f114;
    u8 pad1[0x470 - 0x118];
    s32 f470;
    u8 f474;
    u8 pad2[3];
    s32 f478;
    u8 pad3[4];
    s32 f480;
    u8 pad4[8];
    s32 f48C;
    u8 f490;
} S_006A74F8;

extern G_006A74F8 *D_L39_0024D760;
extern H_006A74F8 *D_L39_00247914;
extern N_006A74F8 *D_L39_00241640;
extern s32 *D_L39_00241120;
extern C_006A74F8 D_L39_00241648 __attribute__((section(".sdata")));
extern K_006A74F8 D_001A5CD0;
extern f32 D_L39_004B04E0[];
extern u8 D_L39_002488C0[];
extern u8 D_L39_002488C8[];
extern u8 D_L39_002488D0[];

extern void func_L39_006A8138(void *, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_00199050(void);
extern s32 func_L39_006D40B0(s32);
extern s32 func_L39_006DA680(s32, s32, s32);
extern void func_L39_006BD408(s32, s32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_0069B960(s32, s32, s32, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_006D9E68(s32, s32, u8 *, s32);
extern s32 func_L39_006D34D8(s32, s32, u8 *, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L39_006872E8(H_006A74F8 *, void *, void *, s32, s32, f32);
extern void func_L39_0059A578(s32, s32);
extern void func_L39_006A7928(void);

s32 func_L39_006A74F8(S_006A74F8 *arg0, s32 arg1) {
    u8 buf[0x10];
    s32 i;
    s32 v;
    s32 x;
    K_006A74F8 *k;
    K_006A74F8 *p;
    K_006A74F8 *q;
    H_006A74F8 *h;
    G_006A74F8 *g;
    s32 t;
    H_006A74F8 *r;
    s32 e1;
    s32 e2;

    func_L39_006A8138(arg0, 0);
    arg0->f114->f60->f44(arg0->f114, 1, D_L39_004B04E0[0], 0.0f);
    if (func_L39_0068AEF8(arg0, arg1) != 1) {
        if (arg0->f48C) {
            if (--arg0->f48C == 0) {
                D_L39_00241648 = D_L39_00241640->f188;
                func_00199050();
                func_L39_006D40B0(D_L39_0024D760->f3C);
                e1 = D_L39_00247914->fE0;
                p = &D_001A5CD0;
                func_L39_006DA680(D_L39_0024D760->f4C, p->f78, 0);
                func_L39_006BD408(e1, p->f78);
                D_L39_00247914->f284 = 0xC;
            }
        } else {
            k = &D_001A5CD0;
            if (k->f170 == 0) {
                h = D_L39_00247914;
                g = D_L39_0024D760;
                if (arg1 == 7) {
                    if (k->f174 == 0) {
                        if (arg0->f474 && arg0->f470 == -1) {
                            func_L39_00688340(4, 0, 0);
                            func_L39_0069B960(h->f94, 4, -1, -1, -1);
                            func_00120048(buf, D_L39_002488C8, 0x52, *D_L39_0024D760->f30);
                            for (i = 0; i < 8; i++) {
                                v = D_L39_00241640->f150[i];
                                if (v != -1 && D_001A5CD0.f34 != v) {
                                    func_L39_006D9E68(D_L39_0024D760->f48, v, buf, 1);
                                }
                            }
                            arg0->f48C = 0x1E;
                        } else if (arg0->f478 >= 0) {
                            func_L39_00688340(4, 0, 0);
                            func_00199050();
                            func_L39_006D40B0(g->f3C);
                            e2 = D_L39_00247914->fE0;
                            q = &D_001A5CD0;
                            func_L39_006DA680(D_L39_0024D760->f4C, q->f78, 0);
                            func_L39_006BD408(e2, q->f78);
                            if (func_L39_006D34D8(g->f3C, arg0->f478, q->fFE, q->fC, q->f18, arg0->f480)) {
                                D_L39_00247914->f284 = 0x21;
                            } else if (q->f634 == 1) {
                                r = D_L39_00247914;
                                func_L39_006872E8(r, (void *)func_00381FF0(0x12F5), D_L39_002488C0, 4, 0, 0.6f);
                            } else if (r = D_L39_00247914, q->f634 == 3) {
                                func_L39_006872E8(r, (void *)func_00381FF0(0x12F6), D_L39_002488C0, 4, 0, 0.6f);
                            } else {
                                func_L39_006872E8(r, (void *)func_00381FF0(0x1FCF), D_L39_002488D0, 4, 0, 0.6f);
                            }
                        }
                    } else {
                        x = D_L39_00241640->f17C;
                        if (*D_L39_00241120 >= 2 && x <= 0x2D) {
                            x += 10;
                        }
                        func_L39_0059A578(x, 0);
                    }
                    return 1;
                }
            }
            if (arg0->f490) {
                t = func_00381FF0(0x173A);
                func_L39_006872E8(D_L39_00247914, D_L39_002488C0, (void *)t, 4, 0, 0.6f);
                arg0->f490 = 0;
            } else {
                if (arg1 != 5) {
                    return 0;
                }
                func_L39_006A7928();
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L39_006A74F8 */
