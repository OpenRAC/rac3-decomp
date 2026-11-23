/* functional: high. Compiles; every store and branch re-read against retail asm. */
/* localdecomp:start func_L01_0037D920 */
#include "vu0.h"
typedef struct { s32 mode, count, f8, color0, color1; f32 scale; } Settings_0037D920;
extern Settings_0037D920 D_L01_002B3AC0;
extern s32 D_L01_001DFB40 __attribute__((section(".data")));
extern s32 D_L01_001E1D94 __attribute__((section(".data")));
extern s32 D_L01_001E1D90 __attribute__((section(".data")));
extern u8 D_0014262F[];
extern u8 D_L01_002C5600[];
extern f32 D_001DDB60_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDB60_sda, 4");
extern f32 D_001DDB64_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDB64_sda, 4");
extern vu0_v4 D_L01_001E2DE0[];
extern vu0_v4 D_L01_001E1D70[];
extern vu0_v4 D_L01_001E1D80[];
extern s32 D_L01_001E1DA0 __attribute__((section(".data")));
extern f32 D_L01_001E1DBC __attribute__((section(".data")));
extern f32 D_L01_001E1DB8 __attribute__((section(".data")));
u8 *func_L01_0037D920(u8 *owner, vu0_q *pos, vu0_q *dir, vu0_q *other, s32 a4, s32 a5, s32 alt, f32 scale)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_00382538(void);
    extern void func_L01_004AA7E8(void *, s32);
    vu0_v4 v0, v1, from, to, delta;
    u8 *obj = func_003C24B0(0x186F, 0x80);
    u8 *s;
    u8 *second;
    Settings_0037D920 *settings;
    s32 color;
    if (obj != 0) {
        obj[0x20] = 0;
        obj[0x30] = 255;
        *(u16 *)(obj + 0x32) = 255;
        settings = &D_L01_002B3AC0;
        s = *(u8 **)(obj + 0x68);
        *(vu0_q *)(obj + 0x10) = *pos;
        *(vu0_q *)(s + 0x20) = *pos;
        second = s + 0x10;
        func_0038CE20(dir, dir, 0.1f);
        func_0038CE20(other, other, 0.1f);
        *(vu0_q *)s = *dir;
        *(vu0_q *)(s + 0x10) = *other;
        *(s32 *)(s + 0x40) = a4;
        *(u8 **)(s + 0x38) = owner;
        *(u8 **)(obj + 0xB8) = owner;
        *(f32 *)(s + 0x30) = func_00382538();
        *(f32 *)(s + 0x3C) = scale;
        *(s32 *)(s + 0x34) = 0;
        *(s32 *)(s + 0x44) = a5;
        *(s32 *)(s + 0x4C) = 0;
        *(s32 *)(s + 0x48) = alt;
        D_L01_001E1D94 = D_L01_001DFB40;
        D_L01_001E1D90 = 1;
        {
            u8 *weapons = D_L01_002C5600;
            u8 type = *(D_0014262F[0] * 240 + weapons + 1);
            color = 0xBFA0FFA0;
            if (type == 1) color = 0xBFFFA0A0;
            if (type == 2) color = 0xBFFF8040;
            if (type == 3) color = 0xBFA0A0FF;
            if (type >= 4) color = 0xBFA0A0FF;
        }
        settings->color0 = 0xBFB0B0B0;
        settings->color1 = color;
        func_0038CF68(s, s, 30.0f);
        func_0038CF68(second, second, 30.0f);
        if (alt) {
            vu0_v4 *camera = D_L01_001E2DE0;
            func_0038CE20(&v0, camera, D_001DDB60_sda);
            func_0038CE20(&v1, camera - 2, D_001DDB64_sda);
            vec_add_ba(&from, camera - 58, &v1);
            vec_add_ba(&from, &from, &v0);
            func_0038CF68(&delta, second, 100.0f);
            vec_add_ab(&to, &from, &delta);
            D_L01_002B3AC0.mode = 2;
            *(vu0_q *)D_L01_001E1D70 = *(vu0_q *)&from;
            settings->count = 5;
            settings->scale = 0.25f;
        } else {
            func_0038CF68(&delta, s, 100.0f);
            *(vu0_q *)D_L01_001E1D70 = *pos;
            vec_add_ab(&to, pos, &delta);
            D_L01_002B3AC0.mode = 4;
            settings->count = 10;
            settings->scale = 0.75f;
        }
        *(vu0_q *)D_L01_001E1D80 = *(vu0_q *)&to;
        D_L01_001E1DA0 = 17;
        D_L01_001E1DBC = 0.2f;
        D_L01_001E1DB8 = 0.2f;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
    }
    return obj;
}
/* localdecomp:end func_L01_0037D920 */
