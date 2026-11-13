#include "common.h"

/* NTSC-U counterpart of func_L39_00662B68 (src/levels/shared/L39_00662678.c) */
/* localdecomp:start func_L39_00660290 */
typedef struct {
    u32 f0;
    u32 f4;
    char p8[0x44];
    u32 f4C;
} S_662B68_A;
typedef struct {
    u8 pad[0x128];
    u32 tick;
} S_662B68_P;
extern S_662B68_P D_001A5E50;

/* from rac4-decomp's func_0053CB70 */
void func_L39_00660290(S_662B68_A *a, s32 b, s32 c)
{
    u32 p = D_001A5E50.tick;
    a->f4 = p;
    if (c > 0)
        a->f0 = (a->f0 & 0x1fff) |
                ((D_001A5E50.tick + b + c - p) << 13);
    else
        a->f0 &= 0x1fff;
    a->f4C = D_001A5E50.tick + b;
}
/* localdecomp:end func_L39_00660290 */
