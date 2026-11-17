#include "common.h"

/* localdecomp:start func_L39_005D9710 */
extern u8 D_L39_0024362C;
extern s32 func_L39_006121B0();
void func_L39_005D9710(void) {
    D_L39_0024362C = 0;
    func_L39_006121B0(25);
}
/* localdecomp:end func_L39_005D9710 */

/* localdecomp:start func_L39_005D9730 */
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern void func_L39_005D7FF8();
extern void func_L39_005D9710(void);
extern void func_L39_005D8E18();
extern s32 D_L39_0024C288[2];
extern s32 D_L39_0024C2A0;

s32 func_L39_005D9730(s32 idx)
{
    s32 *list[1];

    if (D_L39_0024C2A0 == 0) {
        func_003E6FA0(D_L39_0024C288, (s32)func_L39_005D7FF8, (s32)func_L39_005D9710, (s32)func_L39_005D8E18, 0, 0);
        D_L39_0024C2A0 = 1;
    }
    list[0] = D_L39_0024C288;
    return (s32)list[idx];
}
/* localdecomp:end func_L39_005D9730 */
