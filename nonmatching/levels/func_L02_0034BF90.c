/* Level 02 (Florana), PAL. 139 diff with check.py --target level_02. 139 differences, inflated by one cause: retail loads `309.0f` into `$f2` before the first compare, copies x with `mov.s $f3,$f0` and reloads 309.0f at the join (4 more instructions, shifting every later branch); this C keeps one constant register. The argument order of `func_L01_00451FE0` (the `mov.s $f14/$f15/$f17` interleaved with `$a3/$t0..$t3`) and of the `func_L01_00456C98` calls also differ. Needs `@ps2as` (set for L02_003484D8.c). */
#include "common.h"
extern u8 D_001D66B0;
extern u8 D_001E1300[];
__asm__(".extern D_001E1300, 16");
s32 func_L02_0034C308(void *);
void func_L02_0034C7B8(void *);
void func_003C7C38(void *);
void func_L01_0044FD88(void *, void *, s32, s32);
s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
void func_L01_003A6BB0(void *);
void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_L01_00452860(void *, void *, s32);
void func_L01_00456BD0(void *, s32);
void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);

s32 func_L02_0034BF90(u8 *a) {
    u8 *s = *(u8 **)(a + 0x68);
    f32 x;
    f32 y;
    if (a[0x20] == 0 && func_L02_0034C308(a) != 0) return 1;
    if (*(u8 **)(s + 0xB14) != 0) {
        *(s32 *)(*(u8 **)(s + 0xB14) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(s + 0xB14) + 0x24) + 0x10);
        func_003C7C38(*(void **)(s + 0xB14));
    }
    if (s[0x3E] == 2) {
        func_L02_0034C7B8(a);
        return 1;
    }
    if (a[0xBC] == 0) func_L01_0044FD88(a, *(void **)(s + 0x2E0), 0, 0);
    if (a[0x20] != 0x17) {
        if (func_L01_00452FB0(a, s + 0x160, 0, 0, 0) != 0) {
            if (*(s32 *)(s + 0xA30) != -1) *(s32 *)(s + 0xA30) = -1;
            func_L01_003A6BB0(a);
        }
    }
    if (*(u16 *)(a + 0x7C) != 0) {
        if (*(f32 *)(s + 0x30) <= 2.0f) {
            func_L01_00451FE0(a, 0x38, &D_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            *(u16 *)(a + 0x7C) = 0;
        }
    }
    if (s[0x5E] != 0) {
        func_L02_0034C7B8(a);
        return 1;
    }
    x = *(f32 *)(a + 0x18);
    y = *(f32 *)(s + 0xA08);
    if (x < 309.0f && 309.0f < y) {
        func_L02_0034C7B8(a);
        return 1;
    }
    if (y < 309.0f && x < 25.0f) {
        func_L02_0034C7B8(a);
        return 1;
    }
    func_L01_00452860(a, s + 0x30, 0);
    if (s[0x5F] != 0) {
        func_L01_00456BD0(a, 3);
        if (a[0x95] == 0)
            func_L01_00456C98(a, *(s32 *)(s + 0x2C0), (s32)(s + 0xA00), 0, 0, 0, 3, 0, 0, 0, *(f32 *)(s + 0x2C4), 10.0f, 1.0f);
        else
            func_L01_00456C98(a, *(s32 *)(s + 0x2C8), (s32)(s + 0xA00), 0, 0, 0, 3, 0, 0, 0, *(f32 *)(s + 0x2CC), 10.0f, 1.0f);
    } else {
        if (a[0x20] != 0x1A) func_L01_00456BD0(a, 3);
        if (a[0x95] == 0)
            func_L01_00456C98(a, *(s32 *)(s + 0x2C0), (s32)(s + 0xA00), 0, 0, 0, 1, 0, 0, 0, *(f32 *)(s + 0x2C4), 10.0f, 1.0f);
        else
            func_L01_00456C98(a, *(s32 *)(s + 0x2C8), (s32)(s + 0xA00), 0, 0, 0, 1, 0, 0, 0, *(f32 *)(s + 0x2CC), 10.0f, 1.0f);
    }
    if (a[0x31] != 0) {
        if (func_L01_0040E548(D_001E1300, a + 0x10) < 576.0f) {
            func_L01_004472C0(a);
            a[0x6F] = 0x16;
        }
    }
    return 0;
}
