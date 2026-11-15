#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 D_L39_004433C4[];

/* localdecomp:start func_L39_004BBBA0 */
/* method-table call with the "no method" error (siblings: func_L39_004BBBE8); sibling call j func_004BC6C8 = ee-gcc 2.9 library code */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BBBA0(void) {
    if (D_L39_004433C4[0] != 0) {
        ((void (*)(void))D_L39_004433C4[0])();
    } else {
        func_L39_004BC6C8(26, 112, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BBBA0 */
