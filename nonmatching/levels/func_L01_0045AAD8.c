/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_004577D0, the NTSC-U twin of func_L01_0045AAD8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 @ps2as" (src/levels/shared/L01_0045A6F0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0045A6F0 (src/levels/shared/L01_0045A6F0.c) */
#include "vu0.h"

/* localdecomp:start func_L01_004577D0 */
typedef struct {
    u8 p0[0x10];
    f32 x10;
    f32 y14;
    f32 z18;
    u8 p1C[0x8C];
    f32 yaw;      /* 0xA8? see below */
} Dummy_004577D0;

extern f32 D_001D7DD0_sda;
__asm__(".extern D_001D7DD0_sda, 4");
extern void func_L01_00445758(void *, f32, f32, f32, f32, void *, s32);
extern f32 func_00389468(f32, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388730(void *, void *);
extern void func_003BF640(void *, f32);
extern f32 func_00388770(void *);
extern f32 func_003887A0(void *);
extern void func_003BEE20(void *, f32, f32, f32, f32);

void func_L01_004577D0(u8 *self, u8 *d, f32 *tgt, f32 ang) {
    f32 v0[4];
    f32 v1[4];
    f32 gap;
    f32 a;
    f32 yw;
    f32 sp;
    f32 lim;
    f32 *pos;

    if ((*(u32 *)(d + 0x38) & 0x10) == 0) {
        func_L01_00445758(self + 0xF8, ang, *(f32 *)(d + 0x14), *(f32 *)(d + 0x18), *(f32 *)(d + 0x1C), d + 0xB4, 0);
    }
    gap = func_00389468(*(f32 *)(self + 0xF8), ang);
    if ((*(u32 *)(d + 0x38) & 0x10) == 0 && *(f32 *)(d + 0x30) < gap) {
        qzero(v0);
        if (*(f32 *)(d + 0xB4) * 30.0f < gap - *(f32 *)(d + 0x30)) {
            *(u32 *)(d + 0x9C) |= 2;
        }
    } else {
        *(s32 *)(d + 0x9C) &= -3;
        if (*(u32 *)(d + 0x38) & 0x400) {
            *(f32 *)(d + 0xCC) = func_003887C8(self + 0x10, tgt);
        } else {
            *(f32 *)(d + 0xCC) = func_00388800(self + 0x10, tgt);
        }
        if (*(f32 *)(d + 0xCC) <= *(f32 *)(d + 0x34)) {
            qzero(v0);
        } else {
            sp = sqrt_asm((*(f32 *)(d + 0xCC) - *(f32 *)(d + 0x34)) * 2.0f * *(f32 *)(d + 0x24));
            lim = *(f32 *)(d + 0x28);
            if (lim < sp) sp = lim;
            if (*(s32 *)(d + 0x80) != 0 && *(s16 *)(self + 0xAA) != 0x16BD) {
                a = func_00388A28(*(f32 *)(d + 0x60) - *(f32 *)(self + 0x10), *(f32 *)(d + 0x64) - *(f32 *)(self + 0x14));
                yw = func_00389380(a, 3.14159012f);
                ang = func_003893C8(ang, yw);
                if (D_001D7DD0_sda < ang) ang = D_001D7DD0_sda;
                else if (ang < -D_001D7DD0_sda) ang = -D_001D7DD0_sda;
                ang = func_00389380(ang, yw);
            }
            if (*(u32 *)(d + 0x38) & 0x400) {
                vec_sub_ab(v0, tgt, self + 0x10);
                func_00388830(v0, v0, sp);
            } else {
                v0[0] = func_00388960(ang) * sp;
                v0[1] = func_00388978(ang) * sp;
                *(s32 *)&v0[2] = 0;
            }
        }
    }
    vec_sub_ab(v1, v0, d + 0xA0);
    pos = (f32 *)(d + 0xA0);
    if ((*(u32 *)(d + 0x38) & 0x400) == 0) *(s32 *)&v1[2] = 0;
    if (func_00388730(v0, pos) > 0.0f) {
        func_003BF640(v1, *(f32 *)(d + 0x20));
    } else {
        func_003BF640(v1, *(f32 *)(d + 0x24));
    }
    vec_add_ab(d + 0xA0, d + 0xA0, v1);
    if (*(u32 *)(d + 0x38) & 0x400) {
        *(f32 *)(d + 0xB0) = func_00388770(pos);
    } else {
        *(f32 *)(d + 0xB0) = func_003887A0(pos);
    }
    if ((*(u32 *)(d + 0x38) & 4) == 0) {
        f32 h0 = *(f32 *)(d + 0x90);
        f32 h1 = *(f32 *)(self + 0x18);
        if (h0 < h1) {
            if (*(s16 *)(d + 0xC2) < 2) {
                if (h1 - h0 < 0.15f) {
                    u8 *w = d + 0x50;
                    a = func_00388A28(*(f32 *)(d + 0x58), func_003887A0(w));
                    if (0.08726646f < a) {
                        if (-func_00388730(pos, w) < *(f32 *)(d + 0xA8)) {
                            *(f32 *)(d + 0xA8) = -func_00388730(pos, w);
                        }
                    }
                }
            }
            *(f32 *)(d + 0xA8) = *(f32 *)(d + 0xA8) - *(f32 *)(d + 0x2C);
            if (*(s16 *)(d + 0xC0) == 0) {
                *(u32 *)(d + 0x94) |= 0x20;
            }
        } else {
            f32 e = h0 - h1;
            if (e < *(f32 *)(d + 0xA8)) *(f32 *)(d + 0xA8) = e;
            else if (*(f32 *)(d + 0xA8) < 0.0f) *(f32 *)(d + 0xA8) = 0.0f;
            func_003BEE20(d + 0xA8, *(f32 *)(d + 0x90) - *(f32 *)(self + 0x18), 0.011111111f, 0.011111111f, 1.0f);
        }
    }
}
/* localdecomp:end func_L01_004577D0 */
