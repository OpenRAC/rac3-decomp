#include "common.h"

/* NTSC-U counterpart of func_L39_006A74F8 (src/levels/39_multiplayer_menu/L39_006A74F8.c) */
/* localdecomp:start func_L39_006A4CE8 */
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

extern G_006A74F8 *D_L39_0024D860;
extern H_006A74F8 *D_L39_00247A74_006A4CE8;
extern N_006A74F8 *D_L39_002417C0;
extern s32 *D_L39_002412A0;
extern C_006A74F8 D_L39_002417C8 __attribute__((section(".sdata")));
extern K_006A74F8 D_001A5E50;
extern f32 D_L39_004B05A0[];
extern u8 D_L39_00248A10[];
extern u8 D_L39_00248A18_006A4CE8[];

extern void func_L39_006A5820(void *, s32);
extern s32 func_L39_00688350(void *, s32);
extern void func_00199190(void);
extern s32 func_L39_006D1928(s32);
extern s32 func_L39_006D7B28(s32, s32, s32);
extern void func_L39_006BA8F0(s32, s32);
extern void func_L39_00685798(s32, s32, s32);
extern void func_L39_00699150(s32, s32, s32, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_006D7310(s32, s32, u8 *, s32);
extern s32 func_L39_006D0D50(s32, s32, u8 *, s32, s32, s32);
extern s32 func_0037DF98(s32);
extern void func_L39_006847C8(H_006A74F8 *, void *, void *, s32, s32, f32);
extern void func_L39_005992A8(s32, s32);
extern void func_L39_006A5070(void);

s32 func_L39_006A4CE8(S_006A74F8 *arg0, s32 arg1) {
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

    func_L39_006A5820(arg0, 0);
    arg0->f114->f60->f44(arg0->f114, 1, D_L39_004B05A0[0], 0.0f);
    if (func_L39_00688350(arg0, arg1) != 1) {
        if (arg0->f48C) {
            if (--arg0->f48C == 0) {
                D_L39_002417C8 = D_L39_002417C0->f188;
                func_00199190();
                func_L39_006D1928(D_L39_0024D860->f3C);
                e1 = D_L39_00247A74_006A4CE8->fE0;
                p = &D_001A5E50;
                func_L39_006D7B28(D_L39_0024D860->f4C, p->f78, 0);
                func_L39_006BA8F0(e1, p->f78);
                D_L39_00247A74_006A4CE8->f284 = 0xC;
            }
        } else {
            k = &D_001A5E50;
            if (k->f170 == 0) {
                h = D_L39_00247A74_006A4CE8;
                g = D_L39_0024D860;
                if (arg1 == 7) {
                    if (k->f174 == 0) {
                        if (arg0->f474 && arg0->f470 == -1) {
                            func_L39_00685798(4, 0, 0);
                            func_L39_00699150(h->f94, 4, -1, -1, -1);
                            func_00120048(buf, D_L39_00248A18_006A4CE8, 0x52, *D_L39_0024D860->f30);
                            for (i = 0; i < 8; i++) {
                                v = D_L39_002417C0->f150[i];
                                if (v != -1 && D_001A5E50.f34 != v) {
                                    func_L39_006D7310(D_L39_0024D860->f48, v, buf, 1);
                                }
                            }
                            arg0->f48C = 0x1E;
                        } else if (arg0->f478 >= 0) {
                            func_L39_00685798(4, 0, 0);
                            func_00199190();
                            func_L39_006D1928(g->f3C);
                            e2 = D_L39_00247A74_006A4CE8->fE0;
                            q = &D_001A5E50;
                            func_L39_006D7B28(D_L39_0024D860->f4C, q->f78, 0);
                            func_L39_006BA8F0(e2, q->f78);
                            if (func_L39_006D0D50(g->f3C, arg0->f478, q->fFE, q->fC, q->f18, arg0->f480)) {
                                D_L39_00247A74_006A4CE8->f284 = 0x21;
                            }
                        }
                    } else {
                        x = D_L39_002417C0->f17C;
                        if (*D_L39_002412A0 >= 2 && x <= 0x2D) {
                            x += 10;
                        }
                        func_L39_005992A8(x, 0);
                    }
                    return 1;
                }
            }
            if (arg0->f490) {
                t = func_0037DF98(0x173A);
                func_L39_006847C8(D_L39_00247A74_006A4CE8, D_L39_00248A10, (void *)t, 4, 0, 0.6f);
                arg0->f490 = 0;
            } else {
                if (arg1 != 5) {
                    return 0;
                }
                func_L39_006A5070();
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L39_006A4CE8 */
