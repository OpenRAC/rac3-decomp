#include "common.h"

/* localdecomp:start func_L36_003DFFE8 */
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBE90[][0x400];
extern int D_001D545C;

/* from rac2-decomp's func_00279B70 */
int func_L36_003DFFE8(u8 *a0, int a1, int a2)
{
    int c = D_001BBE90[D_001D545C][a2 >> 1];
    return (a0[(a2 & 1) ? ((c >> 4) & 7) : (c & 7)] * a1) / 100;
}
/* localdecomp:end func_L36_003DFFE8 */
