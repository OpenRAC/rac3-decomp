/* functional: medium-high. Compiles in context, not exact (181 diff: layout/registers). Offsets, constants (exact float bit patterns), gp globals and callee arguments re-read against retail; scan loop over the object array (stride 0x100, limit D_L01_001E0020) claims up to 8 matching mobs (types 0x1BAF/0x1BBE/0x1E8D). */
#include "vu0.h"
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0020;
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00459218(void *, void *, s32, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern Cls_00352C58 *func_L01_0043B548(s32, s32);
s32 func_L01_00352E60(S_351E18m *m) {
    u8 *obj = (u8 *)m;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *p;
    s32 i = 0;
    s32 k;
    s32 h;
    s32 g;
    f32 r;
    Cls_00352C58 *c;
    if (func_00382468(2) != 0) *(u16 *)(obj + 0x34) |= 0x8000;
    obj[0x30] = 0x40;
    r = func_003824E0(1.25f, 1.5f);
    *(f32 *)(v + 0x5D4) = r;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * r;
    *(s16 *)(v + 0x5DC) = 0x19;
    *(s16 *)(v + 0x5DE) = 0;
    for (k = 7; k >= 0; k--) *(s32 *)(v + 0x3F0 + k * 4) = 0;
    p = D_L01_001E001C;
    while (p < (u8 *)D_L01_001E0020) {
        h = *(s16 *)(p + 0xAA);
        if (h == 0x1BAF || h == 0x1BBE || h == 0x1E8D) {
            *(u8 **)(v + 0x3F0 + i * 4) = p;
            *(s32 *)(p + 0x98) = 0;
            *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
            i++;
            func_L01_004AA7E8(p, 1);
            if (i >= 8) break;
        }
        p += 0x100;
    }
    if (*(s32 *)(v + 0x240) != 0) {
        g = D_001D545C;
        if (g == 1) *(s32 *)(v + 0x478) = g;
        else *(s32 *)(v + 0x478) = 0;
    } else {
        *(s32 *)(v + 0x478) = 0;
    }
    *(s32 *)(v + 0x3E8) = 0;
    func_L01_00459218(obj, v + 0x410, 12, v + 0x3E8);
    *(vu0_q *)(v + 0x2F0) = *(vu0_q *)(obj + 0x10);
    *(vu0_q *)(v + 0x310) = *(vu0_q *)(obj + 0x10);
    r = func_L01_00443A18(0.0f, 15.0f);
    *(f32 *)(v + 0x308) = r * 0.0174532924f;
    v[0x170] = 0x10;
    v[0x1A8] = 4;
    *(f32 *)(v + 0x194) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.150000006f;
    v[0x1D7] = 1;
    *(f32 *)(v + 0x190) = 0.5f;
    if (func_00382468(2) != 0) {
        v[0x176] = 7;
        v[0x1D3] = 0x11;
        v[0x1D2] = 0xB;
    } else {
        v[0x176] = 8;
        v[0x1D3] = 0x13;
        v[0x1D2] = 0xA;
    }
    v[0x1DA] = 4;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x188) = 0.0140000004f;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1A9] = 1;
    *(f32 *)(v + 0x17C) = 0.300000012f;
    *(f32 *)(v + 0x180) = 0.0200000014f;
    *(f32 *)(v + 0x184) = 0.0100000007f;
    *(f32 *)(v + 0x18C) = 0.000800000038f;
    *(f32 *)(v + 0x1A0) = *(f32 *)(obj + 0x18) - 10.0f;
    if (D_001D545C == 12) *(s16 *)(v + 0x1AA) = 0x280B;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x70) = 0.400000006f;
    *(f32 *)(v + 0x74) = 0.25f;
    *(f32 *)(v + 0x80) = 1.39626336f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00200000009f;
    func_L01_0045BD78(obj, 0.00480000023f, 0.0800000057f, 0.00502654864f, 0.125663713f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(f32 *)(v + 0x30) = 1.0f;
        *(s16 *)(v + 0x34) = 1;
    }
    *(f32 *)(v + 0x40) = 0.5f;
    v[0x3E] = 1;
    v[0x38] = 0;
    v[0x39] = 1;
    v[0x5E] = 0;
    v[0x5F] = 0;
    *(s32 *)(v + 0x2E0) = 0;
    *(s16 *)(v + 0x2E4) = 0;
    *(s16 *)(v + 0x2E6) = 0;
    *(s32 *)(v + 0x2E8) = 0;
    *(s32 *)(v + 0x330) = 0;
    if (*(s32 *)(v + 0x47C) != 0) {
        v[0x3F] = 0;
        v[0x64] = 0;
    }
    if (*(f32 *)(v + 0x2DC) < *(f32 *)(v + 0x2D4)) {
        *(f32 *)(v + 0x2DC) = *(f32 *)(v + 0x2D4) + *(f32 *)(v + 0x2D4);
    }
    if (*(s32 *)(v + 0x240) != 0) obj[0x62] = 0;
    if (D_001D545C == 1) {
        h = *(s16 *)(obj + 0xB2);
        if (h == 0xA) {
            obj[0x62] = 0;
        } else if (h == 12 || h == 14 || h == 16 || h == 0x255 || h == 0x256) {
            obj[0x62] = 0;
        }
    }
    if (*(s32 *)(v + 0x240) > 0) {
        c = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(v + 0x240) = -1;
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
        v[0x24F] = 5;
        v[0x24E] = 0x11;
        c->f0(obj);
        return 0;
    }
    if (*(s16 *)(v + 0x346) != 0 || *(s32 *)(v + 0x47C) != 0) {
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
        func_L01_004450F0(obj, 0x12, 7);
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(obj, 1);
        *(s16 *)(v + 0x2E6) = 0xF;
        return 0;
    }
    if (*(s16 *)(v + 0x344) != 0) {
        func_L01_004450F0(obj, 0x12, 7);
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(obj, 1);
        return 0;
    }
    if (*(s32 *)(v + 0x334) != -1) {
        func_L01_004450F0(obj, 1, 0);
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, func_00382498(0, 10), 0);
        }
        return 0;
    }
    func_L01_004450F0(obj, 4, 1);
    if (obj[0x43] != 3) {
        func_003C3A10(obj, 3, func_00382498(0, 10), 0);
    }
    if (*(s32 *)(v + 0x340) != 0) {
        k = func_00382498(0, 7);
        if (obj[0x43] != 2) func_003C3A10(obj, 2, k << 1, 0);
        func_L01_004450F0(obj, 2, -1);
    }
    return 0;
}
