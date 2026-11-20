#include "common.h"

typedef struct { u8 pad[0x330]; s32 ids[8]; } Grp_003345D0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_003347B0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} GroupState_00334958;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_00334B10;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) t1v;
typedef t1v t0v;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00332360;
typedef struct {
    u8 pad0[0x350];
    s32 w350;
    u8 pad354[4];
    u8 *p358;
    u8 pad35C[4];
    s32 w360;
} St_00332360;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xF];
    unsigned long d30;
    u8 pad38[0x30];
    St_00332360 *p68;
    u8 pad6C[0x29];
    u8 b95;
    u8 pad96[2];
    s32 w98;
    u8 pad9C[0xE];
    s16 hAA;
} Obj_00332360;
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x286C - 0x25C4];
    s32 w286C;
} Hero_00332360;

/* localdecomp:start func_L19_00331380 */
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

extern Hero_00332360 D_1A4BE0;
extern u8 D_1A4C60[];
extern s32 D_001D545C;
extern s32 D_001A80A8[];
extern s32 D_L19_001DF240;
extern s32 D_L19_001DCBE0;
extern s32 D_L19_001E8E58_00332360[];
extern s32 func_L01_0044C108(void *);
extern void func_L19_00332948(void *);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_00454370(void *, void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L19_00333C60(u8 *);
extern void func_L19_00333580();
extern f32 func_L01_0040E570(u8 *, u8 *);
extern void func_L19_003336E0(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_L19_003556D0(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern int func_L19_00335210(u8 *, u8 *);
extern s32 func_L19_003556B0(u8 *);
extern void func_L19_00355720(void *, void *);
extern void func_003C5060(u8 *, float *, float *, int);
extern void func_0038D000(void *, void *, void *);
extern u8 *func_L19_00333DC0(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L01_004468C8(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_0045A9F0(void *);
extern void func_L19_0030D928(u8 *, void *, void *);
extern f32 func_L01_004395E0(void *);
extern f32 func_L06_0042B660(f32, u8 *, u8 *);
extern s32 func_L19_00335130(u8 *);
extern s32 func_L19_0030D8F8(u8 *, u8 *);
extern void func_L19_00335330(u8 *);
extern void func_003C4BB0(void *, f32);
extern void func_L19_00349A18(void *, void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L19_00349AF0(void *, f32);
extern void func_L19_00335748(void *, void *);
extern void func_L19_00335408(void *, void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_0038D308(void *, void *);
extern u8 *func_L19_00334CF0();
extern s32 func_L03_003F6A80(void *, void *, void *, s32, s32);
extern void func_L19_00333FC0(u8 *);
extern void func_L01_004436F4(void *);

#define HERO_00331380 ((u8 *)&D_1A4BE0)

void func_L19_00331380(M_00331380 *m) {
    P_00331380 *pv;

    if (func_L01_0044C108(&m->pos) == 0) {
        return;
    }
    pv = m->pv;
    func_L19_00332948(m);
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
                func_L01_0041A5B0(0xB93, 0x36);
            }
        }
        if (func_L01_004561E0(m)) {
            func_L01_0045BD78(m, 0.0024f, 0.060000002f, 0.0050265486f, 0.12566371f);
            pv->f164 = 0.008f;
            pv->f174 = 0.5f;
        }
        break;
    case 2:
        if (func_L01_004561E0(m)) {
            func_L01_0045BD78(m, 0.004f, 0.10000001f, 0.010053097f, 0.25132743f);
            pv->f164 = 0.008f;
            pv->f174 = 0.0f;
        }
        break;
    case 3:
        if (func_L01_004561E0(m)) {
            func_L01_0045BD78(m, 0.0024f, 0.060000002f, 0.010053097f, 0.25132743f);
            pv->f164 = 0.008f;
            pv->f174 = 0.1f;
        }
        break;
    case 4:
        if (func_L01_004561E0(m)) {
            func_L01_0045BD78(m, 0.0024f, 0.060000002f, 0.0050265486f, 0.12566371f);
            pv->f164 = 0.0024f;
            pv->f174 = 0.4f;
        }
        break;
    case 5:
        if (func_L01_004561E0(m)) {
            func_L01_0045BD78(m, 0.0024f, 0.060000002f, 0.0050265486f, 0.12566371f);
            pv->f164 = 0.0024f;
            pv->f174 = 0.05f;
        }
        break;
    case 6:
        if (func_L01_004561E0(m)) {
            func_L01_0045BD78(m, 0.0024f, 0.060000002f, 0.010053097f, 0.25132743f);
            pv->f164 = 0.0072000003f;
            pv->f174 = 0.05f;
        }
        break;
    case 8: {
        s32 r = func_L01_00454370(m, pv->b80);
        if (r & 1) {
            func_003C2880(m);
            return;
        }
        if (r & 2) {
            func_L01_004450F0((u8 *)m, 2, 0);
        }
        break;
    }
    }
    switch (m->state) {
    case 1:
        if (pv->p354 != 0 && func_L01_00456250(pv->p354)) {
            func_L01_004450F0((u8 *)m, 4, 1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 0) {
                func_003C3A10((u8 *)m, 0, func_00382468(m->cls->a48->b10), 0xC);
            }
            pv->w370 = 2;
            pv->f174 = 0.5f;
            pv->w374 = (func_00382498(0x3C, 0x78) * 5 + 2) / 6;
            pv->w378 = 0;
            pv->w37C = 0;
        }
        func_L19_00333C60((u8 *)m);
        break;
    case 4:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 0) {
                func_003C3A10((u8 *)m, 0, func_00382468(m->cls->a48->b10), 0xC);
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
                vu0_v4 cam = *(vu0_v4 *)D_1A4C60;
                func_L19_00333580(m, cam);
            }
        }
        if (func_L01_0040E570((u8 *)&pv->v3C0, (u8 *)&m->pos) > 9.0f) {
            func_L01_004450F0((u8 *)m, 3, -1);
            break;
        }
        func_L19_00333C60((u8 *)m);
        break;
    case 3: {
        f32 d;
        if (func_L01_004561B8(m)) {
            if (m->b43 != 2) {
                func_003C3A10((u8 *)m, 2, func_00382468(m->cls->a50->b10), 8);
            }
            pv->f174 = 0.5f;
            {
                u8 *hero = HERO_00331380;
                pv->p358 = *(M_00331380 **)(hero + 0x25C0);
            }
        }
        {
            {
                vu0_v4 cam = *(vu0_v4 *)D_1A4C60;
                func_L19_00333580(m, cam);
            }
        }
        func_L19_003336E0(m);
        d = func_L01_0040E570((u8 *)&pv->v3C0, (u8 *)&m->pos);
        if (d < 1.0f || (pv->w1C0 >= 0x65 && d < 9.0f)) {
            func_L01_004450F0((u8 *)m, 4, -1);
        }
        break;
    }
    case 5:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 2) {
                func_003C3A10((u8 *)m, 2, func_00382468(m->cls->a50->b10), 0x11);
            }
            pv->f174 = 0.1f;
            pv->v3C0.x = func_0038D098(pv->f364);
            pv->v3C0.y = func_0038D0B0(pv->f364);
            pv->v3C0.z = 0.0f;
            vec_add_ab(&pv->v3C0, &pv->v3C0, &m->pos);
        }
        func_L19_003336E0(m);
        if (m->h96 >= 0x1A) {
            func_L01_004450F0((u8 *)m, 4, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(m)) {
            switch (m->hAA) {
            case 0x93C:
            case 0x940:
                if (m->b43 != 3) {
                    func_003C3A10((u8 *)m, 3, 0, 0x11);
                }
                break;
            case 0xA59:
                if (m->b43 != 3) {
                    func_003C3A10((u8 *)m, 3, 0, 0x11);
                }
                break;
            }
        }
        {
            u8 *hero = HERO_00331380;
            func_L01_0045BD10(m, func_0038D160(*(f32 *)(hero + 0x80) - m->pos.x, *(f32 *)(hero + 0x84) - m->pos.y));
        }
        if (m->b60 & 2) {
            func_L01_004450F0((u8 *)m, 4, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(m)) {
            pv->f174 = 0.1f;
        }
        if (pv->f174 < func_0038CF38(&m->pos, &pv->v3C0)) {
            if (m->b43 != 2) {
                func_003C3A10((u8 *)m, 2, func_00382468(m->cls->a50->b10), 8);
            }
            func_L19_003336E0(m);
        } else {
            if (m->b43 != 0) {
                func_003C3A10((u8 *)m, 0, func_00382468(m->cls->a48->b10), 0x11);
            }
        }
        if (func_0038CAD0(pv->t36C)) {
            func_L01_004450F0((u8 *)m, 4, -1);
        }
        break;
    case 11: {
        {
            vu0_v4 v;
            f32 a;
            M_00331380 *t;
            if (func_L01_004561B8(m)) {
                if (m->b43 != 2) {
                    func_003C3A10((u8 *)m, 2, func_00382468(m->cls->a50->b10), 8);
                }
            }
            func_L19_003556D0(pv->p358, &v);
            t = pv->p358;
            a = func_0038DBA0(t->fF8, func_0038D160(m->pos.x - t->pos.x, m->pos.y - t->pos.y));
            if (fabs_asm(a) > 1.0471976f) {
                f32 d = func_0038CF38(&pv->p358->pos, &v);
                f32 h = a * 0.5f;
                pv->v3C0.x = func_0038D098(func_0038DAB8(pv->p358->fF8, h)) * d;
                pv->v3C0.y = func_0038D0B0(func_0038DAB8(pv->p358->fF8, h)) * d;
                pv->v3C0.z = 0.0f;
                vec_add_ba(&pv->v3C0, &pv->v3C0, &pv->p358->pos);
            } else {
                pv->v3C0 = v;
            }
            if ((D_L19_001DF240 & 3) == (((s32)m >> 8) & 3)) {
                if (func_L19_00335210((u8 *)m, (u8 *)&v)) {
                    pv->f140 = 0.05f;
                } else {
                    pv->f140 = 0.1f;
                }
            }
            func_L19_003336E0(m);
            if (!func_L19_003556B0((u8 *)pv->p358) || pv->w1C0 >= 0x65) {
                pv->f140 = 0.1f;
                func_L01_004450F0((u8 *)m, 4, 1);
            } else if (func_L01_0040E570((u8 *)&m->pos, (u8 *)&v) <= pv->f174 * pv->f174) {
                func_L01_004450F0((u8 *)m, 0xC, -1);
            }
        }
        break;
    }
    case 12:
        if (func_L01_004561B8(m)) {
            func_L19_00355720(pv->p358, m);
            pv->f170 = 0.17453292f;
            pv->f174 = 0.0f;
            func_003C5060((u8 *)pv->p358, (float *)&pv->v1E0, (float *)&pv->v1E0, 0);
            pv->v1E0.y = 0.0f;
            func_0038D000(&pv->v1E0, &pv->v1E0, pv->p358->mtx);
            pv->f140 = 0.0f;
            pv->f144 = 0.0f;
        }
        pv->v3C0 = pv->p358->pos;
        func_L19_003336E0(m);
        if (func_0038CF38(&m->pos, &pv->p358->pos) < 0.1f) {
            func_003C2880(m);
            return;
        }
        break;
    case 8: {
        M_00331380 *t;
        if (func_L01_004561B8(m)) {
            if (m->b43 != 3) {
                func_003C3A10((u8 *)m, 3, func_00382468(m->cls->a54->b10), 8);
            }
        }
        t = pv->p358;
        if (t == 0 || t->state == 0xFE || t->state == 0xFD || (D_L19_001DF240 & 7) == (((s32)m >> 8) & 7)) {
            pv->p358 = (M_00331380 *)func_L19_00333DC0((u8 *)m);
            if (pv->p358 == 0) {
                func_L01_004450F0((u8 *)m, 0xA, -1);
                break;
            }
        }
        pv->v3C0 = pv->p358->pos;
        func_L19_003336E0(m);
        if ((D_L19_001DF240 & 3) == (((s32)m >> 8) & 3)) {
            vu0_v4 a;
            vu0_v4 b;
            a = m->pos;
            a.z = a.z + 0.2f;
            func_0038CE20(&b, m->mtx, 0.4f);
            vec_add_ab(&b, &b, &m->pos);
            b.z = b.z + 0.2f;
            if (func_003D3CB0(&a, &b, 0, m, 0) && D_L19_001E8E58_00332360[0] == (s32)pv->p358) {
                func_L01_004450F0((u8 *)m, 9, -1);
            }
        }
        break;
    }
    case 9:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 4) {
                func_003C3A10((u8 *)m, 4, 0, 8);
            }
        } else if (func_L01_0044E1B8(m, 14.0f)) {
            func_L01_004468C8((u8 *)m, 1, 0x10000, 0, 1, 0, 0.4f, 4.0f, 1.0f);
        } else if (m->b60 & 2) {
            pv->p358 = (M_00331380 *)func_L19_00333DC0((u8 *)m);
            if (pv->p358 != 0) {
                func_L01_004450F0((u8 *)m, 8, -1);
            } else {
                func_L01_004450F0((u8 *)m, 0xA, -1);
            }
        } else {
            func_L01_0045A9F0(m);
        }
        break;
    case 10:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 0) {
                func_003C3A10((u8 *)m, 0, func_00382468(m->cls->a48->b10), 0xC);
            }
        }
        if ((D_L19_001DF240 & 7) == (((s32)m >> 8) & 7)) {
            pv->p358 = (M_00331380 *)func_L19_00333DC0((u8 *)m);
        }
        func_L19_00333C60((u8 *)m);
        if (pv->p358 != 0) {
            func_L01_004450F0((u8 *)m, 8, -1);
        } else if (m->h96 >= 0xFB) {
            func_L01_004450F0((u8 *)m, 4, 1);
        }
        break;
    case 13: {
        {
            vu0_v4 a;
            vu0_v4 b;
            f32 d;
            if (func_L01_004561B8(m)) {
                if (m->b43 != 2) {
                    func_003C3A10((u8 *)m, 2, func_00382468(m->cls->a50->b10), 8);
                }
            }
            func_L19_0030D928((u8 *)pv->p358, &a, &b);
            d = func_L01_0040E570((u8 *)&m->pos, (u8 *)&a);
            if (d < func_L01_0040E570((u8 *)&m->pos, (u8 *)&b)) {
                pv->v3C0 = a;
            } else {
                pv->v3C0 = b;
            }
            func_L19_003336E0(m);
            if (pv->w1D4 & 0x80) {
                func_L01_004450F0((u8 *)m, 0xE, -1);
            }
        }
        break;
    }
    case 14:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 4) {
                func_003C3A10((u8 *)m, 4, 0, 8);
            }
            m->w98 = 0;
            vec_sub_ab(&pv->v3C0, &pv->v3C0, &pv->p358->pos);
            func_003C5060((u8 *)pv->p358, (float *)&pv->v3C0, (float *)&pv->v3C0, 0);
            pv->v3C0.y = 0.0f;
            if (pv->v3C0.x < pv->v3C0.y) {
                pv->v3C0.x = -3.8f;
            } else {
                pv->v3C0.x = 3.8f;
            }
            func_0038D000(&pv->v3C0, &pv->v3C0, pv->p358->mtx);
            vec_add_ab(&pv->v3C0, &pv->v3C0, &pv->p358->pos);
        }
        {
            M_00331380 *t = pv->p358;
            func_L01_0045BD10(m, func_0038D160(t->pos.x - m->pos.x, t->pos.y - m->pos.y));
        }
        if (func_L01_004395E0(m) > 11.0f) {
            func_L06_0042B660(0.16000001f, (u8 *)&m->pos, (u8 *)&pv->v3C0);
        }
        if (m->b60 & 2) {
            func_L01_004450F0((u8 *)m, 0xF, -1);
            if (m->b43 != 5) {
                func_003C3A10((u8 *)m, 5, 0, 5);
            }
            func_L01_00456230(pv->p358, 1);
        }
        break;
    case 15:
        if (func_L01_004561B8(m)) {
            pv->w1C8 = 0;
        }
        if (func_L01_0040E570(D_1A4C60, (u8 *)&pv->p358->pos) > 144.0f) {
            if (!func_L19_00335130((u8 *)m) && !func_L19_0030D8F8((u8 *)pv->p358, D_1A4C60)) {
                func_L19_00335330((u8 *)m);
            }
        }
        break;
    case 16: {
        {
            vu0_v4 d;
            vec_sub_ba(&d, &pv->v3C0, &m->pos);
            func_003C4BB0(&d, 0.50000006f);
            vec_add_ab(&m->pos, &m->pos, &d);
            if (m->b42 == m->b43) {
                m->pos = pv->v3C0;
                func_L01_004450F0((u8 *)m, 6, 1);
            }
        }
        break;
    }
    case 17:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 2) {
                func_003C3A10((u8 *)m, 2, func_00382468(m->cls->a50->b10), 8);
            }
        }
        func_L19_00349A18(pv->p358, &m->pos, &pv->v3C0);
        func_L19_003336E0(m);
        if (pv->w1D4 & 0x80) {
            func_L01_004450F0((u8 *)m, 0x12, -1);
            func_L01_00456230(pv->p358, 1);
        }
        break;
    case 18:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 4) {
                func_003C3A10((u8 *)m, 4, 0, 8);
            }
        }
        {
            M_00331380 *t = pv->p358;
            func_L01_0045BD10(m, func_0038D160(t->pos.x - m->pos.x, t->pos.y - m->pos.y));
        }
        if (m->b42 == m->b43) {
            if (func_L01_004395E0(m) >= 10.0f) {
                vu0_v4 a;
                func_003C2F58(m, 2, &a);
                func_L19_00349AF0(pv->p358, a.z - m->pos.z);
            }
            if (m->b60 & 2) {
                func_L01_004450F0((u8 *)m, 6, 1);
                func_L01_00456230(pv->p358, 0);
            }
        }
        break;
    case 19:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 2) {
                func_003C3A10((u8 *)m, 2, func_00382468(m->cls->a50->b10), 8);
            }
        }
        switch (pv->p358->hAA) {
        case 0xB10:
            func_L19_00335748(pv->p358, &pv->v3C0);
            break;
        case 0xF4D:
            func_L19_00335408(pv->p358, &pv->v3C0);
            break;
        }
        func_L19_003336E0(m);
        if (pv->w1D4 & 0x80) {
            func_L01_004450F0((u8 *)m, 0x14, -1);
        }
        break;
    case 20:
        if (func_L01_004561B8(m)) {
            if (m->b43 != 5) {
                func_003C3A10((u8 *)m, 5, 0, 8);
            }
        }
        {
            M_00331380 *t = pv->p358;
            func_L01_0045BD10(m, func_0038D160(t->pos.x - m->pos.x, t->pos.y - m->pos.y));
        }
        if (m->b60 & 2) {
            func_L01_004450F0((u8 *)m, 6, 1);
        } else if (func_L01_0044E1B8(m, 20.0f)) {
            func_L01_00456230(pv->p358, 1);
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
            func_0038D000(&a, &a, m->mtx);
            if (pv->v1E0.z < 0.0f) {
                pv->v1E0.z = pv->v1E0.z - pv->f388;
                if (0.0f < m->fF4) {
                    func_003C41A0(&m->fF4, pv->b38C, 0.0f, 0.010053097f, 0.010053097f, 0.50265485f);
                } else {
                    m->fF4 = func_0038DB00(m->fF4, 0.50265485f);
                }
                if (m->pos.z < pv->f3A0) {
                    f32 g = func_003C3D30(&m->pos, 0, 0, 0.5f);
                    if (m->pos.z <= g) {
                        m->pos.z = g;
                        func_L01_004450F0((u8 *)m, 4, 1);
                    }
                }
            } else {
                pv->v1E0.z = pv->v1E0.z - pv->f384;
                m->fF4 = func_0038DB00(m->fF4, 0.50265485f);
            }
            func_0038D308(m->mtx, &m->fF0);
            func_0038D000(&b, &b, m->mtx);
            vec_sub_ba(&c, &a, &b);
            vec_add_ab(&m->pos, &m->pos, &c);
        }
        break;
    }
    case 23:
        if ((D_L19_001DF240 & 0x3F) == (((s32)m >> 8) & 0x3F) && D_L19_001DCBE0 < D_L19_001DF240) {
            vu0_v4 a;
            vu0_v4 b;
            M_00331380 *t = (M_00331380 *)func_L19_00334CF0(m, &a, &b);
            if (t != 0) {
                m->h34 &= 0xFFBE;
                m->h34 |= m->cls->h44 & 0x1000;
                m->w98 = m->cls->w10;
                qzero(&pv->v1E0);
                pv->w218 = -1;
                D_L19_001DCBE0 = D_L19_001DF240 + 0x32;
                if (t->hAA == 0x1BB2) {
                    func_L01_004450F0((u8 *)m, 1, 0);
                    func_L01_00456230(t, 0);
                    pv->p354 = t;
                    m->pos = t->pos;
                    *(M_00331380 **)t->pv = m;
                } else {
                    func_L01_004450F0((u8 *)m, 4, 1);
                    func_L03_003F6A80(m, &a, &b, 0, 0);
                }
            }
        }
        break;
    }
    func_L19_00333FC0((u8 *)m);
    func_L01_004436F4(m);
}
/* localdecomp:end func_L19_00331380 */

