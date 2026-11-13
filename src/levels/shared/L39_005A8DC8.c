#include "common.h"

/* localdecomp:start func_L39_005A8DC8 */
extern s32 D_L39_00242A50;
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00242A50, 16");
__asm__(".extern D_L39_00241120, 16");
extern void func_L01_004D2470(void *, s32);

void func_L39_005A8DC8(void) {
    s32 i;
    if (D_L39_00242A50 != 0) {
        for (i = 0; i < *D_L39_00241120; i++) {
            func_L01_004D2470((void *)(D_L39_00242A50 + 0x1FCA8), i);
        }
    }
}
/* localdecomp:end func_L39_005A8DC8 */
