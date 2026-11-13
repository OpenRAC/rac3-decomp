#include "common.h"

/* localdecomp:start func_L40_003F6078 */
extern int *D_L40_0035746C[];
int func_L40_003F6078(int *obj)
{
    int *state = (int *)obj[0x68/4];
    int *base = D_L40_0035746C[0];
    int *p = base + state[0x1C/4];
    return p[0x22];
}
/* localdecomp:end func_L40_003F6078 */
