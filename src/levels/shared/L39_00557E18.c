#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_00557E18 */
extern s32 D_L39_0024B2A8;
s32 func_L39_00557E18(s32 a0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if ((&D_L39_0024B2A8)[i] == a0) return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00557E18 */
