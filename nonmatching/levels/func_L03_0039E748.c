/* near miss (level 3, Starship Phoenix): 67 differences: the stores, constants and callees match retail but the scheduling differs; retail also loads four float constants (0x3A9D4952, 0x3D75C290, 0x3AA4B5BF, 0x3D80ADFD) into $f12-$f15 for the func_L01_0045BD78 call that shift the register allocation; dead locals and stores under a false condition were folded away */
#include "common.h"

/* localdecomp:start func_L03_0039E748 */
void func_L01_0045BD78(void *);
void func_L03_0039EB90(void *);
void func_L03_0039EBE8(void *);

void func_L03_0039E748(void *arg0) {
    u8 *a = arg0;
    u8 *p;
    if (a[0x20] == 0) {
        p = *(u8 **)(a + 0x68);
        p[0x39] = 0;
        *(s32 *)(p + 0x23C) = 0;
        p[0x26D] = 0;
        p[0x80] = 4;
        p[0x82] = 3;
        p[0xE9] = 5;
        *(f32 *)(p + 0xAC) = 0.15000001f;
        p[0x86] = 0xFF;
        *(f32 *)(p + 0x8C) = 0.3f;
        *(f32 *)(p + 0x90) = 0.020000001f;
        *(f32 *)(p + 0x94) = 0.010000001f;
        *(f32 *)(p + 0x98) = 0.014f;
        *(f32 *)(p + 0x9C) = 0.00080000004f;
        p[0x58] = 0x14;
        p[0x5A] = 0xE;
        *(f32 *)(p + 0x40) = 1.0f;
        *(f32 *)(p + 0x160) = 1.5707964f;
        *(f32 *)(p + 0x180) = 0.24434610f;
        *(f32 *)(p + 0x17C) = 0.19600002f;
        *(f32 *)(p + 0x184) = 0.5f;
        *(void **)(p + 0x254) = func_L03_0039EBE8;
        *(void **)(p + 0x258) = func_L03_0039EB90;
        p[0xB8] = 0xFF;
        p[0x81] = 3;
        p[0xE8] = 5;
        p[0xEB] = 0xFF;
        *(f32 *)(p + 0xA0) = 0.5f;
        *(f32 *)(p + 0xA4) = 0.5f;
        *(f32 *)(p + 0x150) = 0.5f;
        *(f32 *)(p + 0x154) = 0.5f;
        *(f32 *)(p + 0x158) = 0.5f;
        *(f32 *)(p + 0x15C) = 0.5f;
        func_L01_0045BD78(p);
        *(s32 *)(p + 0x188) |= 0x10;
        func_L03_0039EB90(a);
        *(s32 *)(p + 0x300) = 0;
    }
}
/* localdecomp:end func_L03_0039E748 */
