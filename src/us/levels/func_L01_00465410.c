#include "common.h"

/* localdecomp:start func_L01_00465410 */
typedef unsigned int Q_00465410 __attribute__((mode(TI)));

typedef struct {
    Q_00465410 q;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
} T_00465410;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    u8 fA;
    u8 fB;
    f32 fC;
    union {
        Q_00465410 q;
        f32 f[4];
    } f10;
    T_00465410 f20;
} S_00465410;

extern u8 *D_L01_002211A4_00465410[];

S_00465410 *func_L01_00465410(Q_00465410 *a0, Q_00465410 *a1, s32 a2, s32 a3) {
    extern f32 func_0037E250(f32, f32);
    extern void *func_L01_0045E438(s32);
    S_00465410 *p = func_L01_0045E438(0x23);
    if (p != 0) {
        T_00465410 *s;
        p->f10.q = *a0;
        p->f1 = 0;
        s = &p->f20;
        p->f4 = 0x80808080;
        p->f9 = 0x12;
        p->f3 = 0x44;
        p->fC = func_0037E250(10500.0f, 16800.0f);
        p->f2 = *D_L01_002211A4_00465410[0];
        s->q = *a1;
        s->f14 = a3;
        s->f10 = a2;
        s->f18 = p->f10.f[2];
        if (a2 == 2) {
            s->f18 = 0.0f;
        }
        s->f1C = func_0037E250(0.0029166667f, 0.005f);
    }
    return p;
}

/* localdecomp:end func_L01_00465410 */
