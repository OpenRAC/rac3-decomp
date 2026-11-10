#include "common.h"

/* localdecomp:start func_L39_00505048 */
s32 func_L39_00505048(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x34));
}
/* localdecomp:end func_L39_00505048 */

/* localdecomp:start func_L39_00505050 */
extern s32 func_L39_00505050();

s32 func_L39_00505050(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_L39_00505050 */

/* localdecomp:start func_L39_00505058 */
extern s32 func_L39_00505058();

s32 func_L39_00505058(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_L39_00505058 */

/* localdecomp:start func_L39_00505060 */
extern s32 func_L39_00505060();

s32 func_L39_00505060(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_L39_00505060 */

INCLUDE_ASM("asm/levels", func_L39_00505068);

/* localdecomp:start func_L39_00505120 */
extern s32 func_L39_0050C260(s32 *, s32);
extern void func_11D380(s32, s32, s32);

s32 func_L39_00505120(s32 *self, s32 *src)
{
    if (!func_L39_0050C260(self, src[0])) {
        return 0;
    }
    self[1] = src[1];
    if (src[3]) {
        func_11D380(self[3], src[3], src[2]);
    }
    return 1;
}
/* localdecomp:end func_L39_00505120 */
