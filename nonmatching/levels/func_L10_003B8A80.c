/* near miss (level 10, Zeldrin Starport): first full draft, about 130 differences at level 10 (file @ps2as), most of them the order of the 31 stores that initialise the Soldier Bot's 0x68 block (constants built inline and stored in an order gcc's scheduler does not give for this statement order), plus the argument setup of the two func_L10_003B9078 calls in the 0x328 branch (retail loads the shared a3 = 0 before the branch). A random statement-order search over the 31 stores reached 108 after 400 steps. In src/levels/10_zeldrin_starport/L10_003B5B48.c after func_L10_003B85A0 (which calls it) */
#include "common.h"

/* localdecomp:start func_L10_003B8A80 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B8A80;
extern u8 *D_L10_0021D1C0[];
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L10_003B9078(u8 *, s32, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);

s32 func_L10_003B8A80(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);

    p[0x170] = 0x1C;
    p[0x1A8] = 3;
    *(s32 *)(p + 0x334) = 1;
    *(s32 *)(p + 0x338) = 0;
    p[0x1D7] = 0;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    p[0x1DA] = 0;
    *(s16 *)(p + 0x198) = 0;
    p[0x172] = 0x11;
    *(f32 *)(p + 0x17C) = 0.64000005f;
    *(f32 *)(p + 0x184) = 0.0088f;
    *(f32 *)(p + 0x188) = 0.014800001f;
    *(f32 *)(p + 0x18C) = 0.016f;
    *(f32 *)(p + 0x19C) = 0.4f;
    p[0x1CE] = 6;
    p[0x1CF] = 0xC;
    p[0x1DB] = 0xFF;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 0.7853982f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.00392f;
    p[0x171] = 0x11;
    *(f32 *)(p + 0x180) = 0.12f;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    p[0x1CC] = 6;
    p[0x1CD] = 0xC;
    *(f32 *)(p + 0x74) = 0.5f;
    func_L01_0045BD78(m, 0.0064000003f, 0.12f, 0.010053097f, 0.25132743f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 0xA;
        *(f32 *)(p + 0x30) = 10.0f;
    }
    p[0x3E] = 1;
    p[0x39] = 1;
    *(f32 *)(p + 0x40) = 2.0f;
    *(u8 **)(p + 0x2DC) = func_003C24B0(0x1611, 0x80);
    func_L01_00456160(*(u8 **)(p + 0x2DC), m);
    m[0x30] = (*(u8 **)(p + 0x2DC))[0x30];
    *(u16 *)(m + 0x32) = *(u16 *)(*(u8 **)(p + 0x2DC) + 0x32);
    *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) |= 0x100;
    func_003C2F58(m, 0, *(u8 **)(p + 0x2DC) + 0x10);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF0) = *(f32 *)(m + 0xF0);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF4) = *(f32 *)(m + 0xF4);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF8) = *(f32 *)(m + 0xF8);
    func_0038D308(*(u8 **)(p + 0x2DC) + 0xC0, *(u8 **)(p + 0x2DC) + 0xF0);
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.5f;
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(p + 0x2DC) + 0x24) + 0x24) * 1.5f;
    if (*(s32 *)(p + 0x2EC) != 0) {
        *(V4_3B8A80 *)(p + 0x300) = *(V4_3B8A80 *)(m + 0x10);
        *(f32 *)(p + 0x2FC) = *(f32 *)(m + 0xF8);
        func_L01_004450F0(m, 0x1D, 4);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) |= 0x41;
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) &= 0xEFFF;
        *(s32 *)(*(u8 **)(p + 0x2DC) + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(p + 0x2DC), 1);
    } else if (*(s32 *)(p + 0x328) != 0) {
        if (*(s32 *)(p + 0x310) != -1) {
            func_L10_003B9078(m, 0xD, 0, 0);
            *(V4_3B8A80 *)(m + 0x10) = *(V4_3B8A80 *)(D_L10_0021D1C0[*(s32 *)(p + 0x310)] + 0x10);
            func_L01_004450F0(m, 1, 0);
        } else {
            func_L10_003B9078(m, 0xD, 0, 0);
            func_L01_004450F0(m, 1, 0);
        }
        *(s32 *)(p + 0x338) = 1;
    } else {
        func_L01_004450F0(m, 1, 0);
        if (m[0x43] != 0) {
            func_003C3A10(m, 0, 0, 0);
        }
        func_003C3A10(*(u8 **)(p + 0x2DC), 0, 0, 0);
    }
    if (*(s32 *)(p + 0x33C) != 0) {
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) |= 0x41;
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) &= 0xEFFF;
        *(s32 *)(*(u8 **)(p + 0x2DC) + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(p + 0x2DC), 1);
        func_L01_004450F0(m, 0x1D, 4);
    }
    return 0;
}
/* localdecomp:end func_L10_003B8A80 */
