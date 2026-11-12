#include "common.h"

/* localdecomp:start func_L08_003A0D90 */
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L08_003A16C8(void);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_0038CAD0(void *);
extern u8 D_L08_001E1D40[];
__asm__(".extern D_L08_001E1D40, 16");

void func_L08_003A0D90(void *arg0) {
    u8 *v17;
    f32 f;
    f32 r;
    u16 t;

    v17 = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        f = func_L01_0040E548(D_L08_001E1D40, (u8 *)arg0 + 0x10);
        if (f < 1024.0f) {
            func_L01_004472C0(arg0);
            *(u8 *)((u8 *)arg0 + 0x6F) = 30;
        }
        if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
            func_L01_00404808((void *) func_L08_003A16C8, arg0);
        }
    }
    r = func_0038DAB8(*(f32 *)(v17 + 0x1D0), 0.139626354f);
    *(f32 *)(v17 + 0x1D0) = r;
    r = func_0038D0B0(r);
    *(s32 *)((u8 *)arg0 + 0x78) = func_0038DBD8((r + 1.0f) * 0.5f, 0x8000B0B0, 0x80004040);
    func_0038CAD0(v17 + 0x190);
    t = *(u16 *)((u8 *)arg0 + 0x96);
    if (t < 0xFFFF) {
        *(u16 *)((u8 *)arg0 + 0x96) = t + 1;
    }
}
/* localdecomp:end func_L08_003A0D90 */
