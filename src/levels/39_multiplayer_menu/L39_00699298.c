#include "common.h"

/* localdecomp:start func_L39_00699298 */
extern void *D_00247914[];
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);

void func_L39_00699298(void *object)
{
    func_L39_0067F168();
    func_L39_0068ADC8(object);
    *(u8 *)((u8 *)D_00247914[0] + 0x280) = 0;
    *(u8 *)((u8 *)object + 0x2B4) = 0;
}
/* localdecomp:end func_L39_00699298 */
