#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    Vec4 v;
    u8 *o;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} S34BD48;

/* localdecomp:start func_L30_0034CB68 */
extern void func_L30_0034CC28(S34BD48 *s, u8 *o, Vec4 *pos, s32 a3, s32 a4, f32 f);
extern void func_003C2F58(u8 *a0, s32 a1, u128_t *a2);
extern s32 func_003D4D00(u128_t *a0, s32 a1, u8 *a2, s32 a3, f32 f12);
extern void func_L30_004E70A8(u8 *a0, u128_t *a1, u8 *a2, s32 a3);
void func_L30_0034CB68(u8 *a0, s32 a1, s32 a2, s32 a3, u128_t *t0, s32 t1, f32 f12, f32 f13) {
    u128_t m[3];
    u128_t pos;
    s32 r;
    ((void (*)(u128_t *a0, u8 *a1, s32 a2, s32 a3, s32 t0, f32 f12))func_L30_0034CC28)(m, a0, a1, a2, t1, f12);
    if (a3 < 0) {
        if (t0 != 0) {
            pos = *t0;
        } else {
            pos = *(u128_t *)(a0 + 16);
        }
    } else {
        func_003C2F58(a0, a3, &pos);
    }
    r = func_003D4D00(&pos, 0, a0, 0, f13);
    if (r != 0) {
        func_L30_004E70A8(a0, m, a0 + 16, r);
    }
}
/* localdecomp:end func_L30_0034CB68 */

/* localdecomp:start func_L30_0034CC28 */


extern void func_0038CF68(S34BD48 *, S34BD48 *, f32);

void func_L30_0034CC28(S34BD48 *s, u8 *o, Vec4 *pos, s32 a3, s32 a4, f32 f) {
    s->o = o;
    if (a3 != 0) {
        s->flags = 0x1000001;
        if (a4 != 0) {
            s->flags = 0x1020001;
        }
    } else {
        s->flags = 0x1010000;
    }
    s->f1C = f;
    s->i20 = 1;
    s->v.q = pos->q;
    func_0038CF68(s, s, 1.0f);
    s->v.f[3] = 5627.9248046875f;
    s->b18 = 3;
    s->b19 = 2;
    s->h1A = *(u16 *)(o + 170);
}
/* localdecomp:end func_L30_0034CC28 */

/* localdecomp:start func_L30_0034CCD0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0034CCD0;

extern void func_0038D000(void *, void *, void *);

void func_L30_0034CCD0(u8 *o, f32 *x0, f32 *x1, f32 *z0, f32 *z1) {
    V_0034CCD0 hi, lo, pos;

    if (o != 0) {
        hi.x = 1.0f;
        hi.y = 1.0f;
        hi.z = 1.0f;
        lo.x = -1.0f;
        lo.y = -1.0f;
        lo.z = -1.0f;
        func_0038D000(&hi, &hi, o);
        func_0038D000(&lo, &lo, o);
        __asm__ __volatile__(
            "lqc2 $vf1, %3\n"
            "lqc2 $vf2, %1\n"
            "sqc2 $vf1, %2\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %1\n"
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(hi), "+m"(lo), "=m"(pos)
            : "m"(*(V_0034CCD0 *)(o + 0x30)));
        if (x0 != 0) {
            *x0 = lo.x;
        }
        if (x1 != 0) {
            *x1 = hi.x;
        }
        if (z0 != 0) {
            *z0 = lo.z;
        }
        if (z1 != 0) {
            *z1 = hi.z;
        }
    }
}
/* localdecomp:end func_L30_0034CCD0 */

/* localdecomp:start func_L30_0034CDC0 */
typedef struct {
    u8 pad0[0x140];
    f32 x;
    f32 y;
    f32 z;
} S_0034CDC0;

extern S_0034CDC0 D_L30_001E2100;
extern f32 D_001A4C64 __attribute__((section(".data")));
extern f32 D_L30_001E6EB0 __attribute__((section(".data")));
extern f32 D_L30_001E6EB4 __attribute__((section(".data")));

void func_L30_0034CDC0(f32 s, f32 *l, f32 *r, f32 *b, f32 *t) {
    f32 d = D_001A4C64 - D_L30_001E2100.y;

    if (l != 0) {
        *l = D_L30_001E2100.x - s * D_L30_001E6EB0 * d;
    }
    if (r != 0) {
        *r = D_L30_001E2100.x + s * D_L30_001E6EB0 * d;
    }
    if (b != 0) {
        *b = D_L30_001E2100.z - s * D_L30_001E6EB4 * d;
    }
    if (t != 0) {
        *t = D_L30_001E2100.z + s * D_L30_001E6EB4 * d;
    }
}
/* localdecomp:end func_L30_0034CDC0 */
