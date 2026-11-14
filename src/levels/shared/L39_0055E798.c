#include "common.h"

/* localdecomp:start func_L39_0055E798 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct K_0055E798 {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x10];
    f32 f24;
    u8 pad28[0x1C];
    u16 h44;
} K_0055E798;

typedef struct P_0055E798 {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x24];
    s32 w28;
    u8 pad2C[0x2D8 - 0x2C];
    void *w2D8;
    void *w2DC;
} P_0055E798;

typedef struct B_0055E798 {
    u8 pad0[0x70];
    f32 f70;
    u8 pad74[0xC];
} B_0055E798;

typedef struct S200_0055E798 {
    u32 w0;
    u32 w4;
    u32 w8;
} S200_0055E798;

typedef struct G_0055E798 G_0055E798;
typedef struct O_0055E798 O_0055E798;

struct G_0055E798 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[2];
    u8 b38;
    u8 pad39[5];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x80 - 0x44];
    B_0055E798 blk[3];
    S200_0055E798 s200;
    f32 f20C;
    u8 pad210[8];
    f32 f218;
    s32 w21C;
    void *w220;
    s32 w224;
    u8 pad228[4];
    s32 w22C;
    s32 w230;
    s32 w234;
    s32 w238;
    f32 f23C;
    u8 pad240[0xC];
    s32 w24C;
    f32 f250;
    f32 f254;
    O_0055E798 *p258;
    f32 f25C;
};

struct O_0055E798 {
    u8 pad0[0x10];
    u8 q10[0x10];
    u8 b20;
    u8 b21;
    u8 pad22[2];
    K_0055E798 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[2];
    unsigned long d38;
    u8 pad40[3];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 b60;
    u8 pad61[7];
    G_0055E798 *p68;
    u8 pad6C[0xC];
    u32 w78;
    u8 pad7C[0x96 - 0x7C];
    u16 h96;
    s32 w98;
    u8 pad9C[0xAA - 0x9C];
    s16 hAA;
    u8 padAC[0xB8 - 0xAC];
    O_0055E798 *pB8;
    u8 padBC[2];
    u8 bBE;
    u8 padBF;
    u8 vC0[0x30];
    union {
        u8 q[0x10];
        f32 f[4];
    } uF0;
};

typedef struct Q_0055E798 {
    u8 pad0[0x1C];
    s32 w1C;
    u8 pad20[0xC];
    s32 w2C;
    u8 pad30[0xAC - 0x30];
    s32 wAC;
} Q_0055E798;

typedef struct E_0055E798 {
    u8 pad[0x68];
    Q_0055E798 *p68;
    u8 pad6C[0xC];
    u32 w78;
    u8 pad7C[0x100 - 0x7C];
} E_0055E798;

typedef struct T_0055E798 {
    u8 pad0[0x40];
    s32 w40[2];
    u8 pad48[0x88 - 0x48];
    s32 w88[8];
} T_0055E798;

__asm__(".extern D_L39_0024BF5C, 16");
extern E_0055E798 *D_L39_0024BF5C;
extern T_0055E798 *D_L39_00352B4C[];
__asm__(".extern D_L39_0024BF5C_0055E798, 4");
__asm__(".extern D_L39_0024BF98, 4");
__asm__(".extern D_L39_0024B3E0, 4");
extern E_0055E798 *D_L39_0024BF5C_0055E798;
extern s32 D_L39_0024BF98;
extern f32 D_L39_0024B3E0;
extern s8 *D_L39_00241640;
extern u32 D_L39_0024112C;
extern s16 *D_L39_002927E0[];
typedef struct { u8 v[1]; } C_0055E798;
__asm__(".extern D_L39_002462A8, 16");
__asm__(".extern D_L39_002462A9, 16");
__asm__(".extern D_L39_002462AA, 16");
extern C_0055E798 D_L39_002462A8;
extern C_0055E798 D_L39_002462A9;
extern C_0055E798 D_L39_002462AA;

extern s32 func_L39_0055D808(u8 *);
extern s32 func_L39_0055D818(u8 *);
extern void func_L39_0055D828(O_0055E798 *);
extern s32 func_L39_0055DB18(G_0055E798 *);
extern void func_L39_0055F3C0(O_0055E798 *);
extern void func_L39_0055F808();
extern void func_L39_0055F8D8(O_0055E798 *, G_0055E798 *);
extern P_0055E798 *func_L39_0061D7B0(void *);
extern void func_L39_005F2FF8(O_0055E798 *, s32);
extern P_0055E798 *func_L39_0066C828(O_0055E798 *, s32, s32);
extern void func_L39_0061C1E0(O_0055E798 *, s32);
extern void func_L39_0066B9A0(s32, s32);
extern void func_L39_0066BA78(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void func_003C3A10(O_0055E798 *, s32, s32, s32);
extern void func_003C3938(O_0055E798 *, s32, s32);
extern void func_L01_004450F0(O_0055E798 *, s32, s32);
extern s32 func_L01_004561B8(O_0055E798 *);
extern O_0055E798 *func_003C24B0(s32, s32);
extern void func_003C2880(O_0055E798 *);
extern void func_003C7C38(O_0055E798 *);
extern s32 func_003D4D00(void *, s32, s32, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038CB78(void *, s32, s32);

void func_L39_0055E798(O_0055E798 *self) {
    G_0055E798 *g;
    s32 v;
    s32 flag;
    s32 i;
    s32 n;
    f32 m;
    P_0055E798 *p;
    void *o;
    E_0055E798 *e;

    g = self->p68;
    if (self->h96 < 0xFFFF) {
        self->h96++;
    }
    v = func_L39_0055DB18(g);
    if (self->b20 != 0 && v != g->w22C) {
        p = func_L39_0061D7B0(self);
        g->w22C = v;
        p->w28 = v;
        if (v == 0) {
            self->bBE = (self->bBE | 0x10) & 0xF7;
        } else if (v == 1) {
            self->bBE = (self->bBE | 0x8) & 0xEF;
        } else {
            self->bBE &= 0xE7;
        }
    }
    switch (self->b20) {
    case 0:
        if (D_L39_00241640[0x193] == 0) {
            func_003C2880(self);
            return;
        }
        p = func_L39_0066C828(self, -1, 1);
        g->w22C = -2;
        p->w28 = v;
        func_L39_0061C1E0(self, -1);
        {
            S200_0055E798 *t = &g->s200;
            t->w0 = 0xFFFFFFFF;
            t->w4 = 0;
            t->w8 = 0;
        }
        g->w224 = 0;
        g->f218 = 0;
        if (g->w234 == 0) {
            g->w234 = 3;
        }
        if (g->w238 == 0) {
            g->w238 = 30;
        }
        if (g->f23C == 0) {
            g->f23C = 75.0f;
        }
        if (g->f250 == 0) {
            g->f250 = 16.0f;
        }
        if (g->f25C == 0) {
            if (g->w230 != 0) {
                g->f25C = 128.0f;
            } else {
                g->f25C = 16.0f;
            }
        }
        m = g->f25C < g->f250 ? g->f250 : g->f25C;
        i = (s32)m + 15;
        if (self->b30 < i) {
            self->b30 = i < 256 ? i : 255;
        }
        if (self->h32 < self->b30) {
            self->h32 = self->b30;
        }
        self->uF0.f[2] = func_0038DAB8(self->uF0.f[2], D_L39_0024B3E0 * 0.017453292f);
        func_0038D308(self->vC0, &self->uF0);
        {
            f32 a = g->f250 * 0.75f;
            f32 b = g->f25C * 0.75f;
            g->w21C = -1;
            g->f254 = a * a;
            g->f20C = b * b;
        }
        if (self->hAA == 0x1A63 || self->hAA == 0x1BBD) {
            g->p258 = func_003C24B0(0x15CA, 0);
        } else if (self->hAA == 0x16FE) {
            g->p258 = func_003C24B0(0x1B17, 0);
        }
        if (self->hAA == 0x1BBD) {
            g->f40 = 1.5f;
        }
        *(u128_t *)g->p258->q10 = *(u128_t *)self->q10;
        *(u128_t *)g->p258->uF0.q = *(u128_t *)self->uF0.q;
        g->p258->f2C = g->p258->p24->f24 * (self->f2C / self->p24->f24);
        g->p258->h32 = self->h32;
        g->p258->b31 = 1;
        g->p258->pB8 = self;
        g->p258->d38 = self->d38;
        func_003C7C38(g->p258);
        self->w98 = 0;
        self->h34 = (self->h34 | 0x41) & 0xEFFF;
        func_L39_005F2FF8(self, 1);
        g->b3E = 3;
        self->h34 |= 0x4000;
        g->f30 = g->h34;
        if (g->w230 != 0) {
            func_003C3938(self, 2, 0);
            self->f48 = 1.0f;
            func_L01_004450F0(self, 3, -1);
        } else {
            func_L01_004450F0(self, 1, -1);
        }
        func_0038CB78(&g->blk[0], 0, 0x80);
        func_0038CB78(&g->blk[1], 0, 0x80);
        func_0038CB78(&g->blk[2], 0, 0x80);
        g->blk[0].f70 = 1.0f;
        g->blk[1].f70 = 1.0f;
        g->blk[2].f70 = 1.0f;
        break;
    case 1:
        if (g->w230 == 0) {
            g->b38 = v;
            if (func_L01_004561B8(self) != 0) {
                if (self->b43 != 1) {
                    func_003C3A10(self, 1, 0, 10);
                }
                self->f48 = -1.0f;
                e = &D_L39_0024BF5C[g->w24C];
                if (func_L39_0055D808((u8 *)e) != 0) {
                    func_L39_0066B9A0(e->p68->w1C, self->b21);
                } else if (func_L39_0055D818((u8 *)e) != 0) {
                    func_L39_0066BA78(e->p68->w2C, self->b21);
                }
            }
            if (self->b60 & 2) {
                func_003C3938(self, 0, 0);
                self->w98 = 0;
                self->h34 = (self->h34 | 0x41) & 0xEFFF;
                func_L39_005F2FF8(self, 1);
                g->p258->h34 &= 0xFFBE;
                g->p258->h34 |= g->p258->p24->h44 & 0x1000;
                g->p258->w98 = g->p258->p24->w10;
            }
        } else {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0) {
            g->p258->h34 |= 0x41;
            g->p258->h34 &= 0xEFFF;
            g->p258->w98 = 0;
            func_L39_005F2FF8(g->p258, 1);
            self->h34 &= 0xFFBE;
            self->h34 |= self->p24->h44 & 0x1000;
            self->w98 = self->p24->w10;
            if (self->b43 != 2) {
                func_003C3A10(self, 2, 0, 10);
            }
            self->f48 = 1.0f;
        }
        break;
    case 9:
        if ((D_L39_0024112C & 0x1F) == 0) {
            self->w98 = 0;
            self->h34 = (self->h34 | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            if (g->p258 != 0) {
                g->p258->h34 |= 0x41;
                g->p258->h34 &= 0xEFFF;
                g->p258->w98 = 0;
                func_L39_005F2FF8(g->p258, 1);
            }
            if (func_003D4D00(&self->q10, 1, 0, 0, 0.75f) == 0) {
                func_L39_0055D828(self);
                if (g->w230 != 0) {
                    func_L01_004450F0(self, 3, -1);
                } else {
                    if (self->b43 != 0) {
                        func_003C3A10(self, 0, 0, 1);
                    }
                    self->f48 = 1.0f;
                    func_L01_004450F0(self, 1, -1);
                }
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            func_L39_0055F8D8(self, g);
            g->p258->h34 |= 0x41;
            g->p258->h34 &= 0xEFFF;
            g->p258->w98 = 0;
            func_L39_005F2FF8(g->p258, 1);
            self->h34 &= 0xFFBE;
            self->h34 |= self->p24->h44 & 0x1000;
            self->w98 = self->p24->w10;
            if (self->b43 != 1) {
                func_003C3A10(self, 1, 0, 10);
            }
            self->f48 = 1.0f;
        }
        if (self->b60 & 2) {
            if (self->b43 != 2) {
                func_003C3A10(self, 2, 0, 10);
            }
            self->f48 = 1.0f;
            func_L01_004450F0(self, 4, -1);
        }
        func_L39_0055F808(self, g);
        break;
    case 4:
        func_L39_0055F8D8(self, g);
        if ((self->b60 & 2) || self->h96 >= 11) {
            func_L39_0055F3C0(self);
        }
        func_L39_0055F808(self, g);
        if (self->hAA == 0x1A63) {
            P_0055E798 *tt;
            o = 0;
            tt = func_L39_0061D7B0(g->w220);
            if (tt != 0) {
                if ((tt->b3 & 0xF) == 0) {
                    o = tt;
                }
            }
            if (o == 0) {
                break;
            }
            if (func_L39_00648840(o, 0x1D) != 0) {
                break;
            }
            flag = 1;
            if (D_L39_00241640 != 0) {
                if (D_L39_00241640[0x18F] == 0) {
                    flag = 0;
                }
            }
            if (flag == 0) {
                break;
            }
            n = g->w22C;
            if (n >= 0) {
                if (n < 2) {
                    Q_0055E798 *q = ((E_0055E798 *)((u8 *)D_L39_0024BF5C + (D_L39_00352B4C[0]->w40[n] << 8)))->p68;
                    s16 *lst = D_L39_002927E0[q->wAC];
                    for (;;) {
                        s32 k = q->wAC;
                        E_0055E798 *le;
                        if ((u8)k == 0xFF) {
                            break;
                        }
                        if (D_L39_0024BF98 < k) {
                            break;
                        }
                        if (lst == 0) {
                            break;
                        }
                        if (lst[-1] < 0) {
                            if (lst != D_L39_002927E0[k]) {
                                break;
                            }
                        }
                        le = (E_0055E798 *)((u8 *)D_L39_0024BF5C + ((*lst & 0x7FFF) << 8));
                        if (le == 0) {
                            break;
                        }
                        if ((O_0055E798 *)le == self) {
                            flag = 0;
                            break;
                        }
                        lst++;
                    }
                }
            }
            if (flag != 0) {
                func_L39_00648960(o, 0x1D);
            }
        } else if (self->hAA == 0x1BBD) {
            P_0055E798 *tt;
            tt = func_L39_0061D7B0(g->w220);
            if (tt == 0) {
                break;
            }
            if ((tt->b3 & 0xF) != 3) {
                break;
            }
            o = tt->w2D8;
            if (o == 0) {
                o = tt->w2DC;
                if (o == 0) {
                    break;
                }
            }
            if (func_L39_00648840(o, 0x20) != 0) {
                break;
            }
            func_L39_00648960(o, 0x20);
        }
        break;
    case 5:
        func_L39_0055F8D8(self, g);
        func_L39_0055F808(self, g);
        if (func_L01_004561B8(self) != 0) {
            if (self->b43 != 3) {
                func_003C3A10(self, 3, 0, 5);
            }
            self->f48 = 1.0f;
        }
        if (self->b60 & 2) {
            if (self->b43 != 2) {
                func_003C3A10(self, 2, 0, 5);
            }
            self->f48 = 1.0f;
            self->b20 = 4;
            g->f218 = func_L39_005B4410(-0.15f, 0.05f);
        }
        break;
    case 6:
    case 7:
        if ((self->h34 & 1) == 0 || (g->p258->h34 & 1) == 0) {
            self->w98 = 0;
            self->h34 = (self->h34 | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            g->p258->h34 |= 0x41;
            g->p258->h34 &= 0xEFFF;
            g->p258->w98 = 0;
            func_L39_005F2FF8(g->p258, 1);
        }
        break;
    case 8:
        break;
    }
    i = g->w24C;
    if (i >= 0) {
        if (func_L39_0055D808((u8 *)&D_L39_0024BF5C_0055E798[i])) {
            s32 c = D_L39_00352B4C[0]->w88[D_L39_0024BF5C[g->w24C].p68->w1C];
            if (c >= 0) {
                s32 o = c * 3;
                self->w78 = 0x80000000 | (D_L39_002462AA.v[o] << 16) | (D_L39_002462A9.v[o] << 8) | D_L39_002462A8.v[o];
            } else {
                self->w78 = 0x80FFFFFF;
            }
        } else if (func_L39_0055D818((u8 *)&D_L39_0024BF5C[g->w24C])) {
            self->w78 = D_L39_0024BF5C_0055E798[g->w24C].w78;
        }
        if (g->p258 != 0) {
            g->p258->w78 = self->w78;
        }
    }
}
/* localdecomp:end func_L39_0055E798 */

