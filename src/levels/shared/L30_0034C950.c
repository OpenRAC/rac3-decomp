#include "common.h"

LINKER_REMNANT("asm/levels", func_L30_0034C950);

INCLUDE_ASM("asm/levels", func_L30_0034C958);

/* localdecomp:start func_L30_0034C9F8 */
extern f32 func_0038DB48(f32 a);
extern f32 func_0038D160(f32 a, f32 b);

f32 func_L30_0034C9F8(f32 *v) {
    if (v[0] == 0.0f) {
        if (v[2] > 0.0f) {
            return func_0038DB48(1.5707964f);
        }
        return func_0038DB48(-1.5707964f);
    }
    return func_0038D160(v[0], v[2]);
}
/* localdecomp:end func_L30_0034C9F8 */

/* localdecomp:start func_L30_0034CA78 */
extern u8 D_00142731[];
s32 func_L30_0034CA78(void) {
    s32 v = D_00142731[0];
    s32 n = 0;
    while (v != 0) {
        n += v % 2;
        v >>= 1;
    }
    return n;
}
/* localdecomp:end func_L30_0034CA78 */
