#include "common.h"

/* declared by functions of L39_0055D7F8.c, which this file was cut from */
extern u16 *D_L39_002927E0[];
struct E_0055DB18;
extern struct E_0055DB18 *D_L39_0024BF5C;
extern s32 D_L39_0024BF98;
extern void func_L01_004450F0(void *, s32, s32);
typedef struct T_0055DB18 {
    u8 pad[0x88];
    s32 w88[8];
    s32 wA8[8];
} T_0055DB18;
typedef struct Q_0055DB18 {
    u8 pad0[0x1C];
    s32 f1C;
    u8 pad20[0xC];
    s32 f2C;
} Q_0055DB18;
typedef struct E_0055DB18 {
    u8 pad[0x68];
    Q_0055DB18 *f68;
    u8 pad2[0x100 - 0x6C];
} E_0055DB18;
extern E_0055DB18 *D_L39_0024BF5C;
extern T_0055DB18 *D_L39_00352B4C[];

/* localdecomp:start func_L39_0055DCE0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0055DCE0;

typedef struct R_0055DCE0 {
    u32 w0;
    s32 w4;
    s32 w8;
} R_0055DCE0;

typedef struct Q_0055DCE0 {
    u8 pad0[0x30];
    s32 w30;
    u8 pad34[0x200 - 0x34];
    R_0055DCE0 r;
    u8 pad20C[0x21C - 0x20C];
    s32 w21C;
    s32 w220;
    u8 pad224[0x228 - 0x224];
    s32 w228;
    s32 w22C;
    s32 w230;
} Q_0055DCE0;

typedef struct S_0055DCE0 {
    u8 pad0[0x10];
    V4_0055DCE0 pos;
    u8 b20;
    u8 b21;
    u8 pad22[0x30 - 0x22];
    u8 b30;
    u8 pad31[0x68 - 0x31];
    Q_0055DCE0 *p68;
    u8 pad6C[0xAC - 0x6C];
    s32 wAC;
} S_0055DCE0;

typedef struct O2_0055DCE0 O2_0055DCE0;
typedef struct {
    u8 pad0[0x10];
    s32 (*fn)(O2_0055DCE0 *);
} VT_0055DCE0;
struct O2_0055DCE0 {
    u8 pad0[0x14];
    VT_0055DCE0 *vt;
};

typedef struct {
    u8 pad0[0x2D0];
    s32 w2D0;
} E_0055DCE0;

typedef struct {
    u8 pad0[0x18F];
    s8 b18F;
} G_0055DCE0;

typedef struct {
    u8 pad0[0x40];
    s32 w40[2];
} T_0055DCE0;

typedef struct {
    u8 pad0[0x2548];
    s32 w2548;
} P_0055DCE0;

__asm__(".extern D_L39_0024BF5C, 16");
__asm__(".extern D_L39_00241640, 16");
extern G_0055DCE0 *D_L39_00241640;
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00242930, 16");
extern s32 D_L39_00242930;
extern void func_L39_00662B18(void *, void *, s32);
extern E_0055DCE0 *func_L39_006685D8(u32);
extern O2_0055DCE0 *func_L39_0061D1D8(u32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32,
                              s32, s32, f32, f32, s32, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3718(s32, void *);
extern P_0055DCE0 *func_L39_0061BF38(s32);
extern void func_L39_00648960(void *, s32);
extern void func_003C3938(void *, s32, s32);
extern void func_L39_0055D948(s32);
typedef int u128_0055DCE0 __attribute__((mode(TI)));

void func_L39_0055DCE0(S_0055DCE0 *self, u32 *msg) {
    Q_0055DCE0 *q = self->p68;
    R_0055DCE0 *r = &q->r;
    u32 type = msg[0] & 0xF;

    switch (type) {
    case 0: {
        s32 t;
        if (r->w4 != 0) {
            break;
        }
        t = msg[1] + (msg[0] >> 13);
        if (q->w21C < t) {
            q->w21C = t;
            func_L39_00662B18(msg, r, 4);
            if (q->r.w0 != 0xFFFFFFFF) {
                if (((q->r.w0 >> 24) & 0xF) == 3) {
                    q->w220 = func_L39_006685D8(q->r.w0)->w2D0;
                } else {
                    O2_0055DCE0 *o = func_L39_0061D1D8(q->r.w0);
                    q->w220 = (o != 0) ? o->vt->fn(o) : 0;
                }
                if (q->w220 != 0) {
                    if (self->b20 == 1) {
                        func_L01_004450F0(self, 2, -1);
                    } else {
                        func_L01_004450F0(self, 4, -1);
                    }
                } else {
                    if (q->w230 != 0) {
                        if (self->b20 != 3) {
                            func_L01_004450F0(self, 3, -1);
                        }
                    } else {
                        if (self->b20 != 1) {
                            func_L01_004450F0(self, 1, -1);
                        }
                    }
                    q->w228 = 0;
                }
            } else {
                q->w220 = 0;
                if (q->w230 != 0) {
                    if (self->b20 != 3) {
                        func_L01_004450F0(self, 3, -1);
                    }
                } else {
                    if (self->b20 != 1) {
                        func_L01_004450F0(self, 1, -1);
                    }
                }
                q->w228 = 0;
            }
        }
        break;
    }
    case 1:
        if (self->b20 != 7) {
            V4_0055DCE0 sph;
            V4_0055DCE0 *pos;
            u16 *p;
            s32 n;
            s32 found;

            pos = &self->pos;
            sph = self->pos;
            sph.w = 3.5f;
            if (func_L39_005BE900(&sph, 0, self->b30) != -1) {
                V4_0055DCE0 v;
                s32 h;
                func_L01_003303B8(pos, 0, 5, 5, 5, 5, 5, 0, 0.75f, 0.0f, 0.0f, 2.0f, 0, 1, 1, 0,
                                  1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_L01_00451FE0(self, 0x1F, &D_L39_00242930, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f,
                                  -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                if (q->w230 != 0) {
                    h = func_L39_005F33E0(1, 0, self);
                } else {
                    h = func_L39_005F33E0(5, 0, self);
                }
                *(u128_0055DCE0 *)&v = 0;
                v.z = 1.0f;
                func_L39_005F3718(h, &v);
            }
            func_L01_004450F0(self, 7, -1);

            n = 0;
            for (p = D_L39_002927E0[self->b21];
                 self->b21 != 0xFF && self->b21 <= D_L39_0024BF98 && p != 0 &&
                 ((s16)p[-1] >= 0 || p == D_L39_002927E0[self->b21]);
                 p++) {
                S_0055DCE0 *o = (S_0055DCE0 *)&D_L39_0024BF5C[*p & 0x7FFF];
                if (o == 0) {
                    break;
                }
                if (o->b20 == 7) {
                    n++;
                }
            }
            if (n != 1) {
                goto done;
            }
            found = 0;
            if (D_L39_00241640 != 0 && D_L39_00241640->b18F == 0) {
                found = 1;
            }
            if (found) {
                goto done;
            }
            if (q->w22C >= 0) {
                if (q->w22C < 2) {
                    u16 *p2;
                    S_0055DCE0 *e = (S_0055DCE0 *)((E_0055DB18 *)((u8 *)D_L39_0024BF5C + (((T_0055DCE0 *)D_L39_00352B4C[0])->w40[q->w22C] << 8)))->f68;
                    for (p2 = D_L39_002927E0[e->wAC];
                         (e->wAC & 0xFF) != 0xFF && e->wAC <= D_L39_0024BF98 && p2 != 0 &&
                         ((s16)p2[-1] >= 0 || p2 == D_L39_002927E0[e->wAC]);
                         p2++) {
                        S_0055DCE0 *o = (S_0055DCE0 *)&D_L39_0024BF5C[*p2 & 0x7FFF];
                        if (o == 0) {
                            break;
                        }
                        if (o == self) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            if (!found) {
                s32 i;
                for (i = 0; i < *D_L39_00241120; i++) {
                    P_0055DCE0 *pl = func_L39_0061BF38(i);
                    if (pl->w2548 == q->w22C) {
                        func_L39_00648960(pl, 0x25);
                    }
                }
            }
        }
    done:
        r->w4 = 1;
        r->w8 = msg[1];
        r->w0 = 0xFFFFFFFF;
        q->w30 = 0;
        func_003C3938(self, 0, 0);
        q->w220 = 0;
        break;
    case 2: {
        s32 a;
        func_L39_00662B18(msg, &a, 4);
        break;
    }
    case 3: {
        s32 a, b;
        func_L39_00662B18(msg, &a, 4);
        func_L39_00662B18(msg, &b, 4);
        ((void (*)(s32, s32))func_L39_0055D948)(a, b);
        break;
    }
    }
}
/* localdecomp:end func_L39_0055DCE0 */

