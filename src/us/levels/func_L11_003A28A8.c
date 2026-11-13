#include "common.h"

/* NTSC-U counterpart of func_L11_003A4410 (src/levels/11_obani_moons/L11_003A2CD0.c): 0.0064 -> 0.00444444; 0.06 -> 0.05; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944 */
extern s32 func_L11_003A28A8(u8 *);

/* localdecomp:start func_L11_003A28A8 */
typedef int q_3A4410 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A4410;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L11_003A28A8(u8 *a0)
{
    u8 *v;
    V4_3A4410 m[4];

    *(s32 *)(a0 + 0x78) = 0x7F7F1010;
    v = *(u8 **)(a0 + 0x68);
    *(q_3A4410 *)(v + 0x310) = *(q_3A4410 *)(a0 + 0x10);
    func_003C5180(a0 + 0x10, m, 0);
    func_L01_0044E358(a0 + 0xC0, &m[0], &m[1]);
    v[0x170] = 0xA;
    v[0x1A8] = 3;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(f32 *)(v + 0x194) = 0.5f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    *(u16 *)(a0 + 0x34) |= 0x100;
    *(f32 *)(v + 0x9C) = 0.0f;
    *(s32 *)(v + 0xA8) |= 1;
    *(f32 *)(v + 0x70) = 0.45f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 60.0f;
    *(f32 *)(v + 0x80) = 1.3089969f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    func_L01_00458A70(a0, 0.00444444455f, 0.0500000045f, 0.00698131742f, 0.209439531f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 1;
        *(f32 *)(v + 0x30) = 1.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 0.75f;
    func_L01_00441FB8(a0, 1, 0);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L11_003A28A8 */
