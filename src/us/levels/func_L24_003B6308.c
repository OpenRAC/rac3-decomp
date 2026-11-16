#include "common.h"

/* NTSC-U counterpart of func_L24_003B7F00 (src/levels/24_insomniac_museum/L24_003B7820.c) */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L24_001DD5B0_003B6308;
extern s32 D_001D545C;
extern void func_L24_00354BE0(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_0032FE90_003B6308(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_L24_001DD5B0_003B6308;
extern s32 D_001D545C;
extern void func_L24_00354BE0(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_0032FE90_003B6308(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

/* localdecomp:start func_L24_003B6308 */
/* log:
 * 1. copy of func_L24_003B7B88 (same task) with this one's offsets and callee
 */
extern s32 D_L24_001DD5B0_003B6308;
__asm__(".extern D_L24_001DD5B0_003B6308, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L24_003B6568(u8 *);
extern void func_L24_00354BE0(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_0032FE90_003B6308(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

void func_L24_003B6308(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 buf[16];

    if (D_L24_001DD5B0_003B6308 != 0 && a0[0x20] < 2) return;
    if (D_001D545C != 0x539 && D_001D545C != 0x18) return;
    if (a0[0x20] == 0) func_L24_003B6568(a0);
    if (a0[0x20] == 1) {
        func_L24_00354BE0(a0, 2, 0, p + 0x170, *(s32 *)(p + 0x168), *(f32 *)(p + 0x16C));
        if (func_L01_00444358(a0, -1, 0) != 0) {
            func_L01_00441FB8(a0, 2, -1);
            if (a0[0x43] != 1) func_003BE4F0(a0, 1, 0, 4);
        }
    } else if (a0[0x20] == 2 && (a0[0x60] & 2)) {
        a0[0xA8] = 0xFF;
        func_003BDA38(a0, 2, buf);
        func_L01_0032FE90_003B6308(buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004A6DF8(a0, 1);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x190);
        func_L01_00441FB8(a0, 3, -1);
        *(u16 *)(a0 + 0x34) |= 2;
    }
    if (D_001D545C == 0x18) *(f32 *)(a0 + 0x18) = 101.86f;
    else *(f32 *)(a0 + 0x18) = 48.84f;
}
/* localdecomp:end func_L24_003B6308 */
