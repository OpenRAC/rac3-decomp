#include "common.h"

/* localdecomp:start func_L30_00348240 */
#include "vu0.h"
extern f32 D_L30_001DD198;
__asm__(".extern D_L30_001DD198, 4");
extern f32 D_L30_001DD19C;
__asm__(".extern D_L30_001DD19C, 4");
extern f32 D_L30_001DD1A0;
__asm__(".extern D_L30_001DD1A0, 4");
extern f32 D_L30_001DD1A4 __attribute__((section(".data")));
extern f32 D_L30_001DD1A8 __attribute__((section(".data")));
extern f32 D_L30_001DD1B0;
__asm__(".extern D_L30_001DD1B0, 4");
extern f32 D_L30_001DD1B4;
__asm__(".extern D_L30_001DD1B4, 4");
extern f32 D_L30_001DD1C0;
__asm__(".extern D_L30_001DD1C0, 4");
extern f32 D_L30_001DD1C4 __attribute__((section(".data")));
extern f32 D_L30_001DD1C8 __attribute__((section(".data")));
extern void func_003C4C18(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern int func_00382498(int, int);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L30_00348240(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 col;
    s32 n;
    f32 s;
    s32 i;

    for (i = 1; i >= 0; i--) {
        pos = *(vu0_v4 *)(a0 + 0x10);
        func_003C4C18(&pos.x, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD1B4 : D_L30_001DD19C);
        col.x = func_003824E0(0.0f, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD1C0 : D_L30_001DD1A0);
        col.y = func_003824E0(0.0f, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD1C4 : D_L30_001DD1A4);
        col.z = func_003824E0(0.040000003f, *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD1C8 : D_L30_001DD1A8);
        n = func_00382498(0, 2) - 1;
        s = func_003824E0(0.25f, 1.25f) * 210000.0f;
        func_L01_0046FB40(&pos, &col, 0x25, 0x808080, n, 0x60, 0, 0, s, s * 0.1f,
                          *(u8 *)(a0 + 0x20) == 3 ? D_L30_001DD1B0 : D_L30_001DD198);
    }
}
/* localdecomp:end func_L30_00348240 */
