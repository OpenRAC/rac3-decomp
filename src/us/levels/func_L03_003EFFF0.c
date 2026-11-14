#include "common.h"

/* localdecomp:start func_L03_003EFFF0 */
typedef void (*fn_t)(int);
extern int D_L03_001DF3B8;
extern fn_t D_L03_001DF398[] __attribute__((section(".sdata")));
extern int D_L03_001DF3A8[] __attribute__((section(".sdata")));

void func_L03_003EFFF0(fn_t first, int second) {
    int index = D_L03_001DF3B8;
    if (index < 4) {
        D_L03_001DF398[index] = first;
        D_L03_001DF3A8[index] = second;
        D_L03_001DF3B8 = index + 1;
    }
}
/* localdecomp:end func_L03_003EFFF0 */
