#include "common.h"

/* NTSC-U counterpart of func_L40_0040B058 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"

/* The Siege Ranger (Galactic Ranger), legs class 0x109F with its torso 0x109E: moby update,
   network create / think / update callbacks and its walking and fighting. A moby's pVar is at
   +0x68. */

/* The front end's vector helpers */
extern f32 func_00388770(void *v);                 /* length of a vector */
extern f32 func_00388A28(f32 x, f32 y);            /* the angle of (x, y) */

extern s32 D_001A5F78[];

/* localdecomp:start func_L40_0040A9A0 */
__asm__(".extern D_L40_002473D0, 4");
extern f32 D_L40_002473D0;
extern s32 D_001A5F78[];
extern void func_003886E8(void *d, void *s, f32 k);
extern void func_L40_0040C828(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L40_0040CC28(u8 *m, void *target, s32 mode, f32 yaw);

void func_L40_0040A9A0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 d;
    s32 n;
    f32 len;

    vec_sub_ba(&d, v + 0x300, m + 0x10);
    n = (s32)((*(s32 *)(v + 0x2C4) + (s32)D_L40_002473D0 - D_001A5F78[0]) * 0.06f);
    if (n < 0) {
        n = 0;
    }
    func_003886E8(v + 0x110, &d, 1.0f / (n + 1));
    len = func_00388770(v + 0x110);
    if (len > 0.0f) {
        func_L40_0040C828(m, 10, 0, 0x14);
        *(f32 *)(*(u8 **)(v + 0x270) + 0xF8) = *(f32 *)(m + 0xF8);
    }
    if (len == 0.0f) {
        *(s32 *)(v + 0x25C) -= 1;
    } else {
        func_L40_0040CC28(m, v + 0x300, 0, func_00388A28(*(f32 *)(v + 0x300) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x304) - *(f32 *)(m + 0x14)));
        *(s32 *)(v + 0x25C) -= 1;
    }
}
/* localdecomp:end func_L40_0040A9A0 */
