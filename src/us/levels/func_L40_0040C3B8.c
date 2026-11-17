#include "common.h"

/* NTSC-U counterpart of func_L40_0040CA88 (src/levels/shared/L40_0040A4D0.c): 0.00392 -> 0.00272222; 0.0024 -> 0.00166667; 0.12 -> 0.1; 0.0100531 -> 0.00698132; 0.502655 -> 0.418879 */
#include "vu0.h"
extern void func_003BDA38(u8 *m, s32 a1, void *pos);
extern void func_L40_0040C828(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L40_0040C3B8(u8 *m);
extern void func_003BDA38(u8 *m, s32 a1, void *pos);

/* localdecomp:start func_L40_0040C3B8 */
__asm__(".extern D_L40_002412A0, 16");
extern s32 *D_L40_002412A0;
extern s32 func_L01_0044B550(u8 *m);
extern void func_L01_00458A70(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern u8 *func_003BCFB0(s32 cls, s32 a1);
extern void func_L01_00452E70(u8 *torso, u8 *m);
extern void func_L01_00441FB8(u8 *m, s32 a1, s32 a2);

/* The Ranger legs' state-0 init: home position, movement and turn settings, the torso (spawned
   again if it is gone), and the sparks of its arrival. */
s32 func_L40_0040C3B8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *t;

    *(vu0_v4 *)(v + 0x240) = *(vu0_v4 *)(m + 0x10);
    *(f32 *)(v + 0x240) = *(f32 *)(m + 0x10);
    *(f32 *)(v + 0x244) = *(f32 *)(m + 0x14);
    *(f32 *)(v + 0x248) = *(f32 *)(m + 0x18);
    *(s32 *)(v + 0x2A4) = 0;
    *(s32 *)(v + 0x2A8) = func_L01_0044B550(m);
    *(u8 *)(v + 0x170) = 4;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(u8 *)(v + 0x1A8) = 1;
    *(u8 *)(v + 0x1D7) = 1;
    *(u8 *)(v + 0x167) = 0x80;
    *(s16 *)(v + 0x16C) = 4;
    *(s16 *)(v + 0x16E) = 0xF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.5f;
    *(s32 *)(v + 0x1DC) = -1;
    *(u8 *)(v + 0x168) = 0;
    *(u8 *)(v + 0x169) = 0;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 20;
        *(f32 *)(v + 0x30) = 20.0f;
    }
    *(f32 *)(v + 0x40) = 2.0f;
    *(f32 *)(v + 0x288) = *(f32 *)(m + 0xF8);
    *(f32 *)(v + 0x70) = 0.7f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 1.9f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00272222236f;
    *(s32 *)(v + 0xAC) = -1;
    *(f32 *)(v + 0xA4) = 0.05f;
    func_L01_00458A70(m, 0.00166666671f, 0.100000009f, 0.00698131742f, 0.418879062f);
    *(u8 *)(m + 0x30) = 0xFF;
    *(s16 *)(m + 0x32) = 0xFF;
    t = *(u8 **)(v + 0x270);
    if (t == 0 || *(s16 *)(t + 0xAA) != 0x109E || *(u8 *)(t + 0x20) == 0xFE || *(u8 *)(t + 0x20) == 0xFF) {
        *(u8 **)(v + 0x270) = func_003BCFB0(0x109E, 0x80);
        func_L01_00452E70(*(u8 **)(v + 0x270), m);
    }
    func_003BDA38(m, 0, *(u8 **)(v + 0x270) + 0x10);
    if (*D_L40_002412A0 >= 2) {
        *(u8 *)(m + 0x62) = 1;
        *(u8 *)(*(u8 **)(v + 0x270) + 0x62) = 1;
    }
    *(u8 *)(*(u8 **)(v + 0x270) + 0x30) = 0xFF;
    *(s16 *)(*(u8 **)(v + 0x270) + 0x32) = 0xFF;
    *(s32 *)(v + 0x298) = 0;
    *(s32 *)(v + 0x294) = 0x10001;
    *(s32 *)(v + 0x340) = -1;
    func_L01_00441FB8(m, 1, 0);
    func_L40_0040C828(m, 0, 0, 0);
    *(f32 *)(v + 0x278) = -10.0f;
    *(u16 *)(m + 0x34) &= 0xFFBE;
    *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
    *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    if (*(u8 **)(v + 0x270) != 0) {
        *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xFFBE;
        *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(v + 0x270) + 0x24) + 0x44) & 0x1000;
        *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(v + 0x270) + 0x24) + 0x10);
    }
    func_L40_0040C1A8((vu0_v4 *)(m + 0x10));
    return 0;
}
/* localdecomp:end func_L40_0040C3B8 */
