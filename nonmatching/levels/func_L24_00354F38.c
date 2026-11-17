/* func_L24_00354F38: 8 differences (level 24, file L24_003519E8.c; its inline float constants need @ps2as on that
   file's line, which keeps func_L24_00351FD8 matching but is not committed with this near miss). The state
   initialisation (about 30 constant byte/float stores, the home position at +0x310, func_L01_0045BD78 with arguments
   read into locals ahead of the stores as retail loads them, health default, func_L01_004450F0 and func_003C3A10
   animation choices, the +0x2E4 flag branch with func_L01_004AA7E8) matches except the order of two constant loads
   (retail li 1 before li 0xFF), four byte stores of the constant run (+0x1D9, +0x1DB, +0x176, +0x1D8), and two
   argument multiplies (f15 before f13). Found by a 400-step statement hill climb, two pair-swap passes and every
   position of the +0x1D7 store; all 24 orders of the four argument locals change nothing. */
#include "common.h"
#include "vu0.h"
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_004AA7E8(void *, s32);
__asm__(".extern D_L24_001DD518, 4");
__asm__(".extern D_L24_001DD51C, 4");
__asm__(".extern D_L24_001DD520, 4");
__asm__(".extern D_L24_001DD524, 4");
extern f32 D_L24_001DD518;
extern f32 D_L24_001DD51C;
extern f32 D_L24_001DD520;
extern f32 D_L24_001DD524;

s32 func_L24_00354F38(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 a;
    f32 c;
    f32 d;
    f32 e;

    s[0x1A8] = 3;
    s[0x1D9] = 3;
    s[0x1DA] = 3;
    s[0x170] = 0x16;
    s[0x171] = 0xC;
    s[0x1CC] = 0;
    s[0x1CD] = 0;
    s[0x176] = 0xE;
    s[0x1D3] = 0x10;
    s[0x1D2] = 0xB;
    *(f32 *)(s + 0x190) = 0.8f;
    *(f32 *)(s + 0x194) = 1.2f;
    s[0x172] = 0xC;
    s[0x1DB] = 0xFF;
    *(f32 *)(s + 0x19C) = 0.15f;
    s[0x1D8] = 3;
    *(f32 *)(s + 0x17C) = 0.40000004f;
    *(f32 *)(s + 0x184) = 0.010000001f;
    s[0x1D7] = 1;
    *(f32 *)(s + 0x180) = 0.020000001f;
    *(f32 *)(s + 0x188) = 0.014f;
    *(f32 *)(s + 0x18C) = 0.002f;
    *(f32 *)(s + 0x1A0) = 5.0f;
    *(f32 *)(s + 0x208) = 0.5f;
    if (*(s32 *)(s + 0x2E4) == 0) {
        s[0x1A9] = 1;
    }
    if (*(s32 *)(s + 0x350) != -1) {
        *(s32 *)(s + 0x1DC) = *(s32 *)(s + 0x350);
    }
    if (*(s32 *)(s + 0x2E4) == 0) {
        *(f32 *)(obj + 0x18) = func_003C3D30(obj + 0x10, 0, obj, 0.5f);
    }
    *(vu0_q *)(s + 0x310) = *(vu0_q *)(obj + 0x10);
    if (*(s32 *)(s + 0x350) != -1) {
        *(s32 *)(s + 0xAC) = *(s32 *)(s + 0x350);
    }
    d = D_L24_001DD524 * 0.017453292f * 0.00040000002f;
    e = D_L24_001DD520 * 0.017453292f * 0.020000001f;
    a = D_L24_001DD51C * 0.00040000002f;
    c = D_L24_001DD518 * 0.020000001f;
    *(f32 *)(s + 0x15C) = 0.8f;
    *(f32 *)(s + 0x78) = 1.2f;
    *(f32 *)(s + 0x70) = 1.1f;
    *(f32 *)(s + 0x74) = 0.4f;
    *(f32 *)(s + 0x7C) = 1.5f;
    *(f32 *)(s + 0x80) = 1.5707964f;
    *(f32 *)(s + 0xA0) = 0.2443461f;
    *(f32 *)(s + 0x9C) = 0.10000001f;
    func_L01_0045BD78(obj, a, c, d, e);
    s[0x58] = 0x14;
    s[0x5A] = 0xE;
    if (*(s16 *)(s + 0x34) == 0) {
        *(s16 *)(s + 0x34) = 10;
        *(f32 *)(s + 0x30) = 10.0f;
    }
    *(f32 *)(s + 0x40) = 1.2f;
    s[0x39] = 1;
    s[0x3E] = 1;
    *(s32 *)(s + 0x2DC) = 0;
    func_L01_004450F0(obj, 1, 0);
    if (obj[0x43] != 0) {
        func_003C3A10(obj, 0, 0, 0);
    }
    if (*(s32 *)(s + 0x2F4) != -1) {
        if (obj[0x43] != 4) {
            func_003C3A10(obj, 4, 0, 0);
        }
        func_L01_004450F0(obj, 2, -1);
    } else if (*(s32 *)(s + 0x2E4) == 0 && *(s32 *)(s + 0x338) == 0) {
        if (obj[0x43] != 4) {
            func_003C3A10(obj, 4, func_00382468(3), func_00382468(6));
        }
        func_L01_004450F0(obj, 6, -1);
    }
    if (*(s32 *)(s + 0x2E4) != 0) {
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
        if (*(s32 *)(s + 0x2E4) != 0 && *(s32 *)(s + 0x2EC) != -1) {
            func_L01_004450F0(obj, 7, 5);
        }
    }
    return 0;
}
