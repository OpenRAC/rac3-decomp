/* near miss (level 11, Obani Moons): 2 differences, with @ps2as on its file (inline float constants; the file has it since func_L11_003A8FE0): two float stores in the other order (retail stores 0x70 then 0x78, the C 0x78 then 0x70); every other instruction, both constant pools and the leftover $a1 = 6 are retail's. Found with a store-order search (about 600 orders of the 18 stores, one chained assignment of the four 0.5f stores); func_L01_0045BD78 takes (void *, f32, f32, f32, f32) and $a1 is a leftover */
#include "common.h"

/* localdecomp:start func_L11_003A9B30 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L11_003A9B30(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);

    *(s16 *)(a0 + 0x7C) = 0xFF;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    v[0x1A8] = 3;
    v[0x1DB] = 0xFF;
    v[0x170] = 6;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(f32 *)(v + 0x78) = *(f32 *)(v + 0x74) = *(f32 *)(v + 0x194) = *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x70) = 0.7f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 0.7853982f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, 0.020000001f, 0.40000004f, 0.010053097f, 0.25132743f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 100;
        *(f32 *)(v + 0x30) = 100.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 2.0f;
    func_L01_004450F0(a0, 1, 0);
    if (a0[0x43] != 2) {
        func_003C3A10(a0, 2, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L11_003A9B30 */
