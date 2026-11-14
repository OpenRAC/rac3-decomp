#include "common.h"

/* localdecomp:start func_L02_00428520 */
#include "vu0.h"
extern void func_0038D000(char *, char *, char *);
extern void func_0038CE20(void *, void *, float);

void func_L02_00428520(char *a0, char *a1, float f12, float f13, float f14) {
    *(float *)(a1 + 4) = f13;
    *(float *)(a1 + 8) = f14;
    *(float *)(a1 + 0) = f12;
    func_0038D000(a1, a1, a0 + 0xC0);
    func_0038CE20(a1, a1, *(float *)(a0 + 0x2C));
    vec_add_ba(a1, a1, a0 + 0x10);
}
/* localdecomp:end func_L02_00428520 */
