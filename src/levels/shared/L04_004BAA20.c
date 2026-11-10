#include "common.h"

typedef struct { int w[32]; } S;

/* localdecomp:start func_L04_004BAA20 */
extern S D_001A30B0[];
int func_L04_004BAA20(unsigned int a, int b) {
    if (a < 0x34) { int *p = D_001A30B0[a].w; p[0x35] = b; }
    return 1;
}
/* localdecomp:end func_L04_004BAA20 */
