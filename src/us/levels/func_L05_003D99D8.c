#include "common.h"

/* NTSC-U counterpart of func_L05_003DBE18 (src/levels/05_daxx/L05_003DBE18.c) */
#include "vu0.h"

/* localdecomp:start func_L05_003D99D8 */
typedef int u128_t_3DBE18 __attribute__((mode(TI)));
extern f32 D_L05_001DF1A8;
__asm__(".extern D_L05_001DF1A8, 4");
extern f32 D_L05_001DF1AC;
__asm__(".extern D_L05_001DF1AC, 4");
extern s32 D_L05_001DF1A0;
__asm__(".extern D_L05_001DF1A0, 4");
extern s32 D_L05_001DF1A4;
__asm__(".extern D_L05_001DF1A4, 4");
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L05_003D99D8(u8 *a0) {
    vu0_v4 c;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 *cp;
    u8 *m;

    if (func_L01_00444358(a0, -1, 0) != 0) {
        cp = &c;
        m = a0 + 0xC0;
        c = *(vu0_v4 *)m;
        c.z -= 0.5f;
        func_00388830(cp, cp, 0.10000001f);
        func_L01_0044ED60(a0, 0x7F, cp, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_0039FE80(0, 0, a0);
        func_L01_0044F1E8(a0, 0x1E5E, 0);
        *(u128_t_3DBE18 *)&b = 0;
        b.x = D_L05_001DF1A8;
        a = b;
        func_003886E8(&a, &a, 15.651901f);
        *(u128_t_3DBE18 *)&b = 0;
        b.z = -0.116666675f;
        func_L02_003E0520(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.15f, 1.5f, 20.0f, 1.0f);
        func_003886E8(&a, &a, *(f32 *)(a0 + 0x2C));
        func_003888C8(&a, &a, m);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_0032FE90(&a, 0, 0, 0, 0, 2, 5, 0, D_L05_001DF1AC * 15.651901f * 0.06389f, 0.0f, 0.0f, 0.0f,
                          0, 0, 0, 0, 0, 0, 0x1000000, 0, D_L05_001DF1A0, D_L05_001DF1A0, 0, 0, 0, 0,
                          D_L05_001DF1A4, D_L05_001DF1A4, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L05_003D99D8 */
