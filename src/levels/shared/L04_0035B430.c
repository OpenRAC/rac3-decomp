#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_0035B430);

INCLUDE_ASM("asm/levels", func_L04_0035B5D8);

INCLUDE_ASM("asm/levels", func_L04_0035B838);

/* localdecomp:start func_L04_0035B908 */
typedef int u128_35A960 __attribute__((mode(TI)));

typedef struct {
    u128_35A960 a;
    u128_35A960 b;
    s32 active;
} S_35A960;

extern s32 func_L04_004BB4F8(u128_35A960 *, u128_35A960 *, f32);
extern u32 func_L04_004BB268(void);
extern s32 func_L04_004BB348(u32, s32, s32, s32);
extern void func_L04_004BB288(u32, f32);
extern void func_L04_004BB2E0(u32, u128_35A960 *, u128_35A960 *);
extern void func_L04_004BB3A8(u32);

void func_L04_0035B908(s32 arg0, S_35A960 *p, S_35A960 *q, u32 *h) {
    u128_35A960 v[2];
    u32 n;

    if (p->active == 1 || q->active == 1) {
        if (p->active == 1) {
            v[0] = p->a;
            if (q->active == 1) {
                v[1] = q->b;
            } else {
                v[1] = p->b;
            }
        } else {
            v[0] = q->a;
            v[1] = q->b;
        }
        if (*h == 0xFFFFFFFF) {
            if (func_L04_004BB4F8(&v[0], &v[1], 24.0f) == 0) {
                n = func_L04_004BB268();
                *h = n;
                func_L04_004BB348(n, 0, arg0, 6455);
                func_L04_004BB288(*h, 24.0f);
                func_L04_004BB2E0(*h, &v[0], &v[1]);
            }
        } else if (func_L04_004BB4F8(&v[0], &v[1], 24.0f) == 0) {
            func_L04_004BB2E0(*h, &v[0], &v[1]);
        } else {
            func_L04_004BB3A8(*h);
            *h = 0xFFFFFFFF;
        }
    } else if (*h != 0xFFFFFFFF) {
        func_L04_004BB3A8(*h);
        *h = 0xFFFFFFFF;
    }
}
/* localdecomp:end func_L04_0035B908 */

/* localdecomp:start func_L04_0035BA58 */
extern s32 func_L01_00456250(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L04_003796E0(u8 *);
extern void func_L01_0038B988_0035BA58(void *);
extern void func_L04_003796C8(u8 *);
extern void func_L04_0035A4F8(void *, void *);
extern u8 *D_L04_001DFD9C;
extern s32 D_L04_001DF940;

typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } P_35BA58;
typedef struct { u8 b[0x30]; } Q_35BA58;
typedef struct {
    s32 w0;
    u8 *w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 pad20[3];
    s32 w2C;
    u8 pad30[0x20];
    Q_35BA58 q[4];
    P_35BA58 p[4];
} S_35BA58;

s32 func_L04_0035BA58(void *a0, S_35BA58 *s) {
    s32 ok;
    s32 i;
    s32 c;
    s32 none;
    P_35BA58 *p;
    Q_35BA58 *q;
    none = -1;
    c = s->wC;
    if (c == none && s->w10 == none) {
        return s->w18;
    }
    ok = 1;
    if (c != none && func_L01_00456250(D_L04_001DFD9C + (c << 8)) == 0) {
        ok = 0;
    }
    if (s->w10 != none && func_L01_00456250(D_L04_001DFD9C + (s->w10 << 8)) == 0) {
        ok = 0;
    }
    if (ok == s->w14) {
        if (s->w18 != 0) {
            if (s->w2C == 0) {
                s->w2C = 30;
            }
            if (func_0038CAD0(&s->w2C) != 0) {
                if (s->w4 != 0) {
                    if (func_L04_003796E0(s->w4) != 0) {
                        func_L01_0038B988_0035BA58(s->w4);
                        s->w4 = 0;
                    } else {
                        func_L04_003796C8(s->w4);
                    }
                }
                q = s->q;
                p = s->p;
                for (i = 0; i < 4; i++, q++, p++) {
                    if (p->w4 < D_L04_001DF940) {
                        func_L04_0035A4F8(q, p);
                    }
                }
                s->w18 = 0;
            }
        } else {
            s->w2C = 0;
            if (s->w4 != 0 && func_L04_003796E0(s->w4) != 0) {
                func_L01_0038B988_0035BA58(s->w4);
                s->w4 = 0;
            }
        }
    } else if (s->w18 == 0) {
        if (s->w2C == 0) {
            s->w2C = 30;
        }
        if (func_0038CAD0(&s->w2C) != 0) {
            s->w18 = 1;
        }
    } else {
        s->w2C = 0;
    }
    if (s->w1C != 0 && s->w18 != s->w14) {
        s->wC = -1;
        s->w10 = -1;
    }
    return s->w18;
}
/* localdecomp:end func_L04_0035BA58 */

INCLUDE_ASM("asm/levels", func_L04_0035BC10);

INCLUDE_ASM("asm/levels", func_L04_0035C1B8);

INCLUDE_ASM("asm/levels", func_L04_0035C2B0);

INCLUDE_ASM("asm/levels", func_L04_0035C398);

INCLUDE_ASM("asm/levels", func_L04_0035C9C8);
