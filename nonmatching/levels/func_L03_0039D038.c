/* near miss (level 3, Starship Phoenix): 46 differences: the structure and the beginning match; retail has two nops before the div.s (levels have no divs_nops table) so everything after it is scheduled differently, with f7/f5 register choice and swc1 order; about 30 store-order permutations tried */
#include "common.h"

/* localdecomp:start func_L03_0039D038 */
extern f32 func_00431070(f32, f32);
extern void func_L03_0039D578(u8 *, u8 *);
extern void func_L03_0039D380(u8 *, u8 *);
extern void func_00446C10(u8 *, u8 *, u8 *);
extern u8 D_001426E8[];
extern u8 *D_001A71A0[];

void func_L03_0039D038(u8 *a0) {
    u8 *p;
    f32 r;
    if (a0[0x20] == 0) {
        p = *(u8 **)(a0 + 0x68);
        r = func_00431070(300.0f, 600.0f);
        *(f32 *)(p + 0x34) = 0.2f;
        *(f32 *)(p + 0x40) = 1.4835298f;
        *(f32 *)(p + 0x3C) = 1.0f;
        *(s32 *)(p + 0x340) = (s32)((r * 5.0f + 2.0f) / 6.0f);
        *(f32 *)(p + 0x60) = 0.34906584f;
        *(f32 *)(p + 0x5C) = 0.00392f;
        *(f32 *)(p + 0x64) = 0.01f;
        *(f32 *)(p + 0x4C) = 0.50265485f;
        *(f32 *)(p + 0x54) = 0.010053097f;
        *(f32 *)(p + 0x30) = 1.0f;
        *(f32 *)(p + 0x38) = 1.0f;
        *(f32 *)(p + 0x50) = 0.010053097f;
        if (D_001426E8[0] != 0) {
            func_L03_0039D578(a0, p);
        } else {
            a0[0x30] = 0xFF;
            func_00446C10(a0, D_001A71A0[0], p + 0x120);
            func_L03_0039D380(a0, p);
        }
    }
}
/* localdecomp:end func_L03_0039D038 */
