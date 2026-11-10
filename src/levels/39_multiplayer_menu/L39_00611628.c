#include "common.h"

/* localdecomp:start func_L39_00611628 */
extern void func_L01_00516EC8(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);

/* from rac4-decomp's func_L00_0069D2F0, renamed */
void func_L39_00611628(s32 arg0, s32 *arg1) {
    func_L01_00516EC8(arg0, arg1, arg1 + 1, arg1 + 2, arg1 + 3);
}
/* localdecomp:end func_L39_00611628 */
