/* func_L32_003BE5E0: 34 diff with the file's flags (b37 W12; was 38 in W8 and 50 originally). The block's extern in func_L32_003BE830 must read `(u8 *, u8 *)` to compile. Levers: both loads (p, a1->4) before the null test (`q = *(a1+4); if (p == 0 || q == 0) return;`: retail's three tests now match, reorg puts the lw in the delay slot) and D_L32_001DF1A8/1A4 NOT const (const let sched1 hoist their lwc1 above the lq/sq). Separate the random-amplitude local from the later velocity local so the call result uses $f4. Remaining: the FP register choices and scheduling downstream of the velocity adjustment, and the lwc1 D_001DF1A0 in both delay slots of the || (retail: it is the then-block's first instruction, plain bc1t/bc1f; mine bc1tl/bc1fl with lwc1 0x10($s1) first). Tried (38 each): const toggles of every other D_, nested ifs, `k = D_L32_001DF1A0` temp, swapped operands of the <, flag variable (87), goto form, extra f3 copy. */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L32_001DF1A8; __asm__(".extern D_L32_001DF1A8, 4");
extern f32 D_L32_001DF1A4; __asm__(".extern D_L32_001DF1A4, 4");
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
    u8 *q;
    f32 f21, f20, d, t, f4, amplitude;
    u16 v;
    if (a1 == 0) return;
    p = *(u8 **)a1;
    q = *(u8 **)(a1 + 4);
    if (p == 0 || q == 0) return;
            if (*(u16 *)(a1 + 0xA) & 1) {
                *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x10);
                *(f32 *)(a1 + 0x10) = func_003824E0(D_L32_001DF1A8, D_L32_001DF1A4);
                amplitude = D_L32_001DF1AC;
                *(f32 *)(a1 + 0x14) = func_003824E0(-amplitude, amplitude);
                amplitude = D_L32_001DF1C4;
                *(f32 *)(a0 + 0x10) += func_003824E0(-amplitude, amplitude);
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
