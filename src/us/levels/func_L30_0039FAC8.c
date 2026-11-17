#include "common.h"

/* NTSC-U counterpart of func_L30_003A14F8 (src/levels/shared/L30_003A14F8.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;

/* localdecomp:start func_L30_0039FAC8 */
#include "vu0.h"
typedef struct { Vec4 a; Vec4 b; } E_003A14F8;
typedef struct { u8 pad0[0xD4]; u8 *xD4; u8 pad1[0x16C - 0xD8]; u8 *x16C; } G_003A14F8;
typedef struct { u8 b0, b1, b2, b3; } P_003A14F8;
extern G_003A14F8 D_L30_0021F098_0039FAC8;
extern u8 D_L30_001D66B0_0039FAC8;
extern f32 D_L30_001DEA30;
__asm__(".extern D_L30_001DEA30, 4");
extern f32 D_L30_001DEA10_0039FAC8;
__asm__(".extern D_L30_001DEA10_0039FAC8, 4");
extern f32 D_L30_001DEA0C;
__asm__(".extern D_L30_001DEA0C, 4");
extern f32 D_L30_001DEA04;
__asm__(".extern D_L30_001DEA04, 4");
extern f32 D_L30_001DEA08;
__asm__(".extern D_L30_001DEA08, 4");
extern s32 D_L30_001DE964_0039FAC8;
__asm__(".extern D_L30_001DE964_0039FAC8, 4");
extern f32 D_L30_001DE9FC_0039FAC8;
__asm__(".extern D_L30_001DE9FC_0039FAC8, 4");
extern s32 D_L30_001DE9F8_0039FAC8;
__asm__(".extern D_L30_001DE9F8_0039FAC8, 4");
extern s32 D_L30_001DEA1C;
__asm__(".extern D_L30_001DEA1C, 4");
extern f32 D_L30_001DEA24;
__asm__(".extern D_L30_001DEA24, 4");
extern f32 D_L30_001DEA28;
__asm__(".extern D_L30_001DEA28, 4");
extern f32 D_L30_001DEA2C;
__asm__(".extern D_L30_001DEA2C, 4");
extern s32 D_L30_001DEA20;
__asm__(".extern D_L30_001DEA20, 4");
extern u8 D_L30_001DEA18;
__asm__(".extern D_L30_001DEA18, 4");
extern f32 D_L30_001DEA14;
__asm__(".extern D_L30_001DEA14, 4");
extern f32 D_L30_001DE9E8_0039FAC8;
__asm__(".extern D_L30_001DE9E8_0039FAC8, 4");
extern f32 D_L30_001DE9EC_0039FAC8;
__asm__(".extern D_L30_001DE9EC_0039FAC8, 4");
extern s32 D_L30_001DE9E0_0039FAC8;
__asm__(".extern D_L30_001DE9E0_0039FAC8, 4");
extern s32 D_L30_001DE9E4_0039FAC8;
__asm__(".extern D_L30_001DE9E4_0039FAC8, 4");
extern s32 func_003BD668(void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_00388BF0(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern P_003A14F8 *func_L30_004400E0(void *, s32, s32, s32, f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern P_003A14F8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_L01_00440918(f32, f32);
extern void func_003886C0(void *, void *, void *, f32);

static __inline__ void spawn_003A14F8(Vec4 *pos, s32 t, f32 size) {
    P_003A14F8 *q;

    q = func_L01_0046DCB8(pos, &D_L30_001D66B0_0039FAC8, t, D_L30_001DE9E4_0039FAC8, 0, 0x30, 0x30, size * 210000.0f, 4200.0f, -0.0008333333535119891f, 0);
    if (q != 0) {
        q->b2 = *D_L30_0021F098_0039FAC8.xD4;
    }
}

void func_L30_0039FAC8(u8 *m) {
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;
    u8 mtx[0x40] __attribute__((aligned(16)));
    Vec4 v80;
    Vec4 v90;
    Vec4 vA0;
    s32 n;
    s32 i;
    s32 j;
    s32 t;
    s32 k;
    f32 f;
    f32 size;
    P_003A14F8 *p;
    P_003A14F8 *q;
    E_003A14F8 *e;

    n = func_003BD668(m, 0);
    if (n <= 0) {
        return;
    }
    func_00388830(&v10, *(void **)(m + 0x68), D_L30_001DEA30 * 0.0166666675f);
    func_L01_0044ED60(m, 7, (u8 *)&v10, 0xFF, 0xB4, 0, 0, 0x23,
                      D_L30_001DEA04, D_L30_001DEA08, D_L30_001DEA0C, D_L30_001DEA10_0039FAC8,
                      -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    v20.q = 0;
    v20.f[2] = 0.7f;
    v20.f[0] = -0.3f;
    func_00388BF0(mtx, m + 0xF0);
    func_003888F0(&v30, &v20, mtx);
    vec_add_ab(&v20, &v30, m + 0x10);
    t = func_0037E208(D_L30_001DE964_0039FAC8 + 10, D_L30_001DE964_0039FAC8 + 20);
    f = func_0037E250(D_L30_001DE9FC_0039FAC8 * 0.7f, D_L30_001DE9FC_0039FAC8);
    q = func_L30_004400E0(&v20, D_L30_001DE9F8_0039FAC8, D_L30_001DE9F8_0039FAC8 & 0xFFFFFF, t, f, f * 0.7f);
    if (q != 0) {
        q->b2 = *D_L30_0021F098_0039FAC8.xD4;
    }
    for (i = 0; i < D_L30_001DEA1C; i++) {
        func_0037E2F0(&v80, 0.3f, D_L30_001DEA24);
        vec_add_ba(&v80, m + 0x10, &v80);
        k = func_0037E208(-2, 2);
        p = func_L01_0046DCB8(&v80, &D_L30_001D66B0_0039FAC8, D_L30_001DEA20, 0x7F808080, k, D_L30_001DEA18, 0, D_L30_001DEA28 * 210000.0f, D_L30_001DEA2C * 210000.0f, -0.0008333333535119891f, 1);
        if (p != 0) {
            if (func_0037E1D8(4) != 0) {
                p->b2 = D_L30_0021F098_0039FAC8.x16C[4];
                p->b3 = func_0037E1D8(2) != 0 ? 0x44 : 0x48;
            } else {
                p->b2 = D_L30_0021F098_0039FAC8.x16C[0];
                p->b3 = 0x48;
            }
        }
    }
    e = (E_003A14F8 *)0x70000000; /* scratchpad */
    for (j = 0; j < n; j++, e++) {
        t = func_0037E208(D_L30_001DE964_0039FAC8 - 5, D_L30_001DE964_0039FAC8 + 10);
        if (e->b.f[3] == 0.0f) {
            v80.q = e->a.q;
            v80.f[3] = 1.0f;
            func_0037E2F0(&v90, 0.0f, e->a.f[3]);
            vec_add_ab(&v80, &v80, &v90);
            k = func_L01_00440918(2.0f, 5.0f);
            size = func_0037E250(D_L30_001DE9E8_0039FAC8, D_L30_001DE9EC_0039FAC8) * e->a.f[3];
            func_L01_0046DCB8(&v80, &D_L30_001D66B0_0039FAC8, t, D_L30_001DE9E0_0039FAC8, k, 0x7F, 0x7F, size * 210000.0f, 2100.0f, -0.0008333333535119891f, 1);
            size *= D_L30_001DEA14;
            spawn_003A14F8(&v80, t, size);
        } else {
            v80.q = e->a.q;
            v90.q = e->b.q;
            v80.f[3] = 1.0f;
            v90.f[3] = 1.0f;
            func_003886C0(&vA0, &v80, &v90, func_0037E250(0.0f, 1.0f));
            vA0.f[0] += func_0037E250(-e->a.f[3] * 0.4f, e->a.f[3] * 0.4f);
            vA0.f[1] += func_0037E250(-e->a.f[3] * 0.4f, e->a.f[3] * 0.4f);
            vA0.f[2] += func_0037E250(-e->a.f[3] * 0.4f, e->a.f[3] * 0.4f);
            k = func_L01_00440918(2.0f, 5.0f);
            size = func_0037E250(D_L30_001DE9E8_0039FAC8, D_L30_001DE9EC_0039FAC8) * e->a.f[3];
            func_L01_0046DCB8(&vA0, &D_L30_001D66B0_0039FAC8, t, D_L30_001DE9E0_0039FAC8, k, 0x7F, 0x7F, size * 210000.0f, 2100.0f, -0.0008333333535119891f, 1);
            size *= 6.0f;
            spawn_003A14F8(&vA0, t, size);
        }
    }
}
/* localdecomp:end func_L30_0039FAC8 */
