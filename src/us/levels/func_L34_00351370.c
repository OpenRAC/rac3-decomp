#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L34_00352090 (src/levels/34_vidcomic_3/L34_003515A0.c) */
/* localdecomp:start func_L34_00351370 */
extern f32 D_001DD798_sda;
__asm__(".extern D_001DD798_sda, 4");
extern f32 D_001DD79C_sda;
__asm__(".extern D_001DD79C_sda, 4");
extern f32 D_001DD7A0_sda;
__asm__(".extern D_001DD7A0_sda, 4");
extern s32 D_001DD7A8_sda;
__asm__(".extern D_001DD7A8_sda, 4");
extern s32 D_001DD7AC_sda;
__asm__(".extern D_001DD7AC_sda, 4");
extern f32 D_001DD7B0_sda;
__asm__(".extern D_001DD7B0_sda, 4");
extern f32 D_001DD7B4_sda;
__asm__(".extern D_001DD7B4_sda, 4");
extern f32 D_001DD7B8_sda;
__asm__(".extern D_001DD7B8_sda, 4");
extern f32 D_001DD7BC_sda;
__asm__(".extern D_001DD7BC_sda, 4");
extern f32 D_001DD7C0_sda;
__asm__(".extern D_001DD7C0_sda, 4");
extern f32 D_001DD7C4_sda;
__asm__(".extern D_001DD7C4_sda, 4");
extern u8 *D_L34_0021F298[];

typedef struct {
    u8 pad0[0x20];
    f32 t20;
    u8 pad24[4];
    f32 t28;
    f32 t2C;
} Vars_L34_00351370;

extern u32 func_L01_00445C50(u32, s32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_0046E4D8(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L34_00351370(u8 *a0, void *a1) {
    f32 v[4];
    Vars_L34_00351370 *p;
    u8 *r;
    u32 c1;
    u32 c2;
    f32 sc;

    p = *(Vars_L34_00351370 **)(a0 + 0x68);
    sc = D_001DD798_sda;
    c1 = func_L01_00445C50(0x4F007FFF, 0);
    c2 = func_L01_00445C50(0x1F00007F, 0);
    p->t2C += D_001DD7BC_sda;
    while (p->t2C >= 1.0f) {
        p->t2C -= 1.0f;
        func_0037E2F0(v, D_001DD79C_sda * 0.016666668f, D_001DD7A0_sda * 0.016666668f);
        {
            f32 t = -(D_001DD7A0_sda * 3.0f * 0.016666668f * *(f32 *)(a0 + 0xE8));
            v[2] = fabs_asm(v[2]) + t;
        }
        func_L01_00462190(a1, v, c1, c2, func_0037E208(0x14, 0x23), 1, -1, -1, 0, sc * 40000.0f);
    }
    p->t28 += D_001DD7C0_sda;
    while (p->t28 >= 1.0f) {
        p->t28 -= 1.0f;
        func_0037E2F0(v, D_001DD7B0_sda * 0.016666668f, D_001DD7B4_sda * 0.016666668f);
        {
            f32 a = fabs_asm(v[2]);
            f32 b = -(func_0037E250(D_001DD7A0_sda, D_001DD7A0_sda * 4.0f) * 0.016666668f * *(f32 *)(a0 + 0xE8));
            v[2] = a + b + D_001DD7B8_sda;
        }
        func_L01_0046E4D8(a1, v, func_0037E208(D_001DD7AC_sda, D_001DD7A8_sda));
    }
    p->t20 += D_001DD7C4_sda;
    while (p->t20 >= 1.0f) {
        p->t20 -= 1.0f;
        func_003886E8(v, a0 + 0xE0, -0.15f);
        r = func_L01_00472438(a1, v, 0x1E, 1, 0x7F00B4FF, 0x3000B4FF, 0, 147000.0f, 42000.0f, -5.0f);
        if (r != 0) {
            r[2] = *D_L34_0021F298[4];
            r[3] = func_0037E1D8(2) != 0 ? 0x44 : 0x48;
        }
        r = func_L01_00472438(a1, v, 0xF, 1, 0x7F007EFF, 0x40007EFF, 0, 63000.004f, 21000.0f, 0.0f);
        if (r != 0) {
            r[2] = *D_L34_0021F298[0x16C / 4];
            r[3] = 0x48;
        }
    }
}
/* localdecomp:end func_L34_00351370 */
