#include "common.h"

/* localdecomp:start func_L04_003CFC98 */
void func_L01_004450F0(s32, s32, s32);
void func_L04_003CE760(void *, s32, s32, s32);

void func_L04_003CFC98(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2F4) = 0;
    func_L01_004450F0((s32) arg0, 0xD, 3);
    func_L04_003CE760(arg0, 1, 0, 1);
    func_L04_003CE760(arg0, 0, 0, 1);
}
/* localdecomp:end func_L04_003CFC98 */

/* localdecomp:start func_L04_003CFCF8 */
s32 func_00382498(s32, s32);
f32 func_003824E0(f32, f32);
f32 func_0038DAB8(f32, f32);

void func_L04_003CFCF8(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 *s2 = *(u8 **)((u8 *)arg0 + 0x68);

    *(s32 *)(s2 + 0x2F4) = func_00382498(1, 6);
    *(f32 *)(s2 + 0x310) = arg3;
    *(f32 *)(s2 + 0x314) = func_0038DAB8(arg1, func_003824E0(-0.008726646192371845f, 0.008726646192371845f));
    *(f32 *)(s2 + 0x318) = func_0038DAB8(arg1, arg2);
    *(f32 *)(s2 + 0x31C) = func_003824E0(4.0f, 6.0f);
}
/* localdecomp:end func_L04_003CFCF8 */

/* localdecomp:start func_L04_003CFDA8 */
typedef int u128_t __attribute__((mode(TI)));

void func_L04_003CFDA8(u8 *a0, u8 *a1) {
    *(u128_t *)(*(u8 **)(a0 + 0x68) + 0x2D0) = *(u128_t *)a1;
}
/* localdecomp:end func_L04_003CFDA8 */

/* localdecomp:start func_L04_003CFDB8 */
void func_L04_003CFDB8(u8 *a0, u8 *a1) {
    u8 *t = *(u8 **)(a0 + 0x68);
    u8 *s = *(u8 **)(a1 + 0x68);
    *(s32 *)(t + 0x2E0) = *(s32 *)s;
    if (*(f32 *)(s + 4) > 0.0f) {
        *(f32 *)(t + 0x2E4) = *(f32 *)(s + 4);
    }
    *(s32 *)(t + 0x2E8) = *(s32 *)(s + 8);
    if (*(f32 *)(s + 0xC) > 0.0f) {
        *(f32 *)(t + 0x2E4) = *(f32 *)(s + 0xC);
    }
    *(u128_t *)(t + 0x2D0) = *(u128_t *)(a1 + 0x10);
    func_L04_003CE760(a0, 0, 0, 1);
}
/* localdecomp:end func_L04_003CFDB8 */

/* localdecomp:start func_L04_003CFE28 */
f32 func_L04_003CFE28(void) {
    return 0.75f;
}
/* localdecomp:end func_L04_003CFE28 */
