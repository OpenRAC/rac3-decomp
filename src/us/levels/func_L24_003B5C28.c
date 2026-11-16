#include "common.h"

/* NTSC-U counterpart of func_L24_003B7820 (src/levels/24_insomniac_museum/L24_003B7820.c) */
/* localdecomp:start func_L24_003B5C28 */
extern s32 D_L24_001DD5B0_003B5C28;
__asm__(".extern D_L24_001DD5B0_003B5C28, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L24_003B5E78(u8 *);
extern void func_L24_00354BE0(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_0032FE90_003B5C28(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

void func_L24_003B5C28(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 buf[16];

    if (D_L24_001DD5B0_003B5C28 != 0 && a0[0x20] < 2) return;
    if (D_001D545C != 0x539 && D_001D545C != 0x18) return;
    if (a0[0x20] == 0) func_L24_003B5E78(a0);
    if (a0[0x20] == 1) {
        func_L24_00354BE0(a0, 1, 0, p + 0x130, *(s32 *)(p + 0x124), *(f32 *)(p + 0x128));
        if (func_L01_00444358(a0, -1, 0) != 0) {
            func_L01_00441FB8(a0, 2, -1);
            if (a0[0x43] != 7) func_003BE4F0(a0, 7, 0, 4);
        }
    } else if (a0[0x20] == 2 && (a0[0x60] & 2)) {
        a0[0xA8] = 0xFF;
        func_003BDA38(a0, 0, buf);
        func_L01_0032FE90_003B5C28(buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004A6DF8(a0, 1);
        func_L01_00441FB8(a0, 3, -1);
        *(u16 *)(a0 + 0x34) |= 2;
    }
    if (D_001D545C == 0x18) *(f32 *)(a0 + 0x18) = 101.86f;
    else *(f32 *)(a0 + 0x18) = 48.84f;
}
/* localdecomp:end func_L24_003B5C28 */
