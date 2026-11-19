/* near miss (level 10, Zeldrin Starport): 49 differences at level 10 with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as), down from about 130. In src/levels/10_zeldrin_starport/L10_003B5B48.c after func_L10_003B85A0 (which calls it).
 * What fixed it (130 to 49): (1) retail's 0x180 / call-argument constant is 0x3df5c290, which is 0.120000005f, not 0.12f (0x3df5c28f); (2) the constant 1 kept in a named local (`s32 one = 1;` for the stores at 0x334, 0x39, 0x3e and 0x338): retail keeps it in $s2 over the calls and stores it with `sw $s2,0x338`, a literal 1 after the branches is rematerialised as `addiu $v0,$zero,1` (130 to 77); (3) the order of the 31 initialising stores found by a hill climb (about 1200 compiles; 77 to 49; the draft order was retail's output order, which is not the source order that produces it: ties go to the later statement and constants with more uses are materialised first).
 * Left (49): about 37 in the stores (retail materialises 0.5 then 0.12 first, `mov.s $f13,$f11` right after it, and keeps the 0x180 store late; this C schedules the 0.12 chain last), and about 12 in the 0x328 branch: retail's != -1 path starts with `move $a3,$zero` (in the beq's delay slot) and jumps with `b` into one shared `jal func_L01_004450F0` whose delay slot is a nop, with the vector `sq` in the `b`'s delay slot; this C merges nothing there and puts the `sq` in the jal's delay slot. A single call after the if/else (110) and a local for the index (198) were worse. */
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
    s32 one = 1;

    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(s32 *)(p + 0x334) = one;
    *(s32 *)(p + 0x338) = 0;
    p[0x171] = 0x11;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    p[0x1D7] = 0;
    p[0x170] = 0x1C;
    p[0x1CC] = 6;
    p[0x1A8] = 3;
    *(f32 *)(p + 0x17C) = 0.64000005f;
    *(f32 *)(p + 0x184) = 0.0088f;
    p[0x1CD] = 0xC;
    *(f32 *)(p + 0x188) = 0.014800001f;
    *(f32 *)(p + 0x18C) = 0.016f;
    *(f32 *)(p + 0x7C) = 1.0f;
    p[0x1CE] = 6;
    p[0x1CF] = 0xC;
    p[0x1D8] = 0;
    *(f32 *)(p + 0x80) = 0.7853982f;
    p[0x1D9] = 0;
    p[0x1DB] = 0xFF;
    *(f32 *)(p + 0x19C) = 0.4f;
    *(f32 *)(p + 0x180) = 0.120000005f;
    *(f32 *)(p + 0x9C) = 0.00392f;
    p[0x1DA] = 0;
    *(s16 *)(p + 0x198) = 0;
    *(f32 *)(p + 0x74) = 0.5f;
    *(f32 *)(p + 0x70) = 0.7f;
    p[0x172] = 0x11;
    func_L01_0045BD78(m, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 0xA;
        *(f32 *)(p + 0x30) = 10.0f;
    }
    p[0x39] = one;
    p[0x3E] = one;
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
        *(s32 *)(p + 0x338) = one;
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
