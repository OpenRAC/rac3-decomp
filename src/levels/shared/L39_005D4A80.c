#include "common.h"

/* localdecomp:start func_L39_005D4A80 */
#include "vu0.h"

typedef struct {
    u8 p0[4];
    u32 w04;
    u8 b08;
    u8 p09;
    s16 s0A;
    u8 p0C[4];
    vu0_v4 pos;
    vu0_v4 vel;
} S_005D4A80;
typedef struct {
    u8 p0[8];
    f32 f08;
    f32 f0C;
    u8 p10[4];
    s16 s14;
    u8 b16;
    u8 p17[5];
    f32 f1C;
} V_005D4A80;

__asm__(".extern D_L39_0024112C, 16");
extern s32 D_L39_0024112C;
extern f32 D_L39_0024DCC0[];
extern void func_L39_005FFB48(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern void func_003CD250(void *);

void func_L39_005D4A80(S_005D4A80 *p) {
    vu0_v4 tmp;
    f32 k;
    V_005D4A80 *v = (V_005D4A80 *)&p->vel;
    vu0_v4 *pos = &p->pos;

    func_L39_005FFB48(pos, pos);
    func_0038CE20(v, v, 0.9f);
    v->f08 = v->f08 - v->f0C;
    vec_add_ab(&p->pos, &p->pos, &p->vel);
    func_L39_005FFB48(pos, pos);
    if (D_L39_0024112C % 10 == 0) {
        v->f1C = func_0038DAB8(v->f1C, 1.0f);
        k = func_0038D0B0(v->f1C) * 0.0075f;
        func_0038CF68(&tmp, D_L39_0024DCC0, k);
        vec_add_ab(&p->vel, &p->vel, &tmp);
    }
    if (p->s0A < v->s14) {
        p->w04 = ((s32)((f32)p->s0A / (f32)v->s14 * 128.0f) << 24) | 0x204040;
    } else {
        p->w04 = 0x4F204040;
    }
    p->b08 += v->b16;
    if (func_0038CB00(&p->s0A) != 0) {
        func_003CD250(p);
    }
}
/* localdecomp:end func_L39_005D4A80 */
