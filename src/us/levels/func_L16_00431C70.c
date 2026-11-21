#include "common.h"

/* NTSC-U counterpart of func_L16_00434C98 (src/levels/16_kerwan/L16_00434C98.c) */
/* localdecomp:start func_L16_00431C70 */
#include "vu0.h"

typedef struct Mob_434C98 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x14];
    u16 f34;
    u8 pad36[0x2D];
    u8 b63;
    u8 pad64[4];
    u8 *f68;
    u8 pad6C[0x3E];
    s16 oclass;
} Mob_434C98;

typedef struct Ctl_434C98 {
    u8 pad0[0x30];
    s32 st;
    s32 t;
    u8 pad38[0xC];
    s16 n;
    u8 pad46[0x15A];
    Mob_434C98 *mobys[8];
} Ctl_434C98;

typedef struct V4_434C98 { f32 x, y, z, w; } __attribute__((aligned(16))) V4_434C98;

extern Ctl_434C98 D_L16_001E6EC0_00431C70;
extern Mob_434C98 *D_L16_0023A2B0_00431C70[];
extern s32 D_001D545C;
extern u8 D_L16_001E2B20[];
extern f32 D_L16_001D6AE0_00431C70;
__asm__(".extern D_L16_001D6AE0_00431C70, 4");
extern f32 D_L16_001D6AE4_00431C70;
extern f32 D_L16_001D6AE8_00431C70;
extern f32 D_L16_001D6AEC_00431C70;
extern s32 D_L16_001D6C48_00431C70;
__asm__(".extern D_L16_001D6C48_00431C70, 4");
extern s32 D_L16_001D6C88_00431C70;
__asm__(".extern D_L16_001D6C88_00431C70, 4");
extern u8 D_L16_001EFAB0_00431C70[];
extern u8 D_L16_001EF3D0_00431C70[];

