#include "common.h"

/* localdecomp:start func_L39_004B9160 */
extern s32 func_L39_004C3D20(void *, u8 *, s32);
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);

s32 func_L39_004B9160(void *arg0, u8 *arg1, s32 arg2) {
    s32 n;
    s32 r;

    for (n = arg2; n > 0; n -= r, arg1 += r) {
        r = func_L39_004C3D20(arg0, arg1, n);
        if (r < 0) {
            if (*func_L01_003E4008() == 0x71) {
                return func_L39_004B95C0(*func_L01_003E4008());
            }
            return -0x262;
        }
        if (r == 0) {
            break;
        }
    }
    return arg2 - n;
}
/* localdecomp:end func_L39_004B9160 */

INCLUDE_ASM("asm/levels", func_L39_004B9218);

/* localdecomp:start func_L39_004B92B8 */
extern s32 func_L39_004B80D8(void);
extern s32 func_L39_004B8150(void);
extern s32 func_L39_004B9218(s32, u8 *, s32);
extern s32 D_L39_00464788;
extern void *D_L39_00464790;
extern s32 D_L39_00464774;

s32 func_L39_004B92B8(u8 *buf, s32 len) {
    s32 lock;
    s32 r;

    lock = func_L39_004B80D8();
    if (D_L39_00464788 != 0) {
        r = func_L39_004B9160(D_L39_00464790, buf, len);
    } else {
        r = func_L39_004B9218(D_L39_00464774, buf, len);
    }
    if (lock >= 0) {
        func_L39_004B8150();
    }
    return r;
}
/* localdecomp:end func_L39_004B92B8 */

INCLUDE_ASM("asm/levels", func_L39_004B9350);

/* localdecomp:start func_L39_004B93F8 */
typedef struct S_004B93F8 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ void *f10;
} S_004B93F8;

extern s32 D_L39_00464788;
extern S_004B93F8 D_L39_004646F8[];
extern void *D_L39_0046478C;
extern s32 D_L39_0046477C;
extern s32 D_L39_00464780;
extern char D_L39_00442C50[];
extern void func_L39_004BBE28(void *);
extern void func_L39_004C46A8(void *);
extern void func_L39_004C33C8(void);
extern void func_L01_004126A8(s32);
extern void func_00126270(s32);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004B93F8(void) {
    u32 i;
    u32 j;
    char *p;

    if (D_L39_00464788 != 0) {
        for (i = 0; i < 6; i++) {
            if (D_L39_004646F8[i].f10 != 0) {
                func_L39_004BBE28(D_L39_004646F8[i].f10);
                D_L39_004646F8[i].f10 = 0;
            }
        }
        if (D_L39_0046478C != 0) {
            func_L39_004C46A8(D_L39_0046478C);
            D_L39_0046478C = 0;
        }
        func_L39_004C33C8();
    }
    func_L01_004126A8(D_L39_0046477C);
    D_L39_0046477C = -1;
    func_00126270(D_L39_00464780);
    D_L39_00464780 = -1;
    p = D_L39_00442C50;
    for (j = 0; j < 0x200; j++) {
        p[j] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_004B93F8 */

/* localdecomp:start func_L39_004B9570 */
extern s32 D_L39_00464774;
extern s32 D_L39_0046477C;
extern s32 D_L39_00464780;
extern s32 func_001262B0(s32);
extern void func_L01_0033D298(void *);
extern s32 func_L39_00518830(void);

s32 func_L39_004B9570(void) {
    s32 ret;

    if (func_001262B0(D_L39_00464780) < 0) {
        ret = ((s32 (*)(s32))func_L01_0033D298)(D_L39_00464774);
    } else {
        ret = ((s32 (*)(s32))func_L39_00518830)(D_L39_0046477C);
    }
    return ret;
}
/* localdecomp:end func_L39_004B9570 */

/* localdecomp:start func_L39_004B95C0 */
s32 func_L39_004B95C0(s32 id) {
    switch (id) {
    case 116: return -0x269;
    case 4:
    case 113: return -0x259;
    case 12: return -0x26D;
    case 22:
    case 125: return -0x270;
    case 127: return -0x268;
    case 110:
    case 128: return -0x26C;
    case 111: return -0x26A;
    case 104: return -0x272;
    case 118: return -0x26B;
    case 16:
    case 115: return -0x271;
    }
    return -0x271;
}
/* localdecomp:end func_L39_004B95C0 */

/* localdecomp:start func_L39_004B9640 */
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);

s32 func_L39_004B9640(s32 err) {
    s32 ret;

    switch (err) {
    case -1:
        ret = func_L39_004B95C0(*func_L01_003E4008());
        if (ret == -0x271) {
            ret = -0x267;
        }
        break;
    case 1:
        ret = -0x263;
        break;
    case 2:
        ret = -0x264;
        break;
    case 3:
        ret = -0x265;
        break;
    case 4:
        ret = -0x266;
        break;
    default:
        ret = -0x267;
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004B9640 */

/* localdecomp:start func_L39_004B96D0 */
extern s32 D_L39_00464770;
extern char D_L39_00442C50[];
extern u16 D_L39_00442E50;
extern void *func_001206F4(void *, void *);

s32 func_L39_004B96D0(char *name, u16 port) {
    D_L39_00464770 = 1;
    func_001206F4(D_L39_00442C50, name);
    D_L39_00442E50 = port;
    return 0;
}
/* localdecomp:end func_L39_004B96D0 */

INCLUDE_ASM("asm/levels", func_L39_004B9720);

/* localdecomp:start func_L39_004B9C78 */
extern s32 D_L39_00464788;
s32 func_L39_004B9C78(s32 arg0) {
    D_L39_00464788 = arg0;
    return 0;
}
/* localdecomp:end func_L39_004B9C78 */

INCLUDE_ASM("asm/levels", func_L39_004B9C88);

INCLUDE_ASM("asm/levels", func_L39_004BA208);

INCLUDE_ASM("asm/levels", func_L39_004BA760);

INCLUDE_ASM("asm/levels", func_L39_004BAA78);

INCLUDE_ASM("asm/levels", func_L39_004BB1E8);

/* localdecomp:start func_L39_004BB368 */
extern s32 D_L39_00464798[];
extern s32 D_L39_00464794[];

s32 func_L39_004BB368(void) {
    s32 i;
    s32 n;

    n = D_L39_00464798[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
    n = D_L39_00464794[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
}
/* localdecomp:end func_L39_004BB368 */
