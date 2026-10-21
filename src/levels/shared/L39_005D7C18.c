#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005D7C18);

INCLUDE_ASM("asm/levels", func_L39_005D7D80);

INCLUDE_ASM("asm/levels", func_L39_005D7FF8);

/* localdecomp:start func_L39_005D8D18 */
extern u8 D_L39_001D7F1C;
extern s32 D_L39_001D7F18;
extern s32 *D_L39_00241120[];
extern f32 D_L39_0024C2A8[];
extern f32 D_L39_0024C2AC[];
extern f32 D_L39_0024C2B0[];
extern f32 D_L39_0024C2B4[];
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005D8D18(s32 a0, f32 *a1, f32 *a2) {
    if (D_L39_001D7F1C) {
        func_003E82F8(*D_L39_00241120[0] < 2 ? 0 : 4);
        D_L39_001D7F18 = a0;
        D_L39_0024C2A8[0] = a1[0];
        D_L39_0024C2AC[0] = a1[1];
        D_L39_0024C2B0[0] = a2[0];
        D_L39_0024C2B4[0] = a2[1];
        func_L01_00516AA0(0x70000, 1, 1);
    }
}
/* localdecomp:end func_L39_005D8D18 */
