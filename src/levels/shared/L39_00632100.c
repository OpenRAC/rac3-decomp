#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

/* declared by functions of L39_0062D7C8.c, which this file was cut from */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern void func_0038D000(f32 *, f32 *, u8 *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D328(float *, void *);
extern void func_0038D5B0(float *, float *);
extern f32 func_L39_00632678(u8 *, f32 *);

/* localdecomp:start func_L39_00632100 */

extern f32 func_0038CED8(Vec4 *);
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern f32 func_0038D160(f32, f32);

f32 func_L39_00632100(u8 *m, Vec4 *v) {
    Vec4 t;

    switch (m[6662]) {
    case 0:
        return func_0038D160(v->f[2], func_0038CED8(v));
    case 1:
    case 2:
        t.q = v->q;
        func_0038D028(&t, &t, m + 96);
        return func_0038D160(t.f[2], func_0038CED8(&t));
    }
    return 0.0f;
}
/* localdecomp:end func_L39_00632100 */

/* localdecomp:start func_L39_00632180 */
#include "vu0.h"
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);

void func_L39_00632180(u8 *m, f32 *out, s32 add, f32 x, f32 y, f32 z) {
    qzero(out);
    out[0] = x;
    out[1] = y;
    out[2] = z;
    func_0038D028((Vec4 *)out, (Vec4 *)out, m + 0x20);
    if (add) {
        __asm__ __volatile__(
            "lqc2 $vf2, %1\n"
            "lqc2 $vf1, 0(%0)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "m"(*(vu0_v4 *)(m + 0xA0)) : "memory");
    }
}
/* localdecomp:end func_L39_00632180 */

/* localdecomp:start func_L39_006321F0 */
#include "vu0.h"
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);

void func_L39_006321F0(u8 *m, Vec4 *v, s32 add, f32 scale, f32 ang, f32 z) {
    v->f[0] = func_0038D098(ang) * scale;
    v->f[1] = func_0038D0B0(ang) * scale;
    v->f[2] = z;
    func_0038D028(v, v, m + 0x20);
    if (add) {
        __asm__ __volatile__(
            "lqc2 $vf2, %1\n"
            "lqc2 $vf1, 0(%0)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(v), "m"(*(vu0_v4 *)(m + 0xA0)) : "memory");
    }
}
/* localdecomp:end func_L39_006321F0 */

/* localdecomp:start func_L39_00632298 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);

extern void func_0038CFB8(f32 *, f32 *, f32);

void func_L39_00632298(Obj62FA50 *o, f32 *dst, f32 *src, f32 scale) {
    switch (o->mode) {
    case 0:
        func_0038CFB8(dst, src, scale);
        break;
    case 1:
    case 2:
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, src, o->m1);
        func_0038CFB8(dst, dst, scale);
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, dst, o->m0);
        break;
    }
}
/* localdecomp:end func_L39_00632298 */

/* localdecomp:start func_L39_00632328 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
void func_L39_00632328(u8 *a, Vec4 *dst, Vec4 *src, f32 s) {
    switch (a[0x1A06]) {
    case 0:
        *dst = *src;
        dst->f[2] *= s;
        break;
    case 1:
    case 2:
        func_0038D028(dst, src, a + 0x60);
        dst->f[2] *= s;
        func_0038D028(dst, dst, a + 0x20);
        break;
    }
}
/* localdecomp:end func_L39_00632328 */

/* localdecomp:start func_L39_006323B8 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
void func_L39_006323B8(u8 *p, float *v, void *m, float s) {
    switch (p[6662]) {
    case 0:
        v[0] *= s;
        v[1] *= s;
        break;
    case 1:
    case 2:
        ((void (*)(float *, void *, void *))func_0038D028)(v, m, p + 96);
        v[0] *= s;
        v[1] *= s;
        ((void (*)(float *, void *, void *))func_0038D028)(v, v, p + 32);
        break;
    }
}
/* localdecomp:end func_L39_006323B8 */

INCLUDE_ASM("asm/levels", func_L39_00632458);

/* localdecomp:start func_L39_00632558 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);



void func_L39_00632558(S_62FD10 *s, Vec4 *out, Vec4 *in, f32 z) {
    s32 m = s->mode;

    if (m == 0) {
        out->q = in->q;
        out->f[2] = z;
        return;
    }
    if (m < 0) {
        return;
    }
    if (m < 3) {
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, in, s->m60);
        out->f[2] = z;
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, out, s->m20);
    }
}
/* localdecomp:end func_L39_00632558 */

/* localdecomp:start func_L39_006325D8 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern f32 func_0038CED8(Vec4 *);
extern void func_0038D328(float *, void *);
extern void func_0038D5B0(float *, float *);
float func_L39_006325D8(u8 *p, float *v) {
    float m[16];
    float inv[16];
    float t[4];
    switch (p[6662]) {
    case 0:
        return ((float (*)(float *))func_0038CED8)(v);
    case 1:
    case 2:
        func_0038D328(m, (void *)(*(s32 *)(p + 9508) + 240));
        func_0038D5B0(inv, m);
        ((void (*)(float *, void *, void *))func_0038D028)(t, v, inv);
        return ((float (*)(float *))func_0038CED8)(t);
    }
    return 0.0f;
}
/* localdecomp:end func_L39_006325D8 */

/* localdecomp:start func_L39_00632678 */
extern void func_0038D000(f32 *, f32 *, u8 *);
f32 func_L39_00632678(u8 *a, f32 *b) {
    f32 tmp[4];
    switch (a[6662]) {
    case 0:
        return b[2];
    case 1:
    case 2:
        func_0038D000(tmp, b, a + 96);
        return tmp[2];
    }
    return 0.0f;
}
/* localdecomp:end func_L39_00632678 */

/* localdecomp:start func_L39_006326C8 */
#include "vu0.h"
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);

f32 func_L39_006326C8(u8 *p) {
    f32 m[16];
    Vec4 v;
    Vec4 a;
    Vec4 b;
    Vec4 c;
    v.f[0] = func_0038D098(0.0f);
    v.f[1] = func_0038D0B0(0.0f);
    v.f[2] = 0.0f;
    func_0038D328(m, p + 0xB0);
    func_0038D028(&v, &v, (u8 *)m);
    if (*(f32 *)(p + 0x230) != 0.0f || *(f32 *)(p + 0x234) != 0.0f) {
        qzero(&a);
        c.q = *(u128_t *)(p + 0x230);
        qzero(&b);
        a.f[2] = -func_0038D160(*(f32 *)(p + 0x230), *(f32 *)(p + 0x234));
        func_0038D328(m, &a);
        func_0038D028(&v, &v, (u8 *)m);
        func_0038D028(&c, &c, (u8 *)m);
        b.f[1] = -func_0038D160(c.f[2], c.f[0]);
        func_0038D328(m, &b);
        func_0038D028(&v, &v, (u8 *)m);
        a.f[2] = -a.f[2];
        func_0038D328(m, &a);
        func_0038D028(&v, &v, (u8 *)m);
    }
    return func_0038D160(v.f[0], v.f[1]);
}
/* localdecomp:end func_L39_006326C8 */

/* localdecomp:start func_L39_00632818 */
#include "vu0.h"
extern void func_L39_00632888(void *, void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

f32 func_L39_00632818(void *a0, u128_t *a1) {
    u128_t t[2];

    t[0] = *a1;
    qzero(&t[1]);
    func_L39_00632888(a0, &t[1], &t[1], 1.0f);
    return func_0038CE68(&t[0], &t[1]);
}
/* localdecomp:end func_L39_00632818 */
