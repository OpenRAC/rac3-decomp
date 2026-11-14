#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_0035B3B8);

/* localdecomp:start func_L07_0035C880 */
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L07_0035C880(u8 *a0)
{
    u8 buf[0x10];
    s32 v;

    v = a0[0x20] == 5 ? 0x40202080 : 0x40802020;
    func_003C2F58(a0, 2, buf);
    func_003D9508(buf, 0xB, v, 1, 0.1f, 0.08f, 0.0f);
    func_003C2F58(a0, 3, buf);
    func_003D9508(buf, 0xB, v, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_L07_0035C880 */

INCLUDE_ASM("asm/levels", func_L07_0035C958);
