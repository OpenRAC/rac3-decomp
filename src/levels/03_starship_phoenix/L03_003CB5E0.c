#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x44];
    s32 w6C;
    u8 pad70[0x24];
    s32 w94;
} S_001CCFD0_003CBB68;

INCLUDE_ASM("asm/levels", func_L03_003CB5E0);

INCLUDE_ASM("asm/levels", func_L03_003CB910);

INCLUDE_ASM("asm/levels", func_L03_003CBA20);

/* localdecomp:start func_L03_003CBB68 */
extern S_001CCFD0_003CBB68 D_001CCFD0;
extern s32 func_L01_004BA800(void);
extern void func_003A2B68(s32, s32);

s32 func_L03_003CBB68(s32 a0, s32 a1) {
    if (func_L01_004BA800() != 0) {
        return 0;
    }
    if (D_001CCFD0.w6C != 0) {
        return 0;
    }
    if (D_001CCFD0.w24 != -1) {
        return 0;
    }
    if (D_001CCFD0.w94 != 0) {
        return 0;
    }
    func_003A2B68((a1 & 0x3FFF) + 0x7D0, 0);
    return 1;
}
/* localdecomp:end func_L03_003CBB68 */

INCLUDE_ASM("asm/levels", func_L03_003CBBD8);

INCLUDE_ASM("asm/levels", func_L03_003CBC28);

INCLUDE_ASM("asm/levels", func_L03_003CBD50);
