#include "common.h"

/* NTSC-U counterpart of func_L19_00331380 (src/levels/shared/L19_00331380.c) */
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x286C - 0x25C4];
    s32 w286C;
} Hero_00332360;

/* localdecomp:start func_L19_003309C0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    u8 b10;
} An_00331380;

typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x44 - 0x14];
    u16 h44;
    u8 pad46[0x48 - 0x46];
    An_00331380 *a48;
    u8 pad4C[0x50 - 0x4C];
    An_00331380 *a50;
    An_00331380 *a54;
} Cl_00331380;

typedef struct M_00331380 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    Cl_00331380 *cls;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x42 - 0x36];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    void *pv;
    u8 pad6C[0x95 - 0x6C];
    u8 b95;
    u16 h96;
    s32 w98;
    u8 pad9C[0xAA - 0x9C];
    s16 hAA;
    u8 padAC[0xC0 - 0xAC];
    f32 mtx[12];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} M_00331380;

typedef struct {
    u8 pad0[0x80];
    u8 b80[0x140 - 0x80];
    f32 f140;
    f32 f144;
    u8 pad148[0x164 - 0x148];
    f32 f164;
    u8 pad168[0x170 - 0x168];
    f32 f170;
    f32 f174;
    u8 pad178[0x1C0 - 0x178];
    s32 w1C0;
    u8 pad1C4[0x1C8 - 0x1C4];
    s32 w1C8;
    u8 pad1CC[0x1D4 - 0x1CC];
    s32 w1D4;
    u8 pad1D8[0x1E0 - 0x1D8];
    vu0_v4 v1E0;
    u8 pad1F0[0x218 - 0x1F0];
    s32 w218;
    u8 pad21C[0x354 - 0x21C];
    M_00331380 *p354;
    M_00331380 *p358;
    u8 pad35C[0x364 - 0x35C];
    f32 f364;
    u8 pad368[0x36C - 0x368];
    u8 t36C[4];
    s32 w370;
    s32 w374;
    s32 w378;
    s32 w37C;
    u8 pad380[0x384 - 0x380];
    f32 f384;
    f32 f388;
    u8 b38C[0x3A0 - 0x38C];
    f32 f3A0;
    u8 pad3A4[0x3C0 - 0x3A4];
    vu0_v4 v3C0;
} P_00331380;

extern Hero_00332360 D_001A4BE0;
extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern s32 D_001A80A8[];
extern s32 D_L19_001DF240_003309C0;
extern s32 D_L19_001DCC20_003309C0;
extern s32 D_L19_001E8E58_00332360[];
extern s32 func_L01_00448E90(void *);
extern void func_L19_00331F70(void *);
extern void func_L01_00417F60(s32, s32);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00451078(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BD360(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00452F40(void *, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L19_00333288(u8 *);
extern void func_L19_00332BA8(u8 *, vu0_v4);
extern f32 func_L01_0040C040(u8 *, u8 *);
extern void func_L19_00332D08(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_00388398(void *);
extern void func_L19_003546D8(void *, void *);
extern f32 func_00389468(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern int func_L19_00334838(u8 *, u8 *);
extern s32 func_L19_003546B8(u8 *);
extern void func_L19_00354728(void *, void *);
extern void func_003BFAF8(u8 *, float *, float *, int);
extern void func_003888C8(void *, void *, void *);
extern u8 *func_L19_003333E8(u8 *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_L01_00443790(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004576E8(void *);
extern void func_L19_0030D5E0(u8 *, void *, void *);
extern f32 func_L01_00436500(void *);
extern f32 func_L06_00428768(f32, u8 *, u8 *);
extern s32 func_L19_00334758(u8 *);
extern s32 func_L19_0030D5B0(u8 *, u8 *);
extern void func_L19_00334958_003309C0(u8 *);
extern void func_003BF640(void *, f32);
extern void func_L19_00348C68(void *, void *, void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L19_00348D40(void *, f32);
extern void func_L19_00334D70(void *, void *);
extern void func_L19_00334A30(void *, void *);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_00388BD0(void *, void *);
extern u8 *func_L19_00334318();
extern s32 func_L03_003F4470(void *, void *, void *, s32, s32);
extern void func_L19_003335E8(u8 *);
extern void func_L01_004405F4(void *);

#define HERO_00331380 ((u8 *)&D_001A4BE0)

void func_L19_003309C0(M_00331380 *m) {
    P_00331380 *pv;

    if (func_L01_00448E90(&m->pos) == 0) {
        return;
    }
    pv = m->pv;
    func_L19_00331F70(m);
    {
        u8 *hero = HERO_00331380;
        M_00331380 *h = *(M_00331380 **)(hero + 0x25C0);
        if (h->hAA != 0x57 && h->hAA != 0x18B2) {
            return;
        }
    }
    switch (m->b95) {
    case 0:
        break;
    case 1:
        if (D_001D545C == 0x1B || D_001D545C == 8) {
            s32 t = D_001A80A8[0];
            s32 k = 1 << D_001D545C;
            if ((t & k) == 0) {
                func_L01_00417F60(0xB93, 0x36);
            }
        }
        if (func_L01_00452EF0(m)) {
            func_L01_00458A70(m, 0.0016666667f, 0.050000004f, 0.0034906587f, 0.104719765f);
            pv->f164 = 0.0055555557f;
            pv->f174 = 0.5f;
        }
        break;
    case 2:
        if (func_L01_00452EF0(m)) {
            func_L01_00458A70(m, 0.0027777778f, 0.083333336f, 0.0069813174f, 0.20943953f);
            pv->f164 = 0.0055555557f;
            pv->f174 = 0.0f;
        }
        break;
    case 3:
        if (func_L01_00452EF0(m)) {
            func_L01_00458A70(m, 0.0016666667f, 0.050000004f, 0.0069813174f, 0.20943953f);
            pv->f164 = 0.0055555557f;
            pv->f174 = 0.1f;
        }
        break;
    case 4:
        if (func_L01_00452EF0(m)) {
            func_L01_00458A70(m, 0.0016666667f, 0.050000004f, 0.0034906587f, 0.104719765f);
            pv->f164 = 0.0016666667f;
            pv->f174 = 0.4f;
        }
        break;
    case 5:
        if (func_L01_00452EF0(m)) {
            func_L01_00458A70(m, 0.0016666667f, 0.050000004f, 0.0034906587f, 0.104719765f);
            pv->f164 = 0.0016666667f;
            pv->f174 = 0.05f;
        }
        break;
    case 6:
        if (func_L01_00452EF0(m)) {
            func_L01_00458A70(m, 0.0016666667f, 0.050000004f, 0.0069813174f, 0.20943953f);
            pv->f164 = 0.005f;
            pv->f174 = 0.05f;
        }
        break;
    case 8: {
        s32 r = func_L01_00451078(m, pv->b80);
        if (r & 1) {
            func_003BD360(m);
            return;
        }
        if (r & 2) {
            func_L01_00441FB8((u8 *)m, 2, 0);
        }
        break;
    }
    }
    switch (m->state) {
    case 1:
        if (pv->p354 != 0 && func_L01_00452F60(pv->p354)) {
            func_L01_00441FB8((u8 *)m, 4, 1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 0) {
                func_003BE4F0((u8 *)m, 0, func_0037E1D8(m->cls->a48->b10), 0xF);
            }
            pv->w370 = 2;
            pv->f174 = 0.5f;
            pv->w374 = func_0037E208(0x3C, 0x78);
            pv->w378 = 0;
            pv->w37C = 0;
        }
        func_L19_00333288((u8 *)m);
        break;
    case 4:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 0) {
                func_003BE4F0((u8 *)m, 0, func_0037E1D8(m->cls->a48->b10), 0xF);
            }
            pv->w370 = 2;
            pv->f174 = 0.5f;
            {
                u8 *hero = HERO_00331380;
                pv->p358 = *(M_00331380 **)(hero + 0x25C0);
            }
        }
        {
            {
                vu0_v4 cam = *(vu0_v4 *)D_001A4C60;
                func_L19_00332BA8((u8 *)m, cam);
            }
        }
        if (func_L01_0040C040((u8 *)&pv->v3C0, (u8 *)&m->pos) > 9.0f) {
            func_L01_00441FB8((u8 *)m, 3, -1);
            break;
        }
        func_L19_00333288((u8 *)m);
        break;
    case 3: {
        f32 d;
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 2) {
                func_003BE4F0((u8 *)m, 2, func_0037E1D8(m->cls->a50->b10), 0xA);
            }
            pv->f174 = 0.5f;
            {
                u8 *hero = HERO_00331380;
                pv->p358 = *(M_00331380 **)(hero + 0x25C0);
            }
        }
        {
            {
                vu0_v4 cam = *(vu0_v4 *)D_001A4C60;
                func_L19_00332BA8((u8 *)m, cam);
            }
        }
        func_L19_00332D08(m);
        d = func_L01_0040C040((u8 *)&pv->v3C0, (u8 *)&m->pos);
        if (d < 1.0f || (pv->w1C0 >= 0x79 && d < 9.0f)) {
            func_L01_00441FB8((u8 *)m, 4, -1);
        }
        break;
    }
    case 5:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 2) {
                func_003BE4F0((u8 *)m, 2, func_0037E1D8(m->cls->a50->b10), 0x14);
            }
            pv->f174 = 0.1f;
            pv->v3C0.x = func_00388960(pv->f364);
            pv->v3C0.y = func_00388978(pv->f364);
            pv->v3C0.z = 0.0f;
            vec_add_ab(&pv->v3C0, &pv->v3C0, &m->pos);
        }
        func_L19_00332D08(m);
        if (m->h96 >= 0x1F) {
            func_L01_00441FB8((u8 *)m, 4, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(m)) {
            switch (m->hAA) {
            case 0x93C:
            case 0x940:
                if (m->b43 != 3) {
                    func_003BE4F0((u8 *)m, 3, 0, 0x14);
                }
                break;
            case 0xA59:
                if (m->b43 != 3) {
                    func_003BE4F0((u8 *)m, 3, 0, 0x14);
                }
                break;
            }
        }
        {
            u8 *hero = HERO_00331380;
            func_L01_00458A08(m, func_00388A28(*(f32 *)(hero + 0x80) - m->pos.x, *(f32 *)(hero + 0x84) - m->pos.y));
        }
        if (m->b60 & 2) {
            func_L01_00441FB8((u8 *)m, 4, -1);
        }
        break;
    case 7:
        if (func_L01_00452EC8(m)) {
            pv->f174 = 0.1f;
        }
        if (pv->f174 < func_00388800(&m->pos, &pv->v3C0)) {
            if (m->b43 != 2) {
                func_003BE4F0((u8 *)m, 2, func_0037E1D8(m->cls->a50->b10), 0xA);
            }
            func_L19_00332D08(m);
        } else {
            if (m->b43 != 0) {
                func_003BE4F0((u8 *)m, 0, func_0037E1D8(m->cls->a48->b10), 0x14);
            }
        }
        if (func_00388398(pv->t36C)) {
            func_L01_00441FB8((u8 *)m, 4, -1);
        }
        break;
    case 11: {
        {
            vu0_v4 v;
            f32 a;
            M_00331380 *t;
            if (func_L01_00452EC8(m)) {
                if (m->b43 != 2) {
                    func_003BE4F0((u8 *)m, 2, func_0037E1D8(m->cls->a50->b10), 0xA);
                }
            }
            func_L19_003546D8(pv->p358, &v);
            t = pv->p358;
            a = func_00389468(t->fF8, func_00388A28(m->pos.x - t->pos.x, m->pos.y - t->pos.y));
            if (fabs_asm(a) > 1.0471976f) {
                f32 d = func_00388800(&pv->p358->pos, &v);
                f32 h = a * 0.5f;
                pv->v3C0.x = func_00388960(func_00389380(pv->p358->fF8, h)) * d;
                pv->v3C0.y = func_00388978(func_00389380(pv->p358->fF8, h)) * d;
                pv->v3C0.z = 0.0f;
                vec_add_ba(&pv->v3C0, &pv->v3C0, &pv->p358->pos);
            } else {
                pv->v3C0 = v;
            }
            if ((D_L19_001DF240_003309C0 & 3) == (((s32)m >> 8) & 3)) {
                if (func_L19_00334838((u8 *)m, (u8 *)&v)) {
                    pv->f140 = 0.05f;
                } else {
                    pv->f140 = 0.1f;
                }
            }
            func_L19_00332D08(m);
            if (!func_L19_003546B8((u8 *)pv->p358) || pv->w1C0 >= 0x79) {
                pv->f140 = 0.1f;
                func_L01_00441FB8((u8 *)m, 4, 1);
            } else if (func_L01_0040C040((u8 *)&m->pos, (u8 *)&v) <= pv->f174 * pv->f174) {
                func_L01_00441FB8((u8 *)m, 0xC, -1);
            }
        }
        break;
    }
    case 12:
        if (func_L01_00452EC8(m)) {
            func_L19_00354728(pv->p358, m);
            pv->f170 = 0.17453292f;
            pv->f174 = 0.0f;
            func_003BFAF8((u8 *)pv->p358, (float *)&pv->v1E0, (float *)&pv->v1E0, 0);
            pv->v1E0.y = 0.0f;
            func_003888C8(&pv->v1E0, &pv->v1E0, pv->p358->mtx);
            pv->f140 = 0.0f;
            pv->f144 = 0.0f;
        }
        pv->v3C0 = pv->p358->pos;
        func_L19_00332D08(m);
        if (func_00388800(&m->pos, &pv->p358->pos) < 0.1f) {
            func_003BD360(m);
            return;
        }
        break;
    case 8: {
        M_00331380 *t;
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 3) {
                func_003BE4F0((u8 *)m, 3, func_0037E1D8(m->cls->a54->b10), 0xA);
            }
        }
        t = pv->p358;
        if (t == 0 || t->state == 0xFE || t->state == 0xFD || (D_L19_001DF240_003309C0 & 7) == (((s32)m >> 8) & 7)) {
            pv->p358 = (M_00331380 *)func_L19_003333E8((u8 *)m);
            if (pv->p358 == 0) {
                func_L01_00441FB8((u8 *)m, 0xA, -1);
                break;
            }
        }
        pv->v3C0 = pv->p358->pos;
        func_L19_00332D08(m);
        if ((D_L19_001DF240_003309C0 & 3) == (((s32)m >> 8) & 3)) {
            vu0_v4 a;
            vu0_v4 b;
            a = m->pos;
            a.z = a.z + 0.2f;
            func_003886E8(&b, m->mtx, 0.4f);
            vec_add_ab(&b, &b, &m->pos);
            b.z = b.z + 0.2f;
            if (func_003CE740(&a, &b, 0, m, 0) && D_L19_001E8E58_00332360[0] == (s32)pv->p358) {
                func_L01_00441FB8((u8 *)m, 9, -1);
            }
        }
        break;
    }
    case 9:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 4) {
                func_003BE4F0((u8 *)m, 4, 0, 0xA);
            }
        } else if (func_L01_0044AF40(m, 14.0f)) {
            func_L01_00443790((u8 *)m, 1, 0x10000, 0, 1, 0, 0.4f, 4.0f, 1.0f);
        } else if (m->b60 & 2) {
            pv->p358 = (M_00331380 *)func_L19_003333E8((u8 *)m);
            if (pv->p358 != 0) {
                func_L01_00441FB8((u8 *)m, 8, -1);
            } else {
                func_L01_00441FB8((u8 *)m, 0xA, -1);
            }
        } else {
            func_L01_004576E8(m);
        }
        break;
    case 10:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 0) {
                func_003BE4F0((u8 *)m, 0, func_0037E1D8(m->cls->a48->b10), 0xF);
            }
        }
        if ((D_L19_001DF240_003309C0 & 7) == (((s32)m >> 8) & 7)) {
            pv->p358 = (M_00331380 *)func_L19_003333E8((u8 *)m);
        }
        func_L19_00333288((u8 *)m);
        if (pv->p358 != 0) {
            func_L01_00441FB8((u8 *)m, 8, -1);
        } else if (m->h96 >= 0x12D) {
            func_L01_00441FB8((u8 *)m, 4, 1);
        }
        break;
    case 13: {
        {
            vu0_v4 a;
            vu0_v4 b;
            f32 d;
            if (func_L01_00452EC8(m)) {
                if (m->b43 != 2) {
                    func_003BE4F0((u8 *)m, 2, func_0037E1D8(m->cls->a50->b10), 0xA);
                }
            }
            func_L19_0030D5E0((u8 *)pv->p358, &a, &b);
            d = func_L01_0040C040((u8 *)&m->pos, (u8 *)&a);
            if (d < func_L01_0040C040((u8 *)&m->pos, (u8 *)&b)) {
                pv->v3C0 = a;
            } else {
                pv->v3C0 = b;
            }
            func_L19_00332D08(m);
            if (pv->w1D4 & 0x80) {
                func_L01_00441FB8((u8 *)m, 0xE, -1);
            }
        }
        break;
    }
    case 14:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 4) {
                func_003BE4F0((u8 *)m, 4, 0, 0xA);
            }
            m->w98 = 0;
            vec_sub_ab(&pv->v3C0, &pv->v3C0, &pv->p358->pos);
            func_003BFAF8((u8 *)pv->p358, (float *)&pv->v3C0, (float *)&pv->v3C0, 0);
            pv->v3C0.y = 0.0f;
            if (pv->v3C0.x < pv->v3C0.y) {
                pv->v3C0.x = -3.8f;
            } else {
                pv->v3C0.x = 3.8f;
            }
            func_003888C8(&pv->v3C0, &pv->v3C0, pv->p358->mtx);
            vec_add_ab(&pv->v3C0, &pv->v3C0, &pv->p358->pos);
        }
        {
            M_00331380 *t = pv->p358;
            func_L01_00458A08(m, func_00388A28(t->pos.x - m->pos.x, t->pos.y - m->pos.y));
        }
        if (func_L01_00436500(m) > 11.0f) {
            func_L06_00428768(0.13333334f, (u8 *)&m->pos, (u8 *)&pv->v3C0);
        }
        if (m->b60 & 2) {
            func_L01_00441FB8((u8 *)m, 0xF, -1);
            if (m->b43 != 5) {
                func_003BE4F0((u8 *)m, 5, 0, 5);
            }
            func_L01_00452F40(pv->p358, 1);
        }
        break;
    case 15:
        if (func_L01_00452EC8(m)) {
            pv->w1C8 = 0;
        }
        if (func_L01_0040C040(D_001A4C60, (u8 *)&pv->p358->pos) > 144.0f) {
            if (!func_L19_00334758((u8 *)m) && !func_L19_0030D5B0((u8 *)pv->p358, D_001A4C60)) {
                func_L19_00334958_003309C0((u8 *)m);
            }
        }
        break;
    case 16: {
        {
            vu0_v4 d;
            vec_sub_ba(&d, &pv->v3C0, &m->pos);
            func_003BF640(&d, 0.4166667f);
            vec_add_ab(&m->pos, &m->pos, &d);
            if (m->b42 == m->b43) {
                m->pos = pv->v3C0;
                func_L01_00441FB8((u8 *)m, 6, 1);
            }
        }
        break;
    }
    case 17:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 2) {
                func_003BE4F0((u8 *)m, 2, func_0037E1D8(m->cls->a50->b10), 0xA);
            }
        }
        func_L19_00348C68(pv->p358, &m->pos, &pv->v3C0);
        func_L19_00332D08(m);
        if (pv->w1D4 & 0x80) {
            func_L01_00441FB8((u8 *)m, 0x12, -1);
            func_L01_00452F40(pv->p358, 1);
        }
        break;
    case 18:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 4) {
                func_003BE4F0((u8 *)m, 4, 0, 0xA);
            }
        }
        {
            M_00331380 *t = pv->p358;
            func_L01_00458A08(m, func_00388A28(t->pos.x - m->pos.x, t->pos.y - m->pos.y));
        }
        if (m->b42 == m->b43) {
            if (func_L01_00436500(m) >= 10.0f) {
                vu0_v4 a;
                func_003BDA38(m, 2, &a);
                func_L19_00348D40(pv->p358, a.z - m->pos.z);
            }
            if (m->b60 & 2) {
                func_L01_00441FB8((u8 *)m, 6, 1);
                func_L01_00452F40(pv->p358, 0);
            }
        }
        break;
    case 19:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 2) {
                func_003BE4F0((u8 *)m, 2, func_0037E1D8(m->cls->a50->b10), 0xA);
            }
        }
        switch (pv->p358->hAA) {
        case 0xB10:
            func_L19_00334D70(pv->p358, &pv->v3C0);
            break;
        case 0xF4D:
            func_L19_00334A30(pv->p358, &pv->v3C0);
            break;
        }
        func_L19_00332D08(m);
        if (pv->w1D4 & 0x80) {
            func_L01_00441FB8((u8 *)m, 0x14, -1);
        }
        break;
    case 20:
        if (func_L01_00452EC8(m)) {
            if (m->b43 != 5) {
                func_003BE4F0((u8 *)m, 5, 0, 0xA);
            }
        }
        {
            M_00331380 *t = pv->p358;
            func_L01_00458A08(m, func_00388A28(t->pos.x - m->pos.x, t->pos.y - m->pos.y));
        }
        if (m->b60 & 2) {
            func_L01_00441FB8((u8 *)m, 6, 1);
        } else if (func_L01_0044AF40(m, 20.0f)) {
            func_L01_00452F40(pv->p358, 1);
        }
        break;
    case 21: {
        {
            vu0_v4 a;
            vu0_v4 b;
            vu0_v4 c;
            f32 h;
            vec_add_ba(&m->pos, &m->pos, &pv->v1E0);
            qzero(&a);
            qzero(&b);
            switch (m->hAA) {
            case 0x940:
                b.z = 0.8f;
                a.z = 0.8f;
                break;
            case 0x964:
                b.z = 0.3f;
                a.z = 0.3f;
                break;
            case 0x93C:
            default:
                b.z = 0.8f;
                a.z = 0.8f;
                break;
            }
            func_003888C8(&a, &a, m->mtx);
            if (pv->v1E0.z < 0.0f) {
                pv->v1E0.z = pv->v1E0.z - pv->f388;
                if (0.0f < m->fF4) {
                    func_003BEC60(&m->fF4, pv->b38C, 0.0f, 0.0069813174f, 0.0069813174f, 0.41887906f);
                } else {
                    m->fF4 = func_003893C8(m->fF4, 0.41887906f);
                }
                if (m->pos.z < pv->f3A0) {
                    f32 g = func_003BE7F0(&m->pos, 0, 0, 0.5f);
                    if (m->pos.z <= g) {
                        m->pos.z = g;
                        func_L01_00441FB8((u8 *)m, 4, 1);
                    }
                }
            } else {
                pv->v1E0.z = pv->v1E0.z - pv->f384;
                m->fF4 = func_003893C8(m->fF4, 0.41887906f);
            }
            func_00388BD0(m->mtx, &m->fF0);
            func_003888C8(&b, &b, m->mtx);
            vec_sub_ba(&c, &a, &b);
            vec_add_ab(&m->pos, &m->pos, &c);
        }
        break;
    }
    case 23:
        if ((D_L19_001DF240_003309C0 & 0x3F) == (((s32)m >> 8) & 0x3F) && D_L19_001DCC20_003309C0 < D_L19_001DF240_003309C0) {
            vu0_v4 a;
            vu0_v4 b;
            M_00331380 *t = (M_00331380 *)func_L19_00334318(m, &a, &b);
            if (t != 0) {
                m->h34 &= 0xFFBE;
                m->h34 |= m->cls->h44 & 0x1000;
                m->w98 = m->cls->w10;
                qzero(&pv->v1E0);
                pv->w218 = -1;
                D_L19_001DCC20_003309C0 = D_L19_001DF240_003309C0 + 0x3C;
                if (t->hAA == 0x1BB2) {
                    func_L01_00441FB8((u8 *)m, 1, 0);
                    func_L01_00452F40(t, 0);
                    pv->p354 = t;
                    m->pos = t->pos;
                    *(M_00331380 **)t->pv = m;
                } else {
                    func_L01_00441FB8((u8 *)m, 4, 1);
                    func_L03_003F4470(m, &a, &b, 0, 0);
                }
            }
        }
        break;
    }
    func_L19_003335E8((u8 *)m);
    func_L01_004405F4(m);
}
/* localdecomp:end func_L19_003309C0 */
