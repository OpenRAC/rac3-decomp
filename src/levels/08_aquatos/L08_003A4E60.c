#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x24];
    f32 f24;
} T_003A56E8;
typedef struct {
    u8 p0[0x30];
    f32 f30;
    s16 h34;
    u8 p36[0x3];
    u8 b39;
    u8 p3A[0x4];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 p44[0x14];
    u8 b58;
    u8 p59[0x1];
    u8 b5A;
    u8 p5B[0x15];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 p84[0x18];
    s32 w9C;
    f32 fA0;
    u8 pA4[0x4];
    s32 wA8;
    u8 pAC[0xC4];
    u8 b170;
    u8 b171;
    u8 p172[0x4];
    u8 b176;
    u8 p177[0x19];
    f32 f190;
    f32 f194;
    u8 p198[0x4];
    f32 f19C;
    u8 p1A0[0x8];
    u8 b1A8;
    u8 p1A9[0x2E];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 p1DC[0x100];
    s32 w2DC;
    vu0_v4 v2E0;
    u8 p2F0[0x20];
    f32 f310;
    u8 p314[0x10];
    s32 w324;
    u8 p328[0x4];
    s32 w32C;
    u8 p330[0x1C];
    s32 w34C;
} P_003A56E8;
typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[4];
    T_003A56E8 *p24;
    u8 p28[4];
    f32 f2C;
    u8 p30[4];
    u16 h34;
    u8 p36[0xD];
    u8 b43;
    u8 p44[0x24];
    P_003A56E8 *p68;
    u8 p6C[0x2C];
    s32 w98;
    u8 p9C[0x20];
    u8 bBC;
} M_003A56E8;

INCLUDE_ASM("asm/levels", func_L08_003A4E60);

