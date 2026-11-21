#include "common.h"

/* NTSC-U counterpart of func_L18_00352AF8 (src/levels/shared/L18_00352AF8.c): 0.48 -> 0.4; 0.02 -> 0.0166667 */
#include "vu0.h"

/* localdecomp:start func_L18_00351EF0 */
typedef int u128_00352AF8 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00352AF8;

extern f32 func_003893C8(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388770(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L01_0046A9C8(void *, void *, void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
__asm__(".extern D_L18_001DD398_00351EF0, 8");
extern V_00352AF8 D_L18_001DD398_00351EF0[][3] __attribute__((section(".sdata")));
__asm__(".extern D_L18_001DD3C8, 4");
extern f32 D_L18_001DD3C8;
__asm__(".extern D_L18_001DD3CC, 4");
extern f32 D_L18_001DD3CC;
__asm__(".extern D_L18_001DD3D0, 4");
extern f32 D_L18_001DD3D0;
__asm__(".extern D_L18_001DD3D4, 4");
extern f32 D_L18_001DD3D4;
__asm__(".extern D_L18_001DD3D8, 4");
extern f32 D_L18_001DD3D8;

void func_L18_00351EF0(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 b;
    f32 s;
    s32 i;
    s32 k;
    V_00352AF8 vec;
    V_00352AF8 v1;
    V_00352AF8 v2;
    V_00352AF8 v3;
    V_00352AF8 v4;

    a = func_003893C8(*(f32 *)(a0 + 0xF4), *(f32 *)(st + 0x2C4));
    b = *(f32 *)(st + 0x2C8);
    *(u128_00352AF8 *)&vec = 0;
    s = func_00388770(st + 0x290) / 0.400000036f;
    if (s > 1.0f) {
        s = 1.0f;
    } else if (s < 0.5f) {
        s = 0.5f;
    }
    k = 0;
    for (i = 0; i < 2; i++) {
        func_003BDA38(a0, i == 0 ? 6 : 7, &v1);
        v1.v[3] = 0.0f;
        *(u128_00352AF8 *)&v2 = *(u128_00352AF8 *)&v1;
        *(u128_00352AF8 *)&v3 = *(u128_00352AF8 *)&v1;
        *(u128_00352AF8 *)&v4 = *(u128_00352AF8 *)&v1;
        func_003BF6A8(&v2, D_L18_001DD3C8);
        func_003BF6A8(&v3, D_L18_001DD3C8);
        func_003BF6A8(&v4, D_L18_001DD3C8);
        func_0037E4B8(&vec, -(func_0037E250(D_L18_001DD3CC, D_L18_001DD3D0) * 0.0166666675f) * s, b, a);
        func_L01_0046A9C8(a0, &v2, &vec, &D_L18_001DD398_00351EF0[k][0], 1);
        func_003886E8(&vec, &vec, func_0037E250(D_L18_001DD3D4, D_L18_001DD3D8));
        func_L01_0046A9C8(a0, &v3, &vec, &D_L18_001DD398_00351EF0[k][1], 1);
        func_003886E8(&vec, &vec, func_0037E250(D_L18_001DD3D4, D_L18_001DD3D8));
        func_L01_0046A9C8(a0, &v4, &vec, &D_L18_001DD398_00351EF0[k][2], 1);
    }
}
/* localdecomp:end func_L18_00351EF0 */
