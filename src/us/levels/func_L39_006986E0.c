#include "common.h"

/* NTSC-U counterpart of func_L39_0069AEF0 (src/levels/39_multiplayer_menu/L39_0069AEF0.c) */
/* localdecomp:start func_L39_006986E0 */
typedef struct {
    char name[0x12];
    char score[8];
    char extra[0x126];
    char team[0x20];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C[6];
    s32 f184;
    s32 f188;
} Info_0069AEF0;

typedef struct {
    u8 pad[0x1E0];
} Obj_0069AEF0;

typedef struct VObj_0069AEF0 VObj_0069AEF0;
typedef struct {
    u8 pad0[0x64];
    s32 (*f64)(VObj_0069AEF0 *);
    u8 pad68[0x8C - 0x68];
    s32 (*f8C)(VObj_0069AEF0 *);
    u8 pad90[0xAC - 0x90];
    s32 (*fAC)(VObj_0069AEF0 *);
} VT_0069AEF0;
struct VObj_0069AEF0 {
    u8 pad[0x60];
    VT_0069AEF0 *vt;
};

typedef struct {
    u8 pad0[0x114];
    VObj_0069AEF0 *f114;
    u8 pad118[4];
    VObj_0069AEF0 *f11C;
    VObj_0069AEF0 *f120;
    VObj_0069AEF0 *f124;
    VObj_0069AEF0 *f128;
    u8 pad12C[4];
    VObj_0069AEF0 *f130;
    u8 *f134;
    u8 pad138[0x2A8 - 0x138];
    u32 f2A8;
    s32 f2AC;
    u8 pad2B0[4];
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0;
    u8 f2D4[8];
    s32 f2DC;
    s32 f2E0;
    s32 f2E4;
    s32 f2E8;
    s32 f2EC;
    s32 f2F0;
    s32 f2F4;
    u8 pad2F8[8];
    s32 f300;
    char f304[0x80];
    u8 f384[1];
} Self_0069AEF0;

typedef struct {
    u8 pad0[0x28];
    s32 f28;
} G30_0069AEF0;

typedef struct {
    u8 pad0[0x30];
    G30_0069AEF0 *f30;
    u8 pad34[4];
    s32 *f38;
    s32 f3C;
    u8 pad40[0xC];
    s32 *f4C;
} G_0069AEF0;

typedef struct {
    u8 pad0[0x2AC];
    s32 f2AC;
    s32 f2B0;
    u8 f2B4;
} E_0069AEF0;

typedef struct {
    u8 pad0[0xE8];
    E_0069AEF0 *fE8;
    u8 padEC[0x284 - 0xEC];
    s32 f284;
} H_0069AEF0;

typedef struct {
    u8 pad0[0xD0];
    s16 fD0[1];
} T_0069AEF0;

extern G_0069AEF0 *D_L39_0024D860;
extern H_0069AEF0 *D_L39_00247A74;
typedef struct {
    T_0069AEF0 *tbl;
    u8 pad4[4];
    u8 f8;
    u8 f9;
    u8 fA;
    u8 fB;
    u8 padC[3];
    u8 fF;
    u8 f10;
    u8 pad11[3];
    u8 f14;
    u8 pad15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
} G_00241640_0069AEF0;
extern G_00241640_0069AEF0 D_L39_002417C0 __attribute__((section(".sdata")));
extern s32 *D_L39_002412A0;
extern char D_L39_00248238[];
extern char D_L39_00248240[];
extern char D_L39_00248290[];
extern char D_L39_002483A8[];
extern char D_L39_002483B0[];
extern char D_L39_002483B8[];
extern char D_L39_002483C0[];
extern char D_L39_002483C8[];

typedef struct {
    u8 pad0[0xAA];
    u8 fAA;
    u8 padAB[0x17C - 0xAB];
    s32 f17C;
} C_0069AEF0;
extern C_0069AEF0 D_001A5E50;

extern s32 func_00183CCC(void);
extern s32 func_001200E0(char *, char *, ...);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_001206F4(char *, char *);
extern u32 func_00120884(char *);
extern void func_001962F8(void);
extern char *func_0037DF98(s32);
extern void func_L39_006C9630(void *);
extern u8 *func_L39_006D8BF8(s32 *, s32);
extern s32 func_L39_006C9860(void *, s32);
extern void func_L39_006C9850(void *, s32, s32);
extern void func_L39_006CC290(s32 *, s32);
extern s32 func_L39_006847C8(void *, char *, char *, s32, f32, s32);
extern void func_L39_006C9870(void *, void *);
extern s32 func_L39_006D96D0(s32 *, s32, s32, s32 *);
extern s32 func_L39_006D12A8(s32, void *, s32, s32);
extern void func_L39_006D9878(s32 *, s32 *);
extern void func_L39_006D2750(s32, s32, char *, s32, s32, s32, s32);

