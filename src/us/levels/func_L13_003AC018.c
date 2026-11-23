#include "common.h"

/* NTSC-U counterpart of func_L13_003ADE00 (src/levels/shared/L13_003ADE00.c): 0.4 -> 0.333333; 0.02 -> 0.0166667; 0.0432 -> 0.03; 0.432 -> 0.3 */
/* localdecomp:start func_L13_003AC018 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003ADE00;

typedef struct P_003ADE00 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x8];
    u8 b3E;
    u8 pad3F[0x1F];
    u8 b5E;
    u8 b5F;
    u8 pad60[0x68];
    f32 fC8;
    f32 fCC;
    u8 padD0[0x2A0];
    s32 w370;
    f32 f374;
    s32 w378;
    f32 f37C;
    u8 pad380[0x44];
    f32 f3C4;
    u8 pad3C8[0x8];
    s32 w3D0;
    u8 pad3D4[0xC];
    u8 *p3E0;
    s32 w3E4;
    s32 w3E8;
} P_003ADE00;

typedef struct M_003ADE00 {
    u8 pad0[0x10];
    V_003ADE00 pos;
    u8 b20;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[0x36];
    P_003ADE00 *pv;
    u8 pad6C[0x3];
    u8 b6F;
    u8 pad70[0xC];
    u16 h7C;
    u8 pad7E[0x17];
    u8 b95;
    u8 pad96[0x2A];
    V_003ADE00 vC0;
    u8 padD0[0x10];
    V_003ADE00 vE0;
} M_003ADE00;

extern u8 D_L13_001E21C0[];
extern f32 D_L13_001DF230;
extern s32 D_L13_001DE7C0;
extern f32 D_L13_001DE7C4_003AC018;
extern f32 D_L13_001DE7D0;
extern f32 D_L13_001DE7D4;
extern u8 D_L13_001DE790_003AC018[] __attribute__((section(".sdata")));
extern u8 D_L13_001DE7A8[] __attribute__((section(".sdata")));
__asm__(".extern D_L13_001DE790_003AC018, 8");
__asm__(".extern D_L13_001DE7A8, 8");
__asm__(".extern D_L13_001DE7C0, 4");
__asm__(".extern D_L13_001DE7C4_003AC018, 4");
__asm__(".extern D_L13_001DE7D0, 4");
__asm__(".extern D_L13_001DE7D4, 4");
__asm__(".extern D_L13_001DF230, 4");
__asm__(".extern D_L13_001D67C4_003AC018, 4");
__asm__(".extern D_001D545C, 4");
extern s32 D_001D545C;
extern s32 D_L13_001D67C4_003AC018;

extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L13_003ADC08(u8 *);
extern void func_00388830(void *, void *, f32);
extern void func_L13_003C40E0(void *, void *, void *);
extern void func_003BD360(void *);
extern void func_003C0188(void *, void *, void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L13_003ACD60(void *);
extern void func_L13_003AC720(u8 *);
extern void func_L01_0044CB08(void *, void *, s32, s32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L05_00465110(void *, void *, void *, s32, s32);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_00456960(s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_0044EB78(void *, void *, s32, f32, s32);

s32 func_L13_003AC018(M_003ADE00 *m) {
    P_003ADE00 *p = m->pv;
    s32 hit;
    s32 anim;
    f32 speed;
    V_003ADE00 pos;
    V_003ADE00 dir;
    V_003ADE00 mat[4];
    V_003ADE00 off;

    if (m->b31 != 0 && func_L01_0040C018(D_L13_001E21C0, &m->pos) < 1024.0f) {
        func_L01_00444188(m);
        m->b6F = 30;
    }
    if (m->b95 == 1) {
        p->fCC = 0.2f;
        p->fC8 = 0.75f;
        if (func_L01_0044FCD0(m, (u8 *)p + 0x70, 0, 0, 0) != 0) {
            p->w3E4 = 1;
            func_L13_003ADC08((u8 *)m);
        }
    } else {
        p->fCC = 2.0f;
        p->fC8 = 2.0f;
        hit = 0;
        if (func_L01_0044FCD0(m, (u8 *)p + 0x70, 0, 0, 1) != 0) {
            hit = 1;
        }
        if (m->b95 == 0 && 0.0f < p->f30) {
            if (p->f30 <= (f32)p->h34 * p->f3C4) {
                if (p->p3E0 != 0) {
                    func_00388830(&pos, &m->vE0, 0.333333343f);
                    dir = *(V_003ADE00 *)(p->p3E0 + 0x10);
                    func_L13_003C40E0(m, &dir, &pos);
                    func_003BD360(p->p3E0);
                    p->p3E0 = 0;
                }
                func_00388830(&pos, &m->vC0, -1.0f);
                func_003C0188(m, (u8 *)p + 0x70, &pos, 3, -1);
                func_L01_00441FB8(m, 16, 1);
            }
        } else if (m->b95 == 2 && 0.0f < p->f30 && hit != 0) {
            func_L13_003ACD60(m);
            func_L01_00441FB8(m, 22, -1);
        }
    }
    if (p->b5E != 0) {
        func_L13_003AC720((u8 *)m);
        return 0;
    }
    if (m->pos.z < D_L13_001DF230 - 5.0f) {
        func_L13_003AC720((u8 *)m);
        return 0;
    }
    if (p->b3E == 2) {
        func_L13_003AC720((u8 *)m);
        return 0;
    }
    if (p->p3E0 != 0) {
        func_L01_0044CB08(m, p->p3E0, 4, 0);
        func_003BD9A0(p->p3E0, 0, mat);
        pos = mat[3];
        {
            s32 i;
            for (i = 0; i < D_L13_001DE7C0; i++) {
                func_003BF6A8(&pos, D_L13_001DE7C4_003AC018);
                func_00388830(&dir, &mat[2], func_0037E250(D_L13_001DE7D0, D_L13_001DE7D4) * 0.0166666675f);
                func_L05_00465110(&pos, &dir, D_L13_001DE790_003AC018, func_0037E1D8(2), func_0037E1D8(3) - 1);
            }
        }
        func_00388830(&off, &mat[0], 0.5f);
        vec_add_ab(&pos, &off, &mat[3]);
        {
            s32 i;
            for (i = 0; i < D_L13_001DE7C0; i++) {
                func_003BF6A8(&pos, D_L13_001DE7C4_003AC018);
                func_00388830(&dir, &mat[2], func_0037E250(D_L13_001DE7D0, D_L13_001DE7D4) * 0.0166666675f);
                func_L05_00465110(&pos, &dir, D_L13_001DE7A8, func_0037E1D8(2), func_0037E1D8(3) - 1);
            }
        }
        func_00388830(&off, &mat[0], -0.5f);
        vec_add_ab(&pos, &off, &mat[3]);
        {
            s32 i;
            for (i = 0; i < D_L13_001DE7C0; i++) {
                func_003BF6A8(&pos, D_L13_001DE7C4_003AC018);
                func_00388830(&dir, &mat[2], func_0037E250(D_L13_001DE7D0, D_L13_001DE7D4) * 0.0166666675f);
                func_L05_00465110(&pos, &dir, D_L13_001DE7A8, func_0037E1D8(2), func_0037E1D8(3) - 1);
            }
        }
    }
    func_L01_0044F5E8(m, (u8 *)p + 0x30, 0);
    if (p->b5F != 0) {
        if (D_001D545C == 22 && p->w3E8 == 0) {
            p->w3E8 = 1;
            if (++D_L13_001D67C4_003AC018 >= 15) {
                func_L01_00456960(23);
            }
        }
        func_L01_004538E0(m, 5);
        anim = m->b20 >= 8 ? p->w378 : p->w370;
        speed = m->b20 >= 8 ? p->f37C : p->f374;
        func_L01_004539A8(m, anim, 0, 0, 0, 0, 3, 0, 0, 0, speed, 10.0f, 1.0f);
    } else {
        func_L01_004538E0(m, 3);
        anim = m->b20 >= 8 ? p->w378 : p->w370;
        speed = m->b20 >= 8 ? p->f37C : p->f374;
        func_L01_004539A8(m, anim, 0, 0, 0, 0, 1, p->w3D0 != 0, 0, 0, speed, 10.0f, 1.0f);
    }
    m->h7C |= 0xE0;
    func_L01_0044B5C8(m, (u8 *)p + 0x270, 0, 0.0299999993f, 0.300000012f);
    func_L01_0044B5C8(m, (u8 *)p + 0x2F0, 1, 0.0299999993f, 0.300000012f);
    func_L01_0044EB78(m, (u8 *)p + 0x3F0, 5, 2.5f, 1);
    func_L01_0044EB78(m, (u8 *)p + 0x470, 6, 2.5f, 1);
    func_L01_0044EB78(m, (u8 *)p + 0x4F0, 7, 2.5f, 1);
    func_L01_0044EB78(m, (u8 *)p + 0x570, 8, 2.5f, 1);
    return 1;
}
/* localdecomp:end func_L13_003AC018 */
