#include "common.h"

/* localdecomp:start func_L39_005181D8 */
void func_L39_005181D8(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x18);
    *(void **)((u8 *)arg1 + 0x18) = temp_v1;
    if (temp_v1 != 0) {
        *(u8 *)((u8 *)temp_v1 + 0x16) = (u8) ((*(u8 *)((u8 *)temp_v1 + 0x16)) | 8);
    }
    *(void **)((u8 *)arg1 + 0x1C) = (void *) (*(void **)((u8 *)arg0 + 0x1C));
    *(void **)((u8 *)arg0 + 0x1C) = arg1;
}
/* localdecomp:end func_L39_005181D8 */

/* localdecomp:start func_L39_00518200 */
s32 func_L39_00518200(u8 *arg0, u8 *arg1) {
    unsigned long w = *(unsigned long *)(arg0 + 0x10);
    unsigned long mask = 0x9000;
    mask <<= 22;
    if (w & mask) {
        *(u8 **)(arg1 + 0x18) = arg0;
        *(u32 *)(arg1 + 0x1C) = *(u32 *)(arg0 + 0x20);
        *(u8 **)(arg0 + 0x20) = arg1;
        arg0[0x16] |= 8;
        return 0;
    }
    return 4;
}
/* localdecomp:end func_L39_00518200 */
