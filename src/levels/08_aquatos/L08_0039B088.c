#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_0039B088);

INCLUDE_ASM("asm/levels", func_L08_0039C028);

INCLUDE_ASM("asm/levels", func_L08_0039C220);

INCLUDE_ASM("asm/levels", func_L08_0039C480);

/* localdecomp:start func_L08_0039C760 */
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L05_0035E050(void);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00451DF8(void *, f32, void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_0038CAD0(void *);
extern u8 D_L08_001E1D40[];
__asm__(".extern D_L08_001E1D40, 16");

void func_L08_0039C760(void *arg0) {
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
        func_L01_00404808((void *) func_L05_0035E050, arg0);
    }
    func_L01_00451DF8(arg0, 2.5f, v17 + 0x240, 1, 1);
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        f = func_L01_0040E548(D_L08_001E1D40, (u8 *)arg0 + 0x10);
        if (f < 576.0f) {
            func_L01_004472C0(arg0);
            *(u8 *)((u8 *)arg0 + 0x6F) = 0x16;
        }
    }
    r = func_0038DAB8(*(f32 *)(v17 + 0x31C), 0.15358898f);
    *(f32 *)(v17 + 0x31C) = r;
    r = func_0038D0B0(r);
    *(s32 *)((u8 *)arg0 + 0x78) = func_0038DBD8((r + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L08_0039C760 */
