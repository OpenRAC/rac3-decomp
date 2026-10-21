#include "common.h"

/* localdecomp:start func_L40_004279D8 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_004279D8(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_004279D8 */

/* localdecomp:start func_L40_00427A00 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00427A00(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_00427A00 */

/* localdecomp:start func_L40_00427A28 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00427A28(s32 a0) {
    return func_L39_0066DD30(a0, 2, 0) != 0;
}
/* localdecomp:end func_L40_00427A28 */

/* localdecomp:start func_L40_00427A50 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L40_00427A50(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L40_00427A50 */
