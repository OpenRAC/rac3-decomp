#include "common.h"

/* localdecomp:start func_L04_003D10D0 */
void func_L04_003D10D0(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 104);
    u8 *d = *(u8 **)(a0 + 104);
    *(s32 *)(d + 128) = *(s32 *)(s + 0);
    if (*(f32 *)(s + 4) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 4);
    }
    *(s32 *)(d + 136) = *(s32 *)(s + 8);
    if (*(f32 *)(s + 12) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 12);
    }
    *(s32 *)(d + 144) = *(s32 *)(s + 88);
    *(s32 *)(d + 152) = *(s32 *)(s + 32);
}
/* localdecomp:end func_L04_003D10D0 */

/* localdecomp:start func_L04_003D1128 */
typedef void (*Fn_003CF2A0)(u8 *);

extern u8 D_001A30B0[];
extern void func_003C2880(s32);
extern void func_003A4F28(s32);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);

void func_L04_003D1128(u8 *self) {
    u8 *v = *(u8 **)(self + 104);
    s32 idx;
    u8 *e;

    if (*(s32 *)(v + 156) != 0) {
        func_003C2880(*(s32 *)(v + 156));
        *(s32 *)(v + 156) = 0;
    }
    if (*(s32 *)(v + 160) != 0) {
        func_003C2880(*(s32 *)(v + 160));
        *(s32 *)(v + 160) = 0;
    }
    idx = *(s32 *)(v + 164);
    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 220) == self && e[208] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 164) = -1;
    (*func_L01_0043B548(6625, 108))(self);
}
/* localdecomp:end func_L04_003D1128 */

/* localdecomp:start func_L04_003D11E0 */
int func_L04_003D11E0(u8 *a) {
    int r = 3;
    if (a[32] != 2) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L04_003D11E0 */

/* localdecomp:start func_L04_003D11F8 */
#include "vu0.h"

extern f32 func_00382538(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L04_003D11F8(vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[10][4] __attribute__((aligned(16)));
    s32 i;

    vec_sub_ab(&step, b, a);
    func_0038CE20(&step, &step, 0.111111112f);
    cur = *a;
    for (i = 0; i < 10; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 9) {
            func_003C4C18(pts[i], 0.3f);
        }
        pts[i][3] = 0.075f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.075f, 4.0f, 0.0f, 0x17, 0x17, 0xB, -1, 0x80802020, 0);
    func_003D9508(a, 0x31, -1, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(a, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
    func_003D9508(b, 0x31, -1, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(b, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
}
/* localdecomp:end func_L04_003D11F8 */

/* localdecomp:start func_L04_003D1420 */
#include "vu0.h"

typedef struct O_3D1420_003D1420 O_3D1420_003D1420;
typedef struct {
    u8 pad0[0x90];
    s32 i90;
    O_3D1420_003D1420 *p94;
} M_3D1420_003D1420;
struct O_3D1420_003D1420 {
    u8 pad0[0x10];
    vu0_q q10;
    u8 pad20[0x68 - 0x20];
    M_3D1420_003D1420 *p68;
    u8 pad6C[0x90 - 0x6C];
    s32 i90;
    u8 pad94[0xD0 - 0x94];
    vu0_q qD0;
    vu0_q qE0;
};
extern f32 D_L04_001DEB30_003D1420; __asm__(".extern D_L04_001DEB30_003D1420, 4");
extern f32 D_L04_001DEB34_003D1420; __asm__(".extern D_L04_001DEB34_003D1420, 4");
extern void func_0038CE20(void *, void *, f32);
extern void func_L04_003D11F8_003D1420(vu0_q *, vu0_q *);

void func_L04_003D1420(O_3D1420_003D1420 *o) {
    vu0_q a[2];
    vu0_q t;
    vu0_q u;
    vu0_q qa, qb;
    M_3D1420_003D1420 *m;
    O_3D1420_003D1420 *other;

    m = o->p68;
    other = m->p94;
    if (m->i90 < 0) {
        a[0] = o->q10;
    } else {
        func_0038CE20(&a[0], &o->qE0, D_L04_001DEB30_003D1420);
        func_0038CE20(&t, &o->qD0, D_L04_001DEB34_003D1420);
        __asm__("lqc2 %0, %4\n"
                "\tlqc2 %1, %5\n"
                "\tvadd.xyz %1, %1, %0\n"
                "\tlqc2 %0, %6\n"
                "\tsqc2 %0, %3\n"
                "\tsqc2 %1, %2"
                : "=&j"(qa), "=&j"(qb), "=m"(a[0]), "=m"(u)
                : "m"(a[0]), "m"(t), "m"(o->q10));
        vec_add_ab(&a[0], &a[0], &u);
    }
    if (other->i90 < 0) {
        a[1] = m->p94->q10;
    } else {
        func_0038CE20(&a[1], &m->p94->qE0, D_L04_001DEB30_003D1420);
        func_0038CE20(&t, &m->p94->qD0, -D_L04_001DEB34_003D1420);
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(a[1]));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(a[1]) : "j"(qa));
        vec_add_ab(&a[1], &a[1], &m->p94->q10);
    }
    func_L04_003D11F8_003D1420(&a[0], &a[1]);
}
/* localdecomp:end func_L04_003D1420 */

/* localdecomp:start func_L04_003D1530 */
__asm__(".extern D_L04_001DEBC0, 4");
extern s32 D_L04_001DEBC0;
s32 *func_L04_003D1530(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 1) {
        *a2 = 28;
        return &D_L04_001DEBC0;
    }
    return 0;
}
/* localdecomp:end func_L04_003D1530 */

INCLUDE_ASM("asm/levels", func_L04_003D1550);
