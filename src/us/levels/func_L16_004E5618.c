#include "common.h"

/* NTSC-U counterpart of func_L16_004E9558 (src/levels/16_kerwan/L16_004E9558.c) */
/* localdecomp:start func_L16_004E5618 */
extern s32 D_L16_001DFC40_004E5618;
__asm__(".extern D_L16_001DFC40_004E5618, 16");
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);

void func_L16_004E5618(u8 *obj, s32 r, s32 g, s32 b, s32 a, s32 dr, s32 dg, s32 db, s32 period)
{
    s32 n = period;
    f32 s = func_00388978((f32)(D_L16_001DFC40_004E5618 % n) / (f32)n * 2.0f * 3.1415927f + -3.1415927f);

    b += (s32)(s * db) + db / 2;
    g += (s32)(s * dg) + dg / 2;
    r += (s32)(s * dr) + dr / 2;
    *(s32 *)(obj + 0x78) = func_003894A0(*(s32 *)(obj + 0x78), (a << 24) | (b << 16) | (g << 8) | r, 0.05f);
}
/* localdecomp:end func_L16_004E5618 */
