#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003B4350);

/* localdecomp:start func_L10_003B4600 */
extern void func_0038A238(s32);
extern void func_L01_0042B068(s32, s32);
extern void func_003864C0(s32);
extern f32 D_L10_001DEC50;
extern u8 D_L10_001DECE4;
extern u8 D_L10_001DECE5;
extern u8 D_L10_001DECE6;
extern f32 D_L10_001DECE8;
extern f32 D_L10_001DECEC;
extern f32 D_L10_001DECF0;
extern f32 D_L10_001DECF4;

void func_L10_003B4600(void) {
    func_0038A238(5);
    func_L01_0042B068(2, 0);
    D_L10_001DEC50 = 1.5f;
    D_L10_001DECE4 = 1;
    D_L10_001DECE5 = 1;
    D_L10_001DECE6 = 1;
    D_L10_001DECE8 = 262144.0f;
    D_L10_001DECEC = 524288.0f;
    D_L10_001DECF0 = 255.0f;
    D_L10_001DECF4 = 249.0f;
    func_003864C0(0);
}
/* localdecomp:end func_L10_003B4600 */

INCLUDE_ASM("asm/levels", func_L10_003B4698);

INCLUDE_ASM("asm/levels", func_L10_003B5690);

INCLUDE_ASM("asm/levels", func_L10_003B57A8);
