#include "common.h"

INCLUDE_ASM("asm/levels", func_L22_003B3228);

INCLUDE_ASM("asm/levels", func_L22_003B5EF8);

/* localdecomp:start func_L22_003B6698 */
/* from the NTSC-U draft (func_L22_003B4E48) with PAL names and constants; the 0x40 store is a struct field so it does not depend on the D_001D545C load (sched order) */
typedef int Q_003B6698 __attribute__((mode(TI)));
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_003B6698;
extern S_003B6698 D_L22_00236640;
typedef struct { u8 pad[0x40]; f32 f40; } P_003B6698;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");

s32 func_L22_003B6698(u8 *m) {
    u8 *p;
    s32 id, b, c;

    m[0x30] = 64;
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.25f;
    p = *(u8 **)(m + 0x68);
    if (func_00382468(2)) {
        *(u16 *)(m + 0x34) |= 0x8000;
    }
    *(Q_003B6698 *)(p + 0x4E0) = *(Q_003B6698 *)(m + 0x10);
    *(Q_003B6698 *)(p + 0x4F0) = *(Q_003B6698 *)(m + 0x10);
    *(f32 *)(p + 0x448) = func_L01_00443A18(0.0f, 20.0f) * 0.017453292f;
    p[0x170] = 17;
    *(s32 *)(p + 0x390) = 100;
    *(s32 *)(p + 0x394) = 167;
    *(f32 *)(p + 0x35C) = 2.7925267f;
    *(f32 *)(p + 0x358) = -2.7925267f;
    *(f32 *)(p + 0x354) = 1.5707964f;
    p[0x1A8] = 4;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1D7] = 1;
    if (func_00382468(2)) {
        p[0x176] = 9;
        p[0x1D3] = 17;
        p[0x1D2] = 11;
    } else {
        p[0x1D3] = 19;
        p[0x176] = 10;
        p[0x1D2] = 10;
    }
    *(f32 *)(p + 0x17C) = 0.3f;
    *(f32 *)(p + 0x180) = 0.020000001f;
    *(f32 *)(p + 0x184) = 0.010000001f;
    *(f32 *)(p + 0x188) = 0.014f;
    *(f32 *)(p + 0x18C) = 0.00080000004f;
    p[0x1DA] = 4;
    p[0x1DB] = 255;
    p[0x1A9] = 1;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    *(f32 *)(p + 0x1A0) = *(f32 *)(m + 0x18) - 10.0f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x70) = 0.5f;
    *(f32 *)(p + 0x74) = 0.25f;
    *(f32 *)(p + 0x78) = 0.65f;
    *(f32 *)(p + 0x80) = 1.553343f;
    *(f32 *)(p + 0xA0) = 0.17453292f;
    *(f32 *)(p + 0x9C) = 0.002f;
    *(f32 *)(p + 0xA4) = 0.3f;
    func_L01_0045BD78(m, 0.0032000002f, 0.050000004f, 0.0050265486f, 0.12566371f);
    p[0x58] = 20;
    p[0x5A] = 14;
    if (*(s16 *)(p + 0x34) == 0) {
        *(f32 *)(p + 0x30) = 1.0f;
        *(u16 *)(p + 0x34) = 1;
    }
    id = *(u16 *)(m + 0xB2);
    if (D_L22_00236640.spent[(s16)id] || (b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)], b = (id & 1) ? (b >> 4) & 7 : b & 7)) {
        p[0x3E] = 1;
    } else {
        p[0x3E] = 3;
    }
    p[0x39] = 1;
    ((P_003B6698 *)p)->f40 = 0.5f;
    if (D_001D545C == 22) {
        p[0x64] = 0;
        p[0x3F] = 0;
    }
    *(s32 *)(p + 0x450) = 0;
    *(s32 *)(p + 0x4AC) = -1;
    *(s32 *)(p + 0x454) = 0;
    *(s32 *)(p + 0x458) = 0;
    *(s32 *)(p + 0x45C) = 0;
    *(s32 *)(p + 0x490) = 0;
    *(s32 *)(p + 0x494) = 0;
    *(s32 *)(p + 0x498) = 0;
    *(s32 *)(p + 0x49C) = 0;
    *(s32 *)(p + 0x4A0) = 0;
    *(s32 *)(p + 0x4A4) = 0;
    *(s32 *)(p + 0x460) = 0;
    *(s32 *)(p + 0x480) = 0;
    *(s32 *)(p + 0x484) = 0;
    *(s32 *)(p + 0x48C) = 0;
    *(s32 *)(p + 0x47C) = 0;
    id = *(u16 *)(m + 0xB2);
    if (D_L22_00236640.spent[(s16)id] || (c = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)], (id & 1) ? (c >> 4) & 7 : c & 7)) {
        (*(s32 *)(p + 0x4A0))++;
    }
    if (*(s32 *)(p + 0x488)) {
        *(u8 **)(p + 0x48C) = func_003C24B0(0x1A3C, 128);
        if (*(u8 **)(p + 0x48C)) {
            func_L01_00456160(*(u8 **)(p + 0x48C), m);
            (*(u8 **)(p + 0x48C))[0x30] = 0;
            *(u16 *)(*(u8 **)(p + 0x48C) + 0x32) = *(u16 *)(m + 0x32);
            *(s32 *)(*(u8 **)(p + 0x48C) + 0x98) = 0;
            *(u16 *)(*(u8 **)(p + 0x48C) + 0x34) |= 2;
        }
    }
    func_00382468(10);
    if (*(s32 *)(p + 0x470) != -1) {
        func_003C3A10(m, 0, func_00382468((*(u8 **)(*(u8 **)(m + 0x24) + 0x48))[0x10]), 0);
        func_L01_004450F0(m, 1, 0);
    } else {
        func_003C3A10(m, 0, func_00382468((*(u8 **)(*(u8 **)(m + 0x24) + 0x48))[0x10]), 0);
        func_L01_004450F0(m, 4, 1);
    }
    return 0;
}
/* localdecomp:end func_L22_003B6698 */
