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

/* localdecomp:start func_L39_004C3F68 */
/* OpenSSL's SSL_CTX_ctrl; its sibling SSL_ctrl is func_L39_004C3E28 above */
typedef struct S_004C3F68 S_004C3F68;
typedef struct {
    char _p0[0x34];
    s64 (*f34)(S_004C3F68 *, s32, s64, s32);
} V_004C3F68;
typedef struct {
    char _p0[0x30];
    s64 f30;
} H_004C3F68;
struct S_004C3F68 {
    V_004C3F68 *f0;
    char _p4[0x8 - 0x4];
    s64 f8;
    char _p10[0x1C - 0x10];
    H_004C3F68 *f1C;
    s64 f20;
    char _p28[0x30 - 0x28];
    s32 f30;
    char _p34[0x4C - 0x34];
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    char _p7C[0xA4 - 0x7C];
    s32 fA4;
    char _pA8[0xE8 - 0xA8];
    s64 fE8;
    s64 fF0;
    char _pF8[0x114 - 0xF8];
    s32 f114;
    s32 f118;
};

s64 func_L39_004C3F68(S_004C3F68 *arg0, s32 arg1, s64 arg2, s32 arg3) {
    s64 ret;

    switch (arg1) {
    case 0x28:
        return arg0->fA4;
    case 0x29:
        ret = arg0->fA4;
        arg0->fA4 = arg2;
        return ret;
    case 0x2E:
        ret = 0;
        if (arg3 == 100 || arg3 == 101) {
            arg0->fE8 = arg2;
            ret = 1;
        }
        if (arg3 == 102 || arg3 == 100) {
            arg0->fF0 = arg2;
            ret = 1;
        }
        return ret;
    case 0x2F:
        ret = 0x19000;
        if (arg3 == 101) {
            if (arg0->fE8 != 0) {
                ret = arg0->fE8;
            }
        } else if (arg3 == 102) {
            if (arg0->fF0 != 0) {
                ret = arg0->fF0;
            }
        } else {
            ret = 0;
        }
        return ret;
    case 0x2A:
        ret = arg0->f20;
        arg0->f20 = arg2;
        return ret;
    case 0x2B:
        return arg0->f20;
    case 0x2C:
        ret = arg0->f30;
        arg0->f30 = arg2;
        return ret;
    case 0x2D:
        return arg0->f30;
    case 0x14:
        return arg0->f1C->f30;
    case 0x15:
        return arg0->f4C;
    case 0x16:
        return arg0->f54;
    case 0x17:
        return arg0->f50;
    case 0x18:
        return arg0->f58;
    case 0x19:
        return arg0->f60;
    case 0x1A:
        return arg0->f5C;
    case 0x1B:
        return arg0->f70;
    case 0x1C:
        return arg0->f74;
    case 0x1D:
        return arg0->f64;
    case 0x1E:
        return arg0->f68;
    case 0x1F:
        return arg0->f6C;
    case 0x20:
        return arg0->f8 |= arg2;
    case 0x33:
        return arg0->f114;
    case 0x32:
        ret = arg0->f114;
        arg0->f114 = arg2;
        return ret;
    case 0x36:
        return arg0->f118;
    case 0x35:
        ret = arg0->f118;
        arg0->f118 = arg2;
        return ret;
    case 0x37:
        return arg0->f78;
    default:
        return arg0->f0->f34(arg0, arg1, arg2, arg3);
    }
}
/* localdecomp:end func_L39_004C3F68 */

INCLUDE_ASM("asm/levels", func_L39_004C4128);

/* localdecomp:start func_L39_004C4168 */
typedef struct {
    char _p0[0x10];
    void *f10;
} S2_004C4168;
typedef struct {
    char _p0[0x60];
    void *f60;
    char _p64[0xDC - 0x64];
    S2_004C4168 *fDC;
} S_004C4168;

void *func_L39_004C4168(S_004C4168 *arg0) {
    if (arg0 != 0 && arg0->f60 != 0) {
        return arg0->f60;
    }
    return arg0->fDC != 0 ? arg0->fDC->f10 : 0;
}
/* localdecomp:end func_L39_004C4168 */
