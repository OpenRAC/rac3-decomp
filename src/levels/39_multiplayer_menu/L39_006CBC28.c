#include "common.h"

/* localdecomp:start func_L39_006CBC28 */
extern s32 D_L39_00249160 __attribute__((section(".data")));
extern void func_L39_0067F168(void *);
extern void func_L39_0068ADC8(void *);

void func_L39_006CBC28(void *object)
{
    func_L39_0067F168(object);
    func_L39_0068ADC8(object);
    D_L39_00249160 = -1;
    *(s32 *)((u8 *)object + 0x2B0) = 0;
    *(s32 *)((u8 *)object + 0x2A8) = 0;
    *(s32 *)((u8 *)object + 0x2AC) = 0;
}
/* localdecomp:end func_L39_006CBC28 */

INCLUDE_ASM("asm/levels", func_L39_006CBC70);
