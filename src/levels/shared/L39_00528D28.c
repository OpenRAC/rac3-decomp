#include "common.h"

/* localdecomp:start func_L39_00528D28 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_003C7C38(void *);
extern void func_L39_005F33E0(s32, s32, void *);

/* from L39_0054D4B0 (same constructor shape) */
u8 *func_L39_00528D28(s32 a0, void *a1, void *a2, s32 a3, s32 a4, f32 f0, f32 f1, f32 f2, f32 f3) {
    u8 *object = func_003C24B0(0x15A5, 0x80);
    u8 *state;
    f32 lo;
    f32 hi;
    if (object == 0) {
        return 0;
    }
    lo = -0.785398f;
    hi = 0.785398f;
    object[0x30] = 0xFF;
    *(f32 *)(object + 0xF8) = f0;
    *(f32 *)(object + 0xF4) = f1;
    *(s16 *)(object + 0x32) = 0xFF;
    object[0x31] = 1;
    object[0x20] = 0;
    *(f32 *)(object + 0x2C) = *(f32 *)(*(u8 **)(object + 0x24) + 0x24) * 0.25f;
    state = *(u8 **)(object + 0x68);
    *(s32 *)(state + 0x30) = a0;
    *(s32 *)(state + 0x64) = a4;
    *(u128_t *)(object + 0x10) = *(u128_t *)a1;
    *(u128_t *)(state + 0x20) = *(u128_t *)a1;
    *(u128_t *)(state + 0x10) = *(u128_t *)a2;
    *(f32 *)(state + 0x50) = func_L39_005B4410(-0.007736f, 0.007736f);
    *(f32 *)(state + 0x54) = func_L39_005B4410(-0.019248f, 0.019248f);
    *(f32 *)(state + 0x38) = f2;
    *(f32 *)(state + 0x5C) = f3;
    *(s32 *)(state + 0x3C) = 0;
    *(s32 *)(state + 0x40) = 0;
    *(s32 *)(state + 0x44) = 0;
    *(f32 *)(state + 0x48) = func_L39_005B4410(lo, hi);
    *(f32 *)(state + 0x4C) = func_L39_005B4410(lo, hi);
    *(s32 *)(state + 0x60) = a3;
    *(s32 *)(state + 0x34) = 0xD0;
    func_003C7C38(object);
    func_L39_005F33E0(0, 0, object);
    return object;
}
/* localdecomp:end func_L39_00528D28 */
