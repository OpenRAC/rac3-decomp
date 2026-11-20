#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003ADE00 */
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

extern u8 D_L13_001E2140[];
extern f32 D_L13_001DF1B0;
extern s32 D_L13_001DE790;
extern f32 D_L13_001DE794;
extern f32 D_L13_001DE7A0;
extern f32 D_L13_001DE7A4;
extern u8 D_L13_001DE760[] __attribute__((section(".sdata")));
extern u8 D_L13_001DE778[] __attribute__((section(".sdata")));
__asm__(".extern D_L13_001DE760, 8");
__asm__(".extern D_L13_001DE778, 8");
__asm__(".extern D_L13_001DE790, 4");
__asm__(".extern D_L13_001DE794, 4");
__asm__(".extern D_L13_001DE7A0, 4");
__asm__(".extern D_L13_001DE7A4, 4");
__asm__(".extern D_L13_001DF1B0, 4");
__asm__(".extern D_L13_001D67C4, 4");
__asm__(".extern D_001D545C, 4");
extern s32 D_001D545C;
extern s32 D_L13_001D67C4;

extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L13_003AF9F0(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L13_003C62A8(void *, void *, void *);
extern void func_003C2880(void *);
extern void func_003C56E0(void *, void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L13_003AEB48(void *);
extern void func_L13_003AE508(u8 *);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00451DF8(void *, void *, s32, f32, s32);

s32 func_L13_003ADE00(M_003ADE00 *m) {
    P_003ADE00 *p = m->pv;
    s32 hit;
    s32 anim;
    f32 speed;
    V_003ADE00 pos;
    V_003ADE00 dir;
    V_003ADE00 mat[4];
    V_003ADE00 off;

    if (m->b31 != 0 && func_L01_0040E548(D_L13_001E2140, &m->pos) < 1024.0f) {
        func_L01_004472C0(m);
        m->b6F = 30;
    }
    if (m->b95 == 1) {
        p->fCC = 0.2f;
        p->fC8 = 0.75f;
        if (func_L01_00452FB0(m, (u8 *)p + 0x70, 0, 0, 0) != 0) {
            p->w3E4 = 1;
            func_L13_003AF9F0((u8 *)m);
        }
    } else {
        p->fCC = 2.0f;
        p->fC8 = 2.0f;
        hit = 0;
        if (func_L01_00452FB0(m, (u8 *)p + 0x70, 0, 0, 1) != 0) {
            hit = 1;
        }
        if (m->b95 == 0 && 0.0f < p->f30) {
            if (p->f30 <= (f32)p->h34 * p->f3C4) {
                if (p->p3E0 != 0) {
                    func_0038CF68(&pos, &m->vE0, 0.40000004f);
                    dir = *(V_003ADE00 *)(p->p3E0 + 0x10);
                    func_L13_003C62A8(m, &dir, &pos);
                    func_003C2880(p->p3E0);
                    p->p3E0 = 0;
                }
                func_0038CF68(&pos, &m->vC0, -1.0f);
                func_003C56E0(m, (u8 *)p + 0x70, &pos, 3, -1);
                func_L01_004450F0(m, 16, 1);
            }
        } else if (m->b95 == 2 && 0.0f < p->f30 && hit != 0) {
            func_L13_003AEB48(m);
            func_L01_004450F0(m, 22, -1);
        }
    }
    if (p->b5E != 0) {
        func_L13_003AE508((u8 *)m);
        return 0;
    }
    if (m->pos.z < D_L13_001DF1B0 - 5.0f) {
        func_L13_003AE508((u8 *)m);
        return 0;
    }
    if (p->b3E == 2) {
        func_L13_003AE508((u8 *)m);
        return 0;
    }
    if (p->p3E0 != 0) {
        func_L01_0044FD88(m, p->p3E0, 4, 0);
        func_003C2EC0(p->p3E0, 0, mat);
        pos = mat[3];
        {
            s32 i;
            for (i = 0; i < D_L13_001DE790; i++) {
                func_003C4C18(&pos, D_L13_001DE794);
                func_0038CF68(&dir, &mat[2], func_003824E0(D_L13_001DE7A0, D_L13_001DE7A4) * 0.020000001f);
                func_L05_00468EA8(&pos, &dir, D_L13_001DE760, func_00382468(2), func_00382468(3) - 1);
            }
        }
        func_0038CF68(&off, &mat[0], 0.5f);
        vec_add_ab(&pos, &off, &mat[3]);
        {
            s32 i;
            for (i = 0; i < D_L13_001DE790; i++) {
                func_003C4C18(&pos, D_L13_001DE794);
                func_0038CF68(&dir, &mat[2], func_003824E0(D_L13_001DE7A0, D_L13_001DE7A4) * 0.020000001f);
                func_L05_00468EA8(&pos, &dir, D_L13_001DE778, func_00382468(2), func_00382468(3) - 1);
            }
        }
        func_0038CF68(&off, &mat[0], -0.5f);
        vec_add_ab(&pos, &off, &mat[3]);
        {
            s32 i;
            for (i = 0; i < D_L13_001DE790; i++) {
                func_003C4C18(&pos, D_L13_001DE794);
                func_0038CF68(&dir, &mat[2], func_003824E0(D_L13_001DE7A0, D_L13_001DE7A4) * 0.020000001f);
                func_L05_00468EA8(&pos, &dir, D_L13_001DE778, func_00382468(2), func_00382468(3) - 1);
            }
        }
    }
    func_L01_00452860(m, (u8 *)p + 0x30, 0);
    if (p->b5F != 0) {
        if (D_001D545C == 22 && p->w3E8 == 0) {
            p->w3E8 = 1;
            if (++D_L13_001D67C4 >= 15) {
                func_L01_00459C50(23);
            }
        }
        func_L01_00456BD0(m, 5);
        anim = m->b20 >= 8 ? p->w378 : p->w370;
        speed = m->b20 >= 8 ? p->f37C : p->f374;
        func_L01_00456C98(m, anim, 0, 0, 0, 0, 3, 0, 0, 0, speed, 10.0f, 1.0f);
    } else {
        func_L01_00456BD0(m, 3);
        anim = m->b20 >= 8 ? p->w378 : p->w370;
        speed = m->b20 >= 8 ? p->f37C : p->f374;
        func_L01_00456C98(m, anim, 0, 0, 0, 0, 1, p->w3D0 != 0, 0, 0, speed, 10.0f, 1.0f);
    }
    m->h7C |= 0xE0;
    func_L01_0044E850(m, (u8 *)p + 0x270, 0, 0.0432f, 0.43200004f);
    func_L01_0044E850(m, (u8 *)p + 0x2F0, 1, 0.0432f, 0.43200004f);
    func_L01_00451DF8(m, (u8 *)p + 0x3F0, 5, 2.5f, 1);
    func_L01_00451DF8(m, (u8 *)p + 0x470, 6, 2.5f, 1);
    func_L01_00451DF8(m, (u8 *)p + 0x4F0, 7, 2.5f, 1);
    func_L01_00451DF8(m, (u8 *)p + 0x570, 8, 2.5f, 1);
    return 1;
}
/* localdecomp:end func_L13_003ADE00 */
