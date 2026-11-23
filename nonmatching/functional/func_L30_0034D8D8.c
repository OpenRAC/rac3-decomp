/* functional: high. From asm; abs.s done with ternary (retail uses fabs_asm); 105 diff = scheduling; fov ratios default to 17.17 when z or the fov factor is 0, as retail */
#include "vu0.h"
extern s32 D_L30_001DF2C0;
extern u8 D_L30_001E2100[];
extern f32 D_L30_001E6EA0;
extern f32 D_L30_001E6EA4;
extern f32 D_L30_001E6EB0;
extern f32 D_L30_001E6EB4;
extern void func_0038D028(f32 *out, void *a, void *b);

s32 func_L30_0034D8D8(void *pos, f32 margin) {
    vu0_v4 d;
    vu0_v4 r;
    f32 ratioX = 17.17f;
    f32 ratioY = 17.17f;
    f32 z;

    if (D_L30_001DF2C0 < 5) {
        return 1;
    }
    if (*(f32 *)D_L30_001E2100 < 0.5f) {
        return 1;
    }
    d.x = ((vu0_v4 *)pos)->x - *(f32 *)(D_L30_001E2100 + 0x140);
    d.y = ((vu0_v4 *)pos)->y - *(f32 *)(D_L30_001E2100 + 0x144);
    d.z = ((vu0_v4 *)pos)->z - *(f32 *)(D_L30_001E2100 + 0x148);
    func_0038CE20(&d, &d, 1024.0f);
    func_0038D028(&r.x, &d, D_L30_001E2100);
    z = r.z;
    if (z < D_L30_001E6EA0) {
        return 0;
    }
    if (D_L30_001E6EA4 < z) {
        return 0;
    }
    r.x = r.x < 0.0f ? -r.x : r.x;
    r.y = r.y < 0.0f ? -r.y : r.y;
    if (z != 0.0f) {
        if (D_L30_001E6EB0 != 0.0f) {
            ratioX = r.x / (z * D_L30_001E6EB0);
        }
    }
    if (r.z != 0.0f) {
        if (D_L30_001E6EB4 != 0.0f) {
            ratioY = r.y / (r.z * D_L30_001E6EB4);
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
