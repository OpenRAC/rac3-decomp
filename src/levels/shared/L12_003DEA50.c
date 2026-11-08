#include "common.h"

/* localdecomp:start func_L12_003DEA50 */
extern char D_L12_001DF220;

/* from rac4-decomp's func_L01_003D78E0 */
void *func_L12_003DEA50(long a1, long a2, int *a3)
{
    if (a2 == 0) {
        *a3 = 4;
        return &D_L12_001DF220;
    }
    return 0;
}
/* localdecomp:end func_L12_003DEA50 */
