/* PAL retail reconstruction, P08 wave 3.
 * Stock check.py: 356 positional differences with the owner's unchanged
 * -O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as flags.
 * Remaining: 0x70 versus 0x60 frame, cached hero-address lifetime,
 * saved-register allocation, loop/store scheduling and division padding.
 * No divs_nops row currently exists for this function.
 * The s32 signature follows the owner's earlier prototype, whose caller ignores
 * the result; no return value is established on every retail exit.
 * The owning INCLUDE_ASM remains. Full PAL/US linkage is not verified.
 */
#include "common.h"
#include "vu0.h"
extern u8 D_001DE970_sda;
extern s32 D_001DE96C_sda;
extern s32 D_001DFC40_sda;
extern u8 *D_001E015C_sda;
__asm__(".extern D_001DE970_sda, 1");
__asm__(".extern D_001DE96C_sda, 4");
__asm__(".extern D_001DFC40_sda, 4");
__asm__(".extern D_001E015C_sda, 4");
extern u8 *D_L16_001E015C;
extern s32 D_L16_001DFC40;
extern u8 D_001A4BE0_003CB420[] __asm__("D_001A4BE0");
extern u8 D_L16_001E2B80[];
extern void func_L16_003CBA28();
extern s32 func_L01_00447490();
extern s32 func_L01_0044CE88();
extern void func_003C4A40();
extern s32 func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_004443E8();
extern void func_0038D000(void *, void *, void *);
extern void func_L02_003FB148(s32, s32, f32);
extern void func_L01_0044ABD0();
extern void func_L01_0044E820();
extern void func_L01_00404A10();
extern u8 *func_003C4D58(void *);
s32 func_L16_003CB420(void *raw) {
    u8 *a0 = raw;
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *hit;
    u8 *node;
    u8 *hero = D_001A4BE0_003CB420;
    f32 ratio;
    f32 best;
    f32 distance;
    s32 side;
    s32 index;
    s32 i;
    if (a0[0x20] == 0) func_L16_003CBA28(a0);
    if (!D_001DE970_sda && a0[0x95]) {
        D_001DE970_sda = 1;
        D_001DE96C_sda++;
    }
    hit = (u8 *)func_L01_00447490(a0, -1, 0);
    if (hit) {
        if (D_001DFC40_sda >= *(s32 *)(s + 0x19C) &&
            a0[0x20] != 11 && a0[0x95] != 3 && a0[0x95] != 0) {
            if (*(s32 *)(hit + 0x20))
                s[0x57] = func_L01_0044CE88(*(s32 *)(hit + 0x20));
            *(f32 *)(s + 0x40) -= *(f32 *)(hit + 0x2C);
            s[0x37] = 0xFF;
            *(s32 *)(s + 0x19C) = D_L16_001DFC40 + 8;
            func_003C4A40(a0, s + 0x30);
            *(f32 *)(s + 0x1A0) += *(f32 *)(hit + 0x2C);
            if (*(f32 *)(s + 0x1A0) >= (f32)*(s16 *)(s + 0x44) / 10.0f) {
                func_L01_004450F0(a0, 11, -1);
                *(f32 *)(s + 0x1A0) = -1000.0f;
            }
        }
        a0[0xA8] = 0xFF;
    }
    if ((D_L16_001DFC40 & 31) == (((s32)a0 >> 8) & 31) &&
        a0[0x20] != 8 && a0[0x20] != 9) {
        side = -1;
        index = -1;
        best = 1000000.0f;
        for (i = 0; i < 3; i++) {
            distance = func_L01_0040E570(a0 + 0x10,
                D_L16_001E015C + (((s32 *)(s + 0x1F0))[i] << 8) + 0x10);
            if (distance < best) { best = distance; side = 0; index = i; }
            distance = func_L01_0040E570(a0 + 0x10,
                D_L16_001E015C + (((s32 *)(s + 0x1FC))[i] << 8) + 0x10);
            if (distance < best) { best = distance; side = 1; index = i; }
        }
        if (best > 400.0f) {
            *(s16 *)(s + 0x218) = side;
            *(s16 *)(s + 0x21A) = index;
            func_L01_004450F0(a0, 6, -1);
        }
    }
    ratio = *(f32 *)(s + 0x40) / (f32)*(s16 *)(s + 0x44);
    if (ratio <= 0.0f) {
        if (*(s32 *)(s + 0x1BC) == 0) {
            if (a0[0x95] != 3) func_L01_004443E8(a0, 0x200, 3);
            func_L01_004450F0(a0, 12, 3);
        } else {
            func_L01_004450F0(a0, 4, -1);
        }
    }
    if (ratio > 0.666f) *(s32 *)(s + 0x190) = 1;
    else if (ratio > 0.333f) *(s32 *)(s + 0x190) = 2;
    else *(s32 *)(s + 0x190) = 3;
    if (*(s32 *)(s + 0x1BC) == 2) {
        if (*(s16 *)(s + 0x218)) i = ((s32 *)(s + 0x1FC))[*(s16 *)(s + 0x21A)];
        else i = ((s32 *)(s + 0x1F0))[*(s16 *)(s + 0x21A)];
        node = D_001E015C_sda + (i << 8);
        func_0038D000(s + 0x260, s + 0x250, node + 0xC0);
        vec_add_ab(s + 0x260, s + 0x260, node + 0x10);
    }
    if (*(s32 *)(hero + 0x2850) < *(s32 *)(s + 0x220) && *(s32 *)(s + 0x1E4) <= 0)
        *(s32 *)(s + 0x224) = 1;
    *(s32 *)(s + 0x220) = *(s32 *)(hero + 0x2850);
    if (a0[0x95] != 0 && a0[0x95] != 3) {
        func_L02_003FB148(4, 0, ratio < 0.0f ? 0.0f : ratio);
        if (*(s32 *)(D_L16_001E2B80 + 0x144) == 0) {
            *(s32 *)(D_L16_001E2B80 + 0x148) = 0;
            *(u8 **)(D_L16_001E2B80 + 0x144) = a0;
        }
    } else if (*(u8 **)(D_L16_001E2B80 + 0x144) == a0) {
        *(s32 *)(D_L16_001E2B80 + 0x144) = 0;
    }
    func_L01_0044ABD0(a0, s + 0x30);
    if (*(s16 *)(s + 0x30) == 0) func_L01_0044E820(a0, *(s32 *)(s + 0x20C));
    func_L01_00404A10(a0, 3);
    qzero(s + 0x2D0);
    qzero(s + 0x350);
    *(s32 *)(s + 0x180) = *(s32 *)(hero + 0x25C0);
    *(s16 *)(s + 0x184) = 1;
    if (*(s32 *)(s + 0x108)) *(s32 *)(s + 0x1A4) = *(s32 *)(s + 0x108);
    if (*(s32 *)(s + 0x1A4)) {
        for (i = 0; i < 3; i++) {
            if (*(u8 **)(hero + 0x35C) == D_L16_001E015C + (((s32 *)(s + 0x1F0))[i] << 8)) {
                *(s16 *)(s + 0x214) = 0; *(s16 *)(s + 0x216) = i;
            } else if (*(u8 **)(hero + 0x35C) == D_L16_001E015C + (((s32 *)(s + 0x1FC))[i] << 8)) {
                *(s16 *)(s + 0x214) = 1; *(s16 *)(s + 0x216) = i;
            }
            if (*(u8 **)(s + 0x1A4) == D_L16_001E015C + (((s32 *)(s + 0x1F0))[i] << 8)) {
                *(s16 *)(s + 0x210) = 0; *(s16 *)(s + 0x212) = i;
            } else if (*(u8 **)(s + 0x1A4) == D_L16_001E015C + (((s32 *)(s + 0x1FC))[i] << 8)) {
                *(s16 *)(s + 0x210) = 1; *(s16 *)(s + 0x212) = i;
            }
        }
        if (*(s16 *)(s + 0x21A) == -1) *(s16 *)(s + 0x21A) = *(u16 *)(s + 0x212);
        if (*(s16 *)(s + 0x218) == -1) *(s16 *)(s + 0x218) = *(u16 *)(s + 0x210);
        node = func_003C4D58(*(void **)(s + 0x1A4));
        if (node) *(vu0_q *)(s + 0x240) = *(vu0_q *)(node + 0x10);
        if (*(s32 *)(s + 0x1A8) != *(s32 *)(s + 0x1A4)) {
            *(s32 *)(s + 0x1A8) = *(s32 *)(s + 0x1A4);
            *(s32 *)(s + 0x1AC) = 0;
        }
    }
}
