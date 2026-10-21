#include "common.h"

LINKER_REMNANT("asm/levels", func_L03_00433088);

/* localdecomp:start func_L03_004330B8 */
extern s16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
extern void func_L01_00456230(u8 *, s32);

void func_L03_004330B8(s32 a0, s32 a1) {
    s16 *list = D_L03_0021C620[a0];
    s16 *p;
    if (list != 0) {
        p = list;
        do {
            func_L01_00456230(D_L03_001DF99C + ((*p & 0x7fff) << 8), a1);
        } while (*p++ >= 0);
    }
}
/* localdecomp:end func_L03_004330B8 */
