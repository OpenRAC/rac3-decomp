#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_00335408 */
extern f32 D_L19_001DCD10;
__asm__(".extern D_L19_001DCD10, 4");
extern void func_0038CE20(void *, void *, f32);

void func_L19_00335408(u8 *a0, void *a1) {
    func_0038CE20(a1, a0 + 0xC0, D_L19_001DCD10);
    vec_add_ba(a1, a1, a0 + 0x10);
}
/* localdecomp:end func_L19_00335408 */
