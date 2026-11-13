#include "common.h"

/* NTSC-U counterpart of func_L08_003A0D90 (src/levels/08_aquatos/L08_003A0D90.c): 0.139626 -> 0.116355 */
/* localdecomp:start func_L08_0039F1C0 */
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L08_0039FA48(void);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_0038CAD0(void *);
extern u8 D_L08_001E1D40_0039F1C0[];
__asm__(".extern D_L08_001E1D40_0039F1C0, 16");

void func_L08_0039F1C0(void *arg0) {
    u8 *v17;
    f32 f;
    f32 r;
    u16 t;

    v17 = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        f = func_L01_0040C018(D_L08_001E1D40_0039F1C0, (u8 *)arg0 + 0x10);
        if (f < 1024.0f) {
            func_L01_00444188(arg0);
            *(u8 *)((u8 *)arg0 + 0x6F) = 30;
        }
        if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
            func_L01_00402498((void *) func_L08_0039FA48, arg0);
        }
    }
    r = func_0038DAB8(*(f32 *)(v17 + 0x1D0), 0.116355292f);
    *(f32 *)(v17 + 0x1D0) = r;
    r = func_0038D0B0(r);
    *(s32 *)((u8 *)arg0 + 0x78) = func_0038DBD8((r + 1.0f) * 0.5f, 0x8000B0B0, 0x80004040);
    func_0038CAD0(v17 + 0x190);
    t = *(u16 *)((u8 *)arg0 + 0x96);
    if (t < 0xFFFF) {
        *(u16 *)((u8 *)arg0 + 0x96) = t + 1;
    }
}
/* localdecomp:end func_L08_0039F1C0 */
