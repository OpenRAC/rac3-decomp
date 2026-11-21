/* functional: high. 179 diff = scheduling; verified constants (0.02, 0.2, 1.6, 14.6), stack args 50/120, loop 7, rand%3 kind select, z bias 0.06 */
#include "common.h"
#include "vu0.h"
extern vu0_v4 D_L01_001E2A40;
void func_L01_00392A90(u8 *obj, vu0_v4 *position) {
    extern f32 func_0038CEA8(void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0040E6B8(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_003298C8(void *, void *, s32, s32, s32, u32, s32, s32, s32, s32, f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_0013D3E0(void);
    extern void func_0038D000(void *, void *, void *);
    vu0_v4 direction, velocity, random;
    f32 distance;
    s32 i;
    vu0_v4 *d = &direction;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(direction) : "m"(D_L01_001E2A40), "m"(*position) : "vf1", "vf2");
    distance = func_0038CEA8(d);
    *(vu0_q *)&random = 0;
    random.x = func_003824E0(-1.0f, 1.0f);
    random.y = func_003824E0(-1.0f, 1.0f);
    random.z = func_003824E0(-1.0f, 1.0f);
    direction.z += distance * 0.5f;
    velocity = random;
    func_0038CF68(&velocity, &velocity, distance / 5.0f * 0.020000001415610313f);
    distance *= 2.0f;
    func_0038CF68(d, d, distance * 0.020000001415610313f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(velocity) : "m"(velocity), "m"(direction) : "vf1", "vf2");
    func_L01_0040E6B8(&velocity, &velocity, 0.20000001788139343f);
    func_L01_003298C8(position, &velocity, func_00382498(50,75), 3, 0, 0x80808080, 0, 1, 50, 120, 1.6f, 14.6f);
    for (i = 6; i >= 0; --i) {
        s32 kind = 1;
        f32 a = func_003824E0(0.2617993950843811f, 1.3089969158172607f);
        f32 b = func_00382538();
        func_00382760(&random, func_003824E0(8.0f, 12.0f) * 0.020000001415610313f, b, a);
        random.z += 0.06000000238418579f;
        { s32 r = func_0013D3E0() % 3;
          if (r) kind = 0;
        }
        func_0038D000(&random, &random, obj + 0xC0);
        func_L01_003298C8(position, &random, func_00382498(50,75), kind, 0, 0x80808080, 0, 1, 50, 120, 1.6f, 14.6f);
    }
}
