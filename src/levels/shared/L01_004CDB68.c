#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004CDB68);

INCLUDE_ASM("asm/levels", func_L01_004CDB70);

INCLUDE_ASM("asm/levels", func_L01_004CDC38);

/* localdecomp:start func_L01_004CDEA8 */
extern s32 func_11BB58(void *, s32, s32);
extern void func_L01_004CDC38(void *, s32, s32, f32, f32);

void func_L01_004CDEA8(u8 *object, s32 value, s32 count)
{
    s32 limit = (count == -1) ? 300 : count;
    u8 *inner = object + 0x4ED0;

    func_11BB58((void *)(object + 0x4F58), value, 255);
    func_L01_004CDC38((void *)inner, 1, limit, 255.0f, 80.0f);
}
/* localdecomp:end func_L01_004CDEA8 */

/* localdecomp:start func_L01_004CDF10 */
void func_L01_004CDF10(u8 *a0) {
    **(s32 **)(a0 + 20180) = 0;
}
/* localdecomp:end func_L01_004CDF10 */
