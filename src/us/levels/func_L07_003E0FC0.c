#include "common.h"

/* localdecomp:start func_L07_003E0FC0 */
typedef int u128_t __attribute__((mode(TI)));

extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern void func_L07_003E16E8(u8 *);
extern s32 D_L07_001E18B8;

void func_L07_003E0FC0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *p;
    s32 t;

    *(u128_t *)(s + 0x230) = *(u128_t *)(a0 + 0x10);
    *(u128_t *)(s + 0x240) = *(u128_t *)(a0 + 0xF0);
    *(u128_t *)(s + 0x220) = *(u128_t *)(a0 + 0x10);
    *(f32 *)(s + 0x270) = func_0037E2A8();
    *(f32 *)(s + 0x278) = func_0037E250(0.03490659f, 0.06981318f);
    *(f32 *)(s + 0x27C) = func_0037E250(0.35f, 0.65f);
    p = s + 0x30;
    t = *(s32 *)(p + 0x38);
    D_L07_001E18B8 = 0;
    *(f32 *)(p + 0x20) = 0.0013888889f;
    *(f32 *)(p + 0x28) = 0.16666667f;
    *(s32 *)(p + 0x38) = t | 0x414;
    *(f32 *)(p + 0x24) = 0.0013888889f;
    *(f32 *)(p + 0x1C) = 0.104719765f;
    *(f32 *)(p + 0x14) = 0.0017453294f;
    *(f32 *)(p + 0x18) = 0.0017453294f;
    *(f32 *)(s + 0x30) = 2.2f;
    *(f32 *)(p + 4) = -2.2f;
    func_L07_003E16E8(a0);
}
/* localdecomp:end func_L07_003E0FC0 */
