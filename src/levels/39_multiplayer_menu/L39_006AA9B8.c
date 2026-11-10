#include "common.h"

/* localdecomp:start func_L39_006AA9B8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0067F168();

void func_L39_006AA9B8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
    *(s32 *)((u8 *)p + 0x39C) = -1;
    *(s32 *)((u8 *)p + 0x3A0) = -1;
    *(s32 *)((u8 *)p + 0x3AC) = -1;
    *(s32 *)((u8 *)p + 0x3A8) = -1;
    *(s32 *)((u8 *)p + 0x3A4) = -1;
    *(s32 *)((u8 *)p + 0x3B0) = -1;
    *(s32 *)((u8 *)p + 0x3B4) = -1;
    *(s32 *)((u8 *)p + 0x3B8) = -1;
}
/* localdecomp:end func_L39_006AA9B8 */

INCLUDE_ASM("asm/levels", func_L39_006AAA08);
