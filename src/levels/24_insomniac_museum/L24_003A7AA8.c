#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L24_003A7AA8 */
typedef struct {
    u8 pad0[0x28];
    f32 f28;
    u8 pad2C[4];
} S_3A7AA8;
extern S_3A7AA8 D_L24_002B9460[];
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);

void func_L24_003A7AA8(u8 *a0, u8 *a1) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v1[4] __attribute__((aligned(16)));
    f32 v2[4] __attribute__((aligned(16)));
    f32 v3[4] __attribute__((aligned(16)));
    f32 v4[4] __attribute__((aligned(16)));
    f32 f22 = 8.0f;
    f32 f21;
    f32 f20;
    if (*(s32 *)(a1 + 0x980) > 0) {
        f22 = D_L24_002B9460[*(s32 *)(a1 + 0x980) - 1].f28 * f22;
    }
    *(vu0_q *)v3 = *(vu0_q *)(a0 + 0x10);
    func_0038CE20(v4, a0 + 0xD0, -0.5f);
    vec_add_ba(v3, v3, v4);
    f21 = 0.419999987f;
    v3[2] = v3[2] + *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 2.20000005f;
    func_0038CE20(v1, a0 + 0xC0, 2.0f);
    f20 = 1.0f;
    func_0038CE20(v2, a0 + 0xC0, 4.69999981f);
    vec_add_ba(v1, v1, v3);
    vec_add_ab(v2, v2, v3);
    func_L01_00446780(a0, v1, 0x10000, 0, 1, 0, f21, f22, f20);
    func_003C4098(v0, v1, v2, 0.25f);
    func_L01_00446780(a0, v0, 0x10000, 0, 1, 0, f21, f22, f20);
    func_003C4098(v0, v1, v2, 0.550000012f);
    func_L01_00446780(a0, v0, 0x10000, 0, 1, 0, f21, f22, f20);
    func_003C4098(v0, v1, v2, 0.850000024f);
    func_L01_00446780(a0, v0, 0x10000, 0, 1, 0, f21, f22, f20);
}
/* localdecomp:end func_L24_003A7AA8 */

INCLUDE_ASM("asm/levels", func_L24_003A7CE8);

/* localdecomp:start func_L24_003A7F58 */
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L24_003A7F58(void *a0) {
    f32 a[4] __attribute__((aligned(16)));
    f32 d[16] __attribute__((aligned(16)));
    func_003C2EC0(a0, 0, d);
    *(vu0_q *)a = *(vu0_q *)d;
    func_0038CF68(a, a, 0.1f);
    vec_add_ab(a, a, &d[12]);
    func_003D9508(a, 0xB, 0x20000080, 1, 0.5f, 0.08f, 0.0f);
}
/* localdecomp:end func_L24_003A7F58 */

/* localdecomp:start func_L24_003A7FD8 */

extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);

void func_L24_003A7FD8(void *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[16] __attribute__((aligned(16)));
    f32 f[4] __attribute__((aligned(16)));
    f32 zero = 0.0f;
    func_003C2EC0(a0, 0, d);
    *(vu0_q *)a = *(vu0_q *)d;
    func_0038CF68(a, a, 0.1f);
    vec_add_ab(a, a, &d[12]);
    func_L03_00433C70(a0, a, a1 + 0x970, 0x10000, 0, 1, 0, (f32)(*(s32 *)(a1 + 0x95C) + 4), zero);
    *(vu0_q *)f = *(vu0_q *)(a1 + 0x970);
    func_003C4098(b, a, f, func_003824E0(zero, 1.0f));
    *(vu0_q *)c = *(vu0_q *)d;
    func_0038CF68(c, c, 0.02f);
    func_L01_00466588(b, c, 0x40000FFF, 0x10000FF, func_00382498(5, 8), 1, 25000.0f);
}
/* localdecomp:end func_L24_003A7FD8 */

/* localdecomp:start func_L24_003A8118 */
extern vu0_q D_L24_001E8F60;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0040A8C0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void *func_L01_00470668(void *, void *, s32, f32);

