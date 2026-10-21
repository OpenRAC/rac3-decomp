#include "common.h"

/* localdecomp:start func_L01_004D0CB0 */
extern u32 *func_L01_004CC758_004D0CB0(u8 *);

u32 func_L01_004D0CB0(u8 *a0) {
    return *func_L01_004CC758_004D0CB0(a0 + 700) & 0xFF000000;
}
/* localdecomp:end func_L01_004D0CB0 */
