/* functional: high. Verified against PAL asm: constants, rand ranges, color select, life=(r*5+2)/6, 11-arg spawn call (ints in a0-a3,t0-t3, floats f12-f14), sprite byte stores. Differs only in f20/f21 allocation, abs.s scheduling and constant load order. Draft called the spawn through a cast prototype; this uses the file prototype with args in its order. */
#include "vu0.h"
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32,s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *D_L20_002203DC[];
void func_L20_003F4918(void *pos) {
    vu0_v4 v;
    f32 speed;
    f32 z;
    f32 size;
    s32 color;
    u8 *p;
    func_L01_00443B88(&v, 0.020000001f, 0.0500000045f);
    z = v.z;
    z = __builtin_fabsf(z);
    z += func_003824E0(7.0f, 10.5f) * 0.020000001f;
    v.z = z;
    speed = func_003824E0(0.06f, 0.22f);
    func_00382468(3);
    color = func_00382468(3) ? 0x263438 : 0x273538;
    { s32 life = (func_00382498(90,150) * 5 + 2) / 6;
    size = 210000.0f;
    size *= speed;
    p = func_L01_004713C8(
        pos, &v, life, color, -2, 127, 127, 0, size, size, 0.00624000048f);
    }
    if (p != 0) {
        p[2] = D_L20_002203DC[0][func_00382468(3) + 10];
        p[3] = 0x44;
    }
}
