/* func_L14_00354C28: near miss, 10 diff: file already @ps2as; left: order of the argument moves for func_L01_00451FE0 (retail interleaves mov.s $f14/$f15/$f17 with the integer li's and the two stack stores, ours groups the li's first); the same call matches in func_L01_003B1DC0, so this is a scheduling tie, not the prototype
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
void func_L14_00354C28(void *a0) {
    vu0_v4 v10;
    vu0_v4 v20;
    s32 i;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xFFF, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        qzero(&v10);
        qzero(&v20);
        for (i = 0; i < 7; i++) {
            func_003C2F58(a0, i, &v20);
            func_L02_003E2E38(a0, &v20, 2.0f, &v10, 10, 0, 0, 0.040000003f, 1.5f, 3.0f, 2.0f);
        }
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
