/* functional: high. Read block by block against PAL asm; callee names checked in catalogue; result of the third random call is read before the add. Not byte-identical (flags/scheduling only). */

#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
extern const f32 D_L32_001DF1A8;
extern const f32 D_L32_001DF1A4;
extern const f32 D_L32_001DF1AC;
extern const f32 D_L32_001DF1C4;
extern const f32 D_L32_001DF18C;
extern const f32 D_L32_001DF188;
extern s32 D_L32_001DF178;
extern s32 D_L32_001DF17C;
extern const f32 D_L32_001DF1A0;
extern const f32 D_L32_001DF19C;
extern const f32 D_L32_001DF1B0;
extern const f32 D_L32_001DF198;
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L32_003BE5E0(u8 *a0, u8 *a1) {
    u8 *p;
    f32 f21, f20, d, t, f4;
    u16 v;
    if (a1 == 0) return;
    p = *(u8 **)a1;
    if (p == 0) return;
    if (*(u8 **)(a1 + 4) == 0) return;
            if (*(u16 *)(a1 + 0xA) & 1) {
                *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x10);
                *(f32 *)(a1 + 0x10) = func_003824E0(D_L32_001DF1A8, D_L32_001DF1A4);
                t = D_L32_001DF1AC;
                *(f32 *)(a1 + 0x14) = func_003824E0(-t, t);
                t = D_L32_001DF1C4;
                d = func_003824E0(-t, t);
                *(f32 *)(a0 + 0x10) += d;
                *(f32 *)(a0 + 0xC) = func_003824E0(D_L32_001DF18C, D_L32_001DF188);
                *(s32 *)(a0 + 4) = func_0038DBD8(D_L32_001DF178, D_L32_001DF17C, func_003824E0(0.0f, 1.0f));
            }
            f4 = func_L03_0034B440((f32)*(s16 *)(a0 + 0xA), (f32)*(s16 *)(a1 + 8), 1.0f, 1, 0, 0);
            if (*(f32 *)(p + 0x18) < *(f32 *)(a0 + 0x18) || *(f32 *)(a1 + 0x10) > 0.0f) {
                *(f32 *)(a1 + 0x10) -= D_L32_001DF1A0;
                *(f32 *)(a0 + 0x18) += *(f32 *)(a1 + 0x10);
            }
            t = *(f32 *)(a1 + 0x14);
            d = D_L32_001DF19C;
            if (!(t < 0.0f)) d = -d;
            t += d;
            *(f32 *)(a1 + 0x14) = t;
            *(s32 *)(a0 + 4) = (*(s32 *)(a0 + 4) & 0xFFFFFF) | ((s32)(D_L32_001DF1B0 * (1.0f - f4)) << 24);
            *(f32 *)(a0 + 0x10) += t;
            v = *(u16 *)(a1 + 0xE);
            f21 = D_L32_001DF198 * (f32)*(s16 *)(a1 + 8) * (f32)(v >> 8) * 0.00390625f;
            f20 = (f32)(v & 0xFF);
            *(u8 *)(a0 + 8) = (s32)func_003C4088(f20, f20 + (f20 + f21), func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), 0.0f));
}
