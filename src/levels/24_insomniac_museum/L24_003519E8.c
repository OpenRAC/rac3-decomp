#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003519E8);

/* localdecomp:start func_L24_00351FD8 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L24_001E8F58[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L24_00351FD8(u8 *obj) {
    f32 a[4];
    f32 b[4];
    u8 *s = *(u8 **)(obj + 0x68);

    *(u128_t *)a = *(u128_t *)(obj + 0x10);
    a[2] += 1.0f;
    *(u128_t *)b = *(u128_t *)(s + 0x220);
    if (func_003D3CB0(a, b, 0x10, obj, 0) == 0) {
        return 1;
    }
    if (D_L24_001E8F58[0] != 0) {
        if (D_L24_001E8F58[0] == *(s32 *)(s + 0x230)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L24_00351FD8 */

INCLUDE_ASM("asm/levels", func_L24_00352060);

INCLUDE_ASM("asm/levels", func_L24_00354948);

INCLUDE_ASM("asm/levels", func_L24_00354F38);
