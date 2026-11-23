/* functional: high. Same behaviour; difference is register allocation and scheduling. func_L07_003A79F0/003A7AC0 declared with void* params here but the file later defines them with typed pointers: adjust at landing. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003A75E0 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
} R_003A75E0;
extern s32 D_001DE3D0_sda;
__asm__(".extern D_001DE3D0_sda, 4");
extern f32 D_001DE3D8_sda;
__asm__(".extern D_001DE3D8_sda, 4");
extern void func_L07_003A7AC0(R_003A75E0 *, f32, void *, void *);
extern void func_L07_003A79F0(void *, void *, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_0040E4C0(void *);

void func_L07_003A75E0(void *arg0) {
    u8 *o = arg0;
    u8 *s = *(u8 **)(o + 0x68);
    R_003A75E0 r;
    vu0_v4 g;
    vu0_v4 t;
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 e;
    u8 *w;
    u8 *pp;
    s32 a;
    s32 i;
    s32 j;
    s32 jj;
    s32 k;
    s32 m;
    f32 len;
    f32 f20;
    f32 x;
    vu0_v4 *q;
    vu0_v4 *q2;
    vu0_v4 *p3;
    vu0_v4 *q3;

    func_L07_003A7AC0(&r, (f32)*(u16 *)(o + 0x96) * *(f32 *)(s + 0x29C), *(void **)(s + 0x290), *(void **)(s + 0x294));
    if (*(u16 *)(o + 0x96) < (D_001DE3D0_sda * 5 + 2) / 6) {
        r.f8 = D_001DE3D8_sda;
    }
    *(u128_t *)&t = 0;
    t.z = r.f4;
    w = s + 0x280;
    g = t;
    func_L01_0044FD88(*(struct Moby **)(o + 0xB8), (struct Moby *)o, s[0x2BA], 0);
    *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) & 0xFFFD;
    *(u128_t *)s = *(u128_t *)(o + 0x10);
    *(u128_t *)(s + 0x140) = *(u128_t *)(o + 0x10);
    func_0038CF68(&t, o + 0xC0, r.f0);
    pp = (u8 *)&p;
    for (a = 1; a < r.b15; a++) {
        vec_add_ab(s + a * 16, s + a * 16 - 16, &t);
        *(u128_t *)(s + a * 16 + 0x140) = *(u128_t *)(s + a * 16);
    }
    q = (vu0_v4 *)s + r.b15;
    q2 = (vu0_v4 *)s + (r.b15 + 20);
    for (j = r.b15; j < 20; j++, q++, q2++) {
        p = *q;
        vec_sub_ba(&d, q, q2);
        func_0038CE20(&d, &d, r.f8);
        vec_add_ab(q, q, &d);
        vec_add_ab(q, q, &g);
        *(u128_t *)q2 = *(u128_t *)&p;
    }
    for (k = 0; k < r.b14; k++) {
        for (jj = 0, p3 = (vu0_v4 *)s; jj < 19; jj++, p3++) {
            for (m = 1, q3 = p3 + 1; m <= r.b17 && jj + m < 20; m++, q3++) {
                func_L07_003A79F0(p3, q3, jj >= r.b15, jj + m >= r.b15, ((f32)m * r.f0) * ((f32)m * r.f0));
            }
        }
    }
    func_0038D000(pp, w, *(u8 **)(o + 0xB8) + 0xC0);
    vec_add_ab(&p, &p, *(u8 **)(o + 0xB8) + 0x10);
    q = (vu0_v4 *)s;
    for (i = 0; i < 20; i++, q++) {
        if (q->z < r.fC + *(f32 *)(s + 0x298)) {
            q->z = r.fC + *(f32 *)(s + 0x298);
        }
        if (i < r.b16) {
            continue;
        }
        vec_sub_ab(&d, &p, q);
        f20 = r.f10 * r.f10;
        len = func_L01_0040E4C0(&d);
        x = f20 / (len + f20) - 0.5f;
        if (0.0f < x) {
            func_0038CE20(&e, &d, x + x);
            vec_sub_ab(q, q, &e);
        }
        if (!(q->z < p.z)) {
            continue;
        }
        d.z = 0.0f;
        len = func_L01_0040E4C0(&d);
        x = f20 / (len + f20) - 0.5f;
        if (0.0f < x) {
            func_0038CE20(&e, &d, x + x);
            vec_sub_ab(q, q, &e);
        }
    }
}
/* localdecomp:end func_L07_003A75E0 */
