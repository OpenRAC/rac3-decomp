#include "common.h"

/* localdecomp:start func_L07_003670F0 */
extern int D_L07_001DD800;
extern int D_L07_0028E440[];
unsigned char func_L07_003670F0(void) {
    unsigned char c = 0;
    int i;
    for (i = 0; i < D_L07_001DD800; i++) {
        if (D_L07_0028E440[i] != 0) c++;
    }
    return c;
}
/* localdecomp:end func_L07_003670F0 */
