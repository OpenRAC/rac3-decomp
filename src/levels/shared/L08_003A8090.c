#include "common.h"

/* localdecomp:start func_L08_003A8090 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003A8090;

extern u8 D_001A4C60[];
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L08_003A8090(u8 *o) {
    V4_003A8090 a;
    V4_003A8090 b;
    V4_003A8090 c;

    if (o[0x20] == 0) {
        if (o[0x21] != 0xFF) {
            if (o[0xBC] != 0) {
                func_L01_004450F0(o, 1, -1);
                func_L01_00456230(o, 1);
            } else if (func_L01_00456250(o) != 0) {
                func_L01_004450F0(o, 1, -1);
            }
        } else if (func_0038CF38(o + 0x10, D_001A4C60) < 7.0f) {
            func_L01_004450F0(o, 1, -1);
            func_L01_00456230(o, 1);
        }
    }
    if (o[0x20] == 1) {
        (*(u16 *)(o + 0x96))++;
        func_0038CF68(&a, o + 0xE0, 0.070000008f);
        func_0038CF68(&b, o + 0xC0, -0.070000008f);
        __asm__ __volatile__(
            "lqc2 $vf1, %2\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "lqc2 $vf1, %3\n"
            "sqc2 $vf1, %0\n"
            "sqc2 $vf2, %1\n"
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %0\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %1\n"
            : "=m"(c), "+m"(*(V4_003A8090 *)(o + 0x10))
            : "m"(a), "m"(b)
            : "memory");
        if (*(u16 *)(o + 0x96) >= 31) {
            func_L01_004450F0(o, 2, -1);
        }
    }
}
/* localdecomp:end func_L08_003A8090 */

/* localdecomp:start func_L08_003A81F0 */
#include "vu0.h"

extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00445BE0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_001A4C60[];

void func_L08_003A81F0(u8 *o) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;

    if (o[0x20] == 0) {
        if (o[0x21] != 0xFF) {
            if (o[0xBC] != 0) {
                if (o[0xBC] != 2) {
                    func_003A52A0(0, 0, o);
                    func_L01_00445BE0(o[0x21], 2);
                }
                func_L01_004450F0(o, 1, -1);
                func_L01_00456230(o, 1);
            } else if (func_L01_00456250(o) != 0) {
                func_L01_004450F0(o, 1, -1);
            }
        } else if (func_0038CF38(o + 0x10, D_001A4C60) < 7.0f) {
            func_003A52A0(0, 0, o);
            func_L01_004450F0(o, 1, -1);
            func_L01_00456230(o, 1);
        }
    }
    if (o[0x20] == 1) {
        (*(u16 *)(o + 0x96))++;
        func_0038CF68(&a, o + 0xE0, 0.0700000077f);
        func_0038CF68(&b, o + 0xC0, -0.0700000077f);
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
            func_L01_004450F0(o, 2, -1);
        }
    }
}
/* localdecomp:end func_L08_003A81F0 */

INCLUDE_ASM("asm/levels", func_L08_003A8388);
