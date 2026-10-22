#include "common.h"

/* localdecomp:start func_L39_0068A8F8 */
s32 func_L01_00516470(s32, f32, f32);
s32 func_L01_005169C8(s32, f32);
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
s32 func_L01_00517538(s32, f32, f32);
extern u8 D_L39_003D2880[];

void func_L39_0068A8F8(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    s32 *temp_s0;

    temp_s0 = ((arg0 + 0x94) * 4) + D_L39_003D2880;
    func_L01_00516AA0(*temp_s0, 1, 1);
    func_L01_005170B8(*temp_s0, arg1);
    func_L01_00516470(*temp_s0, fparg0, fparg1);
    func_L01_00517538(*temp_s0, fparg2, fparg3);
    func_L01_005169C8(*temp_s0, fparg4);
}
/* localdecomp:end func_L39_0068A8F8 */

INCLUDE_ASM("asm/levels", func_L39_0068A9B8);

INCLUDE_ASM("asm/levels", func_L39_0068AAB8);

INCLUDE_ASM("asm/levels", func_L39_0068ADC8);

INCLUDE_ASM("asm/levels", func_L39_0068AEF8);

INCLUDE_ASM("asm/levels", func_L39_0068AF68);

INCLUDE_ASM("asm/levels", func_L39_0068B058);

INCLUDE_ASM("asm/levels", func_L39_0068B178);

INCLUDE_ASM("asm/levels", func_L39_0068B1E0);

INCLUDE_ASM("asm/levels", func_L39_0068B260);

INCLUDE_ASM("asm/levels", func_L39_0068B2F8);

INCLUDE_ASM("asm/levels", func_L39_0068B3C0);
