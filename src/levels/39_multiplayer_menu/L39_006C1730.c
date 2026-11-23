#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_00688400(void *, s32);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);

/* localdecomp:start func_L39_006C1730 */
__asm__(".extern D_L39_00247914, 16");
__asm__(".extern D_L39_00241640, 16");
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_001DC204_sda, 4");

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

extern S_006C1730_G *D_L39_00247914;
extern S_006C1730_P *D_L39_00241640;
extern S_006C1730_X *D_L39_0024D760;
extern S_006C1730_G *D_001DC204_sda;
extern S_006C1730_D D_001A5CD0;
extern s32 D_001A5CD8[];
extern u8 D_L39_00249550[];

extern void func_L39_006C20B0(void *);
extern s32 func_L39_006C3778(void *, s32, s32, s32);
extern void func_L39_006C3AA8(void *);
extern void func_L39_006C2C40(void *);
extern void func_L39_006C3670(void *);
extern s32 func_L39_006C40A8(void *);
extern s32 func_L39_006C30A0(void *);
extern void func_L39_006C4448(void *);
extern s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L39_006C45C8(void *, s32, s32 *);
extern s32 func_L39_006C46F0(void *, s32);
extern void func_L39_006C4360(void *, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L39_006878A0(void *, s32, s32, s32);
extern s32 func_L39_006872E8(void *, s32, s32, s32, s32, f32);
extern void func_L39_006873F0(void *, void *, s32, s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_006C38E0(void *, s32, s32);
extern void func_L39_006C4308(void *, s32, s32);
extern s32 func_L39_006C4788(void *, s32);
extern s32 func_L39_006CC238(s32, s32);
extern void func_L39_006CC2A8(s32, void *, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_00687640(void *, s32, s32, s32, u8, s32, s32, u8 *, u8, u8, u8, u8, s32);
extern void func_L01_00448248(s32 *, s32, s32);
extern void func_0019CB10(s32, s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_0019B5E8(s32);
extern void func_00199A20(void);


s32 func_L39_006C1730(S_006C1730_O *obj, s32 arg1) {
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

    g = D_L39_00247914;
    if (g->w274 >= 0) {
        ent = g->w110[g->w274];
    } else {
        ent = 0;
    }
    if (ent != 0) {
        func_L39_006C20B0(obj);
        return 1;
    }
    if (D_001A5CD0.b169 != 0 || D_001A5CD0.w2EC != 0) {
        func_L39_006C3778(obj, 1, 0, -1);
        D_001A5CD0.b169 = 0;
        return 1;
    }
    if (arg1 != 0) {
        obj->w2BC = 0;
    } else {
        obj->w2BC = obj->w2BC + 1;
    }
    func_L39_006C3AA8(obj);
    func_L39_006C2C40(obj);
    func_L39_006C20B0(obj);
    func_L39_006C3670(obj);
    if (func_L39_006C40A8(obj) != 0) {
        return 1;
    }
    if (D_L39_00241640 != 0) {
        if (D_L39_00241640->hF0[0] < 7 && func_L39_006C30A0(obj) != 0) {
            return 1;
        }
        if (D_L39_00241640->hF0[0] >= 7
            && (D_001A5CD0.w128 + 0x1388 < D_L39_00241640->w174
                || (D_L39_00241640->hF0[0] >= 7 && D_001A5CD0.w128 >= D_L39_00241640->w174))) {
            func_L39_006C4448(obj);
            return 1;
        }
        for (k = 0; k < 8; k++) {
            if (D_L39_00241640->hE0[k] == D_001A5CD8[0] && D_L39_00241640->hF0[k] == 5) {
                func_L39_006C3778(obj, 1, 0, 0x1600);
                return 1;
            }
        }
    }
    q = D_L39_0024D760->w40;
    t = 0;
    if (q->b0 != 0 && q->w4 >= 0) {
        t = &q->items[q->w4];
    }
    do {
        if (t != 0) {
            if (D_L39_00241640 != 0) {
                for (i = 0; i < 8; i++) {
                    h = D_L39_00241640->hE0[i];
                    if (h >= 0) {
                        func_0019CB10(h, 0);
                        do {
                            for (j = 0; j < t->w4; j++) {
                                if (D_L39_00241640->w150[i] == t->w8[j]->w1C) {
                                    func_0019CB10(h, 1);
                                    break;
                                }
                            }
                        } while (0);
                    }
                }
            }
        }
    } while (0);
    if (D_L39_00241640 != 0) {
        if (D_L39_00241640->hF0[0] >= 7) {
            return 1;
        }
    }
    if (arg1 == 7 && D_L39_00241640 != 0) {
        func_L39_00688340(4, 0, 0);
        idx = obj->w290 - 15;
        if ((u32)idx < 0x28 && obj->w2B8 == 0) {
            func_L39_006C45C8(obj, idx, &loc);
            n = func_L39_006C46F0(obj, idx);
            if (D_001A5CD0.b168 != 0 && n >= 0 && loc < 0) {
                ctx = D_001DC204_sda;
                if (obj->w2E0 == 2) {
                    if (obj->b2E5 == 0) {
                        r = 1;
                    } else {
                        ctx = D_L39_00247914;
                        r = func_L39_006878A0(ctx, func_00381FF0(0x16CB), func_00381FF0(0x15FE), 0);
                    }
                } else {
                    r = func_L39_006878A0(ctx, func_00381FF0(0x16CB), func_00381FF0(0x15FE), 0);
                }
                if (r == 0) {
                    func_L39_006C4360(obj, idx);
                    g2 = D_L39_00247914;
                    func_L39_006872E8(g2, func_00381FF0(0x1720), (s32)D_L39_00249550, 4, 0, 0.6f);
                    return 1;
                }
                if (r == 1) {
                    func_00120048(buf, (char *)func_00381FF0(0x15FF), D_L39_00241640->name[n]);
                    g2 = D_L39_00247914;
                    if (func_L39_006872E8(g2, (s32)buf, func_00381FF0(0x1031), 3, 0, 0.6f) == 1) {
                        D_L39_00241640->hF0[n] = 5;
                    }
                }
                return 1;
            } else if (D_001A5CD0.b168 != 0 && n < 0) {
                if (idx - D_001A5CD0.w130 >= D_001A5CD0.w138) {
                    func_L01_00448248(&D_001A5CD0.w13C, 0, 1);
                } else {
                    func_L01_00448248(&D_001A5CD0.w138, 0, 1);
                }
                if (idx >= D_001A5CD0.w130 + D_001A5CD0.w138 + D_001A5CD0.w13C) {
                    func_L39_0068B2F8(obj, obj->w290 - 1, 0);
                }
            } else if (n >= 0 && loc >= 0 && D_L39_00241640->hF0[0] < 7) {
                if (D_L39_00241640->hF0[n] == 0) {
                    func_L39_006C38E0(obj, idx, 1);
                    return 1;
                } else if (D_L39_00241640->hF0[n] == 6) {
                    if (D_001A5CD0.b168 != 0) {
                        D_L39_00241640->hF0[n] = 0;
                        func_L39_006C38E0(obj, idx, 1);
                        return 1;
                    }
                    if (loc == 0) {
                        v = 1;
                    } else {
                        v = 3;
                    }
                    func_L39_006C4308(obj, v, loc);
                }
                return 1;
            }
        }
        if (obj->w290 == 3 && obj->w2B8 == 0) {
            kk = func_L39_006C4788(obj, 0);
            if (kk >= 0) {
                mm = func_L39_006C46F0(obj, kk);
                if (D_001A5CD0.b168 != 0 && mm >= 0) {
                    D_L39_00241640->hF0[mm] = 0;
                }
                if (D_L39_00241640->hF0[mm] == 0 && mm >= 0) {
                    func_L39_006873F0(D_L39_00247914, D_L39_00249550, 3, (u32)(obj->w2CC - 1) < 2);
                    return 1;
                } else {
                    func_L39_006C4308(obj, 4, 0);
                    return 1;
                }
            }
        }
        if (obj->w290 == 5) {
            S_006C1730_G *g3 = D_L39_00247914;
            func_L39_00687640(g3, obj->w2E0, obj->w2D4, obj->w2E8, obj->b2E4, obj->w2EC, obj->w2F0, obj->f2D8,
                              obj->b300, obj->b301, obj->b302, obj->b303, obj->b2E5);
            return 1;
        }
        if (obj->w290 == 4 && D_001A5CD0.b168 != 0) {
            if (obj->b2A8 == 0) {
                return 1;
            }
            w = func_L39_006CC238(3, D_001A5CD0.w5F4);
            if (w < 8) {
                func_L39_006CC2A8(3, &D_001A5CD0.w5F4, w + 8);
            }
            D_L39_00241640->hF0[0] = 7;
            D_L39_00241640->w174 = D_001A5CD0.w128 + 0xFA0;
            func_0019B5E8(2);
            func_00199A20();
            return 1;
        }
    }
    if (arg1 == 8) {
        S_006C1730_G *g3 = D_L39_00247914;
        func_L39_00687640(g3, obj->w2E0, obj->w2D4, obj->w2E8, obj->b2E4, obj->w2EC, obj->w2F0, obj->f2D8,
                          obj->b300, obj->b301, obj->b302, obj->b303, obj->b2E5);
        return 1;
    }
    if (arg1 == 5) {
        func_L39_00688340(0x17, 0, 0);
        func_L39_006C3778(obj, 0, 1, -1);
        return 1;
    }
    if (func_L39_0068AEF8(obj, arg1) != 0) {
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
        func_L39_00689F00(obj, flags, 3, 3, 0.5f, fl, 0.805f, 0.035f, 0.041f, 1.0f);
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
        func_L39_00689F00(obj, flags2, 3, 3, 0.287f, fl, 0.38f, 0.035f, 0.041f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_006C1730 */
