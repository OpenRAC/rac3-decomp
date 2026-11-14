#include "common.h"

/* declared by functions of L39_004CCE58.c, which this file was cut from */
extern void func_L39_004F4F18(s32 *);

/* localdecomp:start func_L39_004D1BB8 */
extern s32 func_L39_004F6E18(s32, s32 *, s32 *, s32, s32, s32);

s32 func_L39_004D1BB8(s32 a0) {
    s32 buf[4];
    s32 v;
    s32 r;

    do {
        r = func_L39_004F6E18(a0, buf, &v, 0, 0, 0);
    } while (0);
    func_L39_004F4F18(&a0);
    return r;
}
/* localdecomp:end func_L39_004D1BB8 */
