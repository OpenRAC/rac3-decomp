/* PAL near miss (Codex wave 11): near miss: 208 words differ in its file's context with the file's flags.
 * Replaces the earlier draft (Codex wave 6 near miss: 211 words differ under tools/check.py in its file's context with the file's flags, measured 2026-11-21;
 * this one: 208).
 * Worker's note: 208 diff, 12 bytes short (W/func_L32_003BE098.checks/level_32.log): the file has no @ps2as, so li.s 1.5707964f becomes a gp literal-pool lwc1 (retail lui/ori/mtc1); the fractional part now uses the vu0.h cvtsw_asm(cvtws_asm()) helpers (retail's in-FPU cvt.w.s/cvt.s.w, the file's only such site); still m is spilled to the stack and the hoisted 0xC row offset takes fp where retail keeps m in fp (the near tie the draft note measures), which shifts the stack slots and the inner loop; needs @ps2as on L32_003BE008.c's line before the allocation tie is worth more work
 */
#include "common.h"

/* localdecomp:start func_L32_003BE098 */
#include "vu0.h"
extern s32 D_L32_001DF1C8;
extern s32 D_L32_001DF1D4;
extern s32 D_L32_001DF1D0;
extern f32 D_L32_001DF310[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF280[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF328[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF268[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF2C8[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF2B0[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF250[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF298[] __attribute__((section(".sdata")));
extern f32 D_L32_001DF2E0[] __attribute__((section(".sdata")));
extern u32 D_L32_001DF200[] __attribute__((section(".sdata")));
extern u32 D_L32_001DF2F8[] __attribute__((section(".sdata")));
extern u32 D_L32_001DF1E8[] __attribute__((section(".sdata")));
__asm__(".extern D_L32_001DF1C8, 4");
__asm__(".extern D_L32_001DF1D4, 4");
__asm__(".extern D_L32_001DF1D0, 4");
__asm__(".extern D_L32_001DF310, 4");
__asm__(".extern D_L32_001DF280, 4");
__asm__(".extern D_L32_001DF328, 4");
__asm__(".extern D_L32_001DF268, 4");
__asm__(".extern D_L32_001DF2C8, 4");
__asm__(".extern D_L32_001DF2B0, 4");
__asm__(".extern D_L32_001DF250, 4");
__asm__(".extern D_L32_001DF298, 4");
__asm__(".extern D_L32_001DF2E0, 4");
__asm__(".extern D_L32_001DF200, 4");
__asm__(".extern D_L32_001DF2F8, 4");
__asm__(".extern D_L32_001DF1E8, 4");
extern f32 D_L32_002A5260[16][3];
extern f32 D_L32_002A5320[16][2];
extern u32 D_L32_001E25B0[16];
void func_L32_003BE098(void *arg) {
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern s32 func_00389598(u32);
    extern void func_003A9440(s32, unsigned long);
    extern void func_0038C750(void);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    u8 *m = arg;
    u8 *p = *(u8 **)(m + 0x68);
    f32 *phases;
    f32 fade;
    f32 t, angle, value, phase;
    s32 i, n;
    u32 color;
    if (*(s32 *)(p + 4) < D_L32_001DF1C8 - D_L32_001DF1D4) {
        if (*(s32 *)(p + 4) < D_L32_001DF1D0) fade = (f32)*(s32 *)(p + 4) / (f32)D_L32_001DF1D0;
        else fade = 1.0f;
    } else fade = (f32)(D_L32_001DF1C8 - *(s32 *)(p + 4)) / (f32)D_L32_001DF1D4;
    phases = (f32 *)(p + 0x14);
    for (i = 0; i < 5; i++) {
        for (n = 0; n < 16; n += 2) {
            D_L32_002A5260[n+1][0] = D_L32_002A5260[n][0] = *(f32 *)(m + 0x10) + D_L32_001DF328[i];
            D_L32_002A5260[n+1][1] = D_L32_002A5260[n][1] = *(f32 *)(m + 0x14) + D_L32_001DF268[i];
            t = n * 0.0625f;
            angle = t * 1.5707963705062866f;
            value = func_0038D0B0(angle);
            D_L32_002A5260[n+1][2] = D_L32_002A5260[n][2] = *(f32 *)(m + 0x18) + fade * D_L32_001DF250[i] * value;
            D_L32_002A5260[n][0] -= D_L32_001DF310[i] * func_0038D098(angle);
            value = func_0038D098(angle);
            D_L32_002A5260[n+1][0] += D_L32_001DF310[i] * value;
            color = (D_L32_001DF200[i] & 0xFFFFFF) | ((s32)((1.0f - t) * 128.0f) << 24);
            D_L32_001E25B0[n] = D_L32_001E25B0[n+1] = color;
            phase = phases[i] + D_L32_001DF2C8[i];
            phases[i] = phase - cvtsw_asm(cvtws_asm(phase));
            D_L32_002A5320[n][0] = D_L32_001DF298[i];
            D_L32_002A5320[n+1][0] = D_L32_001DF298[i] + D_L32_001DF2E0[i];
            D_L32_002A5320[n+1][1] = D_L32_002A5320[n][1] = phases[i] + D_L32_001DF2B0[i] + t * D_L32_001DF280[i];
        }
        func_003A9440(6, func_00389598(D_L32_001DF2F8[i]));
        func_003A9440(8, 0);
        if (D_L32_001DF1E8[i]) func_003A9440(0x42, ((unsigned long)0x8000 << 24) | 0x44);
        else func_003A9440(0x42, ((unsigned long)0x8000 << 24) | 0x48);
        func_0038C750();
        func_003D3A24(16, D_L32_002A5260, D_L32_001E25B0, D_L32_002A5320, 1);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L32_003BE098 */
