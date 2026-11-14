#include "common.h"

/* NTSC-U counterpart of func_L39_0066A8C8 (src/levels/shared/L39_0066A690.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_00667FF0 */
#include "vu0.h"
typedef union {
    u128_t q;
    f32 f[4];
} V_0066A8C8;
extern s32 D_001A5F78[];
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern u8 *func_L01_004633E8(f32, f32, f32, f32, void *, s32, void *, u32, s32);

/* from the shape of func_L01_0040D510 */
void func_L39_00667FF0(u8 *a0, u8 *a1) {
    V_0066A8C8 vel;
    V_0066A8C8 pt;
    u8 *particle;
    u8 *data;
    s32 r;

    if (a1[0xBC] == 9 && *(s32 *)(a0 + 0x2E8) - 100 >= D_001A5F78[0]) {
        pt.q = *(u128_t *)(a1 + 0x10);
        qzero(&vel);
        pt.f[2] += 0.75f;
        vel.f[2] += (func_L39_005B2510(0.0f, 1.25f) + 0.25f) * 0.0166666675f;
        particle = func_L01_004633E8(0.0f, 1.0f, 1.01f, 210000.0f, &pt, 1, &vel, 0x101010, 0);
        if (particle != 0) {
            particle[3] = 0x44;
            *(s16 *)(particle + 0xA) = func_L39_005B24C8(0x3C, 0xA0);
            particle[9] = 100;
            data = particle + 0x20;
            r = func_L39_005B24C8(1, 10);
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x7F;
            *(f32 *)(data + 0x1C) = r;
            data[0xB] = particle[0xA];
        }
    }
}
/* localdecomp:end func_L39_00667FF0 */
