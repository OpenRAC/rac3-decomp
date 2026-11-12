/* near miss (level 5): 27 differences (check.py with -mvu0-use-vf0-vf2 and the divs_nops row "func_L05_00362148 2"); every instruction is right but the scheduling: retail stores the three byte fields before the halfword (sh 0x32) and loads the $gp float after the lq/sq copies, ours hoists the sh and the $gp load into the div.s shadow and puts the 1.0f constant in $f0 (retail $f1); typed-struct fields and about 12 statement orders gave nothing better */
#include "common.h"

/* localdecomp:start func_L05_00362148 */
#include "vu0.h"
__asm__(".extern D_L05_001DD9C0, 4");
__asm__(".extern D_L05_001DD9D4, 4");
extern f32 D_L05_001DD9C0;
extern f32 D_L05_001DD9D4;
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

u8 *func_L05_00362148(u8 *a0, vu0_v4 *a1, vu0_v4 *a2, s32 a3, s32 t0, u8 t1, f32 f) {
    u8 *m;
    u8 *s;
    vu0_v4 tmp;
    m = func_003C24B0(0x169C, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        m[0x30] = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        *(s16 *)(m + 0x32) = 0xFF;
        *(s32 *)(s + 4) = a3;
        *(s32 *)(s + 0) = (s32)a0;
        *(vu0_v4 *)(m + 0x10) = *a1;
        *(vu0_v4 *)(m + 0xF0) = *(vu0_v4 *)(a0 + 0xF0);
        *(f32 *)(m + 0x2C) = D_L05_001DD9C0;
        *(f32 *)(s + 0xC) = 1.0f / (f32)t0;
        *(s32 *)(s + 0x54) = t1;
        *(f32 *)(s + 0x58) = f;
        *(s16 *)(s + 8) = t0;
        *(s32 *)(s + 0x50) = 0;
        *(vu0_v4 *)(s + 0x20) = *a1;
        *(vu0_v4 *)(s + 0x10) = *a2;
        vec_sub_ba(&tmp, s + 0x10, s + 0x20);
        tmp.z = 0;
        func_0038CE20(&tmp, &tmp, D_L05_001DD9D4);
        vec_add_ba(s + 0x40, s + 0x20, &tmp);
        func_0038CF68(&tmp, &tmp, -1.0f);
        tmp.z = *(f32 *)(s + 0x18) - *(f32 *)(s + 0x28);
        vec_add_ab(s + 0x30, s + 0x10, &tmp);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L05_00362148 */
