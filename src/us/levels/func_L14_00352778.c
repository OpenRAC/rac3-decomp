#include "common.h"

/* NTSC-U counterpart of func_L14_00353790 (src/levels/14_koros/L14_00353718.c): 167 -> 200 */
#include "vu0.h"

/* localdecomp:start func_L14_00352778 */
extern u8 D_L14_001D66B0_00352778;
extern s32 D_L14_001D67B8_00352778;
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L02_00426140(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);
extern void func_00388830(void *, void *, f32);
void func_L14_00352778(u8 *a0) {
    vu0_v4 buf10;
    vu0_v4 v20;
    vu0_v4 *v10;
    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 7, &D_L14_001D66B0_00352778, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        v10 = &buf10;
        *v10 = *(vu0_v4 *)(a0 + 0x10);
        buf10.z += 1.5f;
        func_00388830(&v20, a0 + 0xD0, 1.0f);
        vec_add_ab(v10, v10, &v20);
        func_L02_00426140(a0, v10, 5, 0, &D_L14_001D66B0_00352778, 0x463C5028, 0, 0xC8, 1.0f, 30.0f, 1.5f, 2.5f);
        func_L01_0044EBF8(a0, 1, 0.0f);
        D_L14_001D67B8_00352778 = D_L14_001D67B8_00352778 + 1;
        if (D_L14_001D67B8_00352778 >= 100) {
            func_L01_00456960(0x11);
        }
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L14_00352778 */
