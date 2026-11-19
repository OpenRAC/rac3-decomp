#include "common.h"

/* localdecomp:start func_L39_0069A630 */
typedef struct O_0069A630 O_0069A630;
typedef struct {
    u8 pad0[0x20];
    void (*f20)(O_0069A630 *, s32, s32);
    void (*f24)(O_0069A630 *, u8 *);
    u8 pad28[0x8];
    void (*f30)(O_0069A630 *, f32 *, f32 *);
    u8 pad34[0x2C];
    void (*f60)(O_0069A630 *, s32);
    s32 (*f64)(O_0069A630 *);
    u8 pad68[0x24];
    s32 (*f8C)(O_0069A630 *);
    u8 pad90[0x18];
    void (*fA8)(O_0069A630 *, s32);
    s32 (*fAC)(O_0069A630 *);
    u8 padB0[0x8];
    void (*fB8)(O_0069A630 *, u8 *);
    u8 padBC[0x8];
    u8 *(*fC4)(O_0069A630 *);
} V_0069A630;
struct O_0069A630 {
    u8 pad0[0x4];
    s32 f4;
    u8 pad8[0x58];
    V_0069A630 *f60;
};
typedef struct {
    u8 pad0[0x110];
    O_0069A630 *objs[12];
    u8 pad140[0x150];
    s32 f290;
    u8 pad294[0x14];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0;
    s32 f2D4;
    u8 pad2D8[0x4];
    s32 f2DC;
    s32 f2E0;
    s32 f2E4;
    s32 f2E8;
    u8 pad2EC[0x18];
    u8 f304[0x80];
    u8 f384[1];
} S_0069A630;
typedef struct {
    u8 pad0[0xE0];
    s32 fE0;
    u8 padE4[0x1A0];
    s32 f284;
} G_0069A630;
typedef struct {
    u8 pad0[0x4C];
    s32 *f4C;
} P_0069A630;

extern G_0069A630 *D_00247914;
__asm__(".extern D_00247914, 16");
extern u8 D_00248138[];
extern G_0069A630 *D_001DC204_sda;
extern P_0069A630 *D_001E2050_sda;

