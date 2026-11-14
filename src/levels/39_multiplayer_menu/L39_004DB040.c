#include "common.h"

/* localdecomp:start func_L39_004DB040 */
s32 func_L39_004DAAB0(void *arg0);

void func_L39_004DB040(void *arg0) {
    s32 t;
    void *cur;
    while (arg0 != 0) {
        cur = arg0;
        t = *(s32 *)((u8 *)arg0 + 0x2C);
        arg0 = *(void **)((u8 *)arg0 + 0x24);
        func_L39_004DAAB0(cur);
        if (t >= 2) {
            break;
        }
    }
}
/* localdecomp:end func_L39_004DB040 */

/* localdecomp:start func_L39_004DB090 */
s32 func_L39_004BB440(void *arg0);
void func_L39_004BB3F0(void *arg0, s32 arg1);

void func_L39_004DB090(void *arg0) {
    func_L39_004BB3F0(arg0, func_L39_004BB440(*(void **)((u8 *)arg0 + 0x24)));
    *(s32 *)((u8 *)arg0 + 0x18) = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x24) + 0x18);
}
/* localdecomp:end func_L39_004DB090 */

LINKER_REMNANT("asm/levels", func_L39_004DB0D0);