s32 func_L39_006986E0(Self_0069AEF0 *p) {
    Info_0069AEF0 info;
    Obj_0069AEF0 obj;
    char label[0x20];
    s32 a, b;
    s32 c, d;
    s32 res;
    s32 res2;
    s32 h;
    s32 sel;
    s32 players;
    s32 count;
    s32 limit;
    s32 mode;
    s32 ok;
    H_0069AEF0 *g;
    s32 i;
    u8 *rec;
    u8 mask;
    s32 *q;
    s32 *list;
    s32 first;
    s32 n;
    E_0069AEF0 *e;
    s32 t1, t2;
    s32 stamp;

    h = D_L39_0024D860->f3C;
    stamp = func_00183CCC();
    info.f164 = 8;
    info.f160 = stamp;
    info.f168 = 1;
    info.f16C[0] = 0;
    info.f16C[1] = 0;
    info.f16C[2] = 0;
    info.f16C[3] = 0;
    info.f16C[4] = 0;
    info.f16C[5] = 0;
    info.f184 = 0;
    info.f188 = 0;
    info.name[0] = 0;
    info.team[0] = 0;
    func_L39_006C9630(&obj);
    sel = p->f11C->vt->fAC(p->f11C);
    players = p->f114->vt->f8C(p->f114) + 1;
    count = p->f128->vt->fAC(p->f128);
    limit = D_L39_0024D860->f30->f28;
    list = D_L39_0024D860->f4C;
    first = *list;
    if (p->f2A8 == 1) {
        rec = func_L39_006D8BF8(list, first);
        if (rec != 0) {
            u8 *tag = rec + 0x1C;
            s32 *pa = &a;
            s32 *pb = &b;
            s32 kind = 8;
            if (tag[0] == 'C') {
                if (tag[1] == 'Y') {
                    kind = 1;
                    func_001200E0((char *)rec + 0x1E, D_L39_00248238, pa, pb);
                } else if (tag[1] == 'R') {
                    kind = 4;
                    func_001200E0((char *)rec + 0x1E, D_L39_00248238, pa, pb);
                } else if (tag[1] == 'C') {
                    kind = 2;
                    func_001200E0((char *)rec + 0x1E, D_L39_00248240, pa, pb);
                }
            } else if (tag[0] == 'H') {
                kind = 6;
                func_001200E0((char *)rec + 0x1E, D_L39_00248238, pa, pb);
            }
            if (kind == 1) {
                limit = a + 40;
            }
            if (limit == 0 || limit == 99) {
                limit = 40;
            }
        }
    }
    mode = 0;
    if (p->f2A8 == 3) {
        mode = 2;
    } else if (p->f2A8 == 2) {
        mode = 1;
    } else if (p->f2A8 >= 2) {
        if (p->f2A8 == 4) {
            mode = func_L39_006C9860(p->f384, 0xC);
        }
    }
    D_001A5E50.f17C = 0;
    info.f184 = p->f120->vt->fAC(p->f120);
    info.f188 = p->f124->vt->fAC(p->f124);
    if (mode == 2) {
        func_00120048(info.name, D_L39_002483A8, D_L39_002483B0, p->f304);
    } else {
        func_001206F4(info.name, p->f304);
    }
    {
        s32 len;
        for (len = func_00120884(info.name); len < 0x12; len++) {
            info.name[len] = ' ';
        }
    }
    func_00120048(info.score, D_L39_00248238, limit);
    func_00120048(info.extra, D_L39_002483B8, p->f300);
    if (p->f130->vt->f64(p->f130)) {
        func_001206F4(info.team, (char *)p->f134 + 0x14);
    } else {
        info.team[0] = 0;
    }
    if (players >= 7) {
        D_L39_002417C0.f10 = 0;
    }
    D_L39_002417C0.fF = p->f2E8;
    p->f2B8 = p->f2A8 == 3 ? 1 : p->f2B8;
    if (p->f2B4 == 0) {
        D_L39_002417C0.f8 = 1;
        D_L39_002417C0.f9 = 1;
        D_L39_002417C0.fA = 1;
        D_L39_002417C0.fB = 1;
    } else {
        D_L39_002417C0.f8 = 0;
        D_L39_002417C0.f9 = 0;
        D_L39_002417C0.fA = 0;
        D_L39_002417C0.fB = 0;
    }
    D_L39_002417C0.f16 = 0;
    if (p->f2C0 == 1) {
        D_L39_002417C0.f16 = 1;
    }
    D_L39_002417C0.f17 = p->f2E0;
    D_L39_002417C0.f18 = p->f2E4;
    if (p->f2AC == 2) {
        D_L39_002417C0.f14 = 0;
    } else {
        D_L39_002417C0.f14 = p->f2C4;
    }
    D_L39_002417C0.f1A = p->f2D0;
    D_L39_002417C0.f1B = p->f2C8;
    D_L39_002417C0.f1C = p->f2CC;
    D_L39_002417C0.f1D = p->f2B8 == 1;
    mask = 0;
    {
        s32 bit;
        for (bit = 0; bit < 8; bit++) {
            if (p->f2D4[bit]) {
                mask |= 1 << bit;
            }
        }
    }
    D_L39_002417C0.f19 = mask;
    ok = 1;
    func_L39_006C9850(&obj, 1, sel);
    func_L39_006C9850(&obj, 0x10, players);
    func_L39_006C9850(&obj, 0xF, p->f2DC / 5);
    func_L39_006C9850(&obj, 0x11, p->f2AC);
    func_L39_006C9850(&obj, 0x14, p->f2B8);
    func_L39_006C9850(&obj, 0x15, p->f2E0 / 5);
    func_L39_006C9850(&obj, 0x16, p->f2BC);
    func_L39_006C9850(&obj, 0x18, p->f2C0);
    func_L39_006C9850(&obj, 0x17, p->f2E4);
    func_L39_006C9850(&obj, 0x17, p->f2E4);
    func_L39_006C9850(&obj, 0x19, p->f2C4);
    func_L39_006C9850(&obj, 0x1A, p->f2D0);
    func_L39_006C9850(&obj, 0x1B, p->f2CC);
    func_L39_006C9850(&obj, 0x1C, p->f2C8);
    func_L39_006C9850(&obj, 0x13, p->f2B4);
    func_L39_006C9850(&obj, 4, p->f2D4[0] ? 0 : ok);
    func_L39_006C9850(&obj, 5, p->f2D4[1] ? 0 : ok);
    func_L39_006C9850(&obj, 6, p->f2D4[2] ? 0 : ok);
    func_L39_006C9850(&obj, 7, p->f2D4[3] ? 0 : ok);
    func_L39_006C9850(&obj, 8, p->f2D4[4] ? 0 : ok);
    func_L39_006C9850(&obj, 9, p->f2D4[5] ? 0 : ok);
    func_L39_006C9850(&obj, 0xA, p->f2D4[6] ? 0 : ok);
    func_L39_006C9850(&obj, 0xB, p->f2D4[7] ? 0 : ok);
    if (p->f2A8 == 4) {
        s32 x = func_L39_006C9860(p->f384, 0xC);
        s32 y = func_L39_006C9860(p->f384, 0xD);
        s32 z = func_L39_006C9860(p->f384, 0xE);
        func_L39_006C9850(&obj, 0xC, x);
        func_L39_006C9850(&obj, 0xD, y);
        func_L39_006C9850(&obj, 0xE, z);
        D_L39_00247A74->fE8->f2B4 = 1;
    } else {
        switch (mode) {
        case 0:
            func_L39_006C9850(&obj, 0xD, limit);
            break;
        case 1:
            q = D_L39_0024D860->f38;
            func_L39_006CC290(q, 0);
            if (*q == -1) {
                g = D_L39_00247A74;
                func_L39_006847C8(g, func_0037DF98(0x116F), D_L39_00248290, 4, 0.6f, 0);
                D_L39_00247A74->f284 = 0x19;
            } else {
                func_L39_006C9850(&obj, 0xD, *q);
            }
            break;
        case 2:
            q = D_L39_0024D860->f38;
            func_L39_006CC290(q, 0);
            n = *q;
            if (n == -1) {
                g = D_L39_00247A74;
                func_L39_006847C8(g, func_0037DF98(0x116F), D_L39_00248290, 4, 0.6f, 0);
                D_L39_00247A74->f284 = 0x19;
            } else if (n < p->f2F0) {
                func_L39_006C9850(&obj, 0xD, n);
                func_L39_006C9850(&obj, 0xE, p->f2F0);
            } else {
                func_L39_006C9850(&obj, 0xD, p->f2F0);
                func_L39_006C9850(&obj, 0xE, n);
            }
            t1 = p->f2EC;
            t2 = p->f2F4;
            e = D_L39_00247A74->fE8;
            e->f2AC = t1;
            e->f2B0 = t2;
            break;
        }
    }
    func_L39_006C9850(&obj, 0xC, mode);
    ok = 1;
    func_L39_006C9850(&obj, 2, *D_L39_0024D860->f4C);
    func_L39_006C9870(&obj, &info);
    if (p->f2A8 == 3) {
        c = func_L39_006C9860(&obj, 0xD);
        d = func_L39_006C9860(&obj, 0xE);
        ok = func_L39_006D96D0(D_L39_0024D860->f4C, c, d, &res);
    }
    if (ok) {
        ok = func_L39_006D12A8(h, &info, count, 0);
        if (!ok) {
            if (p->f2A8 == 3) {
                func_L39_006D9878(D_L39_0024D860->f4C, &res2);
            }
        } else {
            for (i = 1; i < count; i++) {
                char *nm = (char *)D_L39_0024D860->f30 + 4;
                if (func_00120884(nm) < 10) {
                    func_00120048(label, D_L39_002483C0, nm, i + 1);
                } else {
                    func_00120048(label, D_L39_002483C8, nm, i + 1);
                }
                func_L39_006D2750(h, i, label, 0, D_L39_002417C0.tbl->fD0[i], 0, 0);
            }
            *D_L39_002412A0 = count;
            D_001A5E50.fAA = count >= 2;
            func_001962F8();
        }
    }
    func_L39_006C9668(&obj, 2);
    return ok;
}
/* localdecomp:end func_L39_006986E0 */
