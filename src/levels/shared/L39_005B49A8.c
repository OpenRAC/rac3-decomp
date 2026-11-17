#include "common.h"

/* localdecomp:start func_L39_005B49A8 */
typedef struct S_005B49A8 { u8 pad0[0x7F]; u8 x7F; u8 pad80[0x31]; u8 xB1; s16 xB2; } S_005B49A8;
extern S_005B49A8 *D_L39_0024C100_005B49A8[] __attribute__((section(".sdata")));
void func_L39_005B49A8(S_005B49A8 *p) {
    s32 i;

    if (p->xB2 >= 0 && !(p->xB1 & 0x80)) {
        p->x7F++;
        for (i = 1; i >= 0; i--) {
            if (p == D_L39_0024C100_005B49A8[i]) {
                break;
            }
        }
    }
}
/* localdecomp:end func_L39_005B49A8 */
