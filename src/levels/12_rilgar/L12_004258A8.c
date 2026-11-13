#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L12_004258A8 */
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(f32 *, f32);
extern s32 func_L01_003AEA58(s32, void *, void *, s32, f32);
extern s32 func_00382468(s32);
extern void func_L01_004AAC98(s32, s32, s32, s32);

void func_L12_004258A8(u8 *self, vu0_v4 *pa, vu0_v4 *pb, vu0_v4 *pc) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 t;
    s32 hit;
    vu0_v4 *qb;
    vu0_v4 *qc;

    a = *pa;
    b = *pb;
    c = *pc;
    qb = &b;
    qc = &c;
    r.x = func_003824E0(qb->x, qc->x);
    r.y = func_003824E0(qb->y, qc->y);
    r.z = func_003824E0(qb->z, qc->z);
    t = r;
    func_0038CF68(&t, &t, -0.6f);
    func_003C4C18((f32 *)&t, 0.3f);
    vec_add_ba(&p, self + 0x10, &r);
    vec_add_ab(&p, &p, &a);
    hit = func_L01_003AEA58(0, &t, &p, 0, 0.0f);
    if (hit != 0 && func_00382468(2) == 0) {
        func_L01_004AAC98(0, 0, hit, 0x1F7C);
    }
}
/* localdecomp:end func_L12_004258A8 */
