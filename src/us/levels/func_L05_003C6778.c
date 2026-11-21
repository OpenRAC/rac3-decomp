#include "common.h"

/* NTSC-U counterpart of func_L05_003C8890 (src/levels/shared/L05_003C87A8.c): 250 -> 300; 0.02 -> 0.0166667; 12 -> 14; 17 -> 20 */
#include "vu0.h"

/* localdecomp:start func_L05_003C6778 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C8890;
extern void func_003BFC18(void *, void *, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00440A88_003C6778(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern void func_00388758(void *, void *, void *);
extern void func_L01_00467DA8_003C6778(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_0046D570_003C6778(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern u8 D_L05_001D66B0_003C6778;
__asm__(".extern D_L05_001DECB0_003C6778, 8");
extern s32 D_L05_001DECB0_003C6778[2];
__asm__(".extern D_L05_001DECD0_003C6778, 8");
extern f32 D_L05_001DECD0_003C6778[2];
__asm__(".extern D_L05_001DECF0_003C6778, 8");
extern f32 D_L05_001DECF0_003C6778[2];
__asm__(".extern D_L05_001DED10_003C6778, 8");
extern s32 D_L05_001DED10_003C6778[2];

u8 *func_L05_003C6778(void *a0, void *a1, void *pos, void *dir, f32 scale)
{
    V_3C8890 v;
    V_3C8890 d;
    u8 *obj;
    u8 *m;
    f32 t;
    s32 i;

    func_003BFC18(pos, &v, 1);
    obj = func_003BCFB0(0x1C33, 0x80);
    if (obj != 0) {
        m = *(u8 **)(obj + 0x68);
        *(u16 *)(obj + 0x34) |= 0x100;
        *(s32 *)(m + 0x20) = 0x12C;
        obj[0x30] = 0xFF;
        *(s16 *)(obj + 0x32) = 0xFF;
        *(f32 *)(obj + 0x2C) = 0.003f;
        obj[0x20] = 0;
        *(u128_t *)(obj + 0x10) = *(u128_t *)pos;
        *(u128_t *)m = *(u128_t *)dir;
        *(void **)(m + 0x34) = a1;
        func_L01_00440A88_003C6778(m + 0x10, 0.2f, 1.0f);
        t = func_0037E250(-1000.0f, 1000.0f) * 0.017453292f * 0.0166666675f;
        func_00388830(m + 0x10, m + 0x10, func_00388978(t));
        *(f32 *)(m + 0x1C) = func_00388960(t);
        *(f32 *)(m + 0x2C) = scale;
        *(s32 *)(m + 0x28) = 0;
        *(s32 *)(m + 0x24) = 0;
        func_00388830(&d, dir, 1.0f);
        *(V_3C8890 *)(obj + 0xC0) = d;
        func_00388758(obj + 0xD0, obj + 0xC0, &v);
        func_00388830(obj + 0xD0, obj + 0xD0, 1.0f);
        func_00388758(obj + 0xE0, obj + 0xD0, obj + 0xC0);
        *(f32 *)(obj + 0xCC) = *(f32 *)(obj + 0xDC) = *(f32 *)(obj + 0xEC) = 0.0f;
        *(void **)(m + 0x30) = a0;
        for (i = 0; i < 4; i++) {
            func_L01_00467DA8_003C6778(pos, 0xE, D_L05_001DECD0_003C6778[i], D_L05_001DECF0_003C6778[i], D_L05_001DECB0_003C6778[i], 2, 1, &D_L05_001D66B0_003C6778, 0.0f, 1);
        }
        for (; i < 7; i++) {
            func_L01_0046D570_003C6778(pos, 0x14, D_L05_001DECD0_003C6778[i], D_L05_001DECF0_003C6778[i], D_L05_001DECB0_003C6778[i], 2, 2, &D_L05_001D66B0_003C6778, 0, D_L05_001DED10_003C6778[i - 4], 6, 1);
        }
    }
    return obj;
}
/* localdecomp:end func_L05_003C6778 */
