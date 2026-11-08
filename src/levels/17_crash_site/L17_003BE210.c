#include "common.h"

INCLUDE_ASM("asm/levels", func_L17_003BE210);

/* localdecomp:start func_L17_003BE2F8 */
typedef struct { u8 p0[0x30]; u8 b30; u8 p31[3]; u16 h34; } S_E2F8_O;
extern void func_L01_004450F0(S_E2F8_O *, s32, s32);
void func_L17_003BE2F8(S_E2F8_O *a0) {
    func_L01_004450F0(a0, 1, -1);
    a0->b30 = 0xFF;
    a0->h34 &= ~1;
}
/* localdecomp:end func_L17_003BE2F8 */

INCLUDE_ASM("asm/levels", func_L17_003BE338);
