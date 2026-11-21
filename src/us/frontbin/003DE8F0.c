#include "common.h"

/* NTSC-U counterpart of func_003E3E40 (src/frontbin/3E3E40.c): bar height 0.05 -> 0.049333, pulse step 0.06 -> 0.05, decay 0.94 -> 0.95 */
/* localdecomp:start func_U_003DE8F0 */
typedef struct { u8 pad[0xAA]; s16 xAA; } M_U_003DE8F0;
typedef struct { f32 f0; s16 h4; } R_U_003DE8F0;
typedef struct {
    u8 pad0[0x19E0];
    M_U_003DE8F0 *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 x25E4;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 x2850;
} W_U_003DE8F0;
typedef struct { u8 pad[0x20]; u8 x20; } F_U_003DE8F0;
extern s32 D_U_001D9590;
extern f32 D_U_001D9598;
extern W_U_003DE8F0 D_001A4BE0[];
extern F_U_003DE8F0 D_00142CA0[];
extern s32 D_00142668[];
extern s32 D_U_001DA868[2];
extern char D_U_001D95A0[];
extern R_U_003DE8F0 *func_U_0037E0B8(M_U_003DE8F0 *);
extern s32 func_U_003894A0(s32, s32, f32);
extern f32 func_U_00388960(f32);
extern s32 func_U_003E1E50(s32, f32, f32);
extern s32 func_U_003E2C88(s32, f32, f32);
extern s32 func_U_003E24B0(s32, s32);
extern s32 func_U_003E28E0(s32, s32);
extern s32 func_U_003E22D0(s32, s32, s32);
extern s32 func_U_003E2808(s32, s32);
extern s32 func_U_003E2618(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_0011B2E8(void *, char *, s32);
__asm__(".extern D_U_001D9590, 4");
__asm__(".extern D_U_001D9598, 4");
extern void func_U_003DFB20(f32 *, f32);
extern s32 func_U_003DE8E0(s32);
void func_U_003DE8F0(void) {
    s32 current = D_001A4BE0[0].x2850;
    s32 maximum;
    s32 initial;
    s32 ones, tens, hundreds, showHundreds, digit, color;
    f32 bar0, bar1, x0, y, x1;
    f32 start, left, pulse, health, capacity, first, center, fade;
    if ((u8)(D_001A4BE0[0].x25E4 ^ 1) == 0) initial = 4;
    else initial = D_00142668[0];
    maximum = initial;
    if (D_001A4BE0[0].x25C4 == 0x31 && D_001A4BE0[0].x19E0 &&
        (D_001A4BE0[0].x19E0->xAA == 0x1A17 || D_001A4BE0[0].x19E0->xAA == 0x107E)) {
        R_U_003DE8F0 *r = func_U_0037E0B8(D_001A4BE0[0].x19E0);
        if (r) {
            current = (s32)(r->f0 * 100.0f / r->h4);
            maximum = 100;
        }
    }
    health = current;
    capacity = maximum;
    if (D_00142CA0[0].x20 == 0) {
        bar0 = health / capacity * 0.230333f;
        func_U_003DFB20(&bar0, 0.230333f);
        func_U_003E2C88(0x9000A, 0.230333f - bar0, 0.0493329987f);
        func_U_003E1E50(0x9000A, 0.615581036f, 0.0739995018f);
        func_U_003E2C88(0x9000B, bar0, 0.0493329987f);
        func_U_003E1E50(0x9000B, 0.385248005f, 0.0739995018f);
        func_U_003E24B0(0x90008, 0);
    } else {
        bar1 = health / capacity * 0.226833001f;
        func_U_003DFB20(&bar1, 0.226833001f);
        func_U_003E2C88(0x9000A, 0.226833001f - bar1, 0.0493329987f);
        func_U_003E1E50(0x9000A, 0.587747991f, 0.0739995018f);
        func_U_003E2C88(0x9000B, bar1, 0.0493329987f);
        func_U_003E1E50(0x9000B, 0.360915005f, 0.0739995018f);
        func_U_003E24B0(0x90008, 1);
        func_U_003E1E50(0x90008, 0.598917007f, 0.074000001f);
    }
    digit = current / 10;
    ones = func_U_003DE8E0(current % 10);
    tens = func_U_003DE8E0(digit % 10);
    digit = (current / 100) % 10;
    showHundreds = digit != 0;
    hundreds = func_U_003DE8E0(digit);
    func_U_003E28E0(0x90003, ones);
    func_U_003E28E0(0x90004, tens);
    func_U_003E28E0(0x90005, hundreds);
    func_U_003E22D0(0x90005, 1, showHundreds);
    start = 0.0900000036f;
    if (showHundreds) start = 0.135000005f;
    func_0011B2E8(D_U_001DA868, D_U_001D95A0, maximum);
    x0 = 0.0f;
    x1 = 0.0f;
    func_U_003E2618(0x90006, &x0, &y, &x1, &y);
    first = x0;
    pulse = start + (x1 - first);
    center = 0.5f;
    if (D_00142CA0[0].x20) center = 0.475f;
    left = center - pulse * 0.5f;
    if (showHundreds) {
        func_U_003E1E50(0x90005, left, 0.074000001f);
        left += 0.045f;
    }
    func_U_003E1E50(0x90004, left, 0.074000001f);
    left += 0.045f;
    func_U_003E1E50(0x90003, left, 0.074000001f);
    func_U_003E1E50(0x90006, left + 0.045f, 0.0689999983f);
    if (health < capacity * 0.15f) {
        D_U_001D9598 += 0.05f;
        if (D_U_001D9598 >= 2.0f) D_U_001D9598 -= 2.0f;
        D_U_001D9590++;
    } else {
        if (D_U_001D9598 > 1.0f) D_U_001D9598 = 2.0f - D_U_001D9598;
        D_U_001D9598 *= 0.95f;
    }
    if (D_U_001D9598 > 1.0f) fade = 2.0f - D_U_001D9598;
    else fade = D_U_001D9598;
    color = func_U_003894A0(0x8066CCFF, 0x60202080, (1.0f - func_U_00388960(fade * 3.14159274f)) * 0.5f);
    func_U_003E2808(0x90003, color);
    func_U_003E2808(0x90004, color);
    func_U_003E2808(0x90005, color);
    func_U_003E2808(0x90006, color);
}
/* localdecomp:end func_U_003DE8F0 */
