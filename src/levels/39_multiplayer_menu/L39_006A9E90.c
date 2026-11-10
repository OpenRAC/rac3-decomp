#include "common.h"

/* localdecomp:start func_L39_006A9E90 */
__asm__(".extern D_001DBC5C_sda, 4");
__asm__(".extern D_001DD26C_sda, 4");
__asm__(".extern D_001DD270_sda, 4");
__asm__(".extern D_001DD274_sda, 4");
__asm__(".extern D_001DD278_sda, 4");
__asm__(".extern D_001DD27C_sda, 4");
__asm__(".extern D_001DD280_sda, 4");
__asm__(".extern D_001DD284_sda, 4");
__asm__(".extern D_001DD288_sda, 4");
__asm__(".extern D_001DD28C_sda, 4");
__asm__(".extern D_001DD290_sda, 4");
__asm__(".extern D_001DD294_sda, 4");
__asm__(".extern D_001DD298_sda, 4");
__asm__(".extern D_001DD29C_sda, 4");
__asm__(".extern D_001DD2A0_sda, 4");
__asm__(".extern D_001DD2A4_sda, 4");
__asm__(".extern D_001DD2A8_sda, 4");
__asm__(".extern D_001DD2AC_sda, 4");
__asm__(".extern D_001DD2B0_sda, 4");
__asm__(".extern D_001DD2B4_sda, 4");
__asm__(".extern D_001DD2B8_sda, 4");
__asm__(".extern D_001DD2BC_sda, 4");
__asm__(".extern D_001DD2C0_sda, 4");
extern s32 D_001DBC5C_sda;
extern f32 D_001DD26C_sda, D_001DD270_sda, D_001DD274_sda, D_001DD278_sda, D_001DD27C_sda;
extern f32 D_001DD280_sda, D_001DD284_sda, D_001DD288_sda, D_001DD28C_sda, D_001DD290_sda;
extern f32 D_001DD294_sda, D_001DD298_sda, D_001DD29C_sda, D_001DD2A0_sda;
extern f32 D_001DD2A4_sda, D_001DD2A8_sda, D_001DD2AC_sda, D_001DD2B0_sda;
extern f32 D_001DD2B4_sda, D_001DD2B8_sda, D_001DD2BC_sda, D_001DD2C0_sda;
extern s32 func_L39_0067F1B0(void);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern void func_L39_00688460(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);

typedef struct {
    u8 pad0[0x39C];
    s32 f39C, f3A0, f3A4, f3A8, f3AC, f3B0, f3B4, f3B8;
} S_006A9E90;

void func_L39_006A9E90(void *a0)
{
    s32 v[4];
    S_006A9E90 *p = a0;

    func_003E9138(p->f3A4 = func_L39_0067F1B0(), 0x80000000, 0, D_001DD294_sda, D_001DD298_sda, D_001DD29C_sda, D_001DD2A0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3A4);
    func_003E9138(p->f3A8 = func_L39_0067F1B0(), 0x331465B7, 0, D_001DD294_sda, D_001DD298_sda, D_001DD29C_sda, D_001DD2A0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3A8);
    func_003E9138(p->f3B0 = func_L39_0067F1B0(), 0x80000000, 0, D_001DD2A4_sda, D_001DD2A8_sda, D_001DD2AC_sda, D_001DD2B0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3B0);
    func_003E9138(p->f3B4 = func_L39_0067F1B0(), 0x331465B7, 0, D_001DD2A4_sda, D_001DD2A8_sda, D_001DD2AC_sda, D_001DD2B0_sda);
    func_003E8630(D_001DBC5C_sda, p->f3B4);
    func_003E9270(p->f3B8 = func_L39_0067F1B0(), 0x332299DE, D_001DD2B4_sda, D_001DD2B8_sda, D_001DD2BC_sda, D_001DD2C0_sda, 0.004f, 0.004f);
    func_003E8630(D_001DBC5C_sda, p->f3B8);
    func_003E8EF0(p->f39C = func_L39_0067F1B0(), 0x64, 0x332299DE, D_001DD26C_sda, D_001DD270_sda, D_001DD274_sda, D_001DD278_sda, D_001DD27C_sda);
    func_003E8630(D_001DBC5C_sda, p->f39C);
    func_003E8EF0(p->f3A0 = func_L39_0067F1B0(), 0x65, 0x332299DE, D_001DD280_sda, D_001DD284_sda, D_001DD288_sda, D_001DD28C_sda, D_001DD290_sda);
    func_003E8630(D_001DBC5C_sda, p->f3A0);
    func_003E9138(p->f3AC = func_L39_0067F1B0(), 0x8066CCFF, 0, 2.0f, 2.0f, 0.02f, 0.05f);
    func_003E8630(D_001DBC5C_sda, p->f3AC);
    func_L39_00688460(a0, v, v, v, v, v, 2.0f, 2.0f, 0.0f, 0.0f, 1.0f);
}
/* localdecomp:end func_L39_006A9E90 */

INCLUDE_ASM("asm/levels", func_L39_006AA0F0);
