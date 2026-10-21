#include "common.h"

/* localdecomp:start func_L03_003F6A80 */
typedef s32 (*Fn003F4470)(s32, s32, s32, s32, s32);
extern Fn003F4470 *func_L01_0043B568(s32, s32, s32);
s32 func_L03_003F6A80(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    Fn003F4470 *f = func_L01_0043B568(2491, 0, 4);
    if (f == 0) {
        return 0;
    }
    return (*f)(a0, a1, a2, a3, t0);
}
/* localdecomp:end func_L03_003F6A80 */

LINKER_REMNANT("asm/levels", func_L03_003F6B10);
