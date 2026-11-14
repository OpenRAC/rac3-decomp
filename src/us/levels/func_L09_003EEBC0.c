#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003EEBC0 */
typedef int u128_t_003EEBC0 __attribute__((mode(TI)));

typedef struct {
    u8 p0[4];
    f32 f4;
} P_003EEBC0;

typedef struct {
    u8 p0[0x2C];
    f32 f2C;
    u8 p30[1];
    u8 b31;
    u8 p32[0x36];
    P_003EEBC0 *p68;
} M_003EEBC0;

extern u8 D_L09_001D66B0_003EEBC0[8];
__asm__(".extern D_L09_001D66B0_003EEBC0, 16");
extern f32 D_001DF570_sda;
__asm__(".extern D_001DF570_sda, 4");
extern f32 D_001DF574_sda;
__asm__(".extern D_001DF574_sda, 4");
extern s32 D_L09_001DFC40;
__asm__(".extern D_L09_001DFC40, 16");

extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);
extern f32 func_0037E250(f32, f32);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);

void func_L09_003EEBC0(M_003EEBC0 *m) {
    P_003EEBC0 *p;
    vu0_v4 a;
    vu0_v4 b;

    p = m->p68;
    if (func_L01_00444358(m, -1, 0) != 0) {
        func_0039FE80(0, 0, m);
        func_L01_0044ED60(m, 0xFF, D_L09_001D66B0_003EEBC0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0044F1E8(m, 0x1EAF, 0);
        *(u128_t_003EEBC0 *)&b = 0;
        b.z = D_001DF570_sda;
        a = b;
        func_003886E8(&a, &a, 2.7311213f);
        *(u128_t_003EEBC0 *)&b = 0;
        b.z = -0.116666675f;
        func_L02_003E0520(m, &a, 0.1f, &b, 0x14, 0, 0, 0.15f, m->f2C * 4.096682f, 20.0f, 1.0f);
        func_003886E8(&a, &a, m->f2C);
        func_003888C8(&a, &a, (u8 *)m + 0xC0);
        vec_add_ab(&a, &a, (u8 *)m + 0x10);
        func_L01_0032FE90(&a, 0, 0, 0, 0, 2, 5, 0, D_001DF574_sda * 2.7311213f * m->f2C, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x8EFFFE, 0x40FFFD, 0, 0, 0, 0, 0x8EFFFE, 0x40FFFD, 0, 0);
        func_L01_0044EBF8(m, 1, 0.0f);
        func_003BD360(m);
    } else if (D_L09_001DFC40 == 0) {
        p->f4 = func_0037E250(0.03490659f, 0.104719765f);
    } else if (m->b31 != 0) {
        func_L01_0044EB38(m, p, 0xB0B0B0B0, 0x60606060, p->f4);
    }
}
/* localdecomp:end func_L09_003EEBC0 */
