#include "common.h"

/* localdecomp:start func_L39_00515A70 */
/* best: 82 diff (mostly shifted by 1). Retail keeps the call result live in $v0 along the fall-through (bnez, lw $a0 for the src reload, no move $v0,$zero); this C lets gcc know res==0 after the test, so it uses $v0 as a temp and adds move $v0,$zero. Tried: early returns, nested ifs, single-exit res=0x20F, return 0. */
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18; s32 *f1C; s32 *f20; s32 *f24; } S_00515A70;
extern u8 D_L39_0046F468[];
extern s32 func_L39_005084A8(s32, S_00515A70 **, u8 *);
extern s32 func_L39_004F6060(s32, s32 **, s32);

s32 func_L39_00515A70(s32 **arg0, s32 arg1) {
    S_00515A70 *src;
    s32 res;
    s32 *dst;

    res = func_L39_005084A8(arg1, &src, D_L39_0046F468);
    if (res != 0) {
        return res;
    }
    if (src->f18 != 2) {
        return 0x20F;
    }
    res = func_L39_004F6060(arg1, arg0, 0x40);
    if (res != 0) {
        return res;
    }
    dst = *arg0;
    dst[0] = src->f0;
    dst[1] = src->f4;
    dst[2] = src->f8;
    dst[3] = src->fC;
    dst[4] = src->f10;
    dst[5] = src->f14;
    dst[6] = src->f1C[0];
    dst[7] = src->f1C[1];
    dst[8] = src->f1C[2];
    dst[9] = src->f1C[3];
    dst[10] = src->f20[0];
    dst[11] = src->f20[1];
    dst[12] = src->f20[2];
    dst[13] = src->f20[3];
    dst[14] = src->f24[0];
    dst[15] = src->f24[1];
    return res;
}
/* localdecomp:end func_L39_00515A70 */
