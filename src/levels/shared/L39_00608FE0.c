#include "common.h"

/* localdecomp:start func_L39_00608FE0 */
__asm__(".extern D_001D5C90_sda, 4");
extern int func_00139E08(int);
extern int D_001D5C90_sda;
extern volatile s32 D_L39_0024CC28;
__asm__(".extern D_L39_0024CC28, 16");
extern volatile s32 D_L39_0024CC2C;
__asm__(".extern D_L39_0024CC2C, 16");

void func_L39_00608FE0(int value)
{
    while (func_00139E08(0) == value && D_001D5C90_sda == 0) {}
    D_L39_0024CC28 = 1;
    D_L39_0024CC2C = 0;
}
/* localdecomp:end func_L39_00608FE0 */
