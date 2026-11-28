#include "common.h"
/* localdecomp:start func_L01_003C93E0 */
#include "vu0.h"
extern u8 D_L01_001D66B0[8];
extern void func_003BDA38(s32, s32, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_003AFF80(void *, void *, void *, u32, u32, u32, u32, f32, f32);
extern void func_L01_00466F98(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);

void func_L01_003C93E0(u8 *o) {
    vu0_v4 a, b, c;
    u8 *st;
    u8 *own;
    f32 r;

    st = *(u8 **)(o + 0x68);
    own = *(u8 **)(*(u8 **)(*(u8 **)(o + 0xB8) + 0xB8) + 0x68);
    *(vu0_q *)&b = *(vu0_q *)(st + 0x4A0);
    func_003BDA38(*(s32 *)(st + 0x550), 0, &a);
    r = func_0037E250(0.0f, 1.0f);
    if (r <= *(f32 *)(own + 0x84)) {
        f32 ang, h;
        vec_sub_ab(&c, &b, &a);
        ang = func_003893C8(func_00388A28(c.x, c.y), func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_00388A28(func_003887A0(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_0037E4B8(&c, 1.0f, func_00389380(func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003AFF80(o, &a, &c, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, *(f32 *)(own + 0x80), 0.6499999761581421f);
    } else {
        f32 ang, h;
        b.x += func_L01_00440918(0.0f, 0.2f);
        b.y += func_L01_00440918(0.0f, 0.2f);
        b.z += func_L01_00440918(0.0f, 0.2f);
        vec_sub_ab(&c, &b, &a);
        ang = func_003893C8(func_00388A28(c.x, c.y), func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_00388A28(func_003887A0(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_0037E4B8(&c, 1.0f, func_00389380(func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003AFF80(o, &a, &c, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.6499999761581421f);
    }
    func_L01_00466F98(&a, D_L01_001D66B0, 0x14, 0x50, 0xFF1010, 0, func_0037E250(8.0f, 10.0f) * 0.25f * 210000.0f, 600.0f, 0.949999988079071f, 0.0f, 0.0f);
}
/* localdecomp:end func_L01_003C93E0 */
