#include "common.h"

/* localdecomp:start func_L01_00521B40 */
extern s32 func_L01_00521C88_00521B40();

extern u8 D_L01_001DC2A8[];
void func_L01_00521B40(u8 *p, s32 f) { *(u8 **)p = D_L01_001DC2A8; if (f & 1) func_L01_00521C88_00521B40(p); }
/* localdecomp:end func_L01_00521B40 */
