#include "common.h"

/* localdecomp:start func_L11_003C36A8 */
extern u8 D_L11_001E1780[];

void func_L11_003C36A8(s32 idx, f32 x, f32 y)
{
    char *st = (char *)D_L11_001E1780 + idx * 0x460;
    char *p;

    if (*(s16 *)(*(char **)(st + 0x50) + 0x86) != 0)
        return;
    p = *(char **)(*(char **)(st + 0x50) + 0x70) + 0x60;
    if (x != 0.0f)
        *(f32 *)(p + 0x104) = x;
    if (y != 0.0f)
        *(f32 *)(p + 0x108) = y;
}
/* localdecomp:end func_L11_003C36A8 */
