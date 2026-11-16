#include "common.h"

/* NTSC-U counterpart of func_L08_0039EBC0 (src/levels/08_aquatos/L08_0039EBC0.c) */
/* localdecomp:start func_L08_0039D0C0 */
extern s32 func_00388398(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_00402498(void *, void *);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L08_0039D948(void *);
extern u8 D_L08_001E1D40_0039D0C0[];
__asm__(".extern D_L08_001E1D40_0039D0C0, 16");

void func_L08_0039D0C0(u8 *arg0) {
    u8 *m = *(u8 **)(arg0 + 0x68);
    f32 t;

    func_00388398(m + 0x190);
    if (arg0[0x31] != 0) {
        if (func_L01_0040C018(D_L08_001E1D40_0039D0C0, arg0 + 0x10) < 1024.0f) {
            func_L01_00444188(arg0);
            arg0[0x6F] = 30;
        }
        if (arg0[0x31] != 0) {
            func_L01_00402498(func_L08_0039D948, arg0);
        }
    }
    t = func_00389380(*(f32 *)(m + 0x1D0), 0.1163552924990654f);
    *(f32 *)(m + 0x1D0) = t;
    *(s32 *)(arg0 + 0x78) = func_003894A0(0x8000B0B0, 0x80004040, (func_00388978(t) + 1.0f) * 0.5f);
    if (*(u16 *)(arg0 + 0x96) < 0xFFFF) {
        *(u16 *)(arg0 + 0x96) += 1;
    }
}
/* localdecomp:end func_L08_0039D0C0 */
