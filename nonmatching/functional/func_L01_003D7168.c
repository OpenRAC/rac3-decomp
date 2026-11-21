/* exact: byte-identical per tools/check.py at level 01. */
#include "common.h"
/* localdecomp:start func_L01_003D7168 */
extern s32 D_L01_001D545C;
void func_L01_003D7168(s32 *kind, u32 *first, u32 *second, s32 *flag) {
    switch (*kind) {
    case 0:
        *first = 0x325C66;
        *second = 0x4C6C74;
        break;
    case 1:
        *first = 0x325C66;
        *second = 0x4C6C74;
        *flag = 0;
        break;
    case 2:
        *first = 0x325C66;
        *second = 0x4C6C74;
        *flag = 1;
        break;
    case 3:
        if (D_L01_001D545C == 41 || D_L01_001D545C == 51 || D_L01_001D545C == 48) {
            *first = 0xF0EBEE;
            *second = 0xF0EBEE;
        } else {
            *first = 0x5786AE;
            *second = 0x2E475C;
        }
        *flag = 0;
        break;
    case 4:
        if (D_L01_001D545C == 41 || D_L01_001D545C == 51 || D_L01_001D545C == 48) {
            *first = 0x312B2A;
            *second = 0x312B2A;
        } else {
            *first = 0x15212B;
            *second = 0x192834;
        }
        *flag = 0;
        break;
    }
}
/* localdecomp:end func_L01_003D7168 */
