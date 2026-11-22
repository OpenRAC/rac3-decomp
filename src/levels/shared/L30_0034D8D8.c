#include "common.h"

/* declared by functions of L30_0034D1E8.c, which this file was cut from */
extern void func_0038CE20(void *d, void *s, f32 k);

/* localdecomp:start func_L30_0034D8D8 */
#include "vu0.h"
extern s32 D_L30_001DF2C0;
extern u8 D_L30_001E2100[];
typedef struct { u8 pad0[0xA0]; f32 fA0; f32 fA4; u8 pad1[8]; f32 fB0; f32 fB4; } S_001E6E00;
extern S_001E6E00 D_L30_001E6E00;
extern void func_0038D028(f32 *out, void *a, void *b);

s32 func_L30_0034D8D8(void *pos, f32 margin) {
    vu0_v4 d;
    vu0_v4 r;
    f32 ratioX = 17.23f;
    f32 ratioY = 17.23f;
    f32 z;

    if (D_L30_001DF2C0 < 5) {
        return 1;
    }
    if (*(f32 *)D_L30_001E2100 < 0.5f) {
        return 1;
    }
    vec_sub_ab(&d, pos, D_L30_001E2100 + 0x140);
    func_0038CE20(&d, &d, 1024.0f);
    func_0038D028(&r.x, &d, D_L30_001E2100);
    z = r.z;
    if (z < D_L30_001E6E00.fA0) {
        return 0;
    }
    if (D_L30_001E6E00.fA4 < z) {
        return 0;
    }
    r.x = fabs_asm(r.x);
    r.y = fabs_asm(r.y);
    if (z != 0.0f) {
        if (D_L30_001E6E00.fB0 != 0.0f) {
            ratioX = r.x / (z * D_L30_001E6E00.fB0);
        }
    }
    if (r.z != 0.0f) {
        if (D_L30_001E6E00.fB4 != 0.0f) {
            ratioY = r.y / (r.z * D_L30_001E6E00.fB4);
        }
    }
    if (margin < ratioX) {
        return 0;
    }
    if (margin < ratioY) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L30_0034D8D8 */
