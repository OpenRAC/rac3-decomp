#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;

typedef struct { u8 pad0[0xFB0]; f32 f0FB0; u8 pad1[0x2468 - 0xFB4]; f32 f2468; } S_00633160;

typedef struct {
    u8 pad0[0x474];
    s32 mode;
    s32 kind;
    u8 pad1[0x142F - 0x47C];
    u8 alternate;
    u8 pad2[0x1A07 - 0x1430];
    u8 special;
    u8 pad3[0x2468 - 0x1A08];
    f32 speed;
} View_00633428;

/* localdecomp:start func_L39_00632A20 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);
typedef struct { vu0_q q; } vu0_s_00632A20;
static __inline__ void vec_add_c_00632A20(void *d, void *a, void *b) {
    vu0_q qa = ((vu0_s_00632A20 *)a)->q, qb = ((vu0_s_00632A20 *)b)->q, qr;
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_s_00632A20 *)d) : "j"(qr));
}
static __inline__ void vec_add_copy_00632A20(void *d, void *b, void *cd, void *cs) {
    vu0_q x, y, qc;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_s_00632A20 *)b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_s_00632A20 *)d), "j"(x), "j"(x));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("lqc2 %1, %3\n\tsqc2 %1, %0\n\tsqc2 %4, %2" : "=m"(*(vu0_s_00632A20 *)cd), "+j"(x), "=m"(*(vu0_s_00632A20 *)d) : "m"(*(vu0_s_00632A20 *)cs), "j"(y));
}
void func_L39_00632A20(u8 *m, vu0_v4 *out, vu0_v4 *in, f32 f)
{
    vu0_v4 t0;
    vu0_v4 t1;

    switch (m[0x1A06]) {
    case 0:
        out->z = in->z - f;
        break;
    case 1:
        func_0038CF68(&t0, m + 0x230, -f);
        func_L39_00632298(m, &t1, in, 0.0f);
        func_L39_00632558(m, out, out, 0.0f);
        {
            vu0_v4 tmp;
            vec_add_copy_00632A20(out, &t1, &tmp, &t0);
            vec_add_c_00632A20(out, out, &tmp);
        }
        break;
    case 2:
        func_0038CF68(&t0, m + 0x250, f);
        func_L39_00632298(m, &t1, in, 0.0f);
        func_L39_00632558(m, out, out, 0.0f);
        {
            vu0_v4 tmp;
            vec_add_copy_00632A20(out, &t1, &tmp, &t0);
            vec_add_c_00632A20(out, out, &tmp);
        }
        break;
    }
}
/* localdecomp:end func_L39_00632A20 */
