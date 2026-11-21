#include "common.h"

/* NTSC-U counterpart of func_L39_006B19E0 (src/levels/39_multiplayer_menu/L39_006B19E0.c) */
/* localdecomp:start func_L39_006AF078 */
typedef struct O_006B19E0 O_006B19E0;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(O_006B19E0 *, s32, s32);
    u8 pad20[0x30 - 0x20];
    void (*f30)(O_006B19E0 *, f32 *, f32 *);
    u8 pad34[0x8C - 0x34];
    s32 (*f8C)(O_006B19E0 *);
    u8 pad90[0x9C - 0x90];
    s32 (*f9C)(O_006B19E0 *, f32 *, f32 *);
    u8 padA0[0xB8 - 0xA0];
    void (*fB8)(O_006B19E0 *, char *);
    u8 padBC[0xDC - 0xBC];
    void (*fDC)(O_006B19E0 *, s32);
} V_006B19E0;
struct O_006B19E0 {
    u8 pad0[0x4];
    s32 f4;
    u8 pad8[0x60 - 0x8];
    V_006B19E0 *vt;
};
typedef struct {
    u8 pad0[0x110];
    O_006B19E0 *f110[8];
    O_006B19E0 *f130;
    u8 pad134[0x138 - 0x134];
    O_006B19E0 *f138;
    O_006B19E0 *f13C;
    u8 pad140[0x290 - 0x140];
    s32 f290;
    u8 pad294[0x2A8 - 0x294];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    u8 pad2B4[0x494 - 0x2B4];
    s32 f494;
    s32 f498[1];
} S_006B19E0;
typedef struct {
    u8 pad0[0x94];
    void *f94;
    u8 pad98[0xA0 - 0x98];
    void *fA0;
    u8 padA4[0xD0 - 0xA4];
    void *fD0;
    u8 padD4[0xF0 - 0xD4];
    void *fF0;
    u8 padF4[0x284 - 0xF4];
    s32 f284;
} G_006B19E0;
typedef struct {
    s32 f0;
    u8 pad4[0x34 - 0x4];
    u8 f34;
} N_006B19E0;
typedef struct {
    u8 pad0[0x28];
    s32 f28;
} P_006B19E0;
typedef struct {
    u8 pad0[0x30];
    P_006B19E0 *f30;
    u8 pad34[0x38 - 0x34];
    N_006B19E0 *f38;
} R_006B19E0;
typedef struct {
    u8 pad0[0x7C];
    s32 f7C;
} D_006B19E0;

__asm__(".extern D_L39_00247A74_006AF078, 16");
extern G_006B19E0 *D_L39_00247A74_006AF078;
__asm__(".extern D_L39_0024D860, 16");
extern R_006B19E0 *D_L39_0024D860;
__asm__(".extern D_001DC1E4_sda, 4");
extern G_006B19E0 *D_001DC1E4_sda;
extern D_006B19E0 D_001A5E50;
extern s32 D_L39_00248FE8[];

