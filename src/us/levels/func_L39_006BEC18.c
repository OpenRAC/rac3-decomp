#include "common.h"

/* NTSC-U counterpart of func_L39_006C1730 (src/levels/39_multiplayer_menu/L39_006C1730.c) */
/* localdecomp:start func_L39_006BEC18 */
__asm__(".extern D_L39_00247A74_006BEC18, 16");
__asm__(".extern D_L39_002417C0, 16");
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_001DC1E4_sda, 4");

typedef struct S_006C1730_Z {
    u8 pad[0x1C];
    s32 w1C;
} S_006C1730_Z;

typedef struct S_006C1730_I {
    s32 w0;
    s32 w4;
    S_006C1730_Z **w8;
} S_006C1730_I;

typedef struct S_006C1730_Q {
    u8 b0;
    u8 pad1[3];
    s32 w4;
    u8 pad8[0x20];
    S_006C1730_I items[1];
} S_006C1730_Q;

typedef struct S_006C1730_X {
    u8 pad[0x40];
    S_006C1730_Q *w40;
} S_006C1730_X;

typedef struct S_006C1730_P {
    char name[8][16];
    u8 pad80[0x60];
    s16 hE0[8];
    s16 hF0[8];
    u8 pad100[0x50];
    s32 w150[8];
    s32 w170;
    s32 w174;
} S_006C1730_P;

typedef struct S_006C1730_G {
    u8 pad0[0x110];
    s32 w110[0x40];
    u8 pad210[0x64];
    s32 w274;
} S_006C1730_G;

typedef struct S_006C1730_D {
    u8 pad0[0x128];
    s32 w128;
    s32 w12C;
    s32 w130;
    s32 w134;
    s32 w138;
    s32 w13C;
    u8 pad140[0x28];
    u8 b168;
    u8 b169;
    u8 pad16A[0x182];
    s32 w2EC;
    u8 pad2F0[0x304];
    s32 w5F4;
} S_006C1730_D;

typedef struct S_006C1730_VT {
    u8 pad[0x30];
    void (*f30)(void *, s32 *, f32 *);
} S_006C1730_VT;

typedef struct S_006C1730_E {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x58];
    S_006C1730_VT *vt;
} S_006C1730_E;

typedef struct S_006C1730_O {
    u8 pad0[0x110];
    S_006C1730_E *e[0x37];
    u8 pad1EC[0xA4];
    s32 w290;
    u8 pad294[0x14];
    u8 b2A8;
    u8 pad2A9[0xF];
    s32 w2B8;
    s32 w2BC;
    u8 pad2C0[0xC];
    s32 w2CC;
    u8 pad2D0[4];
    s32 w2D4;
    u8 f2D8[8];
    s32 w2E0;
    u8 b2E4;
    u8 b2E5;
    u8 pad2E6[2];
    s32 w2E8;
    s32 w2EC;
    s32 w2F0;
    u8 pad2F4[0xC];
    u8 b300;
    u8 b301;
    u8 b302;
    u8 b303;
} S_006C1730_O;

extern S_006C1730_G *D_L39_00247A74_006BEC18;
extern S_006C1730_P *D_L39_002417C0;
extern S_006C1730_X *D_L39_0024D860;
extern S_006C1730_G *D_001DC1E4_sda;
extern S_006C1730_D D_001A5E50;
extern s32 D_001A5E58[];
extern u8 D_L39_002496A0[];

