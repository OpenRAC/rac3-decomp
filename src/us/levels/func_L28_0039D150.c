#include "common.h"

/* NTSC-U counterpart of func_L28_0039F010 (src/levels/28_aquatos_sewers/L28_0039D530.c): 0.153589 -> 0.127991 */
/* localdecomp:start func_L28_0039D150 */
extern u8 D_L28_001E1540_0039D150[];
extern void func_L01_00402498(void *, void *);
extern void func_L08_0039D948(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, u32);
void func_L28_0039D150(u8 *a0) {
    u8 *d = *(u8 **)(a0 + 0x68);
    f32 t;
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE) *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L28_001E1540_0039D150, a0 + 0x10) < 1024.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x1E;
        }
    }
    if (a0[0x20] != 1 && a0[0x31] != 0) func_L01_00402498(func_L08_0039D948, a0);
    t = func_0038DAB8(*(f32 *)(d + 0x1DC), 0.127990812f);
    *(f32 *)(d + 0x1DC) = t;
    *(s32 *)(a0 + 0x78) = func_0038DBD8((func_0038D0B0(t) + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L28_0039D150 */
