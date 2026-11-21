#include "common.h"

/* NTSC-U counterpart of func_L20_00443730 (src/levels/20_final_boss/L20_00443730.c) */
/* localdecomp:start func_L20_004403A8 */
#include "vu0.h"

typedef struct O_00443730 {
    u8 pad0[0x10];
    vu0_q pos;
    u8 pad20[4];
    struct O_00443730 *p24;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0xE];
    u16 h44;
    u8 pad46[0x1D];
    u8 b63;
    u8 pad64[4];
    s32 p68;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0xE];
    s16 id;
} O_00443730;
typedef struct G_00443730 {
    u8 pad0[0x30];
    s32 v30;
    s32 v34;
    u8 pad38[0xC];
    s16 n;
    u8 pad46[0x15A];
    O_00443730 *list[2];
    O_00443730 *l1A8;
    O_00443730 *l1AC;
    O_00443730 *l1B0;
    u8 pad1B4[8];
    O_00443730 *l1BC;
    u8 pad1C0[4];
    O_00443730 *l1C4;
} G_00443730;
typedef struct {
    s16 a0;
    s16 a2;
    f32 a4;
    f32 a8;
    f32 ac;
    f32 b0;
    s32 b4;
    s32 b8;
    s32 bc;
} P_00443730;
typedef struct {
    s16 c80;
    s16 c82;
    f32 c84;
    f32 c88;
    f32 c8C;
    f32 c90;
    s32 c94;
    s32 c98;
    s32 c9C;
} R_00443730;

