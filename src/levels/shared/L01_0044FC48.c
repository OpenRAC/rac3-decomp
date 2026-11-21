#include "common.h"

/* localdecomp:start func_L01_0044FC48 */
typedef struct {
    s32 v[38];
} T_0044FC48;

extern T_0044FC48 D_L01_002BC250;
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);

void func_L01_0044FC48(s32 i, u8 flag) {
    T_0044FC48 t = D_L01_002BC250;

    if (flag) {
        func_L01_00451F60(t.v[i], -1, 0);
    } else if (t.v[i] != 0) {
        func_L01_00452560(0, 15, t.v[i], 150, 0, 0, 0);
    }
}
/* localdecomp:end func_L01_0044FC48 */

LINKER_REMNANT("asm/levels", func_L01_0044FD80);
