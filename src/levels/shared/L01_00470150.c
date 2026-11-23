#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00470150 */
extern s32 func_00382468(s32);
extern void func_0038D000(void *, void *, void *);
extern const u8 *D_L01_002211FC[];
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    vu0_v4 v10;
    u8 *w20;
    s32 w24;
    f32 f28;
    u8 b2C, b2D, b2E, b2F;
    vu0_v4 v30;
} P_470150;
typedef struct { u8 *w0; s32 w4; f32 f8; u8 bC, bD, bE, bF; u8 pad10[0xC]; f32 f1C; } Q_470150;
P_470150 *func_L01_00470150(vu0_v4 *a0, u8 *a1, s32 a2, s32 a3, s32 a4, f32 f12, s32 a5, s32 a6, s32 a7, f32 f13, f32 f14, u8 s8, s32 s9) {
    vu0_v4 tmp;
    P_470150 *p = (P_470150 *)func_L01_004618E0(0x59);
    Q_470150 *q;
    vu0_v4 *pv;
    s32 v;
    if (p != 0) {
        p->w4 = a2;
        p->fC = f12;
        p->b1 = 0;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b8 = func_00382468(0xFF);
        {
            const u8 *t = D_L01_002211FC[0];
            u8 c = t[a4];
            p->hA = a5;
            p->b2 = c;
        }
        q = (Q_470150 *)&p->w20;
        pv = &p->v30;
        p->w20 = a1;
        q->w4 = a3;
        q->f8 = f13;
        q->bC = a6;
        q->bD = s8;
        p->v30 = *a0;
        q->f1C = f14;
        if (a4 == 0) q->bE = 1;
        q->bF = s9;
        if (a1 != 0) {
            *(vu0_q *)&p->v10 = *(vu0_q *)(a1 + 0x10);
            func_0038D000(&tmp, pv, a1 + 0xC0);
            vec_add_ab(&p->v10, &p->v10, &tmp);
            if (a7 > 0) v = a7 >> 5;
            else v = (s16)*(u16 *)(a1 + 0x32) >> 5;
            p->b9 = (v << 4) + 4;
        } else {
            p->v10 = *a0;
        }
    }
    return p;
}
/* localdecomp:end func_L01_00470150 */
