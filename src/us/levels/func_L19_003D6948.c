#include "common.h"

/* NTSC-U counterpart of func_L19_003D8E30 (src/levels/19_thran_asteroid_belt/L19_003D7AE8.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L19_003D6948 */
typedef int u128_t_3D8E30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D8E30;
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L19_003D6948(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_3D8E30 b;
    V4_3D8E30 c;
    V4_3D8E30 w;
    f32 s;
    f32 t;
    s32 i;
    s32 r;

    s = 1.0f / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    *(u128_t_3D8E30 *)&b = 0;
    b.z = 0.28f;
    t = s * *(f32 *)(m + 0x2C);
    func_003886E8(&b, &b, s);
    for (i = 0; i < 2; i++) {
        *(u128_t_3D8E30 *)&w = 0;
        w.x = func_0037E250(-1.0f, 1.0f);
        w.y = func_0037E250(-1.0f, 1.0f);
        w.z = func_0037E250(0.0f, 2.0f);
        c = w;
        func_003886E8(&w, m + 0xE0, -1.0f);
        vec_add_ab(&c, &w, &c);
        func_00388830(&c, &c, func_0037E250(1.5f, 3.0f) * 0.0166666675f);
        r = func_0037E208(3, 6);
        func_L02_003E0520(m, &b, 0.0f, &c, r, (i & 1) ? 3 : 0, 0.0333333351f, t, 15.0f, 1.0f, 0);
    }
    v[1] = v[1] - 1;
    *v = func_0037E208(0x5A, 0xB4);
}
/* localdecomp:end func_L19_003D6948 */
