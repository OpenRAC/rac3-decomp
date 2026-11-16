#include "common.h"

/* NTSC-U counterpart of func_L27_003A1B30 (src/levels/27_aquatos_base/L27_003A1250.c) */
#include "vu0.h"
extern u8 D_001A30B0[];
extern void func_0039FB08(s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L27_003A02B8(u8 *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L27_004CD958(s32, s32);
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003C2868(void *);

/* localdecomp:start func_L27_003A02B8 */

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1B30;
typedef union {
    u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80];
    f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0];
} Hero_3A1B30;
typedef struct { u8 p00[0xAA]; s16 hAA; } S_HOBJ_3A1B30;
typedef struct { s32 f0; u8 p04[8]; s32 fC; u8 p10[0x490]; s32 f4A0; } S_M68_3A1B30;
typedef struct {
    u8 p00[0x10];
    V4_3A1B30 pos;
    u8 b20;
    u8 p21[0x47];
    S_M68_3A1B30 *f68;
    u8 p6C[0x84];
    V4_3A1B30 vF0;
} S_MOB_3A1B30;
typedef struct {
    s32 f0, f4, f8; u8 p0C[0x18]; s32 f24; u8 p28[0xC]; s32 f34; u8 p38[4]; s32 f3C;
    u8 p40[0x28]; s32 f68; s32 f6C; f32 f70; s32 f74; s32 f78; s32 f7C; V4_3A1B30 v80;
    s32 f90, f94, f98, f9C, fA0; u8 pA4[0x20]; s32 fC4, fC8, fCC, fD0, fD4; u8 pD8[4];
    s32 fDC, fE0, fE4, fE8; u8 pEC[8]; s32 fF4, fF8, fFC; u8 p100[0x18];
    s32 f118, f11C, f120, f124, f128;
} S_D_3A1B30;
typedef struct { u8 p00[0x20]; u8 b20; u8 p21[0x47]; S_D_3A1B30 *f68; } S_SELF_3A1B30;
typedef struct { u8 p0[0xD0]; u8 bD0; u8 pD1[0xB]; void *fDC; } S_G7_3A1B30;
typedef struct { u8 p00[0x30]; V4_3A1B30 v30; u8 p40[0x30]; V4_3A1B30 v70; } S_DEE_3A1B30;

