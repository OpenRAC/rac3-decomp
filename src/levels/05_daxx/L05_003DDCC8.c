#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003DDCC8);

/* localdecomp:start func_L05_003DDD20 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_L01_00451E78(u8 *a0, s32 a1, f32 f);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern u8 D_L05_001D66B0[8];

void func_L05_003DDD20(void *m) {
    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0xFFF, D_L05_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f,
                          0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L05_003DDD20 */
