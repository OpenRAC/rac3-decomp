#include "common.h"

/* NTSC-U counterpart of func_L18_00354250 (src/levels/shared/L18_003537D8.c): 0.1 -> 0.0833333 */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90_00353648(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_L18_00353648 */
extern s32 func_L01_0032FE90_00353648(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F090(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);

/* from the NTSC-U draft of func_L18_00353648 */
void func_L18_00353648(void *arg0) {
    u8 *a0 = arg0;
    vu0_v4 v;
    u8 *s = *(u8 **)(a0 + 0x68);
    func_L01_0032FE90_00353648(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.5f, 10.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_00388830(&v, s + 0x290, 0.0833333358f);
    func_L01_0044F090(a0, 0x3FF, &v, 1, 0x23, -1.0f, 3.0f, 6.0f, 5.0f, 15.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_0039FE80(0, 0, a0);
    func_L18_00353590(arg0, 1);
}
/* localdecomp:end func_L18_00353648 */