extern Hero_3A1B30 D_001A4BE0;
extern u8 *D_001DED1C_sda_003A02B8;
__asm__(".extern D_001DED1C_sda_003A02B8, 4");
extern S_MOB_3A1B30 *D_L27_001DED1C_003A02B8;
__asm__(".extern D_L27_001DED1C_003A02B8, 16");
extern S_DEE_3A1B30 *D_L27_001DEE00_003A02B8;
__asm__(".extern D_L27_001DEE00_003A02B8, 16");
extern u8 D_001A30B0[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 D_001A818C[4];
extern u8 D_L27_001E1600_003A02B8[];
extern s32 func_L01_00452EF0(void *);
extern void func_L27_003A1590();
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_00417F60(s32, s32);
extern f32 func_00388A28(f32, f32);
extern void func_L22_003B5AA0(void *, f32, void *, s32);

extern void func_L27_0039DEA0(void *);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003E94A0(s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L01_00452F60(void *);

extern void func_003C2868(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_003E9510(s32, void *);
extern void func_L01_00438430(s32);
extern void func_L01_00441FB8(void *, s32, s32);


void func_L27_003A02B8(u8 *pself) {
    S_SELF_3A1B30 *self = (S_SELF_3A1B30 *)pself;
    S_D_3A1B30 *d = self->f68;
    S_MOB_3A1B30 *m, *o0, *o4;
    S_G7_3A1B30 *g;
    V4_3A1B30 a, b, c;
    f32 x, t, u;

    if (func_L01_00452EF0(self) != 0) {
        func_L27_003A1590(self);
        d->fDC = 0;
    }
    if (d->f6C == 0) {
        if ((d->fC4 == -1 || ((S_MOB_3A1B30 *)((d->fC4 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fC4 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD) ||
            (d->fC8 == -1 || ((S_MOB_3A1B30 *)((d->fC8 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fC8 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD) ||
            (d->fCC == -1 || ((S_MOB_3A1B30 *)((d->fCC << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fCC << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD) ||
            (d->fD0 == -1 || ((S_MOB_3A1B30 *)((d->fD0 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fD0 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD) ||
            (d->f7C == -1 || ((S_MOB_3A1B30 *)((d->f7C << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->f7C << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD) ||
            (d->fD4 == -1 || ((S_MOB_3A1B30 *)((d->fD4 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fD4 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD) ||
            (d->f98 == -1 || ((S_MOB_3A1B30 *)((d->f98 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->f98 << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD) ||
            (d->f9C == -1 || ((S_MOB_3A1B30 *)((d->f9C << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->f9C << 8) + (s32)D_001DED1C_sda_003A02B8))->b20 == 0xFD))
            d->f6C = 1;
    }
    if (func_L01_00453210(&D_001A4BE0.i[0x20], d->f8) == 0) {
        if ((D_001BBC40[d->f34 + (D_001D545C << 4)] & 0x80) == 0) {
            if (((S_HOBJ_3A1B30 *)D_001A4BE0.ptr[0x970])->hAA != 0x1A4E &&
                D_001A4BE0.i[0x973] != 0x14 && D_001A4BE0.i[0x973] != 0x19 && D_001A818C[0] >= 0) {
                func_L01_00417F60(0xBA6, 0x49);
            }
        }
    }
    if (D_L27_001DED1C_003A02B8[d->fE0].f68->fC == 0) {
        s32 i = d->fC4;
        if (i != -1 && D_L27_001DED1C_003A02B8[i].b20 != 0xFE && D_L27_001DED1C_003A02B8[i].b20 != 0xFD &&
            D_L27_001DED1C_003A02B8[i].f68->f4A0 > 0) {
            a = D_L27_001DED1C_003A02B8[d->f118].pos;
            func_L22_003B5AA0(&D_L27_001DED1C_003A02B8[i],
                func_00388A28(((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.x - D_L27_001DED1C_003A02B8[d->f118].pos.x,
                              ((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.y - D_L27_001DED1C_003A02B8[d->f118].pos.y), &a, 0);
        }
    }
    D_L27_001DED1C_003A02B8[d->fE0].f68->fC = D_L27_001DED1C_003A02B8[d->f118].f68->f0;

    if (D_L27_001DED1C_003A02B8[d->fE4].f68->fC == 0) {
        s32 i = d->fCC;
        if (i != -1 && D_L27_001DED1C_003A02B8[i].b20 != 0xFE && D_L27_001DED1C_003A02B8[i].b20 != 0xFD &&
            D_L27_001DED1C_003A02B8[i].f68->f4A0 > 0) {
            a = D_L27_001DED1C_003A02B8[d->f11C].pos;
            func_L22_003B5AA0(&D_L27_001DED1C_003A02B8[i],
                func_00388A28(((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.x - D_L27_001DED1C_003A02B8[d->f11C].pos.x,
                              ((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.y - D_L27_001DED1C_003A02B8[d->f11C].pos.y), &a, 0);
        }
    }
    D_L27_001DED1C_003A02B8[d->fE4].f68->fC = D_L27_001DED1C_003A02B8[d->f11C].f68->f0;

    if (D_L27_001DED1C_003A02B8[d->fE8].f68->fC == 0) {
        s32 i = d->fD4;
        if (i != -1 && D_L27_001DED1C_003A02B8[i].b20 != 0xFE && D_L27_001DED1C_003A02B8[i].b20 != 0xFD &&
            D_L27_001DED1C_003A02B8[i].f68->f4A0 > 0) {
            a = D_L27_001DED1C_003A02B8[d->f120].pos;
            func_L22_003B5AA0(&D_L27_001DED1C_003A02B8[i],
                func_00388A28(((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.x - D_L27_001DED1C_003A02B8[d->f120].pos.x,
                              ((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.y - D_L27_001DED1C_003A02B8[d->f120].pos.y), &a, 0);
        }
    }
    D_L27_001DED1C_003A02B8[d->fE8].f68->fC = D_L27_001DED1C_003A02B8[d->f120].f68->f0;
    D_L27_001DED1C_003A02B8[d->fF4].f68->fC = D_L27_001DED1C_003A02B8[d->f124].f68->f0;
    D_L27_001DED1C_003A02B8[d->fF8].f68->fC = 1;
    D_L27_001DED1C_003A02B8[d->fFC].f68->fC = D_L27_001DED1C_003A02B8[d->f128].f68->f0;

    if (d->f74 == 0) {
        if (d->f7C != -1 && D_L27_001DED1C_003A02B8[d->f7C].b20 != 0xFE &&
            D_L27_001DED1C_003A02B8[d->f7C].b20 != 0xFD && D_L27_001DED1C_003A02B8[d->f7C].f68->f4A0 > 0) {
            m = &D_L27_001DED1C_003A02B8[d->f90];
            if (D_001A4BE0.i[0x971] != 0x74 && D_001A4BE0.i[0x971] != 0x58) {
                if (((S_HOBJ_3A1B30 *)D_001A4BE0.ptr[0x970])->hAA == 0x1A4E) {
                    func_L27_004CD958(0x58, 0);
                } else {
                    func_L27_004CD958(0x74, 0);
                }
                func_L27_0039DEA0(&D_L27_001DED1C_003A02B8[d->f7C]);
                func_L01_003E9588(0, D_L27_001E1600_003A02B8, D_L27_001E1600_003A02B8 + 0x10, 0, 0, 0);
                func_L01_003E94A0(0, &D_L27_001DEE00_003A02B8[d->f94].v30);
                d->f70 = 0;
                o0 = &D_L27_001DED1C_003A02B8[d->f0];
                o4 = &D_L27_001DED1C_003A02B8[d->f4];
                *(u128_t *)&o0->pos = *(u128_t *)&D_L27_001DEE00_003A02B8[d->f78].v30;
                *(u128_t *)&o0->vF0 = *(u128_t *)&D_L27_001DEE00_003A02B8[d->f78].v70;
                func_003BE4F0(o0, 0x14, 0, 5);
                a.x = -func_00388960(o0->vF0.z);
                a.y = -func_00388978(o0->vF0.z);
                a.z = 0;
                a.w = 1.0f;
                vec_add_ab(&o4->pos, &o0->pos, &a);
                o4->vF0 = o0->vF0;
            }
            if (func_L01_00452F60(&D_L27_001DED1C_003A02B8[d->f7C]) != 0) {
                x = d->f70 + 1.0f;
                d->f70 = x;
                t = x / 300.0f;
                u = t > 1.0f ? 1.0f : t;
                a = d->v80;
                a.z = a.z + -15.0f;
                b = d->v80;
                vec_sub_ba(&c, &b, &a);
                func_003886E8(&c, &c, u);
                vec_add_ab(&m->pos, &c, &a);
                func_003C2868(m);
                {
                s32 i = d->f24;
                if (i == -1 || ((S_G7_3A1B30 *)(D_001A30B0 + (i << 7)))->fDC != m ||
                    ((S_G7_3A1B30 *)(D_001A30B0 + (i << 7)))->bD0 == 0) {
                    d->f24 = func_0039FE80(0, 4, m);
                }
                }
                if (u >= 1.0f) {
                    s32 i;
                    d->f74 = 1;
                    i = d->f24;
                    if (i != -1) {
                        g = (S_G7_3A1B30 *)(D_001A30B0 + (i << 7));
                        if (g->fDC == m && g->bD0 != 0) func_0039FB08(i);
                    }
                    d->f24 = -1;
                }
            }
            a.x = 0;
            a.y = -func_00388A28(func_00388800(&D_L27_001DEE00_003A02B8[d->f94].v30, &m->pos),
                                 m->pos.z - D_L27_001DEE00_003A02B8[d->f94].v30.z);
            a.z = func_00388A28(m->pos.x - D_L27_001DEE00_003A02B8[d->f94].v30.x,
                                m->pos.y - D_L27_001DEE00_003A02B8[d->f94].v30.y);
            func_L01_003E9510(0, &a);
        }
    }
    if (D_L27_001DED1C_003A02B8[d->fA0].f68->f0 == 0) {
        if (d->f98 != -1 && D_L27_001DED1C_003A02B8[d->f98].b20 != 0xFE &&
            D_L27_001DED1C_003A02B8[d->f98].b20 != 0xFD && D_L27_001DED1C_003A02B8[d->f98].f68->f4A0 > 0) {
            if (func_L01_00452F60(&D_L27_001DED1C_003A02B8[d->f98]) == 0) {
                func_L27_0039DEA0(&D_L27_001DED1C_003A02B8[d->f98]);
            } else {
                D_L27_001DED1C_003A02B8[d->fA0].f68->f0 = 1;
            }
        }
    }
    if (d->f74 != 0) {
        if (self->b20 == 5) {
            func_L01_00438430(d->f34);
            D_L27_001DED1C_003A02B8[d->f90].pos = d->v80;
            func_L01_00441FB8(self, 6, 2);
        }
    }
    if (func_0037E0F0(&D_001A4BE0.i[0x20], d->f68, 0) != 0) {
        func_L01_00438430(d->f3C);
        func_L01_00441FB8(self, 3, 0);
    }
}
/* localdecomp:end func_L27_003A02B8 */
