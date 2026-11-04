#include "common.h"

/* localdecomp:start func_L01_0045F1E8 */
extern u8 D_L01_001CCFD0[];

void func_L01_0045F1E8(s32 a0, s32 a1)
{
    u8 *b = D_L01_001CCFD0;

    if (*(s16 *)(b + 0x48) == a0 && *(s16 *)(b + 0x3C) == -1)
        return;
    if (a0 != -1)
        a0 &= 0xFF;
    if (a1 != -1)
        a0 &= 0xFF;
    if (*(s16 *)(b + 0x4E) == 0 && *(s16 *)(b + 0xC6) == 0) {
        *(s16 *)(b + 0x48) = a0;
        return;
    }
    {
        u8 *c = D_L01_001CCFD0;

        *(s16 *)(c + 0x3C) = a0;
        *(s16 *)(c + 0x3E) = a1;
    }
}
/* localdecomp:end func_L01_0045F1E8 */
