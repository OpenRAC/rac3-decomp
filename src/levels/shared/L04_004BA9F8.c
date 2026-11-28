#include "common.h"

typedef struct { int w[32]; } S;

/* localdecomp:start func_L04_004BA9F8 */
extern S D_001A30B0[];
int func_L04_004BA9F8(unsigned int a, int b) {
    if (a < 0x34) { int *p = D_001A30B0[a].w; p[0x36] = b; }
    return 1;
}
/* localdecomp:end func_L04_004BA9F8 */
