/* near miss (level 5, Daxx): 8 differences: needs @ps2as; -0.04f and 1.5f in swapped saved FP registers (retail f25/f24), and mov.s f12 before move a2 in the second call */
#include "common.h"

/* localdecomp:start func_L05_003DB9F8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DB9F8;

typedef struct S_3DB9F8 {
    u8 pad0[0x68];
    s32 *f68;
} S_3DB9F8;

extern f32 D_001DF15C_sda;
__asm__(".extern D_001DF15C_sda, 4");

extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(S_3DB9F8 *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L05_003DB9F8(S_3DB9F8 *a0) {
    V4_3DB9F8 b;
    V4_3DB9F8 v;
    u128_t z;
    s32 *p;
    s32 r;
    u8 *c;
    f32 km, k0, k1, k2, k3;

    km = -0.040000003f;
    k0 = 0.0f;
    k1 = 1.5f;
    k2 = 15.0f;
    k3 = 1.0f;
    p = a0->f68;
    c = (u8 *)a0 + 0xC0;
    z = 0;
    *(u128_t *)&v = z;
    v.z = D_001DF15C_sda;
    b = v;
    *(u128_t *)&v = z;
    v.x = 0.040000003f;
    v.z = km;
    func_0038D000(&v, &v, c);
    r = func_00382498(3, 6);
    func_L02_003E2E38(a0, &b, &v, r, 0, 0, k0, 0.040000003f, k1, k2, k3);
    v.x = km;
    v.z = -0.048000004f;
    func_0038D000(&v, &v, c);
    r = func_00382498(3, 6);
    func_L02_003E2E38(a0, &b, &v, r, 1, 0, k0, 0.040000003f, k1, k2, k3);
    r = func_00382498(0x5A, 0xB4);
    *p = (r * 5 + 2) / 6;
}
/* localdecomp:end func_L05_003DB9F8 */
