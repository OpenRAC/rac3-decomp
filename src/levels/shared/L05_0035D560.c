#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

/* localdecomp:start func_L05_0035D560 */
extern void func_L05_0035E050(s32);
extern void func_L05_0035DF68(s32);

void func_L05_0035D560(s32 a0) {
    u8 buf[448];
    func_L05_0035E050(a0);
    func_L05_0035DF68(a0);
}
/* localdecomp:end func_L05_0035D560 */

INCLUDE_ASM("asm/levels", func_L05_0035D590);

INCLUDE_ASM("asm/levels", func_L05_0035DA38);

/* localdecomp:start func_L05_0035DF68 */
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_00447470_0035DF68(s32, s32, f32);
extern void func_003C5458(void *, s32, f32, f32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD7E0, 8");
extern u8 D_L05_001DD7E0[8];
__asm__(".extern D_L05_001DD7F0, 4");
extern f32 D_L05_001DD7F0;
__asm__(".extern D_L05_001DD7D0, 4");
extern s32 D_L05_001DD7D0;
__asm__(".extern D_L05_001DD7D8, 4");
extern f32 D_L05_001DD7D8;
__asm__(".extern D_L05_001DD7D4, 4");
extern f32 D_L05_001DD7D4;

void func_L05_0035DF68(s32 a0)
{
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;
    vu0_v4 n;
    f32 dot;

    func_003C2EC0((void *)a0, 0, m);
    func_0038D028(&p, D_L05_001DD7E0, m);
    vec_add_ba(&p, &p, m + 0x30);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CF68(&n, m + 0x10, -1.0f);
    dot = func_0038CE68(&d, &n);
    if (D_L05_001DD7F0 < dot) {
        func_003C5458(&p, func_L01_00447470_0035DF68(D_L05_001DD7D0 & 0xFFFFFF, D_L05_001DD7D0, dot * dot), D_L05_001DD7D8, D_L05_001DD7D4);
    }
}
/* localdecomp:end func_L05_0035DF68 */

/* localdecomp:start func_L05_0035E050 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);
__asm__(".extern D_L05_001DD838, 8");
extern s32 D_L05_001DD838[2];
__asm__(".extern D_L05_001DD810, 8");
extern u8 D_L05_001DD810[8];
__asm__(".extern D_L05_001DD830, 8");
extern s32 D_L05_001DD830[2];
__asm__(".extern D_L05_001DD800, 8");
extern f32 D_L05_001DD800[2];
__asm__(".extern D_L05_001DD7F8, 8");
extern f32 D_L05_001DD7F8[2];

void func_L05_0035E050(s32 a0)
{
    s32 i;
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;

    for (i = 0; i < 2; i++) {
        func_003C2F58((u8 *)a0, D_L05_001DD838[i], (u8 *)&p);
        func_003C2EC0((void *)a0, D_L05_001DD838[i], m);
        func_0038D028(&d, D_L05_001DD810 + i * 0x10, m);
        vec_add_ab(&p, &p, &d);
        func_003C5458(&p, D_L05_001DD830[i], D_L05_001DD800[i], D_L05_001DD7F8[i]);
    }
}
/* localdecomp:end func_L05_0035E050 */

INCLUDE_ASM("asm/levels", func_L05_0035E148);

/* localdecomp:start func_L05_0035E5A8 */
extern s32 D_L05_001EA6D8[];
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
void func_L05_0035E5A8(u8 *a0) {
    Vec4 a;
    Vec4 b;
    u8 *s0;
    a.q = *(u128_t *)(a0 + 16);
    s0 = *(u8 **)(a0 + 104);
    b.q = *(u128_t *)(s0 + 768);
    a.f[2] += *(f32 *)(s0 + 120);
    b.f[2] += *(f32 *)(s0 + 120);
    if (!func_003D3CB0(&a, &b, 16, a0, 0) || (D_L05_001EA6D8[0] != 0 && D_L05_001EA6D8[0] == *(s32 *)(s0 + 560))) {
        *(u128_t *)(s0 + 784) = *(u128_t *)(s0 + 752) = *(u128_t *)(s0 + 768);
    }
}
/* localdecomp:end func_L05_0035E5A8 */

/* localdecomp:start func_L05_0035E640 */
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
extern s32 D_L05_001EA6D8[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
s32 func_L05_0035E640(u8 *a0) {
    u8 buf[16];
    u128_t q;
    u8 *s1;
    s32 d;
    s1 = *(u8 **)(a0 + 104);
    func_003C2F58(a0, 6, buf);
    q = *(u128_t *)(s1 + 544);
    if (((s32 (*)(u8 *a0, u128_t *a1, s32 a2, u8 *a3, s32 t0))func_003D3CB0)(buf, &q, 16, a0, 0) == 0) {
        return 1;
    }
    d = D_L05_001EA6D8[0];
    if (d != 0) {
        if (d == *(s32 *)(s1 + 560)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L05_0035E640 */

/* localdecomp:start func_L05_0035E6C8 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

s32 func_L05_0035E6C8(u8 *a0) {
    u8 *m;
    vu0_v4 p;
    vu0_v4 d;
    f32 h;

    p = *(vu0_v4 *)(a0 + 0x10);
    m = *(u8 **)(a0 + 0x68);
    d.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 0.1f;
    d.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 0.1f;
    d.z = 0.0f;
    vec_add_ab(&p, &p, &d);
    h = func_003C3D30(&p, 0, 0, 0.5f);
    if (h < *(f32 *)(a0 + 0x18)) {
        if (fabs_asm(h - *(f32 *)(a0 + 0x18)) > *(f32 *)(m + 0x7C)) {
            d.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 3.0f;
            d.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 3.0f;
            d.z = 0.0f;
            vec_add_ab(&p, a0 + 0x10, &d);
            h = func_003C3D30(&p, 0, 0, 1.0f);
            if (*(f32 *)(a0 + 0x18) - 5.0f < h) {
                *(f32 *)(m + 0x3AC) = h;
                return 1;
            }
            return 2;
        }
    }
    return 0;
}
/* localdecomp:end func_L05_0035E6C8 */

/* localdecomp:start func_L05_0035E820 */
extern u8 *D_L05_001DFC80;
extern f32 func_0038CF38(void *, void *);

void func_L05_0035E820(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 *q = (s32 *)(s + 0x3C0);
    s32 *p;
    f32 best;
    s32 i;
    s32 *e = q + *(s32 *)(s + 0x3D4);
    best = func_0038CF38(D_L05_001DFC80 + (*e << 7) + 0x30, s + 0x220);
    for (i = 0, p = q; i < 4; i++) {
        s32 t = *p++;
        if (t != -1) {
            if (best < func_0038CF38(D_L05_001DFC80 + (t << 7) + 0x30, s + 0x220)) {
                *(s32 *)(s + 0x3D4) = i;
            }
        }
    }
}
/* localdecomp:end func_L05_0035E820 */

INCLUDE_ASM("asm/levels", func_L05_0035E8F0);
