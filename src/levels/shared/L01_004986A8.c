#include "common.h"

/* localdecomp:start func_L01_004986A8 */
void func_L01_004986A8(void *arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;

    if (arg1 < (*(s32 *)((u8 *)arg0 + 0xC))) {
        temp_v0 = ((s32) (*(s32 *)((u8 *)arg0 + 0x10)) / 2) - 1;
        *(s32 *)((u8 *)arg0 + 8) = temp_v0;
        if (temp_v0 < 0) {
            *(s32 *)((u8 *)arg0 + 8) = 0;
        }
        temp_a3 = *(s32 *)((u8 *)arg0 + 0x10);
        temp_v1 = arg1 - (*(s32 *)((u8 *)arg0 + 8));
        temp_a2 = *(s32 *)((u8 *)arg0 + 0xC);
        *(s32 *)((u8 *)arg0 + 4) = temp_v1;
        if ((temp_v1 + temp_a3) >= temp_a2) {
            *(s32 *)((u8 *)arg0 + 4) = (s32) (temp_a2 - temp_a3);
        } else if (temp_v1 < 0) {
            *(s32 *)((u8 *)arg0 + 4) = 0;
        }
        *(s32 *)((u8 *)arg0 + 8) = (s32) (arg1 - (*(s32 *)((u8 *)arg0 + 4)));
    }
}
/* localdecomp:end func_L01_004986A8 */
