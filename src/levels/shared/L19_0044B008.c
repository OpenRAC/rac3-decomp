#include "common.h"

/* localdecomp:start func_L19_0044B008 */
extern int D_L19_001D67B4;
extern int D_L19_001EE428[];

void func_L19_0044B008(int a) {
    int i = D_L19_001D67B4;
    if (i < 64) {
        D_L19_001D67B4 = i + 1;
        D_L19_001EE428[i] = a;
    }
}
/* localdecomp:end func_L19_0044B008 */
