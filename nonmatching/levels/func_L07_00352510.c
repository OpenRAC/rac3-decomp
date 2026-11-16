/*
 * PAL near miss, P02 wave 2, 2026-11-16.
 * Owner: src/levels/07_annihilation_nation/L07_00351C58.c.
 * Exact flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 16 differing instructions after two formulations.
 * Remaining differences: repeated float stores and callback/byte-store scheduling.
 * No flags or metadata changed. Uses the stock owning-file context.
 * Preserved as a bounded draft, not a match; further tuning remains possible.
 */
#include "common.h"
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L07_00352A88(s32);
extern void func_L07_00352A58(s32);
void func_L07_00352510(u8 *obj)
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
    if (kind == 1 || kind == 3) func_L01_00446058(obj, 0x1D8B, 0x1769);
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.25f;
    p[9] = p[0xF] = 0;
    v[0xB8] = 255;
    v[0x80] = 5;
    *(f32 *)(v + 0x120) = 1.0f;
    *(s32 *)(v + 0x124) |= 1;
    *(f32 *)(v + 0x150) = 0.65f;
    *(f32 *)(v + 0x154) = *(f32 *)(v + 0xAC) = 0.15f;
    *(f32 *)(v + 0x15C) = *(f32 *)(v + 0xA0) =
        *(f32 *)(v + 0xA4) = *(f32 *)(v + 0x158) = 0.5f;
    *(f32 *)(v + 0x160) = 3.1415927f;
    *(f32 *)(v + 0x180) = 0.78539819f;
    *(f32 *)(v + 0x17C) = 0.00392f;
    *(f32 *)(v + 0x184) = 0.2f;
    func_L01_0045BD78(obj, 0.0032000002f, 0.050000004f, 0.0050265486f, 0.12566371f);
    *(s32 *)(v + 0x460) = 0;
    *(void **)(v + 0x244) = func_L07_00352A88;
    *(void **)(v + 0x248) = func_L07_00352A58;
    v[0x25D] = 2;
    *(s16 *)(v + 0x24C) = -1;
    v[0x25F] = 7;
    func_L07_00352A58((s32)obj);
}