void func_L39_006B0040(S_006B19E0 *);
s32 func_L39_006AFB30(S_006B19E0 *);
s32 func_L39_006AF7B8(S_006B19E0 *, s32);
s32 func_L39_00685798(s32, s32, s32);
extern s32 func_L39_00688350(void *, s32);
extern char *func_0037DF98(s32);
s32 func_L39_006847C8(G_006B19E0 *, char *, char *, s32, s32, f32);
void func_L39_006B0378(S_006B19E0 *);
void func_L39_006B03B0(S_006B19E0 *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_00684C90(G_006B19E0 *, s32);
s32 func_L39_006AF948(S_006B19E0 *, s32 *, s32 *, s32);
s32 func_L39_006AFAE8(S_006B19E0 *, s32, s32);
void func_L39_00699150(void *, s32, s32, s32, s32);
void func_L39_0069F928(u8 *, long, s32);
void func_L39_006C3EC8(void *, s32);
s32 func_L39_006CC290(N_006B19E0 *, s32);
void func_L39_006B2920(void *, s32, s32);
extern void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

static __inline__ s32 getType_006B19E0(O_006B19E0 *o) {
    return o->f4;
}

s32 func_L39_006AF078(S_006B19E0 *this, s32 arg1) {
    s32 sel;
    O_006B19E0 **pp;
    O_006B19E0 *o;
    s32 i;
    s32 first;
    s32 last;
    s32 mode;
    s32 text;
    G_006B19E0 *g;
    O_006B19E0 **arr;
    N_006B19E0 *n;
    s32 sp0;
    s32 sp4;
    f32 a, b;
    f32 x, y;

    func_L39_006B0040(this);
    if (func_L39_006AFB30(this)) {
        return 1;
    }
    if (this->f290 != 10 && this->f290 >= 0) {
        this->f2B0 = this->f290;
        sel = -1;
        switch (this->f290) {
        case 0: sel = 0; break;
        case 1: sel = 1; break;
        case 2: sel = 2; break;
        case 3: sel = 3; break;
        case 4: sel = 4; break;
        case 5: sel = 5; break;
        case 6:
        case 7: sel = 6; break;
        }
        this->f130->vt->fDC(this->f130, sel);
    }
    if (func_L39_006AF7B8(this, arg1)) {
        func_L39_00685798(3, 0, 0);
        return 1;
    }
    if (func_L39_00688350(this, arg1)) {
        return 1;
    }
    if (arg1 == 5) {
        func_L39_00685798(0x17, 0, 0);
        g = D_L39_00247A74_006AF078;
        if (func_L39_006847C8(g, func_0037DF98(0xF64), func_0037DF98(0x1031), 3, 0, 0.6f) != 1) {
            return 1;
        }
        func_L39_006B0378(this);
        func_L39_006B03B0(this);
    }
    if (arg1 == 7) {
        func_L39_00685798(4, 0, 0);
        switch (this->f290) {
        case 0:
            this->f2A8 = func_00130760(func_0012DCB0(), 0x24000);
            this->f2AC = 1;
            return 1;
        case 1: {
            s32 lvl;
            if ((u32)(D_001A5E50.f7C - 40) >= 60) {
                lvl = D_L39_0024D860->f30->f28;
                D_001A5E50.f7C = lvl;
            } else {
                lvl = D_001A5E50.f7C;
            }
            while (!((u32)(lvl - 40) < 60)) {
                lvl = func_L39_00684C90(D_L39_00247A74_006AF078, 1);
                if (lvl < 0) {
                    return 1;
                }
                D_001A5E50.f7C = lvl;
            }
            sp0 = -1;
            if (!func_L39_006AF948(this, D_L39_00248FE8, &sp0, lvl != 99 ? lvl : 40)) {
                return 1;
            }
            if (func_L39_006AFAE8(this, sp0, 0)) {
                func_L39_00699150(D_001DC1E4_sda->f94, 0, -1, -1, -1);
                D_L39_00247A74_006AF078->f284 = 0xC;
            }
            return 1;
        }
        case 2: {
            s32 cur = D_001A5E50.f7C;
            s32 lvl = cur;
            G_006B19E0 *menu;
            if (cur == -1) {
                lvl = D_L39_0024D860->f30->f28;
            }
            if (cur != -1) {
                func_L39_0069F928(D_001DC1E4_sda->fA0, 0, lvl);
                menu = D_L39_00247A74_006AF078;
            } else {
                func_L39_0069F928(D_L39_00247A74_006AF078->fA0, 0, lvl);
                menu = D_L39_00247A74_006AF078;
            }
            menu->f284 = 0xF;
            return 1;
        }
        case 6:
            func_L39_006C3EC8(D_L39_00247A74_006AF078->fF0, 1);
            D_L39_00247A74_006AF078->f284 = 0x23;
            return 1;
        case 3: {
            s32 lvl;
            if (D_001A5E50.f7C == -1) {
                lvl = D_L39_0024D860->f30->f28;
            } else {
                lvl = D_001A5E50.f7C;
            }
            while (!((u32)(lvl - 40) < 60)) {
                lvl = func_L39_00684C90(D_L39_00247A74_006AF078, 1);
                if (lvl < 0) {
                    return 1;
                }
                D_001A5E50.f7C = lvl;
            }
            sp4 = -1;
            if (!func_L39_006AF948(this, D_L39_00248FE8, &sp4, lvl != 99 ? lvl : 40)) {
                return 1;
            }
            func_L39_006AFAE8(this, sp4, 1);
            return 1;
        }
        case 4:
            D_L39_00247A74_006AF078->f284 = 4;
            return 1;
        case 5:
            n = D_L39_0024D860->f38;
            func_L39_006CC290(n, 0);
            if (n->f34 != 0) {
                D_001DC1E4_sda->f284 = 9;
                return 1;
            }
            if (n->f0 == -1) {
                D_L39_00247A74_006AF078->f284 = 8;
                return 1;
            }
            D_001DC1E4_sda->f284 = 6;
            return 1;
        case 7:
            D_L39_00247A74_006AF078->f284 = 0x26;
            return 1;
        case 10: {
            s32 sel2 = this->f138->vt->f8C(this->f138);
            if (sel2 != -1) {
                func_L39_006B2920(D_L39_00247A74_006AF078->fD0, this->f498[sel2], 1);
                D_L39_00247A74_006AF078->f284 = 0x1B;
            }
            return 1;
        }
        }
    }
    if (this->f290 == 10) {
        arr = this->f110;
        this->f138->vt->f9C(this->f138, &a, &b);
        arr += this->f290;
        {
            s32 cur = (*arr)->vt->f8C(*arr);
            s32 arrows = cur > 0;
            if (cur < this->f494 - 1) {
                arrows |= 2;
            }
            func_L39_00687358(this, arrows, 3, 3, 0.728f, b + 0.0035f, 0.32700002f, 0.032f, 0.041f, 1.0f);
        }
    } else {
        arr = this->f110;
        pp = &arr[this->f290]; o = *pp;
        o->vt->f30(o, &x, &y);
        first = -1;
        last = -1;
        for (i = 0; i < 8; i++, arr++) {
            if (getType_006B19E0(*arr) == 3 || getType_006B19E0(*arr) == 4 || getType_006B19E0(*arr) == 5) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        mode = this->f290 != first;
        if (this->f290 != last) {
            mode |= 2;
        }
        func_L39_00687358(this, mode, 3, 3, x, y + 0.0f, 0.33200002f, 0.034f, 0.041f, 1.0f);
    }
    text = -1;
    switch (this->f290) {
    case 0: text = 0x10DC; break;
    case 2: text = 0x10DD; break;
    case 3: text = 0x10DE; break;
    case 4: text = 0x10DF; break;
    case 6: text = 0x10E1; break;
    case 5: text = 0x10E0; break;
    case 1: text = 0x11F0; break;
    }
    if (text >= 0) {
        this->f13C->vt->fB8(this->f13C, func_0037DF98(text));
        this->f13C->vt->f1C(this->f13C, 1, 0);
    } else {
        this->f13C->vt->f1C(this->f13C, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L39_006AF078 */