/* localdecomp:start func_L08_003A6F48 */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x44 - 0x14];
    u16 f44;
} C_003A6F48;
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[3];
    C_003A6F48 *pclass;
    u8 pad28[0x34 - 0x28];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    void *pvar;
    u8 pad6c[0x98 - 0x6C];
    s32 f98;
    u8 pad9c[0xAA - 0x9C];
    s16 oclass;
} M_003A6F48;
typedef struct {
    u8 pad0[0x324];
    s32 f324;
} P_003A6F48;
extern u8 *D_L08_001DF21C;
__asm__(".extern D_L08_001DF21C, 16");
extern s32 D_L08_001DF258;
extern s16 *D_L08_0021BEA0[];
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L08_003A6F48(M_003A6F48 *a0) {
    P_003A6F48 *p = a0->pvar;
    M_003A6F48 *r;
    s16 *q;

    if (p->f324 != 0xFF) {
        a0->flags &= ~0x41;
        a0->flags |= a0->pclass->f44 & 0x1000;
        a0->f98 = a0->pclass->f10;
        q = D_L08_0021BEA0[p->f324];
        while ((p->f324 & 0xFF) != 0xFF && p->f324 <= D_L08_001DF258 && q != 0 && (q[-1] >= 0 || q == D_L08_0021BEA0[p->f324])) {
            r = (M_003A6F48 *)(D_L08_001DF21C + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            if (r->oclass == 0x1A79 && r->state != 0xFE && r->state != 0xFD) {
                func_L01_003303B8((u8 *)r + 0x10, 0, 25, 20, 20, 20, 25, 0, 1.25f, 0.0f, 0.0f, 2.0f,
                    0, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_003C2880(r);
            }
            q++;
        }
    }
}
/* localdecomp:end func_L08_003A6F48 */

/* localdecomp:start func_L08_003A7138 */
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0x47]; u8 *p68; u8 p6C[0x29]; u8 b95;
} O_003A7138;
typedef struct {
    u8 p0[0x30]; f32 f30; u8 p34[0xA]; u8 b3E; u8 p3F[0x1F]; u8 b5E; u8 b5F;
    u8 p60[0x234 - 0x60]; s16 h234; u8 p236[0x2C0 - 0x236];
    s32 f2C0; f32 f2C4; s32 f2C8; f32 f2CC; u8 p2D0[8]; s32 f2D8; u8 p2DC[0x31C - 0x2DC];
    s32 f31C; u8 p320[0xC]; s32 f32C; u8 p330[0x3D4 - 0x330]; s32 f3D4;
} P_003A7138;
extern f32 D_001A4C60[];
extern s32 func_L08_003A74A8(void *);
extern void func_L08_003A76C8(void *m);
extern void func_L01_003A4320(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L08_003A7138(O_003A7138 *a0) {
    P_003A7138 *p = (P_003A7138 *)a0->p68;
    f32 old;
    if (a0->b20 == 0 && func_L08_003A74A8(a0) != 0) return 1;
    if (p->b3E == 2) {
        func_L08_003A76C8(a0);
        return 1;
    }
    old = p->f30;
    if (func_L01_00452FB0(a0, (u8 *)p + 0x160, 0, 0, 0) != 0) func_L01_003A4320(a0);
    if (p->f30 < old) {
        p->f2D8 = 1;
        func_L01_003A4320(a0);
    }
    func_L01_00452860(a0, &p->f30, 0);
    if (p->b5E != 0) {
        func_L08_003A76C8(a0);
        return 1;
    }
    if (func_0038CF38((u8 *)a0 + 0x10, D_001A4C60) < 32.0f) {
        if (p->f31C != -1 && p->h234 != 1 && p->f32C == 0) {
            if (func_L01_00456500(D_001A4C60, p->f31C) != 0) p->f32C = 1;
        }
    }
    if (p->b5F != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 3, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
        else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 3, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
    } else {
        if (p->f3D4 == 0) {
            p->f32C = 1;
            func_L01_00456BD0(a0, 3);
            if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 1, 3, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
            else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 1, 3, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
        } else {
            func_L01_00456BD0(a0, 3);
            if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 1, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
            else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 1, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
        }
        if (p->f2C0 != -1) {
            if (p->f32C == 0) return 0;
            if (func_L01_00456500(D_001A4C60, p->f2C0) != 0) {
                p->f32C = 0;
                return 0;
            }
        }
        if (p->f32C != 0) {
            if (func_0038CF38((u8 *)a0 + 0x10, D_001A4C60) < p->f2C4) p->f32C = 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L08_003A7138 */

/* localdecomp:start func_L08_003A74A8 */
/* PAL port of the NTSC-U match src/us/levels/func_L08_003A56E8.c */
#include "vu0.h"


extern f32 D_L08_001DE29C;
__asm__(".extern D_L08_001DE29C, 4");
extern f32 func_00382538(void);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

s32 func_L08_003A74A8(M_003A56E8 *m) {
    P_003A56E8 *p;

    p = m->p68;
    p->f310 = func_00382538();
    p->w32C = 0;
    p->w34C = 0;
    m->bBC = 0;
    p->b170 = 0x10;
    p->b1A8 = 3;
    p->b171 = 0xE;
    p->f190 = 0.5f;
    p->f194 = 0.5f;
    p->b176 = 0x12;
    p->f19C = 0.15f;
    p->b1D7 = 1;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    p->b1DB = 0xFF;
    p->v2E0 = m->pos;
    p->f74 = 0.5f;
    p->f70 = 1.25f;
    p->w9C = 0;
    p->f78 = 0.5f;
    p->f7C = 1.0f;
    p->f80 = 1.4835298f;
    p->fA0 = 0.34906584f;
    p->wA8 |= 5;
    func_L01_0045BD78(m, 0.0064000003f, 0.15f, 0.010053097f, 0.25132743f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 10;
        p->f30 = 10.0f;
    }
    p->b39 = 1;
    p->b3F = 0;
    p->f40 = 2.0f;
    m->f2C = m->p24->f24 * D_L08_001DE29C;
    p->b3E = 1;
    if (m->b43 != 5) {
        func_003C3A10(m, 5, 0, 8);
    }
    func_L01_004450F0(m, 0xD, -1);
    if (p->w324 != -1) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    if (p->w2DC != 0) {
        func_L01_004450F0(m, 1, 0);
        if (m->b43 != 0) {
            func_003C3A10(m, 0, 0, 8);
        }
    }
    return 0;
}
/* localdecomp:end func_L08_003A74A8 */

/* localdecomp:start func_L08_003A76C8 */
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                   f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *m, s32 a, s32 b);
extern u8 D_L08_001D66B0[8];

void func_L08_003A76C8(void *m) {
    func_L01_00452310(m, 0x1FFF, D_L08_001D66B0, 1, 0x1E, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_L01_004443E8(m, 0, 3);
}
/* localdecomp:end func_L08_003A76C8 */

/* localdecomp:start func_L08_003A7750 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[0x11]; u8 b31; u8 p32[0x10]; u8 b42; u8 p43[0x2C]; u8 b6F;
    u8 p70[0x25]; u8 b95; u16 h96;
} M_003A7750;
typedef struct {
    u8 p0[0x220]; vu0_v4 v220; u8 p230[0x10]; u8 v240[0x90]; s32 w2D0; s32 w2D4; u8 p2D8[0x38];
    f32 f310; f32 f314; u8 p318[0x38]; u8 v350[0x64]; f32 f3B4;
} P_003A7750;
extern s32 D_L08_001DEDC0;
__asm__(".extern D_L08_001DEDC0, 16");
extern u8 D_L08_001E1D40[];
extern f32 D_001DE2A0_sda;
__asm__(".extern D_001DE2A0_sda, 4");
extern f32 D_001DE2A4_sda;
__asm__(".extern D_001DE2A4_sda, 4");
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382498(s32, s32);
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);

void func_L08_003A7750(void *arg) {
    M_003A7750 *m = arg;
    P_003A7750 *p = *(P_003A7750 **)((u8 *)m + 0x68);
    vu0_v4 out;
    vu0_v4 vel;
    vu0_v4 v;
    s32 t;

    func_0038CAD0(&p->w2D0);
    func_0038CB00(&p->w2D4);
    if (m->h96 < 0xFFFF) m->h96++;
    *(vu0_q *)&v = 0;
    v.z = -(func_003824E0(2.5f, 3.5f) * 0.020000001f);
    vel = v;
    func_003C2F58(m, 1, &out);
    out.z -= 0.25f;
    if (D_L08_001DEDC0 & 1) {
        func_L01_004637C8(&out, &vel, 0xCF0000FF, 0xCF, (func_00382498(0x12, 0x16) * 5 + 2) / 6, 0xA0, -10, 1);
    } else {
        func_L01_004637C8(&out, &vel, 0x6000FFFF, 0x80, (func_00382498(0x14, 0x18) * 5 + 2) / 6, 0xD2, -10, 1);
    }
    t = func_00382498(0x14, 0x5A);
    func_L01_004637C8(&out, &vel, 0xEFFF7F4F, 0xFF0000, (func_00382498(0xA, 0xF) * 5 + 2) / 6, t, -t, 1);
    if ((m->b42 == 0x14 || m->b42 == 0x16) && m->b95 == 2) {
        func_003C2F58(m, 3, &v);
        p->f3B4 = -func_0038D160(func_0038CF38(&v, &p->v220), p->v220.z - v.z);
    }
    func_L01_0044E850(m, p->v350, 3, 0.0432f, 0.43200004f);
    func_L01_00451DF8((u8 *)m, p->v240, 4, 1, 2.5f);
    if (m->b31 != 0 && func_L01_0040E548(D_L08_001E1D40, &m->pos) < 576.0f) {
        func_L01_004472C0(m);
        m->b6F = 0x16;
    }
    func_L01_0044EAE0(m, &p->f310, &p->f314, D_001DE2A0_sda, D_001DE2A4_sda * 0.017453292f * 0.020000001f, -1.0f);
}
/* localdecomp:end func_L08_003A7750 */