void func_L24_003A8118(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    u8 *q;
    f32 x;
    s32 i;

    func_003C2EC0(a0, 0, m);
    *(vu0_q *)v = *(vu0_q *)m;
    func_0038CF68(v, v, 0.1f);
    q = p + 0x970;
    vec_add_ab(v, v, &m[12]);
    func_0038CF68(q, m, 10.0f);
    vec_add_ab(q, v, q);
    if (func_003D3CB0(v, q, 2, a0, 0) != 0) {
        *(vu0_q *)q = D_L24_001E8F60;
    }
    *(vu0_q *)w = *(vu0_q *)q;
    func_L01_0040A8C0(v, w, 0xE, 0, 0x8010104F, 0x8010104F, 0x8010104F, 0x8010104F, (f32)*(s32 *)(p + 0x95C) * 0.1f, 1.0f, 0.0f);
    x = (f32)*(s32 *)(p + 0x95C) * 0.1f + (func_003824E0(0.0f, 0.1f) + 0.5f);
    func_003D9508(v, 0x31, 0x8010104F, 0, x, 0.08f, func_00382538());
    x = (f32)*(s32 *)(p + 0x95C) * 0.1f + (func_003824E0(0.0f, 0.2f) + 0.5f);
    func_003D9508(q, 0x31, 0x8010104F, 0, x, 0.08f, func_00382538());
    x = (f32)*(s32 *)(p + 0x95C) * 0.1f;
    for (i = 0; i < *(s32 *)(p + 0x95C) + 1; i++) {
        qzero(r);
        r[0] = func_003824E0(-3.0f - x, x + 3.0f) * 0.0200000014f;
        r[1] = func_003824E0(-3.0f - x, x + 3.0f) * 0.0200000014f;
        r[2] = (func_003824E0(0.0f, 1.0f) + 2.0f) * 0.0200000014f;
        func_L01_00470668(p + 0x970, r, ((*(s32 *)(p + 0x95C) * 2 + 15) * 5 + 2) / 6, 6.98131726e-06f);
    }
}
/* localdecomp:end func_L24_003A8118 */

/* localdecomp:start func_L24_003A8400 */
extern f32 func_0038D0B0(f32);
extern void func_0038D2D0(void *, f32);
extern f32 func_0038D098(f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_L24_003A8400(u8 *a0, s32 a1, s32 a2, s32 a3, f32 f12) {
    f32 m[16] __attribute__((aligned(16)));
    f32 c = func_0038D0B0((f32)(a1 - 0xB4) * 0.017453292f) * 0.1f;
    f32 s;
    f12 = f12 * (3.0f - c);
    func_0038D2D0(m, c + 2.0f);
    m[10] = f12;
    *(vu0_q *)&m[12] = *(vu0_q *)(a0 + 0x10);
    s = func_0038D098((f32)(a1 % 0x168) * 0.017453292f);
    func_003D9740(m, a3, ((s32)(s * 16.0f + 32.0f) << 24) | a2, 5, 1, (f32)a1 / 360.0f);
}
/* localdecomp:end func_L24_003A8400 */

/* localdecomp:start func_L24_003A8530 */
extern void func_L24_003A8400(u8 *, s32, s32, s32, f32);

void func_L24_003A8530(u8 *a0, f32 f12) {
    s32 t;
    func_L24_003A8400(a0, *(u16 *)(a0 + 0x96), 0x401080, 0x22, f12);
    t = *(u16 *)(a0 + 0x96);
    t += 0x28;
    func_L24_003A8400(a0, t >= 0x168 ? t - 0x168 : t, 0x802040, 0x27, f12);
    t = *(u16 *)(a0 + 0x96);
    t += 0xA0;
    func_L24_003A8400(a0, t >= 0x168 ? t - 0x168 : t, 0x40FF, 0x28, f12);
}
/* localdecomp:end func_L24_003A8530 */
