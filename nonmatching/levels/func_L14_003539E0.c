/* func_L14_003539E0: near miss, 71 diff: needs the divs_nops row "func_L14_003539E0 2" (file already VU0 + @ps2as); D_L14_001D66B0_v is a second name for the address at vector type (resolve_symbols row needed); logic complete; left: FP register allocation (retail keeps t in $f20, 1.0f in $f21, 1.1f in $f22; ours gives 1.0f $f20, t $f22) and the absolute lqc2 of D_001D66B0 through $at
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
extern u8 D_L14_001D66B0;
extern vu0_v4 D_L14_001D66B0_v;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L14_00353910(void *, void *, void *, s32);
void func_L14_003539E0(u8 *a0) {
    vu0_v4 a;
    vu0_v4 c;
    vu0_v4 b;
    f32 t;
    s32 n;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        t = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        n = (s32)(t * 15.0f);
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 7, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        b = *(vu0_v4 *)(a0 + 0xD0);
        vec_sub_ab(&b, &D_L14_001D66B0_v, &b);
        func_0038CDF8((f32 *)&c, (f32 *)(a0 + 0xC0), (f32 *)&b, 0.5f);
        func_0038CF68(&c, &c, 1.0f);
        vec_add_ba(&a, a0 + 0x10, &c);
        func_L14_00353910(a0, &a, &c, n);
        a.z += t * 1.1f;
        func_L14_00353910(a0, &a, &c, n);
        t = (t + t) * 1.1f;
        a.z -= t;
        func_L14_00353910(a0, &a, &c, n);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
