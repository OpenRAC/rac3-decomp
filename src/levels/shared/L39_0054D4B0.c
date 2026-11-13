#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_0054D4B0 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005FF538(void *, void *, f32, f32, f32);
extern void func_003C7C38(void *);
u8 *func_L39_0054D4B0(s32 owner, void *position, void *direction, s32 a3, s32 a4, s32 a5) {
    u8 *object = func_003C24B0(0x1090, 0x80);
    u8 *state;
    f32 first, second;
    u8 stamp;
    if (object != 0) {
        state = *(u8 **)(object + 0x68);
        stamp = 0xFF;
        *(s16 *)(object + 0x32) = stamp;
        object[0x30] = stamp;
        object[0x20] = 0;
        *(s32 *)(object + 0xB8) = owner;
        *(u128_t *)(object + 0x10) = *(u128_t *)position;
        *(u128_t *)state = *(u128_t *)direction;
        *(f32 *)(object + 0x2C) = 0.01f;
        *(s32 *)(state + 0x40) = a5;
        first = func_L39_005B4410(0.06283186f, 0.12566371f);
        *(f32 *)(state + 0x10) = first;
        second = func_L39_005B4410(0.06283186f, 0.12566371f);
        *(s32 *)(state + 0x30) = owner;
        *(s32 *)(state + 0x3C) = a4;
        *(s32 *)(state + 0x38) = a3;
        *(s32 *)(state + 0x18) = 0;
        *(f32 *)(state + 0x14) = second;
        *(s32 *)(state + 0x34) = func_L39_005FF538(object, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(object);
    }
    return object;
}
/* localdecomp:end func_L39_0054D4B0 */
