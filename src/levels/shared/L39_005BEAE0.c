#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005BEAE0);

/* localdecomp:start func_L39_005BEAF8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern int func_L39_005BEB98(void *, void *, Vec4 *);
extern int func_L39_005BEFB0(void *, void *, Vec4 *);

int func_L39_005BEAF8(void *a, void *b, Vec4 *out) {
    Vec4 tmp;
    int r;
    if (out != 0) {
        r = func_L39_005BEB98(a, b, &tmp);
        r &= func_L39_005BEFB0(a, &tmp, &tmp);
        *out = tmp;
        return r;
    }
    if (func_L39_005BEB98(a, b, 0) != 0) {
        int t = func_L39_005BEFB0(a, b, 0);
        if (t != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005BEAF8 */

INCLUDE_ASM("asm/levels", func_L39_005BEB98);

INCLUDE_ASM("asm/levels", func_L39_005BEFB0);

LINKER_REMNANT("asm/levels", func_L39_005BF280);
