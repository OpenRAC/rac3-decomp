#include "common.h"

/* localdecomp:start func_L39_004C3E28 */
typedef struct S_004C3E28 S_004C3E28;
typedef struct {
    char _p0[0x30];
    s64 (*f30)(S_004C3E28 *, s32, s64, s32);
} V_004C3E28;
struct S_004C3E28 {
    char _p0[0x8];
    V_004C3E28 *f8;
    char _pC[0x58 - 0xC];
    s32 f58;
    char _p5C[0xE0 - 0x5C];
    s32 fE0;
    char _pE4[0xFC - 0xE4];
    s32 fFC;
    s64 f100;
    char _p108[0x110 - 0x108];
    s32 f110;
    s32 f114;
    s64 f118;
    s64 f120;
};

s64 func_L39_004C3E28(S_004C3E28 *arg0, s32 arg1, s64 arg2, s32 arg3) {
    s64 ret;

    switch (arg1) {
    case 0x28:
        return arg0->f58;
    case 0x29:
        ret = arg0->f58;
        arg0->f58 = arg2;
        return ret;
    case 0x2E:
        ret = 0;
        if (arg3 == 100 || arg3 == 101) {
            arg0->f118 = arg2;
            ret = 1;
        }
        if (arg3 == 102 || arg3 == 100) {
            arg0->f120 = arg2;
            ret = 1;
        }
        return ret;
    case 0x2F:
        ret = 0x19000;
        if (arg3 == 101) {
            if (arg0->f118 != 0) {
                ret = arg0->f118;
            }
        } else if (arg3 == 102) {
            if (arg0->f120 != 0) {
                ret = arg0->f120;
            }
        } else {
            ret = 0;
        }
        return ret;
    case 0x20:
        return arg0->f100 |= arg2;
    case 0x33:
        return arg0->f110;
    case 0x32:
        ret = arg0->f110;
        arg0->f110 = arg2;
        return ret;
    case 0x36:
        return arg0->f114;
    case 0x35:
        ret = arg0->f114;
        arg0->f114 = arg2;
        return ret;
    case 0x34:
        ret = arg0->fE0;
        arg0->fE0 = arg2;
        return ret;
    case 0x37:
        return arg0->fFC;
    default:
        return arg0->f8->f30(arg0, arg1, arg2, arg3);
    }
}
/* localdecomp:end func_L39_004C3E28 */

INCLUDE_ASM("asm/levels", func_L39_004C3F68);

INCLUDE_ASM("asm/levels", func_L39_004C4128);

INCLUDE_ASM("asm/levels", func_L39_004C4168);
