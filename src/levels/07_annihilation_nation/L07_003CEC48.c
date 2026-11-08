#include "common.h"

/* localdecomp:start func_L07_003CEC48 */
extern s32 D_L07_001DF41C;
s32 func_L07_003BAC58(s32);
s32 func_L07_003BADA8(void);

s32 func_L07_003CEC48(void *arg0) {
    void *p;
    s32 a;

    p = *(void **)((u8 *)arg0 + 0x68);
    if (*(s16 *)((u8 *)p + 0x144) != 1) {
        return 0;
    }
    a = *(s32 *)((u8 *)p + 0x420);
    if (a != -1) {
        if (func_L07_003BAC58(D_L07_001DF41C + (a << 8)) == 0) {
            return 0;
        }
    }
    a = *(s32 *)((u8 *)p + 0x424);
    if (a != -1) {
        if (func_L07_003BADA8() == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003CEC48 */

INCLUDE_ASM("asm/levels", func_L07_003CECD0);
