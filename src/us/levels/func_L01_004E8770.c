#include "common.h"

/* localdecomp:start func_L01_004E8770 */
extern u8 D_001A4BE0[];

/* For item ids 0x13, 0x27, 0x3F and 0x97 only, sets two fields in the hero state (0x287C to 3 and
 * 0x1FC to 0x46); does nothing for other items. */
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
