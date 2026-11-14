#include "common.h"

/* NTSC-U counterpart of func_L07_003B7E40 (src/levels/07_annihilation_nation/L07_003B7408.c) */
/* localdecomp:start func_L07_003B6550 */
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void *func_L01_0044B550(void *);
extern void func_L07_003B6B58(void *);
extern void func_L07_003B6BD0(void);

void func_L07_003B6550(u8 *a0) {
    u8 *d;

    d = *(u8 **)(a0 + 0x68);
    d[0x58] = 20;
    d[0x3F] = 0;
    d[0x5A] = 14;
    *(f32 *)(d + 0x40) = 1.0f;
    d[0x3E] = 3;
    *(u16 *)(d + 0x2A0) = *(u16 *)(d + 0x34);
    d[0x64] = 0;
    *(u16 *)(d + 0x2A2) = *(u16 *)(a0 + 0xB6);
    *(f32 *)(d + 0x94) = 1.2f;
    *(f32 *)(d + 0x90) = 2.5f;
    *(f32 *)(d + 0x98) = 1.2f;
    *(f32 *)(d + 0x9C) = 1.2f;
    *(f32 *)(d + 0xA0) = 3.1415927f;
    d[0x39] = 0;
    *(f32 *)(d + 0xC0) = 0.7853982f;
    *(f32 *)(d + 0xBC) = 0.0027222224f;
    *(f32 *)(d + 0xC4) = 0.5f;
    func_L01_00458A70(a0, 0.0019444445f, 0.116666675f, 0.0034906587f, 0.104719765f);
    *(void **)(d + 0x194) = func_L07_003B6BD0;
    *(void **)(d + 0x198) = func_L07_003B6B58;
    d[0x1AD] = 0xFF;
    *(s16 *)(d + 0x19C) = -1;
    *(void **)(d + 0x2A4) = func_L01_0044B550(a0);
    func_L07_003B6B58(a0);
}
/* localdecomp:end func_L07_003B6550 */
