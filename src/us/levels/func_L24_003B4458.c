#include "common.h"

/* NTSC-U counterpart of func_L24_003B6050 (src/levels/24_insomniac_museum/L24_003B6050.c): 3 -> 4 */
#include "vu0.h"

/* localdecomp:start func_L24_003B4458 */
extern s32 D_001D545C;
extern s32 D_L24_001DD5B0_003B4458;
__asm__(".extern D_L24_001DD5B0_003B4458, 16");
extern s32 func_L24_003B4728(u8 *);
extern void func_003BD360(void *);
extern void func_L24_00354BE0(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

void func_L24_003B4458(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 t;
    if (func_L24_003B4728(a0) != 0) {
        func_003BD360(a0);
        return;
    }
    t = D_001D545C;
    if (t != 0x539 && t != 0x18 && t != 3) {
        return;
    }
    if (*(s32 *)(p + 0x938) != 0) {
        return;
    }
    if (D_L24_001DD5B0_003B4458 != 0 && a0[0x20] < 2) {
        return;
    }
    if (a0[0x20] == 1) {
        *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) &= 0xFFBE;
        *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(p + 0x8DC) + 0x24) + 0x44) & 0x1000;
        *(s32 *)(*(u8 **)(p + 0x8DC) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(p + 0x8DC) + 0x24) + 0x10);
        *(u16 *)(a0 + 0x34) &= 0xFFBE;
        *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        func_L24_00354BE0(a0, 1, 0, p + 0x910, *(s32 *)(p + 0x90C), *(f32 *)(p + 0x930));
        if (func_L01_00444358(a0, -1, 0) != 0) {
            func_L01_00441FB8(a0, 2, -1);
            if (a0[0x43] != 4) {
                func_003BE4F0(a0, 4, 0, 4);
            }
        }
    } else if (a0[0x20] == 2) {
        if (a0[0x60] & 2) {
            u8 v[16] __attribute__((aligned(16)));
            func_003BDA38(a0, 5, v);
            func_L01_0032FE90(v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
                0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            a0[0xA8] = 0xFF;
            *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(p + 0x8DC) + 0x98) = 0;
            func_L01_004A6DF8(*(u8 **)(p + 0x8DC), 1);
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(a0 + 0x98) = 0;
            func_L01_004A6DF8(a0, 1);
            *(u16 *)(a0 + 0x34) |= 2;
            func_L01_00441FB8(a0, 3, -1);
        }
    }
}
/* localdecomp:end func_L24_003B4458 */
