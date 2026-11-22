#include "common.h"
#include "vu0.h"
typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
/* localdecomp:start func_L01_00510F08 */

typedef struct { vu0_q q; } vu0_s_00510F08;
static __inline__ void vec_add_c_00510F08(void *d, void *a, void *b) {
    vu0_q qa = ((vu0_s_00510F08 *)a)->q, qb = ((vu0_s_00510F08 *)b)->q, qr;
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_s_00510F08 *)d) : "j"(qr));
}
static __inline__ void vec_add_copy_00510F08(void *d, void *b, void *cd, void *cs) {
    vu0_q x, y, qc;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_s_00510F08 *)b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_s_00510F08 *)d), "j"(x), "j"(x));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("lqc2 %1, %3\n\tsqc2 %1, %0\n\tsqc2 %4, %2" : "=m"(*(vu0_s_00510F08 *)cd), "+j"(x), "=m"(*(vu0_s_00510F08 *)d) : "m"(*(vu0_s_00510F08 *)cs), "j"(y));
}
extern D_001A4BE0_t D_001A4BE0;
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00511588(f32 *, f32 *, f32);
extern void func_L01_00511508(Vec4 *, Vec4 *, f32);

void func_L01_00510F08(Vec4 *o, Vec4 *q, f32 x) {
    Vec4 a;
    Vec4 b;
    u8 *base = (u8 *)&D_001A4BE0;

    switch (base[0x25F4]) {
    case 0:
        o->f[2] = q->f[2] - x;
        break;
    case 1: {
        Vec4 c;
        func_0038CF68(&a, base + 0x2C0, -x);
        func_L01_00511588(b.f, q->f, 0.0f);
        func_L01_00511508(o, o, 0.0f);
        vec_add_copy_00510F08(o, &b, &c, &a);
        vec_add_c_00510F08(o, o, &c);
        break;
    }
    case 2: {
        Vec4 c;
        func_0038CF68(&a, base + 0x2E0, x);
        func_L01_00511588(b.f, q->f, 0.0f);
        func_L01_00511508(o, o, 0.0f);
        vec_add_copy_00510F08(o, &b, &c, &a);
        vec_add_c_00510F08(o, o, &c);
        break;
    }
    }
}
/* localdecomp:end func_L01_00510F08 */