INCLUDE_ASM("asm/levels", func_L19_00332948);

/* localdecomp:start func_L19_00332D38 */
/* PAL port of the NTSC-U match src/us/levels/func_L19_00332360.c */


extern Hero_00332360 D_1A4BE0;
extern s32 D_L19_001E8E58_00332360[];
extern f32 func_L01_0040E570(u8 *, u8 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *func_L19_003345D0(u8 *);
extern u8 *func_L19_003347B0(u8 *a0);
extern u8 *func_L19_00334958(u8 *arg0);
extern u8 *func_L19_00334B10(u8 *a0);
extern s32 func_L19_00335130(u8 *a0);
extern void func_L19_00335330(u8 *obj);

void func_L19_00332D38(Obj_00332360 *a) {
    St_00332360 *s;
    s32 mode;
    f32 d;
    u8 *r;
    V4_00332360 va;
    V4_00332360 vb;

    mode = D_1A4BE0.w286C;
    s = a->p68;
    if (mode == 0) {
        return;
    }
    if (a->b20 == 0xC) {
        return;
    }
    if (a->b95 == 7) {
        return;
    }
    if ((a->d30 & 0x104100000000ul) == 0x4100000000ul) {
        if (a->w98 == 0) {
            return;
        }
    }
    if (s->w360 != 0) {
        return;
    }
    if (a->b95 == 4 && mode != 6) {
        return;
    }
    if (a->b95 == 5 && mode != 5) {
        return;
    }
    if (a->b20 == 1) {
        if (s->w350 == 0) {
            return;
        }
        if (mode != 1) {
            return;
        }
        d = func_L01_0040E570((u8 *)&D_1A4BE0 + 0x80, (u8 *)a + 0x10);
        if (d < 144.0f) {
            va = *(V4_00332360 *)((u8 *)a + 0x10);
            vb = *(V4_00332360 *)((u8 *)&D_1A4BE0 + 0x80);
            va.z = va.z + 1.0f;
            vb.z = vb.z + 1.0f;
            if (func_003D3CB0(&va, &vb, 0, a, 0) == 0 || D_L19_001E8E58_00332360[0] == D_1A4BE0.w25C0) {
                func_L01_004450F0(a, 4, 1);
            }
        }
        return;
    }
    switch (mode) {
    case 1:
        if (a->b95 != 1) {
            func_L01_004450F0(a, 3, 1);
        } else if (a->b20 != 3) {
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 3:
        if (a->b95 != 2 && a->hAA == 0x964) {
            func_L01_004450F0(a, 10, 2);
        }
        break;
    case 2:
        if (a->b95 != 0) {
            func_L01_004450F0(a, 2, 0);
        }
        break;
    case 4:
        if (a->hAA == 0x964) {
            s->w360 = 25;
            if (a->b95 != 3) {
                r = func_L19_003345D0(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 11, 3);
                }
            }
        }
        break;
    case 6:
        if (a->hAA == 0x940) {
            s->w360 = 25;
            if (a->b95 != 4) {
                r = func_L19_003347B0(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 13, 4);
                }
            } else if (a->b20 == 0xD) {
                func_L01_004450F0(a, 4, 1);
            } else if (a->b20 == 0xF) {
                if (func_L19_00335130(a) == 0) {
                    func_L19_00335330(a);
                }
            }
        }
        break;
    case 5:
        if (a->hAA == 0x93C) {
            s->w360 = 25;
            if (a->b95 != 5) {
                r = func_L19_00334958(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 17, 5);
                }
            } else if (a->b20 != 0x12) {
                func_L01_00456230(s->p358, 0);
                s->p358 = 0;
                func_L01_004450F0(a, 4, 1);
            }
        }
        break;
    case 7:
        if (a->hAA == 0xA59) {
            s->w360 = 25;
            if (a->b95 != 6) {
                r = func_L19_00334B10(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 19, 6);
                }
            } else if (a->b20 != 0x14) {
                func_L01_00456230(s->p358, 0);
                s->p358 = 0;
                func_L01_004450F0(a, 4, 1);
            }
        }
        break;
    case 8:
        if (a->hAA == 0x964) {
            if (a->b95 != 1) {
                func_L01_004450F0(a, 4, 1);
            }
        } else {
            func_L01_004450F0(a, 6, 1);
        }
        break;
    }
}
/* localdecomp:end func_L19_00332D38 */

