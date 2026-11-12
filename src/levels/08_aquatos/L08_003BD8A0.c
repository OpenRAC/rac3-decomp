#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_003BD8A0);

INCLUDE_ASM("asm/levels", func_L08_003BDA50);

INCLUDE_ASM("asm/levels", func_L08_003BDBB8);

INCLUDE_ASM("asm/levels", func_L08_003BDE60);

/* localdecomp:start func_L08_003BDFB8 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_00452460(void *, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(u8 *);
extern void func_L08_003BDE60(void *, f32, f32);
extern s32 D_L08_001D66B0;

void func_L08_003BDFB8(void *arg0) {
    if (func_L01_00447490(arg0, -1, 0) != 0) {
        func_L01_00451FE0(arg0, 1, &D_L08_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L08_003BDE60(arg0, 0.7f, -2.3f);
        func_003A52A0(0, 0, arg0);
        func_L01_00452460(arg0, 0x1E90, 0);
        func_L01_00451E78(arg0, 1, 0.0f);
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L08_003BDFB8 */
