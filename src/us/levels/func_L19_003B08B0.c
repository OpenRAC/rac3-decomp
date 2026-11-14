#include "common.h"

/* NTSC-U counterpart of func_L19_003B2538 (src/levels/19_thran_asteroid_belt/L19_003B1A80.c) */
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L19_003B08B0 */
extern f32 func_L01_00436500(void *);
extern void func_L01_00440A88(f32 *, f32, f32);
extern s32 func_L19_003B0BF0(u8 *obj);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L19_003D04E8(void *, void *, void *, f32, s32);

s32 func_L19_003B08B0(u8 *obj) {
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 e;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c[4];
    u8 *v;
    u8 *p;
    s32 t;
    s32 n;

    v = *(u8 **)(obj + 0x68);
    t = (s32)func_L01_00436500(obj);
    if (*(s16 *)(v + 0x382) == 4) {
        if (t < 4 || t >= 12)
            return 1;
        *(s16 *)(v + 0x382) = 12;
        n = 3;
    } else {
        if (t < 12)
            return 1;
        *(s16 *)(v + 0x382) = 4;
        n = 2;
    }
    a = *(vu0_v4 *)(v + 0x220);
    p = *(u8 **)(v + 0x230);
    if (p != 0 && a.z + 5.0f < *(f32 *)(obj + 0x18))
        a = *(vu0_v4 *)(p + 0x10);
    if (func_0037E1D8(4) == 0) {
        func_L01_00440A88(&b.x, 0.8f, 1.2f);
        if (func_0037E1D8(2))
            b.x = -b.x;
        if (func_0037E1D8(2))
            b.y = -b.y;
        vec_add_ab(&a, &a, &b);
    }
    if (func_L19_003B0BF0(obj) == 0)
        return 0;
    func_003BD9A0(obj, n, c);
    func_003886E8(&e, &c[0], 0.1f);
    vec_add_ba(&f, &c[3], &e);
    vec_sub_ba(&g, &a, &f);
    func_00388830(&b, &g, 0.3f);
    vec_add_ab(&f, &b, &f);
    func_00388830(&g, &g, 0.25f);
    p = func_L19_003D04E8(obj, &f, &g, *(u8 *)(v + 0x44), 0);
    if (p != 0)
        *(u8 **)(p + 0xB8) = obj;
    return 1;
}
/* localdecomp:end func_L19_003B08B0 */