/* localdecomp:start func_L19_00333160 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[2];
    u8 b38;
    u8 pad39[0x140 - 0x39];
    f32 f140;
    f32 f144;
    f32 f148;
    f32 f14C;
    f32 f150;
    u8 pad154[0x16C - 0x154];
    f32 f16C;
    f32 f170;
    f32 f174;
    u8 pad178[0x188 - 0x178];
    u8 *p188;
    u8 *p18C;
    u8 pad190[0x230 - 0x190];
    u8 a230[0x80];
    u8 a2B0[0xA0];
    s32 w350;
    u8 pad354[4];
    s32 w358[14];
    u8 pad390[0x10];
    s32 w3A0;
    f32 f3A4;
    s32 w3A8;
    u8 pad3AC[4];
    s32 w3B0;
    s32 w3B4;
    u8 pad3B8[4];
    f32 f3BC;
    vu0_v4 v3C0;
    vu0_v4 v3D0;
} S_00333160;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[4];
    u8 *p24;
    u8 pad28[0xC];
    u16 h34;
    u8 pad36[0xD];
    u8 b43;
    u8 pad44[0x24];
    S_00333160 *s;
    u8 pad6C[0x12];
    u8 b7E;
    u8 pad7F[0x2B];
    s16 hAA;
    u8 padAC[0x14];
    vu0_v4 vC0;
} A_00333160;

extern s32 D_L19_001DCBE0 __attribute__((section(".sdata")));
extern s32 D_L19_001DCBD4 __attribute__((section(".sdata")));
extern s32 D_L19_001DCBD0 __attribute__((section(".sdata")));
__asm__(".extern D_L19_001DCBE0, 4");
__asm__(".extern D_L19_001DCBD4, 4");
__asm__(".extern D_L19_001DCBD0, 4");
extern s32 func_00382468(s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L19_00333468(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L19_00333160(u8 *arg0) {
    A_00333160 *a = (A_00333160 *)arg0;
    S_00333160 *s = a->s;
    vu0_v4 v;
    f32 y;

    if (func_00382468(2)) {
        a->h34 |= 0x8000;
    } else {
        a->h34 &= 0x7FFF;
    }
    a->b7E |= 1;
    D_L19_001DCBE0 = 0;
    D_L19_001DCBD4 = 0;
    a->pos.z = func_003C3D30(&a->pos, 0, 0, 0.5f);
    if (s->w350 == 0) {
        func_L19_00333468(arg0);
    }
    s->f30 = 1.0f;
    s->h34 = 1;
    s->b38 = 3;
    s->f174 = 0.5f;
    s->f140 = 0.1f;
    s->f144 = 0.1f;
    s->f148 = 0.5f;
    s->f14C = 0.5f;
    s->f150 = 1.5882496f;
    s->f170 = 0.5235988f;
    s->p188 = s->a230;
    s->p18C = s->a2B0;
    s->f16C = 0.008f;
    switch (a->hAA) {
    case 0x93C:
        s->f140 = 0.42f;
        a->pos.z += 0.089f;
        break;
    case 0x940:
        s->f140 = 0.39f;
        a->pos.z += 0.089f;
        func_0038CF68(&v, &a->vC0, -0.2f);
        vec_add_ba(&a->pos, &v, &a->pos);
        break;
    case 0xA59:
        s->f140 = 0.42f;
        a->pos.z += 0.089f;
        break;
    default:
        s->f140 = 0.1f;
        a->pos.z += 0.089f;
        break;
    }
    s->w358[0] = 0;
    s->w358[1] = 0;
    s->w358[2] = 0;
    s->w358[3] = 0;
    s->w358[4] = 0;
    s->w358[5] = 0;
    s->w358[6] = 0;
    s->w358[7] = 0;
    s->w358[8] = 0;
    s->w358[9] = 0;
    s->w358[10] = 0;
    s->w358[11] = 0;
    s->w358[12] = 0;
    s->w358[13] = 0;
    s->w3A0 = 0;
    y = a->pos.z;
    s->f3A4 = y;
    s->w3A8 = -1;
    s->w3B0 = D_L19_001DCBD0++;
    s->w3B4 = 0;
    if (s->f3BC <= -999.0f) {
        s->f3BC = y - 10.0f;
    }
    qzero(&s->v3C0);
    qzero(&s->v3D0);
    func_L01_004450F0(arg0, 1, 0);
    if (a->hAA == 0xA59) {
        if (a->b43 != 6) {
            func_003C3A10(arg0, 6, 0, 0);
        }
    } else if (a->b43 != 0) {
        func_003C3A10(arg0, 0, func_00382468(*(u8 *)(*(u8 **)(a->p24 + 0x48) + 0x10)), 0);
    }
}
/* localdecomp:end func_L19_00333160 */

