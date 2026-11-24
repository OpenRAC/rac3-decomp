/* PAL near miss (round 21/23, carried from Sonnet b22 M1 round 8; reproduced by round 23 W9): func_L10_003B4698 (4088 bytes), the level 10 menu/pause
 * handler: a state switch (jump table, 50 entries) over self->state, about 70 calls, `jalr`-free, many gp globals.
 * Standalone check (python tools/check.py <this file> func_L10_003B4698 --no-context, no INCLUDE_ASM, it carries its own typedefs): 1022 of 1022 words,
 * 658 raw / 96 aligned (difflib) / about 40 aligned with the saved registers renamed. It does not splice into src/levels/10_zeldrin_starport/L10_003B4350.c
 * (type conflicts with that file's declarations). Contains a `switch` (50-entry jump table): any match needs the manager's level build.
 * Left: 60 of the 96 words are ONE swap: retail self = $s4 and the table base (D_001BBC40: `lui $a0,0x1c; addiu $s3,$a0,-0x43c0`) = $s3, ours the reverse
 * (the 0xFE constant of the three `== 0xFE` compares follows the base: $s3 in retail). global.c priorities: self 27 refs / 847 insns = 0.127, base 6 refs /
 * 132 insns = 0.091, so ours allocates self first; refs are equal in retail, so the formula alone does not explain it. Tried in round 23: a `u8 *tbl = D_001BBC40;`
 * local for every table access (153 aligned, worse). Other leftovers: addu operand order of obj_at(), v0/v1 of the D_1F2040 loads, the s1 copy, one `move v1,v0`,
 * the second quad copy register, jump-table reloc lines. A second local variable for a second loop fixed a $s3/$s4 swap in func_L02_00350478 (live ranges
 * merge when one variable serves two loops): not applicable here (no loop variable), but look for a pseudo that serves two lifetimes. */
#include "common.h"

typedef int Q10 __attribute__((mode(TI)));

typedef struct M10 {
    s32 w0, w4, w8, wC, w10;
    s16 h14, h16;
    s32 w18, w1C, w20, w24, w28, w2C;
    s32 a30[7];
    s32 w4C;
    s32 a50[5];
    s32 w64, w68, w6C, w70, w74, w78, w7C, w80, w84;
} M10;

typedef struct Self10 {
    u8 p00[0x20];
    u8 state;
    u8 p21[0xF];
    u8 b30;
    u8 p31[0x37];
    M10 *m;
    u8 p6C[0x29];
    u8 b95;
} Self10;

typedef struct Src10 {
    u8 p0[0x10];
    s32 w10;
    u8 p14[0x30];
    u16 h44;
} Src10;

struct Obj10;
typedef struct Rec10 {
    u8 p0[8];
    s32 w8;
    s32 wC;
    u8 p10[0x7C];
    s32 w8C;
    s32 w90;
    u8 p94[0xB];
    u8 b9f;
    u8 pA0[0x23C];
    struct Obj10 *o2DC;
    u8 p2E0[0x5C];
    s32 w33C;
    u8 p340[0x64];
    s32 w3A4;
    u8 p3A8[0x20];
    s32 w3C8;
    u8 p3CC[0x20];
    struct Obj10 *o3EC;
    u8 p3F0[0x568];
    s32 w958;
} Rec10;

typedef struct Obj10 {
    u8 p00[0x10];
    Q10 q10;
    u8 b20;
    u8 p21[3];
    Src10 *src;
    u8 p28[8];
    u8 b30;
    u8 b31;
    u8 p32[2];
    u16 flags;
    u8 p36[0x2E];
    void (*fn64)(struct Obj10 *);
    Rec10 *rec;
    u8 p6C[0x29];
    u8 b95;
    u8 p96[2];
    s32 w98;
    u8 p9C[0xE];
    s16 id;
    u8 pAC[0x44];
    Q10 qF0;
} Obj10;

