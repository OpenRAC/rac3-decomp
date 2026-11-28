#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_005C94D0 */
typedef struct {
    f32 x0, x4, x8, xC;
    f32 f10, f14, f18, f1C;
} S_005C94D0_v;
typedef struct {
    u8 p0[4];
    s32 f4;
    u8 b8;
    u8 p9;
    u8 pA[2];
    f32 fC;
    f32 pos[4] __attribute__((aligned(16)));
    S_005C94D0_v v;
} S_005C94D0;
extern vu0_q D_L39_0025F760;
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_002429BC, 16");

void func_L39_005C94D0(S_005C94D0 *o) {
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L39_005BC330(void *, void *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(void *);
    extern s32 func_L01_00448CC0(f32, f32, f32, f32);
    S_005C94D0_v *v;
    f32 *p;
    f32 a, b, c;
    s32 neg;
    f32 newpos[4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));

    if (o != 0) {
        v = &o->v;
        a = v->f10;
        b = v->f14;
        c = v->f18;
        neg = 0;
        if (a < 0.0f || b < 0.0f || c < 0.0f) {
            a = -a;
            neg = 1;
            b = -b;
            c = -c;
        }
        o->pos[2] = o->pos[2] - v->xC;
        v->f1C = v->f1C + 0.0f;
        o->fC = o->fC + -120.00001f;
        vec_add_ab(newpos, o->pos, v);
        if (v->x0 != 0.0f || v->x4 != 0.0f || v->x8 != 0.0f) {
            p = o->pos;
            if (func_003D3CB0(p, newpos, 6, 0, 0) != 0) {
                *(vu0_q *)o->pos = D_L39_0025F760;
                qzero(v);
                o->fC = o->fC + o->fC;
            } else {
                s32 flag = D_L39_002429BC;
                *(vu0_q *)o->pos = *(vu0_q *)newpos;
                if (flag != 0) {
                    func_L39_005BC330(p, tmp, 0);
                    if (v->xC != 0.0f) {
                        func_0038CE20(tmp, tmp, -v->xC);
                        vec_add_ab(v, v, tmp);
                    } else {
                        func_0038CE20(tmp, tmp, 0.009072f);
                        vec_add_ab(v, v, tmp);
                    }
                } else {
                    f32 k = v->xC;
                    if (k != 0.0f) {
                        v->x8 = v->x8 + k;
                    } else {
                        v->x8 = v->x8 + -0.009072f;
                    }
                }
            }
        }
        if (v->f1C <= 0.0f || func_0038CB00((u8 *)o + 0xA) != 0 || o->fC < 0.0f || newpos[0] < 0.01f ||
            newpos[1] < 0.01f || newpos[2] < 0.01f) {
            func_003CD250(o);
            return;
        }
        if (neg == 0) {
            a += -0.012f;
            if (a < 0.0f) {
                a = 0.0f;
            }
            b += -0.036012f;
            if (b < 0.0f) {
                b = 0.0f;
            }
        } else {
            b += -0.012f;
            if (b < 0.0f) {
                b = 0.0f;
            }
            a += -0.036012f;
            if (a < 0.0f) {
                a = 0.0f;
            }
        }
        c += -0.060000002f;
        if (c < 0.0f) {
            c = 0.0f;
        }
        v->f1C = v->f1C + 0.0f;
        if (v->f1C < 0.0f) {
            v->f1C = 0.0f;
        }
        o->f4 = func_L01_00448CC0(a, b, c, v->f1C);
        if (neg > 0) {
            v->f10 = -a;
            v->f14 = -b;
            v->f18 = -c;
        } else {
            v->f10 = a;
            v->f14 = b;
            v->f18 = c;
        }
        o->b8 = o->b8 - 1;
    }
}
/* localdecomp:end func_L39_005C94D0 */
