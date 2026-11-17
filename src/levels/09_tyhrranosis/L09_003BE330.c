#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BE330 */
extern s32 func_0038CB00(void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C3FC0(void *, void *);
extern void func_0038D750(void *, s32, f32);

s32 func_L09_003BE330(u8 *a0, void *a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (p[0xD41] == 0) {
        p[0xD41] = 2;
        *(s16 *)(p + 0xD3A) = 50;
        *(f32 *)(p + 0xD3C) = 0.02f;
    }
    if (func_0038CB00(p + 0xD3A) != 0 || p[0xD41] == 1) {
        p[0xD41] = 1;
        return 1;
    }
    if (p[0xD41] == 2) {
        *(f32 *)(p + 0xC30) = func_003C3BE8(-(*(f32 *)(a0 + 0x18) - 332.0f + -2.0f), 0.0f,
                                            (f32)*(s16 *)(p + 0xD3A) * *(f32 *)(p + 0xD3C));
        func_0038CE20(p + 0xC30, p + 0xC30, 1024.0f);
        if (a1 != 0)
            func_003C3FC0(p + 0xC50, a1);
        else
            func_0038D750(p + 0xC50, 1, -0.017453292f);
    }
    return 0;
}
/* localdecomp:end func_L09_003BE330 */
