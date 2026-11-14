#include "common.h"

/* NTSC-U counterpart of func_L14_00354C28 (src/levels/14_koros/L14_003542F0.c): 0.04 -> 0.0333333 */
#include "vu0.h"
extern u8 D_L14_001D66B0_00353C08;
extern s32 D_L14_001D67B8_00353C08;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);
extern u8 D_L14_001D66B0_00353C08;
extern s32 D_L14_001D67B8_00353C08;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);

/* localdecomp:start func_L14_00353C08 */
extern u8 D_L14_001D66B0_00353C08;
extern s32 D_L14_001D67B8_00353C08;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
void func_L14_00353C08(void *a0) {
    vu0_v4 v10;
    vu0_v4 v20;
    s32 i;
    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0xFFF, &D_L14_001D66B0_00353C08, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        qzero(&v10);
        qzero(&v20);
        for (i = 0; i < 7; i++) {
            func_003BDA38(a0, i, &v20);
            func_L02_003E0520(a0, &v20, 2.0f, &v10, 10, 0, 0.0333333351f, 1.5f, 3.0f, 2.0f, 0);
        }
        D_L14_001D67B8_00353C08 = D_L14_001D67B8_00353C08 + 1;
        if (D_L14_001D67B8_00353C08 >= 100) {
            func_L01_00456960(0x11);
        }
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L14_00353C08 */
