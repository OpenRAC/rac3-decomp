#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 D_L39_00443498[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BC4B0 */
extern s32 D_L39_00443498[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BC4B0(void *a) {
    if (D_L39_00443498[0] != 0) {
        ((void (*)(void *))D_L39_00443498[0])(a);
    } else {
        func_L39_004BC6C8(26, 136, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BC4B0 */

/* localdecomp:start func_L39_004BC4F8 */
/* the name of an X.520 attribute (2.5.4.n, DER 55 04 n): flag != 0 gives the short name, 0 the long one */
extern char D_L39_004751C0[];
extern char D_L39_004751D0[];
extern char D_L39_004751D8[];
extern char D_L39_004751E0[];
extern char D_L39_004751E8[];
extern char D_L39_004751F8[];
extern char D_L39_00475200[];
extern char D_L39_00475210[];
extern char D_L39_00475218[];
extern char D_L39_00475228[];
extern char D_L39_00475230[];
extern char D_L39_00475248[];
extern char D_L39_00475250[];
extern char D_L39_00475268[];
extern char D_L39_00475270[];
extern char D_L39_00475288[];
extern char D_L39_00475290[];
extern char D_L39_00475298[];
extern char D_L39_004752A0[];
extern char D_L39_004752B0[];
extern char D_L39_004752B8[];
extern char D_L39_004752C8[];
extern char D_L39_004752D0[];
extern char D_L39_004752E0[];
extern char D_L39_004752E8[];
extern char D_L39_00475300[];

char *func_L39_004BC4F8(u8 *p, s32 len, s32 flag) {
    if (len != 3) {
        return 0;
    }
    if (p[0] != 0x55 || p[1] != 4) {
        return 0;
    }
    switch (p[2]) {
    case 3:
        return flag == 0 ? D_L39_004751C0 : D_L39_004751D0;
    case 4:
        return flag == 0 ? D_L39_004751D8 : D_L39_004751E0;
    case 5:
        return flag == 0 ? D_L39_004751E8 : D_L39_004751F8;
    case 6:
        return flag == 0 ? D_L39_00475200 : D_L39_00475210;
    case 7:
        return flag == 0 ? D_L39_00475218 : D_L39_00475228;
    case 8:
        return flag == 0 ? D_L39_00475230 : D_L39_00475248;
    case 10:
        return flag == 0 ? D_L39_00475250 : D_L39_00475268;
    case 11:
        return flag == 0 ? D_L39_00475270 : D_L39_00475288;
    case 12:
        return flag == 0 ? D_L39_00475290 : D_L39_00475298;
    case 13:
        return flag == 0 ? D_L39_004752A0 : D_L39_004752B0;
    case 42:
        return flag == 0 ? D_L39_004752B8 : D_L39_004752C8;
    case 43:
        return flag == 0 ? D_L39_004752D0 : D_L39_004752E0;
    case 45:
        return flag == 0 ? D_L39_004752E8 : D_L39_00475300;
    }
    return 0;
}
/* localdecomp:end func_L39_004BC4F8 */

INCLUDE_ASM("asm/levels", func_L39_004BC6C8);

/* localdecomp:start func_L39_004BC880 */
s64 func_L39_004BC880(s64 *arg0) {
    return *arg0 * 13;
}
/* localdecomp:end func_L39_004BC880 */

/* localdecomp:start func_L39_004BC898 */
s32 func_L39_004BC898(s64 *arg0, s64 *arg1) {
    return *arg0 - *arg1;
}
/* localdecomp:end func_L39_004BC898 */

INCLUDE_ASM("asm/levels", func_L39_004BC8B0);
