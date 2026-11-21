#include "common.h"

/* NTSC-U counterpart of func_L01_00467688 (src/levels/shared/L01_00465878.c): life 252 ticks (60 Hz) for PAL's 210 */
/* localdecomp:start func_L01_00464068 */
#include "vu0.h"
extern u8 *D_L01_00221188[];
extern u8 *func_L01_0045E438(s32);
extern f32 func_0037E250(f32, f32);
extern u8 func_0013D3E0(void);
extern void func_00388E38(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern void func_003888C8(void *, void *, void *);

void func_L01_00464068(void *position, void *orientation, f32 spread) {
    vu0_v4 transformed, delta, velocity;
    vu0_v4 matrix[4];
    u8 *particle = func_L01_0045E438(0x1C);
    u8 *state;
    s32 r, g, b;
    if (particle) {
        f32 low = -0.03f;
        state = particle + 0x20;
        delta.x = func_0037E250(low, 0.03f);
        delta.y = func_0037E250(low, 0.03f);
        delta.z = 0;
        if (orientation) {
            func_00388E38(matrix, orientation);
            func_003888F0(&transformed, &delta, matrix);
            vec_add_ba(particle + 0x10, &transformed, position);
        } else {
            vec_add_ba(particle + 0x10, &delta, position);
        }
        *(f32 *)(particle + 0x18) -= 0.05f;
        /* The divisor sign does not change the remainder. */
        r = (s32)func_0013D3E0() % -96;
        if (!r) r = 1;
        g = ((s32)func_0013D3E0() % r) % 64;
        if (!g) g = 1;
        b = ((s32)func_0013D3E0() % g) % 48;
        *(s32 *)(particle + 4) = (r + 143) | ((g + 143) << 8) | ((b + 111) << 16);
        particle[9] = 0x44;
        particle[3] = 0x48;
        particle[1] = 0;
        particle[8] = 0;
        particle[2] = *D_L01_00221188[0];
        *(f32 *)(state + 4) = func_0037E250(0.0f, 0.0223456006f) + 0.00001f;
        *(f32 *)(particle + 0xC) = func_0037E250(10080.0f, 19950.0f);
        *(f32 *)(state + 8) = 0;
        *(s16 *)(particle + 0xA) = 252;
        *(f32 *)(state + 0xC) = 1.0f;
        qzero(&velocity);
        if (orientation) {
            velocity.x = spread;
            velocity.z = -0.0025f;
            func_003888C8(state + 0x10, &velocity, orientation);
        } else {
            *(f32 *)(state + 0x10) = func_0037E250(-spread, spread);
            *(f32 *)(state + 0x14) = func_0037E250(-spread, spread);
            *(f32 *)(state + 0x18) = -0.0025f;
        }
    }
}
/* localdecomp:end func_L01_00464068 */
