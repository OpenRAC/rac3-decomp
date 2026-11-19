/* func_L32_003BE5E0: 50 diff with the file's flags. Needs the f32 D_ globals declared const (store/load scheduling) and u16 v. Remaining: first null tests (retail beqz/beqz/beql, mine beql/beql/beqz), the f4/f3 float register choice for the func_L03_0034B440 result and t, the lwc1 D_001DF1A0 in both delay slots of the || (retail), and the first lh in the lq/sq branch (retail beql). */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
extern const f32 D_L32_001DF1A8; __asm__(".extern D_L32_001DF1A8, 4");
extern const f32 D_L32_001DF1A4; __asm__(".extern D_L32_001DF1A4, 4");
extern const f32 D_L32_001DF1AC; __asm__(".extern D_L32_001DF1AC, 4");
extern const f32 D_L32_001DF1C4; __asm__(".extern D_L32_001DF1C4, 4");
extern const f32 D_L32_001DF18C; __asm__(".extern D_L32_001DF18C, 4");
extern const f32 D_L32_001DF188; __asm__(".extern D_L32_001DF188, 4");
extern s32 D_L32_001DF178; __asm__(".extern D_L32_001DF178, 4");
extern s32 D_L32_001DF17C; __asm__(".extern D_L32_001DF17C, 4");
extern const f32 D_L32_001DF1A0; __asm__(".extern D_L32_001DF1A0, 4");
extern const f32 D_L32_001DF19C; __asm__(".extern D_L32_001DF19C, 4");
extern const f32 D_L32_001DF1B0; __asm__(".extern D_L32_001DF1B0, 4");
extern const f32 D_L32_001DF198; __asm__(".extern D_L32_001DF198, 4");
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
                *(f32 *)(a0 + 0x10) += func_003824E0(-t, t);
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

INCLUDE_ASM("asm/levels", func_L32_003BE5E0);