/* localdecomp:start func_L19_00333468 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern u16 D_L19_001DCBDC;
__asm__(".extern D_L19_001DCBDC, 2");

void func_L19_00333468(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (*(s16 *)(a0 + 0xAA) == 0x964) {
        if (*(s32 *)(s + 0x3B8) != 0) {
            *(u8 **)(s + 0x354) = func_003C24B0(0x1BB2, 0x80);
            if (*(u8 **)(s + 0x354) != 0) {
                func_L01_00456160(*(u8 **)(s + 0x354), a0);
                *(s16 *)(*(u8 **)(s + 0x354) + 0x32) = 0x30;
                **(u8 ***)(*(u8 **)(s + 0x354) + 0x68) = a0;
            }
        } else {
            *(u8 **)(s + 0x354) = func_003C24B0(0x972, 0x80);
            if (*(u8 **)(s + 0x354) != 0) {
                func_L01_00456160(*(u8 **)(s + 0x354), a0);
                *(s16 *)(*(u8 **)(s + 0x354) + 0x32) = 0x30;
            }
        }
    } else {
        *(u8 **)(s + 0x354) = func_003C24B0(0xD75, 0x80);
        if (*(u8 **)(s + 0x354) != 0) {
            func_L01_00456160(*(u8 **)(s + 0x354), a0);
            *(u16 *)(*(u8 **)(s + 0x354) + 0x7C) = D_L19_001DCBDC;
            *(s16 *)(*(u8 **)(s + 0x354) + 0x32) = 0x30;
            if (*(s16 *)(a0 + 0xAA) == 0x93C) {
                u8 *m = *(u8 **)(s + 0x354);
                *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.2f;
            }
        }
    }
}
/* localdecomp:end func_L19_00333468 */

