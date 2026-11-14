#include "common.h"

/* NTSC-U counterpart of func_L10_003B57A8 (src/levels/10_zeldrin_starport/L10_003B4350.c): 50 -> 60 */
extern s32 D_L10_001E04A0;
extern f32 D_L10_001E04A4;
static __inline__ s32 scale_3B5690(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)((f32)(s32)v * D_L10_001E04A4 + 0.5f + (D_L10_001E04A0 == 1 ? z0 : z1));
}


/* localdecomp:start func_L10_003B3798 */
__asm__(".extern D_L10_001DE778_003B3798, 4");
extern s32 D_L10_001DE778_003B3798;
extern void func_00387C78(s32, s32, s32, s32, s32, s32);
extern void func_L01_00432FE8(s32, s32, f32, f32, f32, f32);
extern void func_L10_003B3680(u8 *, s32, f32, f32, f32, f32);

void func_L10_003B3798(void) {
    s32 t = D_L10_001DE778_003B3798;
    s32 m;
    s32 fr;
    f32 f;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;
    f32 w;
    f32 g;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;

    m = t / 60;
    fr = (t - m * 60) * 100;
    fr = fr / 60;
    if (m >= 100) {
        m = 99;
    }
    f = 0.0f;
    if (fr > 80) {
        f = (f32)(fr - 80) / 20.0f;
    }
    d0 = m % 10;
    d1 = m / 10 % 10;
    d2 = fr / 10 % 10;
    d3 = fr % 10;
    func_00387C78(scale_3B5690(71.0f), scale_3B5690(105.0f), 200, 307, 30, 0);
    func_L01_00432FE8(0x60, 0x462299DE, (f32)scale_3B5690(71.0f), (f32)scale_3B5690(105.0f), 200.0f, 307.0f);
    y0 = 251.0f;
    y1 = 255.0f;
    func_L10_003B3680((u8 *)0, 0x802020D0, 82.0f, 86.0f, y0, y1);
    func_L10_003B3680((u8 *)0, 0x802020D0, 92.0f, 96.0f, y0, y1);
    g = f + f;
    y1 = 250.0f - f;
    x0 = 75.0f - f * 3.0f;
    x1 = f * 3.0f + 103.0f;
    y0 = (y1 - 22.0f) - g;
    func_L10_003B3680((u8 *)d0, 0x802020D0, x0, x1, y0, y1);
    y1 = (y0 - 2.0f) - f;
    func_L10_003B3680((u8 *)d1, 0x802020D0, x0, x1, (y1 - 22.0f) - g, y1);
    y0 = f + 258.0f;
    y1 = (y0 + 22.0f) + g;
    func_L10_003B3680((u8 *)d2, 0x802020D0, x0, x1, y0, y1);
    y0 = (y1 + 2.0f) + f;
    func_L10_003B3680((u8 *)d3, 0x802020D0, x0, x1, y0, (y0 + 22.0f) + g);
}
/* localdecomp:end func_L10_003B3798 */
