#include "common.h"

/* localdecomp:start func_L39_005193C0 */
extern void func_0011D534(void *, s32, s32);
extern s32 func_L39_00518A38(s32);
void func_L39_005193C0(s32 *arg0, s32 *arg1) {
    func_0011D534(arg0, 0, 0x10);
    arg0[1] = func_L39_00518A38(arg1[0]);
}
/* localdecomp:end func_L39_005193C0 */

/* localdecomp:start func_L39_00519408 */
typedef struct S_00519408 { char _p0[4]; s32 f4; } S_00519408;
extern s32 func_L39_00518A38(s32);
void func_L39_00519408(s32 *arg0, S_00519408 *arg1) {
    *arg0 = func_L39_00518A38(arg1->f4);
}
/* localdecomp:end func_L39_00519408 */
