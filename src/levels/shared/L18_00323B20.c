#include "common.h"

/* localdecomp:start func_L18_00323B20 */
extern void func_L01_00409B08(u8 *, s32, s32);

void func_L18_00323B20(u8 *a0) {
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        func_L01_00409B08(a0 + 16, 0x305080, 1);
    }
}
/* localdecomp:end func_L18_00323B20 */
