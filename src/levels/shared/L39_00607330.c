#include "common.h"

/* localdecomp:start func_L39_00607330 */
extern s32 D_L39_002412DC[];
extern s32 *D_L39_00241120[];
extern void func_L39_00605EF8(void *, s32);
extern void func_L01_004D2470(void *, s32);

void func_L39_00607330(u8 *arg0) {
    s32 i;

    if (D_L39_002412DC[0] != 39) {
        for (i = 0; i < *D_L39_00241120[0]; i++) {
            func_L39_00605EF8(arg0 + 6304 + i * 2896, i);
            func_L01_004D2470(arg0, i);
        }
    }
}
/* localdecomp:end func_L39_00607330 */
