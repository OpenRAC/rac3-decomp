/* NTSC-U draft (Claude wave C2): C of func_L16_00431280, the NTSC-U twin of func_L16_00434290, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 11 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L16_00431280", whose code is not the PAL one).
 * Worker's note: flags: working flags '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (PAL file: '-O2 -G8 -fopt-stack -mno-check-zero-division'). needs @ps2as (float constants lui/ori/mtc1, no hazard nop after mtc1; PAL flags lack it). With @ps2as 11 diff: only the ...
 */
#include "common.h"

/* localdecomp:start func_L16_00431280 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_003BF6A8(f32 *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00472438(f32 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 D_L16_001D6C20[];

void func_L16_00431280(void) {
    f32 va[4];
    f32 vb[4];
    u8 p[0x20];
    u8 arr[0x20];
    u8 *q;
    s32 i;

    *(s32 *)(p + 0x14) = 0x23802020;
    *(s32 *)(p + 0x18) = 0x00202020;
    *(s16 *)(p + 0) = 0x78;
    *(s16 *)(p + 2) = 0x5A;
    *(s32 *)(p + 0x1C) = 5;
    *(f32 *)(p + 4) = 0.6f;
    *(s32 *)(p + 8) = 0;
    *(f32 *)(p + 0xC) = 0.0033333336f;
    *(f32 *)(p + 0x10) = 0.0016666668f;
    *(u128_t *)(arr + 0) = *(u128_t *)(D_L16_001D6C20 + 0);
    *(u128_t *)(arr + 0x10) = *(u128_t *)(D_L16_001D6C20 + 0x10);
    q = arr;
    for (i = 1; i >= 0; i--) {
        *(u128_t *)va = *(u128_t *)q;
        q += 0x10;
        func_003BF6A8(va, 0.15f);
        vb[0] = func_0037E250(-*(f32 *)(p + 0x10), *(f32 *)(p + 0x10));
        vb[1] = func_0037E250(-*(f32 *)(p + 0x10), *(f32 *)(p + 0x10));
        vb[2] = func_0037E250(*(f32 *)(p + 0xC), *(f32 *)(p + 0xC) + *(f32 *)(p + 0xC));
        func_L01_00472438(va, vb, func_0037E208(*(s16 *)(p + 2), *(s16 *)(p + 0)), 0, *(s32 *)(p + 0x14), *(s32 *)(p + 0x18), 1,
                          (f32)(s32)(*(f32 *)(p + 4) * 210000.0f), (f32)(s32)(*(f32 *)(p + 8) * 210000.0f), 0.0f);
    }
}
/* localdecomp:end func_L16_00431280 */
