#include "common.h"

/* localdecomp:start func_L39_004C6098 */
s32 func_L39_004C6098(s32 arg0) {
    switch (arg0) {
    case 1: return 0xCB;
    case 2: return 0xCA;
    case 4: return 0xC9;
    case 6: return 0xCC;
    }
    return 0xFD;
}
/* localdecomp:end func_L39_004C6098 */

INCLUDE_ASM("asm/levels", func_L39_004C6100);

INCLUDE_ASM("asm/levels", func_L39_004C6120);

INCLUDE_ASM("asm/levels", func_L39_004C6250);

INCLUDE_ASM("asm/levels", func_L39_004C6BA0);

INCLUDE_ASM("asm/levels", func_L39_004C6E08);

INCLUDE_ASM("asm/levels", func_L39_004C70F8);

INCLUDE_ASM("asm/levels", func_L39_004C74F8);

INCLUDE_ASM("asm/levels", func_L39_004C7CD0);

INCLUDE_ASM("asm/levels", func_L39_004C8088);

INCLUDE_ASM("asm/levels", func_L39_004C8110);

INCLUDE_ASM("asm/levels", func_L39_004C8568);

INCLUDE_ASM("asm/levels", func_L39_004C8748);

INCLUDE_ASM("asm/levels", func_L39_004C8950);

INCLUDE_ASM("asm/levels", func_L39_004C8C10);

INCLUDE_ASM("asm/levels", func_L39_004C8E30);

INCLUDE_ASM("asm/levels", func_L39_004C91C0);

INCLUDE_ASM("asm/levels", func_L39_004C9368);

INCLUDE_ASM("asm/levels", func_L39_004C9568);

INCLUDE_ASM("asm/levels", func_L39_004C9678);

INCLUDE_ASM("asm/levels", func_L39_004C9E08);

INCLUDE_ASM("asm/levels", func_L39_004C9F50);

INCLUDE_ASM("asm/levels", func_L39_004CA000);

INCLUDE_ASM("asm/levels", func_L39_004CA180);

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

INCLUDE_ASM("asm/levels", func_L39_004CA268);
