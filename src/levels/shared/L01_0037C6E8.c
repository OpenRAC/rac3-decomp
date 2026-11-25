#include "common.h"

/* localdecomp:start func_L01_0037C6E8 */
extern s32 D_L01_001E10D0[];

void func_L01_0037C6E8(s32 a0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == 0) {
            D_L01_001E10D0[i] = a0;
            return;
        }
    }
}
/* localdecomp:end func_L01_0037C6E8 */

/* localdecomp:start func_L01_0037C720 */
extern s32 D_L01_001E10D0[];
s32 func_L01_0037C720(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_0037C720 */

/* localdecomp:start func_L01_0037C758 */
extern int D_L01_001E10D0[];
int func_L01_0037C758(int a)
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
/* localdecomp:end func_L01_0037C758 */