/* localdecomp:start func_L19_00333580 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_00332BA8;

extern s32 func_00382380(void *, s32, s32);
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern u8 *D_L19_001DF800;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));

void func_L19_00333580(u8 *arg0, Vec4_00332BA8 v) {
    u8 *s2;
    u16 *s1;
    s32 idx;
    s32 start;
    u8 *ent;
    u8 *s0;
    u8 *m;

    s2 = *(u8 **)(arg0 + 104);
    *(Vec4_00332BA8 *)(s2 + 960) = v;
    start = *(s32 *)(s2 + 912);
    if (start < 0) {
        return;
    }
    for (s1 = D_L19_0021C260[start];
         (idx = *(s32 *)(s2 + 912), (idx & 0xFF) != 255) && D_L19_001DF758 >= idx && s1 != 0 &&
         ((s16)s1[-1] >= 0 || s1 == D_L19_0021C260[idx]);
         s1++) {
        ent = D_L19_001DF71C + ((*s1 & 0x7FFF) << 8);
        if (ent == 0) {
            return;
        }
        s0 = *(u8 **)(ent + 104);
        if (func_00382380(s2 + 960, *(s32 *)s0, 0) != 0) {
            if (*(s32 *)(s0 + 8) < 0 || func_00382380(arg0 + 16, *(s32 *)(s0 + 8), 0) != 0) {
                m = (u8 *)((*(s32 *)(s0 + 4) << 7) + (s32)D_L19_001DF800);
                if (fabs_asm(*(f32 *)(m + 56) - *(f32 *)(arg0 + 24)) < 2.5f) {
                    *(u128_t *)(s2 + 960) = *(u128_t *)(m + 48);
                    return;
                }
            }
        }
    }
}
/* localdecomp:end func_L19_00333580 */

/* localdecomp:start func_L19_003336E0 */
extern s32 func_L19_003337D8(u8 *, s32, vu0_v4 *, vu0_v4 *, s32 *, s32, s32);
extern s32 func_L01_0045A748(void *, void *);
extern void func_L19_00334F80(u8 *a0, float a1);

void func_L19_003336E0(void *arg0) {
    u8 *self = arg0;
    u8 *v = *(u8 **)(self + 0x68);
    u128_t t;
    u8 *e;
    u8 *tg;
    f32 a;

    t = *(u128_t *)(v + 0x3C0);
    func_L19_003337D8(self, *(s32 *)(v + 0x3AC), (vu0_v4 *)&t, (vu0_v4 *)(v + 0x3D0), (s32 *)(v + 0x3A8), *(s32 *)(v + 0x358), 0);
    func_L01_0045A748(self, &t);
    if (*(u8 **)(v + 0x1C4) == 0) {
        return;
    }
    e = *(u8 **)(v + 0x1C8);
    if (e != 0 && *(s16 *)(e + 0xAA) == 0x97A) {
        a = *(f32 *)(self + 0xF8);
    } else {
        e = *(u8 **)(v + 0x1C4);
        a = func_0038D160(*(f32 *)(e + 0x10) - *(f32 *)(self + 0x10), *(f32 *)(e + 0x14) - *(f32 *)(self + 0x14));
        {
            f32 d = func_0038DB00(a, *(f32 *)(self + 0xF8));
            f32 lim = 1.5707964f;
            if (d < 0.0f) {
                lim = -1.5707964f;
            }
            a = func_0038DAB8(lim, *(f32 *)(self + 0xF8));
        }
    }
    func_L19_00334F80(self, a);
}
/* localdecomp:end func_L19_003336E0 */

