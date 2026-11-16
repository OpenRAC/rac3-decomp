#include "common.h"

/* NTSC-U counterpart of func_003E41F8 (boot_elf). */
extern void func_0011B2E8();
extern s32 func_U_0038DF00(s32, s32, f32);
extern s32 D_U_001D9590;
extern f32 D_U_001D9598;
extern s32 D_00142668[];
extern s32 D_U_001DA868[2];
extern char D_U_001D95A0[];
extern s32 func_U_0038DF00(s32, s32, f32);
extern f32 func_U_0038D3C0(f32);
extern s32 func_U_003E40A0(s32);
extern void func_U_003E52E0(f32 *, f32);
extern s32 func_U_003E7610(s32, f32, f32);
extern s32 func_U_003E8448(s32, f32, f32);
extern s32 func_U_003E7C70(s32, s32);
extern s32 func_U_003E80A0(s32, s32);
extern s32 func_U_003E7A90(s32, s32, s32);
extern s32 func_U_003E7FC8(s32, s32);
extern s32 func_U_003E7DD8_003E40B0(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_0011B2E8(void *, char *, s32);
extern void func_0011B2E8();
extern s32 func_U_0038DF00(s32, s32, f32);
typedef struct { u8 pad[0xAA]; s16 xAA; } M_3DE8F0;
typedef struct { f32 f0; s16 h4; } R_3DE8F0;
typedef struct {
    u8 pad0[0x19E0];
    M_3DE8F0 *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 x25E4;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 x2850;
} W_3DE8F0;
typedef struct { u8 pad[0x20]; u8 x20; } F_3DE8F0;
extern s32 D_U_001D9590;
extern f32 D_U_001D9598;
extern W_3DE8F0 D_001A4BE0_003E40B0[];
extern F_3DE8F0 D_00142CA0_003E40B0[];
extern s32 D_00142668[];
extern s32 D_U_001DA868[2];
extern char D_U_001D95A0[];
extern R_3DE8F0 *func_U_00382748_003E40B0(M_3DE8F0 *);
extern s32 func_U_0038DF00(s32, s32, f32);
extern f32 func_U_0038D3C0(f32);
extern s32 func_U_003E40A0(s32);
extern void func_U_003E52E0(f32 *, f32);
extern s32 func_U_003E7610(s32, f32, f32);
extern s32 func_U_003E8448(s32, f32, f32);
extern s32 func_U_003E7C70(s32, s32);
extern s32 func_U_003E80A0(s32, s32);
extern s32 func_U_003E7A90(s32, s32, s32);
extern s32 func_U_003E7FC8(s32, s32);
extern s32 func_U_003E7DD8_003E40B0(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_0011B2E8(void *, char *, s32);

/* localdecomp:start func_U_003E40B0 */
__asm__(".extern D_U_001D9590, 4");
__asm__(".extern D_U_001D9598, 4");
void func_U_003E40B0(void) {
    extern R_3DE8F0 *func_U_00382748_003E40B0(M_3DE8F0 *);
    extern void func_U_003E52E0(f32 *, f32);
    extern s32 func_U_003E8448(s32, f32, f32);
    extern s32 func_U_003E7610(s32, f32, f32);
    extern s32 func_U_003E7C70(s32, s32);
    extern s32 func_U_003E40A0(s32);
    extern s32 func_U_003E80A0(s32, s32);
    extern s32 func_U_003E7A90(s32, s32, s32);
    extern void func_0011B2E8(void *, char *, s32);
    extern s32 func_U_003E7DD8_003E40B0(s32, f32 *, f32 *, f32 *, f32 *);
    extern f32 func_U_0038D3C0(f32);
    extern s32 func_U_0038DF00(s32, s32, f32);
    extern s32 func_U_003E7FC8(s32, s32);
    s32 current = D_001A4BE0_003E40B0[0].x2850;
    s32 maximum;
    s32 initial;
    s32 ones, tens, hundreds, showHundreds, digit, color;
    f32 bar0, bar1, x0, y, x1;
    f32 start, left, pulse, health, capacity, first, center, fade;
    if ((u8)(D_001A4BE0_003E40B0[0].x25E4 ^ 1) == 0) initial = 4;
    else initial = D_00142668[0];
    maximum = initial;
    if (D_001A4BE0_003E40B0[0].x25C4 == 0x31 && D_001A4BE0_003E40B0[0].x19E0 &&
        (D_001A4BE0_003E40B0[0].x19E0->xAA == 0x1A17 || D_001A4BE0_003E40B0[0].x19E0->xAA == 0x107E)) {
        R_3DE8F0 *r = func_U_00382748_003E40B0(D_001A4BE0_003E40B0[0].x19E0);
        if (r) {
            current = (s32)(r->f0 * 100.0f / r->h4);
            maximum = 100;
        }
    }
    health = current;
    capacity = maximum;
    if (D_00142CA0_003E40B0[0].x20 == 0) {
        bar0 = health / capacity * 0.230333f;
        func_U_003E52E0(&bar0, 0.230333f);
        func_U_003E8448(0x9000A, 0.230333f - bar0, 0.04933299869298935f);
        func_U_003E7610(0x9000A, 0.615581036f, 0.0739995018f);
        func_U_003E8448(0x9000B, bar0, 0.04933299869298935f);
        func_U_003E7610(0x9000B, 0.385248005f, 0.0739995018f);
        func_U_003E7C70(0x90008, 0);
    } else {
        bar1 = health / capacity * 0.226833001f;
        func_U_003E52E0(&bar1, 0.226833001f);
        func_U_003E8448(0x9000A, 0.226833001f - bar1, 0.04933299869298935f);
        func_U_003E7610(0x9000A, 0.587747991f, 0.0739995018f);
        func_U_003E8448(0x9000B, bar1, 0.04933299869298935f);
        func_U_003E7610(0x9000B, 0.360915005f, 0.0739995018f);
        func_U_003E7C70(0x90008, 1);
        func_U_003E7610(0x90008, 0.598917007f, 0.074000001f);
    }
    digit = current / 10;
    ones = func_U_003E40A0(current % 10);
    tens = func_U_003E40A0(digit % 10);
    digit = (current / 100) % 10;
    showHundreds = digit != 0;
    hundreds = func_U_003E40A0(digit);
    func_U_003E80A0(0x90003, ones);
    func_U_003E80A0(0x90004, tens);
    func_U_003E80A0(0x90005, hundreds);
    func_U_003E7A90(0x90005, 1, showHundreds);
    start = 0.0900000036f;
    if (showHundreds) start = 0.135000005f;
    func_0011B2E8(D_U_001DA868, D_U_001D95A0, maximum);
    x0 = 0.0f;
    x1 = 0.0f;
    func_U_003E7DD8_003E40B0(0x90006, &x0, &y, &x1, &y);
    first = x0;
    pulse = start + (x1 - first);
    center = 0.5f;
    if (D_00142CA0_003E40B0[0].x20) center = 0.475f;
    left = center - pulse * 0.5f;
    if (showHundreds) {
        func_U_003E7610(0x90005, left, 0.074000001f);
        left += 0.045f;
    }
    func_U_003E7610(0x90004, left, 0.074000001f);
    left += 0.045f;
    func_U_003E7610(0x90003, left, 0.074000001f);
    func_U_003E7610(0x90006, left + 0.045f, 0.0689999983f);
    if (health < capacity * 0.15f) {
        D_U_001D9598 += 0.05000000074505806f;
        if (D_U_001D9598 >= 2.0f) D_U_001D9598 -= 2.0f;
        D_U_001D9590++;
    } else {
        if (D_U_001D9598 > 1.0f) D_U_001D9598 = 2.0f - D_U_001D9598;
        D_U_001D9598 *= 0.949999988079071f;
    }
    if (D_U_001D9598 > 1.0f) fade = 2.0f - D_U_001D9598;
    else fade = D_U_001D9598;
    color = func_U_0038DF00(0x8066CCFF, 0x60202080, (1.0f - func_U_0038D3C0(fade * 3.14159274f)) * 0.5f);
    func_U_003E7FC8(0x90003, color);
    func_U_003E7FC8(0x90004, color);
    func_U_003E7FC8(0x90005, color);
    func_U_003E7FC8(0x90006, color);
}
/* localdecomp:end func_U_003E40B0 */