INCLUDE_ASM("asm/levels", func_L39_0055F3C0);

/* localdecomp:start func_L39_0055F808 */
typedef struct O_0055F808 {
    u8 pad0[0xE8];
    f32 fE8;
    u8 padEC[0x160 - 0xEC];
    f32 f160;
    u8 pad164[0x1E0 - 0x164];
    f32 f1E0;
    u8 pad1E4[0x210 - 0x1E4];
    f32 f210;
    f32 f214;
} O_0055F808;
typedef struct A_0055F808 {
    u8 pad0[0xF8];
    f32 fF8;
} A_0055F808;
__asm__(".extern D_L39_0024B3D0, 4");
__asm__(".extern D_L39_0024B3D4, 4");
__asm__(".extern D_L39_0024B3D8, 4");
__asm__(".extern D_L39_0024B3DC, 4");
extern f32 D_L39_0024B3D0;
extern f32 D_L39_0024B3D4;
extern f32 D_L39_0024B3D8;
extern f32 D_L39_0024B3DC;
extern f32 func_0038DB00(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L39_0055F808(A_0055F808 *a0, O_0055F808 *a1)
{
    a1->fE8 = func_0038DB00(a1->f210, a0->fF8);
    func_L01_0044E850(a0, (u8 *)a1 + 0x80, 0, D_L39_0024B3D0 * 1.44f, D_L39_0024B3D4 * 1.44f);
    a1->f160 = a1->f214;
    func_L01_0044E850(a0, (u8 *)a1 + 0x100, 2, D_L39_0024B3D8 * 1.44f, D_L39_0024B3DC * 1.44f);
    a1->f1E0 = a1->f214 * 0.35f;
    func_L01_0044E850(a0, (u8 *)a1 + 0x180, 3, D_L39_0024B3D8 * 1.44f, D_L39_0024B3DC * 1.44f);
}
/* localdecomp:end func_L39_0055F808 */
