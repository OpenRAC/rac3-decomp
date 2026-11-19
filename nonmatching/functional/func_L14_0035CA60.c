/* functional: high. Near miss (18 diffs, FPU register choice only); needs -mvu0-use-vf0-vf2 for its vec_add_ab (compiles with it; file flags otherwise). Last-store order and lim load order differ from retail but do not alias. D_L14_001DD6CC is the same const the file declares for func_L14_0035CBA0. */
#include "vu0.h"
__asm__(".extern D_L14_001DD6BC, 4");
__asm__(".extern D_L14_001DD6B8, 4");
__asm__(".extern D_L14_001DD6C0, 4");
__asm__(".extern D_L14_001DD6C8, 4");
__asm__(".extern D_L14_001DD6C4, 4");
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
    f32 x;
    f32 y;
    f32 lim;
    func_003C41A0((f32 *)(a1 + 0x14), a1 + 0xC, *(f32 *)(a1 + 0x10), D_L14_001DD6BC, D_L14_001DD6BC, D_L14_001DD6B8);
    func_0038CE20((f32 *)(a0 + 0x10), a0 + 0xD0, *(f32 *)(a1 + 0x14));
    vec_add_ab(a0 + 0x10, a0 + 0x10, a1 + 0x30);
    t = fabs_asm(*(f32 *)(a1 + 0x14)) / D_L14_001DD6C0;
    x = *(f32 *)(a0 + 0x18) + t * D_L14_001DD6C8;
    y = t * D_L14_001DD6C4;
    lim = D_L14_001DD6CC;
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
