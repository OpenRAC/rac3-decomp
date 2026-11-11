/* func_L19_003B2290: VU0 part matches with -mvu0-use-vf0-vf2 added to L19_003B1A80.c's flags (vec_sub_ba/vec_add_ab from vu0.h, #include "vu0.h" in the prelude); tail differs. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V_3B2290 __attribute__((aligned(16)));
extern u8 *D_001E8E58[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);

s32 func_L19_003B2290(u8 *obj, f32 dz) {
    V_3B2290 a;
    V_3B2290 b;
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *t;
    s32 r;

    a = *(V_3B2290 *)(obj + 0x10);
    a.z = a.z + dz;
    vec_sub_ba(&b, p + 0x220, &a);
    b.z = 0.0f;
    func_0038CF68(&b, &b, 3.0f);
    vec_add_ab(&b, &b, &a);
    if (func_003D3CB0(&a, &b, 0x10, obj, 0) != 0) {
        t = D_001E8E58[0];
        r = 0;
        if (t != 0) {
            if (*(s16 *)(t + 0xAA) == 0x1AB8)
                r = 1;
            else if (t == *(u8 **)(p + 0x230))
                r = 1;
        }
    } else {
        r = 1;
    }
    return r;
}
