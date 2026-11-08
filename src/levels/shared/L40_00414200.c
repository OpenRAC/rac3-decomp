#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 w0; s32 w4; } S_414200;

/* localdecomp:start func_L40_00414200 */
extern u8 *D_L40_0024845C;
extern u8 *D_L40_00248500[];

void func_L40_00414200(u8 *obj, u128_t *out) {
    S_414200 *vars = *(S_414200 **)(obj + 0x68);
    if (vars->w4 == -1) {
        *out = *(u128_t *)(D_L40_00248500[0] + vars->w0 * 128 + 0x30);
    } else {
        *out = *(u128_t *)(D_L40_0024845C + vars->w4 * 256 + 0x10);
    }
    if (((f32 *)out)[2] < *(f32 *)(obj + 0x18)) {
        ((f32 *)out)[2] = *(f32 *)(obj + 0x18);
    }
}
/* localdecomp:end func_L40_00414200 */
