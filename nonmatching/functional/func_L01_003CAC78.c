/* functional: high. 62 instructions differ (register allocation only); same calls, arguments and constants as retail. */
#include "vu0.h"
extern u8 D_L01_001D66B0[];
extern void func_003C2F58(s32, s32, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_003B1750(void *, void *, void *, u32, u32, u32, u32, f32, f32);
extern void func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);

void func_L01_003CAC78(u8 *o) {
    vu0_v4 a, b, c;
    u8 *st;
    u8 *own;
    f32 r, ang, h;

    st = *(u8 **)(o + 0x68);
    own = *(u8 **)(*(u8 **)(o + 0xB8) + 0xB8);
    own = *(u8 **)(own + 0x68);
    *(vu0_q *)&b = *(vu0_q *)(st + 0x4A0);
    func_003C2F58(*(s32 *)(st + 0x550), 0, &a);
    r = func_003824E0(0.0f, 1.0f);
    if (r <= *(f32 *)(own + 0x84)) {
        vec_sub_ab(&c, &b, &a);
        ang = func_0038DB00(func_0038D160(c.x, c.y), func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_0038D160(func_0038CED8(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_00382760(&c, 1.0f, func_0038DAB8(func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003B1750(o, &a, &c, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, *(f32 *)(own + 0x80), 0.6499999761581421f);
    } else {
        b.x += func_L01_00443A18(0.0f, 0.2f);
        b.y += func_L01_00443A18(0.0f, 0.2f);
        b.z += func_L01_00443A18(0.0f, 0.2f);
        vec_sub_ab(&c, &b, &a);
        ang = func_0038DB00(func_0038D160(c.x, c.y), func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_0038D160(func_0038CED8(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_00382760(&c, 1.0f, func_0038DAB8(func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003B1750(o, &a, &c, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.6499999761581421f);
    }
    func_L01_0046A610(&a, D_L01_001D66B0, 0x11, 0x50, 0xFF1010, 0, func_003824E0(8.0f, 10.0f) * 0.25f * 210000.0f, 600.0f, 0.949999988079071f, 0.0f, 0.0f);
}
