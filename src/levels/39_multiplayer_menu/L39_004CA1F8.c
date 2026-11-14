#include "common.h"

/* localdecomp:start func_L39_004CA1F8 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* from rac4-decomp's func_L00_00505FF8, renamed */
s32 func_L39_004CA1F8(void) {
    func_L39_004BC6C8(0x10, 0x6D, 0xE, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004CA1F8 */

/* localdecomp:start func_L39_004CA228 */
extern s32 func_L39_004CA268(s32);
extern s32 *func_L01_003E4008(s32);

/* from rac4-decomp's func_L00_00506028 */
s32 func_L39_004CA228(s32 arg0) {
    s32 c = (u32)(arg0 + 1) < 2U;
    s32 r;
    if (c) {
        r = func_L39_004CA268(*func_L01_003E4008(c));
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_004CA228 */

/* localdecomp:start func_L39_004CA268 */
s32 func_L39_004CA268(s32 arg0) {
    switch (arg0) {
    case 4:
    case 11:
    case 0x47:
    case 0x77:
    case 0x78:
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004CA268 */

INCLUDE_ASM("asm/levels", func_L39_004CA2C0);

/* localdecomp:start func_L39_004CA2E8 */
typedef struct { u8 pad[8]; unsigned long key; } S_004CA2E8;

s32 func_L39_004CA2E8(S_004CA2E8 **a, S_004CA2E8 **b) {
    unsigned long mask = 0xFFFFFF;
    unsigned long x = (*a)->key;
    unsigned long y = (*b)->key;
    x &= mask;
    y &= mask;
    if (x == y) {
        return 0;
    }
    return (y < x) ? 1 : -1;
}
/* localdecomp:end func_L39_004CA2E8 */
