#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_0054CF30 */
extern u8 *func_003C24B0(s32, s32);
extern float func_L39_005B4410(float, float);
extern s32 func_L39_005FF538(u8 *, u8 *, float, float, float);
extern void func_003C7C38(u8 *);

u8 *func_L39_0054CF30(s32 a0, u8 *position, u8 *direction, s32 a3, s32 a4, s32 a5) {
    u8 *object = func_003C24B0(0x108E, 0x80);
    u8 *state;
    float first, second;
    u8 stamp;
    if (object != 0) {
        state = *(u8 **)(object + 0x68);
        stamp = 0xFF;
        object[0x20] = 0;
        *(u16 *)(object + 0x32) = stamp;
        object[0x30] = stamp;
        *(u128_t *)(object + 0x10) = *(u128_t *)position;
        *(u128_t *)state = *(u128_t *)direction;
        *(float *)(object + 0x2C) = 0.01f;
        *(s32 *)(state + 0x50) = a5;
        first = func_L39_005B4410(0.06283186f, 0.12566371f);
        *(float *)(state + 0x10) = first;
        second = func_L39_005B4410(0.06283186f, 0.12566371f);
        *(s32 *)(state + 0x4C) = a4;
        *(s32 *)(state + 0x48) = a3;
        *(s32 *)(state + 0x18) = 0;
        *(s32 *)(state + 0x40) = a0;
        *(float *)(state + 0x14) = second;
        *(s32 *)(state + 0x44) = func_L39_005FF538(object, 0, 1.0f, 1.0f, 1.0f);
        *(s32 *)(object + 0xB8) = a0;
        func_003C7C38(object);
    }
    return object;
}
/* localdecomp:end func_L39_0054CF30 */