extern G_00443730 D_L20_001E71C0_004403A8;
extern O_00443730 *D_L20_00239E30_004403A8[];
__asm__(".extern D_L20_00239E30_004403A8, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L20_001D6AE0_004403A8[4];
__asm__(".extern D_L20_001D6AE0_004403A8, 4");
extern u8 D_L20_001D6AE4_004403A8;
__asm__(".extern D_L20_001D6AE4_004403A8, 16");
extern u8 D_L20_001D6AE8_004403A8;
__asm__(".extern D_L20_001D6AE8_004403A8, 16");
extern vu0_q D_L20_001E0070_004403A8[] __attribute__((section(".sdata")));
extern u8 D_L20_001E2E00_004403A8[];
extern s32 D_L20_001D6C50_004403A8[] __attribute__((section(".sdata")));
__asm__(".extern D_L20_001D6C50_004403A8, 4");
extern s32 D_L20_001D6C6C_004403A8;
__asm__(".extern D_L20_001D6C6C_004403A8, 4");
extern u8 D_L20_001D6C70_004403A8[] __attribute__((section(".sdata")));
__asm__(".extern D_L20_001D6C70_004403A8, 4");
extern R_00443730 D_L20_001D6C80_004403A8 __attribute__((section(".sdata")));
__asm__(".extern D_L20_001D6C80_004403A8, 2");
typedef struct { u8 p0[0x2C]; s32 i2C; u8 p30[0x10]; f32 f40; u8 p44[4]; s32 i48; } C_00443730;
extern C_00443730 D_L20_001E2E80_004403A8;

extern void func_L01_00420D88();
extern void func_003A04A0();
extern void func_L01_004026A0();
extern void func_003A26D0();
extern void func_L01_0044EB38(void *, void *, unsigned, unsigned, float);
extern void func_L01_00402498();
extern void func_L01_00421438();
extern O_00443730 *func_L08_00403828(s32);
extern s32 func_L01_0032FE90_004403A8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L03_0040EB30();
extern void func_L20_0043FFF0();
extern void func_L03_0040ED50();
extern void func_L02_003F8C58(void *, void *);
extern void func_L20_003D6798();
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0044C900(void *, void *, f32, f32, f32);
extern s32 func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L16_00431B48(void *);
extern void func_L16_00431AC0();
extern void func_00388830(void *, void *, f32);
extern s32 func_L07_003E1EA0(void *, void *, void *, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004A72A8(s32, s32, s32, s32);
extern void func_L08_00403E80(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L10_00404020(s32, s32, f32);
extern void func_L20_004402A8();

void func_L20_004403A8(void) {
    int i;
    O_00443730 *o;
    int j;

    func_L01_00420D88();
    for (i = 0; i < D_L20_001E71C0_004403A8.n; i++) {
        o = D_L20_001E71C0_004403A8.list[i];
        if (o != 0 && o->id == 0xE29) o->flags |= 0x800;
        if (o->id == 0xD54) {
            o->b63 = 0;
            for (j = 0; D_L20_00239E30_004403A8[j] != 0; j++) {
                if (D_L20_00239E30_004403A8[j]->b63 != 0) D_L20_00239E30_004403A8[j]->b63 = 1;
            }
            func_003A04A0(o, 0);
            func_L01_004026A0(func_003A26D0, o);
        }
        if (o != 0) {
            if (o->id == 0xFA0) {
                if (o->p68 != 0)
                    func_L01_0044EB38(o, (void *)(o->p68 + 12), 0x80AAAAD2, 0x80396464, 0.061086528f);
            } else if (o->id == 0x1DEE || o->id == 0x19BC) {
                func_L01_0044EB38(o, D_L20_001D6AE0_004403A8, 0x80505080, 0x80404038, 0.031997703f);
            } else if (o->id == 0x1977) {
                func_L01_0044EB38(o, &D_L20_001D6AE4_004403A8, 0x8080AAAA, 0x80464646, 0.03781547f);
            } else if (o->id == 0x1766) {
                func_L01_0044EB38(o, &D_L20_001D6AE8_004403A8, 0x80AAAAFF, 0x80646496, 0.11053753f);
            } else if (o->id == 0x195B || o->id == 0x1B58 || o->id == 0x195C || o->id == 0x175A) {
                func_L01_00402498(func_L01_00421438, o);
            }
        }
    }
    if (D_001D545C == 0x14) {
        G_00443730 *g = &D_L20_001E71C0_004403A8;
        vu0_v4 v;
        if (g->v30 == 1) {
            P_00443730 p;
            vu0_v4 c;
            if (g->v34 >= 0x2A8) {
                int k;
                O_00443730 *e;
                for (k = 0; k < 6; k++) {
                    if (D_L20_001E71C0_004403A8.v34 == k * 5 + 0x2A8) {
                        e = func_L08_00403828(0x1D44);
                        if (e != 0) {
                            if (k == 0) {
                                D_L20_001E0070_004403A8[0] = *(vu0_q *)&v = e->pos;
                                func_L01_0032FE90_004403A8(&v, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 3.0f, 0.0f, 0.0f, 2.0f,
                                                  1, 1, 1, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                            } else {
                                vu0_v4 *pv = &v;
                                qzero(pv);
                                func_003BF6A8(pv, 3.0f);
                                vec_add_ba(pv, D_L20_001E0070_004403A8, pv);
                                func_L01_0032FE90_004403A8(pv, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, func_0037E250(1.0f, 2.0f), 0.0f, 0.0f, 2.0f,
                                                  1, 1, 1, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                            }
                        }
                    }
                }
            }
            if ((u32)(D_L20_001E71C0_004403A8.v34 - 0x2B3) < 0x9F) {
                int n;
                p.b4 = 0x40505570;
                p.b8 = 0x202020;
                p.a0 = 0xF0;
                p.a2 = 0x78;
                p.bc = 5;
                p.a4 = 300.0f;
                p.a8 = 200.0f;
                p.ac = 0.016666668f;
                p.b0 = 0.0050000004f;
                for (n = 0; n < p.bc; n++) {
                    vu0_v4 *pv = &v;
                    *(vu0_q *)pv = D_L20_001E0070_004403A8[0];
                    func_003BF6A8(pv, 3.0f);
                    c.x = func_0037E250(-p.b0, p.b0);
                    c.y = func_0037E250(-p.b0, p.b0);
                    c.z = func_0037E250(p.ac, p.ac + p.ac);
                    func_L01_00460318(pv, &c, p.b4, p.b8, p.a0 + func_0037E1D8(p.a2), (s32)p.a8, (s32)p.a4, 0);
                }
            }
            if ((u32)(D_L20_001E71C0_004403A8.v34 - 0x5DC) < 0x25B) {
                G_00443730 *h = &D_L20_001E71C0_004403A8;
                func_L03_0040EB30(h->l1AC, 0xFA, 0x40400000, 0x40404040);
                func_L20_0043FFF0(h->l1AC, 0x5DC, 0x5E1);
                func_L03_0040ED50(h->l1AC, 0x82E, 0x836);
            }
        } else if (g->v30 == 2) {
            if (g->v34 >= 0x47E) {
                O_00443730 *t = g->l1A8;
                func_L02_003F8C58(t, (u8 *)t + 0xC0);
                func_L01_00402498(func_L20_003D6798, t);
            }
        } else if (g->v30 == 3) {
            vu0_v4 vA0;
            vu0_v4 vB0;
            vu0_v4 vC0;
            vu0_v4 vD0;
            vu0_v4 vE0;
            vu0_v4 vF0;
            u8 m100[0x30] __attribute__((aligned(16)));
            int q;
            *(vu0_q *)&vA0 = *(vu0_q *)&v = 0;
            v.z = 1.0f;
            vA0.z = 1.0f;
            for (q = 0; q < 5; q++) {
                O_00443730 *t = func_L08_00403828(D_L20_001D6C50_004403A8[q]);
                if (t != 0 && t->p24 != 0) {
                    t->flags &= ~0x41;
                    t->flags |= t->p24->h44 & 0x1000;
                    t->f98 = *(s32 *)((u8 *)t->p24 + 0x10);
                }
            }
            {
            G_00443730 *h = &D_L20_001E71C0_004403A8;
            if (h->v34 == 0x66) {
                func_L08_00403E80(3, &v, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
            if (h->v34 == 0x645) {
                func_L08_00403E80(3, &v, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
                func_L08_00403E80(2, &vA0, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
            if (h->v34 == 0x668) {
                int r;
                func_003888C8(&vB0, D_L20_001D6C70_004403A8, D_L20_001E2E00_004403A8 + 0x20);
                vec_add_ba(&vB0, &vB0, D_L20_001E2E00_004403A8);
                for (r = 0; r < D_L20_001D6C80_004403A8.c9C; r++) {
                    f32 sp, a, b;
                    s32 nn;
                    qzero(&vC0);
                    func_L01_0044C900(&vC0, &vC0, func_0037E250(D_L20_001D6C80_004403A8.c90, D_L20_001D6C80_004403A8.c8C) * 0.016666668f, func_0037E250(-3.14159274f, 3.14159274f), func_0037E250(-3.14159274f, 3.14159274f));
                    if (vC0.z < 0.0f) vC0.z = -vC0.z;
                    a = func_0037E250(D_L20_001D6C80_004403A8.c88, D_L20_001D6C80_004403A8.c84);
                    nn = func_0037E250(D_L20_001D6C80_004403A8.c82, D_L20_001D6C80_004403A8.c80);
                    func_L01_00468DC0(&vB0, &vC0, D_L20_001D6C80_004403A8.c94, a, nn, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
                }
            }
            }
            {
            G_00443730 *h = &D_L20_001E71C0_004403A8;
            if (h->v34 == 1) D_L20_001D6C6C_004403A8 = 0x4EC;
            if ((u32)(h->v34 - 0x4EC) < 0x10) {
                func_L16_00431B48(h->l1C4);
                func_L01_00402498(func_L16_00431AC0, 0);
            }
            if ((u32)(h->v34 - 0x758) < 0x3D && h->v34 % 10 == 0) {
                *(vu0_q *)&vE0 = *(vu0_q *)&vD0 = 0;
                vD0.x = 30.0f;
                vD0.y = 1.20000005f;
                vE0.x = -30.0f;
                vE0.y = 3.0f;
                vE0.z = -3.0f;
                vD0.z = 2.0f;
                func_003888C8(&vB0, &vD0, D_L20_001E2E00_004403A8 + 0x20);
                vec_add_ba(&vB0, D_L20_001E2E00_004403A8, &vB0);
                func_003888C8(&vF0, &vE0, D_L20_001E2E00_004403A8 + 0x20);
                func_00388830(&vC0, &vF0, 1.0f);
                func_L07_003E1EA0(0, &vB0, &vC0, 1, 0x32, 0, 1.0f, 1.0f, 0.0f);
                func_L01_0032FE90_004403A8(&vB0, 0, 0, 0, 0, 5, 0, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                                  0, 1, 0, 0, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                if (h->l1B0 != 0) func_L01_004A72A8(6, 0, (s32)h->l1B0, 0x199A);
            }
            }
            if ((u32)(D_L20_001E71C0_004403A8.v34 - 0x776) < 0x3D && D_L20_001E71C0_004403A8.v34 % 10 == 0) {
                D_L20_001E2E80_004403A8.f40 = func_0037E250(0.100000001f, 0.200000003f);
                D_L20_001E2E80_004403A8.i48 = 0x19;
                D_L20_001E2E80_004403A8.i2C = 0;
            }
            {
            G_00443730 *h = &D_L20_001E71C0_004403A8;
            if ((u32)(h->v34 - 0x7C6) < 0x6F && h->v34 % 20 == 0) {
                O_00443730 *t = h->l1BC;
                if (t != 0) {
                    *(vu0_q *)&vC0 = *(vu0_q *)&vD0 = 0;
                    vC0.y = -6.666667f;
                    vD0.y = -3.0f;
                    vD0.z = 1.0f;
                    func_L02_003F8C58(t, m100);
                    func_003888C8(&vD0, &vD0, m100);
                    vec_add_ba(&vB0, &vD0, &t->pos);
                    func_003888C8(&vC0, &vC0, m100);
                    func_L07_003E1EA0(0, &vB0, &vC0, 1, 50 - (s32)((f32)(h->v34 - 0x7C6) * 0.400000006f), 0, 1.0f, 3.0f, 0.0f);
                }
            }
            }
            if ((u32)(D_L20_001E71C0_004403A8.v34 - 0x7F8) < 0x6F && D_L20_001E71C0_004403A8.v34 % 20 == 0) {
                D_L20_001E2E80_004403A8.f40 = func_0037E250(0.0500000007f, 0.100000001f);
                D_L20_001E2E80_004403A8.i48 = 0x14;
                D_L20_001E2E80_004403A8.i2C = 0;
            }
            func_L10_00404020(7, 0, 1.0f);
            if (D_L20_001E71C0_004403A8.l1BC != 0) func_L01_00402498(func_L20_004402A8, 0);
        } else if (g->v30 == 4) {
            if ((u32)(g->v34 - 0x32) < 0xB && !(g->v34 & 1)) {
                O_00443730 *t = g->list[0];
                if (t != 0) {
                    vu0_v4 *pv = &v;
                    *(vu0_q *)pv = t->pos;
                    func_003BF6A8(pv, 5.0f);
                    v.z = v.z + 5.0f;
                    func_L01_0032FE90_004403A8(pv, 0, 0xF, 0xA, 0xF, 0, 0, 3, func_0037E250(1.5f, 2.5f), 0.0f, 0.0f, 2.0f,
                                      0, 0, 0, 0, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L20_004403A8 */
