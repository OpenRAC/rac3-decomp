#include "common.h"

/* NTSC-U counterpart of func_L09_003BBB58 (src/levels/09_tyhrranosis/L09_003B8580.c) */
#include "vu0.h"
#include "vu0.h"
extern u8 D_001426E0[];
extern u8 *D_L09_001E011C;
extern void func_00399F90(void);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(u8 *, u8);

/* localdecomp:start func_L09_003BA2E0 */
extern u8 *D_L09_001E011C;
__asm__(".extern D_L09_001E011C, 16");
extern u8 D_001426E0[];
extern void func_00399F90(void);
extern void func_00388440(void *, s32, s32);
extern void func_L01_00437350(void *, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(u8 *, u8);

s32 func_L09_003BA2E0(u8 *a0) {
    u8 *p;
    u8 *e;
    u8 *g;
    s32 i;
    if (a0[0x20] != 0) {
        return 0;
    }
    p = *(u8 **)(a0 + 0x68);
    *(s16 *)(p + 0x108) = 0;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    *(u16 *)(a0 + 0x34) |= 0x2004;
    a0[0x30] = *(s16 *)(a0 + 0x32) = 200;
    *(f32 *)(p + 0x100) = 0.5f;
    *(f32 *)(p + 0x104) = 0.5f;
    *(f32 *)(p + 0x10C) = 0.15f;
    p[0x118] = 0xFF;
    p[0xE1] = 0xFF;
    p[0xE2] = 4;
    p[0xE0] = 0x16;
    p[0xE6] = 4;
    p[0x14B] = 0xFF;
    p[0x142] = 6;
    p[0x143] = 0x10;
    p[0x147] = 1;
    *(f32 *)(p + 0x12C) = 0.05f;
    *(f32 *)(p + 0x194) = 1.5f;
    *(s32 *)(p + 0xEC) = 0;
    *(s32 *)(p + 0xF0) = 0;
    *(s32 *)(p + 0xF4) = 0;
    *(s32 *)(p + 0xF8) = 0;
    *(s32 *)(p + 0xFC) = 0;
    p[0x148] = 0;
    p[0x149] = 0;
    p[0x14A] = 0;
    *(f32 *)(p + 0x190) = 1.0f;
    *(f32 *)(p + 0x198) = 1.0f;
    *(f32 *)(p + 0x19C) = 1.0f;
    *(f32 *)(p + 0x1A0) = 1.30899692f;
    *(f32 *)(p + 0x1C0) = 1.04719758f;
    *(f32 *)(p + 0x1BC) = 0.0027222223579883575f;
    *(f32 *)(p + 0x1C4) = 1.0f;
    *(s32 *)(p + 0x1C8) |= 2;
    *(f32 *)(p + 0x40) = 2.5f;
    p[0x39] = 1;
    p[0x3E] = 3;
    p[0x3F] = 0;
    p[0x64] = 0;
    if (*(s16 *)(p + 0x34) == 0 || *(f32 *)(p + 0x30) <= *(f32 *)(p + 0xEC)) {
        *(s16 *)(p + 0x34) = 500;
        *(f32 *)(p + 0x30) = 500.0f;
    }
    g = D_001426E0;
    if (g[0x3C] == 0) {
        g[0x3C] |= 1;
        func_00399F90();
    }
    for (i = 0; i < 8; i++) {
        if ((u32)i < 8 && ((D_001426E0[0x3C] >> i) & 1)) {
            *(f32 *)(p + 0x30) = *(f32 *)(p + 0x30) * ((f32)(p + i)[0xD44] * 0.01f);
            *(s16 *)(p + 0x34) = *(f32 *)(p + 0x30);
            break;
        }
    }
    if (p[0x44] == 0) {
        p[0x44] = 3;
    }
    if (p[0x45] == 0) {
        p[0x45] = 2;
    }
    if (p[0x46] == 0) {
        p[0x46] = 5;
    }
    p[0x58] = 0x28;
    p[0x5A] = 0x60;
    func_00388440(p + 0x280, 0, 0x480);
    func_00388440(p + 0xB80, 0, 0x80);
    func_00388440(p + 0xC00, 0, 0x40);
    func_L01_00437350(a0, 0x33, p + 0xC00);
    func_00388440(p + 0xC40, 0, 0x40);
    func_L01_00437350(a0, 0x32, p + 0xC40);
    e = D_L09_001E011C + (*(s32 *)(p + 0xCD0) << 8);
    if (e != 0) {
        func_003BE4F0(e, 0, 0, 0);
        p[0xD2C] = 1;
    }
    p[0xD40] = 1;
    *(s16 *)(p + 0xD32) = 7200;
    p[0xD41] = 0;
    p[0xD43] = *(f32 *)(p + 0x30) / 250.0f - 1.0f;
    func_003BE4F0(a0, 8, 0, 0);
    func_L01_00441FB8(a0, 1, 0);
    func_L01_00442050(a0, 0);
    return 1;
}
/* localdecomp:end func_L09_003BA2E0 */
