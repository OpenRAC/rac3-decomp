#include "common.h"

/* NTSC-U timing counterpart of func_L07_003A6FC8. */
/* localdecomp:start func_L07_003A57F0 */
extern s32 func_00388398(void *);
extern f32 func_L01_00442070(f32);

void func_L07_003A57F0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 **q;
    s32 i;
    f32 t;
    u8 *o;

    if (arg1 != 0) {
        *(s32 *)(p + 0x158) = 0x50;
        return;
    }
    func_00388398(p + 0x158);
    t = (f32) * (s32 *)(p + 0x158) / 40.0f;
    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    func_L01_00442070(t);
    q = (u8 **)(p + 0x130);
    for (i = 8; i >= 0; i--) {
        o = *q;
        if (o != 0) {
            *(f32 *)(o + 0xC) = t * 210000.0f * 0.75f;
        }
        q++;
    }
}
/* localdecomp:end func_L07_003A57F0 */
