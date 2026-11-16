#include "common.h"

/* NTSC-U counterpart of func_L21_003AF758 (src/levels/21_obani_draco/L21_003AEB70.c) */
#include "vu0.h"
extern s32 func_L21_003ADC08(u8 *);
extern void func_L21_003AE058(void *);
extern void func_003BE4F0(u8 *, s32, s32, s32);

/* localdecomp:start func_L21_003ADC08 */
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L21_003AE058(void *);

s32 func_L21_003ADC08(u8 *a0) {
    u8 *s;
    if (a0[0x20] != 0) {
        return 0;
    }
    s = *(u8 **)(a0 + 0x68);
    *(s16 *)(s + 0x108) = 0;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    *(f32 *)(s + 0x100) = 0.5f;
    *(f32 *)(s + 0x104) = 0.5f;
    s[0xE0] = 9;
    s[0xE1] = 7;
    *(f32 *)(s + 0x10C) = 0.15f;
    s[0x118] = 0xFF;
    s[0xE2] = 9;
    s[0xE6] = 10;
    *(f32 *)(s + 0xEC) = 0.25f;
    *(f32 *)(s + 0xF0) = 1.0f / 60.0f;
    *(f32 *)(s + 0xF4) = 0.0069444444961845875f;
    *(f32 *)(s + 0xF8) = 0.009722222574055195f;
    *(f32 *)(s + 0xFC) = 0.0005555555690079927f;
    s[0x14B] = 0xFF;
    s[0x147] = 0;
    s[0x148] = 0;
    s[0x149] = 0;
    s[0x14A] = 0;
    s[0x142] = 0;
    s[0x143] = 0;
    *(f32 *)(s + 0x110) = *(f32 *)(a0 + 0x18) - 10.0f;
    *(f32 *)(s + 0x12C) = 0.8f;
    *(f32 *)(s + 0x128) = 0.4f;
    *(f32 *)(s + 0x190) = 0.1f;
    *(f32 *)(s + 0x194) = 0.2f;
    *(f32 *)(s + 0x180) = 1.0f;
    *(f32 *)(s + 0x198) = 2.0f;
    *(f32 *)(s + 0x19C) = 2.0f;
    *(f32 *)(s + 0x1A0) = 1.3089969f;
    *(f32 *)(s + 0x1C0) = 3.1415927f;
    *(f32 *)(s + 0x1BC) = 0.0027222223579883575f;
    *(f32 *)(s + 0x1C4) = 1.0f;
    *(f32 *)(s + 0x40) = 1.0f;
    s[0x3E] = 1;
    s[0x39] = 0;
    s[0x3F] = 0;
    s[0x64] = 0;
    s[0x5F] = 0;
    if (*(s16 *)(s + 0x34) == 0 || *(f32 *)(s + 0x30) <= 0.0f) {
        *(s16 *)(s + 0x34) = 25;
        *(f32 *)(s + 0x30) = 25.0f;
    }
    if (s[0x44] == 0) {
        s[0x44] = 2;
    }
    s[0x58] = 0x28;
    s[0x5A] = 0x60;
    if (a0[0x43] != 0) {
        func_003BE4F0(a0, 0, 0, 0);
    }
    func_L21_003AE058(a0);
    return 1;
}
/* localdecomp:end func_L21_003ADC08 */
