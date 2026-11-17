#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00541F78);

/* localdecomp:start func_L39_005422E8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern f32 func_L39_005B4410(f32, f32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind, s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_L39_005F33E0(s32, s32, s32);
extern u8 D_L39_00242930[8];
__asm__(".extern D_L39_0024AE8C, 4");
__asm__(".extern D_L39_0024AE90, 4");
__asm__(".extern D_L39_0024AE94, 4");
__asm__(".extern D_L39_0024AE98, 4");
extern s32 D_L39_0024AE8C;
extern s32 D_L39_0024AE90;
extern s32 D_L39_0024AE94;
extern s32 D_L39_0024AE98;

u8 *func_L39_005422E8(u8 *a0, f32 f, f32 *v, u128_t *a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    u8 *o;
    u8 *r;
    f32 g;
    f32 h;
    s32 n;
    f32 z;
    unsigned long t;

    n = 10;
    o = func_003C24B0(0xEA7, 0x80);
    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        r = *(u8 **)(o + 0x68);
        t = *(unsigned long *)(a0 + 0x38);
        *(unsigned long *)(o + 0x38) = t;
        *(u128_t *)(o + 0x10) = *a2;
        *(u128_t *)r = *(u128_t *)v;
        *(u8 **)(r + 0x10) = a0;
        *(f32 *)(r + 0x14) = f;
        *(f32 *)(r + 0x20) = 0.15f;
        *(u16 *)(o + 0x34) |= 0x208;
        *(s32 *)(r + 0x2C) = a3;
        *(s32 *)(r + 0x30) = a4;
        r[0x34] = a5;
        h = func_0038CEA8(v) * 0.8f;
        *(f32 *)(r + 0x3C) = h;
        *(f32 *)(r + 0x38) = -h;
        *(f32 *)(o + 0xF8) = func_0038DAB8(func_0038D160(v[0], v[1]), 1.5707964f);
        *(f32 *)(o + 0xF0) = -func_0038D160(func_0038CED8(v), v[2]);
        func_0038D308(o + 0xC0, o + 0xF0);
        *(u16 *)(o + 0x34) |= 0x100;
        o[0x23] = 0x80;
        *(f32 *)(o + 0x2C) = 0.0725f;
        *(s32 *)(r + 0x24) = 0;
        g = func_L39_005B4410(1.5f, 3.0f);
        switch (a6) {
        case 1: {
            s32 x = D_L39_0024AE94;
            s32 y = D_L39_0024AE98;
            *(s32 *)(r + 0x40) = x;
            *(s32 *)(r + 0x44) = y;
            *(s32 *)(r + 0x48) = x;
            break;
        }
        case 0:
        default: {
            s32 c0 = D_L39_0024AE8C;
            s32 c1 = D_L39_0024AE90;
            *(s32 *)(r + 0x40) = c0;
            *(s32 *)(r + 0x44) = c1;
            *(s32 *)(r + 0x48) = 0x80803010;
            break;
        }
        }
        *(s32 *)(r + 0x4C) = a6;
        z = 0.0f;
        func_L01_0046B458(o + 0x10, 12, g * 0.3f, g, *(s32 *)(r + 0x48), 0, n, D_L39_00242930, z, 0);
        func_L01_0046B458(o + 0x10, 12, g * 0.04f, g * 0.4f, -1, 1, -n, D_L39_00242930, z, 0);
        func_L39_005F33E0(0, 0, (s32)o);
    }
    return o;
}
/* localdecomp:end func_L39_005422E8 */
