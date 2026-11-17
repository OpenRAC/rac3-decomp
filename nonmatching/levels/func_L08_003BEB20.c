/* func_L08_003BEB20: 76 diff with the file's flags; NEEDS-DIVS func_L08_003BEB20 2 (retail has nop nop before the div.s, which shifts the rest of the listing). Other diffs: in the func_L01_00451FE0 arg setup mine emits sw 3,8(sp) before mov.s $f16/$f17 (retail after), and the divisor pointer load uses $v0 (retail $v1). Tried array vs &scalar for D_L08_001D66B0 (86 -> 76). */
#include "vu0.h"
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_00452460(void *, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(u8 *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L08_003BE9C0(void *, void *, f32);
extern s32 D_L08_001D66B0;
__asm__(".extern D_L08_001D66B0, 16");

void func_L08_003BEB20(u8 *a0) {
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    f32 r;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L01_00451FE0(a0, 0x3F, &D_L08_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 1.0f, 3.0f, 1.0f, 3.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003A52A0(0, 0, a0);
        r = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        func_L01_00451E78(a0, 1, 0.0f);
        v1 = (vu0_v4){0};
        v2 = (vu0_v4){0};
        v1.x = -0.46000000834465027f;
        v2.x = 8.0600004196167f;
        func_0038D000(&v1, &v1, a0 + 0xC0);
        func_0038D000(&v2, &v2, a0 + 0xC0);
        func_0038CE20(&v3, &v1, r);
        vec_add_ab(&v1, &v3, a0 + 0x10);
        func_0038CE20(&v3, &v2, r);
        vec_add_ab(&v2, &v3, a0 + 0x10);
        func_0038CE20(&v3, a0 + 0xE0, -1.0f);
        func_L08_003BE9C0(&v1, &v3, r);
        func_L08_003BE9C0(&v2, &v3, r);
        func_L01_00452460(a0, 0x1CF3, 0);
        func_003C2880(a0);
    }
}
