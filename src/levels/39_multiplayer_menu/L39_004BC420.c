#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 D_L39_0044348C[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BC420 */
extern s32 D_L39_0044348C[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BC420(void *a) {
    if (D_L39_0044348C[0] != 0) {
        ((void (*)(void *))D_L39_0044348C[0])(a);
    } else {
        func_L39_004BC6C8(26, 134, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BC420 */
