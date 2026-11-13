#include "common.h"

/* NTSC-U counterpart of func_L08_0039C760 (src/levels/08_aquatos/L08_0039B088.c): 0.153589 -> 0.127991 */
/* localdecomp:start func_L08_0039AD30 */
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L05_0035CE40(void);
extern void func_L01_00402498(void *, void *);
extern void func_L01_0044EB78(void *, f32, void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_0038CAD0(void *);
extern u8 D_L08_001E1D40_0039AD30[];
__asm__(".extern D_L08_001E1D40_0039AD30, 16");

void func_L08_0039AD30(void *arg0) {
    u8 *v17;
    f32 f;
    f32 r;
    u16 t;

    v17 = *(u8 **)((u8 *)arg0 + 0x68);
    func_0038CAD0(v17 + 0x2D0);
    t = *(u16 *)((u8 *)arg0 + 0x96);
    if (t <= 0xFFFE) {
        *(u16 *)((u8 *)arg0 + 0x96) = t + 1;
    }
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        func_L01_00402498((void *) func_L05_0035CE40, arg0);
    }
    func_L01_0044EB78(arg0, 2.5f, v17 + 0x240, 1, 1);
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        f = func_L01_0040C018(D_L08_001E1D40_0039AD30, (u8 *)arg0 + 0x10);
        if (f < 576.0f) {
            func_L01_00444188(arg0);
            *(u8 *)((u8 *)arg0 + 0x6F) = 0x16;
        }
    }
    r = func_0038DAB8(*(f32 *)(v17 + 0x31C), 0.127990812f);
    *(f32 *)(v17 + 0x31C) = r;
    r = func_0038D0B0(r);
    *(s32 *)((u8 *)arg0 + 0x78) = func_0038DBD8((r + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L08_0039AD30 */
