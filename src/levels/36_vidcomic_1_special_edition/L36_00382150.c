#include "common.h"

/* localdecomp:start func_L36_00382150 */
extern u32 D_L36_001E0BD0[4];

void func_L36_00382150(u32 a)
{
    u32 *p;
    s32 i;

    i = 0;
    p = D_L36_001E0BD0;
    for (; i < 4; i++, p++) {
        if (*p == 0) {
            *p = a;
            return;
        }
    }
}
/* localdecomp:end func_L36_00382150 */

/* localdecomp:start func_L36_00382188 */
extern u32 D_L36_001E0BD0[4];

s32 func_L36_00382188(void)
{
    u32 *p;
    s32 i;

    i = 0;
    p = D_L36_001E0BD0;
    for (; i < 4; i++, p++) {
        if (*p == 0)
            return 0;
    }
    return 1;
}
/* localdecomp:end func_L36_00382188 */

/* localdecomp:start func_L36_003821C0 */
extern int D_L01_001E10D0[];
int func_L36_003821C0(int a)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == a) {
            D_L01_001E10D0[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L36_003821C0 */
