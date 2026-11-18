#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_003C5FE8 */
typedef int u128_t_3C5FE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C5FE8;
__asm__(".extern D_L10_001DE898, 4");
__asm__(".extern D_L10_001DE89C, 4");
extern f32 D_L10_001DE898;
extern f32 D_L10_001DE89C;
extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C5FE8(u8 *m) {
    V4_3C5FE8 p;
    V4_3C5FE8 a;
    u128_t_3C5FE8 z;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0xF, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00452460(m, 0x1EAB, 0);
        z = 0;
        *(u128_t_3C5FE8 *)&a = z;
        a.z = D_L10_001DE898;
        p = a;
        func_0038CE20(&p, &p, 21.810249f);
        *(u128_t_3C5FE8 *)&a = z;
        a.z = -0.14000002f;
        func_L02_003E2E38(m, &p, 0.1f, &a, 0x14, 0, 0.18000001f, *(f32 *)(m + 0x2C) * 32.715374f, 20.0f, 1.0f, 0);
        func_0038CE20(&p, &p, *(f32 *)(m + 0x2C));
        func_0038D000(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_L01_003303B8(&p, 0, 0, 0, 0, 2, 5, 0, D_L10_001DE89C * 21.810249f * *(f32 *)(m + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFF, 0x9090FF, 0, 0, 0, 0, 0x5186FF, 0x2A5CFF, 0, 0);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C5FE8 */

/* localdecomp:start func_L10_003C6250 */
typedef int u128_t_3C6250 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C6250;
__asm__(".extern D_L10_001DE8A0, 4");
extern f32 D_L10_001DE8A0;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L10_003C6250(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_3C6250 b;
    V4_3C6250 q;
    V4_3C6250 c;
    V4_3C6250 w;
    f32 s;
    s32 i;
    s32 r;

    *(u128_t_3C6250 *)&q = 0;
    q.z = D_L10_001DE8A0;
    b = q;
    s = 21.848372f;
    func_0038CE20(&b, &b, s);
    for (i = 0; i < 2; i++) {
        func_0038CE20(&c, m + 0xC0, func_003824E0(-1.0f, 1.0f) * s);
        vec_add_ab(&q, &c, &b);
        *(u128_t_3C6250 *)&w = 0;
        w.x = func_003824E0(-1.0f, 1.0f);
        w.y = func_003824E0(-1.0f, 1.0f);
        w.z = func_003824E0(0.0f, 2.0f);
        c = w;
        func_0038CE20(&w, m + 0xE0, 1.0f);
        vec_add_ab(&c, &w, &c);
        func_0038CF68(&c, &c, func_003824E0(1.5f, 3.0f) * 0.020000001f);
        r = func_00382498(3, 6);
        func_L02_003E2E38(m, &q, 0.0f, &c, r, i & 1, 0.040000003f, s * 1.5f * *(f32 *)(m + 0x2C), 15.0f, 1.0f, 0);
    }
    *v = (func_00382498(0x5A, 0xB4) * 5 + 2) / 6;
}
/* localdecomp:end func_L10_003C6250 */
