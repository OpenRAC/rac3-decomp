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

INCLUDE_ASM("asm/levels", func_L39_004CA3D0);
