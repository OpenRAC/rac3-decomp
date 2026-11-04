#include "common.h"

/* localdecomp:start func_L10_003BC128 */
extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L10_003BC128(u8 *self) {
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00452310(self, 0x1FFF, D_L10_001D66B0, 1, 30, 1.0f, 3.0f, 6.0f, 3.0f, 6.0f,
                          255, -1.0f, -1.0f, 180, 0);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L10_003BC128 */
