#include "common.h"

/* localdecomp:start func_L03_0039B418 */
s32 func_L01_00456250(void *);
extern s32 D_L03_001DF99C;

void func_L03_0039B418(void *arg0) {
    void *temp_a0;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if (func_L01_00456250(arg0) != 0) {
        temp_a0 = *(void **)((u8 *)((D_L03_001DF99C + (*(*(s32 **)((u8 *)arg0 + 0x68)) << 8))) + 0x68);
        if ((*(s32 *)((u8 *)temp_a0 + 0xC)) != 1) {
            *(s32 *)((u8 *)temp_a0 + 0xC) = 1;
        }
    }
}
/* localdecomp:end func_L03_0039B418 */
