#include "common.h"

/* NTSC-U counterpart of func_L08_003A81F0 (src/levels/shared/L08_003A8090.c) */
extern u8 D_001A4C60[];
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern s32 func_L01_00452F60(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L08_003A63F8 */
#include "vu0.h"

extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00442AA8(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern s32 func_L01_00452F60(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern u8 D_001A4C60[];

void func_L08_003A63F8(u8 *o) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;

    if (o[0x20] == 0) {
        if (o[0x21] != 0xFF) {
            if (o[0xBC] != 0) {
                if (o[0xBC] != 2) {
                    func_0039FE80(0, 0, o);
                    func_L01_00442AA8(o[0x21], 2);
                }
                func_L01_00441FB8(o, 1, -1);
                func_L01_00452F40(o, 1);
            } else if (func_L01_00452F60(o) != 0) {
                func_L01_00441FB8(o, 1, -1);
            }
        } else if (func_00388800(o + 0x10, D_001A4C60) < 7.0f) {
            func_0039FE80(0, 0, o);
            func_L01_00441FB8(o, 1, -1);
            func_L01_00452F40(o, 1);
        }
    }
    if (o[0x20] == 1) {
        (*(u16 *)(o + 0x96))++;
        func_00388830(&a, o + 0xE0, 0.058333337f);
        func_00388830(&b, o + 0xC0, -0.058333337f);
        __asm__ __volatile__(
            "lqc2 $vf1, %2\n"
            "lqc2 $vf2, %0\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "lqc2 $vf1, %3\n"
            "sqc2 $vf1, %1\n"
            "sqc2 $vf2, %0\n"
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(*(vu0_v4 *)(o + 0x10)), "+m"(c)
            : "m"(a), "m"(b));
        if (*(u16 *)(o + 0x96) >= 0x1F) {
            func_L01_00441FB8(o, 2, -1);
        }
    }
}
/* localdecomp:end func_L08_003A63F8 */