/* localdecomp:start func_L39_0055E2E0 */
typedef int s128_0055E2E0 __attribute__((mode(TI)));
typedef struct V_0055E2E0 {
    f32 x, y, z, w;
} V_0055E2E0 __attribute__((aligned(16)));

typedef struct Vt_0055E2E0 {
    u8 pad0[0x10];
    void *(*f10)(void *);
    u8 pad14[0x1C - 0x14];
    s32 (*f1C)(void *, s32);
} Vt_0055E2E0;

typedef struct H_0055E2E0 {
    u8 pad0[0x14];
    Vt_0055E2E0 *vt;
} H_0055E2E0;

typedef struct C_0055E2E0 {
    u8 pad0[0x20];
    void *w20;
} C_0055E2E0;

typedef struct R_0055E2E0 {
    u32 w0;
    s32 w4;
} R_0055E2E0;

typedef struct Q_0055E2E0 {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x70 - 0x34];
    u8 b70[7];
    u8 b77;
    u8 pad78[0x200 - 0x78];
    R_0055E2E0 r;
    u8 pad208[0x224 - 0x208];
    s32 w224;
    u8 pad228[0x22C - 0x228];
    s32 w22C;
    s32 w230;
    u8 pad234[0x250 - 0x234];
    f32 f250;
    u8 pad254[0x25C - 0x254];
    f32 f25C;
} Q_0055E2E0;

