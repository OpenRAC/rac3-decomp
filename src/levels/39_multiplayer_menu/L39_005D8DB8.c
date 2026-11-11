#include "common.h"

/* localdecomp:start func_L39_005D8DB8 */
__asm__(".extern D_L39_00241120, 16");
extern u8 D_001D7F1C_sda;
extern s32 *D_L39_00241120;
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);

s32 func_L39_005D8DB8(void) {
    if (D_001D7F1C_sda != 0) {
        func_003E82F8(*D_L39_00241120 < 2 ? 0 : 4);
        func_L01_00516AA0(0x70000, 1, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_005D8DB8 */
