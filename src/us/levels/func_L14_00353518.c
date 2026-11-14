#include "common.h"

/* NTSC-U counterpart of func_L14_00354538 (src/levels/14_koros/L14_003542F0.c) */
#include "vu0.h"

typedef struct {
    u8 pad_00[0xAA];
    s16 f_AA;
} S_L14_00354B90;

typedef int u128_t_3542F0 __attribute__((mode(TI)));
extern u8 D_L14_001D66B0_00353518;
extern s32 D_L14_001D67B8_00353518;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);

/* localdecomp:start func_L14_00353518 */
typedef int u128_t_354538 __attribute__((mode(TI)));
extern u8 D_L14_001D66B0_00353518;
extern s32 D_L14_001D67B8_00353518;
__asm__(".extern D_L14_001DD65C, 4");
__asm__(".extern D_L14_001DD660, 4");
__asm__(".extern D_L14_001DD664, 4");
__asm__(".extern D_L14_001DD668, 4");
__asm__(".extern D_L14_001DD66C, 4");
extern s32 D_L14_001DF240_00353518;
extern f32 D_L14_001DD65C;
extern f32 D_L14_001DD660;
extern f32 D_L14_001DD664;
extern f32 D_L14_001DD668;
extern f32 D_L14_001DD66C;
extern void func_L01_004026A0(void *, void *);
extern void func_L14_00353B70(S_L14_00354B90 *);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
void func_L14_00353518(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;
    if (a0[0x31] != 0 && D_L14_001DF240_00353518 != 0) {
        func_L01_004026A0(func_L14_00353B70, a0);
    }
    if (a0[0x20] == 0) {
        D_L14_001D67B8_00353518 = 0;
        a0[0x20] = 1;
    }
    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0x7F, &D_L14_001D66B0_00353518, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = 1.0f / D_L14_001DD66C;
        *(u128_t_354538 *)&a = 0;
        a.x = D_L14_001DD65C;
        a.y = D_L14_001DD660;
        a.z = D_L14_001DD664;
        b = a;
        func_003886E8(&b, &b, t);
        *(u128_t_354538 *)&a = 0;
        a.z = -0.116666675f;
        func_L02_003E0520(a0, &b, 0.1f, &a, 0x14, 0, 0.15f, 1.5f, 20.0f, 1.0f, 0);
        func_003886E8(&b, &b, *(f32 *)(a0 + 0x2C));
        func_003888C8(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_0032FE90(&b, 0, 0, 0, 0, 2, 5, 0, D_L14_001DD668 * t * D_L14_001DD66C, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        D_L14_001D67B8_00353518 = D_L14_001D67B8_00353518 + 1;
        if (D_L14_001D67B8_00353518 >= 100) {
            func_L01_00456960(0x11);
        }
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L14_00353518 */
