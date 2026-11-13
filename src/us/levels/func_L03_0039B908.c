#include "common.h"

/* NTSC-U counterpart of func_L03_0039D038 (src/levels/03_starship_phoenix/L03_0039C888.c) */
extern void func_L03_0039B908();
extern void func_L03_0039BC20();

/* localdecomp:start func_L03_0039B908 */
extern f32 func_0037E250(f32, f32);
extern void func_L03_0039BE18(u8 *, u8 *);
extern void func_L03_0039BC20(void *, void *);
extern void func_L01_00455E98(u8 *, u8 *, u8 *);
extern u8 D_001426E8[];
extern u8 *D_001A71A0[];

void func_L03_0039B908(u8 *a0) {
    u8 *p;
    f32 r;
    if (a0[0x20] == 0) {
        p = *(u8 **)(a0 + 0x68);
        r = func_0037E250(300.0f, 600.0f);
        *(f32 *)(p + 0x30) = 1.0f;
        *(f32 *)(p + 0x38) = 1.0f;
        *(f32 *)(p + 0x50) = 0.00698131742f;
        *(f32 *)(p + 0x34) = 0.2f;
        *(f32 *)(p + 0x3C) = 1.0f;
        *(f32 *)(p + 0x40) = 1.4835298f;
        *(s32 *)(p + 0x340) = (s32)r;
        *(f32 *)(p + 0x60) = 0.34906584f;
        *(f32 *)(p + 0x5C) = 0.00272222236f;
        *(f32 *)(p + 0x64) = 0.01f;
        *(f32 *)(p + 0x4C) = 0.418879062f;
        *(f32 *)(p + 0x54) = 0.00698131742f;
        if (D_001426E8[0] != 0) {
            func_L03_0039BE18(a0, p);
        } else {
            a0[0x30] = 0xFF;
            func_L01_00455E98(a0, D_001A71A0[0], p + 0x120);
            func_L03_0039BC20(a0, p);
        }
    }
}
/* localdecomp:end func_L03_0039B908 */
