#include "common.h"

/* localdecomp:start func_L40_00422A78 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00422A78(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_00422A78 */

/* localdecomp:start func_L40_00422AA0 */
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);
extern void func_L39_00662AA0(s32, s32 *, s32);

void func_L40_00422AA0(s32 a, s32 b) {
    s32 buf[4];
    s32 h = func_L39_0066DCC8(a, 1, 0, 250);
    buf[0] = b;
    func_L39_00662AA0(h, buf, 4);
}
/* localdecomp:end func_L40_00422AA0 */

/* localdecomp:start func_L40_00422AE8 */
s32 func_L40_00422AE8(s32 a0) {
    s32 r;

    r = -1;
    switch (a0) {
    case 0x1ABA: r = 5; break;
    case 0x1ABD: r = 2; break;
    case 0x1ABC: r = 3; break;
    case 0x1ABB: r = 4; break;
    case 0x1ABE: r = 7; break;
    case 0x1AC0: r = 9; break;
    case 0x1AC1: r = 6; break;
    case 0x1B09: r = 15; break;
    case 0x1ABF: case 0x1B0A:
        r = 12;
        break;
    }
    return r;
}
/* localdecomp:end func_L40_00422AE8 */

/* localdecomp:start func_L40_00422B60 */
s32 func_L40_00422B60(s32 a0) {
    switch (a0) {
    case 3: return 0x1096;
    case 2: return 0x1087;
    case 4: return 0x1089;
    case 5: return 0x108A;
    case 6: return 0x1098;
    case 9: return 0x10A7;
    case 7: return 0x10A4;
    case 8: break;
    }
    return -1;
}
/* localdecomp:end func_L40_00422B60 */

/* localdecomp:start func_L40_00422BC8 */
s32 func_L40_00422BC8(s32 index)
{
    switch (index) {
    case 3: return 0x1ABC;
    case 2: return 0x1ABD;
    case 4: return 0x1ABB;
    case 5: return 0x1ABA;
    case 6: return 0x1AC1;
    case 9: return 0x1AC0;
    case 7: return 0x1ABE;
    case 8: break;
    }
    return -1;
}
/* localdecomp:end func_L40_00422BC8 */

INCLUDE_ASM("asm/levels", func_L40_00422C30);

/* localdecomp:start func_L40_00422D58 */
extern s32 func_L40_00422AE8(s32);
extern void func_L39_00672118(s32);
void func_L40_00422D58(u8 *p) {
    func_L39_00672118(func_L40_00422AE8(*(s16 *)(p + 0xAA)));
}
/* localdecomp:end func_L40_00422D58 */

INCLUDE_ASM("asm/levels", func_L40_00422D80);

INCLUDE_ASM("asm/levels", func_L40_00423120);

INCLUDE_ASM("asm/levels", func_L40_00423310);

/* localdecomp:start func_L40_00423510 */
s32 func_L40_00423510(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg2 = 0;
    *arg1 = 0;
    return 0;
}
/* localdecomp:end func_L40_00423510 */
