/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00459208, the NTSC-U twin of func_L01_0045C510, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0045A6F0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0045C510 (src/levels/shared/L01_0045C510.c) */
/* localdecomp:start func_L01_00459208 */
extern void func_L01_00459910(void *, void *, s32, s32);
extern f32 func_L01_0044E4B8(void *, s32, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L01_0044DDA0(void *, void *, f32);
extern void func_L01_0044DE28(void *, void *, void *, f32, s32);
extern f32 func_00388730(void *, void *);
extern void func_003BF640(void *, f32);
extern f32 func_L01_0044DE78(void *, void *, s32);
extern f32 func_L01_0044E300(void *);
extern void func_L01_0044E108(void *, void *, void *, f32);
extern f32 func_003BFB80(void *, void *, s32);
extern void func_003BEE20(f32 *, f32, f32, f32, f32);

void func_L01_00459208(u8 *self, u8 *p, void *tgt, s32 a3, s32 t0, s32 t1, s32 t2) {
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
        func_L01_00459910(self, p, a3, t2);
    }
    lo = 0.0f;
    if ((*(s32 *)(p + 0x38) & 0x10) == 0) {
        lo = func_L01_0044E4B8(self, a3, t2);
    }
    if (*(f32 *)(p + 0x30) < lo) {
        qzero(v0);
    } else {
        d = func_003887C8(self + 0x10, tgt);
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
            func_L01_0044DDA0(self, v0, r);
        }
    }
    vec_sub_ab(v10, v0, p + 0xA0);
    func_L01_0044DE28(self, v10, v10, 0.0f, t2);
    if (0.0f < func_00388730(v0, p + 0xA0)) {
        func_003BF640(v10, *(f32 *)(p + 0x20));
    } else {
        func_003BF640(v10, *(f32 *)(p + 0x24));
    }
    vec_add_ab(p + 0xA0, p + 0xA0, v10);
    *(f32 *)(p + 0xB0) = func_L01_0044DE78(self, p + 0xA0, t2);
    if ((*(s32 *)(p + 0x38) & 4) == 0) {
        f1 = func_L01_0044E300(self + 0x10);
        if (*(f32 *)(p + 0x90) < f1) {
            func_L01_0044E108(self, p + 0xA0, p + 0xA0, *(f32 *)(p + 0x2C));
            if (*(s16 *)(p + 0xC0) == 0) {
                *(s32 *)(p + 0x94) |= 0x20;
            }
        } else {
            h = func_003BFB80(self, p + 0xA0, t2);
            if (*(f32 *)(p + 0x90) - f1 < h) {
                h = *(f32 *)(p + 0x90) - f1;
            } else if (h < 0.0f) {
                h = 0.0f;
            }
            func_003BEE20(&h, *(f32 *)(p + 0x90) - f1, 0.011111111f, 0.011111111f, 1.0f);
            func_L01_0044DE28(self, p + 0xA0, p + 0xA0, h, t2);
        }
    }
}
/* localdecomp:end func_L01_00459208 */
