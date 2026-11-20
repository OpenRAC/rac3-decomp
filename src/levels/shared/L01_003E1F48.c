#include "common.h"

/* localdecomp:start func_L01_003E1F48 */
extern u8 D_L01_001DF5A8[8];
__asm__(".extern D_L01_001DF5A8, 8");

u8 *func_L01_003E1F48(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 4;
        return D_L01_001DF5A8;
    }
    return 0;
}
/* localdecomp:end func_L01_003E1F48 */
