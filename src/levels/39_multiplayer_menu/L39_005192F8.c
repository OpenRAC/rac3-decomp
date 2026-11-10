#include "common.h"

/* localdecomp:start func_L39_005192F8 */
extern s32 func_L39_005190E8(s32);
extern void func_L39_005190C8(void);
extern s32 D_L39_0046F55C[];
s32 *func_L39_005192F8(void) {
    s32 p = func_L39_005190E8(1);
    if (p == 0) {
        return D_L39_0046F55C;
    }
    func_L39_005190C8();
    return (s32 *)(p + 0xC);
}
/* localdecomp:end func_L39_005192F8 */

/* localdecomp:start func_L39_00519340 */
extern s32 func_L39_005190E8(s32);
extern void func_L39_005190C8(void);
extern s32 D_L39_0046F560[];
s32 *func_L39_00519340(void) {
    s32 p = func_L39_005190E8(1);
    if (p == 0) {
        return D_L39_0046F560;
    }
    func_L39_005190C8();
    return (s32 *)(p + 0x10);
}
/* localdecomp:end func_L39_00519340 */
