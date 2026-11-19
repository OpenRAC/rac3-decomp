/* functional: medium. from asm; unit-tested only by compile; not byte exact (frame size/register use); callee func_L39_005CDCF0 args read as (pos,color,idx,0x35,0,2,1,getter result,scale); func_0038DBD8 assumed colour lerp (c0,c1,t); D_L40_002469C0/D0/E0 float tables */
#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    s32 (*get)(void *);
} VT_003D9E78;

typedef struct {
    u8 pad0[0x14];
    VT_003D9E78 *vt;
} Obj_003D9E78;

extern vu0_v4 D_L40_00249F40;
extern f32 D_L40_002469C0[];
extern f32 D_L40_002469D0[];
extern f32 D_L40_002469E0[];
extern u8 D_L40_0029AF58[];
extern void func_0038CF68(void *d, void *s, f32 k);
extern s32 func_0038CB00(void *);
extern s32 func_0038DBD8(s32 c0, s32 c1, f32 t);
extern u8 *func_L39_005CDCF0(void *, s32, u8, s32, s32, s32, s32, s32, f32);

s32 func_L40_003D9E78(u8 *self, Obj_003D9E78 *t) {
    vu0_v4 A;
    vu0_v4 B;
    u8 *d;
    s32 result;
    s32 n;
    f32 az;

    d = *(u8 **)(self + 0x68);
    vec_sub_ab(&A, &D_L40_00249F40, self + 0x10);
    func_0038CF68(&A, &A, -0.3f);
    result = 0;
    func_0038CF68(&B, &A, 0.1f);
    vec_add_ab(&A, self + 0x10, &A);
    az = A.z;
    for (n = 0; n < 4; n++) {
        if (func_0038CB00(d + 0x44 + n * 2) == 0) {
            f32 *f = (f32 *)(d + 0x50) + n;
            s16 q = *(s16 *)(d + 0x44 + n * 2);
            f32 fv = *f + D_L40_002469C0[n];
            s32 col, a, idx, alpha, get;
            f32 ratio, sc;
            u8 *p;
            u8 *x;

            if (q >= 0x29) {
                result = 1;
            }
            *f = fv;
            if (fv >= 255.0f) {
                *f = fv - 255.0f;
            } else if (fv <= 0.0f) {
                *f = fv + 255.0f;
            }
            col = func_0038DBD8(0x407F2020, 0x107F2020, __builtin_fabsf(0.5f - (f32)(212 - q) / 212.0f));
            ratio = 1.0f - (f32)q / 75.0f;
            sc = D_L40_002469D0[n];
            A.z = az + D_L40_002469E0[n];
            alpha = col >> 24;
            idx = (s32) * f & 0xFF;
            a = ((s32)((f32)alpha * (1.0f - ratio)) << 24) | (col & 0xFFFFFF);
            get = t->vt->get(t);
            p = func_L39_005CDCF0(&A, a, idx, 0x35, 0, 2, 1, get, sc * ratio);
            if (p != 0) {
                x = *(u8 **)(D_L40_0029AF58 + 0xF8);
                p[2] = *x;
            }
            sc = sc * (ratio * 0.7f);
            idx = (s32) * f & 0xFF;
            a |= 0xFFFFFF;
            get = t->vt->get(t);
            p = func_L39_005CDCF0(&A, a, idx, 0x35, 0, 2, 1, get, sc);
            if (p != 0) {
                x = *(u8 **)(D_L40_0029AF58 + 0xF8);
                p[2] = *x;
            }
            vec_add_ab(&A, &A, &B);
        }
    }
    return result;
}
