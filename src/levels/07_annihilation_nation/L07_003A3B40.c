#include "common.h"

/* localdecomp:start func_L07_003A3B40 */
extern s32 func_L01_0033D178(void *);
extern s32 D_L07_001DF41C;
extern s32 D_L07_001DF41C_sda;
__asm__(".extern D_L07_001DF41C, 16");
__asm__(".extern D_L07_001DF41C_sda, 4");

s32 func_L07_003A3B40(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    s32 a, r;

    if (func_L01_0033D178((u8 *)D_L07_001DF41C + (*(s32 *)p << 8)) == 0)
        return 0;
    a = *(s32 *)(p + 4);
    if (a != -1) {
        r = func_L01_0033D178((u8 *)D_L07_001DF41C_sda + (a << 8));
        if (r == 0)
            return 1;
    }
    return -1;
}
/* localdecomp:end func_L07_003A3B40 */

INCLUDE_ASM("asm/levels", func_L07_003A3BB0);
