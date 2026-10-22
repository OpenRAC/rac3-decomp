#include "common.h"

/* localdecomp:start func_L12_003CA478 */
void func_L12_003CA478(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        if (*(*(s32 **)((u8 *)arg0 + 0x68)) != 0) {
            *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 0x8000);
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 1);
    }
}
/* localdecomp:end func_L12_003CA478 */
