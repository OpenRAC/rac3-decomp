#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00450F00 */
extern void func_0038D000(void *, void *, void *);

void func_L01_00450F00(u8 *self, vu0_v4 *vec) {
    func_0038D000(vec, *(u8 **)(self + 0x68) + 0x20, self + 0xC0);
    vec_add_ba(vec, vec, self + 0x10);
}
/* localdecomp:end func_L01_00450F00 */

LINKER_REMNANT("asm/levels", func_L01_00450F50);
