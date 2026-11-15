#include "common.h"

/* localdecomp:start func_L08_0039EBC0 */
extern s32 func_0038CAD0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L08_0039F4E8(void *);
extern u8 D_L08_001E1D40[];
__asm__(".extern D_L08_001E1D40, 16");

void func_L08_0039EBC0(u8 *arg0) {
    u8 *m = *(u8 **)(arg0 + 0x68);
    f32 t;

    func_0038CAD0(m + 0x190);
    if (arg0[0x31] != 0) {
        if (func_L01_0040E548(D_L08_001E1D40, arg0 + 0x10) < 1024.0f) {
            func_L01_004472C0(arg0);
            arg0[0x6F] = 30;
        }
        if (arg0[0x31] != 0) {
            func_L01_00404808(func_L08_0039F4E8, arg0);
        }
    }
    t = func_0038DAB8(*(f32 *)(m + 0x1D0), 0.13962635f);
    *(f32 *)(m + 0x1D0) = t;
    *(s32 *)(arg0 + 0x78) = func_0038DBD8(0x8000B0B0, 0x80004040, (func_0038D0B0(t) + 1.0f) * 0.5f);
    if (*(u16 *)(arg0 + 0x96) < 0xFFFF) {
        *(u16 *)(arg0 + 0x96) += 1;
    }
}
/* localdecomp:end func_L08_0039EBC0 */
