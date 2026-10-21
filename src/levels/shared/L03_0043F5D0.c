#include "common.h"

/* localdecomp:start func_L03_0043F5D0 */
extern f32 func_0038D0B0(void *a0, void *a1);
extern void func_0038DBD8(void *a0, void *a1, f32 a2);
void func_L03_0043F5D0(void *a0, void *a1) {
    func_0038DBD8(a0, a1, func_0038D0B0(a0, a1) * 0.5f + 0.5f);
}
/* localdecomp:end func_L03_0043F5D0 */
