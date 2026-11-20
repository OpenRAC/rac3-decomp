#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BE330.c, which this file was cut from */
extern s32 func_0038CB00(void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C3FC0(void *, void *);

/* declared by functions of L09_003BE450.c, which this file was cut from */
extern s32 func_0038CB00(void *);

/* localdecomp:start func_L09_003BE5D0 */
__asm__(".extern D_L09_001E009C, 16");
extern u8 *D_L09_001E009C;
extern f32 D_001A4CB0[];
extern u8 *D_001A71A0[];
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L09_003E7BC0(void *, void *, void *, void *, s32, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_0038CB00(void *);

void func_L09_003BE5D0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *m = D_L09_001E009C + *(s32 *)(p + 0xCD0) * 0x100;
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));

    if ((u32)(m[0x43] - 3) < 2) {
        if (func_L01_0044E1B8(m, 2.0f) != 0) {
            func_003C2F58(m, m[0x43] == 3 ? 7 : 11, a);
            func_003C2F58(m, m[0x43] == 3 ? 8 : 12, b);
            if (a4 != 0 && a0[0x20] == 7) {
                c[0] = func_0038D098(2.9670596f) * 0.56000006f;
                c[1] = func_0038D0B0(2.9670596f) * 0.56000006f;
                c[2] = 0.0f;
            } else if (a4 != 0 && a0[0x20] == 20) {
                f32 *o = c;
                f32 ang;
                f32 *t;
                ang = func_0038D160(b[0] - a[0], b[1] - a[1]);
                t = D_001A4CB0;
                func_00382760(o, 0.56000006f, ang, func_0038D160(func_0038CF38(b, t), t[2] - b[2]));
            } else if (a1 != 0 || a4 != 0) {
                vec_sub_ab(c, b, a);
                func_0038CF68(c, c, 0.56000006f);
            } else {
                f32 *o = c;
                f32 ang;
                f32 *t;
                ang = func_0038D160(b[0] - a[0], b[1] - a[1]);
                t = D_001A4CB0;
                func_00382760(o, 0.56000006f, ang, func_0038D160(func_0038CF38(b, t), t[2] - b[2]));
            }
            func_003A52A0(1, 0, m);
            func_L09_003E7BC0(a0, b, c, a4 != 0 ? 0 : D_001A71A0[0], p[0x45], a1, a2, a3);
        } else if (m[0x60] & 2) {
            func_003C3A10(m, 0, 0, 4);
        }
    } else if (func_0038CB00(p + 0xD36) != 0 || a3 != 0) {
        *(s16 *)(p + 0xD36) = 37;
        p[0xD2D]++;
        func_003C3A10(m, (p[0xD2D] & 1) ? 3 : 4, 0, 8);
    }
}
/* localdecomp:end func_L09_003BE5D0 */
