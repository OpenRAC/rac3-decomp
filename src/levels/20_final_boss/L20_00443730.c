#include "common.h"

/* localdecomp:start func_L20_00443730 */
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

extern G_00443730 D_L20_001E71C0;
extern O_00443730 *D_L20_00239E30[];
__asm__(".extern D_L20_00239E30, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L20_001D6AE0[4];
__asm__(".extern D_L20_001D6AE0, 4");
extern u8 D_L20_001D6AE4;
__asm__(".extern D_L20_001D6AE4, 16");
extern u8 D_L20_001D6AE8;
__asm__(".extern D_L20_001D6AE8, 16");
extern vu0_q D_L20_001E0070[] __attribute__((section(".sdata")));
extern u8 D_L20_001E2E00[];
extern s32 D_L20_001D6C50[] __attribute__((section(".sdata")));
__asm__(".extern D_L20_001D6C50, 4");
extern s32 D_L20_001D6C6C;
__asm__(".extern D_L20_001D6C6C, 4");
extern u8 D_L20_001D6C70[] __attribute__((section(".sdata")));
__asm__(".extern D_L20_001D6C70, 4");
extern R_00443730 D_L20_001D6C80 __attribute__((section(".sdata")));
__asm__(".extern D_L20_001D6C80, 2");
typedef struct { u8 p0[0x2C]; s32 i2C; u8 p30[0x10]; f32 f40; u8 p44[4]; s32 i48; } C_00443730;
extern C_00443730 D_L20_001E2E80;

extern void func_L01_00423AB8();
extern void func_003A58C0();
extern void func_L01_00404A10();
extern void func_003A7AF8();
extern void func_L01_00451DB8(void *, void *, unsigned, unsigned, float);
extern void func_L01_00404808();
extern void func_L01_00424168();
extern O_00443730 *func_L08_00406A30(s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L03_00411C40();
extern void func_L20_00443310();
extern void func_L03_00411E60();
extern void func_L02_003FBE40(void *, void *);
extern void func_L20_003D8248();
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0044FB80(void *, void *, f32, f32, f32);
extern s32 func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L16_00434B70(void *);
extern void func_L16_00434AE8();
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L07_003E3C90(void *, void *, void *, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern void func_L08_004070C0(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L10_00407378(s32, s32, f32);
extern void func_L20_00443630();

void func_L20_00443730(void) {
    int i;
    O_00443730 *o;
    int j;

    func_L01_00423AB8();
    for (i = 0; i < D_L20_001E71C0.n; i++) {
        o = D_L20_001E71C0.list[i];
        if (o != 0 && o->id == 0xE29) o->flags |= 0x800;
        if (o->id == 0xD54) {
            o->b63 = 0;
            for (j = 0; D_L20_00239E30[j] != 0; j++) {
                if (D_L20_00239E30[j]->b63 != 0) D_L20_00239E30[j]->b63 = 1;
            }
            func_003A58C0(o, 0);
            func_L01_00404A10(func_003A7AF8, o);
        }
        if (o != 0) {
            if (o->id == 0xFA0) {
                if (o->p68 != 0)
                    func_L01_00451DB8(o, (void *)(o->p68 + 12), 0x80AAAAD2, 0x80396464, 0.0733038336f);
            } else if (o->id == 0x1DEE || o->id == 0x19BC) {
                func_L01_00451DB8(o, D_L20_001D6AE0, 0x80505080, 0x80404038, 0.0383972451f);
            } else if (o->id == 0x1977) {
                func_L01_00451DB8(o, &D_L20_001D6AE4, 0x8080AAAA, 0x80464646, 0.0453785658f);
            } else if (o->id == 0x1766) {
                func_L01_00451DB8(o, &D_L20_001D6AE8, 0x80AAAAFF, 0x80646496, 0.132645041f);
            } else if (o->id == 0x195B || o->id == 0x1B58 || o->id == 0x195C || o->id == 0x175A) {
                func_L01_00404808(func_L01_00424168, o);
            }
        }
    }
    if (D_001D545C == 0x14) {
        G_00443730 *g = &D_L20_001E71C0;
        vu0_v4 v;
        if (g->v30 == 1) {
            P_00443730 p;
            vu0_v4 c;
            if (g->v34 >= 0x237) {
                int k;
                O_00443730 *e;
                for (k = 0; k < 6; k++) {
                    if (D_L20_001E71C0.v34 == ((k * 5 + 0x2A8) * 5 + 2) / 6) {
                        e = func_L08_00406A30(0x1D44);
                        if (e != 0) {
                            if (k == 0) {
                                D_L20_001E0070[0] = *(vu0_q *)&v = e->pos;
                                func_L01_003303B8(&v, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 3.0f, 0.0f, 0.0f, 2.0f,
                                                  1, 1, 1, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                            } else {
                                vu0_v4 *pv = &v;
                                qzero(pv);
                                func_003C4C18(pv, 3.0f);
                                vec_add_ba(pv, D_L20_001E0070, pv);
                                func_L01_003303B8(pv, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, func_003824E0(1.0f, 2.0f), 0.0f, 0.0f, 2.0f,
                                                  1, 1, 1, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                            }
                        }
                    }
                }
            }
            if ((u32)(D_L20_001E71C0.v34 - 0x240) < 0x84) {
                int n;
                p.b4 = 0x40505570;
                p.b8 = 0x202020;
                p.a0 = 0xF0;
                p.a2 = 0x78;
                p.bc = 5;
                p.a4 = 300.0f;
                p.a8 = 200.0f;
                p.ac = 0.0200000014f;
                p.b0 = 0.00600000052f;
                for (n = 0; n < p.bc; n++) {
                    vu0_v4 *pv = &v;
                    *(vu0_q *)pv = D_L20_001E0070[0];
                    func_003C4C18(pv, 3.0f);
                    c.x = func_003824E0(-p.b0, p.b0);
                    c.y = func_003824E0(-p.b0, p.b0);
                    c.z = func_003824E0(p.ac, p.ac + p.ac);
                    func_L01_004637C8(pv, &c, p.b4, p.b8, p.a0 + func_00382468(p.a2), (s32)p.a8, (s32)p.a4, 0);
                }
            }
            if ((u32)(D_L20_001E71C0.v34 - 0x4E2) < 0x1F7) {
                G_00443730 *h = &D_L20_001E71C0;
                func_L03_00411C40(h->l1AC, 0xFA, 0x40400000, 0x40404040);
                func_L20_00443310(h->l1AC, 0x5DC, 0x5E1);
                func_L03_00411E60(h->l1AC, 0x82E, 0x836);
            }
        } else if (g->v30 == 2) {
            if (g->v34 >= 0x3BE) {
                O_00443730 *t = g->l1A8;
                func_L02_003FBE40(t, (u8 *)t + 0xC0);
                func_L01_00404808(func_L20_003D8248, t);
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
                O_00443730 *t = func_L08_00406A30(D_L20_001D6C50[q]);
                if (t != 0 && t->p24 != 0) {
                    t->flags &= ~0x41;
                    t->flags |= t->p24->h44 & 0x1000;
                    t->f98 = *(s32 *)((u8 *)t->p24 + 0x10);
                }
            }
            {
            G_00443730 *h = &D_L20_001E71C0;
            if (h->v34 == 0x56) {
                func_L08_004070C0(3, &v, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
            if (h->v34 == 0x538) {
                func_L08_004070C0(3, &v, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
                func_L08_004070C0(2, &vA0, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
            if (h->v34 == 0x557) {
                int r;
                func_0038D000(&vB0, D_L20_001D6C70, D_L20_001E2E00 + 0x20);
                vec_add_ba(&vB0, &vB0, D_L20_001E2E00);
                for (r = 0; r < D_L20_001D6C80.c9C; r++) {
                    f32 sp, a, b;
                    s32 nn;
                    qzero(&vC0);
                    func_L01_0044FB80(&vC0, &vC0, func_003824E0(D_L20_001D6C80.c90, D_L20_001D6C80.c8C) * 0.0200000014f, func_003824E0(-3.14159274f, 3.14159274f), func_003824E0(-3.14159274f, 3.14159274f));
                    if (vC0.z < 0.0f) vC0.z = -vC0.z;
                    a = func_003824E0(D_L20_001D6C80.c88, D_L20_001D6C80.c84);
                    nn = func_003824E0(D_L20_001D6C80.c82, D_L20_001D6C80.c80);
                    func_L01_0046C470(&vB0, &vC0, D_L20_001D6C80.c94, a, nn, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
                }
            }
            }
            {
            G_00443730 *h = &D_L20_001E71C0;
            if (h->v34 == 1) D_L20_001D6C6C = 0x41A;
            if ((u32)(h->v34 - 0x41A) < 0xD) {
                func_L16_00434B70(h->l1C4);
                func_L01_00404808(func_L16_00434AE8, 0);
            }
            if ((u32)(h->v34 - 0x61F) < 0x33 && h->v34 % 10 == 0) {
                *(vu0_q *)&vE0 = *(vu0_q *)&vD0 = 0;
                vD0.x = 30.0f;
                vE0.x = -30.0f;
                vE0.y = 3.0f;
                vE0.z = -3.0f;
                vD0.y = 1.20000005f;
                vD0.z = 2.0f;
                func_0038D000(&vB0, &vD0, D_L20_001E2E00 + 0x20);
                vec_add_ba(&vB0, D_L20_001E2E00, &vB0);
                func_0038D000(&vF0, &vE0, D_L20_001E2E00 + 0x20);
                func_0038CF68(&vC0, &vF0, 1.20000005f);
                func_L07_003E3C90(0, &vB0, &vC0, 1, 0x2A, 0, 1.0f, 1.0f, 0.0f);
                func_L01_003303B8(&vB0, 0, 0, 0, 0, 5, 0, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                                  0, 1, 0, 0, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                if (h->l1B0 != 0) func_L01_004AAC98(6, 0, (s32)h->l1B0, 0x199A);
            }
            }
            if ((u32)(D_L20_001E71C0.v34 - 0x638) < 0x33 && D_L20_001E71C0.v34 % 10 == 0) {
                D_L20_001E2E80.f40 = func_003824E0(0.100000001f, 0.200000003f);
                D_L20_001E2E80.i48 = 0x15;
                D_L20_001E2E80.i2C = 0;
            }
            {
            G_00443730 *h = &D_L20_001E71C0;
            if ((u32)(h->v34 - 0x67A) < 0x5D && h->v34 % 20 == 0) {
                O_00443730 *t = h->l1BC;
                if (t != 0) {
                    *(vu0_q *)&vC0 = *(vu0_q *)&vD0 = 0;
                    vC0.y = -8.00000095f;
                    vD0.y = -3.0f;
                    vD0.z = 1.0f;
                    func_L02_003FBE40(t, m100);
                    func_0038D000(&vD0, &vD0, m100);
                    vec_add_ba(&vB0, &vD0, &t->pos);
                    func_0038D000(&vC0, &vC0, m100);
                    func_L07_003E3C90(0, &vB0, &vC0, 1, ((50 - (s32)((f32)(h->v34 - 0x7C6) * 0.400000006f)) * 5 + 2) / 6, 0, 1.0f, 3.0f, 0.0f);
                }
            }
            }
            if ((u32)(D_L20_001E71C0.v34 - 0x6A4) < 0x5D && D_L20_001E71C0.v34 % 20 == 0) {
                D_L20_001E2E80.f40 = func_003824E0(0.0500000007f, 0.100000001f);
                D_L20_001E2E80.i48 = 0x11;
                D_L20_001E2E80.i2C = 0;
            }
            func_L10_00407378(7, 0, 1.0f);
            if (D_L20_001E71C0.l1BC != 0) func_L01_00404808(func_L20_00443630, 0);
        } else if (g->v30 == 4) {
            if ((u32)(g->v34 - 0x2A) < 9 && !(g->v34 & 1)) {
                O_00443730 *t = g->list[0];
                if (t != 0) {
                    vu0_v4 *pv = &v;
                    *(vu0_q *)pv = t->pos;
                    func_003C4C18(pv, 5.0f);
                    v.z = v.z + 5.0f;
                    func_L01_003303B8(pv, 0, 0xF, 0xA, 0xF, 0, 0, 3, func_003824E0(1.5f, 2.5f), 0.0f, 0.0f, 2.0f,
                                      0, 0, 0, 0, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L20_00443730 */
