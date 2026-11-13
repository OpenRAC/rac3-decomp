#include "common.h"

/* NTSC-U counterpart of func_L23_003AF9B8 (src/levels/23_holostar_studios_clank/L23_003AD800.c): 0.00392 -> 0.00272222 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern f32 D_L23_001DE288;
extern void func_L23_003AE0B8(u8 *self);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L23_003AE0B8 */
__asm__(".extern D_L23_001DE284, 4");
__asm__(".extern D_L23_001DE288, 4");
extern f32 D_L23_001DE284;
extern f32 D_L23_001DE288;
extern void func_L01_00441FB8(void *, s32, s32);

void func_L23_003AE0B8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);

    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    *(f32 *)(v + 0x40) = 1.0f;
    v[0x39] = 0;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 0x4B;
        *(f32 *)(v + 0x30) = 75.0f;
    }
    if (*(s32 *)(v + 0x220) != 0) {
        *(f32 *)(v + 0x30) *= D_L23_001DE284;
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x30);
    }
    *(f32 *)(v + 0x70) = D_L23_001DE288;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0x74) = *(f32 *)(v + 0x70);
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.5f;
    *(f32 *)(v + 0x80) = 1.4835298f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00272222236f;
    *(V4 *)(v + 0x250) = *(V4 *)(self + 0x10);
    *(V4 *)(v + 0x290) = *(V4 *)(self + 0x10);
    *(f32 *)(v + 0x24C) = *(f32 *)(self + 0xF8);
    *(s32 *)(v + 0x218) = 0;
    *(s32 *)(v + 0x244) = 0;
    *(s32 *)(v + 0x21C) = 0;
    *(s32 *)(v + 0x240) = 0;
    *(s32 *)(v + 0x228) = 0;
    *(s32 *)(v + 0x2BC) = 0;
    *(s32 *)(v + 0x210) = 0;
    if (self[0x21] != 0xFF)
        func_L01_00441FB8(self, 1, 0);
    else
        func_L01_00441FB8(self, 4, 2);
}
/* localdecomp:end func_L23_003AE0B8 */
