#include "common.h"

/* NTSC-U counterpart of func_L07_003CB9B8 (src/levels/shared/L07_003CB9B8.c) */
/* localdecomp:start func_L07_003C9FC8 */
/* from rac3-decomp's func_L01_00395288 (same shape) */
#include "vu0.h"
extern s32 D_001D545C_003C9FC8;
extern s32 D_L07_001DE6CC_003C9FC8;
extern s32 D_L07_001DE6D0_003C9FC8;
__asm__(".extern D_L07_001DE6CC_003C9FC8, 4");
__asm__(".extern D_L07_001DE6D0_003C9FC8, 4");
extern u8 *D_L07_0021EC98_003C9FC8[];
extern void func_L01_00440A88(f32 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L07_003C9FC8(void *a0) {
    f32 v[4];
    s32 i;
    f32 size;
    s32 color;
    u8 *particle;

    for (i = 0; i < 2; i++) {
        func_L01_00440A88(v, 0.06666667f, 0.09166667f);
        v[2] = fabs_asm(v[2]) + func_0037E250(2.0f, 3.5f) * 0.016666668f;
        size = func_0037E250(0.06f, 0.22f);
        color = func_0037E1D8(3) ? D_L07_001DE6D0_003C9FC8 : D_L07_001DE6CC_003C9FC8;
        switch (D_001D545C_003C9FC8) {
        case 41:
        case 45:
        case 47:
            color = func_0037E1D8(3) ? 0x605129 : 0x5A523E;
            break;
        case 12:
        case 18:
        case 40:
        case 42:
        case 43:
        case 44:
            color = func_0037E1D8(3) ? 0x263438 : 0x273538;
            break;
        }
        particle = func_L01_0046DCB8(a0, v, func_0037E208(90, 150), color, -2, 127, 127,
                                     size * 210000.0f, size * 210000.0f, 0.0043333336f, 0);
        if (particle != 0) {
            particle[2] = D_L07_0021EC98_003C9FC8[97][func_0037E1D8(3) + 10];
            particle[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L07_003C9FC8 */
