#include "common.h"

/* NTSC-U counterpart of func_L40_00434048 (src/levels/shared/L40_00434048.c) */
/* localdecomp:start func_L40_004334E0 */
extern s32 D_001A6C00[];
extern s32 func_L39_005B2498(s32);
extern s32 func_0019D650(void);
extern s32 func_L40_00448C78(s32);
extern s32 func_L40_00448D68(void);
extern s32 func_L40_00449588(s32 a0);

s32 func_L40_004334E0(s32 *a0, u8 *a1) {
    s32 a;
    s32 b;
    s32 c;
    s32 r;
    s32 i;
    s32 res;

    *a0 = -1;
    *a1 = 0;
    a = 0;
    b = 75;
    c = 25;
    if (D_001A6C00[0] & 2) a = b;
    if (!(D_001A6C00[0] & 1)) b = 0;
    if (D_001A6C00[1] == 0) c = 0;
    r = func_L39_005B2498(b + a + c);
    if (r <= b) {
        *a0 = func_0019D650() & ~1;
        res = func_L40_00448C78(*a0);
        for (i = 0; res == 0; i++) {
            *a0 = func_0019D650() & ~1;
            res = func_L40_00448C78(*a0);
            if (i == 20) break;
        }
    } else if (r - b <= c) {
        *a0 = func_0019D650() & ~1;
        res = func_L40_00449588(*a0);
        *a1 = 1;
        for (i = 0; res == 0; i++) {
            *a0 = func_0019D650() & ~1;
            res = func_L40_00449588(*a0);
            if (i == 20) break;
        }
    } else {
        *a0 = func_L40_00448D68();
        res = func_L40_00449588(*a0);
        *a1 = 1;
        for (i = 0; res == 0; i++) {
            *a0 = func_L40_00448D68();
            res = func_L40_00448C78(*a0);
            if (i == 20) break;
        }
    }
    return res;
}
/* localdecomp:end func_L40_004334E0 */
