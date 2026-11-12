/* func_L19_003C27A8: 56 rows shifted from two causes; needs -mvu0-use-vf0-vf2 on L19_003C0938.c (all its C functions still MATCH with it). */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V_3C27A8 __attribute__((aligned(16)));
extern u8 D_001A71C4;
extern u8 *D_001A73E8[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern f32 func_L01_004395E0(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L01_00446780(u8 *, void *, f32, s32, s32, s32, s32, f32, f32);

void func_L19_003C27A8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3C27A8 a;
    V_3C27A8 b;
    V_3C27A8 c;
    f32 f;
    f32 f13;
    s32 r = 0;

    if (*(s32 *)(p + 0x41C) == 2) {
        func_003C2F58(obj, 1, (u8 *)&a);
        func_003C2F58(obj, 2, (u8 *)&b);
        f = func_L01_004395E0(obj);
        r = 20.0f <= f;
    } else if (*(s32 *)(p + 0x41C) == 1) {
        func_003C2F58(obj, 3, (u8 *)&a);
        func_003C2F58(obj, 4, (u8 *)&b);
        f = func_L01_004395E0(obj);
        r = 9.0f <= f;
    }
    if (*(s32 *)(p + 0x45C) == 0 && D_001A73E8[0] == obj)
        *(s32 *)(p + 0x45C) = 1;
    if (r != 0) {
        vec_sub_ba(&c, &b, &a);
        func_0038CE20(&c, &c, 0.5f);
        f = func_0038CEA8(&c);
        vec_add_ab(&c, &c, &a);
        f13 = (f32)p[0x44];
        if (D_001A71C4 == 1)
            f13 = 1.0f;
        func_L01_00446780(obj, &c, f, 1, 0, 1, 0, f13, 1.0f);
    }
}
