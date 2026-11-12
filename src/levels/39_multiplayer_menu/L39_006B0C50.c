#include "common.h"

/* localdecomp:start func_L39_006B0C50 */
extern void *D_00247914[];
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);

void func_L39_006B0C50(void *object)
{
    func_L39_0067F168();
    *(u8 *)((u8 *)D_00247914[0] + 0x280) = *(u8 *)((u8 *)object + 0x2A8);
    func_L39_0068ADC8(object);
}
/* localdecomp:end func_L39_006B0C50 */

INCLUDE_ASM("asm/levels", func_L39_006B0C90);
