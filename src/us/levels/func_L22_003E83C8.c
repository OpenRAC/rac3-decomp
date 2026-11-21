#include "common.h"

/* NTSC-U counterpart of func_L22_003EA3F0 (src/levels/22_mylon/L22_003E9FF0.c): 351 frames for 293, 20 for 17 */
/* localdecomp:start func_L22_003E83C8 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388BD0(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_L22_001DF3D0[8];
__asm__(".extern D_L22_001DF3D0, 8");

void func_L22_003E83C8(u8 *a0) {
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 t;
    u8 *q;
    f32 f20, f21, f22, f23;
    if (a0[0x20] == 0) {
        s32 n = *(u16 *)(a0 + 0x96) + 1;
        *(u16 *)(a0 + 0x96) = n;
        if ((u16)n >= 0x15F) {
            func_L01_00441FB8(a0, 1, -1);
            return;
        }
        q = a0 + 0xC0;
        func_00388BD0(q, a0 + 0xF0);
        f20 = -0.051f;
        func_003888C8(&t, D_L22_001DF3D0, q);
        vec_add_ba(&v, a0 + 0x10, &t);
        func_00388830(&w, q, f20);
        w.z += f20;
        func_003BF6A8(&v, 0.01f);
        func_003BF6A8(&w, 0.02f);
        func_003888C8(&w, &w, q);
        f22 = 210000.0f;
        f21 = func_0037E250(0.25f, 0.35f) * f22;
        f23 = func_0037E250(0.7f, 0.9f) * f22;
        func_L01_0046C468(&v, &w, 20, 0x808080, 30, 96, 32, f21, f23, func_0037E250(-0.007f, -0.01f), 0);
    }
}
/* localdecomp:end func_L22_003E83C8 */
