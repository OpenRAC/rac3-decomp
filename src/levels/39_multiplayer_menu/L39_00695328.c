#include "common.h"

/* localdecomp:start func_L39_00695328 */
extern void *D_0024D760[];
extern void *D_001DC204_sda;

s32 func_L39_00695328(void)
{
    u8 *temp_v1;
    s32 ret;

    temp_v1 = (u8 *)D_0024D760[0];
    temp_v1 = *(u8 **)(temp_v1 + 0x38);
    ret = 0;
    if (temp_v1[0x34] == 0) {
        if (*(s32 *)temp_v1 == -1) {
            *(s32 *)((u8 *)D_001DC204_sda + 0x284) = 8;
            ret = 1;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_00695328 */
