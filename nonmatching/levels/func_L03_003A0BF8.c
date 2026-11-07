/* near miss (level 3, Starship Phoenix): 39 differences, scheduling and register allocation: the C emits the sb 0x82/0xE9 stores after the swc1 stores where retail has them before swc1 0xAC, 0.3 and 0.15 are in swapped float registers and the integer constant registers differ; store reorders (move, swap, reversed, bytes-floats-words) and a typed struct gave 39-72 */
#include "common.h"

/* localdecomp:start func_L03_003A0BF8 */
void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
void func_L03_003A1050(void *);
void func_L03_003A10A8(void *);

void func_L03_003A0BF8(u8 *arg0) {
    u8 *s;
    if (arg0[0x20] == 0) {
        s = *(u8 **)(arg0 + 0x68);
        s[0x39] = 0;
        *(s32 *)(s + 0x23C) = 0;
        s[0x80] = 4;
        s[0x82] = 7;
        s[0xE9] = 5;
        *(f32 *)(s + 0xAC) = 0.15f;
        s[0x86] = 0xFF;
        *(f32 *)(s + 0x8C) = 0.3f;
        *(f32 *)(s + 0x90) = 0.020000001f;
        *(f32 *)(s + 0x94) = 0.010000001f;
        *(f32 *)(s + 0x98) = 0.014f;
        *(f32 *)(s + 0x9C) = 0.00080000004f;
        s[0x58] = 0x14;
        s[0x5A] = 0xE;
        *(f32 *)(s + 0x40) = 1.0f;
        *(f32 *)(s + 0x160) = 1.5707964f;
        *(f32 *)(s + 0x180) = 0.2443461f;
        *(f32 *)(s + 0x17C) = 0.19600002f;
        *(f32 *)(s + 0x184) = 0.5f;
        *(void **)(s + 0x254) = func_L03_003A10A8;
        *(void **)(s + 0x258) = func_L03_003A1050;
        s[0x26D] = 2;
        s[0xB8] = 0xFF;
        s[0x81] = 7;
        s[0xE8] = 5;
        s[0xEB] = 0xFF;
        *(f32 *)(s + 0xA0) = 0.5f;
        *(f32 *)(s + 0xA4) = 0.5f;
        *(f32 *)(s + 0x150) = 0.5f;
        *(f32 *)(s + 0x154) = 0.5f;
        *(f32 *)(s + 0x158) = 0.5f;
        *(f32 *)(s + 0x15C) = 0.5f;
        func_L01_0045BD78(arg0, 0.0012f, 0.060000002f, 0.0012566372f, 0.06283186f);
        *(s16 *)(s + 0x26A) = -1;
        func_L03_003A1050(arg0);
        *(s32 *)(s + 0x300) = 0;
    }
}
/* localdecomp:end func_L03_003A0BF8 */
