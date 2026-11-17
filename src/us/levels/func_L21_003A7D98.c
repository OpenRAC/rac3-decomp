#include "common.h"

/* NTSC-U counterpart of func_L21_003A97E8 (src/levels/21_obani_draco/L21_003A8050.c) */
#include "vu0.h"
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L21_003A7D98(u8 *arg0);

/* localdecomp:start func_L21_003A7D98 */
extern u8 D_001426E0[];
extern void func_00399F90(void);
extern void func_003BE4F0(void *, s32, s32, s32);
void func_L01_00441FB8(void *, s32, s32);

s32 func_L21_003A7D98(u8 *arg0) {
    u8 *v;
    s32 i;
    u8 *arr;

    if (arg0[0x20] != 0) {
        return 0;
    }
    v = *(u8 **)(arg0 + 0x68);
    *(s16 *)(v + 0x108) = 0;
    *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
    v[0xE0] = 0x18;
    v[0x118] = 0xFF;
    v[0xE1] = 0x15;
    v[0xE2] = 0x17;
    v[0xE6] = 0x18;
    *(f32 *)(v + 0x10C) = 0.15f;
    v[0x147] = 1;
    *(f32 *)(v + 0xEC) = 0.25f;
    *(f32 *)(v + 0xF0) = 0.0166666675359f;
    *(f32 *)(v + 0xF4) = 0.00694444449618f;
    *(f32 *)(v + 0xF8) = 0.00972222257406f;
    *(f32 *)(v + 0xFC) = 0.000555555569008f;
    v[0x14B] = 0xFF;
    *(f32 *)(v + 0x100) = 0.5f;
    *(f32 *)(v + 0x104) = 0.5f;
    v[0x148] = 0;
    v[0x149] = 0;
    v[0x14A] = 0;
    v[0x142] = 0;
    v[0x143] = 0;
    *(f32 *)(v + 0x110) = *(f32 *)(arg0 + 0x18) - 10.0f;
    *(f32 *)(v + 0x180) = 1.0f;
    *(f32 *)(v + 0x190) = 0.1f;
    *(f32 *)(v + 0x12C) = 0.2f;
    *(f32 *)(v + 0x194) = 0.2f;
    *(f32 *)(v + 0x128) = 0.01f;
    *(f32 *)(v + 0x17C) = 0.5f;
    *(f32 *)(v + 0x198) = 2.0f;
    *(f32 *)(v + 0x19C) = 2.0f;
    *(f32 *)(v + 0x1A0) = 1.30899692f;
    *(f32 *)(v + 0x1C0) = 3.14159274f;
    *(f32 *)(v + 0x1BC) = 0.00272222235799f;
    *(f32 *)(v + 0x1C4) = 0.5f;
    *(f32 *)(v + 0x40) = 1.2f;
    v[0x3E] = 3;
    v[0x39] = 0;
    v[0x3F] = 0;
    v[0x64] = 0;

    if (D_001426E0[0xD5] == 0) {
        D_001426E0[0xD5] |= 1;
        func_00399F90();
    }
    i = 0;
    arr = v + 0x310;
    for (; i < 8; i++) {
        if ((u32)i < 8 && ((D_001426E0[0xD5] >> i) & 1)) {
            *(f32 *)(v + 0x30) = *(f32 *)(v + 0x30) * ((f32)arr[i] * 0.01f);
            *(s16 *)(v + 0x34) = *(f32 *)(v + 0x30);
            break;
        }
    }
    if (*(s16 *)(v + 0x34) == 0 || *(f32 *)(v + 0x30) <= 0.0f) {
        *(s16 *)(v + 0x34) = 300;
        *(f32 *)(v + 0x30) = 300.0f;
    }
    if (v[0x44] == 0) {
        v[0x44] = 2;
    }
    if (v[0x45] == 0) {
        v[0x45] = 3;
    }
    if (v[0x46] == 0) {
        v[0x46] = 5;
    }
    v[0x58] = 0x28;
    v[0x5A] = 0x60;
    v[0x300] = 3;
    if (arg0[0x43] != 0) {
        func_003BE4F0(arg0, 0, 0, 0);
    }
    func_L01_00441FB8(arg0, 1, 0);
    return 1;
}
/* localdecomp:end func_L21_003A7D98 */
