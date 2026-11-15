#include "common.h"

/* declared by functions of L24_003519E8.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L24_00354948 */
typedef struct {
    u8 p0[0x10]; u128_t q10; u8 p20[0x14]; u16 h34; u8 p36[0x74]; s16 hAA; u8 pAC[0x14];
    u128_t qC0; u128_t qD0; u128_t qE0;
} M_00354948;
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0x10]; u8 b31; u8 p32[2]; u16 h34; u8 p36[0xC]; u8 b42; u8 b43;
    u8 p44[4]; f32 f48; u8 p4C[0x1C]; u8 *f68; u8 p6C[0x29]; u8 b95; u8 p96[0x2A]; u8 vC0[0x10];
} O_00354948;
typedef struct {
    u8 p0[0x30]; f32 f30; u8 p34[0xA]; u8 b3E; u8 p3F[0x1F]; u8 b5E; u8 b5F; u8 p60[0xD0];
    s16 h130; u8 p132[0x2E]; u8 v160[0x1A]; u8 b17A; u8 p17B[0x29]; s32 f1A4; u8 p1A8[0x118];
    s32 f2C0; f32 f2C4; s32 f2C8; f32 f2CC; u8 p2D0[0xC]; M_00354948 *f2DC;
} P_00354948;
extern u8 D_L24_001D66B0[8];
extern s32 D_001DF0C0_sda; __asm__(".extern D_001DF0C0_sda, 4");
extern f32 D_001DD548_sda; __asm__(".extern D_001DD548_sda, 4");
extern f32 D_001DD54C_sda; __asm__(".extern D_001DD54C_sda, 4");
extern s32 func_L24_00354F38(void *);
extern void func_L02_003516A8(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C6FE0(void *);
extern void func_003C7C38(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004443E8(void *, s32, s32);
extern void *func_L01_00447490(void *, u32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003C56E0(void *, void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L02_0034C938(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L24_00354948(O_00354948 *a0) {
    P_00354948 *p = (P_00354948 *)a0->f68;
    u8 *v;
    s32 r;
    u128_t m[4];

    if (a0->b20 == 0 && func_L24_00354F38(a0) != 0) return 1;
    if (p->b3E == 2) {
        func_L02_003516A8(a0);
        return 1;
    }
    if (p->f2DC != 0) {
        func_003C2EC0(a0, 0, m);
        p->f2DC->q10 = m[3];
        func_003C6FE0(p->f2DC);
        if ((p->f2DC->h34 & 4) == 0) func_003C7C38(p->f2DC);
        func_0038CF68(m, m, -1.0f);
        p->f2DC->qC0 = m[2];
        p->f2DC->qD0 = m[1];
        p->f2DC->qE0 = m[0];
        func_L01_00448E10(&p->f2DC->qC0);
        func_003C7DD8(p->f2DC);
        if (a0->h34 & 1) p->f2DC->h34 |= 0x41;
        else p->f2DC->h34 &= ~0x41;
        p->f2DC->h34 |= 6;
    }
    if (p->b5E != 0) {
        if (p->f2DC != 0) {
            if (p->f2DC->hAA == 0x1F4) {
                func_L01_00451FE0(p->f2DC, 0x25, D_L24_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L01_00451FE0(p->f2DC, 0x25, D_L24_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            }
            func_003C2880(p->f2DC);
            p->f2DC = 0;
        }
        func_L01_004443E8(a0, 0, 3);
        func_003C2880(a0);
        return 1;
    }
    v = func_L01_00447490(a0, 0x10000, 1);
    r = func_L01_00452FB0(a0, p->v160, 0, 0, 0);
    if (r != 0) {
        if (p->h130 == 0 && r >= 2) {
            p->f30 = 0.0f;
            if (v != 0) {
                m[0] = *(u128_t *)(v + 0x10);
            } else {
                func_0038CE20(m, a0->vC0, -1.0f);
                ((f32 *)m)[2] = 1.0f;
                ((f32 *)m)[3] = 5627.925f;
            }
            if (func_003C56E0(a0, p->v160, m, 4, -1) != 0) {
                p->f1A4 = D_001DF0C0_sda;
                func_L01_004450F0(a0, 0x16, 3);
                p->b17A = 0;
            }
        }
        if (a0->b42 == 0xC || a0->b43 == 0xC) {
            a0->f48 *= func_003824E0(D_001DD548_sda, D_001DD54C_sda);
        }
        func_L02_0034C938(a0);
        if (p->f2DC != 0 && a0->b95 == 3) {
            if (p->f2DC->hAA == 0x1F4) {
                func_L01_00451FE0(p->f2DC, 0x25, D_L24_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L01_00451FE0(p->f2DC, 0x25, D_L24_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            }
            func_003C2880(p->f2DC);
            p->f2DC = 0;
        }
    }
    func_L01_00452860(a0, &p->f30, 0);
    if (p->b5F != 0) {
        if (p->f30 > 0.0f && a0->b31 != 0) func_L01_00456BD0(a0, 5);
        if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 3, 0, 0, 0, p->f2C4, 5.0f, 1.0f);
        else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 3, 0, 0, 0, p->f2CC, 5.0f, 1.0f);
    } else {
        if (p->f30 > 0.0f && a0->b31 != 0) func_L01_00456BD0(a0, 3);
        if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 1, 0, 0, 0, p->f2C4, 5.0f, 1.0f);
        else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 1, 0, 0, 0, p->f2CC, 5.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L24_00354948 */

INCLUDE_ASM("asm/levels", func_L24_00354F38);
