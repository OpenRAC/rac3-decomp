/* func_L32_0039F828: 137 diff with the file's flags. Retail uses 9 saved regs (b in $fp), stores each result in the next jal's delay slot with arg loads hoisted above, and builds 6.2831855f with lui/ori (needs non-$gp pool constant; ps2as did not help). Mine reorders arg loads/stores and allocates fewer regs. */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L32_001DE484, D_L32_001DE480, D_L32_001DE48C, D_L32_001DE488, D_L32_001DE528, D_L32_001DE524;
extern f32 D_L32_001DE53C, D_L32_001DE578, D_L32_001DE574, D_L32_001DE580, D_L32_001DE57C;
extern f32 D_L32_001DE55C, D_L32_001DE558, D_L32_001DE564, D_L32_001DE560;
extern s32 D_L32_001DE4A8, D_L32_001DE4A4, D_L32_001DE4D4, D_L32_001DE4D0;
f32 func_003824E0(f32, f32);
s32 func_00382498(s32, s32);
f32 func_0038DB48(f32);
f32 func_0038D0B0(f32);
f32 func_003C4088(f32, f32, f32);

void func_L32_0039F828(u8 *a, u8 *b) {
    u8 *p = *(u8 **)(a + 0x68);
    qzero(p);
    *(u128_t *)(p + 0x10) = *(u128_t *)(a + 0x10);
    *(s32 *)(p + 0x40) = 0;
    *(s32 *)(p + 0x44) = 0;
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x4C) = 0;
    *(s32 *)(p + 0x58) = 0;
    *(f32 *)(p + 0x5C) = func_003824E0(D_L32_001DE484, D_L32_001DE480);
    *(f32 *)(p + 0x60) = func_003824E0(D_L32_001DE48C, D_L32_001DE488);
    *(s32 *)(p + 0x64) = func_00382498(D_L32_001DE4A8, D_L32_001DE4A4);
    *(s32 *)(p + 0x68) = func_00382498(D_L32_001DE4D4, D_L32_001DE4D0);
    *(f32 *)(p + 0x70) = func_003824E0(D_L32_001DE528, D_L32_001DE524);
    *(f32 *)(a + 0x2C) = *(f32 *)(*(u8 **)(a + 0x24) + 0x24) * *(f32 *)(p + 0x70);
    *(f32 *)(p + 0x6C) = D_L32_001DE53C * *(f32 *)(p + 0x70);
    *(f32 *)(p + 0x74) = func_003824E0(D_L32_001DE578, D_L32_001DE574);
    *(f32 *)(p + 0x78) = func_003824E0(D_L32_001DE580, D_L32_001DE57C);
    *(u8 **)(p + 0x48) = b;
    if (b != 0) {
        f32 *bf = (f32 *)b;
        f32 *i1 = bf + 4;
        f32 *i2 = bf + 0x44;
        f32 *i3 = bf + 0x24;
        f32 *i4 = bf + 0x64;
        f32 *o1 = (f32 *)(p + 0x80);
        f32 *o2 = (f32 *)(p + 0x100);
        f32 f23 = func_003824E0(D_L32_001DE55C / D_L32_001DE558, 1.0f);
        f32 f22 = func_003824E0(D_L32_001DE564, D_L32_001DE560) * 32.0f;
        s32 i = 0;
        do {
            f32 x = (f32)i / f22;
            f32 f20;
            i++;
            x = x - (f32)(s32)x;
            f20 = f23 * 0.5f;
            f20 = f20 * func_0038D0B0(func_0038DB48(x * 6.2831855f)) + 0.5f;
            *o1++ = func_003C4088(*i1++, *i2++, f20);
            *o2++ = func_003C4088(*i3++, *i4++, f20);
        } while (i < 32);
    }
    *(s32 *)(p + 0x180) = 0;
}
