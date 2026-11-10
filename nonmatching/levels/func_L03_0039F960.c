/* near miss (level 3, Starship Phoenix): 38 differences: structure, prologue, constants and call sequence match; the order of the ~35 independent stores in the middle block differs (retail 80,82,E9,AC,86,8C...; the C delays the 0x82/0xE9/0x86 byte stores), which also swaps a1/a2 and v0/v1; about 12 source permutations tried */
#include "common.h"

/* localdecomp:start func_L03_0039F960 */
void func_L03_0039FDE0(void *);
void func_L03_0039FE40(void *);
void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);

void func_L03_0039F960(u8 *arg0) {
    u8 *s;
    if (arg0[0x20] == 0) {
        s = *(u8 **)(arg0 + 0x68);
        s[0x80] = 4;
        s[0x82] = 9;
        s[0xE9] = 5;
        *(f32 *)(s + 0xAC) = 0.15f;
        s[0x86] = 255;
        *(f32 *)(s + 0x8C) = 0.3f;
        *(f32 *)(s + 0x90) = 0.020000001f;
        *(f32 *)(s + 0x94) = 0.010000001f;
        *(f32 *)(s + 0x98) = 0.014f;
        *(f32 *)(s + 0x9C) = 0.00080000004f;
        *(f32 *)(s + 0x118) = 0.25f;
        s[0x58] = 20;
        s[0x5A] = 14;
        *(f32 *)(s + 0x40) = 1.0f;
        *(f32 *)(s + 0x160) = 1.5707964f;
        *(f32 *)(s + 0x180) = 0.2443461f;
        *(f32 *)(s + 0x17C) = 0.19600002f;
        *(f32 *)(s + 0x184) = 0.5f;
        *(void **)(s + 0x254) = func_L03_0039FE40;
        *(void **)(s + 0x258) = func_L03_0039FDE0;
        s[0xB8] = 255;
        s[0x81] = 9;
        s[0xE8] = 5;
        s[0xEB] = 255;
        *(f32 *)(s + 0xA0) = 0.5f;
        *(f32 *)(s + 0xA4) = 0.5f;
        *(f32 *)(s + 0x150) = 0.5f;
        *(f32 *)(s + 0x154) = 0.5f;
        *(f32 *)(s + 0x158) = 0.5f;
        *(f32 *)(s + 0x15C) = 0.5f;
        s[0x39] = 0;
        *(s32 *)(s + 0x23C) = 0;
        s[0x26D] = 2;
        func_L01_0045BD78(arg0, 0.0012f, 0.060000002f, 0.0012566372f, 0.06283186f);
        *(s16 *)(s + 0x26A) = -1;
        func_L03_0039FDE0(arg0);
        *(s32 *)(s + 0x450) = 0;
    }
}
/* localdecomp:end func_L03_0039F960 */
