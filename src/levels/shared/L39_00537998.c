#include "common.h"

/* localdecomp:start func_L39_00537998 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 D_L39_0024AD90;
__asm__(".extern D_L39_0024AD90, 4");
extern s32 D_L39_0024112C;

u8 *func_L39_00537998(s32 a0, u8 *a1, u128_t *a2, u128_t *a3, s32 a4, s32 a5) {
    u8 *p;
    u8 *q;

    p = func_003C24B0(0x1099, 0x80);
    if (p != 0) {
        q = *(u8 **)(p + 0x68);
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0x7F;
        *(s32 *)(p + 0xB8) = a0;
        *(f32 *)(p + 0x2C) *= 0.5f;
        p[0x31] = 1;
        p[0x20] = 0;
        *(s16 *)(q + 0x36) = 0;
        if (a4 != 0) {
            *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * D_L39_0024AD90;
            *(u128_t *)q = *a3;
            q[0x51] = 1;
            *(s32 *)(q + 0x74) = a5;
        }
        *(u16 *)(q + 0x7C) = *(u16 *)(a1 + 0x2544);
        *(s32 *)(p + 0x90) = *(s32 *)a1;
        *(s32 *)(p + 0x78) = 0;
        *(u16 *)(p + 0x34) |= 0x10;
        *(u128_t *)(p + 0x10) = *a2;
        *(f32 *)(q + 0x38) = func_L39_005B4410(0.020943953f, 0.06283186f);
        {
            s32 d;
            f32 t = func_L39_005B4410(0.020943953f, 0.06283186f);
            f32 z = 0.0f;
            d = D_L39_0024112C;
            *(f32 *)(q + 0x64) = z;
            *(f32 *)(q + 0x3C) = t;
            *(f32 *)(q + 0x60) = z;
            *(f32 *)(q + 0x70) = z;
            *(f32 *)(q + 0x6C) = z;
            *(s32 *)(q + 0x5C) = d;
            *(s32 *)(q + 0x68) = -1;
        }
        *(s32 *)(p + 0x98) = 0;
        func_003C7C38(p);
    }
    return p;
}
/* localdecomp:end func_L39_00537998 */