extern s32 func_L01_00420D88(void);
extern void func_L01_004210C0(void);
extern void func_L01_00420F18(void *, f32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003A04A0(void *, s32);
extern void func_003A26D0(void);
extern void func_L01_00421438(void);
extern void func_L01_00402498(void *, void *);
extern void func_L01_00402560(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern Mob_434C98 *func_L08_00403828(s32);
extern void func_L08_004038A8(void *, s32, s32, s32, f32, f32, f32);
extern void func_L08_00403E80(s32, void *, s32, s32, s32, s32, s32, s32, f32, f32, s32);
extern u8 *func_L10_00403490(s32);
extern void func_L03_0040E698(s32, s32);
extern void func_L03_0040EB30(void *, s32, s32, s32);
extern void func_L16_00431280(void);
extern void func_L16_00431590(void *, V4_434C98 *, V4_434C98 *, V4_434C98 *, s32);
extern void func_L16_00431910(void *);
extern void func_L16_004319D8(void);
extern void func_L16_00431A28(void *, void *);
extern void func_L16_00431A50(u8 *, vu0_v4 *, vu0_v4 *, u8 *, s32);
extern void func_L16_00431AC0(void);
extern void func_L16_00431B48(void *);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_004D4108(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0032FE90_00431C70(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L16_00431C70(void) {
    func_L01_00420D88();
    {
        Mob_434C98 *m;
        s32 j;
        for (j = 0; j < D_L16_001E6EC0_00431C70.n; j++) {
            m = D_L16_001E6EC0_00431C70.mobys[j];
            if (m != 0 && m->oclass == 0xE29) {
                m->f34 |= 0x800;
            }
            if (m->oclass == 0xD54) {
                m->b63 = 0;
                {
                s32 q;
                for (q = 0; D_L16_0023A2B0_00431C70[q] != 0; q++) {
                    if (D_L16_0023A2B0_00431C70[q]->b63 != 0) {
                        D_L16_0023A2B0_00431C70[q]->b63 = 1;
                    }
                }
                }
                func_003A04A0(m, 0);
                func_L01_00402560(func_003A26D0, m);
            }
            if (m == 0) {
                continue;
            }
            if (m->oclass == 0xFA0) {
                if (m->f68 != 0) {
                    func_L01_0044EB38(m, m->f68 + 0xC, 0x80AAAAD2, 0x80396464, 0.06108652800321579f);
                }
            } else if (m->oclass == 0x1DEE || m->oclass == 0x19BC) {
                func_L01_0044EB38(m, &D_L16_001D6AE0_00431C70, 0x80505080, 0x80404038, 0.03199770301580429f);
            } else if (m->oclass == 0x1977) {
                func_L01_0044EB38(m, &D_L16_001D6AE4_00431C70, 0x8080AAAA, 0x80464646, 0.03781547024846077f);
            } else if (m->oclass == 0x1766) {
                func_L01_0044EB38(m, &D_L16_001D6AE8_00431C70, 0x80AAAAFF, 0x80646496, 0.11053752899169922f);
            } else if (m->oclass == 0x195B || m->oclass == 0x1B58 || m->oclass == 0x195C || m->oclass == 0x175A) {
                func_L01_00402498(func_L01_00421438, m);
            }
        }
    }
    {
        Mob_434C98 *o = func_L08_00403828(0x1EFD);
        if (o != 0) {
            func_L01_0044EB38(o, &D_L16_001D6AEC_00431C70, -0x191A, -0x7374, 0.033452145755290985f);
        }
    }
    if (D_001D545C != 0x10) {
        return;
    }
    {
    Ctl_434C98 *c = &D_L16_001E6EC0_00431C70;
    V4_434C98 v90, va0, vb0, vc0, vd0, ve0;
    if (c->st == 0) {
        func_L01_004210C0();
        if (c->st == 0 && c->t < 0x1F5) {
            f32 f20 = 5.0f;
            u8 *s0 = D_L16_001E2B20;
            func_00388830(&v90, s0, f20);
            v90.z += f20;
            if (func_0037E1D8(2) == 0) {
                func_00388830(&va0, s0 + 0x10, -15.0f);
                func_00388830(&vb0, s0 + 0x10, -25.0f);
            } else {
                func_00388830(&va0, s0 + 0x10, 15.0f);
                func_00388830(&vb0, s0 + 0x10, 25.0f);
            }
            if (func_0037E1D8(5) == 0) {
                func_L16_00431590(D_L16_001E6EC0_00431C70.mobys[0], &v90, &va0, &vb0, func_0037E1D8(2) + 2);
            }
            if (D_L16_001E6EC0_00431C70.t % 20 == 0) {
                if (func_0037E1D8(4) == 0) {
                    *(vu0_q *)&vc0 = 0;
                    vc0.x = 18.0f;
                    vc0.z = -2.0f;
                    func_L01_00420F18(&vc0, 8.0f, 0.5f, 2.0f);
                }
            }
        }
        func_L03_0040E698(0x66, 0x190);
        func_L16_00431280();
    } else if (c->st == 1) {
        *(vu0_q *)&v90 = 0;
        *(vu0_q *)&va0 = 0;
        v90.z = 15.0f;
        va0.z = 2.0f;
        func_L16_00431280();
        if (c->t == 1) {
            D_L16_001D6C88_00431C70 = 0x730;
        }
        if (c->t == 0xF91) {
            func_L16_00431910(c->mobys[6]);
        }
        func_L03_0040EB30(c->mobys[4], 0xC8, 0x40400000, 0x40404040);
        if (c->t == 0xFA5 || c->t == 0xFB4) {
            qzero(&vd0);
            vd0.z += 1.0f;
            vec_add_ab(&vd0, (u8 *)c->mobys[7] + 0x10, &vd0);
        }
        {
        Ctl_434C98 *c2 = &D_L16_001E6EC0_00431C70;
        s32 t2 = c2->t;
        if ((u32)(t2 - 0xF91) < 0x24) {
            s32 i;
            func_L16_00431A28(c2->mobys[7], &va0);
            for (i = 0; i < 10; i++) {
                *(vu0_q *)&ve0 = *(vu0_q *)(D_L16_001EFAB0_00431C70 + i * 0x10);
                func_L16_00431A50((u8 *)D_L16_001E6EC0_00431C70.mobys[6], (vu0_v4 *)&v90, (vu0_v4 *)&ve0, D_L16_001EF3D0_00431C70 + i * 0xB0, (s32)&D_L16_001D6C48_00431C70);
                func_L01_00402498(func_L16_004319D8, 0);
            }
        }
        }
        {
        Ctl_434C98 *c3 = &D_L16_001E6EC0_00431C70;
        s32 t = c3->t;
        if ((u32)(t - 0x730) < 0x10 || (u32)(t - 0xE10) < 0x10) {
            if (t == 0xE10) {
                D_L16_001D6C88_00431C70 = t;
            }
            func_L16_00431B48(c3->mobys[5]);
            func_L01_00402498(func_L16_00431AC0, 0);
        }
        }
        {
        Ctl_434C98 *c4 = &D_L16_001E6EC0_00431C70;
        s32 t = c4->t;
        if (t == 0xFA5) {
            s32 k;
            for (k = 0; k < 100; k++) {
                f32 a, b, r, s;
                vb0 = vd0;
                a = (f32)func_0037E1D8(0x168) * 0.017453292f;
                b = (f32)func_0037E1D8(0x168) * 0.017453292f;
                r = func_00388978(b);
                ve0.x = r * 3.0f * func_00388960(a);
                ve0.y = r * 3.0f * func_00388978(a);
                ve0.z = func_00388960(b) * 3.0f;
                func_00388830(&vc0, &ve0, -0.1f);
                vec_add_ab(&vb0, &ve0, &vb0);
                s = func_0037E250(0.5f, 0.7f);
                func_L01_00468DC0(&vb0, &vc0, 0x80802010, s, 0x1E, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
            }
        } else if (t == 0xFB4) {
            vd0.x += 0.0f;
            vd0.y += -2.0f;
            func_L08_004038A8(c4->mobys[7], 0x80802010, 0x80802010, 0xA, 4.0f, 8.0f, 3.0f);
        }
        }
    } else if (c->st == 2) {
        if (c->t == 0xEF6) {
            V4_434C98 *pv = &v90;
            f32 one = 1.0f;
            qzero(&v90);
            v90.z += 2.0f;
            func_L08_00403E80(3, pv, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, one, one, 0x80204080);
            qzero(&v90);
            v90.z += one;
            func_L08_00403E80(4, pv, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, one, one, 0x80204080);
        }
        func_L03_0040E698(0x4A6, 0xF36);
        {
            u8 *o = func_L10_00403490(0x1F85);
            if (o != 0) {
                func_L01_004D4108(o, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
            }
        }
    } else if (c->st == 3) {
        if (c->t == 0x3E) {
            u8 *o = (u8 *)c->mobys[2];
            if (o != 0) {
                    v90 = *(V4_434C98 *)(o + 0x10);
                func_L01_0032FE90_00431C70(&v90, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.5f, 0.0f, 0.0f, 2.0f,
                                  1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                                  0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
        }
    }
    }
}
/* localdecomp:end func_L16_00431C70 */
