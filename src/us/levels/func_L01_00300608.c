#include "common.h"

/* NTSC-U counterpart of func_L01_00300678 (src/levels/shared/L01_00300678.c): 8 -> 10 */
#include "vu0.h"

/* localdecomp:start func_L01_00300608 */
extern s32 D_001A71A4[];
extern void func_003BE4F0(void *, s32, s32, s32);

void func_L01_00300608(u8 *a0) {
    if (D_001A71A4[0] == 8) {
        if (a0[0x43] != 6) {
            func_003BE4F0(a0, 6, 0, 10);
        }
    }
}
/* localdecomp:end func_L01_00300608 */
