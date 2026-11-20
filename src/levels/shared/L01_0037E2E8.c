#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037E2E8 */
#include "vu0.h"
__asm__(".extern D_L01_001DDB74, 4");
__asm__(".extern D_L01_001DDB68, 4");
__asm__(".extern D_L01_001DDB6C, 4");
__asm__(".extern D_L01_001DDB70, 4");

extern f32 D_L01_001DDB74 __attribute__((section(".sdata")));
extern f32 D_L01_001E1DBC __attribute__((section(".data")));
extern f32 D_L01_001E1DB8 __attribute__((section(".data")));
extern f32 D_L01_001E1DA4;
extern f32 D_L01_001E1DA8;
extern f32 D_L01_001E1DAC;
extern s32 D_L01_001E1DA0 __attribute__((section(".data")));
extern s32 D_L01_001DDB68 __attribute__((section(".sdata")));
extern s32 D_L01_001DDB6C __attribute__((section(".sdata")));
extern s32 D_L01_001DDB70 __attribute__((section(".sdata")));
void func_L01_0037E2E8(u8 *p) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_003D9740(void *, s32, u32, s32, s32, f32);
    vu0_v4 matrix[4];
    vu0_v4 pos;
    vu0_v4 delta;
    vu0_v4 rotation;
    vu0_v4 axis;
    u8 *sub = *(u8 **)(p + 0x68);
    u32 c0, c1, c2;
    *(vu0_q *)&pos = *(vu0_q *)(sub + 0x20);
    vec_sub_ab(&delta, p + 0x10, sub + 0x20);
    func_0038CF68(&delta, &delta, 1.0f);
    rotation.x = 0.0f;
    rotation.y = -func_0038D160(func_0038CED8(&delta), delta.z) + -1.5707963705f;
    rotation.z = func_0038D160(delta.x, delta.y);
    rotation.w = 1.0f;
    func_0038D328(matrix, &rotation);
    *(vu0_q *)&axis = *(vu0_q *)&delta;
    func_0038CE20(&axis, &axis, D_L01_001DDB74);
    vec_add_ab(&pos, &pos, &axis);
    *(vu0_q *)&matrix[3] = *(vu0_q *)&pos;
    func_0038CE20(&matrix[0], &matrix[0], D_L01_001E1DBC);
    func_0038CE20(&matrix[1], &matrix[1], D_L01_001E1DB8);
    func_0038CE20(&matrix[2], &matrix[2], D_L01_001DDB74);
    D_L01_001E1DA4 += 0.15f;
    if (D_L01_001E1DA4 >= 7.0f) D_L01_001E1DA4 -= 7.0f;
    D_L01_001E1DA8 += 0.1f;
    if (D_L01_001E1DA8 >= 7.0f) D_L01_001E1DA8 -= 7.0f;
    D_L01_001E1DAC += 0.05f;
    if (D_L01_001E1DAC >= 7.0f) D_L01_001E1DAC -= 7.0f;
    c0 = (D_L01_001E1DA0 << 24) | 0x204080;
    c2 = (D_L01_001E1DA0 << 24) | 0x104080;
    c1 = (D_L01_001E1DA0 << 24) | 0x80C4FF;
    func_0038D890(&matrix[0], &matrix[0], &matrix[2], 0.7853981853f);
    func_0038D890(&matrix[1], &matrix[1], &matrix[2], 0.7853981853f);
    func_003D9740(matrix, D_L01_001DDB68, c0, 8, 1, D_L01_001E1DA4);
    func_0038D890(&matrix[0], &matrix[0], &matrix[2], -1.5707963705f);
    func_0038D890(&matrix[1], &matrix[1], &matrix[2], -1.5707963705f);
    func_003D9740(matrix, D_L01_001DDB6C, c2, 8, 1, D_L01_001E1DA8);
    func_003D9740(matrix, D_L01_001DDB70, c0, 8, 1, D_L01_001E1DAC);
    func_0038CE20(&matrix[0], &matrix[0], 1.1f);
    func_0038CE20(&matrix[1], &matrix[1], 1.1f);
    func_003D9740(matrix, 10, c1, 6, 1, D_L01_001E1DA4);
}
/* localdecomp:end func_L01_0037E2E8 */
