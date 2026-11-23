/* functional: medium. Near-miss draft (compiles under file flags); 77 diff words; constants and callee set cross-checked; description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034D2F0 */
#include "vu0.h"
extern Entry_0034CC80 D_L01_0027FB20[];
void func_L01_0034D2F0(u8 *owner) {
    extern u8 *func_00382348(void *);
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034E080(void *, s32, s32);
    vu0_v4 delta;
    vu0_q damage[3];
    vu0_v4 first, second, temporary;
    s32 i;
    for (i = 0; i < 48; i++) {
        u8 *p = (u8 *)&D_L01_0027FB20[i];
        u8 *info;
        if (*(u8 **)(p + 0xAC) != owner) continue;
        *(vu0_q *)(p + 0x20) = *(vu0_q *)(p + 0x40);
        if (*(u8 **)(p + 0xB4)) {
            info = func_00382348(*(u8 **)(p + 0xB4));
            if (info) {
                func_003C5180(*(u8 **)(p + 0xB4) + 0x10, (f32 *)&delta, 1);
                func_0038CE20((f32 *)&delta, (f32 *)&delta, *(f32 *)(info + 0x10));
                __asm__(
                    "lqc2 $vf1, %0\n\t"
                    "sqc2 $vf1, %1\n\t"
                    "lqc2 $vf2, %4\n\t"
                    "lqc2 $vf1, %5\n\t"
                    "sqc2 $vf2, %2\n\t"
                    "lqc2 $vf2, %1\n\t"
                    "vadd.xyz $vf1, $vf2, $vf1\n\t"
                    "sqc2 $vf1, %0\n\t"
                    "lqc2 $vf1, %0\n\t"
                    "lqc2 $vf2, %2\n\t"
                    "vadd.xyz $vf1, $vf1, $vf2\n\t"
                    "sqc2 $vf1, %3"
                    : "+m"(delta), "=m"(temporary), "=m"(first), "=m"(*(vu0_v4 *)(p + 0x20))
                    : "m"(*(vu0_v4 *)(p + 0x20)), "m"(*(vu0_v4 *)(*(u8 **)(p + 0xB4) + 0x10))
                    : "vf1", "vf2");
            } else {
                *(vu0_q *)(p + 0x20) = *(vu0_q *)(*(u8 **)(p + 0xB4) + 0x10);
            }
        }
        if (*(s32 *)(p + 0xB8)) {
            *(f32 *)(p + 0x60) = func_0038DAB8(*(f32 *)(p + 0x60), *(f32 *)(p + 0x6C) * 100.0f);
            *(f32 *)(p + 0x64) = func_0038DAB8(*(f32 *)(p + 0x64), *(f32 *)(p + 0x70) * 100.0f);
            *(f32 *)(p + 0x68) = func_0038DAB8(*(f32 *)(p + 0x68), *(f32 *)(p + 0x74) * 100.0f);
            *(f32 *)(p + 0x84) = func_0038DAB8(*(f32 *)(p + 0x84), *(f32 *)(p + 0x90) * 100.0f);
            *(f32 *)(p + 0x88) = func_0038DAB8(*(f32 *)(p + 0x88), *(f32 *)(p + 0x94) * 100.0f);
            *(f32 *)(p + 0x8C) = func_0038DAB8(*(f32 *)(p + 0x8C), *(f32 *)(p + 0x98) * 100.0f);
        } else {
            *(f32 *)(p + 0x60) = func_0038DAB8(*(f32 *)(p + 0x60), *(f32 *)(p + 0x6C));
            *(f32 *)(p + 0x64) = func_0038DAB8(*(f32 *)(p + 0x64), *(f32 *)(p + 0x70));
            *(f32 *)(p + 0x68) = func_0038DAB8(*(f32 *)(p + 0x68), *(f32 *)(p + 0x74));
            *(f32 *)(p + 0x84) = func_0038DAB8(*(f32 *)(p + 0x84), *(f32 *)(p + 0x90));
            *(f32 *)(p + 0x88) = func_0038DAB8(*(f32 *)(p + 0x88), *(f32 *)(p + 0x94));
            *(f32 *)(p + 0x8C) = func_0038DAB8(*(f32 *)(p + 0x8C), *(f32 *)(p + 0x98));
        }
        *(f32 *)(p + 0) = func_0038D098(*(f32 *)(p + 0x60)) * *(f32 *)(p + 0x78);
        *(f32 *)(p + 4) = func_0038D0B0(*(f32 *)(p + 0x64)) * *(f32 *)(p + 0x7C);
        *(f32 *)(p + 8) = -func_0038D0B0(*(f32 *)(p + 0x68)) * *(f32 *)(p + 0x80);
        *(f32 *)(p + 0x10) = func_0038D098(*(f32 *)(p + 0x84)) * *(f32 *)(p + 0x9C);
        *(f32 *)(p + 0x14) = func_0038D0B0(*(f32 *)(p + 0x88)) * *(f32 *)(p + 0xA0);
        *(f32 *)(p + 0x18) = -func_0038D0B0(*(f32 *)(p + 0x8C)) * *(f32 *)(p + 0xA4);
        *(vu0_q *)(p + 0x30) = *(vu0_q *)(p + 0x50);
        if (*(u8 **)(p + 0xB0)) {
            info = func_00382348(*(u8 **)(p + 0xB0));
            if (info) {
                func_003C5180(*(u8 **)(p + 0xB0) + 0x10, (f32 *)&delta, 1);
                func_0038CE20((f32 *)&delta, (f32 *)&delta, *(f32 *)(info + 0x10));
                __asm__(
                    "lqc2 $vf1, %0\n\t"
                    "sqc2 $vf1, %1\n\t"
                    "lqc2 $vf2, %4\n\t"
                    "lqc2 $vf1, %5\n\t"
                    "sqc2 $vf2, %2\n\t"
                    "lqc2 $vf2, %1\n\t"
                    "vadd.xyz $vf1, $vf2, $vf1\n\t"
                    "sqc2 $vf1, %0\n\t"
                    "lqc2 $vf1, %0\n\t"
                    "lqc2 $vf2, %2\n\t"
                    "vadd.xyz $vf1, $vf1, $vf2\n\t"
                    "sqc2 $vf1, %3"
                    : "+m"(delta), "=m"(temporary), "=m"(second), "=m"(*(vu0_v4 *)(p + 0x30))
                    : "m"(*(vu0_v4 *)(p + 0x30)), "m"(*(vu0_v4 *)(*(u8 **)(p + 0xB0) + 0x10))
                    : "vf1", "vf2");
            } else {
                *(vu0_q *)(p + 0x30) = *(vu0_q *)(*(u8 **)(p + 0xB0) + 0x10);
            }
        }
        func_0038CDF8(p + 0x30, p + 0x20, p + 0x30, 1.0f - (f32)*(s32 *)(p + 0xB8) / (f32)*(s32 *)(p + 0xBC));
        if (func_0038CAD0(p + 0xB8)) {
            if (*(s32 *)(*(u8 **)(p + 0xB0) + 0x98) && !*(s32 *)(p + 0xC0) && *(s32 *)(p + 0xC4)) {
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                    : "=m"(delta) : "m"(*(vu0_v4 *)(p + 0x20)), "m"(*(vu0_v4 *)(p + 0x30)) : "vf1", "vf2");
                func_0038CF68(&delta, &delta, 0.0400000028f);
                *(s32 *)(owner + 0xB8) = *(s32 *)(*(u8 **)(p + 0xCC) + 0x20);
                func_L01_00446760(damage, owner, 0x410000, &delta, *(f32 *)(p + 0xC8));
                ((u8 *)damage)[0x18] = 5;
                ((u8 *)damage)[0x19] = 3;
                *(u16 *)((u8 *)damage + 0x1A) = *(u16 *)(owner + 0xAA);
                func_L01_00446978(*(u8 **)(p + 0xB0), damage);
                *(s32 *)(p + 0xC0) = 1;
                func_L01_0034E080(p + 0x30, 10, 1);
            }
            if (func_0038CAD0(p + 0xA8)) *(s32 *)(p + 0xAC) = 0;
        }
    }
}
/* localdecomp:end func_L01_0034D2F0 */
