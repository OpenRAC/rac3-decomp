#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005FE2E0);

INCLUDE_ASM("asm/levels", func_L39_005FE358);

INCLUDE_ASM("asm/levels", func_L39_005FE6A0);

INCLUDE_ASM("asm/levels", func_L39_005FED60);

/* localdecomp:start func_L39_005FF060 */
#include "vu0.h"

extern void func_L39_005FF198(void *, void *, f32 *);
extern void func_0038CE20(f32 *, void *, f32);

void func_L39_005FF060(void *a, void *b, f32 *v, f32 t) {
    f32 d[4];

    func_L39_005FF198(a, b, d);
    func_0038CE20(d, d, t);
    vec_sub_ab(v, v, d);
}
/* localdecomp:end func_L39_005FF060 */

INCLUDE_ASM("asm/levels", func_L39_005FF0B8);
