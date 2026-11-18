/* func_L16_00434290: near miss, 9 diff (file L16_00434290.c, which holds only this function; PAL port of the NTSC-U draft, with PAL's callees, 0.004f/0.002f
 * and the PAL constants). Needs `@ps2as` on the file's line in config/levels/text_parts.txt (retail builds the float constants with lui/ori/mtc1, no $gp loads).
 * With it, every word matches except one scheduling block: retail issues `lq $a1,0($v0)` after the constants for p+0xC/p+0x10, `addiu $a2,$zero,5` and
 * `addiu $s2,$sp,0x10`; this C issues the lq right after `addiu $t0,$zero,0x5a` (the vb address kept in a local `vp = vb` before the other statements moved
 * the `addiu $s2` from 11 diff to 9). Tried: struct p and struct arr, const table and const loads, load-both-then-store copies, a Pair struct copy, 250 random
 * orderings of the 12 set-up statements; sched2 shows the lq with 11 dependents (the later stack stores) in every wording. */
#include "common.h"

/* localdecomp:start func_L16_00434290 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_003C4C18(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00475C60(f32 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 D_L16_001D6C20[];

void func_L16_00434290(void) {
    f32 va[4];
    f32 vb[4];
    u8 p[0x20];
    u8 arr[0x20];
    u8 *q;
    f32 *vp;
    s32 i;

    vp = vb;
    *(s32 *)(p + 0x14) = 0x23802020;
    *(s32 *)(p + 0x18) = 0x00202020;
    *(s16 *)(p + 0) = 0x78;
    *(s16 *)(p + 2) = 0x5A;
    *(s32 *)(p + 0x1C) = 5;
    *(f32 *)(p + 4) = 0.6f;
    *(s32 *)(p + 8) = 0;
    *(f32 *)(p + 0xC) = 0.004f;
    *(f32 *)(p + 0x10) = 0.002f;
    *(u128_t *)(arr + 0) = *(u128_t *)(D_L16_001D6C20 + 0);
    *(u128_t *)(arr + 0x10) = *(u128_t *)(D_L16_001D6C20 + 0x10);
    q = arr;
    for (i = 1; i >= 0; i--) {
        *(u128_t *)va = *(u128_t *)q;
        q += 0x10;
        func_003C4C18(va, 0.15f);
        vb[0] = func_003824E0(-*(f32 *)(p + 0x10), *(f32 *)(p + 0x10));
        vb[1] = func_003824E0(-*(f32 *)(p + 0x10), *(f32 *)(p + 0x10));
        vb[2] = func_003824E0(*(f32 *)(p + 0xC), *(f32 *)(p + 0xC) + *(f32 *)(p + 0xC));
        func_L01_00475C60(va, vp, func_00382498(*(s16 *)(p + 2), *(s16 *)(p + 0)), 0, *(s32 *)(p + 0x14), *(s32 *)(p + 0x18), 1,
                          (f32)(s32)(*(f32 *)(p + 4) * 210000.0f), (f32)(s32)(*(f32 *)(p + 8) * 210000.0f), 0.0f);
    }
}
/* localdecomp:end func_L16_00434290 */
