#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003000F8 */
extern s32 func_L01_003F7EE8(u8 *);
extern s32 func_00382468(s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(void *);
extern f32 func_0038CE68(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 D_L01_001DFB50;
extern u8 D_L01_001E29E0[];
void func_L01_003000F8(u8 *o) {
    u8 *p;
    f32 f;
    s32 c;
    u32 w;
    s32 h;
    u32 t;
    p = *(u8 **)(o + 104);
    switch (o[32]) {
    case 0:
        if (func_L01_003F7EE8(o) != 0 || (0.8f < D_L01_001DFB50 && func_00382468(10) == 0)) {
            func_L01_004450F0(o, 1, -1);
            *(u16 *)(o + 52) |= 0x2800;
        }
        break;
    case 1:
        func_L01_003F7EE8(o);
        t = o[35];
        if (t < 2) {
            func_003C2880(o);
            return;
        }
        o[35] = t - 2;
        break;
    }
    f = fabs_asm(func_0038CE68(o + 192, D_L01_001E29E0));
    f = f * (f * f * f * f);
    if (*(u16 *)(o + 150) != 0) {
        h = *(u16 *)(o + 150);
        f = (f32)(10 - abs_asm(h - 10)) * 0.1f;
        *(u16 *)(o + 150) -= 1;
    } else if (func_00382468(45) == 0) {
        *(u16 *)(o + 150) = 20;
    }
    w = *(u32 *)(p + 80);
    if ((w >> 24) != 0)
        f = f * 0.8f;
    c = func_0038DBD8(w, -1, f);
    {
        s32 b = (c >> 16) & 255;
        func_L01_0043B9E8(o, c & 255, (c >> 8) & 255, b);
    }
}
/* localdecomp:end func_L01_003000F8 */
