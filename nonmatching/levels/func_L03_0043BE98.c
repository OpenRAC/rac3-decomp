/* NTSC-U draft (2026-11-14, Codex worker): C of func_L03_00438870, the NTSC-U twin of func_L03_0043BE98, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L03_0043BE98.c's current line.
 * Worker's note: 191 diff; best log func_L03_00438870.02.log; allowed GNU assembler puts 0.01f in lit4 where retail has inline lui/ori/mtc1; no flags_alt. Additional bit-test/register/scheduling differences. VU0 sequence compiles with vf1/vf2 clobbers.
 */
#include "common.h"
#include "vu0.h"
#include "structs/hero.h"

/* localdecomp:start func_L03_00438870 */
extern u8 D_L03_001D66B0[];
extern struct Hero D_001A4BE0;
extern u8 D_001D5471[];
extern s32 func_L03_003F8F68(void *, void *, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388770(void *);
extern s32 func_00388398(void *);
extern f32 func_0037E250(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L03_00438870(u8 *m, u8 *s, s32 a2, s32 a3, s32 a4) {
    vu0_v4 delta, target, pos;
    f32 yaw, pitch;
    f32 rate1 = *(f32 *)(s + 0x120);
    f32 rate2 = *(f32 *)(s + 0x124);
    *(s32 *)(s + 0x12C) = a4;
    if (!func_L03_003F8F68(D_L03_001D66B0, s, 16)) {
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(delta) : "m"(*(vu0_v4 *)s), "m"(*(vu0_v4 *)(m + 0x10)) : "vf1", "vf2");
        yaw = func_003893C8(func_00388A28(delta.x, delta.y), *(f32 *)(m + 0xF8));
        pitch = -func_00388A28(func_003887A0(&delta), delta.z);
    } else {
        if ((*(u8 *)(s + 0x14C) & 1) == 0 &&
            func_00388800(m + 0x10, &D_001A4BE0.pos) < *(f32 *)(s + 0x144) &&
            func_00389468(*(f32 *)(m + 0xF8), func_00388A28(D_001A4BE0.pickup_point.x - *(f32 *)(m + 0x10), D_001A4BE0.pickup_point.y - *(f32 *)(m + 0x14))) < *(f32 *)(s + 0x140)) {
            if (func_00388770(&D_001A4BE0.vel) > 0.01f)
                *(s32 *)(s + 0x15C) = *(s32 *)(s + 0x148);
            else
                func_00388398(s + 0x15C);
        } else if (*(s32 *)(s + 0x15C)) {
            *(s32 *)(s + 0x15C) = 0;
            target = *(vu0_v4 *)&D_001A4BE0.pickup_point;
        }
        if (func_00388398(s + 0x158)) {
            *(s32 *)(s + 0x158) = (s32)func_0037E250((f32)*(s32 *)(s + 0x150), (f32)*(s32 *)(s + 0x154));
            *(f32 *)(s + 0x164) = func_0037E250(*(f32 *)(s + 0x118), *(f32 *)(s + 0x11C));
            *(f32 *)(s + 0x160) = func_0037E250(*(f32 *)(s + 0x110), *(f32 *)(s + 0x114));
        }
        if (*(s32 *)(s + 0x15C) && (*(u8 *)(s + 0x14C) & 1) == 0) {
            target = *(vu0_v4 *)&D_001A4BE0.pickup_point;
            pos = *(vu0_v4 *)(m + 0x10);
            target.z += D_001A4BE0.pickup_point.z - D_001A4BE0.pos.z;
            pos.z += *(f32 *)(s + 0x128);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(delta) : "m"(target), "m"(pos) : "vf1", "vf2");
            yaw = func_003893C8(func_00388A28(delta.x, delta.y), *(f32 *)(m + 0xF8));
            pitch = -func_00388A28(func_003887A0(&delta), delta.z);
            *(f32 *)(s + 0x164) = yaw;
            *(f32 *)(s + 0x160) = pitch;
            rate2 *= 3.0f;
            rate1 *= 3.0f;
        } else {
            yaw = *(f32 *)(s + 0x164);
            pitch = *(f32 *)(s + 0x160);
            if ((*(s32 *)(s + 0x14C) & 2) == 0) yaw = pitch = 0.0f;
        }
    }
    if (yaw > *(f32 *)(s + 0x11C)) yaw = *(f32 *)(s + 0x11C);
    else if (yaw < *(f32 *)(s + 0x118)) yaw = *(f32 *)(s + 0x118);
    if (pitch > -*(f32 *)(s + 0x110)) pitch = -*(f32 *)(s + 0x110);
    else if (pitch < -*(f32 *)(s + 0x114)) pitch = -*(f32 *)(s + 0x114);
    if (*(s32 *)(s + 0x12C)) {
        f32 x = yaw * *(f32 *)(s + 0x138);
        if (*(u16 *)(m + 0x34) & 0x8000) x = -x;
        *(f32 *)(s + 0x78) = x;
        x = yaw * *(f32 *)(s + 0x13C);
        if (*(u16 *)(m + 0x34) & 0x8000) x = -x;
        *(f32 *)(s + 0xF8) = x;
        *(f32 *)(s + 0xF4) = pitch * *(f32 *)(s + 0x13C);
        *(f32 *)(s + 0x74) = pitch * *(f32 *)(s + 0x138);
    }
    if (D_001D5471[0]) *(f32 *)(s + 0x80) = 2.75f;
    func_L01_0044B5C8(m, s + 0x10, a2, rate1, rate2);
    func_L01_0044B5C8(m, s + 0x90, a3, rate1, rate2);
    qzero(s);
}
/* localdecomp:end func_L03_00438870 */
