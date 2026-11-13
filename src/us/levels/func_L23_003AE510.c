#include "common.h"

/* NTSC-U counterpart of func_L23_003AFE10 (src/levels/23_holostar_studios_clank/L23_003AD800.c): 200 -> 240 */
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_L23_003AE510 */
extern f32 D_L23_001DE264;
__asm__(".extern D_L23_001DE264, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L03_0043C598(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004412D0(void *, s32, s32);

void func_L23_003AE510(u8 *o)
{
    u8 *v = *(u8 **)(o + 0x68);
    f32 d[4];

    d[0] = func_0038D098(*(f32 *)(v + 0x2B4)) *
           (D_L23_001DE264 < *(f32 *)(v + 0x2B8) ? D_L23_001DE264 * 0.5f : *(f32 *)(v + 0x2B8) * 0.5f);
    d[1] = func_0038D0B0(*(f32 *)(v + 0x2B4)) *
           (D_L23_001DE264 < *(f32 *)(v + 0x2B8) ? D_L23_001DE264 * 0.5f : *(f32 *)(v + 0x2B8) * 0.5f);
    d[2] = 0.0f;
    func_003A52A0(0, 0, o);
    func_L03_0043C598((s32)o, 0x3FF, (u8 *)d, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 1.0f);
    *(s32 *)(v + 0x210) = 240;
    *(s32 *)(v + 0x228) = 0;
    *(s32 *)(v + 0x244) = 0;
    if (*(s32 *)(v + 0x2B0) == 0)
        func_L01_004412D0(o, 0, 3);
    func_L01_0032FE90(o + 0x10, 1, 10, 20, 0, 4, 20, 2, 2.0f, 0.0f, 0.0f, 0.0f,
                      1, 1, 1, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L23_003AE510 */
