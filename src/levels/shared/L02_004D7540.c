#include "common.h"

/* localdecomp:start func_L02_004D7540 */
extern u8 D_001A71C4[];
extern void func_L02_004D36C0(s32, s32);
void func_L02_004D7540(s32 a0) {
    s32 m = 1;
    if (a0 != 0) {
        m = 2;
    }
    switch (D_001A71C4[0]) {
    case 0:
        func_L02_004D36C0(0, m);
        break;
    case 3:
        func_L02_004D36C0(81, m);
        break;
    }
}
/* localdecomp:end func_L02_004D7540 */
