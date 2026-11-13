#include "common.h"

/* NTSC-U counterpart of func_L39_00552750 (src/levels/shared/L39_00550D48.c): 25 -> 30; 0.0048 -> 0.00333333 */
/* localdecomp:start func_L39_00551E00 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0_00551E00(s32, s32);
extern f32 func_L39_005B25C8_00551E00(void);
extern void func_0038CF68_00551E00(void *, void *, f32);
extern void func_L39_005FC9F8(u8 *, u8 *, u8 *);

u8 *func_L39_00551E00(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 a4, f32 a5) {
    u8 *object = func_003C24B0_00551E00(0x10A9, 0x80);
    u8 *state;
    u8 stamp;
    u8 *pos;
    u8 *vec;
    if (object != 0) {
        state = *(u8 **)(object + 0x68);
        stamp = 0xFF;
        *(u16 *)(object + 0x32) = stamp;
        object[0x30] = stamp;
        if (a4 != 0) {
            object[0x20] = 1;
        } else {
            object[0x20] = 0;
        }
        vec = object + 0xE0;
        pos = object + 0x10;
        *(u128_t *)pos = *(u128_t *)a2;
        *(u128_t *)state = *(u128_t *)a3;
        *(f32 *)(state + 0x10) = func_L39_005B25C8_00551E00();
        *(f32 *)(state + 0x18) = 0.005f;
        *(f32 *)(state + 0x1C) = 0.01f;
        *(s32 *)(state + 0x24) = -1;
        *(f32 *)(state + 0x28) = a5;
        *(s32 *)(state + 0x30) = 0x1E;
        *(s32 *)(state + 0x14) = 0;
        *(u8 **)(state + 0x2C) = a1;
        *(f32 *)(object + 0x2C) = *(f32 *)(*(u8 **)(object + 0x24) + 0x24) * 3.25f;
        object[0x23] = 0x14;
        *(u16 *)(object + 0x34) |= 0x100;
        *(s32 *)(object + 0xB8) = a0;
        *(u128_t *)(object + 0xC0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xC0);
        *(u128_t *)(object + 0xD0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xD0);
        *(u128_t *)(object + 0xE0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xE0);
        func_0038CF68_00551E00(object + 0xD0, object + 0xD0, *(f32 *)(state + 0x18));
        func_0038CF68_00551E00(vec, vec, *(f32 *)(state + 0x1C));
        *(u16 *)(object + 0x34) |= 4;
        *(s32 *)(object + 0x98) = 0;
        state[0x70] = a1 != 0 && *(s16 *)(a1 + 0x2D8) != 0;
        func_L39_005FC9F8(a1, pos, state + 0x60);
        func_0038CF68_00551E00(state + 0x60, state + 0x60, 0.00333333341f);
    }
    return object;
}
/* localdecomp:end func_L39_00551E00 */
