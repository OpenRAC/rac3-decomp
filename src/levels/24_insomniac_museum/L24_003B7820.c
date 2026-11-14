#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L24_003B7820 */
extern s32 D_001DD570;
__asm__(".extern D_001DD570, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L24_003B7A70(u8 *);
extern void func_L24_00355C18(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L24_003B7820(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 buf[16];

    if (D_001DD570 != 0 && a0[0x20] < 2) return;
    if (D_001D545C != 0x539 && D_001D545C != 0x18) return;
    if (a0[0x20] == 0) func_L24_003B7A70(a0);
    if (a0[0x20] == 1) {
        func_L24_00355C18(a0, 1, 0, p + 0x130, *(s32 *)(p + 0x124), *(f32 *)(p + 0x128));
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
            if (a0[0x43] != 7) func_003C3A10(a0, 7, 0, 3);
        }
    } else if (a0[0x20] == 2 && (a0[0x60] & 2)) {
        a0[0xA8] = 0xFF;
        func_003C2F58(a0, 0, buf);
        func_L01_003303B8(buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
        func_L01_004450F0(a0, 3, -1);
        *(u16 *)(a0 + 0x34) |= 2;
    }
    if (D_001D545C == 0x18) *(f32 *)(a0 + 0x18) = 101.86f;
    else *(f32 *)(a0 + 0x18) = 48.84f;
}
/* localdecomp:end func_L24_003B7820 */

INCLUDE_ASM("asm/levels", func_L24_003B7A70);

INCLUDE_ASM("asm/levels", func_L24_003B7B88);

INCLUDE_ASM("asm/levels", func_L24_003B7DE8);

INCLUDE_ASM("asm/levels", func_L24_003B7F00);

INCLUDE_ASM("asm/levels", func_L24_003B8160);

INCLUDE_ASM("asm/levels", func_L24_003B8278);
