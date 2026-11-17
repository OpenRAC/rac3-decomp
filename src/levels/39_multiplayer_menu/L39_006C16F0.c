#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_00688400(void *, s32);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);

/* localdecomp:start func_L39_006C16F0 */
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);

void func_L39_006C16F0(void *object)
{
    *(u8 *)((u8 *)object + 0x2B4) = 0;
    *(s32 *)((u8 *)object + 0x2AC) = -1;
    *(s32 *)((u8 *)object + 0x2B0) = -1;
    func_L39_0067F168();
    func_L39_0068ADC8(object);
}
/* localdecomp:end func_L39_006C16F0 */

INCLUDE_ASM("asm/levels", func_L39_006C1730);
