/* functional: high. 41 diff vs retail, scheduling/reg alloc only (instruction multiset identical except one nop/move); the discarded func_003824E0(0.05,0.2) call is kept because retail makes it (RNG state advance); 13 jals identical */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003868A0;
extern Vec_003868A0 D_L01_001E29C0;
void func_L01_003868A0(u8 *obj, Vec_003868A0 *pos) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(Vec_003868A0 *, f32, f32, f32);
    extern void func_L01_0046A610(Vec_003868A0 *, Vec_003868A0 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    Vec_003868A0 delta, velocity, origin;
    u8 *state;
    f32 angle;
    s32 count;
    f32 scale = 210000.0f;
    __asm__("lqc2 $vf1, %1\n\t"
            "lqc2 $vf2, %2\n\t"
            "vsub.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "=m"(delta) : "m"(D_L01_001E29C0), "m"(*pos) : "vf1", "vf2");
    state = *(u8 **)(obj + 0x68);
    angle = func_0038D160(delta.x, delta.y);
    count = 2;
    if (*(s32 *)(state + 0x3C) <= 1) count = 5;
    while (count != 0) {
        f32 speed = func_003824E0(0.5f, 1.0f);
        s32 type = (s32)func_L01_00443A18(1.0f, 2.0f);
        f32 spread;
        f32 yaw;
        f32 duration;
        count--;
        func_003824E0(0.05f, 0.2f);
        spread = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760(&velocity, speed * 0.0200000014f, yaw, spread);
        origin.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
        origin.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
        origin.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
        duration = func_003824E0(0.05f, 0.2f);
        func_L01_0046A610(&origin, &velocity, 25, 127, 0x7F7F7F, type, duration * scale, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
