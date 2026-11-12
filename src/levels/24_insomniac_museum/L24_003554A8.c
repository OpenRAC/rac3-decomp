#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003554A8);

/* localdecomp:start func_L24_003556A8 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

s32 func_L24_003556A8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v[4];
    f32 w[4];
    f32 h;

    *(u128_t *)v = *(u128_t *)(obj + 0x10);
    w[0] = func_0038D098(*(f32 *)(obj + 0xF8));
    w[1] = func_0038D0B0(*(f32 *)(obj + 0xF8));
    w[2] = 0.0f;
    vec_add_ab(v, v, w);
    h = func_003C3D30(v, 0, 0, 0.5f);
    if (h < *(f32 *)(obj + 0x18)) {
        if (*(f32 *)(s + 0x7C) < fabs_asm(h - *(f32 *)(obj + 0x18))) {
            w[0] = func_0038D098(*(f32 *)(obj + 0xF8)) * 7.5f;
            w[1] = func_0038D0B0(*(f32 *)(obj + 0xF8)) * 7.5f;
            w[2] = 0.0f;
            vec_add_ab(v, obj + 0x10, w);
            h = func_003C3D30(v, 0, 0, 1.0f);
            if (*(f32 *)(obj + 0x18) - 5.0f < h) {
                *(f32 *)(s + 0x308) = h;
                return 1;
            }
            return 2;
        }
    }
    return 0;
}
/* localdecomp:end func_L24_003556A8 */
