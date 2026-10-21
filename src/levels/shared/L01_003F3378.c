#include "common.h"

/* localdecomp:start func_L01_003F3378 */
extern f32 D_L01_001D5FE8[2];
f32 *func_L01_003F3378(int i, f32 v) {
    f32 *p = &D_L01_001D5FE8[i];
    *p = v;
    return p;
}
/* localdecomp:end func_L01_003F3378 */

LINKER_REMNANT("asm/levels", func_L01_003F3390);
