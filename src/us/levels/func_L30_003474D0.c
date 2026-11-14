#include "common.h"

/* NTSC-U counterpart of func_L30_00348240 (src/levels/shared/L30_00348240.c): 0.04 -> 0.0333333; 37 -> 45 */
/* localdecomp:start func_L30_003474D0 */
#include "vu0.h"
extern f32 D_L30_001DD1D8;
__asm__(".extern D_L30_001DD1D8, 4");
extern f32 D_L30_001DD1DC;
__asm__(".extern D_L30_001DD1DC, 4");
extern f32 D_L30_001DD1E0;
__asm__(".extern D_L30_001DD1E0, 4");
extern f32 D_L30_001DD1E4 __attribute__((section(".data")));
extern f32 D_L30_001DD1E8 __attribute__((section(".data")));
extern f32 D_L30_001DD1F0;
__asm__(".extern D_L30_001DD1F0, 4");
extern f32 D_L30_001DD1F4;
__asm__(".extern D_L30_001DD1F4, 4");
extern f32 D_L30_001DD200;
__asm__(".extern D_L30_001DD200, 4");
extern f32 D_L30_001DD204 __attribute__((section(".data")));
extern f32 D_L30_001DD208 __attribute__((section(".data")));
extern void func_003BF6A8(f32 *, f32);
extern f32 func_0037E250(f32, f32);
extern int func_0037E208(int, int);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L30_003474D0(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 col;
    s32 n;
    f32 s;
    s32 i;

    for (i = 1; i >= 0; i--) {
        pos = *(vu0_v4 *)(a0 + 0x10);
        func_003BF6A8(&pos.x, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD1F4 : D_L30_001DD1DC);
        col.x = func_0037E250(0.0f, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD200 : D_L30_001DD1E0);
        col.y = func_0037E250(0.0f, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD204 : D_L30_001DD1E4);
        col.z = func_0037E250(0.0333333351f, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD208 : D_L30_001DD1E8);
        n = func_0037E208(0, 2) - 1;
        s = func_0037E250(0.25f, 1.25f) * 210000.0f;
        func_L01_0046C468(&pos, &col, 0x2D, 0x808080, n, 0x60, 0, 0, s, s * 0.1f,
                          *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD1F0 : D_L30_001DD1D8);
    }
}
/* localdecomp:end func_L30_003474D0 */
