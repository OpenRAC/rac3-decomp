#include "common.h"

/* localdecomp:start func_L40_005406C0 */
extern u8 *func_L39_0061D7B0(void *);
extern s32 func_L40_005416F0(s32 *a);
extern s32 D_L40_002499F4 __attribute__((section(".sdata")));

long func_L40_005406C0(u8 *a0) {
    u8 *o = func_L39_0061D7B0(a0);
    u8 *p;
    long t;
    s32 r;

    if (o != 0 && (o[3] & 0xF) == 7 && o[0x2C] != 0) {
        return *(s32 *)(o + 4) == D_L40_002499F4;
    }
    p = func_L39_0061D7B0(a0);
    t = 0;
    if (p != 0) {
        r = func_L40_005416F0((s32 *)p) != 0;
        t = r;
    }
    return t;
}
/* localdecomp:end func_L40_005406C0 */
