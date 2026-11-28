#include "common.h"
/* localdecomp:start func_L01_00393BC0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_395020;
typedef struct { u8 pad0[0xD4]; u8 *puff_tex; u8 pad1[0x184 - 0xD8]; u8 *rock_tex; } S_221098_395020;
extern f32 D_L01_001DE0C8;
__asm__(".extern D_L01_001DE0C8, 4");
extern f32 D_L01_001DE0CC;
__asm__(".extern D_L01_001DE0CC, 4");
extern S_221098_395020 D_L01_00221118;
extern s32 D_001D545C;
extern void func_L01_00440A88(V4_395020 *v, f32 a, f32 b);
extern f32 func_0037E250(f32 a, f32 b);
extern f32 func_L01_00440918(f32 a, f32 b);
extern s32 func_0037E1D8(s32 a);
extern u8 *func_L01_0046DCB8(void *pos, V4_395020 *vel, s32 life, s32 col, s32 d, s32 e, s32 f, f32 a, f32 b, s32 g, f32 c);

/* whip_wave_dark_puffs: four casts of black then violet puffs from the V5 shock wave */
void func_L01_00393BC0(void *pos) {
    V4_395020 vel;
    f32 up, size, scale;
    s32 i, d;
    u8 *p;

    for (i = 3; i >= 0; i--) {
        func_L01_00440A88(&vel, 0.0250000022f, 0.0666666701f);
        up = vel.z;
        up = fabs_asm(up);
        up += func_0037E250(1.0f, 3.0f) * 0.0166666675f;
        vel.z = up;
        size = func_0037E250(D_L01_001DE0C8, D_L01_001DE0CC);
        func_0037E1D8(3);
        switch (D_001D545C) {
        case 0x29: func_0037E1D8(3); break;
        case 0x2A: func_0037E1D8(3); break;
        }
        scale = 1.25f;
        d = (s32)func_L01_00440918(2.0f, 3.0f);
        p = func_L01_0046DCB8(pos, &vel, 0x3C, 0, d, 0x7F, 0x7F,
                              func_0037E250(0.800000011921f, scale) * 210000.0f * size, size * 2100.0f, 6, 0.00433333358f);
        if (p != 0) {
            p[3] = 0x44;
            p[2] = D_L01_00221118.puff_tex[0];
        }
        d = (s32)func_L01_00440918(2.0f, 3.0f);
        p = func_L01_0046DCB8(pos, &vel, 0x3C, 0x7C0030, d, 0x30, 0x30,
                              func_0037E250(0.800000011921f, scale) * 210000.0f * scale * size, size * 4200.0f, 0, 0.00433333358f);
        if (p != 0) {
            p[3] = 0x44;
            p[2] = D_L01_00221118.puff_tex[0];
        }
    }
}
/* localdecomp:end func_L01_00393BC0 */
