#include "common.h"

/* localdecomp:start func_L13_003C62A8 */
typedef struct { f32 x; f32 y; f32 z; f32 w; } __attribute__((aligned(16))) Q_003C62A8;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);

u8 *func_L13_003C62A8(u8 *parent, Q_003C62A8 *pos, Q_003C62A8 *rot) {
    Q_003C62A8 p;
    Q_003C62A8 r;
    u8 *m;
    u8 *v;
    Q_003C62A8 *rp = &r;

    p = *pos;
    r = *rot;
    m = func_003C24B0(0x1EA5, 0x70);
    if (m != 0) {
        func_L01_00456160(m, parent);
        *(Q_003C62A8 *)(m + 0x10) = p;
        func_L01_0044A7D0(m);
        v = *(u8 **)(m + 0x68);
        *(Q_003C62A8 *)(v + 0x0) = r;
        *(Q_003C62A8 *)(v + 0x10) = r;
        *(f32 *)(v + 8) = func_0038DAB8(*(f32 *)(v + 8), func_L01_00443A18(2.0f, 25.0f) * 0.017453292f);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(rp), rp->z);
        *(f32 *)(m + 0xF8) = func_0038D160(r.x, rp->y);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.75f;
    }
    return m;
}
/* localdecomp:end func_L13_003C62A8 */

/* localdecomp:start func_L13_003C63A8 */
#include "vu0.h"
typedef int u128_t_3C63A8 __attribute__((mode(TI)));
extern u8 D_L13_001D66B0;
__asm__(".extern D_L13_001DEBA8, 4");
__asm__(".extern D_L13_001DEBAC, 4");
__asm__(".extern D_L13_001DEBB0, 4");
extern f32 D_L13_001DEBA8;
extern f32 D_L13_001DEBAC;
extern f32 D_L13_001DEBB0;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L13_003C63A8(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x3F, &D_L13_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = 1.0f / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        *(u128_t_3C63A8 *)&a = 0;
        a.z = D_L13_001DEBA8;
        b = a;
        func_0038CE20(&b, &b, t);
        *(u128_t_3C63A8 *)&a = 0;
        a.z = -0.14000002f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x14, 0, 0.18f, D_L13_001DEBB0 * t * *(f32 *)(a0 + 0x2C), 20.0f, 1.0f, 0);
        func_0038CE20(&b, &b, *(f32 *)(a0 + 0x2C));
        func_0038D000(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, D_L13_001DEBAC * t * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L13_003C63A8 */
