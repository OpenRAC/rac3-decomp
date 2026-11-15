#include "common.h"

/* localdecomp:start func_L39_004D0C60 */
__asm__(".extern D_L39_0046A088, 16");
extern unsigned long D_L39_0046A088[];

/* from rac4-decomp's func_003F6170 */
void func_L39_004D0C60(long arg0) {
    D_L39_0046A088[0] = (unsigned long)(arg0 << 32) >> 32;
}
/* localdecomp:end func_L39_004D0C60 */
