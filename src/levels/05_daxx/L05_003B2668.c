#include "common.h"

/* localdecomp:start func_L05_003B2668 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L05_003B27F8(u8 *, f32, f32, f32, s32);

void func_L05_003B2668(u8 *p) {
    u8 *s = *(u8 **)(p + 0x68);
    f32 f;
    f32 sn;
    f32 cs;
    f32 a;
    f32 b;
    u8 idx;

    f = *(f32 *)(s + 0x29C);
    *(f32 *)(s + 0x29C) = f + (f > 0.8f ? 0.02f : 0.08f);
    if (*(f32 *)(s + 0x29C) > 0.95f) {
        *(f32 *)(s + 0x29C) = 0.95f;
    }
    sn = func_0038D0B0(*(f32 *)(s + 0x29C) * 3.1415927f * 0.5f);
    cs = func_0038D098(*(f32 *)(s + 0x29C) * 3.1415927f * 0.5f);
    cs = 1.0f - cs;
    idx = (s32)((1.0f - cs) * 128.0f);
    b = sn * 0.6f + -0.3f + 1.0f;
    a = sn * 10.0f + 5.0f;
    func_L05_003B27F8(p, a, 0.0f, -0.2617994f, idx);
    func_L05_003B27F8(p, a * b, 0.61086524f, -0.2617994f, idx);
}
/* localdecomp:end func_L05_003B2668 */

INCLUDE_ASM("asm/levels", func_L05_003B27F8);

INCLUDE_ASM("asm/levels", func_L05_003B29D0);

/* localdecomp:start func_L05_003B2E40 */
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L05_003B2E40(u8 *p) {
    s32 r;
    s32 a;

    a = 0;
    if (*(u8 *)(*(u8 **)(p + 0x68) + 0x2B8) < 3) {
        a = 3 - *(u8 *)(*(u8 **)(p + 0x68) + 0x2B8);
    }
    r = func_00382498(a, 2);
    switch (r) {
    case 0:
        func_L01_004450F0((s32) p, 9, -1);
        return;
    case 1:
        func_L01_004450F0((s32) p, 0xC, -1);
        return;
    case 2:
        func_L01_004450F0((s32) p, 0xF, -1);
        return;
    }
}
/* localdecomp:end func_L05_003B2E40 */

INCLUDE_ASM("asm/levels", func_L05_003B2EF0);
