#include "common.h"

/* NTSC-U counterpart of func_L11_003A9B30 (src/levels/11_obani_moons/L11_003A8FE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern s32 func_L11_003A7E98(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L11_003A7E98 */
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);

s32 func_L11_003A7E98(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);

    *(u16 *)(a0 + 0x7C) = 0xFF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.5f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    v[0x170] = 6;
    v[0x1A8] = 3;
    *(f32 *)(v + 0x19C) = 0.150000006f;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x70) = 0.699999988f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 0.785398185f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.0027222223579883575f;
    func_L01_00458A70(a0, 0.013888888992369175f, 0.3333333432674408f, 0.0069813174195587635f, 0.20943953096866608f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(u16 *)(v + 0x34) = 100;
        *(f32 *)(v + 0x30) = 100.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 2.0f;
    func_L01_00441FB8(a0, 1, 0);
    if (a0[0x43] != 2) {
        func_003BE4F0(a0, 2, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L11_003A7E98 */
