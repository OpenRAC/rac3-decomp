#include "common.h"

/* NTSC-U counterpart of func_L07_003A6110 (src/levels/07_annihilation_nation/L07_003A46C8.c) */
s32 func_L07_003A4950(void *, s32);
extern f32 func_003893C8(f32, f32);

/* localdecomp:start func_L07_003A4950 */
extern f32 func_00388800(void *, void *);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L03_0032F420(f32 *, f32 *, f32, f32);
extern s32 func_L07_00332AC0(s32, void *, void *);

s32 func_L07_003A4950(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 v[4];
    f32 d;
    f32 num = 1.8000001f;
    f32 a;
    f32 r;

    d = func_00388800((u8 *)arg0 + 0x10, p + 0x130);
    a = num / d;
    if (a > 3.14159274f) {
        a = 3.14159274f;
    }
    if (arg1 == 0) {
        r = func_003893C8(*(f32 *)(p + 0x280), a);
    } else {
        r = func_00389380(*(f32 *)(p + 0x280), a);
    }
    func_L03_0032F420(v, (f32 *)(p + 0x130), r, d);
    return func_L07_00332AC0(*(s32 *)(p + 0x270), arg0, v);
}
/* localdecomp:end func_L07_003A4950 */