extern u8 D_001BBC40[];
extern s32 D_001D545C_003B4698;
__asm__(".extern D_001D545C_003B4698, 16");
extern u8 D_001426E0[];
extern u8 D_00142BA0[];
extern s32 D_L10_001F2040[];
extern struct {
    u8 *p;
} D_L10_001DF380;
extern u8 *D_L10_001DF29C;
__asm__(".extern D_L10_001DF29C, 4");
extern u8 *D_L10_001DF29C_003B4698;
__asm__(".extern D_L10_001DF29C_003B4698, 16");
extern u8 *D_L10_001DF2A0;
extern s32 D_L10_001DEC50_unused;
extern f32 D_L10_001DEC50;
extern s32 D_L10_001E1520;
__asm__(".extern D_L10_001E1520, 4");
extern s32 D_L10_001E1520_003B4698;
__asm__(".extern D_L10_001E1520_003B4698, 16");
extern s32 D_L10_001D6694_003B4698;
__asm__(".extern D_L10_001D6694_003B4698, 16");
extern s32 D_L10_001E5F30[];
extern u8 *D_001A4F3C[];
extern s32 D_L10_001DE740;
__asm__(".extern D_L10_001DE740, 4");
extern s32 D_L10_001DE744;
__asm__(".extern D_L10_001DE744, 4");
extern s32 D_L10_001DE748;
__asm__(".extern D_L10_001DE748, 4");
extern s32 D_L10_001DE74C;
__asm__(".extern D_L10_001DE74C, 4");
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u32 D_001A8588[];
extern u32 D_001A8594[];
extern s32 D_L10_001E0860[];
extern void func_L10_003B57A8(void);
extern s32 D_001CCFD0_h;
typedef struct G10 {
    u8 p0[0x24];
    s32 w24;
    u8 p28[0x20];
    s16 h48;
    u8 p4A[4];
    s16 h4E;
    u8 p50[0x1C];
    s32 w6C;
    u8 p70[6];
    s16 h76;
    u8 p78[0x1C];
    s32 w94;
    s16 h98;
    u8 p9A[4];
    s16 h9E;
} G10;
extern G10 D_001CCFD0;
extern u8 *D_001D52FC;
extern s32 D_002CF830[];
extern s32 D_L10_001E0864;

