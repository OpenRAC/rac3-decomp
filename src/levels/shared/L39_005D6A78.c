#include "common.h"

/* localdecomp:start func_L39_005D6A78 */
typedef struct { s32 w0; s32 w4; s32 w8; u8 pad[0x10]; } E_5D4508;
extern E_5D4508 D_L39_004840A0[];
extern u8 *func_L39_0061BF38(s32);
void func_L39_005D6A78(s32 a, s32 b) {
    s32 i = *(s32 *)(func_L39_0061BF38(a) + 9540);
    D_L39_004840A0[i].w0 = 5;
    D_L39_004840A0[i].w8 = b;
}
/* localdecomp:end func_L39_005D6A78 */
