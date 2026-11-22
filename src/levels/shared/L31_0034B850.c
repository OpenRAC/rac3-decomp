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

/* declared by functions of L31_0034B688.c, which this file was cut from */
extern float D_L31_001E12B4;

INCLUDE_ASM("asm/levels", func_L31_0034B850);

/* localdecomp:start func_L31_0034BA10 */
extern float D_L31_001E12B4;
extern float D_L31_00284A10[];
extern void func_L31_0034B850(void *, void *, float);

void func_L31_0034BA10(void *obj, void *out, float t) {
    s32 i = 0;
    s32 found = 0;
    s32 lo, hi, mid;
    float ft;

    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    ft = t * D_L31_001E12B4;
    lo = 0;
    mid = 0xFF;
    hi = 0x1FE;
    for (; !found && i < 12; i++) {
        if (D_L31_00284A10[mid + 1] < ft) {
            lo = mid + 1;
            mid = (lo + hi) / 2;
        } else if (ft < D_L31_00284A10[mid]) {
            hi = mid - 1;
            mid = (lo + hi) / 2;
        } else {
            found = 1;
        }
    }
    if (found) {
        func_L31_0034B850(obj, out, ((float)mid + (ft - D_L31_00284A10[mid]) / (D_L31_00284A10[mid + 1] - D_L31_00284A10[mid])) / 511.0f);
    }
}
/* localdecomp:end func_L31_0034BA10 */
