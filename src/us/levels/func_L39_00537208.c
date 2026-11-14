#include "common.h"

/* localdecomp:start func_L39_00537208 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32, s32);
extern float func_L39_005B2510(float, float);
extern void func_003C26C8(u8 *);
extern f32 D_001DF610_sda;
__asm__(".extern D_001DF610_sda, 4");
extern s32 D_L39_002412AC;

u8 *func_L39_00537208(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 a4, s32 a5) {
    u8 *obj = func_003BCFB0(0x1099, 0x80);
    u8 *state;
    f32 second;
    s32 d;
    if (obj != 0) {
        state = *(u8 **)(obj + 0x68);
        obj[0x30] = 0xFF;
        *(u16 *)(obj + 0x32) = 0x7F;
        *(s32 *)(obj + 0xB8) = a0;
        *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) * 0.5f;
        obj[0x31] = 1;
        obj[0x20] = 0;
        *(u16 *)(state + 0x36) = 0;
        if (a4 != 0) {
            *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * D_001DF610_sda;
            *(u128_t *)state = *(u128_t *)a3;
            state[0x51] = 1;
            *(s32 *)(state + 0x74) = a5;
        }
        *(u16 *)(state + 0x7C) = *(u16 *)(a1 + 0x2544);
        *(s32 *)(obj + 0x90) = *(s32 *)a1;
        *(s32 *)(obj + 0x78) = 0;
        *(u16 *)(obj + 0x34) |= 0x10;
        *(u128_t *)(obj + 0x10) = *(u128_t *)a2;
        *(f32 *)(state + 0x38) = func_L39_005B2510(0.017453294f, 0.052359883f);
        second = func_L39_005B2510(0.017453294f, 0.052359883f);
        d = D_L39_002412AC;
        *(f32 *)(state + 0x3C) = second;
        *(f32 *)(state + 0x6C) = *(f32 *)(state + 0x70) = *(f32 *)(state + 0x60) = *(f32 *)(state + 0x64) = 0.0f;
        *(s32 *)(state + 0x5C) = d;
        *(s32 *)(state + 0x68) = -1;
        *(s32 *)(obj + 0x98) = 0;
        func_003C26C8(obj);
    }
    return obj;
}
/* localdecomp:end func_L39_00537208 */
