#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003EBDB8);

INCLUDE_ASM("asm/levels", func_L04_003EC000);

/* localdecomp:start func_L04_003EC268 */
extern u8 D_L04_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L04_003EC268(void *o) {
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_003A52A0(0, 0, o);
        func_L01_00451FE0(o, 15, D_L04_001D66B0, 255, 180, 0, 0, 35, 0, 3, 2.0f, 4.0f, 2.0f, 4.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00451E78(o, 1, 0.0f);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L04_003EC268 */
