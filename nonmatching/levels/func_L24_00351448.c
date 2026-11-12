/* func_L24_00351448: 4 differences (level 24, file L24_0034F040.c, -mvu0-use-vf0-vf2 @ps2as). Registers, frame and
   everything else match; the store order in the state initialisation is off by two adjacent stores: retail has
   `sw $s6,0x10($s0)` before `swc1 $f22,0x20($s0)` and `swc1 $f20,0x14($s0)` before the jal func_003A52A0, this C
   has the pairs swapped. Putting the a1 store first changes the s-register assignment (11 diff); every single
   move of one statement in the store group (50 variants) was tried, none matches. */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_003A52A0(s32, s32, u8 *);

s32 func_L24_00351448(void *a0, void *a1, void *a2, s32 a3, s32 a4, f32 f12, f32 f13, f32 f14, f32 f15) {
    u8 *o = func_003C24B0(0x15E2, 0x80);
    u8 *s;
    f32 *v = (f32 *)a2;

    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        s = *(u8 **)(o + 0x68);
        *(u128_t *)s = *(u128_t *)a2;
        *(u128_t *)(o + 0x10) = *(u128_t *)a0;
        *(f32 *)(o + 0xF8) = func_0038D160(v[0], v[1]);
        *(f32 *)(o + 0xF4) = -func_0038D160(func_0038CED8(v), v[2]);
        *(s32 *)(o + 0xF0) = 0;
        *(f32 *)(s + 0x20) = f13;
        *(void **)(s + 0x10) = a1;
        *(s32 *)(s + 0x28) = a3;
        *(s32 *)(s + 0x2C) = a4;
        *(f32 *)(s + 0x24) = f14;
        *(f32 *)(s + 0x18) = f12 * 0.00040000002f;
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * f15;
        *(f32 *)(s + 0x14) = f15;
        func_003A52A0(0, 0, o);
        o[0x20] = 0;
        func_003C7C38(o);
    }
    return (s32)o;
}