/* localdecomp:start func_L19_003337D8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x12];
    s16 count;
    u8 pad14[0xC];
    s32 *ids;
    u8 pad24[0xC];
} E_003337D8;

typedef struct {
    s32 count;
    u8 pad4[0x1C];
    E_003337D8 e[1];
} T_003337D8;

extern T_003337D8 *D_L19_001DF34C;
extern s32 D_L19_001E8E58_00332360[];
extern u8 *D_L19_001DF800;
extern f32 func_L01_0040E570(u8 *, u8 *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_00382380(void *, s32, s32);

s32 func_L19_003337D8(u8 *a0, s32 idx, vu0_v4 *pos, vu0_v4 *goal, s32 *cur, s32 who, s32 skip) {
    E_003337D8 *e;
    vu0_v4 vb;
    vu0_v4 va;
    vu0_v4 d;
    f32 dist;
    f32 nd;
    f32 best_d;
    s32 best;
    s32 i;
    s32 id;
    u8 *m;

    if (idx < 0 || idx >= D_L19_001DF34C->count) {
        return 1;
    }
    e = &D_L19_001DF34C->e[idx];
    vb = *(vu0_v4 *)(a0 + 0x10);
    va = *pos;
    vb.z = vb.z + 0.4f;
    va.z = va.z + 0.4f;
    dist = func_L01_0040E570((u8 *)&vb, (u8 *)&va);
    vec_sub_ab(&d, &va, &vb);
    func_0038CE20(&d, &d, sqrt_asm(dist));
    if (skip == 0) {
        if (func_003D3CB0(&vb, &va, 2, a0, 0) == 0 || (D_L19_001E8E58_00332360[0] == who && who != 0)) {
            *cur = -1;
            *goal = *pos;
            return 1;
        }
    }
    best = -1;
    best_d = dist * 4.0f + 100.0f;
    for (i = 0; i < e->count; i++) {
        id = e->ids[i];
        m = D_L19_001DF800 + (id << 7);
        if (id == *cur) {
            continue;
        }
        if (func_00382380(&vb, id, 0) != 0) {
            *cur = e->ids[i];
            continue;
        }
        m += 0x30;
        nd = func_L01_0040E570((u8 *)&va, m);
        if (best_d < nd) {
            continue;
        }
        if (func_003D3CB0(&vb, m, 2, a0, 0) == 0) {
            best_d = nd;
            best = i;
        }
    }
    if (best < 0) {
        if (func_L01_0040E570((u8 *)pos, (u8 *)goal) > 0.25f) {
            *pos = *goal;
        } else {
            return 0;
        }
    } else {
        *pos = *(vu0_v4 *)((u8 *)((e->ids[best] << 7) + (s32)D_L19_001DF800) + 0x30);
    }
    return 1;
}
/* localdecomp:end func_L19_003337D8 */

/* localdecomp:start func_L19_00333A80 */
#include "vu0.h"
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
void func_L19_00333A80(void *arg0, void *arg1) {
    u8 *a0 = (u8 *)arg0;
    u8 *s;
    vu0_v4 v;
    vu0_v4 m[4];
    f32 yaw;
    f32 pitch;
    if (*(s16 *)(a0 + 0xAA) == 0x93C && a0[0x43] == 1) {
        return;
    }
    s = *(u8 **)(a0 + 0x68);
    vec_sub_ab(&v, arg1, a0 + 0x10);
    func_0038D5B0(m, a0 + 0xC0);
    func_0038D000(&v, &v, m);
    switch (*(s16 *)(a0 + 0xAA)) {
    case 0x964:
        v.z -= 0.1f;
        break;
    case 0x93C:
    case 0x940:
    case 0xA59:
        v.z -= 0.8f;
        break;
    }
    yaw = func_0038D160(v.x, v.y);
    if (yaw > 1.5707964f) {
        yaw = 1.5707964f;
    } else if (yaw < -1.5707964f) {
        yaw = -1.5707964f;
    }
    yaw *= 0.5f;
    pitch = -func_0038D160(func_0038CED8(&v), v.z);
    if (pitch > 0.7853982f) {
        pitch = 0.7853982f;
    } else if (pitch < -0.7853982f) {
        pitch = -0.7853982f;
    }
    pitch *= 0.5f;
    *(f32 *)(s + 0x298) = yaw;
    *(f32 *)(s + 0x318) = yaw;
    *(f32 *)(s + 0x294) = pitch;
    *(f32 *)(s + 0x314) = pitch;
}
/* localdecomp:end func_L19_00333A80 */

