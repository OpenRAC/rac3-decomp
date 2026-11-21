#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00360D80 */
typedef struct {
    char pad0[0x10];
    s32 w10;
    char pad14[0x24 - 0x14];
    f32 f24;
    char pad28[0x44 - 0x28];
    u16 h44;
} Cls_00360D80;

typedef struct Moby_00360D80 {
    char pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 b21;
    char pad22[2];
    Cls_00360D80 *cls;
    char pad28[0x2C - 0x28];
    f32 f2C;
    u8 b30;
    u8 b31;
    u16 h32;
    u16 flags;
    char pad36[0x43 - 0x36];
    u8 b43;
    char pad44[0x68 - 0x44];
    struct Vars_00360D80 *pv;
    char pad6C[0x6F - 0x6C];
    u8 b6F;
    char pad70[0x95 - 0x70];
    u8 b95;
    char pad96[2];
    s32 w98;
    char pad9C[0xAA - 0x9C];
    s16 hAA;
    char padAC[0xB2 - 0xAC];
    s16 hB2;
    char padB4[0xD0 - 0xB4];
    vu0_v4 vD0;
    vu0_v4 vE0;
    char padF0[0xF8 - 0xF0];
    f32 fF8;
    char padFC[0x100 - 0xFC];
} Moby_00360D80;

typedef struct Vars_00360D80 {
    char pad0[0x30];
    f32 f30;
    s16 h34;
    char pad36[0x38 - 0x36];
    u8 b38;
    u8 b39;
    char pad3A[0x3E - 0x3A];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 b44;
    u8 b45;
    u8 b46;
    char pad47[0x58 - 0x47];
    u8 b58;
    char pad59;
    u8 b5A;
    char pad5B[0x5E - 0x5B];
    u8 b5E;
    u8 b5F;
    char pad60;
    u8 b61;
    char pad62[0x70 - 0x62];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    char pad84[0x9C - 0x84];
    f32 f9C;
    f32 fA0;
    char padA4[0xA8 - 0xA4];
    s32 wA8;
    char padAC[0xBC - 0xAC];
    void *pBC;
    char padC0[0x160 - 0xC0];
    u8 x160[0x10];
    u8 b170;
    u8 b171;
    u8 b172;
    char pad173[0x176 - 0x173];
    u8 b176;
    char pad177[0x17C - 0x177];
    f32 f17C;
    f32 f180;
    f32 f184;
    f32 f188;
    f32 f18C;
    f32 f190;
    f32 f194;
    char pad198[0x19C - 0x198];
    f32 f19C;
    f32 f1A0;
    char pad1A4[0x1A8 - 0x1A4];
    u8 b1A8;
    u8 b1A9;
    s16 h1AA;
    char pad1AC[0x1CC - 0x1AC];
    u8 b1CC;
    u8 b1CD;
    u8 b1CE;
    u8 b1CF;
    char pad1D0[0x1D7 - 0x1D0];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    s32 w1DC;
    char pad1E0[0x210 - 0x1E0];
    f32 f210;
    char pad214[0x220 - 0x214];
    vu0_v4 v220;
    void *w230;
    s16 h234;
    char pad236[0x240 - 0x236];
    struct Moby_00360D80 *w240;
    char pad244[0x250 - 0x244];
    s32 w250;
    char pad254[0x25E - 0x254];
    u8 b25E;
    u8 b25F;
    char pad260[0x2E0 - 0x260];
    s32 w2E0;
    f32 f2E4;
    s32 w2E8;
    f32 f2EC;
    s32 w2F0;
    s16 h2F4;
    char pad2F6[2];
    s32 w2F8;
    struct Moby_00360D80 *o2FC;
    s32 w300;
    s32 w304;
    char pad308[0x30C - 0x308];
    s32 w30C;
    long d310;
    s32 w318;
    char pad31C[0x320 - 0x31C];
    vu0_v4 v320;
    vu0_v4 v330;
    char pad340[0x360 - 0x340];
    s32 w360;
    s32 w364;
    char pad368[0x36C - 0x368];
    f32 f36C;
    char pad370[0x374 - 0x370];
    s32 w374;
    char pad378[0x380 - 0x378];
    s32 w380;
    char pad384[0x390 - 0x384];
    u8 x390[0x490 - 0x390];
    vu0_v4 v490;
    s32 w4A0;
    s32 w4A4;
    char pad4A8[0x4B0 - 0x4A8];
    struct Moby_00360D80 *parts[8];
    s32 w4D0;
    s32 w4D4;
    s32 w4D8;
    s32 w4DC;
    s32 w4E0;
    s32 w4E4;
    char pad4E8[0x4EC - 0x4E8];
    s32 w4EC;
    s32 w4F0;
    char pad4F4[0x4FC - 0x4F4];
    s32 w4FC;
    s32 w500;
    char pad504[0x50C - 0x504];
    s32 w50C;
    s32 w510;
    s32 w514;
    s32 w518;
} Vars_00360D80;

