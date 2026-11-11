#include "common.h"

/* localdecomp:start func_L39_006B7DB0 */
extern s32 D_001DDA64_sda;

extern s32 func_L39_006B7340(s32);
extern s32 func_L39_006B7410(s32);
extern s32 func_L39_006B7490(s32);
extern s32 func_L39_006B7958(s32, s32 *);
extern s32 func_L39_006B7CD8(s32);
extern s32 func_L39_006B7D80(s32);

s32 func_L39_006B7DB0(s32 a0, s32 a1)
{
    s32 ret = 0;

    switch (D_001DDA64_sda) {
    case 0:
        func_L39_006B7340(a0);
        break;
    case 1:
        func_L39_006B7410(a0);
        break;
    case 2:
        func_L39_006B7490(a0);
        break;
    case 3:
        ret = func_L39_006B7958(a0, &a1);
        break;
    case 6:
        func_L39_006B7CD8(a0);
        break;
    case 7:
        ret = func_L39_006B7D80(a0);
        break;
    case 4:
    case 5:
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_006B7DB0 */
