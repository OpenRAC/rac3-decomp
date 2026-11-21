#include "common.h"

/* NTSC-U counterpart of func_L39_0061F3F0 (src/levels/shared/L39_0061ECE0.c) */
#include "vu0.h"

/* localdecomp:start func_L39_0061CC50 */
#include "vu0.h"
typedef int Q_0061F3F0 __attribute__((mode(TI)));

typedef struct S_0061F3F0 {
    Q_0061F3F0 q00;
    Q_0061F3F0 q10;
    s32 i20;
    s32 i24;
    s32 i28;
    u8 pad2C[4];
    Q_0061F3F0 q30;
    Q_0061F3F0 q40;
    Q_0061F3F0 q50;
    Q_0061F3F0 q60;
    Q_0061F3F0 q70;
    Q_0061F3F0 q80;
    Q_0061F3F0 q90;
    Q_0061F3F0 qA0;
    Q_0061F3F0 qB0;
    u8 padC0[0x34];
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x5C];
    s32 i15C;
    Q_0061F3F0 q160;
    Q_0061F3F0 q170;
    Q_0061F3F0 q180;
} S_0061F3F0;

extern s32 D_001A5F78[];
extern f32 D_L39_0024130C;
extern void func_003886E8(void *, void *, f32);

void func_L39_0061CC50(void *arg) {
    S_0061F3F0 *s = arg;
    s32 now = D_001A5F78[0];
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 dv;
    vu0_v4 da;
    vu0_v4 sum;
    Q_0061F3F0 *v;
    f32 dt;
    f32 inv;

    if (now == s->iFC) {
        return;
    }
    if (s->i15C >= 0 && now >= s->i15C) {
        s->q180 = s->q170;
        s->q170 = s->q160;
        s->i15C = -1;
    }
    dt = (f32)(now - s->iF4) / (D_L39_0024130C * 1000.0f);
    pos = *(vu0_v4 *)&s->q90;
    vel = *(vu0_v4 *)&s->qA0;
    v = &s->qA0;
    func_003886E8(&dv, &s->q30, dt);
    func_003886E8(&da, &s->q40, 0.5f * dt * dt);
    vec_add_ba(&sum, &dv, &da);
    {
        vu0_q b, p, a, r, q, d;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)&s->q70));
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(sum));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(b), "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&s->q90) : "j"(r));
        dt = (f32)(now - s->iFC) / (D_L39_0024130C * 1000.0f);
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_v4 *)&s->q90));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(p), "j"(q));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)v) : "j"(d));
    }
    inv = 1.0f / dt;
    func_003886E8(v, v, inv);
    vec_sub_ba(&s->qB0, &vel, v);
    func_003886E8(&s->qB0, &s->qB0, inv);
    s->iFC = now;
}
/* localdecomp:end func_L39_0061CC50 */
