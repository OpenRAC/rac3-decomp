#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0045C510 */
extern void func_L01_0045CC18(void *, void *, s32, s32);
extern f32 func_L01_00451738(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_00451020(void *, void *, f32);
extern void func_L01_004510A8(void *, void *, void *, f32, s32);
extern f32 func_0038CE68(void *, void *);
extern void func_003C4BB0(void *, f32);
extern f32 func_L01_004510F8(void *, void *, s32);
extern f32 func_L01_00451580(void *);
extern void func_L01_00451388(void *, void *, void *, f32);
extern f32 func_003C50E8(void *, void *, s32);
extern void func_003C4360(f32 *, f32, f32, f32, f32);

void func_L01_0045C510(u8 *self, u8 *p, void *tgt, s32 a3, s32 t0, s32 t1, s32 t2) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 h;
    f32 f1;
    f32 lo;
    f32 d;
    f32 r;
    f32 lim;
    f32 top;

    if ((*(s32 *)(p + 0x38) & 0x10) == 0) {
        func_L01_0045CC18(self, p, a3, t2);
    }
    lo = 0.0f;
    if ((*(s32 *)(p + 0x38) & 0x10) == 0) {
        lo = func_L01_00451738(self, a3, t2);
    }
    if (*(f32 *)(p + 0x30) < lo) {
        qzero(v0);
    } else {
        d = func_0038CF00(self + 0x10, tgt);
        *(f32 *)(p + 0xCC) = d;
        lim = *(f32 *)(p + 0x34);
        if (d <= lim) {
            qzero(v0);
        } else {
            top = *(f32 *)(p + 0x28);
            r = sqrt_asm((d - lim + (d - lim)) * *(f32 *)(p + 0x24));
            if (top < r) {
                r = top;
            }
            func_L01_00451020(self, v0, r);
        }
    }
    vec_sub_ab(v10, v0, p + 0xA0);
    func_L01_004510A8(self, v10, v10, 0.0f, t2);
    if (0.0f < func_0038CE68(v0, p + 0xA0)) {
        func_003C4BB0(v10, *(f32 *)(p + 0x20));
    } else {
        func_003C4BB0(v10, *(f32 *)(p + 0x24));
    }
    vec_add_ab(p + 0xA0, p + 0xA0, v10);
    *(f32 *)(p + 0xB0) = func_L01_004510F8(self, p + 0xA0, t2);
    if ((*(s32 *)(p + 0x38) & 4) == 0) {
        f1 = func_L01_00451580(self + 0x10);
        if (*(f32 *)(p + 0x90) < f1) {
            func_L01_00451388(self, p + 0xA0, p + 0xA0, *(f32 *)(p + 0x2C));
            if (*(s16 *)(p + 0xC0) == 0) {
                *(s32 *)(p + 0x94) |= 0x20;
            }
        } else {
            h = func_003C50E8(self, p + 0xA0, t2);
            if (*(f32 *)(p + 0x90) - f1 < h) {
                h = *(f32 *)(p + 0x90) - f1;
            } else if (h < 0.0f) {
                h = 0.0f;
            }
            func_003C4360(&h, *(f32 *)(p + 0x90) - f1, 0.016f, 0.016f, 1.0f);
            func_L01_004510A8(self, p + 0xA0, p + 0xA0, h, t2);
        }
    }
}
/* localdecomp:end func_L01_0045C510 */

INCLUDE_ASM("asm/levels", func_L01_0045C7A8);
