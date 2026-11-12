/* func_L36_00350330: near miss, level 36 (Vidcomic 1 Special Edition). 48 differences (file L36_0034E8C0.c, @ps2as; the u128_t typedef must go in the file prelude or the block): the logic is right; the list head is read into p before the pointer stores (it cannot move above a u8 * store otherwise) and the store order comes from a hill climb over single moves and swaps. Still different: retail stores the 0xB0 copy before 0xA0 and does the 0xF4/0xFC sums in $a1/$a0 with -1 in $a2 before any word store; the tail (0x130/0x128 table pointers) is scheduled differently */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L36_001DFC00;
extern u8 *D_L36_001DFB1C;
extern void *D_L36_001DFB28;
extern f32 func_0038CE68(u8 *, f32 *);
void func_L36_00350330(u8 *a0) {
    u8 *s;
    u8 *p;
    u8 *t;
    f32 v[4];
    u128_t x;
    s = *(u8 **)(a0 + 0x68);
    *(u8 *)(a0 + 0x30) = 0xFF;
    x = *(u128_t *)(a0 + 0x10);
    *(u128_t *)(s + 0xB0) = x;
    *(u128_t *)(s + 0xA0) = x;
    *(s32 *)(s + 0xDC) = -1;
    *(u8 **)(s + 0xFC) = D_L36_001DFB1C + *(s32 *)(s + 0xF8) * 0x100;
    qzero(s + 0xC0);
    p = D_L36_001DFB28;
    *(s32 *)(s + 0xD0) = 0;
    *(u8 **)(s + 0xF4) = D_L36_001DFC00 + *(s32 *)(s + 0xF0) * 0x80;
    *(s32 *)(s + 0xD4) = 0;
    *(s32 *)(s + 0xD8) = -1;
    *(s32 *)(s + 0xE8) = 0;
    *(s32 *)(s + 0xEC) = 0;
    for (; p != 0; p = *(u8 **)(p + 0x28)) {
        if (*(s16 *)(p + 0xAA) == 0x1B55) {
            *(u8 **)(s + 0x100) = p;
        }
    }
    *(u8 **)(s + 0x110) = D_L36_001DFC00 + *(s32 *)(s + 0x10C) * 0x80;
    qzero(v);
    v[0] = 1.0f;
    *(f32 *)(s + 0x114) = *(f32 *)(*(u8 **)(s + 0x110) + 0x30) - func_0038CE68(*(u8 **)(s + 0x110), v);
    *(f32 *)(s + 0x118) = *(f32 *)(*(u8 **)(s + 0x110) + 0x30) + func_0038CE68(*(u8 **)(s + 0x110), v);
    qzero(v);
    v[2] = 1.0f;
    *(f32 *)(s + 0x11C) = *(f32 *)(*(u8 **)(s + 0x110) + 0x38) - func_0038CE68(*(u8 **)(s + 0x110) + 0x20, v);
    *(f32 *)(s + 0x120) = *(f32 *)(*(u8 **)(s + 0x110) + 0x38) + func_0038CE68(*(u8 **)(s + 0x110) + 0x20, v);
    *(u8 **)(s + 0x130) = D_L36_001DFB1C + *(s32 *)(s + 0x12C) * 0x100;
    *(u8 **)(s + 0x128) = D_L36_001DFB1C + *(s32 *)(s + 0x124) * 0x100;
    t = *(u8 **)(*(u8 **)(s + 0x130) + 0x68);
    *(f32 *)(t + 0x88) = *(f32 *)(s + 0x120);
    *(f32 *)(t + 0x80) = *(f32 *)(s + 0x114) + 5.0f;
    *(f32 *)(t + 0x84) = *(f32 *)(s + 0x118) - 5.0f;
}
