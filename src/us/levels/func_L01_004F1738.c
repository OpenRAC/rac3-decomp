#include "common.h"
/* localdecomp:start func_L01_004F1738 */
#include "vu0.h"
extern vu0_q D_001A4C60[];
extern s32 D_001D545C;
void func_L01_004F1738(void) {
    extern f32 func_0037E250(f32, f32);
    extern f32 func_0037E2A8(void);
    extern void func_0037E4B8(void *, f32, f32, f32);
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
    struct { vu0_q position, velocity; } v;
    s32 i, size, life;
    f32 speed, angle, elevation, radius;
    vu0_q *base = D_001A4C60;
    u8 *hero = (u8 *)base - 0x80;
    for (i = 0; i < 10; i++) {
        size = (s32)(func_0037E250(4200.0f, 7350.0f) / 1000.0f);
        life = (s32)(func_0037E250(21000.0f, 31500.001953125f) / 1000.0f);
        speed = func_0037E250(0.00250000018f, 0.0116666667f);
        v.position = *base;
        if (D_001D545C != 6) {
            ((f32 *)&v.position)[2] = *(f32 *)(hero + 0x354);
        }
        do {
            angle = func_0037E2A8();
            elevation = func_0037E250(0.34906584f, 1.39626336f);
            radius = func_0037E250(0.05f, *(f32 *)(hero + 0x284) + 0.2f);
        } while (0);
        func_0037E4B8(&v.velocity, speed, angle, elevation);
        ((f32 *)&v.position)[0] += func_00388960(angle) * radius;
        ((f32 *)&v.position)[1] += func_00388978(angle) * radius;
        func_L01_00460318(&v.position, &v.velocity, 0x7000C0F0, 0x70F0, 0x28, size, life, 1);
    }
}
/* localdecomp:end func_L01_004F1738 */
