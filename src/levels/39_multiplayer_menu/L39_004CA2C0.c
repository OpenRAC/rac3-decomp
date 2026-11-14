#include "common.h"

/* localdecomp:start func_L39_004CA2C0 */
extern s32 func_1205B0(char *, char *);

s32 func_L39_004CA2C0(char ***a, char ***b) {
    char **x = *a;
    char **y = *b;
    return func_1205B0(x[1], y[1]);
}
/* localdecomp:end func_L39_004CA2C0 */
