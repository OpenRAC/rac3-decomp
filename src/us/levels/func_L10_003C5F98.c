#include "common.h"

/* NTSC-U counterpart of func_L10_003C8428 (src/levels/10_zeldrin_starport/L10_003C7C28.c) */
#include "vu0.h"
extern u8 D_L10_001D66B0_003C5F98[8];
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003BD360(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0044EBF8(void *, s32, f32);

/* localdecomp:start func_L10_003C5F98 */
#include "vu0.h"
typedef int u128_t_3C8428 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C8428;
__asm__(".extern D_L10_001DE978, 4");
__asm__(".extern D_L10_001DE97C, 4");
__asm__(".extern D_L10_001DE980, 4");
__asm__(".extern D_L10_001DE984, 4");
extern f32 D_L10_001DE978;
extern f32 D_L10_001DE97C;
extern f32 D_L10_001DE980;
extern f32 D_L10_001DE984;
extern void func_003888C8(void *, void *, void *);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_0032FE90_003C5F98(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C5F98(u8 *m) {
    V4_3C8428 p;
    V4_3C8428 a;
    u128_t_3C8428 z;

    if (func_L01_00444358(m, -1, 0) != 0) {
        func_0039FE80(0, 0, m);
        func_L01_0044ED60(m, 7, D_L10_001D66B0_003C5F98, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        z = 0;
        *(u128_t_3C8428 *)&a = z;
        a.x = D_L10_001DE978;
        a.y = D_L10_001DE97C;
        a.z = D_L10_001DE980;
        p = a;
        func_003886E8(&p, &p, 6.016847f);
        *(u128_t_3C8428 *)&a = z;
        a.z = -0.116666675f;
        func_L02_003E0520(m, &p, 0.1f, &a, 0x14, 0, 0, 0.15f, *(f32 *)(m + 0x2C) * 9.02527f, 20.0f, 1.0f);
        func_003886E8(&p, &p, *(f32 *)(m + 0x2C));
        func_003888C8(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_L01_0032FE90_003C5F98(&p, 0, 0, 0, 0, 2, 5, 0, D_L10_001DE984 * 6.016847f * *(f32 *)(m + 0x2C), 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_0044EBF8(m, 1, 0.0f);
        func_003BD360(m);
    }
}
/* localdecomp:end func_L10_003C5F98 */
