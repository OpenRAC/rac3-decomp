#include "common.h"

/* NTSC-U counterpart of func_L09_003BE5D0 (src/levels/09_tyhrranosis/L09_003BE5D0.c) */
#include "vu0.h"
extern s32 func_003883C8(void *);
extern s32 func_003883C8(void *);

/* localdecomp:start func_L09_003BCD58 */
__asm__(".extern D_L09_001E011C, 16");
extern u8 *D_L09_001E011C;
extern f32 D_001A4CB0[];
extern u8 *D_001A71A0[];
extern s32 func_L01_0044AF40(void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L09_003E5EE8(void *, void *, void *, void *, s32, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_003883C8(void *);

void func_L09_003BCD58(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *m = D_L09_001E011C + *(s32 *)(p + 0xCD0) * 0x100;
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));

    if ((u32)(m[0x43] - 3) < 2) {
        if (func_L01_0044AF40(m, 1.0f) != 0) {
            func_003BDA38(m, m[0x43] == 3 ? 7 : 11, a);
            func_003BDA38(m, m[0x43] == 3 ? 8 : 12, b);
            if (a4 != 0 && a0[0x20] == 7) {
                c[0] = func_00388960(2.9670596f) * 0.4666667f;
                c[1] = func_00388978(2.9670596f) * 0.4666667f;
                c[2] = 0.0f;
            } else if (a4 != 0 && a0[0x20] == 20) {
                f32 *o = c;
                f32 ang;
                f32 *t;
                ang = func_00388A28(b[0] - a[0], b[1] - a[1]);
                t = D_001A4CB0;
                func_0037E4B8(o, 0.4666667f, ang, func_00388A28(func_00388800(b, t), t[2] - b[2]));
            } else if (a1 != 0 || a4 != 0) {
                vec_sub_ab(c, b, a);
                func_00388830(c, c, 0.4666667f);
            } else {
                f32 *o = c;
                f32 ang;
                f32 *t;
                ang = func_00388A28(b[0] - a[0], b[1] - a[1]);
                t = D_001A4CB0;
                func_0037E4B8(o, 0.4666667f, ang, func_00388A28(func_00388800(b, t), t[2] - b[2]));
            }
            func_0039FE80(1, 0, m);
            func_L09_003E5EE8(a0, b, c, a4 != 0 ? 0 : D_001A71A0[0], p[0x45], a1, a2, a3);
        } else if (m[0x60] & 2) {
            func_003BE4F0(m, 0, 0, 5);
        }
    } else if (func_003883C8(p + 0xD36) != 0 || a3 != 0) {
        *(s16 *)(p + 0xD36) = 45;
        p[0xD2D]++;
        func_003BE4F0(m, (p[0xD2D] & 1) ? 3 : 4, 0, 10);
    }
}
/* localdecomp:end func_L09_003BCD58 */
