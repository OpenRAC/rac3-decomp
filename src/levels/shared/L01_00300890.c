#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* declared by functions of L01_003002A8.c, which this file was cut from */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_003C7C38(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C2880(u8 *);

/* localdecomp:start func_L01_00300890 */
typedef struct {
    f32 f0, f4, f8;
    union {
        s32 w;
        f32 f;
    } c;
    u8 p10[0xC];
    u8 b1C;
    u8 p1D[3];
    u8 *p20;
    u8 b24, b25, b26, b27, b28, b29, b2A, b2B, b2C, b2D, b2E, b2F, b30, b31, b32, b33;
    f32 f34, f38, f3C, f40, f44;
    union {
        unsigned long q;
        struct {
            s32 w48;
            s32 w4C;
        } s;
    } u;
    s32 w50;
    f32 f54, f58, f5C, f60;
    s32 w64;
    u8 b68, b69, b6A, b6B;
    u16 h6C, h6E, h70, h72, h74, h76, h78, h7A;
    u8 b7C, b7D, b7E, b7F;
} E00300890;
typedef struct {
    u8 p00[0x20];
    u8 b20;
    u8 p21[0xF];
    u8 b30;
    u8 p31[0x37];
    E00300890 *b;
    u8 p6C[0x50];
    u8 bBC;
} O00300890;
typedef struct {
    f32 f0, f4, f8, fC;
    u8 p10[0xC];
    f32 f1C;
} T00300890;

