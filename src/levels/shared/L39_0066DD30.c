#include "common.h"

/* localdecomp:start func_L39_0066DD30 */
extern void *func_L39_0061D7B0(void *);
extern void *func_L39_00662678(void *, s32, s32);
void *func_L39_0066DD30(void *a, s32 b, s32 c) {
    void *v = func_L39_0061D7B0(a);
    if (v != 0) {
        return func_L39_00662678(v, b, c);
    }
    return 0;
}
/* localdecomp:end func_L39_0066DD30 */
