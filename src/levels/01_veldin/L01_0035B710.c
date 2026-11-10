#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0035B710);

/* localdecomp:start func_L01_0035BB00 */
typedef struct { char p0[0x10]; f32 x; } S;
typedef struct { char p0[0x10]; char p10[0x10]; u8 kind; char p21[0x47]; S *s; } H;

extern s32 D_001DD6AC_sda;
__asm__(".extern D_001DD6AC_sda, 4");
extern s32 D_001DD6B0_sda;
__asm__(".extern D_001DD6B0_sda, 4");
extern f32 D_001DD6B4_sda;
__asm__(".extern D_001DD6B4_sda, 4");
extern f32 D_001DD6B8_sda;
__asm__(".extern D_001DD6B8_sda, 4");
extern f32 D_001DD6BC_sda;
__asm__(".extern D_001DD6BC_sda, 4");

extern f32 func_0040F3F8(f32 a, f32 b);
extern f32 func_00443A78(void);
extern void func_0040A6C0(void *p, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f);

void func_L01_0035BB00(H *a0) {
    S *s;
    f32 r;
    if (a0 != 0 && a0->kind != 0xFE && a0->kind != 0xFD) {
        s = a0->s;
        r = func_0040F3F8(s->x, D_001DD6B4_sda * 0.01745329238474369f);
        s->x = r;
        r = func_0040F3F8(-r * 1.5f, 0.0f);
        func_0040A6C0(a0->p10, D_001DD6AC_sda, D_001DD6B0_sda, 1, D_001DD6BC_sda, 0.0799999982118f, r);
        func_0040A6C0(a0->p10, 0x31, 0x10007FFF, 1, 0.36000001430511475f, 0.0799999982118f, s->x * 0.5f);
        r = func_00443A78();
        func_0040A6C0(a0->p10, 0x2F, 0x507F7F7F, 1, D_001DD6B8_sda, 0.0799999982118f, r);
    }
}
/* localdecomp:end func_L01_0035BB00 */

INCLUDE_ASM("asm/levels", func_L01_0035BC18);