extern void func_0039EF28(void);
extern void func_003C2880(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_0042B068(s32, s32);
extern s32 func_L10_004F76E8(void);
extern void func_L01_00511A40(void *, s32, f32);
extern s32 func_L01_004BA800(void);
extern void func_L01_004B0EE0(void);
extern void func_L01_004A3610(void *, void *);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_003A1930(s32, s32, s32);
extern void func_0038CAD0(s32 *);
extern s32 func_00382380(void *, s32, s32);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);
extern s32 func_L10_004399A0(s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L10_003B4600(void);
extern void func_L01_00456230(void *, s32);
extern void func_L01_00452658(s32, s32);
extern void func_0038A238(s32);
extern void func_L01_0043B510(s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L05_00451150(void *, s32);
extern s32 func_L01_0044C108(void *);
extern void func_L05_0035A568(void *, s32);
extern void func_L10_003B8ED0(void *, s32);
extern void func_L06_0034FCC8(void *, s32);
extern s32 *func_003E6C08(void);
extern s32 func_L10_004F8E78(char *, int);
extern s32 func_0038CB00(s16 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_003B1DB8(void *);
extern void func_L10_003B5B48(void *);
extern s32 func_L01_004561B8(void *);
extern void func_003A1C28(void);
extern void func_0013C170(void);
extern void func_L10_003B4350(s32, s32);
extern void func_L01_004EDE10(void);

static __inline__ Obj10 *obj_at(s32 i) {
    return (Obj10 *)(D_L10_001DF29C_003B4698 + (i << 8));
}

/* localdecomp:start func_L10_003B4698 */
void func_L10_003B4698(Self10 *self) {
    M10 *m = self->m;
    Obj10 *o;
    u8 *h1;
    s32 w24;
    G10 *g;
    Obj10 *w2;
    s32 *t60;
    s32 *x60;
    Rec10 *r2;

    if (D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80) {
        D_001426E0[2] = 1;
        func_0039EF28();
    }
    if (D_001BBC40[m->w20 + (D_001D545C_003B4698 << 4)] & 0x80) {
        u8 *p = D_001426E0;
        p[0x20] = 1;
        func_0039EF28();
        p[0x7A] = 1;
        func_0039EF28();
    }
    switch (self->state) {
    case 0:
        if ((D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80) &&
            !(D_001BBC40[m->w20 + (D_001D545C_003B4698 << 4)] & 0x80)) {
            func_L01_004F50C8(D_L10_001DF380.p + (m->w10 << 7) + 0x30, D_L10_001DF380.p + (m->w10 << 7) + 0x70, 0, 1);
            if (D_L10_001F2040[0] != 1) {
                func_L01_0042B068(1, 0);
            }
        }
        self->b95 = 0;
        if (D_001BBC40[m->w20 + (D_001D545C_003B4698 << 4)] & 0x80) {
            for (o = (Obj10 *)D_L10_001DF29C; (u8 *)o < D_L10_001DF2A0; o++) {
                if (o->id == 0x1C47) {
                    func_003C2880(o);
                }
            }
        }
        self->b30 = 0xFF;
        self->state = 1;
        break;
    case 1:
        if (D_L10_001F2040[0] == 1) {
            if (D_L10_001D6694_003B4698 == 2) {
                obj_at(m->w28)->flags |= 2;
                if (D_L10_001E5F30[0] == 2) {
                    Obj10 *w1 = obj_at(m->w28);
                    w1->b31 = 1;
                    w1->flags &= ~1;
                    w1->q10 = *(Q10 *)((u8 *)w1->rec + 0x70);
                    w1->qF0 = *(Q10 *)((u8 *)w1->rec + 0x80);
                    func_L01_004F50C8(D_L10_001DF380.p + (m->w10 << 7) + 0x30, D_L10_001DF380.p + (m->w10 << 7) + 0x70, 0x74, 1);
                } else {
                    obj_at(m->w28)->flags |= 1;
                    obj_at(m->w28)->b31 = 0;
                    obj_at(m->w28)->flags &= ~2;
                }
            } else {
                if (D_001A4F3C[0] == (u8 *)obj_at(m->w28)) {
                    if (func_L10_004F76E8() != 0x74 && !(D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80)) {
                        func_L01_00511A40(&obj_at(m->w28)->q10, 0, 1.5707964f);
                    }
                }
                obj_at(m->w28)->flags &= ~1;
                obj_at(m->w28)->b31 = 1;
            }
            if (D_L10_001D6694_003B4698 == 6) {
                if ((D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80) &&
                    !(D_001BBC40[m->w20 + (D_001D545C_003B4698 << 4)] & 0x80)) {
                    func_L01_004B0EE0();
                }
            }
        }
        if (!func_L01_004BA800() && D_L10_001D6694_003B4698 != 6) {
            if (D_L10_001DEC50 <= 0.01f) {
                if (D_L10_001E1520 == 1) {
                    func_L01_004A3610(D_L10_001DF380.p + (m->w4 << 7) + 0x30, D_L10_001DF380.p + (m->w4 << 7) + 0x70);
                    func_L01_00451F60(0x25A, 0x4B, 0);
                    D_L10_001E1520 = 0;
                } else if (D_L10_001E1520 == 2) {
                    func_L01_004A3610(D_L10_001DF380.p + (m->w84 << 7) + 0x30, D_L10_001DF380.p + (m->w84 << 7) + 0x70);
                    func_L01_00451F60(0x25A, 0x4B, 0);
                    D_L10_001E1520_003B4698 = 0;
                } else {
                    D_L10_001E1520 = 0;
                }
            }
            if (D_L10_001F2040[0] == 0) {
                if (D_001CCFD0.h48 != m->w74) {
                    D_001CCFD0.h4E = 5;
                    func_003A1930(m->w74, 1, 0x400);
                }
            } else if (D_L10_001F2040[0] == 1) {
                if (D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80) {
                    if (D_001CCFD0.h48 != m->w7C) {
                        D_001CCFD0.h4E = 5;
                        func_003A1930(m->w7C, 0, 0x400);
                    }
                } else if (D_001CCFD0.h48 != m->w78) {
                    D_001CCFD0.h4E = 5;
                    func_003A1930(m->w78, 1, 0x400);
                }
            }
            func_0038CAD0(&D_L10_001DE744);
            if (self->b95 == 0) {
                g = &D_001CCFD0;
                if (g->w6C == 0 && (w24 = g->w24) == -1 && g->w94 == 0) {
                    s32 s0 = -1;
                    if (!(D_001BBC40[m->w80 + (D_001D545C_003B4698 << 4)] & 0x80)) {
                        if (func_00382380(D_001A4C60, m->w6C, 0)) {
                            m->w6C = w24;
                            s0 = m->w64;
                        } else if (func_00382380(D_001A4C60, m->w70, 0)) {
                            m->w70 = w24;
                            s0 = m->w68;
                        }
                    }
                    if (s0 == -1) {
                        if (D_L10_001DE744 == 0 && D_L10_001F2040[0] == 0) {
                            s32 idx = D_L10_001DE74C;
                            s32 n;
                            if (idx < 8) {
                                if (idx == 0) {
                                    s0 = m->w4C;
                                } else {
                                    s0 = m->a30[idx - 1];
                                }
                            } else {
                                s0 = m->a50[idx - 8];
                            }
                            n = idx + 1;
                            D_L10_001DE74C = n;
                            if (n >= 13) {
                                D_L10_001DE74C = 0;
                                n = D_L10_001DE740;
                            }
                            D_L10_001DE744 = n;
                        }
                    }
                    if (s0 != -1) {
                        func_003A2B68((s0 & 0x3FFF) + 0x7D0, 0);
                        self->b95 = 1;
                    }
                }
            } else if (self->b95 == 1) {
                if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                    func_003A1798();
                    self->b95 = 0;
                }
            }
            if (!(D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80)) {
                u8 *h0 = D_001A4BE0;
                if (func_L10_004399A0(*(s32 *)(h0 + 0x25C0), m->w0)) {
                    u8 *q = D_00142BA0;
                    if (*(s32 *)(q + 0x98) & 0x4000000) {
                        func_L01_00452560(0, 4, 0x855, 1, 0, 0, 0);
                        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                            if (D_002CF830[0] == 4) {
                                if (*(s32 *)(q + 0x9C) >= 0) {
                                    Obj10 *w;
                                    func_L10_003B4600();
                                    w = obj_at(m->w18);
                                    func_L01_00456230(w, 1);
                                    w->flags &= ~2;
                                    w->b30 = 0xFF;
                                    w->fn64(w);
                                } else {
                                    func_L01_004F50C8(D_L10_001DF380.p + (m->w4 << 7) + 0x30, D_L10_001DF380.p + (m->w4 << 7) + 0x70, 0, 1);
                                    func_L01_00452658(0, 4);
                                    if (D_L10_001F2040[0] != 1) {
                                        func_0038A238(8);
                                        D_L10_001DEC50 = 1.0f;
                                        func_L01_0042B068(1, 0);
                                        D_L10_001E1520_003B4698 = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            h1 = D_001A4BE0;
            if (func_L10_004399A0(*(s32 *)(h1 + 0x25C0), m->w8)) {
                if (D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80) {
                    u8 *p = D_001426E0;
                    Obj10 *w;
                    p[0x20] = 1;
                    func_0039EF28();
                    p[0x7A] = 1;
                    func_0039EF28();
                    func_L01_0043B510(m->w20);
                    func_L10_003B4600();
                    w = obj_at(m->w2C);
                    func_L01_00456230(w, 1);
                    w->flags &= ~2;
                    w->b30 = 0xFF;
                    w->fn64(w);
                } else {
                    func_L01_00452560(0, 4, 0x855, 1, 0, 0, 0);
                    if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                        if (D_002CF830[0] == 4) {
                            func_L01_004F50C8(D_L10_001DF380.p + (m->wC << 7) + 0x30, D_L10_001DF380.p + (m->wC << 7) + 0x70, 0, 1);
                            func_L01_00452658(0, 4);
                            if (D_L10_001F2040[0] != 0) {
                                func_0038A238(8);
                                D_L10_001DEC50 = 1.0f;
                                func_L01_0042B068(0, 0);
                                D_L10_001E1520_003B4698 = 2;
                            }
                        }
                    }
                }
            }
            if ((D_001BBC40[m->w1C + (D_001D545C_003B4698 << 4)] & 0x80) &&
                !(D_001BBC40[m->w20 + (D_001D545C_003B4698 << 4)] & 0x80)) {
                s32 a1;
                if (m->h16 == 0) {
                    if (!(D_001A8588[0] & (1 << D_001D545C_003B4698))) {
                        func_L01_0041A5B0(0xCF7, 0x9E);
                    }
                    m->h16 = (s32)((f32)m->h14 * 50.0f);
                    func_L05_00451150(obj_at(m->w24), 0x1647);
                    m->w24 = -1;
                    w2 = obj_at(m->w28);
                    r2 = w2->rec;
                    r2->b9f = 1;
                    w2->q10 = *(Q10 *)((r2->w90 << 7) + D_L10_001DF380.p + 0x30);
                    w2->qF0 = *(Q10 *)((r2->w90 << 7) + D_L10_001DF380.p + 0x70);
                    w2->b20 = 5;
                    r2->w8 = 0;
                    for (o = (Obj10 *)D_L10_001DF29C_003B4698; (u8 *)o < D_L10_001DF2A0; o++) {
                        if (o->id == 0x1625 && func_L01_0044C108(&o->q10)) {
                            {
                                Rec10 *r = o->rec;
                                if (r->w3C8 != 0) {
                                    r->w3C8 = 0;
                                    o->flags &= ~2;
                                    o->flags &= ~4;
                                    if (r->w3A4 == -1) {
                                        o->flags &= ~0x45;
                                        o->flags |= o->src->h44 & 0x1000;
                                        o->w98 = o->src->w10;
                                        r->o3EC->flags &= ~0x41;
                                        r->o3EC->flags |= r->o3EC->src->h44 & 0x1000;
                                        r->o3EC->w98 = r->o3EC->src->w10;
                                        r->o3EC->flags &= ~2;
                                        r->o3EC->flags &= ~4;
                                    }
                                } else if (self != 0 && self->state != 0xFE && self->state != 0xFD) {
                                    func_L05_0035A568(o, 1);
                                    func_003C2880(o);
                                }
                            }
                        } else if (o->id == 0x1612 && func_L01_0044C108(&o->q10)) {
                            {
                                Rec10 *r = o->rec;
                                if (r->w33C != 0) {
                                    r->w33C = 0;
                                    o->b20 = 1;
                                    o->b95 = 0;
                                    o->flags &= ~0x41;
                                    o->flags |= o->src->h44 & 0x1000;
                                    o->w98 = o->src->w10;
                                    r->o2DC->flags &= ~0x41;
                                    r->o2DC->flags |= r->o2DC->src->h44 & 0x1000;
                                    r->o2DC->w98 = r->o2DC->src->w10;
                                } else if (self != 0 && self->state != 0xFE && self->state != 0xFD) {
                                    func_L10_003B8ED0(o, 1);
                                    func_003C2880(o);
                                }
                            }
                        } else if (o->id == 0x1619 && func_L01_0044C108(&o->q10)) {
                            {
                                Rec10 *r = o->rec;
                                if (r->w958 != 0) {
                                    r->w958 = 0;
                                    o->b20 = 1;
                                    o->b95 = 0;
                                    o->flags &= ~0x41;
                                    o->flags |= o->src->h44 & 0x1000;
                                    o->w98 = o->src->w10;
                                } else if (self != 0 && self->state != 0xFE && self->state != 0xFD) {
                                    func_L06_0034FCC8(o, 1);
                                    func_003C2880(o);
                                }
                            }
                        } else if (o->id == 0xB && func_L01_0044C108(&o->q10)) {
                            {
                                if (o->rec->wC != 0) {
                                    func_003C2880((void *)o->rec->wC);
                                }
                                func_003C2880(o);
                            }
                        }
                    }
                }
                D_L10_001DE748 = m->h16;
                t60 = D_L10_001E0860;
                if (t60[1] != 0) {
                    x60 = t60;
                } else {
                    x60 = func_003E6C08();
                }
                func_L10_004F8E78((char *)x60, (int)func_L10_003B57A8);
                if (func_0038CB00(&m->h16)) {
                    func_L01_004450F0(self, 2, -1);
                } else {
                    a1 = (m->h16 + 1) / 50;
                    if (m->h16 / 50 != a1) {
                        switch (a1) {
                        case 10:
                            if (!(D_001A8594[0] & (1 << D_001D545C_003B4698))) {
                                func_L01_0041A5B0(0xCF8, 0x9F);
                            }
                        case 6:
                        case 7:
                        case 8:
                        case 9:
                        case 20:
                        case 30:
                        case 40:
                        case 50:
                            func_L01_004AAC98(2, 0x110, self, 0x1C88);
                            break;
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                            func_L01_004AAC98(7 - a1, 0x110, self, 0x1C88);
                            break;
                        }
                    }
                }
            }
        } else if (D_L10_001D6694_003B4698 == 2) {
            switch (D_L10_001E5F30[0]) {
            case 5:
                func_L01_003B1DB8(self);
                break;
            case 6:
                func_L10_003B5B48(self);
                break;
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(self)) {
            for (o = (Obj10 *)D_L10_001DF29C; (u8 *)o < D_L10_001DF2A0; o++) {
                if (o->id == 0x1C88) {
                    func_L01_00456230(o, 1);
                }
            }
            func_003A1C28();
            func_0013C170();
            func_L10_003B4350(0xC, 0x64);
            func_L01_004EDE10();
        }
        break;
    }
}
/* localdecomp:end func_L10_003B4698 */