typedef struct O_0055E2E0 {
    u8 pad0[0x10];
    s128_0055E2E0 pos;
    u8 pad20[0x30 - 0x20];
    u8 b30;
    u8 pad31[0x68 - 0x31];
    Q_0055E2E0 *p68;
    u8 pad6C[0xA8 - 0x6C];
    u8 bA8;
} O_0055E2E0;

typedef struct T_0055E2E0 {
    u8 pad0[0x1F8];
    f32 f1F8[1];
} T_0055E2E0;

extern T_0055E2E0 D_L39_00352940;
__asm__(".extern D_L39_0024112C, 16");
extern s32 D_L39_0024112C;
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_0055FF88(void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_003C4A40(void *, void *);
extern s32 func_L39_0055DC90_0055E2E0(s32);
extern void func_L39_0055DBE8_0055E2E0(s32, s32);
extern s32 func_L39_0055DCB8_0055E2E0(s32);
extern void func_L39_0055DC30(s32);
extern u32 func_L39_0055FC98(u8 *, s32);
extern s32 func_L39_0061CEA0(void *);

s32 func_L39_0055E2E0(O_0055E2E0 *o, s32 a1) {
    Q_0055E2E0 *q = o->p68;
    R_0055E2E0 *rr = &q->r;
    s32 t;
    s32 r;
    C_0055E2E0 *c;
    f32 f21;
    f32 k;

    if (a1 == 0) {
    if (rr->w4 != 0) {
        return 0;
    }
    t = D_L39_0024112C;
    if (q->w224 < t && (t & 7) == (((s32)o >> 8) & 7)) {
        r = func_L39_005B4398(0xF) + 0x1E;
        q->w224 = D_L39_0024112C + r;
        if (func_L39_0055DC90_0055E2E0((s32)o) == 0) {
            if (q->r.w0 != 0xFFFFFFFF) {
                r = func_L39_0055FF88(o);
                if (r != q->r.w0) {
                    func_L39_0055DBE8_0055E2E0((s32)o, r);
                }
            } else {
                r = func_L39_0055FC98((u8 *)o, 0);
                if (r != q->r.w0) {
                    func_L39_0055DBE8_0055E2E0((s32)o, r);
                }
            }
        }
    }
    func_L01_0044ABD0(o, q->b70);
    c = (C_0055E2E0 *)func_L01_00447490(o, 0x10000, 0);
    f21 = func_L01_004474E8(o, c);
    if (c != 0) {
    if (q->w22C >= 0) {
        k = D_L39_00352940.f1F8[q->w22C] * 0.7f;
    } else {
        k = 0.0f;
    }
    f21 = f21 - f21 * k;
    if (c->w20 != 0) {
        if (q->f30 != 0.0f) {
            H_0055E2E0 *h = (H_0055E2E0 *)func_L39_0061CEA0(c->w20);
            if (h != 0 && h->vt->f1C(h, q->w22C) == 0) {
                s32 ok = 1;
                u8 *x = h->vt->f10(h);
                if (q->w230 != 0 && x != 0) {
                    f32 d = (q->f25C < q->f250) ? q->f250 : q->f25C;
                    d = d * d;
                    if (d < func_L01_0040E548(x + 0x10, (u8 *)o + 0x10)) {
                        ok = 0;
                    }
                }
                if (ok != 0) {
                    f32 f = q->f30 - f21;
                    f32 g = (0.0f < f) ? f : 0.0f;
                    q->f30 = g;
                    q->b77 = 0xC8;
                    func_003C4A40(o, q->b70);
                }
            }
        }
        if (c->w20 != 0 && q->f30 == 0.0f) {
            V_0055E2E0 v;
            s128_0055E2E0 *pos = &o->pos;
            v = *(V_0055E2E0 *)pos;
            v.w = 3.5f;
            if (func_L39_005BE900(&v, 0, o->b30) != -1) {
                V_0055E2E0 w;
                s32 e;
                func_L01_003303B8((u8 *)pos, 0, 5, 5, 5, 5, 5, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                                  0, 1, 1, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_L01_00451FE0(o, 0x1F, &D_L39_00242930, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                if (q->w230 != 0) {
                    e = func_L39_005F33E0(1, 0, o);
                } else {
                    e = func_L39_005F33E0(5, 0, o);
                }
                *(s128_0055E2E0 *)&w = 0;
                w.z = 1.0f;
                func_L39_005F3718(e, &w);
            }
            func_L01_004450F0(o, 7, -1);
            if (func_L39_0055DCB8_0055E2E0((s32)o) == 0) {
                func_L39_0055DC30((s32)o);
            }
        }
    }
    o->bA8 = 0xFF;
    }
    }
    return 0;
}
/* localdecomp:end func_L39_0055E2E0 */
