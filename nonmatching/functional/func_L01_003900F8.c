/* functional: high. Draft 18 diff (register/scheduling only); verified rand arg ranges, constants, one iteration of do-while (i=-1), order of calls against asm */
#include "common.h"
#include "vu0.h"
void func_L01_003900F8(vu0_v4 *origin) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32 low, f32 high);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32 angle);
    extern u8 *func_L01_0046B288(void *, u32, u32, s32, f32, f32);
    extern s32 func_00382468(s32);
    vu0_v4 position;
    f32 angle, radius, a, b;
    s32 life;
    s32 i = 0;
    u8 *particle;
    do {
        i--;
        angle = func_00382538();
        radius = func_003824E0(0.0f, 0.6f);
        a = func_003824E0(0.0f, 1.5f);
        b = func_003824E0(1.0f, 5.0f);
        life = func_00382498(100, 160);
        position.x = func_0038D098(angle) * radius;
        position.y = func_0038D0B0(angle) * radius;
        position.z = 0.0f;
        __asm__ volatile (
            "lqc2 vf2, 0(%1)\n"
            "lqc2 vf1, 0(%2)\n"
            "vadd.xyz vf1, vf1, vf2\n"
            "sqc2 vf1, 0(%2)"
            : "+m"(position)
            : "r"(origin), "r"(&position), "m"(*origin)
            : "vf1", "vf2");
        particle = func_L01_0046B288(&position, 0x5005C162, 0x0005C162, life, a, b);
        if (particle != 0) {
            particle[3] = func_00382468(3) ? 0x48 : 0x44;
        }
    } while (i >= 0);
}
