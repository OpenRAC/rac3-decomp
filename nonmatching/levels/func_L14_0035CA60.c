/* func_L14_0035CA60: near miss, 18 diff: needs -mvu0-use-vf0-vf2 on L14_0035C810.c (its eight C functions still match with it) and the divs_nops row "func_L14_0035CA60 2 2"; both products are taken before either store, and the compare limit is read before the stores through D_L14_001DD6CC_n, a non-const name for the word func_L14_0035CBA0 declares const (the const one is hoisted to the top and takes $f4 from t); left: $f0/$f2/$f3 for D_L14_001DD6C0, the +0x18 load and D_L14_001DD6C4 (retail f3/f2/f0, this C f2/f0/f3); 24 statement and operand orders tried
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
__asm__(".extern D_L14_001DD6BC, 4");
__asm__(".extern D_L14_001DD6B8, 4");
__asm__(".extern D_L14_001DD6C0, 4");
__asm__(".extern D_L14_001DD6C8, 4");
__asm__(".extern D_L14_001DD6C4, 4");
__asm__(".extern D_L14_001DD6CC_n, 4");
extern f32 D_L14_001DD6BC;
extern f32 D_L14_001DD6B8;
extern f32 D_L14_001DD6C0;
extern f32 D_L14_001DD6C8;
extern f32 D_L14_001DD6C4;
extern f32 D_L14_001DD6CC_n;
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
s32 func_L14_0035CA60(u8 *a0, u8 *a1) {
    f32 t;
    f32 x;
    f32 y;
    f32 lim;
    func_003C41A0((f32 *)(a1 + 0x14), a1 + 0xC, *(f32 *)(a1 + 0x10), D_L14_001DD6BC, D_L14_001DD6BC, D_L14_001DD6B8);
    func_0038CE20((f32 *)(a0 + 0x10), a0 + 0xD0, *(f32 *)(a1 + 0x14));
    vec_add_ab(a0 + 0x10, a0 + 0x10, a1 + 0x30);
    t = fabs_asm(*(f32 *)(a1 + 0x14)) / D_L14_001DD6C0;
    x = *(f32 *)(a0 + 0x18) + t * D_L14_001DD6C8;
    y = t * D_L14_001DD6C4;
    lim = D_L14_001DD6CC_n;
    *(f32 *)(a0 + 0xF0) = y;
    *(f32 *)(a0 + 0x18) = x;
    if (fabs_asm(*(f32 *)(a1 + 0x10) - *(f32 *)(a1 + 0x14)) < lim) {
        *(f32 *)(a1 + 0x14) = *(f32 *)(a1 + 0x10);
        func_0038CE20((f32 *)(a0 + 0x10), a0 + 0xD0, *(f32 *)(a1 + 0x14));
        vec_add_ab(a0 + 0x10, a0 + 0x10, a1 + 0x30);
        t = fabs_asm(*(f32 *)(a1 + 0x14)) / D_L14_001DD6C0;
        x = *(f32 *)(a0 + 0x18) + t * D_L14_001DD6C8;
        y = t * D_L14_001DD6C4;
        *(f32 *)(a0 + 0xF0) = y;
        *(f32 *)(a0 + 0x18) = x;
        return 1;
    }
    return 0;
}