extern u8 *D_L01_001E001C;
extern T00300890 D_L01_001F1B40[];
extern s32 func_0038CAD0(s32 *);
extern s32 func_0038CB00(void *);
extern s32 func_L01_0040E020(void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DC20(Vec4 *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00424D88(s32);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);

void func_L01_00300890(O00300890 *self) {
    E00300890 *b;
    s32 fl;
    s32 fl2 = 0;
    s32 fl3 = 0;
    s32 fl4 = 0;
    s32 idx;
    Vec4 p;
    Vec4 v;
    u8 *par;

    if (self == 0) {
        return;
    }
    b = self->b;
    fl = 0;
    if (b == 0) {
        return;
    }
    if (self->b20 == 0) {
        self->b30 = 0xFF;
        self->bBC = b->b1C;
        *(s128 *)((u8 *)b + 0x10) = *(s128 *)((u8 *)self + 0x10);
        b->b1C = self->bBC;
        b->c.w = b->u.s.w4C;
        b->h74 = b->h6C;
        b->h76 = b->h6E;
        b->h78 = b->h70;
        b->h7A = b->h72;
        b->f54 = (f32)b->b25 / 100.0f;
        b->f58 = (f32)b->b2A / 100.0f;
        b->f5C = (f32)b->b2F / 100.0f;
        b->f60 = b->f34;
        b->w50 = -1;
        if (b->w64 != -1) {
            b->p20 = D_L01_001E001C + (b->w64 << 8);
        }
        if (b->f40 < 0.0f) {
            b->f40 = -b->f40;
        }
        if (b->f44 < 0.0f) {
            b->f44 = -b->f44;
        }
        self->b20 = 1;
    }
    if (self->bBC != 0) {
        self->bBC--;
        return;
    }
    if (b->u.s.w48 != -1 && func_0038CAD0(&b->u.s.w48)) {
        if (b->w50 != -1) {
            func_L01_00424D88(b->w50);
            b->w50 = -1;
        }
        func_003C2880((u8 *)self);
        return;
    }
    p.q = *(s128 *)((u8 *)self + 0x10);
    p.f[3] = b->f60;
    idx = func_0038DC20(&p, 255.0f);
    if (idx != -1) {
    par = b->p20;
    if (par != 0) {
        v.q = *(s128 *)(par + 0x10);
    } else {
        v.q = *(s128 *)((u8 *)b + 0x10);
    }
    if (!(b->u.s.w4C & 0x800000)) {
        Vec4 o;
        if (b->u.s.w4C & 0x100000) {
            if (b->u.s.w4C & 0x200000) {
                o.f[0] = func_003824E0(-b->f0, b->f0);
                o.f[1] = func_003824E0(-b->f4, b->f4);
                o.f[2] = func_003824E0(-b->f8, b->f8);
            } else {
                s32 w = b->c.w;
                Vec4 *pv = &o;
                f32 r;
                b->c.w = 0;
                r = func_003824E0(b->c.f, 1.0f);
                func_0038CE20(pv, b, r);
                b->c.w = w;
            }
        } else {
            s32 w = b->c.w;
            b->c.w = 0;
            o.q = *(s128 *)b;
            b->c.w = w;
        }
        if ((b->u.s.w4C & 0x400000) && b->p20 != 0) {
            func_0038D000(&o, &o, b->p20 + 0xC0);
        }
        vec_add_ab((u8 *)self + 0x10, &v, &o);
    } else {
        *(s128 *)((u8 *)self + 0x10) = v.q;
    }

    /* channel f60 */
    if (b->h72 != 0) {
        if (func_0038CB00(&b->h7A)) {
            b->h7A = (b->h72 * 5 + 2) / 6;
            if (b->u.s.w4C & 4) {
                b->f60 = b->f3C;
                b->u.s.w4C &= ~8U;
                fl = 1;
            }
        }
    }
    if (!(b->u.s.w4C & 0x80000)) {
        if ((b->u.q & 0x300000000UL) == 0x200000000UL) {
            b->u.s.w4C ^= 2;
        }
        if (!(b->u.s.w4C & 2)) {
            if (b->u.s.w4C & 8) {
                b->f60 = b->f60 - b->f44 * 1.2f;
                if (b->f60 <= b->f3C) {
                    b->f60 = b->f3C;
                    if (b->u.s.w4C & 4) {
                        if ((b->h72 * 5 + 2) / 6 == 0) {
                            b->u.s.w4C ^= 8;
                        }
                    }
                }
            } else {
                b->f60 = b->f60 + b->f40 * 1.2f;
                if (b->f38 <= b->f60) {
                    b->f60 = b->f38;
                    if (!(b->u.s.w4C & 1)) {
                        b->u.s.w4C ^= 8;
                    } else {
                        b->u.s.w4C = (b->u.s.w4C | 2) ^ 8;
                        b->b7F = (b->b6B * 5 + 2) / 6;
                    }
                }
            }
        } else {
            if (b->b6B != 0 && func_L01_0040E020(&b->b7F)) {
                b->u.s.w4C ^= 2;
            }
        }
    } else if (b->h72 == 0 || fl == 1) {
        b->f60 = func_003824E0(b->f3C, b->f38);
    }

    /* channel f54 */
    if (b->h6C != 0) {
        if (func_0038CB00(&b->h74)) {
            b->f54 = (f32)b->b27;
            b->u.s.w4C &= ~0x80U;
            b->h74 = (b->h6C * 5 + 2) / 6;
        }
    }
    if (!(b->u.s.w4C & 0x10000)) {
        if ((b->u.q & 0x3000000000UL) == 0x2000000000UL) {
            b->u.s.w4C ^= 0x20;
        }
        if (!(b->u.s.w4C & 0x20)) {
            if (b->u.s.w4C & 0x80) {
                b->f54 = b->f54 - ((f32)b->b29 / 100.0f) * 1.2f;
                if (b->f54 <= (f32)b->b27 / 100.0f) {
                    b->f54 = (f32)b->b27 / 100.0f;
                    if (b->u.s.w4C & 0x40) {
                        if (b->h6C == 0) {
                            b->u.s.w4C ^= 0x80;
                        }
                    }
                }
            } else {
                b->f54 = b->f54 + ((f32)b->b28 / 100.0f) * 1.2f;
                if ((f32)b->b26 / 100.0f <= b->f54) {
                    b->f54 = (f32)b->b26 / 100.0f;
                    if (!(b->u.s.w4C & 0x10)) {
                        b->u.s.w4C ^= 0x80;
                    } else {
                        b->u.s.w4C = (b->u.s.w4C | 0x20) ^ 0x80;
                        b->b7C = (b->b68 * 5 + 2) / 6;
                    }
                }
            }
        } else {
            if (b->b68 != 0 && func_L01_0040E020(&b->b7C)) {
                b->u.s.w4C ^= 0x20;
            }
        }
    } else if (b->h6C == 0 || fl2 == 1) {
        b->f54 = func_003824E0((f32)b->b27 / 100.0f, (f32)b->b26 / 100.0f);
    }

    /* channel f58 */
    if (b->h6E != 0) {
        if (func_0038CB00(&b->h76)) {
            b->f58 = (f32)b->b2C;
            b->u.s.w4C &= ~0x800U;
            b->h76 = (b->h6E * 5 + 2) / 6;
        }
    }
    if (!(b->u.s.w4C & 0x20000)) {
        if ((b->u.q & 0x30000000000UL) == 0x20000000000UL) {
            b->u.s.w4C ^= 0x200;
        }
        if (!(b->u.s.w4C & 0x200)) {
            if (b->u.s.w4C & 0x800) {
                b->f58 = b->f58 - ((f32)b->b2E / 100.0f) * 1.2f;
                if (b->f58 <= (f32)b->b2C / 100.0f) {
                    b->f58 = (f32)b->b2C / 100.0f;
                    if (b->u.s.w4C & 0x400) {
                        if (b->h6E == 0) {
                            b->u.s.w4C ^= 0x800;
                        }
                    }
                }
            } else {
                b->f58 = b->f58 + ((f32)b->b2D / 100.0f) * 1.2f;
                if ((f32)b->b2B / 100.0f <= b->f58) {
                    b->f58 = (f32)b->b2B / 100.0f;
                    if (!(b->u.s.w4C & 0x100)) {
                        b->u.s.w4C ^= 0x800;
                    } else {
                        b->u.s.w4C = (b->u.s.w4C | 0x200) ^ 0x800;
                        b->b7D = (b->b69 * 5 + 2) / 6;
                    }
                }
            }
        } else {
            if (b->b69 != 0 && func_L01_0040E020(&b->b7D)) {
                b->u.s.w4C ^= 0x200;
            }
        }
    } else if (b->h6E == 0 || fl3 == 1) {
        b->f58 = func_003824E0((f32)b->b2C / 100.0f, (f32)b->b2B / 100.0f);
    }

    /* channel f5C */
    if (b->h70 != 0) {
        if (func_0038CB00(&b->h78)) {
            b->f5C = (f32)b->b31;
            b->u.s.w4C &= ~0x8000U;
            b->h78 = (b->h70 * 5 + 2) / 6;
        }
    }
    if (!(b->u.s.w4C & 0x40000)) {
        if ((b->u.q & 0x300000000000UL) == 0x200000000000UL) {
            b->u.s.w4C ^= 0x2000;
        }
        if (!(b->u.s.w4C & 0x2000)) {
            if (b->u.s.w4C & 0x8000) {
                b->f5C = b->f5C - ((f32)b->b33 / 100.0f) * 1.2f;
                if (b->f5C <= (f32)b->b31 / 100.0f) {
                    b->f5C = (f32)b->b31 / 100.0f;
                    if (b->u.s.w4C & 0x4000) {
                        if (b->h70 == 0) {
                            b->u.s.w4C ^= 0x8000;
                        }
                    }
                }
            } else {
                b->f5C = b->f5C + ((f32)b->b32 / 100.0f) * 1.2f;
                if ((f32)b->b30 / 100.0f <= b->f5C) {
                    b->f5C = (f32)b->b30 / 100.0f;
                    if (!(b->u.s.w4C & 0x1000)) {
                        b->u.s.w4C ^= 0x8000;
                    } else {
                        b->u.s.w4C = (b->u.s.w4C | 0x2000) ^ 0x8000;
                        b->b7E = (b->b6A * 5 + 2) / 6;
                    }
                }
            }
        } else {
            if (b->b6A != 0 && func_L01_0040E020(&b->b7E)) {
                b->u.s.w4C ^= 0x2000;
            }
        }
    } else if (b->h70 == 0 || fl4 == 1) {
        b->f5C = func_003824E0((f32)b->b31 / 100.0f, (f32)b->b30 / 100.0f);
    }

    if (b->w50 == -1) {
        b->w50 = func_L01_00424CB0((u8 *)self + 0x10, b->f60 * 0.8f, (f32)b->b24 / 100.0f, b->f54, b->f58, b->f5C);
    } else {
        T00300890 *t = &D_L01_001F1B40[b->w50];
        *(s128 *)((u8 *)t + 0x10) = *(s128 *)((u8 *)self + 0x10);
        t->f1C = b->f60 * 0.8f;
        t->f0 = b->f54;
        t->f4 = b->f58;
        t->f8 = b->f5C;
        t->fC = (f32)b->b24 / 100.0f;
    }
    } else if (b->w50 != -1) {
        func_L01_00424D88(b->w50);
        b->w50 = -1;
    }
}
/* localdecomp:end func_L01_00300890 */
