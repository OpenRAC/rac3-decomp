#include "common.h"

/* localdecomp:start func_L01_0051F7C0 */
extern s32 func_L01_00521C88_0051F7C0();
extern char D_L01_001DC0C0[];

void func_L01_0051F7C0(u8 *p, s32 f) { *(u8 **)(p + 8) = D_L01_001DC0C0; if (f & 1) func_L01_00521C88_0051F7C0(p); }
/* localdecomp:end func_L01_0051F7C0 */

INCLUDE_ASM("asm/levels", func_L01_0051F7F0);
