#include "common.h"

/* NTSC-U counterpart of func_003BDB58. Uses the period in 60 Hz frames. */
/* localdecomp:start func_U_003BDA80 */
typedef struct {
    u8 pad[0x78];
    s32 color;
} ColorPulse_003BDA80;

extern s32 D_U_001D9D80;
extern f32 func_U_0038D3D8(f32);
extern s32 func_U_0038DF00(s32, s32, f32);

void func_U_003BDA80(ColorPulse_003BDA80 *p, s32 b, s32 g, s32 r, s32 a, s32 db, s32 dg, s32 dr, s32 period) {
    f32 v = func_U_0038D3D8(((f32)(D_U_001D9D80 % period) / (f32)period) * 2.0f * 3.1415927f + -3.1415927f);
    r += (s32)(v * dr) + dr / 2;
    g += (s32)(v * dg) + dg / 2;
    b += (s32)(v * db) + db / 2;
    p->color = func_U_0038DF00(p->color, (a << 24) | (r << 16) | (g << 8) | b, 0.05f);
}
/* localdecomp:end func_U_003BDA80 */
