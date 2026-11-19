/* functional: medium. Sequence read line by line; medium because the helper semantics (cos/sin/angle step) are inferred from their callers rather than read. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0036BF28 */
typedef struct {
    f32 x0, y4, z8, w0C;
    f32 x10, y14, z18, w1C;
    vu0_v4 q20;
    vu0_v4 q30;
    vu0_v4 q40;
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94;
    s32 w98;
    s32 w9C;
    s32 wA0;
    s32 wA4;
    s32 wA8;
    s32 pAC;
} P_0036BF28;
extern P_0036BF28 D_L05_0028DE00[];
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_0038CAD0(void *);

void func_L05_0036BF28(u8 *owner) {
    s32 i;
    P_0036BF28 *p;
    vu0_v4 d;
    f32 k;

    for (i = 0; i < 16; i++) {
        p = &D_L05_0028DE00[i];
        if (p->w9C != (s32)owner) {
            continue;
        }
        p->q20.x += func_003824E0(-0.1f, 0.1f);
        p->q20.y += func_003824E0(-0.1f, 0.1f);
        p->q20.z += func_003824E0(-0.1f, 0.1f);
        vec_sub_ba(&d, &p->q40, &p->q20);
        *(vu0_q *)&p->q20 = *(vu0_q *)(owner + 0x10);
        vec_add_ba(&p->q40, &p->q20, &d);
        if (p->wA0 != 0) {
            k = 100.0f;
        } else {
            k = 50.0f;
        }
        p->f50 = func_0038DAB8(p->f50, p->f5C * k);
        p->f54 = func_0038DAB8(p->f54, p->f60 * k);
        p->f58 = func_0038DAB8(p->f58, p->f64 * k);
        p->f74 = func_0038DAB8(p->f74, p->f80 * k);
        p->f78 = func_0038DAB8(p->f78, p->f84 * k);
        p->f7C = func_0038DAB8(p->f7C, p->f88 * k);
        p->x0 = func_0038D098(p->f50) * p->f68;
        p->y4 = func_0038D0B0(p->f54) * p->f6C;
        p->z8 = -func_0038D0B0(p->f58) * p->f70;
        p->x10 = func_0038D098(p->f74) * p->f8C;
        p->y14 = func_0038D0B0(p->f78) * p->f90;
        p->z18 = -func_0038D0B0(p->f7C) * p->f94;
        func_0038CDF8(&p->q30, &p->q20, &p->q40, 1.0f - (f32)p->wA0 / (f32)p->wA4);
        if (func_0038CAD0(&p->wA0) == 0) {
            continue;
        }
        if (p->wA8 == 0) {
            p->wA8 = 1;
        }
        if (func_0038CAD0(&p->w98) != 0) {
            p->w9C = 0;
        }
    }
}
/* localdecomp:end func_L05_0036BF28 */