s32 func_L39_0068AEF8(S_0069A630 *, s32);
void func_0038CBC8(u8 *, s32);
void func_00120D28(u8 *, u8 *, s32);
void func_L39_0069BED8(S_0069A630 *);
void func_L39_0069C088(S_0069A630 *);
s32 func_L39_005C4350(void);
s32 func_L39_00688340(s32, s32, s32);
void func_L39_006BD408(s32, s32);
void func_L39_00687750(G_0069A630 *, s32 *);
s32 func_L39_006CC350(u8 *, s32);
s32 func_L39_00687508(G_0069A630 *, u8 *, s32, s32, s32, s32 *, s32 *, s32 *,
                       s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
u8 *func_00381FF0(s32);
s32 func_L39_00687450(G_0069A630 *, u8 *, u8 *, s32, s32, s32, s32);
void func_L39_0068B2F8(S_0069A630 *, s32, s32);
s32 func_L39_0069AEF0(S_0069A630 *);
void func_L39_0068A2D0(S_0069A630 *, s32, s32, s32, f32, f32);

s32 func_L39_0069A630(S_0069A630 *self, s32 arg1) {
    s32 busy;

    busy = func_L39_0068AEF8(self, arg1);
    if ((u32)(arg1 - 3) < 2 || arg1 == 7) {
        switch (self->f290) {
        case 0: {
            u8 *s = self->objs[0]->f60->fC4(self->objs[0]);
            if (s != 0 && s[0] != 0) {
                func_0038CBC8(self->f304, 0x11);
                func_00120D28(self->f304, s, 0x10);
            } else {
                self->objs[0]->f60->fB8(self->objs[0], self->f304);
            }
            break;
        }
        case 1:
            func_L39_0069BED8(self);
            break;
        case 2: {
            s32 old = self->f2AC;
            func_L39_0069C088(self);
            if (old != self->f2AC) {
                self->f2B0 = self->f2AC;
            }
            break;
        }
        case 3: {
            s32 a, b, c, d, ex;
            a = self->objs[4]->f60->fAC(self->objs[4]);
            b = self->objs[5]->f60->fAC(self->objs[5]);
            c = self->objs[6]->f60->fAC(self->objs[6]);
            d = self->objs[3]->f60->fAC(self->objs[3]);
            ex = c + b + a - d;
            if (ex > 0) {
                if (ex < a) {
                    a -= ex;
                    ex = 0;
                } else {
                    ex -= a;
                    a = 0;
                }
                if (ex < b) {
                    b -= ex;
                    ex = 0;
                } else {
                    ex -= b;
                    b = 0;
                }
                if (ex < c) {
                    c -= ex;
                    ex = 0;
                } else {
                    ex -= c;
                    c = 0;
                }
            }
            self->objs[4]->f60->fA8(self->objs[4], a);
            self->objs[5]->f60->fA8(self->objs[5], b);
            self->objs[6]->f60->fA8(self->objs[6], c);
            break;
        }
        case 5: {
            s32 a, b, c, d;
            a = self->objs[4]->f60->fAC(self->objs[4]);
            b = self->objs[5]->f60->fAC(self->objs[5]);
            d = self->objs[3]->f60->fAC(self->objs[3]);
            c = self->objs[6]->f60->fAC(self->objs[6]);
            d -= c;
            if (d < b) {
                b = 0;
            }
            d -= b;
            if (d < a) {
                a = d;
            }
            self->objs[4]->f60->fA8(self->objs[4], a);
            self->objs[5]->f60->fA8(self->objs[5], b);
            break;
        }
        case 4: {
            s32 a, b, c, d;
            a = self->objs[4]->f60->fAC(self->objs[4]);
            b = self->objs[5]->f60->fAC(self->objs[5]);
            d = self->objs[3]->f60->fAC(self->objs[3]);
            c = self->objs[6]->f60->fAC(self->objs[6]);
            d -= c;
            if (d < a) {
                a = 0;
            }
            d -= a;
            if (d < b) {
                b = d;
            }
            self->objs[4]->f60->fA8(self->objs[4], a);
            self->objs[5]->f60->fA8(self->objs[5], b);
            break;
        }
        case 6: {
            s32 a, b, c, d;
            a = self->objs[4]->f60->fAC(self->objs[4]);
            b = self->objs[5]->f60->fAC(self->objs[5]);
            d = self->objs[3]->f60->fAC(self->objs[3]);
            c = self->objs[6]->f60->fAC(self->objs[6]);
            if (d < c + b + a) {
                self->objs[6]->f60->fA8(self->objs[6], 1);
            }
            break;
        }
        case 7:
            self->f2DC = self->objs[7]->f60->fAC(self->objs[7]);
            if (((self->f2AC == 1 && self->f2E4 == 0) || (self->f2AC == 2 && self->f2E0 == 0)) &&
                self->f2DC == 0) {
                if (arg1 == 3) {
                    self->f2DC = 0x23;
                } else {
                    self->f2DC = 5;
                }
                self->objs[7]->f60->fA8(self->objs[7], self->f2DC);
            }
            break;
        case 8:
            if (self->objs[8]->f60->f64(self->objs[8])) {
                if (self->f2A8 != 4) {
                    self->objs[9]->f60->f20(self->objs[9], 3, 0);
                } else {
                    self->objs[9]->f60->f20(self->objs[9], 2, 0);
                }
            } else {
                self->objs[9]->f60->f20(self->objs[9], 0, 0);
            }
            break;
        }
    }

    if (self->objs[6]->f60->fAC(self->objs[6]) == 2 && func_L39_005C4350() < 2) {
        self->objs[6]->f60->fA8(self->objs[6], 1);
    }
    if (((self->f2AC == 1 && self->f2E4 == 0) || (self->f2AC == 2 && self->f2E0 == 0)) &&
        self->f2DC == 0) {
        self->f2DC = 5;
        self->objs[7]->f60->fA8(self->objs[7], 5);
    }

    if (busy != 0) {
        return 1;
    }

    if (arg1 == 5) {
        func_L39_00688340(0x17, 0, 0);
        if (self->f2A8 == 0) {
            D_00247914->f284 = 0x19;
            return 1;
        }
        func_L39_006BD408(D_00247914->fE0, *D_001E2050_sda->f4C);
        D_00247914->f284 = 0x1F;
        return 1;
    }
    if (arg1 == 7) {
        if (self->f290 == 10) {
            func_L39_00688340(4, 0, 0);
            func_L39_00687750(D_00247914, &self->f2D4);
            return 1;
        }
        if (self->f290 == 11) {
            s32 t;
            G_0069A630 *g;
            s32 v;
            func_L39_00688340(4, 0, 0);
            t = 0;
            if (self->f2A8 == 3) {
                t = 2;
            } else if (self->f2A8 == 2) {
                t = 1;
            } else if (self->f2A8 == 0 || self->f2A8 == 1) {
                t = 0;
            } else if (self->f2A8 == 4) {
                t = func_L39_006CC350(self->f384, 0xC);
            }
            g = D_001DC204_sda;
            v = self->objs[1]->f60->f8C(self->objs[1]);
            func_L39_00687508(g, D_00248138, t, v, self->f2AC, &self->f2B4,
                              &self->f2E8, &self->f2E0, &self->f2B8, &self->f2BC, &self->f2C0,
                              &self->f2E4, &self->f2C4, &self->f2C8, &self->f2CC, &self->f2D0);
            self->f2B8 = (self->f2A8 == 3) ? 1 : self->f2B8;
            return 1;
        }
        if (self->f290 == 9) {
            u8 buf[0x20];
            G_0069A630 *g;
            u8 *name;
            func_L39_00688340(4, 0, 0);
            func_00120D28(buf, (u8 *)self->objs[9] + 0x14, 0x11);
            buf[0x10] = 0;
            g = D_001DC204_sda;
            name = func_00381FF0(0x1183);
            func_L39_00687450(g, name, buf, 0, 0x11, 1, 0);
            if (buf[0] == 0) {
                self->objs[8]->f60->f60(self->objs[8], 0);
                self->objs[9]->f60->f20(self->objs[9], 0, 0);
                func_L39_0068B2F8(self, 8, 0);
            } else {
                self->objs[9]->f60->f24(self->objs[9], buf);
            }
            return 1;
        }
    } else if (arg1 == 6) {
        func_L39_00688340(4, 0, 0);
        if (func_L39_0069AEF0(self)) {
            D_001DC204_sda->f284 = 0x21;
            return 1;
        }
    }

    {
        O_0069A630 *o;
        f32 x, y;
        s32 i, first, last, flags, k;

        o = self->objs[self->f290];
        o->f60->f30(o, &x, &y);
        first = -1;
        last = -1;
        for (i = 0; i < 12; i++) {
            if ((k = self->objs[i]->f4) == 3 || k == 4 || k == 5) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        flags = self->f290 != first;
        if (self->f290 != last) {
            flags |= 2;
        }
        func_L39_0068A2D0(self, flags, 3, 3, 0.293f, y + -0.0015f);
    }
    return 0;
}
/* localdecomp:end func_L39_0069A630 */
