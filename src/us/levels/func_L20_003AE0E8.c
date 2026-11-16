#include "common.h"

/* NTSC-U counterpart of func_L20_003AF880 (src/levels/20_final_boss/L20_003AF880.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Mo_ *mp[0x40]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x400]; s8 c[0x400]; s16 h[0x200]; u16 uh[0x200]; s32 i[0x100]; u32 u[0x100]; f32 f[0x100]; void *p[0x100]; Mo *mp[0x100]; u128_t q[0x40]; } Pv;
typedef union { f32 f[4]; s32 i[4]; u128_t q; } __attribute__((aligned(16))) V4;
typedef struct { V4 pos; V4 dir; f32 f20[16]; } Beam;
typedef union { u8 b[0x3000]; s16 h[0x1800]; s32 i[0xC00]; f32 f[0xC00]; } GBig;
typedef union { u8 *p[0x100]; } PtrTab;
typedef struct { u8 pad[0xD0]; u8 on; u8 pad1[0xB]; union Mo_ *owner; } Chan;

/* localdecomp:start func_L20_003AE0E8 */
/* Per-frame update for the final boss and its two arm mobys. */
#include "vu0.h"
static __inline__ void vec_add_bt(void *d, void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qa));
}

extern GBig D_001A4BE0;
extern GBig D_001CCFD0;
__asm__(".extern D_001A4BE0, 16");
__asm__(".extern D_001CCFD0, 16");
extern Mo *D_L20_001E029C_003AE0E8;
extern f32 D_L20_001DFB50_003AE0E8;
extern GBig D_L20_001E2E80_003AE0E8;
__asm__(".extern D_L20_001E2E80_003AE0E8, 16");
extern char D_L20_001E9980_003AE0E8[];
extern Beam D_L20_002C5280_003AE0E8;
extern char D_L20_001D66B0_003AE0E8[] __attribute__((section(".sdata")));
extern u8 *D_L20_002203C8_003AE0E8[];

