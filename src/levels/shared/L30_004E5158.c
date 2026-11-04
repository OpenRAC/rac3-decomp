#include "common.h"

typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;

INCLUDE_ASM("asm/levels", func_L30_004E5158);

INCLUDE_ASM("asm/levels", func_L30_004E5370);

INCLUDE_ASM("asm/levels", func_L30_004E5410);

INCLUDE_ASM("asm/levels", func_L30_004E5598);

INCLUDE_ASM("asm/levels", func_L30_004E56D0);

INCLUDE_ASM("asm/levels", func_L30_004E5788);

INCLUDE_ASM("asm/levels", func_L30_004E58F8);

INCLUDE_ASM("asm/levels", func_L30_004E5BF0);

INCLUDE_ASM("asm/levels", func_L30_004E5DD8);

/* localdecomp:start func_L30_004E5F28 */
extern void func_L01_005110E8(s32, f32, f32, f32, s32);

void func_L30_004E5F28(s32 a) {
    func_L01_005110E8(a, 0.0f, 0.0f, 2.3f, 1);
}
/* localdecomp:end func_L30_004E5F28 */

INCLUDE_ASM("asm/levels", func_L30_004E5F58);

INCLUDE_ASM("asm/levels", func_L30_004E6068);

INCLUDE_ASM("asm/levels", func_L30_004E6200);

/* localdecomp:start func_L30_004E6988 */
extern S_004E6988 D_001A4BE0;

f32 func_L30_004E6988(void) {
    s32 x = D_001A4BE0.p25C0[0x43];
    f32 f = 0.0f;
    if (D_001A4BE0.w25C4 == 0xA3) {
        if ((u32)(x - 0x11) < 3) {
            f = 1.5707964f;
        }
        if ((u32)(x - 0x14) < 3) {
            f = 0.7853982f;
        }
        if ((u32)(x - 0x1A) < 3) {
            f = -0.7853982f;
        }
        if ((u32)(x - 0x1D) < 3) {
            f = -1.5707964f;
        }
    }
    if (*(u16 *)(D_001A4BE0.p25C0 + 0x34) & 0x8000) {
        f = 3.1415927f - f;
    }
    return f;
}
/* localdecomp:end func_L30_004E6988 */

INCLUDE_ASM("asm/levels", func_L30_004E6A48);

INCLUDE_ASM("asm/levels", func_L30_004E6AD0);

LINKER_REMNANT("asm/levels", func_L30_004E6D00);

INCLUDE_ASM("asm/levels", func_L30_004E6D08);

INCLUDE_ASM("asm/levels", func_L30_004E6DC8);

INCLUDE_ASM("asm/levels", func_L30_004E6E50);

INCLUDE_ASM("asm/levels", func_L30_004E6ED8);

INCLUDE_ASM("asm/levels", func_L30_004E70A8);

INCLUDE_ASM("asm/levels", func_L30_004E71F0);
