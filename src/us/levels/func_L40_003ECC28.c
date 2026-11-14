#include "common.h"

/* NTSC-U counterpart of func_L40_003ED0C8 (src/levels/shared/L40_003EBB98.c) */
/* localdecomp:start func_L40_003ECC28 */
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

s32 func_L40_003ECC28(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    *(s32 *)(p + 0x1DC) = -1;
    *(f32 *)(p + 0x74) = 0.5f;
    p[0x170] = 4;
    p[0x1A8] = 3;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1D7] = 1;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x80) = 1.4835298f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.008277778f;
    *(s32 *)(p + 0xAC) = -1;
    func_L01_00458A70(a0, 0.0125f, 0.3166667f, 0.0069813174f, 0.20943953f);
    if (*(s16 *)(p + 0x34) == 0) {
        *(f32 *)(p + 0x30) = 1.0f;
        *(s16 *)(p + 0x34) = 1;
    }
    *(f32 *)(p + 0x40) = 0.2f;
    a0[0x30] = 0xFF;
    *(u16 *)(a0 + 0x32) = 0xFF;
    func_L01_00441FB8(a0, 5, 4);
    *(f32 *)(p + 0x2D4) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) / 60.0f;
    *(f32 *)(p + 0x2D8) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) / 60.0f;
    if (a0[0x43] != 0) {
        func_003BE4F0(a0, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L40_003ECC28 */
