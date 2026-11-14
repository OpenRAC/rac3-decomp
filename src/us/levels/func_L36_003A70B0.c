#include "common.h"

/* NTSC-U counterpart of func_L36_003A8920 (src/levels/36_vidcomic_1_special_edition/L36_003A7F38.c): 17 -> 20; 8 -> 10; 67 -> 80; 50 -> 60 */
#include "vu0.h"
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_00388398(u8 *);

/* localdecomp:start func_L36_003A70B0 */
__asm__(".extern D_L36_001DEB1C, 4");
__asm__(".extern D_L36_001DEB20, 4");
__asm__(".extern D_L36_001DEB24, 4");
__asm__(".extern D_L36_001DEB28, 4");
__asm__(".extern D_L36_001DEB18, 4");
extern s32 D_L36_001DEB1C;
extern f32 D_L36_001DEB20;
extern f32 D_L36_001DEB24;
extern s32 D_L36_001DEB28;
extern f32 D_L36_001DEB18;
__asm__(".extern D_L36_001E1FB0_003A70B0, 16");
extern u8 D_L36_001E1FB0_003A70B0;
extern f32 D_L36_001E1FB4_003A70B0;
extern void func_L03_0034A658(f32, u8 *, s32, s32, s32, void *);
extern void func_L36_003A7240(u8 *, u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern s32 func_0039FE80(s32, s32, u8 *);
extern s32 func_00388398(u8 *);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_L30_0034B9C8(u8 *, u8 *);
extern void func_L01_0044B598(u8 *, s32);
extern f32 func_00389380(f32, f32);
extern void func_L36_003A7488(u8 *);
void func_L36_003A70B0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 t;
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        t = D_L36_001DEB1C;
        *(s32 *)(s + 0x50) = 0;
        if (t == 0) {
            D_L36_001DEB1C = 1;
            func_L03_0034A658(D_L36_001DEB20, &D_L36_001E1FB0_003A70B0, 0x14, 10, D_L36_001DEB28, (void *)func_L36_003A7240);
        }
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 0x42:
        if (func_L01_00452EC8(a0) != 0) {
            func_0039FE80(1, 0, a0);
            *(s32 *)(s + 0x54) = 0x50;
        }
        if (func_00388398(s + 0x54) == 0) {
            if (*(s32 *)(s + 0x54) == 0x3C) {
                func_0039FE80(0, 0, a0);
            }
            *(u8 *)(a0 + 0x23) = (s32)((f32)*(s32 *)(s + 0x54) * 128.0f / 80.0f);
            D_L36_001E1FB4_003A70B0 = func_003BEB48(D_L36_001DEB24, D_L36_001DEB20, (f32)*(s32 *)(s + 0x54) / 80.0f);
            func_L30_0034B9C8(&D_L36_001E1FB0_003A70B0, a0);
        }
        break;
    case 1:
        if (*(s32 *)(s + 0x58) != 0) {
            func_L01_0044B598(a0, 0x80000080);
        }
        *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), D_L36_001DEB18);
        break;
    }
    func_L36_003A7488(a0);
}
/* localdecomp:end func_L36_003A70B0 */
