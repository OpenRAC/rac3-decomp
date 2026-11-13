#include "common.h"

/* localdecomp:start func_L39_004CA328 */
extern void func_L39_004DEB50(s32);
extern void func_L01_00353880(s32);
extern s32 D_L39_004656F8 __attribute__((section(".data")));
extern s32 D_L39_00465108[];
extern s32 D_L39_00465128[];
extern char D_L39_00475D90[];
extern char D_L39_00475D98[];
extern char D_L39_00475D08[];
extern char D_L39_00475DA8[];
extern char D_L39_00475DB0[];
extern char D_L39_00475CE0[];
extern char D_L39_00475CD8[];

void func_L39_004CA328(void) {
    D_L39_004656F8 = 0;
    D_L39_00465108[0] = ((s32 (*)(char *))func_L39_004DEB50)(D_L39_00475D90);
    D_L39_00465108[1] = ((s32 (*)(char *))func_L39_004DEB50)(D_L39_00475D98);
    D_L39_00465108[2] = ((s32 (*)(char *))func_L39_004DEB50)(D_L39_00475D08);
    D_L39_00465108[3] = ((s32 (*)(char *))func_L39_004DEB50)(D_L39_00475DA8);
    D_L39_00465108[4] = ((s32 (*)(char *))func_L39_004DEB50)(D_L39_00475DB0);
    D_L39_00465128[0] = ((s32 (*)(char *))func_L01_00353880)(D_L39_00475CE0);
    D_L39_00465128[1] = ((s32 (*)(char *))func_L01_00353880)(D_L39_00475CD8);
}
/* localdecomp:end func_L39_004CA328 */

/* localdecomp:start func_L39_004CA3D0 */
typedef struct {
    char _p0[0x10];
    unsigned long f10;
} S_004CA3D0;

extern s32 func_L39_004DDEE0(void);

s32 func_L39_004CA3D0(S_004CA3D0 *a, s32 *out0, s32 *out1) {
    s32 i;

    if (a == 0) return 0;

    switch (a->f10 & 0x1FC00) {
    case 0x400: i = 0; break;
    case 0x800: i = 1; break;
    case 0x1000: i = 2; break;
    case 0x2000: i = 3; break;
    case 0x4000: i = 4; break;
    case 0x10000: i = 6; break;
    default: i = -1; break;
    }
    if (i < 0 || i >= 8) {
        *out0 = 0;
    } else if (i == 6) {
        *out0 = func_L39_004DDEE0();
    } else {
        *out0 = D_L39_00465108[i];
    }

    switch (a->f10 & 0x60000) {
    case 0x20000: i = 0; break;
    case 0x40000: i = 1; break;
    default: i = -1; break;
    }
    if (i < 0 || i >= 3) {
        *out1 = 0;
    } else {
        *out1 = D_L39_00465128[i];
    }

    if (*out0 != 0 && *out1 != 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004CA3D0 */
