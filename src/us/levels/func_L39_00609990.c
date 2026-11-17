#include "common.h"

/* localdecomp:start func_L39_00609990 */
extern s32 func_L01_003EE980(void);
extern s32 func_L01_003D7990(void);
extern u32 D_001A4CD0[];
__asm__(".extern D_L39_00244000, 16");
extern s32 D_L39_00244000;

/* Returns 1 and records the id when two optional checks (matching the current values of two
 * getters, -1 meaning any) pass and its bit is not set in a global bit array, else returns 0. */
s32 func_L39_00609990(s32 a, s32 b, u32 c) {
    s32 none = -1;
    u32 idx;

    if (a != none && func_L01_003EE980() != a) {
        return 0;
    }
    if (b != none && func_L01_003D7990() != b) {
        return 0;
    }
    idx = c >> 2;
    if (D_001A4CD0[idx] & (1 << (c & 0x1F))) {
        return 0;
    }
    D_L39_00244000 = c;
    return 1;
}
/* localdecomp:end func_L39_00609990 */
