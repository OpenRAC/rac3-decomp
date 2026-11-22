/* PAL near miss (b30 J6): 19 words differ, all of them one register swap: retail keeps the first parameter `a` in $s1 and the pointer `r`
 * (func_00382348's result) in $s2; ours has `a` in $s2 and `r` in $s1. Global-alloc priorities (floor_log2(refs) * refs / live): a = 9 refs over
 * 86 insns (0.314), r = 8 refs over 73 insns (0.329), so r is allocated first; one more reference to `a` flips it (a dummy `|| a == 0` test gives
 * 7 words but adds a branch). No code-free extra reference found (tried: variable forms, switch for the t cases, `!r`, an extra temp for the
 * func_L01_00449020 result). Everything else is retail's: layout (the two func_L01_003ACCD8 calls cross-jump into one block), the `% 8` pair,
 * the mixed $gp / lui read of D_L01_001DFB40 (a single `g = D_L01_001DFB40` after the join), the 64-bit mask test.
 * Check with: python tools/check.py nonmatching/levels/func_L01_003ACD38.c func_L01_003ACD38 --no-context
 */
#include "common.h"

extern void func_L01_003ACCD8(void *a, u8 *m);

/* localdecomp:start func_L01_003ACD38 */
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern u8 *func_00382348(void *);
extern s32 func_L01_00448FF0(void *);
extern s32 func_L01_00452FB0(void *, s32, s32, s32, s32);
extern void func_L01_00445170(void *, s32);
extern s32 func_L01_00449020(void *);
extern void func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L01_003ACD38(u8 *a, u8 *m) {
    u8 *r;
    s32 t;
    s32 g;

    if (*(void **)(m + 0x64) == 0) {
        return a[0x20] != 1;
    }
    r = func_00382348(*(void **)(m + 0x64));
    if (r == 0) {
        return 1;
    }
    if (r[0xE] == 2 || r[0x2E] != 0) {
        func_L01_003ACCD8(a, m);
        return 1;
    }
    t = func_L01_00452FB0(*(void **)(m + 0x64), (void *)func_L01_00448FF0(*(void **)(m + 0x64)), 0, 0, 0);
    if (t != 0) {
        if ((u32)(t - 4) < 2) {
            func_L01_003ACCD8(a, m);
            return 1;
        }
        if ((u32)(t - 2) < 2) {
            func_L01_00445170(a, 3);
        }
    }
    func_L01_00452860(*(void **)(m + 0x64), r, func_L01_00449020(a));
    if ((((*(unsigned long *)(*(u8 **)(m + 0x64) + 0x30)) & 0x104100000000UL) != 0x4100000000UL || *(s32 *)(*(u8 **)(m + 0x64) + 0x98) != 0) && *(f32 *)r > 0.0f) {
        if (r[0x2F] != 0) {
            func_L01_00456BD0(*(void **)(m + 0x64), 5);
        } else {
            func_L01_00456BD0(*(void **)(m + 0x64), 3);
        }
    }
    g = D_L01_001DFB40;
    if ((*(s16 *)(a + 0xB2) + 8) % 8 == g % 8) {
        if (r[0x2F] != 0) {
            func_L01_00456C98(a, *(s32 *)(m + 0xC30), *(f32 *)(m + 0xC34), 0, 0, 0, 0, 3, 0, *(f32 *)(m + 0xC34) * 0.8f, 2.0f, 0, 0);
        } else {
            func_L01_00456C98(a, *(s32 *)(m + 0xC30), *(f32 *)(m + 0xC34), 0, 0, 0, 1, 1, 0, *(f32 *)(m + 0xC34) * 0.8f, 2.0f, 0, 0);
        }
    }
    if (*(s16 *)(m + 0x44) == 1) {
        *(u128_t *)(m + 0x70) = *(u128_t *)(m + 0x30);
    }
    return 0;
}
/* localdecomp:end func_L01_003ACD38 */
