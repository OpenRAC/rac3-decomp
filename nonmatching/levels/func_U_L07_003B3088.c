/* Unlinked NTSC-U draft. 10 differing words with inherited flags. The velocity pointer, counter and palette load use different registers. */
/* Unlinked NTSC-U candidate: 10: velocity/counter allocation and palette-load registers. */
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_003B4978. */
/* localdecomp:start func_L07_003B3088 */
typedef struct { u8 pad[0x16C]; u8 *p; } Data_003B4978;
extern Data_003B4978 D_L07_0021EC98;
void func_L07_003B3088(void *obj, u8 side) {
    extern void func_003BD9A0(void *, s32, void *);
    extern void func_003886E8(void *, void *, f32);
    extern void func_003BF6A8(void *, f32);
    extern f32 func_0037E250(f32, f32);
    extern s32 func_0037E208(s32, s32);
    extern s32 func_0037E1D8(s32);
    extern u8 *func_L01_0046C468(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    struct { vu0_q matrix[4]; vu0_q position, direction, jitter, velocity; } v;
    s32 i;
    s32 life;
    f32 a,b;
    u8 *p;
    func_003BD9A0(obj, side * 3 + 8, v.matrix);
    v.direction = v.matrix[0];
    if (side == 1) vec_neg(&v.direction, &v.direction);
    func_003886E8(&v.position, &v.direction, 1.0f);
    vec_add_ab(&v.position, &v.matrix[3], &v.position);
    i=1;
    do {
        v.jitter = v.position;
        func_003BF6A8(&v.jitter, 1.0f);
        func_003886E8(&v.velocity, &v.direction, func_0037E250(0.083333336f, 0.4166667f));
        func_003BF6A8(&v.velocity, 0.050000004f);
        life = func_0037E208(20,30);
        a = func_0037E250(52500.0f,105000.0f);
        b = func_0037E250(315000.0f,525000.0f);
        p = func_L01_0046C468(&v.position,&v.velocity,life,0x808080,func_0037E1D8(2) ? 3 : -3,127,0,0,a,b,0.0f);
        if (p) {
            --i;
            p[2] = *D_L07_0021EC98.p;
        } else {
            --i;
        }
    } while (i >= 0);
}
/* localdecomp:end func_L07_003B3088 */
