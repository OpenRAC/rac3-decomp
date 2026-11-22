#include "common.h"
#include "vu0.h"

/* declared by functions of L31_00346798.c, which this file was cut from */
extern s32 func_L31_00346838(void *, void *, vu0_v4 *, s32, f32, f32);

/* localdecomp:start func_L31_00346838 */
#include "vu0.h"

extern s32 func_L31_00346838(void *, void *, vu0_v4 *, s32, f32, f32);

typedef struct {
    u8 pad[0x18];
    s32 x18;
} G_001E9180;
__asm__(".extern D_L31_001DCFCC, 4");
__asm__(".extern D_L31_001DCFD0, 4");
extern f32 D_L31_001DCFCC;
extern f32 D_L31_001DCFD0;
extern G_001E9180 D_L31_001E9180;
extern vu0_v4 D_L31_001E91A0;
extern void func_0038CF68(void *, void *, f32);
extern int func_003D3CB0(void *, void *, int, void *, int);
extern s32 func_L30_003445B8(s32);
extern void func_L30_00343830(s32, void *, void *, f32);
extern f32 func_0038CF00(void *, void *);

s32 func_L31_00346838(void *a0, void *a1, vu0_v4 *dir, s32 force, f32 len, f32 h) {
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 *pos = a1;

    *(vu0_q *)&p = *(vu0_q *)pos;
    p.z += h;
    func_0038CF68(&d, dir, len + D_L31_001DCFCC);
    vec_add_ab(&q, &p, &d);
    if (func_003D3CB0(&p, &q, 2, a0, 0)) {
        if (D_L31_001E9180.x18 != 0 && func_L30_003445B8(D_L31_001E9180.x18)) {
            func_L30_00343830(D_L31_001E9180.x18, &r, &p, len + D_L31_001DCFD0);
        }
        if (func_0038CF00(&p, &D_L31_001E91A0) < len || force != 0) {
            vec_sub_ab(&d, &p, &D_L31_001E91A0);
            func_0038CF68(&d, &d, len);
            vec_add_ba(&p, &D_L31_001E91A0, &d);
            *(vu0_q *)pos = *(vu0_q *)&p;
            pos->z -= h;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L31_00346838 */
