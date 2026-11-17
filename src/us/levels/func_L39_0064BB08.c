#include "common.h"

/* NTSC-U counterpart of func_L39_0064E3B0 (src/levels/shared/L39_0064E3B0.c) */
/* localdecomp:start func_L39_0064BB08 */
#include "vu0.h"
typedef int Q_0064E3B0 __attribute__((mode(TI)));
typedef struct {
    s32 w0;
    s32 w4;
    u8 p8[0x18];
    s32 w20;
    u8 p24[8];
} T_0064E3B0;

typedef struct {
    u8 p0[0xA0];
    u8 vA0[0x18];
    f32 fB8;
    u8 pBC[0x120 - 0xBC];
    u8 v120[0x40];
    u8 v160[0x2DE - 0x160];
    s16 h2DE;
    u8 p2E0[0x10];
    s32 w2F0;
    u8 p2F4[0x469 - 0x2F4];
    u8 b469;
    u8 p46A[0x610 - 0x46A];
    f32 f610;
    u8 p614[8];
    s32 w61C;
    u8 p620[8];
    f32 f628;
    u8 p62C[0xFB0 - 0x62C];
    f32 fFB0;
    u8 pFB4[0xFC0 - 0xFB4];
    Q_0064E3B0 qFC0;
    f32 fFD0;
    u8 pFD4[0x1040 - 0xFD4];
    Q_0064E3B0 q1040;
    u8 p1050[0x1064 - 0x1050];
    u8 *w1064;
    s32 w1068;
    f32 f106C;
    u8 p1070[4];
    f32 f1074;
    u8 p1078[4];
    s16 h107C;
    u8 p107E[0x1A06 - 0x107E];
    u8 b1A06;
} S_0064E3B0;

extern T_0064E3B0 D_L39_0047A968[];
extern s32 D_L39_00242B3C;
extern f32 func_00388800(void *, void *);
extern f32 func_003887C8(void *, void *);
extern void func_003BEBF8(void *, f32, f32);
extern f32 func_L39_00631430(void *, void *, s32);
extern f32 func_003893C8(f32, f32);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_L39_0062D4A8(void *, f32, f32, f32);
extern void func_L39_00630DD8(void *, f32, f32);
extern void func_L39_00630EE0(void *, void *);
extern void func_L39_00630E28(void *, f32);
extern void func_L39_006301D8(void *, void *, void *, f32);
extern void func_L39_00635C78(void *, f32, f32, f32);

void func_L39_0064BB08(S_0064E3B0 *p)
{
    T_0064E3B0 *t;
    f32 d;
    f32 e;
    f32 r;
    f32 lo;
    f32 range;
    f32 hi;
    f32 k;
    f32 a;
    f32 b;
    s32 turn;

    if (p->w61C != 0 || p->f628 < (f32)D_L39_0047A968[p->h107C].w20) {
        p->b469 = 2;
    }
    t = &D_L39_0047A968[p->h107C];
    p->fFB0 = 0.0f;
    if (p->w1064 != 0 && p->w2F0 < 4) {
        d = func_00388800(p->w1064 + 0x10, p->vA0);
        if (D_L39_00242B3C != 0) {
            d = func_003887C8(p->w1064 + 0x10, p->vA0);
        }
        d = d - 0.5f;
        if (d < 0.0f) {
            d = 0.0f;
        }
        if (t->w4 == 0) {
            lo = 0.75f;
            range = 0.800000012f;
            hi = 4.0f;
        } else if (t->w4 == 1) {
            lo = 0.600000024f;
            range = 1.70000005f;
            hi = 4.0f;
        } else {
            lo = 1.29999995f;
            range = 1.70000005f;
            hi = 1.89999998f;
        }
        if (fabs_asm(e = d - lo) < range + 3.0f) {
            r = e / 0.899999976f;
            if (hi < r) {
                r = hi;
            }
            if (1.0f < r) {
                p->f1074 = r;
            }
        }
    }
    switch (t->w4) {
    case 0:
        if (p->f628 < 18.0f) {
            p->fFB0 = p->f1074 * 0.07333333790302277f;
        }
        break;
    case 1:
        if (p->w61C != 0 || p->f628 < 9.0f) {
            if (8.0f < p->f628) {
                p->fFB0 = p->f1074 * 0.05000000447034836f;
            } else if (7.0f < p->f628) {
                p->fFB0 = p->f1074 * 0.07500000298023224f;
            } else {
                p->fFB0 = p->f1074 * 0.0949999988079071f;
            }
        }
        break;
    case 2:
        if (p->w61C != 0 || p->f628 < 12.0f) {
            p->fFB0 = p->f1074 * 0.06166667118668556f;
        }
        break;
    }
    func_003BEBF8(&p->f610, 1.0f, 0.200000003f);
    if (p->w1068 != 0 || p->w1064 != 0) {
        if (p->b1A06 != 0) {
            a = func_L39_00631430(p, &p->q1040, 0);
        } else {
            a = func_003893C8(p->f106C, p->fB8);
        }
        b = fabs_asm(a);
        if (t->w4 == 1 && 0.0f < a) {
            p->f610 = 1.0f / (b + 1.0f);
        }
        p->fFD0 = p->f106C;
        p->qFC0 = p->q1040;
        func_L39_00630AC0(p, 0, 0.05000000074505806f, 0.20000000298023224f, 0.28216156363487244f);
    } else {
        turn = 1;
        if (t->w4 == 1 && p->w61C == 0 && 7.0f < p->f628) {
            turn = 0;
        }
        if (turn) {
            func_L39_0062D4A8(p, 5.0f, 0.785398185f, 0.785398185f);
        }
    }
    func_L39_00630DD8(p, 0.010277777910232544f, 0.007777777966111898f);
    if (p->w1068 != 0) {
        if (p->b1A06 != 0) {
            func_L39_00630EE0(p, &p->q1040);
        } else {
            func_L39_00630E28(p, p->f106C);
        }
    } else {
        func_L39_00630E28(p, 99999.0f);
    }
    if (p->h2DE != 0) {
        func_L39_006301D8(p, p->v120, p->v160, 0.0069444444961845875f);
    } else {
        func_L39_006301D8(p, p->v120, p->v120, 0.015000000596046448f);
    }
    func_L39_00635C78(p, 3.70000005f, 0.0f, 0.349999994f);
}
/* localdecomp:end func_L39_0064BB08 */
