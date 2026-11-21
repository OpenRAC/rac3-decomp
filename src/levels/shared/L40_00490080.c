#include "common.h"

/* localdecomp:start func_L40_00490080 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    s16 h20[8];
    f32 f30[8];
    u8 pad50[0x10];
} S_00490080;

extern S_00490080 D_L40_002926E0[];
extern s32 D_L40_00248628;
extern f32 func_0038CF38(void *, void *);
extern s32 func_L39_005BEAF8(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L40_004903C8(s32, s32, f32);

static __inline__ void cross_00490080(vu0_v4 *r, vu0_v4 *a, vu0_v4 *b) {
    func_0038CE90(r, a, b);
}

static __inline__ void scale_00490080(vu0_v4 *v, f32 s) {
    func_0038CF68(v, v, s);
}

static __inline__ f32 dist_00490080(S_00490080 *a, S_00490080 *b) {
    return func_0038CF00(a, b);
}

void func_L40_00490080(void) {
    vu0_v4 up;
    vu0_v4 side;
    vu0_v4 d;
    vu0_v4 p1;
    vu0_v4 p2;
    vu0_q qu;
    S_00490080 *a;
    S_00490080 *b;
    s32 i, j, n, m, k;
    f32 dist, z, lo, hi;

    for (i = 0; i < D_L40_00248628; i++) {
        a = &D_L40_002926E0[i];
        for (j = i + 1; j < D_L40_00248628; j++) {
            b = &D_L40_002926E0[j];
            if (func_0038CF38(a, b) > 40.0f) {
                continue;
            }
            if (!func_L39_005BEAF8(a, b, 0)) {
                continue;
            }
            __asm__("vmr32.xyzw %0, vf0" : "=j"(qu));
            __asm__("sqc2 %1, %0" : "=m"(up) : "j"(qu));
            vec_sub_ab(&d, a, b);
            cross_00490080(&side, &d, &up);
            scale_00490080(&side, 0.5f);
            vec_add_ba(&p1, a, &side);
            vec_add_ab(&p2, b, &side);
            if (!func_L39_005BEAF8(&p1, &p2, 0)) {
                continue;
            }
            vec_sub_ba(&p1, a, &side);
            vec_sub_ab(&p2, b, &side);
            if (!func_L39_005BEAF8(&p1, &p2, 0)) {
                continue;
            }
            func_L40_004903C8(i, j, dist_00490080(a, b));
        }
    }
    for (n = 0; n < D_L40_00248628; n++) {
        lo = hi = D_L40_002926E0[n].pos.z;
        for (m = 0; m < 8 && (k = D_L40_002926E0[n].h20[m]) != -1; m++) {
            dist = dist_00490080(&D_L40_002926E0[n], &D_L40_002926E0[k]);
            if (D_L40_002926E0[n].f10 < dist) {
                D_L40_002926E0[n].f10 = dist;
            }
            z = D_L40_002926E0[k].pos.z;
            if (z < lo) {
                lo = z;
            } else if (hi < z) {
                hi = z;
            }
        }
        D_L40_002926E0[n].f14 = lo - 5.0f;
        D_L40_002926E0[n].f18 = hi + 5.0f;
        D_L40_002926E0[n].f10 += 2.0f;
    }
}
/* localdecomp:end func_L40_00490080 */
