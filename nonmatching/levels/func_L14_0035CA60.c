/* func_L14_0035CA60: near miss, 55 diff: needs the VU0 + @ps2as set on L14_0035C810.c (with .extern hints added to func_L14_0035CBA0's gp variables) and the divs_nops row "func_L14_0035CA60 2"; the logic is complete; left: float load scheduling, retail loads D_001DD6CC (const) after the multiplies, ours hoists it ahead of the second vec_add; the second block is a copy of the first
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
__asm__(".extern D_L14_001DD6BC, 4");
__asm__(".extern D_L14_001DD6B8, 4");
__asm__(".extern D_L14_001DD6C0, 4");
__asm__(".extern D_L14_001DD6C8, 4");
__asm__(".extern D_L14_001DD6C4, 4");
__asm__(".extern D_L14_001DD6CC, 4");
extern f32 D_L14_001DD6BC;
extern f32 D_L14_001DD6B8;
extern f32 D_L14_001DD6C0;
extern f32 D_L14_001DD6C8;
extern f32 D_L14_001DD6C4;
extern const f32 D_L14_001DD6CC;
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
s32 func_L14_0035CA60(u8 *a0, u8 *a1) {
    f32 t;
    func_003C41A0((f32 *)(a1 + 0x14), a1 + 0xC, *(f32 *)(a1 + 0x10), D_L14_001DD6BC, D_L14_001DD6BC, D_L14_001DD6B8);
    func_0038CE20((f32 *)(a0 + 0x10), a0 + 0xD0, *(f32 *)(a1 + 0x14));
    vec_add_ab(a0 + 0x10, a0 + 0x10, a1 + 0x30);
    t = fabs_asm(*(f32 *)(a1 + 0x14)) / D_L14_001DD6C0;
    *(f32 *)(a0 + 0x18) += t * D_L14_001DD6C8;
    *(f32 *)(a0 + 0xF0) = t * D_L14_001DD6C4;
    if (fabs_asm(*(f32 *)(a1 + 0x10) - *(f32 *)(a1 + 0x14)) < D_L14_001DD6CC) {
        *(f32 *)(a1 + 0x14) = *(f32 *)(a1 + 0x10);
        func_0038CE20((f32 *)(a0 + 0x10), a0 + 0xD0, *(f32 *)(a1 + 0x14));
        vec_add_ab(a0 + 0x10, a0 + 0x10, a1 + 0x30);
        t = fabs_asm(*(f32 *)(a1 + 0x14)) / D_L14_001DD6C0;
        *(f32 *)(a0 + 0x18) += t * D_L14_001DD6C8;
        *(f32 *)(a0 + 0xF0) = t * D_L14_001DD6C4;
        return 1;
    }
    return 0;
}
