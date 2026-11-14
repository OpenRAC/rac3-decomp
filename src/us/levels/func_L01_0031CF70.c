#include "common.h"

/* NTSC-U counterpart of func_L01_0031D3D0 (src/levels/shared/L01_0031C1D0.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0031CF70 */
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E2A8(void);
extern void func_00388BD0(void *, void *);
extern f32 func_0037E250(f32, f32);
extern void func_003BF2F8(void *, void *, f32);
extern s32 func_L01_004C4A18(void *, s32, f32, f32, f32);
extern void func_003C26C8(void *);
extern f32 D_001DC8BC_sda;
extern f32 D_001DC8C8_sda;
__asm__(".extern D_001DC8BC_sda, 4");
__asm__(".extern D_001DC8C8_sda, 4");

u8 *func_L01_0031CF70(u128_t *pos, u128_t *vel, s32 a2) {
    u8 *o = func_003BCFB0(0xE64, 0x80);
    u8 *vars;
    f32 f;

    if (o != 0) {
        vars = *(u8 **)(o + 0x68);
        *(u16 *)(o + 0x32) = 0xFF;
        o[0x20] = 0;
        o[0x30] = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        *(u128_t *)(o + 0x10) = *pos;
        *(u128_t *)vars = *vel;
        *(s32 *)(vars + 0x2C) = a2;
        *(s32 *)(vars + 0x28) = 0xF;
        *(s32 *)(vars + 0x24) = 0;
        *(f32 *)(o + 0xF0) = func_0037E2A8();
        *(f32 *)(o + 0xF4) = func_0037E2A8();
        *(f32 *)(o + 0xF8) = func_0037E2A8();
        func_00388BD0(o + 0xC0, o + 0xF0);
        f = func_0037E250(0.0523598827f, 0.104719765f);
        func_003BF2F8(vars + 0x10, o + 0xD0, f);
        if (a2 != 0) {
            *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * D_001DC8C8_sda;
        } else {
            *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * D_001DC8BC_sda;
        }
        *(s32 *)(vars + 0x30) = func_L01_004C4A18(o, 0, 1.0f, 1.0f, 1.0f);
        func_003C26C8(o);
    }
    return o;
}
/* localdecomp:end func_L01_0031CF70 */
