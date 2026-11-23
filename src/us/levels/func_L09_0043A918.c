#include "common.h"

/* NTSC-U counterpart of func_L09_0043D900 (src/levels/09_tyhrranosis/L09_0043D900.c) */
/* localdecomp:start func_L09_0043A918 */
#include "vu0.h"
/* Tyhrranosis controller update: the moby list pass, then the scripted states of the D_L09_001E6F40 controller. Each
 * group of state tests reads the controller through its own pointer (retail rebuilds the base per group), and the
 * st 2 test's dead else (o1 = 0) ends cse's path there so the 0x84 group rebuilds it too. */

typedef struct Mob_D900 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[4];
    struct Mob_D900 *p24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0xE];
    u16 f44;
    u8 pad46[0x1D];
    u8 b63;
    u8 pad64[4];
    u8 *f68;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0xE];
    s16 oclass;
    u8 padAC[8];
    s16 hB4;
} Mob_D900;

typedef struct Ctl_D900 {
    u8 pad0[0x30];
    s32 st;
    s32 t;
    u8 pad38[0xC];
    s16 n;
    u8 pad46[0x15A];
    Mob_D900 *mobys[8];
} Ctl_D900;

typedef struct Fx_D900 {
    s16 a;
    s16 b;
    f32 c;
    f32 d;
    f32 e;
    f32 f;
    s32 col1;
    s32 col2;
    s32 count;
} Fx_D900;

typedef struct Snd_D900 {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[0x10];
    f32 f40;
    u8 pad44[4];
    s32 f48;
} Snd_D900;

extern Ctl_D900 D_L09_001E6F40;
extern Mob_D900 *D_L09_00239C70[];
extern Snd_D900 D_L09_001E2C00;
extern s32 D_001D545C;
extern vu0_v4 D_L09_001EF450[6];
extern vu0_v4 D_L09_001EF4B0[6];
extern struct { u8 pad[0x184]; u8 *p; } D_L09_00220098;
extern s32 D_L09_001D6A90;
__asm__(".extern D_L09_001D6A90, 4");
extern s32 D_L09_001D6A94[] __attribute__((section(".sdata")));
extern s32 D_L09_001D6A98[] __attribute__((section(".sdata")));
extern s32 D_L09_001D6B70;
__asm__(".extern D_L09_001D6B70, 4");
extern s32 D_L09_001D6B80;
__asm__(".extern D_L09_001D6B80, 4");
extern s16 D_L09_001D6B90[2];
__asm__(".extern D_L09_001D6B90, 4");
extern f32 D_L09_001D6B94;
extern f32 D_L09_001D6B98;
extern f32 D_L09_001D6B9C;

