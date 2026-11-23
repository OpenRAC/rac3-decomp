/* PAL near miss (haiku-w4): 35 words differ with the file's flags; the prologue saves and the 1.0f/constant loads are scheduled differently, and the retail VU0 sequence interleaves them (one volatile block here, the j-form needs -mvu0-use-vf0-vf2 on the file line, which config/ does not allow). */
#include "common.h"
#include "vu0.h"
extern S_38C110v D_L01_001E29C0;
void func_L01_0035EB20(S_38C110v *origin) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    S_38C110v direction;
    S_38C110v velocity;
    S_38C110v position;
    f32 heading;
    f32 factor, elevation, yaw;
    s32 kind;
    s32 i;
    f32 lifetime_scale;
    __asm__ __volatile__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(direction) : "m"(D_L01_001E29C0), "m"(*origin) : "vf1", "vf2");
    heading = func_0038D160(direction.x, direction.y);
    lifetime_scale = 210000.0f;
    for (i = 19; i >= 0; i--) {
        factor = func_003824E0(0.5f, 1.0f);
        kind = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        elevation = func_003824E0(0.0f, 1.3962634f);
        yaw = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(&velocity, factor * 0.020000001f, yaw, elevation);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, kind,
                         func_003824E0(0.05f, 0.2f) * lifetime_scale, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
