/* func_L35_003BC828: 6 diff with the file's flags (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as). Only the two int parameters are swapped in $s3/$s4 (retail: a1 in $s4, a2 in $s3); a local copy of a2, and loading the a1 copy before the stores, leave it unchanged. The lq/sq copies, the three func_003824E0 calls and the stores match. */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_003824E0(f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

u8 *func_L35_003BC828(u8 *a0, u8 *a1, s32 a2, f32 a3, f32 a4) {
    u8 *obj;
    u8 *m;
    u8 *pa;
    f32 k0;
    f32 k1;
    f32 k2;

    obj = func_003C24B0(0x1E16, 0x80);
    if (obj == 0) {
        return 0;
    }
    obj[0x30] = 0xFF;
    *(s16 *)(obj + 0x32) = 0x40;
    pa = *(u8 **)(obj + 0x24);
    m = *(u8 **)(obj + 0x68);
    k2 = *(f32 *)(pa + 0x24);
    obj[0x23] = 0x50;
    *(f32 *)(obj + 0x2C) = a3 * k2;
    k1 = 0.0599999987f;
    k0 = -0.0599999987f;
    *(u128_t *)(obj + 0x10) = *(u128_t *)a0;
    *(u128_t *)m = *(u128_t *)a1;
    *(s32 *)(m + 0x20) = a2;
    *(f32 *)(m + 0x28) = a4;
    *(s32 *)(m + 0x24) = 3;
    *(f32 *)(m + 0x10) = func_003824E0(k0, k1);
    *(f32 *)(m + 0x14) = func_003824E0(k0, k1);
    *(f32 *)(m + 0x18) = func_003824E0(k0, k1);
    func_L01_004450F0(obj, 0, -1);
    return obj;
}
