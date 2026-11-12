/* func_L24_0034BA30: 5 differences (level 24, file L24_0034A2C8.c, -mvu0-use-vf0-vf2 @ps2as). Only the first statements
   differ: retail loads the constant 0x34 into $v1 (and lh $v0,0xB2(obj)) and does `lwc1 $f0,0x18(obj)` before the
   second gp zero store (sw $zero,0xAF0($gp)); this C swaps those two registers and the order of the lwc1 and the gp
   store. All 24 orders of the four leading stores, rotations of the two constant-store runs (49 variants), a
   constant held in a local and swapped comparison operands were tried. The parameter must stay `void *`
   (func_L24_0034B930 declares it that way). */
#include "common.h"
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L24_0034BC48(void *);
extern void func_L24_0034BF38(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
__asm__(".extern D_L24_001DD39C, 4");
__asm__(".extern D_L24_001DD3A0, 4");
extern s32 D_L24_001DD39C;
extern s32 D_L24_001DD3A0;

s32 func_L24_0034BA30(void *arg) {
    u8 *obj = arg;
    u8 *s = *(u8 **)(obj + 0x68);

    *(s32 *)(s + 0x580) = 0;
    D_L24_001DD39C = 0;
    D_L24_001DD3A0 = 0;
    *(f32 *)(s + 0x58C) = *(f32 *)(obj + 0x18);
    if (*(s16 *)(obj + 0xB2) == 0x34) {
        *(u16 *)(obj + 0x34) |= 0x8000;
    }
    s[0x1A8] = 3;
    *(f32 *)(s + 0x190) = 0.5f;
    s[0x170] = 0xE;
    s[0x176] = 3;
    *(f32 *)(s + 0x194) = 0.5f;
    *(f32 *)(s + 0x19C) = 0.15f;
    s[0x1D7] = 1;
    if (*(s16 *)(s + 0x34) == 0) {
        *(s16 *)(s + 0x34) = 100;
        *(f32 *)(s + 0x30) = 100.0f;
    }
    *(f32 *)(s + 0x40) = 2.0f;
    *(f32 *)(s + 0x80) = 0.9599311f;
    *(f32 *)(s + 0xA0) = 1.4835298f;
    *(f32 *)(s + 0x9C) = 0.002f;
    *(f32 *)(s + 0xA4) = 1.5f;
    *(f32 *)(s + 0x74) = 4.5f;
    *(f32 *)(s + 0x70) = 6.0f;
    func_L01_0045BD78(obj, 0.0048f, 0.120000005f, 0.0069813174f, 0.47472957f);
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.75f;
    *(s32 *)(s + 0x584) = 0;
    func_L24_0034BC48(obj);
    func_L24_0034BF38(obj);
    func_L01_004450F0(obj, 1, 0);
    if (obj[0x43] != 0) {
        func_003C3A10(obj, 0, 0, 0);
    }
    return 0;
}
