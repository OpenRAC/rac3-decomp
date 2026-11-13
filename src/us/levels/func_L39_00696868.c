#include "common.h"

/* NTSC-U counterpart of func_L39_00698F78 (src/levels/39_multiplayer_menu/L39_00698F78.c) */
/* localdecomp:start func_L39_00696868 */
extern void func_L39_006858B8(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);

void func_L39_00696868(u8 *arg0)
{
    s32 v[4];

    if (arg0[0x2B4]) {
        func_L39_006858B8(arg0, v, v, v, v, v, 0.5f, 0.5f, 1.7f, 1.0f, *(f32 *)(arg0 + 0x2B0));
    } else {
        func_L39_006858B8(arg0, v, v, v, v, v, 0.5f, 0.5f, 1.0f, 1.0f, *(f32 *)(arg0 + 0x2B0));
    }
}
/* localdecomp:end func_L39_00696868 */
