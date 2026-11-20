#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034B688 */
#include "vu0.h"

extern s32 D_L31_001E12B0;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB48(f32);

f32 func_L31_0034B688(void *a, void *b) {
    vu0_v4 d;
    f32 s;
    f32 o;

    s = 1.0f;
    if (D_L31_001E12B0 != 0) {
        s = -1.0f;
    }
    o = 3.1415927f;
    if (D_L31_001E12B0 != 0) {
        o = 0.0f;
    }
    vec_sub_ab(&d, b, a);
    return func_0038DB48(o + func_0038D160(d.x, s * d.z));
}
/* localdecomp:end func_L31_0034B688 */

/* localdecomp:start func_L31_0034B700 */
extern float D_L31_001E12B4;
extern float D_L31_001DD1A8;
extern s32 D_L31_001DD210;
extern float func_0038CF00(void *, void *);
extern void func_L31_0034BB58(void *, void *, float);
__asm__(".extern D_L31_001DD1A8, 4");
__asm__(".extern D_L31_001DD210, 4");
__asm__(".extern D_L31_001E12B4, 16");
void func_L31_0034B700(void *a, void *b, float *pf, void *c, float base, float f13) {
    float step;
    s32 i;
    *pf = base - f13 / D_L31_001E12B4;
    step = 1.0f / D_L31_001DD1A8;
    for (i = 0; i < D_L31_001DD210; i++) {
        if (*pf > 1.0f) {
            *pf = 1.0f;
        } else if (*pf < 0.0f) {
            *pf = 0.0f;
        }
        step *= D_L31_001DD1A8;
        func_L31_0034BB58(a, b, *pf);
        if (i != D_L31_001DD210 - 1) {
            *pf += step * ((func_0038CF00(b, c) - f13) / D_L31_001E12B4);
        }
    }
}
/* localdecomp:end func_L31_0034B700 */
