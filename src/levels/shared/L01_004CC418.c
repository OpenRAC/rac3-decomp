#include "common.h"

/* localdecomp:start func_L01_004CC418 */
extern s32 func_L01_00521C88_004CC418();

extern u8 D_L01_001DB198[];
void func_L01_004CC418(u8 *p, s32 f) { *(u8 **)p = D_L01_001DB198; if (f & 1) func_L01_00521C88_004CC418(p); }
/* localdecomp:end func_L01_004CC418 */