extern void func_L39_006BF598(void *);
extern s32 func_L39_006C0C60(void *, s32, s32, s32);
extern void func_L39_006C0F90(void *);
extern void func_L39_006C0128(void *);
extern void func_L39_006C0B58(void *);
extern s32 func_L39_006C1590(void *);
extern s32 func_L39_006C0588(void *);
extern void func_L39_006C1930(void *);
extern s32 func_L39_00685798(s32, s32, s32);
extern s32 func_L39_006C1AB0(void *, s32, s32 *);
extern s32 func_L39_006C1BD8(void *, s32);
extern void func_L39_006C1848(void *, s32);
extern s32 func_0037DF98(s32);
extern s32 func_L39_00684D80(void *, s32, s32, s32);
extern s32 func_L39_006847C8(void *, s32, s32, s32, s32, f32);
extern void func_L39_006848D0(void *, void *, s32, s32);
extern void func_L39_00688750(void *, s32, s32);
extern void func_L39_006C0DC8(void *, s32, s32);
extern void func_L39_006C17F0(void *, s32, s32);
extern s32 func_L39_006C1C70(void *, s32);
extern s32 func_L39_006C9748(s32, s32);
extern void func_L39_006C97B8(s32, void *, s32);
extern s32 func_L39_00688350(void *, s32);
extern void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_00684B20(void *, s32, s32, s32, u8, s32, s32, u8 *, u8, u8, u8, u8, s32);
extern void func_L01_00445110(s32 *, s32, s32);
extern void func_0019CC50(s32, s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_0019B728(s32);
extern void func_00199B60(void);


s32 func_L39_006BEC18(S_006C1730_O *obj, s32 arg1) {
    s32 ent;
    S_006C1730_G *ctx;
    S_006C1730_G *g;
    S_006C1730_G *g2;
    S_006C1730_Q *q;
    S_006C1730_I *t;
    s32 i;
    s32 k;
    s32 m;
    s32 kk;
    s32 ty;
    s32 w;
    s32 v;
    s32 mm;
    s32 j;
    s32 h;
    s32 idx;
    s32 n;
    s32 r;
    s32 loc;
    s32 first;
    s32 last;
    s32 flags;
    s32 flags2;
    s32 un;
    f32 fl;
    char buf[0x100];

    g = D_L39_00247A74_006BEC18;
    if (g->w274 >= 0) {
        ent = g->w110[g->w274];
    } else {
        ent = 0;
    }
    if (ent != 0) {
        func_L39_006BF598(obj);
        return 1;
    }
    if (D_001A5E50.b169 != 0 || D_001A5E50.w2EC != 0) {
        func_L39_006C0C60(obj, 1, 0, -1);
        D_001A5E50.b169 = 0;
        return 1;
    }
    if (arg1 != 0) {
        obj->w2BC = 0;
    } else {
        obj->w2BC = obj->w2BC + 1;
    }
    func_L39_006C0F90(obj);
    func_L39_006C0128(obj);
    func_L39_006BF598(obj);
    func_L39_006C0B58(obj);
    if (func_L39_006C1590(obj) != 0) {
        return 1;
    }
    if (D_L39_002417C0 != 0) {
        if (D_L39_002417C0->hF0[0] < 7 && func_L39_006C0588(obj) != 0) {
            return 1;
        }
        if (D_L39_002417C0->hF0[0] >= 7
            && (D_001A5E50.w128 + 0x1388 < D_L39_002417C0->w174
                || (D_L39_002417C0->hF0[0] >= 7 && D_001A5E50.w128 >= D_L39_002417C0->w174))) {
            func_L39_006C1930(obj);
            return 1;
        }
        for (k = 0; k < 8; k++) {
            if (D_L39_002417C0->hE0[k] == D_001A5E58[0] && D_L39_002417C0->hF0[k] == 5) {
                func_L39_006C0C60(obj, 1, 0, 0x1600);
                return 1;
            }
        }
    }
    q = D_L39_0024D860->w40;
    t = 0;
    if (q->b0 != 0 && q->w4 >= 0) {
        t = &q->items[q->w4];
    }
    do {
        if (t != 0) {
            if (D_L39_002417C0 != 0) {
                for (i = 0; i < 8; i++) {
                    h = D_L39_002417C0->hE0[i];
                    if (h >= 0) {
                        func_0019CC50(h, 0);
                        do {
                            for (j = 0; j < t->w4; j++) {
                                if (D_L39_002417C0->w150[i] == t->w8[j]->w1C) {
                                    func_0019CC50(h, 1);
                                    break;
                                }
                            }
                        } while (0);
                    }
                }
            }
        }
    } while (0);
    if (D_L39_002417C0 != 0) {
        if (D_L39_002417C0->hF0[0] >= 7) {
            return 1;
        }
    }
    if (arg1 == 7 && D_L39_002417C0 != 0) {
        func_L39_00685798(4, 0, 0);
        idx = obj->w290 - 15;
        if ((u32)idx < 0x28 && obj->w2B8 == 0) {
            func_L39_006C1AB0(obj, idx, &loc);
            n = func_L39_006C1BD8(obj, idx);
            if (D_001A5E50.b168 != 0 && n >= 0 && loc < 0) {
                ctx = D_001DC1E4_sda;
                if (obj->w2E0 == 2) {
                    if (obj->b2E5 == 0) {
                        r = 1;
                    } else {
                        ctx = D_L39_00247A74_006BEC18;
                        r = func_L39_00684D80(ctx, func_0037DF98(0x16CB), func_0037DF98(0x15FE), 0);
                    }
                } else {
                    r = func_L39_00684D80(ctx, func_0037DF98(0x16CB), func_0037DF98(0x15FE), 0);
                }
                if (r == 0) {
                    func_L39_006C1848(obj, idx);
                    g2 = D_L39_00247A74_006BEC18;
                    func_L39_006847C8(g2, func_0037DF98(0x1720), (s32)D_L39_002496A0, 4, 0, 0.6f);
                    return 1;
                }
                if (r == 1) {
                    func_00120048(buf, (char *)func_0037DF98(0x15FF), D_L39_002417C0->name[n]);
                    g2 = D_L39_00247A74_006BEC18;
                    if (func_L39_006847C8(g2, (s32)buf, func_0037DF98(0x1031), 3, 0, 0.6f) == 1) {
                        D_L39_002417C0->hF0[n] = 5;
                    }
                }
                return 1;
            } else if (D_001A5E50.b168 != 0 && n < 0) {
                if (idx - D_001A5E50.w130 >= D_001A5E50.w138) {
                    func_L01_00445110(&D_001A5E50.w13C, 0, 1);
                } else {
                    func_L01_00445110(&D_001A5E50.w138, 0, 1);
                }
                if (idx >= D_001A5E50.w130 + D_001A5E50.w138 + D_001A5E50.w13C) {
                    func_L39_00688750(obj, obj->w290 - 1, 0);
                }
            } else if (n >= 0 && loc >= 0 && D_L39_002417C0->hF0[0] < 7) {
                if (D_L39_002417C0->hF0[n] == 0) {
                    func_L39_006C0DC8(obj, idx, 1);
                    return 1;
                } else if (D_L39_002417C0->hF0[n] == 6) {
                    if (D_001A5E50.b168 != 0) {
                        D_L39_002417C0->hF0[n] = 0;
                        func_L39_006C0DC8(obj, idx, 1);
                        return 1;
                    }
                    if (loc == 0) {
                        v = 1;
                    } else {
                        v = 3;
                    }
                    func_L39_006C17F0(obj, v, loc);
                }
                return 1;
            }
        }
        if (obj->w290 == 3 && obj->w2B8 == 0) {
            kk = func_L39_006C1C70(obj, 0);
            if (kk >= 0) {
                mm = func_L39_006C1BD8(obj, kk);
                if (D_001A5E50.b168 != 0 && mm >= 0) {
                    D_L39_002417C0->hF0[mm] = 0;
                }
                if (D_L39_002417C0->hF0[mm] == 0 && mm >= 0) {
                    func_L39_006848D0(D_L39_00247A74_006BEC18, D_L39_002496A0, 3, (u32)(obj->w2CC - 1) < 2);
                    return 1;
                } else {
                    func_L39_006C17F0(obj, 4, 0);
                    return 1;
                }
            }
        }
        if (obj->w290 == 5) {
            S_006C1730_G *g3 = D_L39_00247A74_006BEC18;
            func_L39_00684B20(g3, obj->w2E0, obj->w2D4, obj->w2E8, obj->b2E4, obj->w2EC, obj->w2F0, obj->f2D8,
                              obj->b300, obj->b301, obj->b302, obj->b303, obj->b2E5);
            return 1;
        }
        if (obj->w290 == 4 && D_001A5E50.b168 != 0) {
            if (obj->b2A8 == 0) {
                return 1;
            }
            w = func_L39_006C9748(3, D_001A5E50.w5F4);
            if (w < 8) {
                func_L39_006C97B8(3, &D_001A5E50.w5F4, w + 8);
            }
            D_L39_002417C0->hF0[0] = 7;
            D_L39_002417C0->w174 = D_001A5E50.w128 + 0xFA0;
            func_0019B728(2);
            func_00199B60();
            return 1;
        }
    }
    if (arg1 == 8) {
        S_006C1730_G *g3 = D_L39_00247A74_006BEC18;
        func_L39_00684B20(g3, obj->w2E0, obj->w2D4, obj->w2E8, obj->b2E4, obj->w2EC, obj->w2F0, obj->f2D8,
                          obj->b300, obj->b301, obj->b302, obj->b303, obj->b2E5);
        return 1;
    }
    if (arg1 == 5) {
        func_L39_00685798(0x17, 0, 0);
        func_L39_006C0C60(obj, 0, 1, -1);
        return 1;
    }
    if (func_L39_00688350(obj, arg1) != 0) {
        return 1;
    }
    if ((u32)(obj->w290 - 15) < 0x28) {
        obj->e[obj->w290]->vt->f30(obj->e[obj->w290], &un, &fl);
        first = -1;
        last = -1;
        for (m = 15; m < 0x37; m++) {
            if ((ty = obj->e[m]->w4) == 3 || ty == 4 || ty == 5) {
                if (first == -1) {
                    first = m;
                }
                last = m;
            }
        }
        flags = obj->w290 != first;
        if (obj->w290 != last) {
            flags |= 2;
        }
        func_L39_00687358(obj, flags, 3, 3, 0.5f, fl, 0.805f, 0.035f, 0.041f, 1.0f);
    } else {
        obj->e[obj->w290]->vt->f30(obj->e[obj->w290], &un, &fl);
        first = -1;
        last = -1;
        for (m = 3; m < 5; m++) {
            if ((ty = obj->e[m]->w4) == 3 || ty == 4 || ty == 5) {
                if (first == -1) {
                    first = m;
                }
                last = m;
            }
        }
        flags2 = obj->w290 != first;
        if (obj->w290 != last) {
            flags2 |= 2;
        }
        func_L39_00687358(obj, flags2, 3, 3, 0.287f, fl, 0.38f, 0.035f, 0.041f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_006BEC18 */
