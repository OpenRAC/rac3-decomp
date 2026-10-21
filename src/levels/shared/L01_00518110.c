#include "common.h"

/* localdecomp:start func_L01_00518110 */
extern s32 func_003E8630(void *a0, void *a1);

s32 func_L01_00518110(void *a0, void *a1, void *a2, void *a3) {
    s32 r = func_003E8630(a0, a1) != 0;
    s32 t = func_003E8630(a0, a2) != 0;
    r = r & t;
    t = func_003E8630(a0, a3) != 0;
    return r & t;
}
/* localdecomp:end func_L01_00518110 */
