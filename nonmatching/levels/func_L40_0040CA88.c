/* func_L40_0040CA88: near miss, 12 diff at level 40. 760 bytes, 14 levels (40-53),
   src/levels/shared/L40_0040A4D0.c (flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as). Written from asm (2026-11-11). Guber state 0 (from
   func_L40_0040C6F0): home pVar+0x240 = position, the walker's constants (pVar +0x70 .. +0xAC and
   +0x167 .. +0x1DC), health 20 if it has none, the torso spawned again if it is missing or dead,
   then the spawn sparks (func_L40_0040C878).

   Every instruction is retail's; two stores are placed elsewhere. Each shares its constant's
   register with a later store (+0x1D7 and +0x1A8 both 1, +0x7C and +0x78 both 1.0): ours emits it
   next to its partner, retail early, where its source place is. That looks like two pseudos
   (each store ending its own's life, which sched1 prefers) that reload_cse merged afterwards;
   cse always gives one pseudo here.
   Tried: the two pairs as named constants at the top (194: they live across the call) or in a
   block of their own (12), the stores of a pair in either order (10-12) and moved earlier (12-191),
   the stores through the pointer table's struct pointers (pVar+0x160, +0x70: 195).
   Moving each first store after its partner gives 10 diff (the block order then differs the
   other way). Context: the file's prelude and earlier blocks. */
#include "common.h"
#include "vu0.h"

extern void func_003C2F58(u8 *m, s32 a1, void *pos);
/* localdecomp:start func_L40_0040CA88 */
extern void func_L40_0040C878(vu0_v4 *pos);
extern void func_L40_0040CEF8(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L01_004450F0(u8 *m, s32 state, s32 a2);
extern u8 *D_L40_00241120[] __attribute__((section(".sdata")));
extern s32 func_L01_0044E7D8(void);
extern void func_L01_0045BD78(u8 *m, f32 a, f32 b, f32 c, f32 d);
extern u8 *func_003C24B0(s32 cls, s32 a1);
extern void func_L01_00456160(u8 *torso, u8 *m);

/* Guber state 0: home = position, the walker's constants, health 20 if none, the torso if it
   is missing, then the spawn sparks. */
s32 func_L40_0040CA88(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *t;

    *(vu0_v4 *)(v + 0x240) = *(vu0_v4 *)(m + 0x10);
    *(f32 *)(v + 0x240) = *(f32 *)(m + 0x10);
    *(f32 *)(v + 0x244) = *(f32 *)(m + 0x14);
    *(f32 *)(v + 0x248) = *(f32 *)(m + 0x18);
    *(s32 *)(v + 0x2A4) = 0;
    *(s32 *)(v + 0x2A8) = func_L01_0044E7D8();
    *(u8 *)(v + 0x170) = 4;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(u8 *)(v + 0x1D7) = 1;
    *(u8 *)(v + 0x167) = 0x80;
    *(s16 *)(v + 0x16C) = 4;
    *(s16 *)(v + 0x16E) = 0xF;
    *(u8 *)(v + 0x1A8) = 1;
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
    *(f32 *)(v + 0x70) = 0.699999988f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 1.89999998f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392000005f;
    *(s32 *)(v + 0xAC) = -1;
    *(f32 *)(v + 0xA4) = 0.0500000007f;
    *(f32 *)(v + 0x78) = 1.0f;
    func_L01_0045BD78(m, 0.00240000011f, 0.120000005f, 0.0100530973f, 0.50265485f);
    *(u8 *)(m + 0x30) = 0xFF;
    *(u16 *)(m + 0x32) = 0xFF;
    t = *(u8 **)(v + 0x270);
    if (t == 0 || *(s16 *)(t + 0xAA) != 0x109E || *(u8 *)(t + 0x20) == 0xFE || *(u8 *)(t + 0x20) == 0xFF) {
        *(u8 **)(v + 0x270) = func_003C24B0(0x109E, 0x80);
        func_L01_00456160(*(u8 **)(v + 0x270), m);
    }
    func_003C2F58(m, 0, *(u8 **)(v + 0x270) + 0x10);
    if (*(s32 *)D_L40_00241120[0] >= 2) {
        *(u8 *)(m + 0x62) = 1;
        *(u8 *)(*(u8 **)(v + 0x270) + 0x62) = 1;
    }
    *(u8 *)(*(u8 **)(v + 0x270) + 0x30) = 0xFF;
    *(u16 *)(*(u8 **)(v + 0x270) + 0x32) = 0xFF;
    *(s32 *)(v + 0x298) = 0;
    *(s32 *)(v + 0x294) = 0x10001;
    *(s32 *)(v + 0x340) = -1;
    func_L01_004450F0(m, 1, 0);
    func_L40_0040CEF8(m, 0, 0, 0);
    *(f32 *)(v + 0x278) = -10.0f;
    *(u16 *)(m + 0x34) &= 0xFFBE;
    *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
    *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    if (*(u8 **)(v + 0x270) != 0) {
        *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xFFBE;
        *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(v + 0x270) + 0x24) + 0x44) & 0x1000;
        *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(v + 0x270) + 0x24) + 0x10);
    }
    func_L40_0040C878((vu0_v4 *)(m + 0x10));
    return 0;
}
/* localdecomp:end func_L40_0040CA88 */