extern s32 func_L04_00361208(Moby_00360D80 *);
extern void func_L01_004AA7E8(Moby_00360D80 *, s32);
extern void func_003C7C38(Moby_00360D80 *);
extern void func_L01_00446A70(Moby_00360D80 *, Moby_00360D80 *, s32, void *, void *, f32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00446058(Moby_00360D80 *, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern s32 func_L04_00361DF8(Moby_00360D80 *);
extern void func_L04_00362490_00360D80(Moby_00360D80 *, s32);
extern s32 func_L04_004C1158(Moby_00360D80 *, void *);
extern void func_L04_003626F0(Moby_00360D80 *);
extern s32 D_L04_001D6694;
extern vu0_v4 D_L04_001D66B0 __attribute__((section(".sdata")));
extern vu0_v4 D_L04_001E27C0;
extern u8 D_L04_001DD7D8[] __attribute__((section(".sdata")));
extern s32 D_L04_001DD7A4;
__asm__(".extern D_L04_001DD7A4, 4");
extern f32 D_L04_001DA8B0;
__asm__(".extern D_L04_001DA8B0, 4");
extern f32 D_L04_001DA8B8;
__asm__(".extern D_L04_001DA8B8, 4");
extern f32 D_L04_002F1D90[];
extern f32 D_L04_002F1F70[];
extern s32 D_001D545C;
extern u8 D_0014275C[];
extern u8 D_0014275B[];

void func_L04_00360D80(Moby_00360D80 *m) {
    Vars_00360D80 *p = m->pv;

    if (m->state == 0 && func_L04_00361208(m) == 0) {
        return;
    }
    if (D_L04_001D6694 == 2) {
        if (((u8)m->flags ^ 1) & 1) {
            m->w98 = 0;
            m->flags = (m->flags | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            p->o2FC->flags |= 0x41;
            p->o2FC->flags &= 0xEFFF;
            p->o2FC->w98 = 0;
            func_L01_004AA7E8(p->o2FC, 1);
            p->w514 = 1;
        }
        return;
    }
    if (p->w514 != 0) {
        m->flags &= 0xFFBE;
        m->flags |= m->cls->h44 & 0x1000;
        m->w98 = m->cls->w10;
        p->o2FC->flags &= 0xFFBE;
        p->o2FC->flags |= p->o2FC->cls->h44 & 0x1000;
        p->o2FC->w98 = p->o2FC->cls->w10;
        p->w514 = 0;
    }
    if (m->b95 != 5 && p->f30 <= 0.0f) {
        vu0_v4 c;

        m->w98 = m->cls->w10;
        func_003C7C38(m);
        c = D_L04_001D66B0;
        func_L01_00446A70(m, m, 0x10000, &m->pos, &D_L04_001D66B0, 100.0f);
    }
    if (p->w4EC != -1 && m->b95 != 7 && m->state != 0 && D_001D545C == 0xD) {
        if (func_L01_00456500(&D_L04_001E27C0, p->w4EC) == 0) {
            m->w98 = 0;
            m->flags = (m->flags | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            return;
        }
        m->flags &= 0xFFBE;
        m->flags |= m->cls->h44 & 0x1000;
        m->w98 = m->cls->w10;
    }
    if (m->flags & 1) {
        if (p->o2FC != 0) {
            p->o2FC->flags |= 1;
        }
    } else {
        if (p->o2FC != 0) {
            p->o2FC->flags &= 0xFFFE;
        }
    }
    if ((D_L04_001DD7A4 != 0 || D_0014275C[0] != 0 || D_001D545C == 0x16) && p->w4FC == 0) {
        if (D_001D545C != 0x16) {
            func_L01_00446058(m, 0x1BA2, 0x16E5);
            if (D_001D545C == 0x10 || D_001D545C == 4 || D_001D545C == 9) {
                p->h34 = 0x2D;
                p->b44 = 0x23;
                if (func_L01_0041A4F0() != 0) {
                    p->h34 = p->h34 * ((D_001D545C == 7 && D_0014275B[0] != 0) ? D_L04_001DA8B0 : D_L04_002F1D90[D_001D545C]);
                    p->b44 = p->b44 * ((D_001D545C == 7 && D_0014275B[0] != 0) ? D_L04_001DA8B8 : D_L04_002F1F70[D_001D545C]);
                }
                p->b45 = p->b44;
                p->b46 = p->b44;
                p->f30 = p->h34;
            }
        } else {
            func_L01_00446058(m, 0x1F05, 0x16E5);
        }
        m->hAA = 0x16E5;
        p->w4FC = 1;
    } else if (D_0014275C[0] == 0 && p->w518 == 0 && (D_001D545C == 0xD || D_001D545C == 0x10 || D_001D545C == 0xC)) {
        p->w518 = 1;
        func_L01_00446058(m, 0x1F04, 0x16E5);
        m->hAA = 0x16E5;
    }
    if (func_L04_00361DF8(m) != 0) {
        func_L04_00362490_00360D80(m, 1);
        return;
    }
    if (func_L04_004C1158(m, D_L04_001DD7D8) != 0) {
        func_L04_003626F0(m);
    }
}
/* localdecomp:end func_L04_00360D80 */

/* localdecomp:start func_L04_00361208 */
typedef struct {
    void (*fn0)(Moby_00360D80 *);
} Iface_00361208;

typedef struct {
    char pad0[0x10];
    vu0_v4 v10;
    char pad20[0x30 - 0x20];
    vu0_v4 v30;
    char pad40[0x78 - 0x40];
    f32 f78;
    char pad7C[0x80 - 0x7C];
} Node_00361208;

extern s32 func_L01_00446058(Moby_00360D80 *, s32, s32);
extern void func_L01_004AA7E8(Moby_00360D80 *, s32);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045BD78(Moby_00360D80 *, f32, f32, f32, f32);
extern Moby_00360D80 *func_003C24B0(s32, s32);
extern void func_L01_00456160(Moby_00360D80 *, Moby_00360D80 *);
extern Iface_00361208 *func_L01_0043B548_00361208(s32, s32);
extern void func_003C3A10(Moby_00360D80 *, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004450F0(Moby_00360D80 *, s32, s32);
extern void func_L04_00362DF0_00361208(Moby_00360D80 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 D_L04_001DD6C8;
__asm__(".extern D_L04_001DD6C8, 4");
extern Moby_00360D80 *D_L04_001DFD9C;
extern Moby_00360D80 *D_L04_001DFDA0;
extern Node_00361208 *D_L04_001DFE80;
extern vu0_v4 D_L04_001E95A0;
extern s32 D_001D545C;

s32 func_L04_00361208(Moby_00360D80 *m) {
    Vars_00360D80 *p = m->pv;
    Moby_00360D80 **pp;
    void *bc;
    s32 n = 0;
    s32 i;
    Moby_00360D80 *it;
    Node_00361208 *q;
    Iface_00361208 *f;
    vu0_v4 a;
    vu0_v4 b;

    D_L04_001DD6C8 = 0;
    p->w50C = 0;
    if (p->w4E4 != 0) {
        p->w4A4 = 1;
    }
    p->w4D8 = 0;
    pp = p->parts;
    p->b3F = 0;
    bc = p->x390;
    for (i = 7; i >= 0; i--) {
        p->parts[i] = 0;
    }
    if (m->hAA == 0x1BA2) {
        p->w364 = m->hAA;
        func_L01_00446058(m, 0x1BA2, 0x16E5);
    } else {
        p->w364 = 0x16E5;
    }
    for (it = D_L04_001DFD9C; it < D_L04_001DFDA0; it++) {
        if (it->hAA == 0x1BAF) {
            pp[n] = it;
            it->w98 = 0;
            it->flags = (it->flags | 0x41) & 0xEFFF;
            func_L01_004AA7E8(it, 1);
            n++;
            if (n >= 8) {
                break;
            }
        }
    }
    if ((func_00382468(2) != 0 || p->w4F0 != 0) && p->w4F0 != -1) {
        m->flags |= 0x8000;
    }
    m->f2C = m->cls->f24;
    p->v490 = m->pos;
    if (p->w304 != -1) {
        q = &D_L04_001DFE80[p->w304];
        p->v320 = q->v30;
        func_0038CF68(&p->v330, &q->v10, 1.0f);
        p->f36C = q->f78;
    } else {
        p->v320 = m->pos;
        p->v330 = m->vD0;
        p->f36C = m->fF8;
    }
    if (p->w30C != -1) {
        p->w318 = 1;
    }
    if (p->w4E4 != 0) {
        p->w318 = 1;
    }
    p->b170 = 0x19;
    p->b1A8 = 5;
    p->b171 = 0xF;
    p->b1D8 = 0;
    p->b1DB = 0x14;
    p->b172 = 0x11;
    p->b1CE = 6;
    p->b1CF = 0xC;
    p->b176 = 0x12;
    p->b1CC = 0;
    p->b1CD = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    p->b1D7 = 1;
    p->b1A9 = 1;
    p->f17C = 0.3f;
    p->f180 = 0.020000001f;
    p->f184 = 0.010000001f;
    p->f188 = 0.014f;
    p->f18C = 0.00080000004f;
    p->f190 = 2.5f;
    p->f194 = 0.75f;
    p->f19C = 0.35f;
    if (D_001D545C == 0xC) {
        p->h1AA = 0x280B;
    }
    p->f1A0 = m->pos.z - 10.0f;
    if (p->w250 != 0) {
        p->f210 = 1.0f;
    }
    if (D_001D545C == 0xC) {
        p->f210 = 0.5f;
    }
    p->w1DC = p->w4DC;
    if (D_001D545C == 0xD) {
        p->f1A0 = m->pos.z - 30.0f;
    }
    p->pBC = bc;
    p->f70 = 0.7f;
    p->f74 = 0.3f;
    p->f78 = 1.0f;
    p->f7C = 2.0f;
    p->f80 = 1.4835298f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.008f;
    func_L01_0045BD78(m, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->w4E4 != 0) {
        p->f78 = 0.7f;
        p->f7C = 0.7f;
        p->wA8 |= 4;
        m->flags |= 0x100;
        p->f80 = 12.566371f;
        p->w318 = 1;
        p->wA8 |= 1;
    }
    if (p->h34 == 0) {
        p->h34 = 0x14;
        p->f30 = 20.0f;
    }
    p->f40 = 1.2f;
    p->b38 = 1;
    p->b39 = 1;
    if (p->w4E0 == 0) {
        p->o2FC = func_003C24B0(0x194E, 0x80);
        if (p->o2FC != 0) {
            func_L01_00456160(p->o2FC, m);
            p->o2FC->h32 = m->h32;
            p->w240 = p->o2FC;
        }
    }
    p->b3E = 1;
    p->b5E = 0;
    p->b5F = 0;
    p->w2F0 = 0;
    p->h2F4 = 0;
    p->w2F8 = 0;
    p->w360 = 0;
    if (p->w250 > 0) {
        f = func_L01_0043B548_00361208(0x19E1, 0x6C);
        p->w250 = -1;
        if (m->b43 != 0) {
            func_003C3A10(m, 0, 0, 0);
        }
        p->b25E = 0x1C;
        p->b25F = 9;
        f->fn0(m);
        if (p->o2FC != 0) {
            func_003C2880(p->o2FC);
            p->o2FC = 0;
            p->w240 = 0;
        }
        return 0;
    }
    if (p->w374 != 0) {
        if (p->w380 != 0) {
            p->v320 = m->pos;
        }
        func_L01_004450F0(m, 0x1A, 7);
        m->w98 = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        if (p->o2FC != 0) {
            p->o2FC->flags |= 0x41;
            p->o2FC->flags &= 0xEFFF;
            p->o2FC->w98 = 0;
            func_L01_004AA7E8(p->o2FC, 1);
        }
    } else if (p->w4E0 != 0) {
        func_L04_00362DF0_00361208(m);
    } else {
        func_L01_004450F0(m, 1, 1);
        if (m->b43 != 0) {
            func_003C3A10(m, 0, 0, 0);
        }
        if (p->w4A0 != 0 && m->b43 != 4) {
            func_003C3A10(m, 4, 0, 0);
        }
        if (p->d310 != -1) {
            func_L01_004450F0(m, 5, 6);
        }
        if (p->w300 != -1) {
            func_L01_004450F0(m, 2, -1);
        } else if (p->w318 == 0) {
            func_L01_004450F0(m, 4, -1);
        }
    }
    if (D_001D545C == 0x10 && p->w4E4 != 0) {
        func_0038CF68(&a, &m->vE0, 2.0f);
        func_0038CF68(&a, &m->vE0, -1.0f);
        if (func_003D3CB0(&a, &b, 0, m, 0) != 0) {
            m->pos = D_L04_001E95A0;
        }
    }
    return 1;
}
/* localdecomp:end func_L04_00361208 */

INCLUDE_ASM("asm/levels", func_L04_00361948);

/* localdecomp:start func_L04_00361BD0 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L02_00431568(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 D_L04_001DD6E0;
__asm__(".extern D_L04_001DD6E0, 4");
extern f32 D_L04_001DD6CC;
__asm__(".extern D_L04_001DD6CC, 4");

void func_L04_00361BD0(u8 *a0, u8 *a1, f32 t) {
    vu0_v4 p;
    vu0_v4 d;
    f32 x;
    f32 lim;

    func_0038CF68(&p, a1 + 0x330, D_L04_001DD6CC * t);
    vec_add_ab(&p, &p, a1 + 0x320);
    vec_sub_ab(&d, a1 + 0x220, &p);
    x = 3.1415927f - func_0038DBA0(*(f32 *)(a1 + 0x36C), func_0038D160(d.x, d.y));
    lim = D_L04_001DD6E0 * 0.017453292f;
    if (lim < x) {
        x = lim;
    }
    if (0.0f < func_0038CE68(a1 + 0x330, &d)) {
        x = func_0038DB00(*(f32 *)(a1 + 0x36C), x);
    } else {
        x = func_0038DAB8(*(f32 *)(a1 + 0x36C), x);
    }
    func_L02_00431568(a0, &p, 0x10, func_0038D160(p.x - *(f32 *)(a0 + 0x10), p.y - *(f32 *)(a0 + 0x14)), -1.0f, -1.0f, -1.0f);
    func_L01_0045BD10(a0, x);
}
/* localdecomp:end func_L04_00361BD0 */

/* localdecomp:start func_L04_00361D20 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 D_L04_001DD6E0;
__asm__(".extern D_L04_001DD6E0, 4");

s32 func_L04_00361D20(void *a0, u8 *a1) {
    vu0_v4 d;
    if (*(s32 *)(a1 + 0x308) == 0) {
        return 0;
    }
    if (a1[0x5F] != 0) {
        return 0;
    }
    vec_sub_ba(&d, a1 + 0x220, a1 + 0x320);
    if (3.1415927f - func_0038DBA0(*(f32 *)(a1 + 0x36C), func_0038D160(d.x, d.y)) < D_L04_001DD6E0 * 0.017453292f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00361D20 */

/* localdecomp:start func_L04_00361DB8 */
s32 func_L04_00361DB8(u8 *a0) {
    u8 t;
    if ((u32)(a0[0x20] - 0x12) >= 7) {
        t = a0[0x95];
        if (t != 5 && t != 8 && t != 7) {
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L04_00361DB8 */

/* localdecomp:start func_L04_00361DF8 */
typedef struct {
    char pad0[0x80];
    vu0_v4 pos;
    char pad90[0xD0 - 0x90];
    vu0_v4 vD0;
    char padE0[0x25C0 - 0xE0];
    void *moby;
} Hero_00361DF8;

typedef struct {
    char pad0[0x6C];
    f32 f6C;
    char pad70[0xF0 - 0x70];
} Row_00361DF8;

extern void func_003C7C38(Moby_00360D80 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(Moby_00360D80 *);
extern s32 func_L04_00361DB8_00361DF8(Moby_00360D80 *, Vars_00360D80 *);
extern void func_L01_004450F0(Moby_00360D80 *, s32, s32);
extern void func_003C3A10(Moby_00360D80 *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0044FD88(Moby_00360D80 *, Moby_00360D80 *, s32, s32);
extern s32 func_L01_00452FB0(Moby_00360D80 *, void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, Moby_00360D80 *);
extern void func_L01_00445BE0(s32, s32);
extern void func_L04_003627C8(Moby_00360D80 *);
extern s32 func_L01_00452860(Moby_00360D80 *, void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L04_00362568(Moby_00360D80 *);
extern void func_L01_00456BD0(Moby_00360D80 *, s32);
extern void func_L01_00456C98(Moby_00360D80 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00456500(void *, s32);
extern vu0_v4 D_L04_001E2840;
extern Moby_00360D80 *D_L04_001E0E78;
extern Row_00361DF8 D_L04_002C5F40[];
extern u8 D_00142637[];
extern s32 D_L04_001D67C4;
extern s32 D_L04_001DF940;
extern s32 D_001D545C;
extern Hero_00361DF8 D_001A4BE0;

s32 func_L04_00361DF8(Moby_00360D80 *m) {
    Vars_00360D80 *p = m->pv;
    s32 i;
    s32 hp;
    s32 r;
    u8 t;

    if (0.0f < p->f30) {
        for (i = 0; i < 8; i++) {
            if (p->parts[i] != 0) {
                p->parts[i]->w98 = p->parts[i]->cls->w10;
                func_003C7C38(p->parts[i]);
            }
        }
    }
    if (m->b31 != 0 && func_L01_0040E548(&D_L04_001E2840, &m->pos) < 576.0f) {
        func_L01_004472C0(m);
        m->b6F = 0x16;
    }
    if (p->b3E == 2) {
        func_L04_00362568(m);
        return 1;
    }
    if (p->b61 == 0x3F && func_L04_00361DB8_00361DF8(m, p) != 0) {
        func_L01_004450F0(m, 0x1D, -1);
        if (m->b43 != 0x14) {
            func_003C3A10(m, 0x14, 1, 2);
        }
    }
    if (D_L04_001E0E78 != 0 && func_L04_00361DB8_00361DF8(m, p) != 0 &&
        func_0038CF38(&m->pos, &D_L04_001E0E78->pos) < 6.0f &&
        p->f30 <= (D_L04_002C5F40 + D_00142637[0])->f6C) {
        func_L01_004450F0(m, 0x1D, -1);
        if (m->b43 != 0x14) {
            func_003C3A10(m, 0x14, 1, 2);
        }
    }
    if (p->o2FC != 0) {
        func_L01_0044FD88(m, p->o2FC, 0, 0);
    }
    hp = p->f30;
    if (p->w4E4 != 0) {
        r = func_L01_00452FB0(m, p->x160, 0, 0, 1);
        if (r != 0) {
            if (r >= 2) {
                func_003A52A0(5, 0, m);
            }
            for (i = 0; i < 8; i++) {
                if (p->parts[i] != 0) {
                    p->parts[i]->w98 = 0;
                    func_003C7C38(p->parts[i]);
                }
            }
            if (m->b21 != 0xFF) {
                func_L01_00445BE0(m->b21, 0);
            }
            func_L04_003627C8(m);
        }
    } else if (func_L01_00452FB0(m, p->x160, 0, 0, 0) != 0) {
        func_003A52A0(5, 0, m);
        for (i = 0; i < 8; i++) {
            if (p->parts[i] != 0) {
                p->parts[i]->w98 = 0;
                func_003C7C38(p->parts[i]);
            }
        }
        if (m->b21 != 0xFF) {
            func_L01_00445BE0(m->b21, 0);
        }
        func_L04_003627C8(m);
    }
    if (p->f30 < (f32)hp) {
        p->w2F8 = 1;
        func_L04_003627C8(m);
    }
    func_L01_00452860(m, &p->f30, 0);
    if (p->b5F != 0 && D_001D545C == 0x16 && p->w50C == 0) {
        p->w50C = 1;
        if (++D_L04_001D67C4 >= 15) {
            func_L01_00459C50(0x17);
        }
    }
    if (p->b5E != 0) {
        func_L04_00362568(m);
        return 1;
    }
    if (((*(unsigned long *)&m->b30 & 0x104100000000L) != 0x4100000000L || m->w98 != 0) && 0.0f < p->f30) {
        if (p->b5F != 0) {
            func_L01_00456BD0(m, 5);
        } else if (D_001D545C != 9 || m->hB2 == 0xCA || m->b95 == 3 || m->b95 == 5) {
            func_L01_00456BD0(m, 3);
        }
    }
    if ((m->hB2 + 8) % 8 == D_L04_001DF940 % 8) {
        if (p->b5F != 0) {
            if (m->b95 == 1) {
                func_L01_00456C98(m, p->w2E0, 0, 0, 0, 0, 3, 0, 0, 0, p->f2E4, 10.0f, 1.0f);
            } else {
                func_L01_00456C98(m, p->w2E8, 0, 0, 0, 0, 3, 0, 0, 0, p->f2EC, 10.0f, 1.0f);
            }
        } else if (m->b95 == 1 || m->b95 == 8) {
            func_L01_00456C98(m, p->w2E0, 0, 0, 0, 0, 1, p->w500 != 0, 0, p->w510 != 0, p->f2E4, 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, p->w2E8, 0, 0, 0, 0, 1, p->w500 != 0, 0, p->w510 != 0, p->f2EC, 10.0f, 1.0f);
        }
    }
    if (p->w4D0 != -1 && p->w4D4 != -1 && (p->h234 != 1 || D_001D545C == 0x1D)) {
        t = m->b95;
        if (t == 1 || t == 4 || t == 2 || (D_001D545C == 0x1D && t == 3)) {
            if (func_L01_00456500(&D_001A4BE0.pos, p->w4D0) != 0) {
                p->w4D8 = 1;
                p->w230 = D_001A4BE0.moby;
                p->v220 = D_001A4BE0.vD0;
            } else {
                p->w4D8 = 0;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L04_00361DF8 */

/* localdecomp:start func_L04_00362490 */
typedef struct {
    void (*fn0)(void *);
    void (*fn4)(void *);
} Iface;

typedef struct {
    char pad0[0x240];
    s32 unk240;
    char pad244[0x250 - 0x244];
    s32 unk250;
    char pad254[0x2FC - 0x254];
    void *unk2FC;
    char pad300[0x4E0 - 0x300];
    s32 unk4E0;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Moby;

extern void func_003C2880(void *);
extern Iface *func_L01_0043B548(s32, s32);
extern void func_L04_00362DF0(Moby *);

void func_L04_00362490(Moby *m, s32 arg1) {
    Vars *v = m->vars;
    Iface *it;

    if (v->unk2FC != 0) {
        func_003C2880(v->unk2FC);
        v->unk2FC = 0;
        v->unk240 = 0;
    }
    if (v->unk250 != 0) {
        it = func_L01_0043B548(6625, 108);
        it->fn0(m);
        if (arg1 != 0) {
            it->fn4(m);
        }
    } else if (v->unk4E0 != 0) {
        func_L04_00362DF0(m);
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L04_00362490 */
