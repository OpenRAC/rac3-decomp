#include "common.h"

/* localdecomp:start func_L39_005BD300 */
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; u8 pad[0xC]; } E_005BD300;
extern E_005BD300 D_L39_004840A0[];
void func_L39_005BD300(void) {
    s32 i;
    E_005BD300 *e;
    for (i = 0; i < 8; i++) {
        e = &D_L39_004840A0[i];
        if (e->w0 == 0) {
            e->wC++;
            if (e->wC > 10) e->wC = 10;
        } else {
            e->wC = 0;
        }
        if (e->w8 != 0) {
            e->w8--;
            if (e->w8 == 0) e->w0 = 0;
        }
    }
}
/* localdecomp:end func_L39_005BD300 */

INCLUDE_ASM("asm/levels", func_L39_005BD368);
