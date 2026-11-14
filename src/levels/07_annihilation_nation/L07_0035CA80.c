#include "common.h"

/* localdecomp:start func_L07_0035CA80 */
extern s32 D_001E0F90;

void func_L07_0035CA80(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((&D_001E0F90)[i] == arg0) {
            (&D_001E0F90)[i] = 0;
            return;
        }
    }
}
/* localdecomp:end func_L07_0035CA80 */

INCLUDE_ASM("asm/levels", func_L07_0035CAB8);

INCLUDE_ASM("asm/levels", func_L07_0035CC10);

/* localdecomp:start func_L07_0035D080 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L07_001E8C18[4];
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

void func_L07_0035D080(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];

    *(u128_t *)v = *(u128_t *)(a0 + 0x10);
    v[2] = v[2] + 0.1f;
    *(u128_t *)w = *(u128_t *)(s + 0x190);
    v[2] = v[2] + *(f32 *)(s + 0x38);
    w[2] = w[2] + *(f32 *)(s + 0x38);
    if (func_003D3CB0(v, w, 0x10, a0, 0) != 0) {
        if (D_L07_001E8C18[0] == 0) {
            return;
        }
        if (D_L07_001E8C18[0] != *(s32 *)(s + 0x1D0)) {
            return;
        }
    }
    *(u128_t *)(s + 0x180) = *(u128_t *)(s + 0x190);
    *(u128_t *)(s + 0x1A0) = *(u128_t *)(s + 0x190);
}
/* localdecomp:end func_L07_0035D080 */