extern PtrTab D_L20_00220258_003AE0E8;
__asm__(".extern D_L20_00220258_003AE0E8, 16");
extern u8 *func_0037E0B8(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_0038E2E8();
extern s32 func_0038E440(void *);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_0039C710(void);
extern void func_0039DAE0(s32, s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BD360(void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BEB58(void *, void *, void *, f32);
extern void func_003C23E8(void *, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_0032FE90_003AE0E8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00356108(void *);
extern void func_L01_003AFB80(void *);
extern void func_L01_003B05E8(void *);
extern void func_L01_00402498(void *, void *);
extern f32 func_L01_00436500(void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00440A88(f32 *, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_L01_00444740(f32 *, f32 *, f32 *, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00458A08(void *, f32);
extern u8 *func_L01_00466F98(void *, f32, void *, s32, s32, s32, s32, f32, f32, f32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_004B6C68(void);
extern s32 func_L03_004307B8(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L07_003E1EA0(void *, void *, void *, s32, s32, s32, f32, f32, f32);
extern s32 func_L20_003B0688();
extern void func_L20_003B0CE0(s32);
extern void func_L20_003B0D20(u8 *);
extern void func_L20_003B0E48(void *, s32, s32, s32);
extern void func_L20_004002F8(void *);

extern Chan D_001A30B0;
__asm__(".extern D_001A30B0, 16");
extern s32 D_L20_001DFD40_003AE0E8;
extern s32 D_L20_001E9BD8_003AE0E8[];
extern f32 D_L20_001DE338;
extern f32 D_L20_001DE33C;
extern f32 D_L20_001DE340;
__asm__(".extern D_L20_001DE338, 4");
__asm__(".extern D_L20_001DE33C, 4");
__asm__(".extern D_L20_001DE340, 4");
extern void func_L20_003B0EC8(void);
extern void func_L20_003B1190(void);
extern void func_L20_003F0138(void *, void *, void *, void *);
extern void func_L20_003F0748(void *, void *, void *, s32, f32, f32);
extern void func_L20_003F21E8(void *, f32, f32);



#define SND(h) ((Chan *)((u8 *)&D_001A30B0 + (h) * 0x80))


void func_L20_003AE0E8(Mo *m) {
    Pv *pv = m->p[0x68 / 4];
    s32 flag;
    V4 v90, vA0;
    union {
        Beam b;
        struct { V4 b0, c0, d0, e0, f0, x100; } s;
    } u;
    V4 v110[4];
    V4 v150;
    s32 n;
    u8 *pp;

    if (func_L20_003B0688() != 0) {
        func_003BD360(m);
        return;
    }
    flag = 0;
    if (D_001A4BE0.i[0x19E0 / 4] != 0) {
        f32 *p = (f32 *)func_0037E0B8((void *)D_001A4BE0.i[0x19E0 / 4]);
        if (p != 0) {
            f32 f = *p;
            if (pv->f[0x394 / 4] != f) {
                if (f < pv->f[0x394 / 4]) {
                    flag = 1;
                }
                pv->f[0x394 / 4] = f;
            }
        }
    } else {
        pv->f[0x394 / 4] = 0.0f;
    }
    if ((flag != 0) || ((D_001A4BE0.i[0x2808 / 4] != 0) && (D_001A4BE0.i[0x19E0 / 4] == 0))) {
        if ((func_0037E1D8(10) == 0) && (m->b[0x95] == 2)) {
            func_L01_003B05E8(m);
        }
    }
    switch (m->b[0x95]) {
    case 5:
        if (func_L01_004B6C68() == 0) {
            func_0039BEC0(9, 1, 0, 0, 0);
        }
        break;
    case 4:
        if (func_L01_00452F60(m) != 0) {
            Mo *c;
            func_L20_003B0E48(m, 2, 0, 0);
            c = m->mp[0x24 / 4];
            m->uh[0x34 / 2] &= 0xFFBE;
            m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
            m->i[0x98 / 4] = c->i[0x10 / 4];
            pv->mp[0x2E4 / 4]->uh[0x34 / 2] &= 0xFFBE;
            pv->mp[0x2E4 / 4]->uh[0x34 / 2] |= pv->mp[0x2E4 / 4]->mp[0x24 / 4]->uh[0x44 / 2] & 0x1000;
            pv->mp[0x2E4 / 4]->i[0x98 / 4] = pv->mp[0x2E4 / 4]->mp[0x24 / 4]->i[0x10 / 4];
            pv->mp[0x2E0 / 4]->uh[0x34 / 2] &= 0xFFBE;
            pv->mp[0x2E0 / 4]->uh[0x34 / 2] |= pv->mp[0x2E0 / 4]->mp[0x24 / 4]->uh[0x44 / 2] & 0x1000;
            pv->mp[0x2E0 / 4]->i[0x98 / 4] = pv->mp[0x2E0 / 4]->mp[0x24 / 4]->i[0x10 / 4];
            func_L01_00441FB8(m, 3, 2);
        }
        break;
    case 0:
        func_L01_00458A08(m, func_00388A28(D_001A4BE0.f[0x80 / 4] - m->f[0x10 / 4], D_001A4BE0.f[0x84 / 4] - m->f[0x14 / 4]));
        if (func_L01_00452EF0(m) != 0) {
            pv->h[0x2D6 / 2] = func_0037E208(0, 30);
        }
        if ((pv->h[0x234 / 2] == 1) && (func_003883C8(pv->b + 0x2D6) != 0)) {
            func_L01_00441FB8(m, 4, 2);
        } else if ((pv->i[0x2D8 / 4] != 0) && (func_003883C8(pv->b + 0x2D6) != 0)) {
            func_L01_00441FB8(m, 2, 1);
            pv->i[0x2D8 / 4] = 0;
            if (pv->i[0x2D0 / 4] < 0x12C) {
                pv->i[0x2D0 / 4] = func_0037E208(0x1E0, 0x258);
            }
        }
        break;
    case 1:
        if (pv->h[0x234 / 2] == 1) {
            func_L01_00441FB8(m, 4, 2);
        } else if (pv->i[0x2D0 / 4] == 0) {
            func_L01_00441FB8(m, 1, 0);
        }
        break;
    case 2:
        if (func_L01_00452EF0(m) != 0) {
            func_0039DAE0((pv->i[0x364 / 4] & 0x3FFF) + 0x7D0, 0);
            pv->i[0x398 / 4] = func_0037E208(0xB4, 0x168);
        }
        if (D_001CCFD0.i[0x6C / 4] == 0) {
            if ((D_001CCFD0.i[0x24 / 4] == -1) && (D_001CCFD0.i[0x94 / 4] == 0) && (pv->i[0x390 / 4] == 0) &&
                (D_001A4BE0.i[0x2850 / 4] > 0) && (func_00388398(pv->b + 0x398) != 0)) {
                func_L01_00356108(m);
            }
            if ((D_001CCFD0.i[0x6C / 4] == 0) && (D_001CCFD0.i[0x24 / 4] == -1) && (D_001CCFD0.i[0x94 / 4] == 0) &&
                (pv->i[0x390 / 4] == 0) && (D_001A4BE0.i[0x2850 / 4] < 0)) {
                func_L01_003AFB80(m);
            }
        }
        if ((D_001CCFD0.h[0x76 / 2] == 0) && (D_001CCFD0.h[0x9E / 2] == 3) && (D_001CCFD0.h[0x98 / 2] < 7000)) {
            func_0039C710();
            pv->i[0x390 / 4] = 0;
        }
        if (D_001A4BE0.i[0x19E0 / 4] != 0) {
            func_L01_00458A08(m, func_00388A28(D_001A4BE0.f[0x80 / 4] - m->f[0x10 / 4], D_001A4BE0.f[0x84 / 4] - m->f[0x14 / 4]));
        } else {
            Mo *t = &D_L20_001E029C_003AE0E8[pv->i[0x2DC / 4]];
            func_L01_00458A08(m, func_00388A28(t->f[0x10 / 4] - m->f[0x10 / 4], t->f[0x14 / 4] - m->f[0x14 / 4]));
        }
        if (pv->h[0x234 / 2] != 1) {
            func_L01_00452EF0(m);
        }
        break;
    case 3: {
        s32 r = func_L01_00451078(m, pv->b + 0x160);
        if ((func_L01_00452EF0(m) != 0) && (pv->f[0x30 / 4] <= 0.0f)) {
            func_L20_003B0E48(m, 0x11, 0, 0x14);
            m->f[0x48 / 4] = 0.65f;
            func_003BDA38(m, 0, &v90);
            func_003BDA38(pv->mp[0x2E0 / 4], 1, &vA0);
            func_L01_0032FE90_003AE0E8(&vA0, 1, 10, 10, 10, 10, 0x14, 0, 9.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 1, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_0039FE80(func_0037E208(5, 9), 0, m);
            D_L20_001E2E80_003AE0E8.f[0x40 / 4] = 0.1f;
            D_L20_001E2E80_003AE0E8.i[0x48 / 4] = 0x5A;
            D_L20_001E2E80_003AE0E8.f[0x20 / 4] = 0.2f;
            D_L20_001E2E80_003AE0E8.i[0x28 / 4] = 0xBE;
            D_L20_001E2E80_003AE0E8.i[0x2C / 4] = 0;
        }
        if (pv->f[0x30 / 4] <= 0.0f) {
            if (*(u16 *)((u8 *)m + 0x96) == 0x96) {
                m->f[0x48 / 4] = 0.65f;
            }
            if (*(u16 *)((u8 *)m + 0x96) >= 0x96) {
                D_L20_001DFB50_003AE0E8 = (f32)(*(u16 *)((u8 *)m + 0x96) - 0x96) / 60.0f;
            }
            if (*(u16 *)((u8 *)m + 0x96) == 0x96) {
                func_003BDA38(m, 0, &v90);
                func_003BDA38(pv->mp[0x2E0 / 4], 1, &vA0);
                func_0039FE80(10, 0, m);
                func_L01_0032FE90_003AE0E8(&vA0, 1, 0, 0, 0, 0, 0, 0, 9.0f, 0.0f, 0.0f, 2.0f,
                                  1, 1, 1, 1, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            if (*(u16 *)((u8 *)m + 0x96) >= 0xDD) {
                func_L20_003B0CE0((s32)m);
                m->i[0x98 / 4] = 0;
                m->uh[0x34 / 2] = (m->uh[0x34 / 2] | 0x41) & 0xEFFF;
                func_L01_004A6DF8(m, 1);
                pv->mp[0x2E4 / 4]->uh[0x34 / 2] |= 0x41;
                pv->mp[0x2E4 / 4]->uh[0x34 / 2] &= 0xEFFF;
                pv->mp[0x2E4 / 4]->i[0x98 / 4] = 0;
                func_L01_004A6DF8(pv->mp[0x2E4 / 4], 1);
                pv->mp[0x2E0 / 4]->uh[0x34 / 2] |= 0x41;
                pv->mp[0x2E0 / 4]->uh[0x34 / 2] &= 0xEFFF;
                pv->mp[0x2E0 / 4]->i[0x98 / 4] = 0;
                func_L01_004A6DF8(pv->mp[0x2E0 / 4], 1);
                func_L01_00441FB8(m, 0x12, 5);
                func_0038E2E8(D_L20_001E9980_003AE0E8, 0x16);
                func_0038E440(D_L20_001E9980_003AE0E8);
            } else {
                s32 hit;
                f32 s;
                D_001A4BE0.h[0x1DC / 2] = 4;
                u.b = D_L20_002C5280_003AE0E8;
                hit = 0;
                u.b.f20[1] = func_0037E250(2.0f, 5.0f);
                u.b.f20[13] = 1.4f;
                u.b.f20[0] = 1.0f;
                if (func_0037E1D8(25) == 0) {
                    func_003BD9A0(pv->mp[0x2E0 / 4], 1, v110);
                    hit = 1;
                }
                if (func_0037E1D8(25) == 0) {
                    func_003BD9A0(pv->mp[0x2E0 / 4], 2, v110);
                    hit = 1;
                }
                if (func_0037E1D8(25) == 0) {
                    func_003BD9A0(pv->mp[0x2E4 / 4], 2, v110);
                    hit = 1;
                }
                if (func_0037E1D8(25) == 0) {
                    func_003BD9A0(pv->mp[0x2E4 / 4], 3, v110);
                    hit = 1;
                }
                if (func_0037E1D8(25) == 0) {
                    func_003BD9A0(m, 1, v110);
                    hit = 1;
                }
                if (func_0037E1D8(25) == 0) {
                    func_003BD9A0(m, 2, v110);
                    hit = 1;
                }
                if (hit != 0) {
                    u.b.pos = v110[3];
                    func_003BDA38(m, 0, &v90);
                    s = -1.0f;
                    if (func_0037E1D8(2) == 0) {
                        s = 1.0f;
                    }
                    func_00388830(&u.b.dir, &v110[func_0037E1D8(3)], s);
                    vec_sub_ab(&vA0, &u.b.pos, &v90);
                    func_00388830(&vA0, &vA0, 1.0f);
                    v150 = u.b.dir;
                    func_003BEB58(&u.b.dir, &vA0, &v150, func_0037E250(0.1f, 0.5f));
                    func_L20_004002F8(&u.b);
                    if (func_0037E1D8(3) == 0) {
                        func_0039FE80(func_0037E208(5, 9), 0, m);
                    }
                }
            }
        } else if ((r & 2) && (pv->f[0x30 / 4] > 0.0f)) {
            if (pv->h[0x234 / 2] == 1) {
                func_L01_00441FB8(m, 4, 2);
            } else {
                func_L01_00441FB8(m, 2, 1);
                pv->i[0x2D0 / 4] = func_0037E208(0x244, 0x258);
            }
        }
        break;
    }
    }
    switch (m->b[0x20]) {
    case 1: {
        u8 *e;
        s32 i;
        f32 k = 1680000.0f;
        func_003BD9A0(pv->mp[0x2E0 / 4], 1, &v90);
        func_00388830(&u.s.e0, &v90, 3.0f);
        vec_add_ab(&u.s.d0, &u.s.e0, &u.s.c0);
        if (func_0037E1D8(2) != 0) {
            e = (u8 *)&u.s.d0;
            n = (s32)func_L01_00440918(1.0f, -1.0f);
            e = func_L01_00466F98(e, k * 6.0f, D_L20_001D66B0_003AE0E8, 0xF, 6, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[2] = D_L20_002203C8_003AE0E8[0][1];
            }
        }
        u.s.f0.f[0] = u.s.d0.f[0] + func_L01_00440918(0.0f, 0.04f);
        u.s.f0.f[1] = u.s.d0.f[1] + func_L01_00440918(0.0f, 0.04f);
        u.s.f0.f[2] = u.s.d0.f[2] + func_L01_00440918(0.0f, 0.04f);
        if (func_0037E1D8(2) != 0) {
            e = (u8 *)&u.s.f0;
            n = (s32)func_L01_00440918(1.0f, -1.0f);
            e = func_L01_00466F98(e, k * 2.4f, D_L20_001D66B0_003AE0E8, 0xF, 0x7F, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
                e[2] = D_L20_002203C8_003AE0E8[0][0];
            }
        }
        for (i = 0; i < 20; i++) {
            func_0037E2F0(&u.s.x100, 5.0f, 8.0f);
            vec_add_ab(&v110[0], &u.s.x100, &u.s.d0);
            vec_sub_ab(&u.s.x100, &u.s.d0, &v110[0]);
            func_00388830(&u.s.x100, &u.s.x100, 0.20000001788139343f);
            pp = func_L01_0046DCB8(&v110[0], &u.s.x100, 0x1E, 0, (s32)func_L01_00440918(2.0f, 5.0f), 0x7F, 0x7F,
                                  func_0037E250(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.004055555909872055f, 6);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258_003AE0E8.p[0xD4 / 4][0];
            }
            pp = func_L01_0046DCB8(&v110[0], &u.s.x100, 0x1E, 0, (s32)func_L01_00440918(2.0f, 5.0f), 0x30, 0x30,
                                  func_0037E250(0.8f, 1.25f) * 210000.0f * 3.0f, 4200.0f, 0.004055555909872055f, 0);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258_003AE0E8.p[0xD4 / 4][0];
            }
        }
        break;
    }
    case 3:
        if (m->b[0x60] & 2) {
            func_L01_00441FB8(m, 6, -1);
            func_L20_003B0E48(m, 0xC, 0, 0x8);
        }
        break;
    case 6: {
        f32 d = func_L01_00436500(m);
        if ((13.0f < d) && (d < 28.0f)) {
            f32 a;
            Mo *t;
            func_0039FE80(2, 0, m);
            func_003BDA38(pv->mp[0x2E0 / 4], 1, &v90);
            a = m->f[0xF8 / 4];
            a = func_00389380(a, func_L01_00440918(15.0f, 65.0f) * 0.0174532924f);
            vA0.f[0] = func_00388960(a);
            vA0.f[1] = func_00388978(a);
            vA0.i[2] = 0;
            vA0.f[2] = func_L01_00440918(vA0.f[2], 45.0f) * 0.0174532924f;
            func_00388830(&vA0, &vA0, 0.8333333730697632f);
            if (D_001A4BE0.i[0x19E0 / 4] != 0) {
                t = *(Mo **)&D_001A4BE0.i[0x25C0 / 4];
            } else if (func_0037E1D8(2) != 0) {
                t = *(Mo **)&D_001A4BE0.i[0x25C0 / 4];
            } else {
                t = &D_L20_001E029C_003AE0E8[pv->i[0x2DC / 4]];
            }
            func_L20_003F0138(pv->mp[0x2E0 / 4], &v90, &vA0, t);
        }
        if (m->b[0x60] & 2) {
            func_L20_003B0E48(m, 7, 0, 0x12);
            func_L01_00441FB8(m, 7, -1);
        }
        break;
    }
    case 7:
        if (m->b[0x60] & 2) {
            func_L20_003B0E48(m, 8, 0, 2);
            func_L01_00441FB8(m, 8, -1);
        }
        break;
    case 8:
        if (m->b[0x60] & 2) {
            func_L20_003B0E48(m, 9, 0, 0x5);
            func_L01_00441FB8(m, 9, -1);
        }
        if ((func_L01_0044AF40(m, 0.5f) != 0) || (func_L01_0044AF40(m, 15.0f) != 0)) {
            f32 sp, r;
            func_0039FE80(0, 0, m);
            func_L01_00440A88(v90.f, 0.0f, 1.0f);
            func_003BDA38(pv->mp[0x2E4 / 4], 0, &vA0);
            func_003886E8(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C_003AE0E8 + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            vec_add_ba(&u.s.b0, &u.s.b0, &u.s.c0);
            sp = D_L20_001DE338 * 0.01666666753590107f;
            r = func_0037E250(D_L20_001DE33C, D_L20_001DE340) * 0.00027777778450399637f;
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            u.s.d0.f[2] = 0.0f;
            func_00388830(&u.s.d0, &u.s.d0, sp);
            u.s.d0.f[2] = func_L01_00444740(vA0.f, u.s.b0.f, 0, D_L20_001DE338 * 0.01666666753590107f, -r);
            func_L01_0032FE90_003AE0E8(&vA0, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L20_003F0748(pv->mp[0x2E4 / 4], &vA0, &u.s.d0, 0, r, 150.0f);
        }
        break;
    case 11:
        if (m->b[0x60] & 2) {
            func_L20_003B0E48(m, 0xC, 0, 0xa);
            func_L01_00441FB8(m, 6, -1);
        }
        if ((D_L20_001DFD40_003AE0E8 & 5) == (((s32)m >> 8) & 5)) {
            Mo *h;
            func_0039FE80(0, 0, m);
            func_L01_00440A88(v90.f, 0.0f, 1.0f);
            func_003BDA38(pv->mp[0x2E4 / 4], 1, &vA0);
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C_003AE0E8 + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            func_003886E8(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            u.s.b0 = u.s.c0;
            h = *(Mo **)&D_001A4BE0.i[0x19E0 / 4];
            if ((h != 0) && (h->h[0xAA / 2] == 0x107E)) {
                func_00388830(&u.s.d0, (u8 *)h->p[0x68 / 4] + 0x290, func_0037E250(4.0f, 10.0f));
                vec_add_ab(&u.s.b0, &u.s.d0, &u.s.b0);
            }
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            func_00388830(&u.s.d0, &u.s.d0, 1.3333333730697632f);
            func_L01_0032FE90_003AE0E8(&vA0, 0, 0, 0, 0, 5, 0, 0, 2.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L07_003E1EA0(m, &vA0, &u.s.d0, 1, 0xF0, 0, 45.0f, 3.0f, 0.0f);
        }
        break;
    case 10:
        if (m->b[0x60] & 2) {
            func_L20_003B0E48(m, 9, 0, 0x5);
            func_L01_00441FB8(m, 0xB, -1);
        }
        if ((D_L20_001DFD40_003AE0E8 & 5) == (((s32)m >> 8) & 5)) {
            Mo *h;
            func_0039FE80(0, 0, m);
            func_L01_00440A88(v90.f, 0.0f, 1.0f);
            func_003BDA38(pv->mp[0x2E4 / 4], 0, &vA0);
            func_003886E8(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            h = *(Mo **)&D_001A4BE0.i[0x19E0 / 4];
            if (h == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C_003AE0E8 + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            u.s.b0 = u.s.c0;
            if ((h != 0) && (h->h[0xAA / 2] == 0x107E)) {
                func_00388830(&u.s.d0, (u8 *)h->p[0x68 / 4] + 0x290, func_0037E250(14.0f, 24.0f));
                vec_add_ab(&u.s.b0, &u.s.d0, &u.s.b0);
            }
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            func_00388830(&u.s.d0, &u.s.d0, 1.3333333730697632f);
            func_L01_0032FE90_003AE0E8(&vA0, 0, 0, 0, 0, 5, 0, 0, 2.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L07_003E1EA0(pv->mp[0x2E4 / 4], &vA0, &u.s.d0, 1, 0xB4, 0, 45.0f, 3.0f, 0.0f);
        }
        break;
    case 9:
        if (m->b[0x60] & 2) {
            func_L20_003B0E48(m, 0xA, 0, 0x8);
            func_L01_00441FB8(m, 0xC, -1);
        }
        if ((func_L01_0044AF40(m, 4.0f) != 0) || (func_L01_0044AF40(m, 18.0f) != 0)) {
            f32 sp, r;
            func_0039FE80(0, 0, m);
            func_L01_00440A88(v90.f, 0.0f, 1.0f);
            func_003BDA38(pv->mp[0x2E4 / 4], 1, &vA0);
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C_003AE0E8 + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            func_003886E8(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            vec_add_ba(&u.s.b0, &u.s.b0, &u.s.c0);
            sp = D_L20_001DE338 * 0.01666666753590107f;
            r = func_0037E250(D_L20_001DE33C, D_L20_001DE340) * 0.00027777778450399637f;
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            u.s.d0.f[2] = 0.0f;
            func_00388830(&u.s.d0, &u.s.d0, sp);
            u.s.d0.f[2] = func_L01_00444740(vA0.f, u.s.b0.f, 0, D_L20_001DE338 * 0.01666666753590107f, -r);
            func_L01_0032FE90_003AE0E8(&vA0, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L20_003F0748(pv->mp[0x2E4 / 4], &vA0, &u.s.d0, 0, r, 150.0f);
        }
        break;
    case 12:
        if (m->b[0x60] & 2) {
            if (m->b[0x42] == 10) {
                func_L20_003B0E48(m, 0xB, 0, 0x8);
            }
            if ((m->b[0x60] & 2) && (m->b[0x42] == 11)) {
                func_L20_003B0E48(m, 8, 0, 0xf);
                func_L01_00441FB8(m, 0xA, -1);
            }
        }
        break;
    case 13:
        if (func_L01_00452EC8(m) != 0) {
            pv->i[0x2F4 / 4] = 0;
            pv->i[0x2FC / 4] = 0;
            pv->i[0x2F8 / 4] = 0;
        }
        pv->f[0x2F4 / 4] += 0.0299999993f;
        if (m->b[0x60] & 2) {
            func_L20_003B0E48(m, 0xD, 0, 0x14);
            func_L01_00441FB8(m, 0xE, -1);
            func_003BDA38(pv->mp[0x2E0 / 4], 2, &v90);
            pv->q[0x310 / 16] = v90.q;
            vA0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                vA0.q = *(u128_t *)((u8 *)D_L20_001E029C_003AE0E8 + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            pv->q[0x300 / 16] = vA0.q;
        } else {
            f32 k = pv->f[0x2F4 / 4] * 262500.0f;
            u8 *e;
            s32 i;
            func_003BD9A0(pv->mp[0x2E0 / 4], 1, &u.s.b0);
            func_00388830(&u.s.f0, &u.s.b0, 3.0f);
            vec_add_ab(&v90, &u.s.e0, &u.s.f0);
            if (func_0037E1D8(2) != 0) {
            e = (u8 *)&v90;
                n = (s32)func_L01_00440918(1.0f, -1.0f);
                e = func_L01_00466F98(e, k * 6.0f, D_L20_001D66B0_003AE0E8, 0xF, 6, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
                if (e != 0) {
                    e[2] = D_L20_002203C8_003AE0E8[0][1];
                }
            }
            vA0.f[0] = v90.f[0] + func_L01_00440918(0.0f, 0.04f);
            vA0.f[1] = v90.f[1] + func_L01_00440918(0.0f, 0.04f);
            vA0.f[2] = v90.f[2] + func_L01_00440918(0.0f, 0.04f);
            if (func_0037E1D8(2) != 0) {
            e = (u8 *)&vA0;
                n = (s32)func_L01_00440918(1.0f, -1.0f);
                e = func_L01_00466F98(e, k * 2.4f, D_L20_001D66B0_003AE0E8, 0xF, 0x7F, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
                if (e != 0) {
                    e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
                    e[2] = D_L20_002203C8_003AE0E8[0][0];
                }
            }
            for (i = 0; i < 6; i++) {
                func_0037E2F0(&u.s.x100, pv->f[0x2F4 / 4] * 0.0833333358168602f, pv->f[0x2F4 / 4] * 0.11666667461395264f);
                pp = func_L01_0046DCB8(&v90, &u.s.x100, 0xF, 0, (s32)func_L01_00440918(2.0f, 5.0f), 0x7F, 0x7F,
                                      func_0037E250(0.8f, 1.25f) * 210000.0f * pv->f[0x2F4 / 4],
                                      pv->f[0x2F4 / 4] * 2100.0f, 0.004055555909872055f, 6);
                if (pp != 0) {
                    pp[3] = 0x44;
                    pp[2] = D_L20_00220258_003AE0E8.p[0xD4 / 4][0];
                }
                pp = func_L01_0046DCB8(&v90, &u.s.x100, 0xF, 0, (s32)func_L01_00440918(2.0f, 5.0f), 0x30, 0x30,
                                      func_0037E250(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2F4 / 4],
                                      pv->f[0x2F4 / 4] * 4200.0f, 0.004055555909872055f, 0);
                if (pp != 0) {
                    pp[3] = 0x44;
                    pp[2] = D_L20_00220258_003AE0E8.p[0xD4 / 4][0];
                }
            }
        }
        break;
    case 14: {
        u8 *e;
        s32 i, h, h2, h3;
        f32 k;
        func_L01_00402498(func_L20_003B0EC8, m);
        pv->f[0x2FC / 4] += 0.05000000447034836f;
        if (2.5f < pv->f[0x2FC / 4]) {
            pv->f[0x2FC / 4] = 2.5f;
        }
        pv->f[0x2F8 / 4] += 0.01666666753590107f;
        if (2.5f < pv->f[0x2F8 / 4]) {
            pv->f[0x2F8 / 4] = 2.5f;
        }
        func_003BD9A0(pv->mp[0x2E0 / 4], 1, &vA0);
        func_00388830(&u.s.e0, &vA0, 3.0f);
        vec_add_ba(&v90, &u.s.d0, &u.s.e0);
        pv->mp[0x2E4 / 4]->i[0x98 / 4] = 0;
        pv->mp[0x2E0 / 4]->i[0x98 / 4] = 0;
        func_003C23E8(pv->mp[0x2E4 / 4], 0x80807F7F);
        func_003C23E8(pv->mp[0x2E0 / 4], 0x80807F7F);
        func_L03_004307B8(m, &v90, pv->b + 0x310, 1, 0, 1, 0, 45.0f, 1.0f);
        pv->mp[0x2E4 / 4]->i[0x98 / 4] = pv->mp[0x2E4 / 4]->mp[0x24 / 4]->i[0x10 / 4];
        pv->mp[0x2E0 / 4]->i[0x98 / 4] = pv->mp[0x2E0 / 4]->mp[0x24 / 4]->i[0x10 / 4];
        func_003C23E8(pv->mp[0x2E4 / 4], 0x80807F7F);
        func_003C23E8(pv->mp[0x2E0 / 4], 0x80807F7F);
        vec_sub_ba(&u.s.f0, pv->b + 0x300, &v90);
        func_00388830(&u.s.f0, &u.s.f0, pv->f[0x2F8 / 4] * 120.0f);
        vec_add_ab(&u.s.f0, &u.s.f0, &v90);
        if (func_003CE740(&v90, &u.s.f0, 2, m, 0) != 0) {
            if (D_L20_001E9BD8_003AE0E8[0] == 0) {
                h2 = pv->i[0x2EC / 4];
                if ((h2 == -1) || ((Mo *)SND(h2)->owner != m) || (SND(h2)->on == 0)) {
                    pv->i[0x2EC / 4] = func_0039FE80(4, 4, m);
                }
                func_L20_003F21E8(pv->b + 0x310, 2.0f, 3.0f);
            }
        } else {
            h = pv->i[0x2EC / 4];
            if ((h != -1) && ((Mo *)SND(h)->owner == m) && (SND(h)->on != 0)) {
                func_0039FB08(h);
            }
            pv->i[0x2EC / 4] = -1;
        }
        k = pv->f[0x2F4 / 4] * 262500.0f;
        if (func_0037E1D8(2) != 0) {
            n = (s32)func_L01_00440918(1.0f, -1.0f);
            e = func_L01_00466F98(&v90, k * 6.0f, D_L20_001D66B0_003AE0E8, 0xF, 6, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[2] = D_L20_002203C8_003AE0E8[0][1];
            }
        }
        u.s.x100.f[0] = v90.f[0] + func_L01_00440918(0.0f, 0.04f);
        u.s.x100.f[1] = v90.f[1] + func_L01_00440918(0.0f, 0.04f);
        u.s.x100.f[2] = v90.f[2] + func_L01_00440918(0.0f, 0.04f);
        if (func_0037E1D8(2) != 0) {
            e = (u8 *)&u.s.x100;
            n = (s32)func_L01_00440918(1.0f, -1.0f);
            e = func_L01_00466F98(e, k * 2.4f, D_L20_001D66B0_003AE0E8, 0xF, 0x7F, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
                e[2] = D_L20_002203C8_003AE0E8[0][0];
            }
        }
        for (i = 0; i < 6; i++) {
            func_0037E2F0(&v110[0], pv->f[0x2F4 / 4] * 0.0833333358168602f, pv->f[0x2F4 / 4] * 0.11666667461395264f);
            pp = func_L01_0046DCB8(&v90, &v110[0], 0xF, 0, (s32)func_L01_00440918(2.0f, 5.0f), 0x7F, 0x7F,
                                  func_0037E250(0.8f, 1.25f) * 210000.0f * pv->f[0x2F4 / 4],
                                  pv->f[0x2F4 / 4] * 2100.0f, 0.004055555909872055f, 6);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258_003AE0E8.p[0xD4 / 4][0];
            }
            pp = func_L01_0046DCB8(&v90, &v110[0], 0xF, 0, (s32)func_L01_00440918(2.0f, 5.0f), 0x30, 0x30,
                                  func_0037E250(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2F4 / 4],
                                  pv->f[0x2F4 / 4] * 4200.0f, 0.004055555909872055f, 0);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258_003AE0E8.p[0xD4 / 4][0];
            }
        }
        h3 = pv->i[0x2E8 / 4];
        if ((h3 == -1) || ((Mo *)SND(h3)->owner != m) || (SND(h3)->on == 0)) {
            pv->i[0x2E8 / 4] = func_0039FE80(1, 4, m);
        }
        if (m->uh[0x96 / 2] > 0xB4) {
            h = pv->i[0x2EC / 4];
            if ((h != -1) && ((Mo *)SND(h)->owner == m) && (SND(h)->on != 0)) {
                func_0039FB08(h);
            }
            pv->i[0x2EC / 4] = -1;
            h = pv->i[0x2E8 / 4];
            if ((h != -1) && ((Mo *)SND(h)->owner == m) && (SND(h)->on != 0)) {
                func_0039FB08(h);
            }
            pv->i[0x2F8 / 4] = 0;
            pv->i[0x2F4 / 4] = 0;
            pv->i[0x2FC / 4] = 0;
            pv->i[0x2E8 / 4] = -1;
            func_L20_003B0E48(m, 0xC, 0, 0xa);
            func_L01_00441FB8(m, 6, -1);
        }
        break;
    }
    }
    func_L20_003B0D20((u8 *)m);
    if ((u8)(m->b[0x95] - 4) >= 2) {
        func_L01_00402498(func_L20_003B1190, m);
    }
}
/* localdecomp:end func_L20_003AE0E8 */
