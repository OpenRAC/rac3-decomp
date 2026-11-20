#include "common.h"

/* NTSC-U counterpart of func_003829D8 (src/boot_elf/text/382848.c): the period is frames itself, not (frames * 5 + 2) / 6 */
/* localdecomp:start func_U_003829F8 */
/* the same code as NTSC-U frontbin's func_U_0037E368 */
extern s32 D_U_001D9AA8[2];
extern s32 D_U_001D9AB0[2];
extern s32 D_U_001D9D88;
extern f32 func_U_0038D3C0(f32);
extern s32 func_U_0038DF00(s32, s32, f32);
__asm__(".extern D_U_001D9D88, 16");

u32 func_U_003829F8(u32 a, u32 b, s32 frames, s32 idx, s32 reset, s32 mode) {
    s32 *last = &D_U_001D9AB0[idx];
    s32 *count = &D_U_001D9AA8[idx];
    s32 n;
    s32 m;
    f32 t;

    if (*last != D_U_001D9D88) {
        *last = D_U_001D9D88;
        (*count)++;
    }
    if (reset) {
        *count = 0;
    }
    n = frames;
    switch (mode) {
    case 0:
        m = *count % (n * 2);
        if (m >= n) {
            t = 1.0f - (f32)(m - n) / (f32)n;
        } else {
            t = (f32)m / (f32)n;
        }
        break;
    case 1:
        t = func_U_0038D3C0((f32)(*count % n) / (f32)n * 3.1415925f);
        t = t * t;
        t = t * t;
        break;
    default:
        t = 0.5f;
        break;
    }
    return func_U_0038DF00(b, a, t);
}
/* localdecomp:end func_U_003829F8 */
