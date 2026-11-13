#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003D7AE8 */
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);

void func_L19_003D7AE8(u8 *self) {
    u8 *d = *(u8 **)(self + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    f32 f;

    if (d == 0)
        return;
    f = *(f32 *)(d + 0x10) - 0.021f;
    *(f32 *)(d + 0x10) = f;
    if (f <= -8.0f)
        *(f32 *)(d + 0x10) = f + 8.0f;
    func_L01_004C7D98(self + 0x10, &a);
    func_0038CE20(&a, &a, 1.9f);
    vec_add_ba(&a, self + 0x10, &a);
    b = *(vu0_v4 *)(self + 0x10);
    func_L01_0040A8C0(&b, &a, 0x1A, 1, 0.55f, 1.0f, *(f32 *)(d + 0x10), 0x53FF7F40, 0x53FF7F40, 0xFF7F40, 0xFF7F40);
    func_L01_004C7D98(self + 0x10, &a);
    func_0038CE20(&a, &a, 2.5f);
    vec_add_ba(&a, self + 0x10, &a);
    b = *(vu0_v4 *)(self + 0x10);
    func_L01_0040A8C0(&b, &a, 0x1A, 1, 0.65f, 1.0f, *(f32 *)(d + 0x10), 0x53FF7F40, 0x53FF7F40, 0xFF7F40, 0xFF7F40);
}
/* localdecomp:end func_L19_003D7AE8 */

/* localdecomp:start func_L19_003D7C88 */
typedef struct { u8 pad[0x28]; f32 x28; f32 x2C; } D_3D7C88;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; D_3D7C88 *x68; u8 pad6C[0x74]; vu0_v4 xE0; } M_3D7C88;
__asm__(".extern D_L19_001DECE0, 4");
__asm__(".extern D_L19_001DECE4, 4");
__asm__(".extern D_L19_001DECE8, 4");
__asm__(".extern D_L19_001DECEC, 4");
__asm__(".extern D_L19_001DECF0, 4");
__asm__(".extern D_L19_001DECF4, 4");
extern f32 D_L19_001DECE0;
extern f32 D_L19_001DECE4;
extern f32 D_L19_001DECE8;
extern s32 D_L19_001DECEC;
extern s32 D_L19_001DECF0;
extern f32 D_L19_001DECF4;
extern s32 D_L19_001E1B08;
extern f32 D_L19_001E1B0C;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D328(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_L19_003D7C88(M_3D7C88 *self) {
    vu0_v4 m[4];
    vu0_v4 pos;
    vu0_v4 u;
    vu0_v4 r;
    vu0_v4 t;
    D_3D7C88 *d;

    d = self->x68;
    if (d == 0)
        return;
    pos = self->pos;
    pos.z = pos.z - 0.25f;
    u = self->xE0;
    d->x28 = func_0038DAB8(d->x28, 0.017453292f);
    r.x = 0.0f;
    r.y = -func_0038D160(func_0038CED8(&u), u.z) + -1.5707964f;
    r.z = d->x28;
    r.w = 1.0f;
    func_0038D328(m, &r);
    t = self->xE0;
    func_0038CE20(&t, &t, D_L19_001DECE0);
    vec_add_ab(&pos, &pos, &t);
    m[3] = pos;
    func_0038CE20(&m[0], &m[0], D_L19_001DECE8);
    func_0038CE20(&m[1], &m[1], D_L19_001DECE4);
    func_0038CE20(&m[2], &m[2], D_L19_001DECE0);
    D_L19_001E1B0C = D_L19_001E1B0C + 0.05f;
    if (7.0f <= D_L19_001E1B0C)
        D_L19_001E1B0C = D_L19_001E1B0C - 7.0f;
    func_003D9740(m, D_L19_001DECEC, ((D_L19_001E1B08 * 3) << 24) | 0xFF8080, 5, 1, D_L19_001E1B0C);

    u = self->xE0;
    d->x2C = func_0038DAB8(d->x2C, -0.0130899697f);
    r.x = 0.0f;
    r.y = -func_0038D160(func_0038CED8(&u), u.z) + -1.5707964f;
    r.z = d->x2C;
    r.w = 1.0f;
    func_0038D328(m, &r);
    m[3] = pos;
    func_0038CE20(&m[0], &m[0], D_L19_001DECE8 * 1.25f);
    func_0038CE20(&m[1], &m[1], D_L19_001DECE4 * 1.25f);
    func_0038CE20(&m[2], &m[2], D_L19_001DECE0);
    D_L19_001DECF4 = D_L19_001DECF4 + 0.03f;
    if (7.0f <= D_L19_001DECF4)
        D_L19_001DECF4 = D_L19_001DECF4 - 7.0f;
    func_003D9740(m, D_L19_001DECF0, ((D_L19_001E1B08 * 3) << 24) | 0xFF8080, 4, 1, D_L19_001DECF4);
}
/* localdecomp:end func_L19_003D7C88 */

/* localdecomp:start func_L19_003D7F80 */
typedef int u128_t_3D7F80 __attribute__((mode(TI)));
extern u8 D_L19_001D66F0;
__asm__(".extern D_L19_001DECF8, 4");
__asm__(".extern D_L19_001DECFC, 4");
extern f32 D_L19_001DECF8;
extern f32 D_L19_001DECFC;
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

void func_L19_003D7F80(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x1F, &D_L19_001D66F0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = 1.0f / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        *(u128_t_3D7F80 *)&b = 0;
        func_0038CE20(&b, &b, t);
        *(u128_t_3D7F80 *)&a = 0;
        a.z = -0.14000002f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x14, 0, 0.18f, D_L19_001DECFC * t * *(f32 *)(a0 + 0x2C), 20.0f, 1.0f, 0);
        func_0038CE20(&b, &b, *(f32 *)(a0 + 0x2C));
        func_0038D000(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, D_L19_001DECF8 * t * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L19_003D7F80 */

/* localdecomp:start func_L19_003D81D0 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L19_004044B0(void *, void *, void *);

void func_L19_003D81D0(u8 *a0) {
    f32 v[4];
    f32 ang;

    ang = *(f32 *)(a0 + 0xFC) * 0.5f * 0.017453292f;
    func_0038CE20(v, a0 + 0xE0, func_0038D0B0(ang));
    v[3] = func_0038D098(ang);
    func_L19_004044B0(a0 + 0xC0, a0 + 0xF0, v);
    func_0038CE90(a0 + 0xD0, a0 + 0xE0, a0 + 0xC0);
    *(s32 *)(a0 + 0xCC) = 0;
    *(s32 *)(a0 + 0xDC) = 0;
}
/* localdecomp:end func_L19_003D81D0 */

INCLUDE_ASM("asm/levels", func_L19_003D8280);

/* localdecomp:start func_L19_003D8BC0 */
typedef int u128_t_3D8BC0 __attribute__((mode(TI)));
extern u8 D_L19_001D66F0;
__asm__(".extern D_L19_001DED1C, 4");
__asm__(".extern D_L19_001DED20, 4");
extern f32 D_L19_001DED1C;
extern f32 D_L19_001DED20;
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
extern u8 *func_L01_00452460(void *, s32, s32);

void func_L19_003D8BC0(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xF, &D_L19_001D66F0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00452460(a0, 0x1EEE, 0);
        t = 1.0f / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        *(u128_t_3D8BC0 *)&b = 0;
        b.z = 0.53f;
        func_0038CE20(&b, &b, t);
        *(u128_t_3D8BC0 *)&a = 0;
        a.z = 0.14000002f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x14, 0, 0.18f, D_L19_001DED20 * t * *(f32 *)(a0 + 0x2C), 20.0f, 1.0f, 0);
        func_0038CE20(&b, &b, *(f32 *)(a0 + 0x2C));
        func_0038D000(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, D_L19_001DED1C * t * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L19_003D8BC0 */

/* localdecomp:start func_L19_003D8E30 */
typedef int u128_t_3D8E30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D8E30;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L19_003D8E30(u8 *m) {
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
    func_0038CE20(&b, &b, s);
    for (i = 0; i < 2; i++) {
        *(u128_t_3D8E30 *)&w = 0;
        w.x = func_003824E0(-1.0f, 1.0f);
        w.y = func_003824E0(-1.0f, 1.0f);
        w.z = func_003824E0(0.0f, 2.0f);
        c = w;
        func_0038CE20(&w, m + 0xE0, -1.0f);
        vec_add_ab(&c, &w, &c);
        func_0038CF68(&c, &c, func_003824E0(1.5f, 3.0f) * 0.020000001f);
        r = func_00382498(3, 6);
        func_L02_003E2E38(m, &b, 0.0f, &c, r, (i & 1) ? 3 : 0, 0.040000003f, t, 15.0f, 1.0f, 0);
    }
    v[1] = v[1] - 1;
    *v = (func_00382498(0x5A, 0xB4) * 5 + 2) / 6;
}
/* localdecomp:end func_L19_003D8E30 */
