#include "common.h"

/* localdecomp:start func_L40_00434168 */
extern s32 D_001A5FC0 __attribute__((section(".data")));
extern s32 D_001A6C00 __attribute__((section(".data")));
extern void func_003BD360(u8 *);
extern s32 func_L39_00669F20(u8 *, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);

void func_L40_00434168(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        if (D_001A5FC0 != 0 || D_001A6C00 == 0) {
            func_003BD360(a0);
        } else {
            func_L39_00669F20(a0, -1, 1);
            a0[48] = 16;
            *(s16 *)(p + 30) = 160;
            *(s16 *)(p + 28) = -3;
            func_L01_00441FB8(a0, 1, -1);
        }
    }
}
/* localdecomp:end func_L40_00434168 */
