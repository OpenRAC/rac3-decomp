#include "common.h"

/* localdecomp:start func_L13_003C5E20 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_L01_00409B08(u8 *a0, s32 a1, s32 a2);
extern void func_L01_00409E70(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_L13_003C5E20(u8 *a0) {
    u8 buf[16];
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 104);
        if (s0 != 0) {
            func_003C2F58(a0, 0, buf);
            func_L01_00409B08(buf, 0x103080, 0);
            func_L01_00409E70(buf, s0 + 48, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}
/* localdecomp:end func_L13_003C5E20 */

INCLUDE_ASM("asm/levels", func_L13_003C5EA8);

INCLUDE_ASM("asm/levels", func_L13_003C62A8);

INCLUDE_ASM("asm/levels", func_L13_003C63A8);
