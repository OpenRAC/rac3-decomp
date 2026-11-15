#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L19_00335470);

/* localdecomp:start func_L19_00335748 */
__asm__(".extern D_L19_001DCD24, 4");
extern f32 D_L19_001DCD24;
extern void func_0038CE20(void *, void *, f32);

void func_L19_00335748(u8 *obj, u8 *out) {
    func_0038CE20(out, obj + 0xC0, D_L19_001DCD24);
    vec_add_ba(out, out, obj + 0x10);
}
/* localdecomp:end func_L19_00335748 */