extern s32 func_L01_00420D88(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_003BF6A8(void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L02_003F8C58(void *, void *);
extern u8 * func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L07_003E1EA0(void *, void *, void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003A04A0(void *, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_00402498(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_004A6DF8(void *, s32);
extern Mob_D900 *func_L08_00403828(s32);
extern void func_L03_0040EE18(void *, s32);
extern void func_L09_0043A1F8(void *);
extern void func_L09_0043A5A8(void *);
extern void func_003A26D0(void);
extern void func_L01_00421438(void);

void func_L09_0043A918(void) {
    func_L01_00420D88();
    {
        Mob_D900 *m;
        s32 j;
        for (j = 0; j < D_L09_001E6F40.n; j++) {
            m = D_L09_001E6F40.mobys[j];
            if (m != 0 && m->oclass == 0xE29) {
                m->f34 |= 0x800;
            }
            if (m->oclass == 0xD54) {
                m->b63 = 0;
                {
                s32 q;
                for (q = 0; D_L09_00239C70[q] != 0; q++) {
                    if (D_L09_00239C70[q]->b63 != 0) {
                        D_L09_00239C70[q]->b63 = 1;
                    }
                }
                }
                func_003A04A0(m, 0);
                func_L01_004026A0(func_003A26D0, m);
            }
            if (m == 0) {
                continue;
            }
            if (m->oclass == 0xFA0) {
                if (m->f68 != 0) {
                    func_L01_0044EB38(m, m->f68 + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
                }
            } else if (m->oclass == 0x1DEE || m->oclass == 0x19BC) {
                func_L01_0044EB38(m, &D_L09_001D6A90, 0x80505080, 0x80404038, 0.031997703f);
            } else if (m->oclass == 0x1977) {
                func_L01_0044EB38(m, D_L09_001D6A94, 0x8080AAAA, 0x80464646, 0.03781547f);
            } else if (m->oclass == 0x1766) {
                func_L01_0044EB38(m, D_L09_001D6A98, 0x80AAAAFF, 0x80646496, 0.11053753f);
            } else if (m->oclass == 0x195B || m->oclass == 0x1B58 || m->oclass == 0x195C || m->oclass == 0x175A) {
                func_L01_00402498(func_L01_00421438, m);
            }
        }
    }
    if (D_001D545C != 9) {
        return;
    }
    {
    Ctl_D900 *c = &D_L09_001E6F40;
    Mob_D900 *o1;
    Mob_D900 *o2;
    Mob_D900 *o3;
    Mob_D900 *o4;
    Mob_D900 *o5;
    Mob_D900 *o6;
    Mob_D900 *o7;
    Mob_D900 *o8;
    if (c->st == 0) {
        Fx_D900 fx;
        vu0_v4 v20, v30, v40, v50;
        s32 i0;
        s32 k0;
        if (c->t >= 0) {
            o1 = c->mobys[3];
            if (o1 != 0) {
                func_L03_0040EE18(o1, 0);
                func_L03_0040EE18(o1, 1);
            }
        }
        {
        Ctl_D900 *c2 = &D_L09_001E6F40;
        if (c2->t == 0x15E) {
            f32 r = func_0037E250(0.1f, 0.2f);
            D_L09_001E2C00.f40 = r;
            D_L09_001E2C00.f48 = 0x3C;
            D_L09_001E2C00.f2C = 0;
        }
        if ((u32)(c2->t - 0x15E) < 0x3D) {
            o2 = c2->mobys[5];
            fx.col1 = 0xC0507080;
            fx.col2 = 0x253040;
            fx.a = 0x78;
            fx.b = 0x3C;
            fx.count = 5;
            fx.c = 150.0f;
            fx.d = 130.0f;
            fx.e = 0.008333334f;
            func_L02_003F8C58(o2, &v50);
            *(vu0_q *)&v40 = *(vu0_q *)&o2->pos;
            for (i0 = 0; i0 < fx.count; i0++) {
                vu0_v4 *p20 = &v20;
                vu0_v4 *p30 = &v30;
                v30.x = func_0037E250(-2.3f, 2.3f);
                v30.y = func_0037E250(-2.3f, 2.3f);
                v30.z = 0.0f;
                vec_add_ab(&v30, &v40, &v30);
                func_003886E8(p20, &v50, 0.083333336f);
                func_003BF6A8(p20, fx.e);
                k0 = func_0037E1D8(fx.b);
                func_L01_00460318(p30, p20, fx.col1, fx.col2, fx.a + k0, (s32)fx.d, (s32)fx.c, 0);
            }
        }
        }
    } else if (c->st == 1) {
        if (c->t >= 0) {
            o3 = c->mobys[3];
            if (o3 != 0) {
                func_L03_0040EE18(o3, 0);
                func_L03_0040EE18(o3, 1);
            }
        }
        {
        Ctl_D900 *c2 = &D_L09_001E6F40;
        if (c2->t == 1) {
            o4 = func_L08_00403828(0x1A46);
            if (o4 != 0) {
                o4->f34 &= 0xFFBE;
                o4->f34 |= o4->p24->f44 & 0x1000;
                o4->f98 = *(s32 *)((u8 *)o4->p24 + 0x10);
            }
            o5 = func_L08_00403828(0x1A42);
            if (o5 != 0) {
                o5->f34 &= 0xFFBE;
                o5->f34 |= o5->p24->f44 & 0x1000;
                o5->f98 = *(s32 *)((u8 *)o5->p24 + 0x10);
            }
        }
        }
        {
        Ctl_D900 *c3 = &D_L09_001E6F40;
        s32 t = c3->t;
        if ((u32)(t - 0xDC) < 0x1F && t % 5 == 0) {
            Mob_D900 *a = c3->mobys[4];
            Mob_D900 *b = func_L08_00403828(0x1A46);
            vu0_v4 v0, v10, v20, v30, v40, v50, d, v70;
            if (a != 0 && b != 0) {
                func_L02_003F8C58(a, &v30);
                func_003888C8(&v20, &D_L09_001D6B70, &v30);
                vec_add_ab(&v0, &v20, &a->pos);
                vec_sub_ba(&v10, &b->pos, &a->pos);
                func_00388830(&v10, &v10, 3.6666667f);
                func_003BF6A8(&v10, 0.033333335f);
                func_L07_003E1EA0(0, &v0, &v10, 1, 0x50, 3, 1.0f, 3.0f, 0.0f);
                if (c3->t == 0xDC) {
                    s32 kb;
                    vec_sub_ba(&d, &a->pos, &b->pos);
                    for (kb = 0; kb < 6; kb++) {
                        *(vu0_q *)&D_L09_001EF450[kb] = *(vu0_q *)&b->pos;
                        *(vu0_q *)&D_L09_001EF4B0[kb] = *(vu0_q *)&d;
                        func_00388830(&D_L09_001EF4B0[kb], &D_L09_001EF4B0[kb], 1.6f);
                        func_003BF6A8(&D_L09_001EF4B0[kb], 0.8f);
                    }
                }
            }
        }
        }
        {
        Ctl_D900 *c4 = &D_L09_001E6F40;
        if (c4->t == 0x113) {
            f32 r = func_0037E250(0.1f, 0.2f);
            D_L09_001E2C00.f48 = 0x28;
            D_L09_001E2C00.f40 = r;
            D_L09_001E2C00.f2C = 0;
            o6 = func_L08_00403828(0x1A46);
            if (o6 != 0) {
                o6->f98 = 0;
                o6->f34 = (o6->f34 | 0x41) & 0xEFFF;
                func_L01_004A6DF8(o6, 1);
            }
            o7 = func_L08_00403828(0x1A42);
            if (o7 != 0) {
                o7->f98 = 0;
                o7->f34 = (o7->f34 | 0x41) & 0xEFFF;
                func_L01_004A6DF8(o7, 1);
            }
        }
        }
        {
        Ctl_D900 *c5 = &D_L09_001E6F40;
        s32 t = c5->t;
        if ((u32)(t - 0x113) < 0x29) {
            f32 sc = (f32)(0x13B - t) * 0.4f / 40.0f;
            vu0_v4 v0;
            s32 ie;
            for (ie = 0; ie < 6; ie++) {
                if (func_0037E1D8(1) == 0) {
                    f32 rr = func_0037E250(0.0f, 20.0f);
                    s32 n;
                    s32 dir;
                    u8 *p;
                    qzero(&v0);
                    func_003BF6A8(&v0, D_L09_001D6B9C * 0.016666668f);
                    n = func_0037E250((f32)D_L09_001D6B90[1], (f32)D_L09_001D6B90[0]);
                    dir = func_0037E208(-1, 1);
                    p = func_L01_00472438(&D_L09_001EF450[ie], &v0, n, dir, 0x7F407FFF, 0x407FFF,
                                          sc * (D_L09_001D6B98 + rr) * 210000.0f, sc * (D_L09_001D6B94 + rr) * 210000.0f, 0.0f, 0);
                    if (p != 0) {
                        p[9] = 0xF2;
                        p[2] = D_L09_00220098.p[3];
                    }
                }
                vec_add_ab(&D_L09_001EF450[ie], &D_L09_001EF450[ie], &D_L09_001EF4B0[ie]);
            }
        }
        }
        {
        Ctl_D900 *c6 = &D_L09_001E6F40;
        if ((u32)(c6->t - 0x15A) < 0xE) {
            Fx_D900 fx;
            vu0_v4 v20, v30;
            s32 i8, k8;
            fx.col1 = 0x60505570;
            fx.col2 = 0x202020;
            fx.a = 0x12C;
            fx.b = 0xC8;
            fx.count = 5;
            fx.c = 400.0f;
            fx.d = 300.0f;
            fx.e = 0.025000002f;
            fx.f = 0.010000001f;
            o8 = func_L08_00403828(0x1A46);
            for (i8 = 0; i8 < fx.count; i8++) {
                vu0_v4 *q20 = &v20;
                vu0_v4 *q30 = &v30;
                *(vu0_q *)&v20 = *(vu0_q *)&o8->pos;
                func_003BF6A8(q20, 5.0f);
                v30.x = func_0037E250(-fx.f, fx.f);
                v30.y = func_0037E250(-fx.f, fx.f);
                v30.z = func_0037E250(fx.f, fx.e);
                k8 = func_0037E1D8(fx.b);
                func_L01_00460318(q20, q30, fx.col1, fx.col2, fx.a + k8, (s32)fx.d, (s32)fx.c, 0);
            }
        }
        }
    } else if (c->st == 2) {
        if (c->t == 0x94) {
            vu0_v4 v0, off;
            *(vu0_q *)&off = 0;
            off.x = -0.2f;
            off.y = -0.2f;
            off.z = -0.1f;
            vec_add_ab(&v0, &c->mobys[3]->pos, &off);
            func_L09_0043A1F8(&v0);
            *(vu0_q *)&D_L09_001D6B80 = *(vu0_q *)&v0;
        } else {
            o1 = 0;
        }
        {
        Ctl_D900 *c2 = &D_L09_001E6F40;
        if ((u32)(c2->t - 0x9E) < 0x29) {
            func_L09_0043A5A8(&D_L09_001D6B80);
        }
        }
    } else if (c->st == 3) {
        s32 i3;
        for (i3 = 0; i3 < D_L09_001E6F40.n; i3++) {
            D_L09_001E6F40.mobys[i3]->hB4 = 1;
        }
    }
    }
}
/* localdecomp:end func_L09_0043A918 */
