#include "common.h"

/* localdecomp:start func_L04_004B3440 */
extern void func_0038CC88(void *, s32, s32);

/* from rac2-decomp's func_L06_0039A2F0, renamed */
void func_L04_004B3440(s32 a0, s32 a1, s32 a2, s32 a3, s32 *list)
{
    char *shot;
    s32 count;
    s32 score;
    s32 tag = a3;
    s16 d;
    s16 fc = *(s16 *)(a2 + 0xB2);
    s16 fa = *(s16 *)(a2 + 0xAA);
    if (a3 == 1)
        d = (s16)(a0 - a2);
    else
        d = (s16)(a0 - *(u16 *)(a2 + 0x68));
    for (score = 0; score < list[0]; score++) {
        char *entry = (char *)list + 4 + score * 16;
        if (*(s32 *)entry != d) continue;
        if (*(u16 *)(entry + 8) != a1) continue;
        if (fc != *(s16 *)(entry + 0xC)) continue;
        if (fa != *(s16 *)(entry + 0xE)) continue;
        tag = *(s16 *)(entry + 0xA);
        if (tag != 0) {
            func_0038CC88(entry + 4, a0, a1);
            return;
        }
    }
    count = list[0];
    shot = (char *)list + 4 + count * 16;
    list[0] = count + 1;
    *(s32 *)shot = d;
    func_0038CC88(shot + 4, a0, a1);
    *(u16 *)(shot + 8) = a1;
    *(s16 *)(shot + 0xA) = tag;
    *(s16 *)(shot + 0xC) = fc;
    *(s16 *)(shot + 0xE) = fa;
}
/* localdecomp:end func_L04_004B3440 */
