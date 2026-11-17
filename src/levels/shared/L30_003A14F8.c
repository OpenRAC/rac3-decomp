#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;

/* localdecomp:start func_L30_003A14F8 */
#include "vu0.h"
typedef struct { Vec4 a; Vec4 b; } E_003A14F8;
typedef struct { u8 pad0[0xD4]; u8 *xD4; u8 pad1[0x16C - 0xD8]; u8 *x16C; } G_003A14F8;
typedef struct { u8 b0, b1, b2, b3; } P_003A14F8;
extern G_003A14F8 D_L30_0021F098;
extern u8 D_L30_001D66B0;
extern f32 D_L30_001DE9F0;
__asm__(".extern D_L30_001DE9F0, 4");
extern f32 D_L30_001DE9D0;
__asm__(".extern D_L30_001DE9D0, 4");
extern f32 D_L30_001DE9CC;
__asm__(".extern D_L30_001DE9CC, 4");
extern f32 D_L30_001DE9C4;
__asm__(".extern D_L30_001DE9C4, 4");
extern f32 D_L30_001DE9C8;
__asm__(".extern D_L30_001DE9C8, 4");
extern s32 D_L30_001DE924;
__asm__(".extern D_L30_001DE924, 4");
extern f32 D_L30_001DE9BC;
__asm__(".extern D_L30_001DE9BC, 4");
extern s32 D_L30_001DE9B8;
__asm__(".extern D_L30_001DE9B8, 4");
extern s32 D_L30_001DE9DC;
__asm__(".extern D_L30_001DE9DC, 4");
extern f32 D_L30_001DE9E4;
__asm__(".extern D_L30_001DE9E4, 4");
extern f32 D_L30_001DE9E8;
__asm__(".extern D_L30_001DE9E8, 4");
extern f32 D_L30_001DE9EC;
__asm__(".extern D_L30_001DE9EC, 4");
extern s32 D_L30_001DE9E0;
__asm__(".extern D_L30_001DE9E0, 4");
extern u8 D_L30_001DE9D8;
__asm__(".extern D_L30_001DE9D8, 4");
extern f32 D_L30_001DE9D4;
__asm__(".extern D_L30_001DE9D4, 4");
extern f32 D_L30_001DE9A8;
__asm__(".extern D_L30_001DE9A8, 4");
extern f32 D_L30_001DE9AC;
__asm__(".extern D_L30_001DE9AC, 4");
extern s32 D_L30_001DE9A0;
__asm__(".extern D_L30_001DE9A0, 4");
extern s32 D_L30_001DE9A4;
__asm__(".extern D_L30_001DE9A4, 4");
extern s32 func_003C2B88(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern P_003A14F8 *func_L30_004437E8(void *, s32, s32, s32, f32, f32);
extern void func_00382580(void *, f32, f32);
extern P_003A14F8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);

static __inline__ void spawn_003A14F8(Vec4 *pos, s32 t, f32 size) {
    P_003A14F8 *q;

    q = func_L01_004713C8(pos, &D_L30_001D66B0, t, D_L30_001DE9A4, 0, 0x30, 0x30, size * 210000.0f, 4200.0f, -0.0012f, 0);
    if (q != 0) {
        q->b2 = *D_L30_0021F098.xD4;
    }
}

void func_L30_003A14F8(u8 *m) {
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

    n = func_003C2B88(m, 0);
    if (n <= 0) {
        return;
    }
    func_0038CF68(&v10, *(void **)(m + 0x68), D_L30_001DE9F0 * 0.020000001f);
    func_L01_00451FE0(m, 7, (u8 *)&v10, 0xFF, 0xB4, 0, 0, 0x23,
                      D_L30_001DE9C4, D_L30_001DE9C8, D_L30_001DE9CC, D_L30_001DE9D0,
                      -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    v20.q = 0;
    v20.f[2] = 0.7f;
    v20.f[0] = -0.3f;
    func_0038D328(mtx, m + 0xF0);
    func_0038D028(&v30, &v20, mtx);
    vec_add_ab(&v20, &v30, m + 0x10);
    t = (func_00382498(D_L30_001DE924 + 10, D_L30_001DE924 + 20) * 5 + 2) / 6;
    f = func_003824E0(D_L30_001DE9BC * 0.7f, D_L30_001DE9BC);
    q = func_L30_004437E8(&v20, D_L30_001DE9B8, D_L30_001DE9B8 & 0xFFFFFF, t, f, f * 0.7f);
    if (q != 0) {
        q->b2 = *D_L30_0021F098.xD4;
    }
    for (i = 0; i < D_L30_001DE9DC; i++) {
        func_00382580(&v80, 0.3f, D_L30_001DE9E4);
        vec_add_ba(&v80, m + 0x10, &v80);
        k = func_00382498(-2, 2);
        p = func_L01_004713C8(&v80, &D_L30_001D66B0, D_L30_001DE9E0, 0x7F808080, k, D_L30_001DE9D8, 0, D_L30_001DE9E8 * 210000.0f, D_L30_001DE9EC * 210000.0f, -0.0012f, 1);
        if (p != 0) {
            if (func_00382468(4) != 0) {
                p->b2 = D_L30_0021F098.x16C[4];
                p->b3 = func_00382468(2) != 0 ? 0x44 : 0x48;
            } else {
                p->b2 = D_L30_0021F098.x16C[0];
                p->b3 = 0x48;
            }
        }
    }
    e = (E_003A14F8 *)0x70000000; /* scratchpad */
    for (j = 0; j < n; j++, e++) {
        t = (func_00382498(D_L30_001DE924 - 5, D_L30_001DE924 + 10) * 5 + 2) / 6;
        if (e->b.f[3] == 0.0f) {
            v80.q = e->a.q;
            v80.f[3] = 1.0f;
            func_00382580(&v90, 0.0f, e->a.f[3]);
            vec_add_ab(&v80, &v80, &v90);
            k = func_L01_00443A18(2.0f, 5.0f);
            size = func_003824E0(D_L30_001DE9A8, D_L30_001DE9AC) * e->a.f[3];
            func_L01_004713C8(&v80, &D_L30_001D66B0, t, D_L30_001DE9A0, k, 0x7F, 0x7F, size * 210000.0f, 2100.0f, -0.0012f, 1);
            size *= D_L30_001DE9D4;
            spawn_003A14F8(&v80, t, size);
        } else {
            v80.q = e->a.q;
            v90.q = e->b.q;
            v80.f[3] = 1.0f;
            v90.f[3] = 1.0f;
            func_0038CDF8(&vA0, &v80, &v90, func_003824E0(0.0f, 1.0f));
            vA0.f[0] += func_003824E0(-e->a.f[3] * 0.4f, e->a.f[3] * 0.4f);
            vA0.f[1] += func_003824E0(-e->a.f[3] * 0.4f, e->a.f[3] * 0.4f);
            vA0.f[2] += func_003824E0(-e->a.f[3] * 0.4f, e->a.f[3] * 0.4f);
            k = func_L01_00443A18(2.0f, 5.0f);
            size = func_003824E0(D_L30_001DE9A8, D_L30_001DE9AC) * e->a.f[3];
            func_L01_004713C8(&vA0, &D_L30_001D66B0, t, D_L30_001DE9A0, k, 0x7F, 0x7F, size * 210000.0f, 2100.0f, -0.0012f, 1);
            size *= 6.0f;
            spawn_003A14F8(&vA0, t, size);
        }
    }
}
/* localdecomp:end func_L30_003A14F8 */
