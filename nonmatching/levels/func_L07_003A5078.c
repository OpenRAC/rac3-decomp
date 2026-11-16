/*
 * PAL near miss, P02 wave 2, 2026-11-16.
 * Owner: src/levels/07_annihilation_nation/L07_003A46C8.c.
 * Exact flags: -O2 -G8 -fopt-stack -mno-check-zero-division
 *              -fno-sched-interblock @ps2as.
 * Stock checker: 30 differing instructions on the initial formulation.
 * Remaining differences: repeated float/color stores and callback-store scheduling.
 * No flags or metadata changed. Uses the stock owning-file context.
 * Preserved as a bounded draft, not a match; further tuning remains possible.
 */
#include "common.h"
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L07_003A5670(u8 *);
extern void func_L07_003A55D8(u8 *);
void func_L07_003A5078(u8 *obj)
{
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *p = v + 0x30;
    s32 kind = func_L07_003C1AF8();
    f32 scale = func_L07_003C1B40(kind);
    *(s16 *)(p + 4) = (s32)(*(s16 *)(v + 0x34) * scale);
    *(f32 *)(v + 0x30) = *(s16 *)(p + 4);
    p[0x14] = (s32)(v[0x44] * scale);
    p[0x15] = (s32)(v[0x45] * scale);
    p[0x16] = (s32)(v[0x46] * scale);
    if (kind == 1 || kind == 3) func_L01_00446058(obj, 0x1D8C, 0x195E);
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.25f;
    p[9] = 1;
    p[0xF] = 0;
    v[0x80] = 5;
    v[0x240] = 0xB0;
    v[0x241] = 0x50;
    v[0x242] = 0x80;
    v[0x244] = 0xE0;
    v[0xB8] = 255;
    *(f32 *)(v + 0x120) = 1.0f;
    *(s32 *)(v + 0x124) |= 1;
    *(f32 *)(v + 0x150) = 0.65f;
    *(f32 *)(v + 0x154) = 0.15f;
    *(f32 *)(v + 0x15C) = 0.5f;
    *(f32 *)(v + 0x160) = 3.1415927f;
    *(f32 *)(v + 0x180) = 0.78539819f;
    *(f32 *)(v + 0x17C) = 0.00392f;
    *(f32 *)(v + 0x184) = 0.2f;
    v[0x243] = 0xE0;
    *(f32 *)(v + 0xA0) = 0.5f;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0xAC) = 0.15f;
    *(f32 *)(v + 0x158) = 0.5f;
    func_L01_0045BD78(obj, 0.002f, 0.044000004f, 0.0050265486f, 0.12566371f);
    v[0x28D] = 5;
    *(s32 *)(v + 0x260) = 0;
    *(s32 *)(v + 0x498) = 0;
    *(s32 *)(v + 0x264) = 0;
    *(s32 *)(v + 0x494) = 0;
    *(void **)(v + 0x274) = func_L07_003A5670;
    *(void **)(v + 0x278) = func_L07_003A55D8;
    *(s16 *)(v + 0x27C) = -1;
    v[0x28F] = 7;
    func_L07_003A55D8(obj);
}
