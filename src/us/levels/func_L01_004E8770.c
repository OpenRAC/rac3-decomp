#include "common.h"

/* localdecomp:start func_L01_004E8770 */
extern u8 D_001A4BE0[];

void func_L01_004E8770(s32 item) {
    u8 *state;
    switch (item) {
    case 0x13:
    case 0x27:
    case 0x3F:
    case 0x97:
        state = D_001A4BE0;
        *(s16 *)(state + 0x287C) = 3;
        *(s16 *)(state + 0x1FC) = 0x46;
        break;
    }
}
/* localdecomp:end func_L01_004E8770 */
