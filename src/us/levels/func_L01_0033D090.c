#include "common.h"

/* NTSC-U counterpart of func_L01_0033D780 (src/levels/shared/L01_0033D2B8.c) */
extern f32 func_00389380(f32, f32);

/* localdecomp:start func_L01_0033D090 */
extern f32 D_L01_001DD050_0033D090;
__asm__(".extern D_L01_001DD050_0033D090, 4");
extern u8 D_L01_001E1930;
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern s32 func_003894A0(f32, s32, s32);
extern void func_L01_0033D7D8(void *);
extern void func_003D3FA0(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0033D090(void *a0) {
    f32 t;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    s32 c0;
    s32 c1;
    s32 c2;

    D_L01_001DD050_0033D090 = func_00389380(D_L01_001DD050_0033D090, 0.125f);
    t = func_00388960(D_L01_001DD050_0033D090);
    f20 = (t + 1.0f) * 0.5f;
    f23 = f20 * 0.0625f + 0.0625f;
    f22 = f20 * 0.19999999f + 0.15f;
    f21 = f20 * 0.125f + 0.125f;
    c0 = func_003894A0(f20, 0x2F007F00, 0x3F007F00);
    c1 = func_003894A0(f20, 0x2F7F7F7F, 0x5F7F7F7F);
    c2 = func_003894A0(f20, 0x10003F00, 0x10003F00);
    func_L01_0033D7D8(a0);
    func_003D3FA0(&D_L01_001E1930, 0x31, c0, 1, f21, 0.125f, 0.0f);
    func_003D3FA0(&D_L01_001E1930, 0x31, c1, 1, f23, 0.124f, 0.0f);
    func_003D3FA0(&D_L01_001E1930, 0xB, c2, 1, f22, 0.123f, 0.0f);
}
/* localdecomp:end func_L01_0033D090 */