/* localdecomp:start func_L19_00333C60 */
extern s32 func_L01_0045A9F0(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L19_00333A80(void *, void *);
extern s32 D_001A4CC0[];

void func_L19_00333C60(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    func_L01_0045A9F0(a0);
    if (a0[0x31] == 0) {
        return;
    }
    if (func_0038CAD0(s0 + 0x374) != 0) {
        if (a0[0x95] == 2) {
            *(f32 *)(s0 + 0x378) = func_L01_00443A18(0.08726646f, 1.0471976f);
            *(f32 *)(s0 + 0x37C) = func_003824E0(-0.34906584f, 0.0f);
            *(s32 *)(s0 + 0x374) = func_00382498(25, 37);
            *(s32 *)(s0 + 0x380) = 0;
        } else if (func_00382468(4) == 0) {
            *(s32 *)(s0 + 0x380) = 1;
            *(s32 *)(s0 + 0x374) = func_00382498(150, 250);
        } else {
            *(f32 *)(s0 + 0x378) = func_L01_00443A18(0.08726646f, 0.34906584f);
            *(f32 *)(s0 + 0x37C) = func_003824E0(-0.2617994f, 0.08726646f);
            *(s32 *)(s0 + 0x374) = func_00382498(50, 100);
            *(s32 *)(s0 + 0x380) = 0;
        }
    }
    if (*(s32 *)(s0 + 0x380) != 0) {
        func_L19_00333A80(a0, D_001A4CC0);
    } else {
        f32 u = *(f32 *)(s0 + 0x37C);
        f32 v = *(f32 *)(s0 + 0x378);
        *(f32 *)(s0 + 0x314) = u;
        *(f32 *)(s0 + 0x318) = v;
        *(f32 *)(s0 + 0x294) = u;
        *(f32 *)(s0 + 0x298) = v;
    }
}
/* localdecomp:end func_L19_00333C60 */

/* localdecomp:start func_L19_00333DC0 */
/* modelled on func_L19_003345D0 in the same file */
extern f32 func_L01_0040E570(u8 *, u8 *);

u8 *func_L19_00333DC0(u8 *a0) {
    Grp_003345D0 *o = *(Grp_003345D0 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best = 0;
    f32 bestd = 225.0f;
    f32 d;
    s32 i;

    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (e[0x20] == 0xFE)
                continue;
            if (e[0x20] == 0xFD)
                continue;
            if ((*(u16 *)(e + 0x34) & 0x1000) && (*(u8 **)(e + 0x24))[0x46] == 5 &&
                fabs_asm(*(f32 *)(a0 + 0x18) - *(f32 *)(e + 0x18)) < 1.5f) {
                d = func_L01_0040E570(a0 + 0x10, e + 0x10);
                if (d < bestd) {
                    bestd = d;
                    best = e;
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L19_00333DC0 */

/* localdecomp:start func_L19_00333FC0 */
extern void func_L01_0044ABD0(void *a, void *b);
extern s32 func_0038CAD0(void *a);
extern void func_L19_003340A0(void *a);
extern void func_L01_0044E850(void *a, void *b, s32 c, f32 d, f32 e);
extern u8 D_001D5470;
__asm__(".extern D_001D5470, 16");

void func_L19_00333FC0(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    func_L01_0044ABD0(obj, st + 0x70);
    if (*(u16 *)(obj + 0x96) < 0xFFFF) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
    func_0038CAD0(st + 0x360);
    func_L19_003340A0(obj);
    if (D_001D5470 != 0 && obj[0x20] != 1) {
        *(f32 *)(st + 0x2A0) = 1.75f;
    }
    func_L01_0044E850(obj, st + 0x230, 1, 0.0432f, 0.43200004f);
    func_L01_0044E850(obj, st + 0x2B0, 0, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L19_00333FC0 */

/* localdecomp:start func_L19_003340A0 */
typedef struct { s32 a, b; } Col_003340A0;
typedef struct { u8 pad[0x78]; s32 f78; } O_003340A0;
extern f32 D_L19_001DCC28;
__asm__(".extern D_L19_001DCC28, 4");
extern f32 D_L19_001DCC2C;
__asm__(".extern D_L19_001DCC2C, 4");
extern f32 D_L19_001DCC30;
__asm__(".extern D_L19_001DCC30, 4");
extern f32 D_L19_001DCC34;
__asm__(".extern D_L19_001DCC34, 4");
extern s32 D_L19_001DCBE8[2];
__asm__(".extern D_L19_001DCBE8, 8");
extern s32 D_L19_001DCBF0[2];
__asm__(".extern D_L19_001DCBF0, 8");
extern s32 D_L19_001DCBF8[2];
__asm__(".extern D_L19_001DCBF8, 8");
extern s32 D_L19_001DCC00[2];
__asm__(".extern D_L19_001DCC00, 8");
extern s32 D_L19_001DCC10[2];
__asm__(".extern D_L19_001DCC10, 8");
extern s32 D_L19_001DCC18[2];
__asm__(".extern D_L19_001DCC18, 8");
extern s32 D_L19_001DCC20[2];
__asm__(".extern D_L19_001DCC20, 8");
extern s32 D_L19_001DF240;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L19_003343A8(u8 *);

void func_L19_003340A0(void *a) {
    u8 *a0 = a;
    u8 *p = *(u8 **)(a0 + 0x68);
    Col_003340A0 c;
    f32 w;
    u16 *q;
    u8 *e;

    if (a0[0x31] == 0) {
        return;
    }
    switch (a0[0x95]) {
    case 1:
    case 7:
        c.a = D_L19_001DCBF0[0];
        c.b = D_L19_001DCBF0[1];
        w = D_L19_001DCC30 * 0.017453292f * 0.020000001f;
        break;
    case 8:
        c.a = D_L19_001DCBF8[0];
        c.b = D_L19_001DCBF8[1];
        w = D_L19_001DCC34 * 0.017453292f * 0.020000001f;
        break;
    case 2:
        c.a = D_L19_001DCBF8[0];
        c.b = D_L19_001DCBF8[1];
        w = D_L19_001DCC2C * 0.017453292f * 0.020000001f;
        break;
    case 3:
        c.a = D_L19_001DCC10[0];
        c.b = D_L19_001DCC10[1];
        w = D_L19_001DCC2C * 0.017453292f * 0.020000001f;
        break;
    case 4:
        c.a = D_L19_001DCC20[0];
        c.b = D_L19_001DCC20[1];
        w = D_L19_001DCC2C * 0.017453292f * 0.020000001f;
        break;
    case 5:
        c.a = D_L19_001DCC18[0];
        c.b = D_L19_001DCC18[1];
        w = D_L19_001DCC2C * 0.017453292f * 0.020000001f;
        break;
    case 6:
        c.a = D_L19_001DCC00[0];
        c.b = D_L19_001DCC00[1];
        w = D_L19_001DCC2C * 0.017453292f * 0.020000001f;
        break;
    case 0:
    default:
        c.a = D_L19_001DCBE8[0];
        c.b = D_L19_001DCBE8[1];
        w = D_L19_001DCC28 * 0.017453292f * 0.020000001f;
        break;
    }
    *(f32 *)(p + 0x35C) = func_0038DAB8(*(f32 *)(p + 0x35C), w);
    ((O_003340A0 *)a0)->f78 = func_0038DBD8(c.a, c.b, func_0038D0B0(*(f32 *)(p + 0x35C)) * 0.5f + 0.5f);
    if (*(s32 *)(p + 0x368) != D_L19_001DF240) {
        for (q = D_L19_0021C260[a0[0x21]];
             a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[a0[0x21]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            *(s32 *)(*(u8 **)(e + 0x68) + 0x368) = D_L19_001DF240;
        }
        func_L01_00404808(func_L19_003343A8, a0);
    }
}
/* localdecomp:end func_L19_003340A0 */

/* localdecomp:start func_L19_003343A8 */
extern s32 D_L19_001DCC38[] __attribute__((section(".sdata"))); __asm__(".extern D_L19_001DCC38, 4");
extern s32 D_L19_001DCC50[] __attribute__((section(".sdata"))); __asm__(".extern D_L19_001DCC50, 4");
extern s32 D_L19_001DCC60[] __attribute__((section(".sdata"))); __asm__(".extern D_L19_001DCC60, 4");
extern s32 D_L19_001DCC70[] __attribute__((section(".sdata"))); __asm__(".extern D_L19_001DCC70, 4");
extern t1v D_L19_001DCC80[] __attribute__((section(".sdata"))); __asm__(".extern D_L19_001DCC80, 4");
extern t1v D_L19_001DCCB0[] __attribute__((section(".sdata"))); __asm__(".extern D_L19_001DCCB0, 4");
extern t1v D_L19_001DCCE0[] __attribute__((section(".sdata"))); __asm__(".extern D_L19_001DCCE0, 4");
extern t1v D_L19_002B1F50[];
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);

void func_L19_003343A8(u8 *a0) {
    u16 *q;
    u8 *e;
    s32 *names;
    t1v *pos;
    s32 n;
    s32 i;
    f32 sc;
    u8 m[0x40];
    t1v v;

    for (q = D_L19_0021C260[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && q != 0 &&
         ((s16)q[-1] >= 0 || q == D_L19_0021C260[a0[0x21]]);
         q++) {
        e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
        if (e == 0)
            return;
        if (e[0x31] == 0)
            continue;
        if (e[0x20] == 0xFE)
            continue;
        if (e[0x20] == 0xFD)
            continue;
        switch (*(s16 *)(e + 0xAA)) {
        case 0x940:
            names = D_L19_001DCC60;
            pos = D_L19_001DCCB0;
            n = 3;
            break;
        case 0x93C:
            names = D_L19_001DCC50;
            pos = D_L19_001DCC80;
            n = 3;
            break;
        case 0x964:
            names = D_L19_001DCC38;
            pos = D_L19_002B1F50;
            n = 5;
            break;
        default:
            names = D_L19_001DCC70;
            pos = D_L19_001DCCE0;
            n = 3;
            break;
        }
        for (i = 0; i < n; i++) {
            func_003C2EC0(e, names[i], m);
            v = pos[i];
            sc = v.w * *(f32 *)(e + 0x2C) / *(f32 *)(*(u8 **)(e + 0x24) + 0x24);
            v.w = 1.0f;
            func_0038D028(&v, &v, m);
            func_003C5458(&v, *(s32 *)(e + 0x78), sc, 0.08f);
        }
    }
}
/* localdecomp:end func_L19_003343A8 */

/* localdecomp:start func_L19_003345D0 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));
extern s32 func_L19_003556B0(u8 *);
extern f32 func_L01_0040E570(u8 *, u8 *);

u8 *func_L19_003345D0(u8 *a0) {
    Grp_003345D0 *o = *(Grp_003345D0 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best = 0;
    f32 bestd = 225.0f;
    f32 d;
    s32 i;

    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (fabs_asm(*(f32 *)(a0 + 0x18) - *(f32 *)(e + 0x18)) < 2.0f) {
                if (*(s16 *)(e + 0xAA) == 0xEF9) {
                    if (func_L19_003556B0(e)) {
                        d = func_L01_0040E570(a0 + 0x10, e + 0x10);
                        if (d < bestd) {
                            bestd = d;
                            best = e;
                        }
                    }
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L19_003345D0 */

/* localdecomp:start func_L19_003347B0 */
extern s32 func_L19_0030D8F8(u8 *, u8 *);
extern u8 D_1A4C60[];


u8 *func_L19_003347B0(u8 *a0) {
    Obj_003347B0 *o = *(Obj_003347B0 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    s32 i = 0;

    while (i < 8) {
        u16 **tbl = D_L19_0021C260;
        for (q = tbl[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF &&
             o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == tbl[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(s16 *)(e + 0xAA) == 0x97A) {
                if (func_L19_0030D8F8(e, a0 + 0x10))
                    return e;
                if (func_L19_0030D8F8(e, D_1A4C60))
                    return e;
            }
        }
        i++;
    }
    return 0;
}
/* localdecomp:end func_L19_003347B0 */

/* localdecomp:start func_L19_00334958 */
extern s32 func_L07_003BEAB0(void *);
extern f32 func_L01_0040E570(u8 *, u8 *);
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));


u8 *func_L19_00334958(u8 *arg0) {
    GroupState_00334958 *o = *(GroupState_00334958 **)(arg0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best = 0;
    f32 bestd = 196.0f;
    f32 d;
    s32 i;

    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(u16 *)(e + 0xAA) == 0xE87 || *(u16 *)(e + 0xAA) == 0xE88) {
                if (func_L07_003BEAB0(e)) {
                    d = func_L01_0040E570(arg0 + 0x10, e + 0x10);
                    if (d < bestd) {
                        bestd = d;
                        best = e;
                    }
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L19_00334958 */

/* localdecomp:start func_L19_00334B10 */
extern s32 func_L07_003BCDC0(void *);
extern f32 func_L01_0040E570(u8 *, u8 *);


u8 *func_L19_00334B10(u8 *a0) {
    Obj_00334B10 *o = *(Obj_00334B10 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best = 0;
    f32 bestd = 100.0f;
    f32 d;
    s32 c;
    s32 i;

    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (e[0x20] == 0xFE)
                continue;
            if (e[0x20] == 0xFD)
                continue;
            c = *(s16 *)(e + 0xAA);
            if (c == 0xB10 || c == 0xF4D) {
                if (c == 0xF4D && func_L07_003BCDC0(e) == 0)
                    continue;
                d = func_L01_0040E570(a0 + 0x10, e + 0x10);
                if (d < bestd) {
                    bestd = d;
                    best = e;
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L19_00334B10 */

/* localdecomp:start func_L19_00334CF0 */
/* log: written from the sibling loops of L19_00331380.c */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00334CF0;
typedef struct {
    u8 pad[0x330];
    s32 ids[8];
    u8 pad350[4];
    u8 *target;
} Vars_00334CF0;
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

u8 *func_L19_00334CF0(u8 *a0, V4_00334CF0 *pos, V4_00334CF0 *dir) {
    Vars_00334CF0 *o = *(Vars_00334CF0 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best;
    f32 bestd;
    f32 d;
    s32 i;
    V4_00334CF0 t;

    if (o->target != 0) {
        bestd = func_L01_0040E548(a0 + 0x10, o->target + 0x10);
    } else {
        bestd = 1000000.0f;
    }
    best = o->target;
    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(s16 *)(e + 0xAA) == 0x972) {
                d = func_L01_0040E548(a0 + 0x10, e + 0x10);
                if (d < bestd) {
                    t = *(V4_00334CF0 *)(e + 0x10);
                    t.z += 1.0f;
                    if (func_L01_003FB640(&t, 0, a0, 0.5f) == 0) {
                        bestd = d;
                        best = e;
                    }
                }
            } else if (*(s16 *)(e + 0xAA) == 0x1BB2 && e[0x20] == 3) {
                f32 d2 = func_L01_0040E548(a0 + 0x10, e + 0x10);
                if (d2 < bestd) {
                    bestd = d2;
                    best = e;
                }
            }
        }
    }
    if (best != 0) {
        *dir = *(V4_00334CF0 *)(best + 0xF0);
        *pos = *(V4_00334CF0 *)(best + 0x10);
        pos->z = func_003C3D30(pos, 0, 0, 0.5f);
    }
    return best;
}
/* localdecomp:end func_L19_00334CF0 */

/* localdecomp:start func_L19_00334F80 */
#include "vu0.h"
extern void func_003C5060(u8 *, float *, float *, int);

void func_L19_00334F80(u8 *a0, float a1) {
    vu0_v4 v;
    unsigned short *p;
    u8 *e;
    u8 *s;
    if (a0[0x21] == 0xFF)
        return;
    for (p = D_L19_0021C260[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L19_0021C260[a0[0x21]]);
         p++) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x20] == 1)
            continue;
        if (e[0x95] < 2) {
            vec_sub_ab(&v, e + 0x10, a0 + 0x10);
            func_003C5060(a0, &v.x, &v.x, 0);
            if (v.x > 0.0f && v.x < 1.0f && fabs_asm(v.y) < 0.7f && fabs_asm(v.z) < 0.5f) {
                s = *(u8 **)(e + 0x68);
                func_L01_004450F0(e, 5, 1);
                *(float *)(s + 0x364) = a1;
                *(short *)(e + 0x96) = 0;
            }
        }
    }
}
/* localdecomp:end func_L19_00334F80 */

/* localdecomp:start func_L19_00335130 */
extern s32 D_001A4F3C[];

s32 func_L19_00335130(u8 *a0) {
    u8 *s;
    u16 *p;
    u8 *e;

    if (D_001A4F3C[0] == *(s32 *)(*(u8 **)(a0 + 0x68) + 0x358))
        return 1;
    s = *(u8 **)(a0 + 0x68);
    if (a0[0x21] == 0xFF)
        return 0;
    for (p = D_L19_0021C260[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L19_0021C260[a0[0x21]]);
         p++) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s32 *)(*(u8 **)(e + 0x68) + 0x1C8) == *(s32 *)(s + 0x358))
            return 1;
    }
    return 0;
}
/* localdecomp:end func_L19_00335130 */

/* localdecomp:start func_L19_00335210 */
extern f32 func_L01_0040E570(u8 *, u8 *);
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));

int func_L19_00335210(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 d;
    u16 *p;
    u8 *e;

    d = func_L01_0040E570(a0 + 0x10, a1);
    for (p = D_L19_0021C260[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L19_0021C260[a0[0x21]]);
         p++) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 1;
        if (e == a0)
            continue;
        if (*(s32 *)(*(u8 **)(e + 0x68) + 0x358) == *(s32 *)(s + 0x358) &&
            func_L01_0040E570(e + 0x10, a1) < d)
            return 0;
    }
    return 1;
}
/* localdecomp:end func_L19_00335210 */

/* localdecomp:start func_L19_00335330 */
extern void func_L19_0030D9A8(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern char D_001A4C60[];


void func_L19_00335330(u8 *obj) {
    t0v t0;
    t1v t1;
    u8 *vars = *(u8 **)(obj + 0x68);
    func_L19_0030D9A8(*(void **)(vars + 0x358), D_001A4C60, &t0);
    t1 = t0;
    t1.z += *(f32 *)(vars + 0x140) + *(f32 *)(vars + 0x144);
    if (func_L01_003FB640(&t1, 0, obj, *(f32 *)(vars + 0x140)) == 0) {
        *(t0v *)(vars + 0x3C0) = t0;
        func_L01_00456230(*(void **)(vars + 0x358), 0);
        *(s32 *)(vars + 0x358) = 0;
        *(s32 *)(obj + 0x98) = (*(s32 **)(obj + 0x24))[4];
        func_L01_004450F0(obj, 0x10, 4);
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 0x11);
        }
    }
}
/* localdecomp:end func_L19_00335330 */
