#include "common.h"

/* localdecomp:start func_L08_0038F5F8 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L08_0038F5F8(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L08_0038F5F8 */

INCLUDE_ASM("asm/levels", func_L08_0038F660);
