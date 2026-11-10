#include "common.h"

/* localdecomp:start func_L39_00515F90 */
typedef struct S_00515F90 {
    s32 fn;
    s32 arg;
} S_00515F90;

s32 func_L39_00515F90(S_00515F90 *p) {
    s32 r = 0;

    if (p) {
        r = p->fn;
        r = ((s32 (*)(s32))r)(p->arg) != 0;
    }
    return r;
}
/* localdecomp:end func_L39_00515F90 */

/* localdecomp:start func_L39_00515FC0 */
void func_L39_0050A098(s32, s32, s32, s32);
void func_L39_00515FC0(void *arg0, s32 arg1) {
    func_L39_0050A098((s32) arg0, arg1, (*(s32 *)((u8 *)arg0 + 4)), 0);
}
/* localdecomp:end func_L39_00515FC0 */

/* localdecomp:start func_L39_00515FE0 */
void func_L39_00509EA0(s32, s32, s32, s32);

void func_L39_00515FE0(s32 arg0, s32 arg1, s32 arg2) {
    func_L39_00509EA0(arg0, arg1, arg2, 0x1D16);
}
/* localdecomp:end func_L39_00515FE0 */
