#include "common.h"

/* NTSC-U counterpart of func_L39_006A4510 (src/levels/39_multiplayer_menu/L39_006A4510.c): calls func_00195500, NTSC-U data addresses */
/* localdecomp:start func_L39_006A1D00 */
typedef struct W_006A1D00 W_006A1D00;
typedef struct V_006A1D00 {
    u8 pad0[0x6C];
    void (*setItems)(W_006A1D00 *, s32, char **);
    u8 pad70[0x18];
    void (*setSel)(W_006A1D00 *, s32);
    s32 (*getSel)(W_006A1D00 *);
    u8 pad90[0x28];
    void (*setText)(W_006A1D00 *, char *);
} V_006A1D00;
struct W_006A1D00 {
    u8 pad0[0x60];
    V_006A1D00 *vt;
};

typedef struct E_006A1D00 {
    s32 pad0[8];
    u8 pad20[2];
    u8 f22;
    u8 pad23;
    s32 pad24[4];
} E_006A1D00;

typedef struct R_006A1D00 {
    char name[0x20];
    s32 f20;
    E_006A1D00 e;
    u8 pad58[0x124 - 0x58];
} R_006A1D00;

typedef struct Q_006A1D00 {
    u8 f0;
    u8 pad1[0xC];
    u8 fD;
    u8 padE[6];
    u8 f14[1];
} Q_006A1D00;

typedef struct G_006A1D00 {
    u8 pad0[0x3C];
    void *f3C;
    u8 pad40[0x38];
    Q_006A1D00 *f78;
} G_006A1D00;

typedef struct S3_006A1D00 {
    char *s[3];
} S3_006A1D00;

typedef struct T_006A1D00 {
    u8 pad0[0x144];
    W_006A1D00 *f144;
    W_006A1D00 *f148;
    W_006A1D00 *f14C;
    W_006A1D00 *f150;
    u8 pad154[0xC];
    u8 *f160;
    W_006A1D00 *f164;
    u8 pad168[0x2A8 - 0x168];
    s32 f2A8;
    u8 pad2AC[0xC];
    u8 *f2B8;
    s32 f2BC;
    s32 f2C0;
    R_006A1D00 *f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0[16];
    s32 f310;
    u8 pad314[4];
    u8 f318[8];
    s32 f320;
    s32 f324;
    s32 f328;
    s32 f32C;
    u8 f330;
    u8 f331;
    u8 pad332[2];
    s32 f334;
    s32 f338;
    u8 f33C;
    u8 f33D;
    u8 f33E;
    u8 f33F;
} T_006A1D00;

__asm__(".extern D_L39_0024D860_006A1D00, 16");
extern void *D_L39_0024D860_006A1D00;
extern char D_L39_002488E0[];
extern char D_L39_002487E8[];
extern char D_L39_002488E8[];
extern char D_L39_002488F8[];
extern char D_L39_00248900[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_00195500(void);
extern s32 func_00120884(void *);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_0037DF98(s32);
extern void *func_L39_006D1BF8(void *, s32);
extern void *func_L39_006D2140(void *, s32, s32 *);
extern void *func_L39_006C9630(void *);
extern void func_L39_006C9A08(void *, void *);
extern s32 func_L39_006C9860(s32 *, s32);
void func_L39_006C9668(void *, s32);
struct S_006A1D00_net;
struct S_006A1D00_g;
extern s32 func_L39_006D4888(struct S_006A1D00_net *);
extern void func_L39_006D6030(struct S_006A1D00_g *);
extern void func_L39_00594648(u8 *, u8 *, s32);
u8 *func_L39_006A2DA0(void);

void func_L39_006A1D00(T_006A1D00 *this, s32 force) {
    void *list;
    s32 total;
    s32 i;
    s32 id;
    s32 sel;
    s32 selIdx;
    W_006A1D00 *w;

    if (!force) {
        s32 now = func_00130760(func_0012DCB0(), 0x24000);
        if (this->f2CC + 5000 >= now) {
            return;
        }
    }
    total = 0;
    this->f2CC = func_00130760(func_0012DCB0(), 0x24000);
    list = ((G_006A1D00 *)D_L39_0024D860_006A1D00)->f3C;
    this->f2B8 = func_L39_006D1BF8(list, this->f2A8);
    if (this->f2B8 != 0) {
      {
        char str[0x50];
        s32 buf[0x78];
        u8 *src;
        u8 *s;

        func_L39_006C9630(buf);
        func_L39_006C9A08(buf, this->f2B8);
        if (func_L39_006C9860(buf, 12) == 0) {
            Q_006A1D00 *q = ((G_006A1D00 *)D_L39_0024D860_006A1D00)->f78;
            void *l = q->fD ? q->f14 : 0;
            while (l == 0) {
                func_L39_006D4888((struct S_006A1D00_net *)q);
                while (q->f0) {
                    func_00195500();
                    if (D_L39_0024D860_006A1D00 != 0) {
                        func_L39_006D6030((struct S_006A1D00_g *)D_L39_0024D860_006A1D00);
                    }
                }
                l = q->fD ? q->f14 : 0;
            }
        }
        this->f2C8 = func_L39_006C9860(buf, 16) + 0x27;
        this->f2B8[0x146] = 0;
        {
            u8 name[0x20];
            s32 j;

            {
                src = this->f2B8 + 0x134;
                func_L39_00594648(name, src, func_00120884(src));
                for (j = 0x11; name[j] == ' '; j--) {
                }
                name[j + 1] = 0;
                this->f144->vt->setText(this->f144, (char *)name);
            }
        }
        switch (this->f2C8) {
        case 0x28:
            func_00120048(str, (char *)func_0037DF98(0xBB1));
            break;
        case 0x29:
            func_00120048(str, (char *)func_0037DF98(0xBB2));
            break;
        case 0x2A:
            func_00120048(str, (char *)func_0037DF98(0xDA));
            break;
        case 0x2B:
            func_00120048(str, (char *)func_0037DF98(0xBB4));
            break;
        case 0x2C:
            func_00120048(str, (char *)func_0037DF98(0xD8));
            break;
        case 0x2D:
            func_00120048(str, (char *)func_0037DF98(0xD4));
            break;
        case 0x2E:
            func_00120048(str, (char *)func_0037DF98(0x18C4));
            break;
        case 0x2F:
            func_00120048(str, (char *)func_0037DF98(0x18C5));
            break;
        case 0x30:
            func_00120048(str, (char *)func_0037DF98(0x18C6));
            break;
        case 0x31:
            func_00120048(str, (char *)func_0037DF98(0x18C7));
            break;
        default:
            func_00120048(str, D_L39_002488E0);
            break;
        }
        this->f148->vt->setText(this->f148, str);
        s = ((u8 *(*)(T_006A1D00 *, s32))func_L39_006A2DA0)(this, func_L39_006C9860(buf, 2));
        if (s != 0) {
            this->f150->vt->setText(this->f150, (char *)s);
        } else {
            this->f150->vt->setText(this->f150, D_L39_002487E8);
        }
        this->f330 = func_L39_006C9860(buf, 0x13) == 0;
        this->f331 = func_L39_006C9860(buf, 0x12) == 0;
        this->f324 = func_L39_006C9860(buf, 0xF) * 5;
        this->f328 = func_L39_006C9860(buf, 0x15) * 5;
        this->f32C = func_L39_006C9860(buf, 0x17);
        this->f334 = func_L39_006C9860(buf, 0x18);
        this->f33E = func_L39_006C9860(buf, 0x19) == 1;
        this->f33C = func_L39_006C9860(buf, 0x1A) == 1;
        this->f33D = func_L39_006C9860(buf, 0x1B) == 1;
        this->f33F = func_L39_006C9860(buf, 0x1C) == 1;
        this->f338 = func_L39_006C9860(buf, 0x14);
        {
            char *opts[3] = { (char *)func_0037DF98(0x1024), (char *)func_0037DF98(0x10E2), (char *)func_0037DF98(0x1026) };
            this->f320 = func_L39_006C9860(buf, 0x11);
            if (this->f338 != 0 && this->f320 == 2) {
                this->f14C->vt->setText(this->f14C, (char *)func_0037DF98(0x162A));
            } else {
                this->f14C->vt->setText(this->f14C, opts[this->f320]);
            }
        }
        this->f2C0 = func_L39_006C9860(buf, 1);
        this->f310 = func_L39_006C9860(buf, 3);
        if (this->f310 > 8) {
            this->f310 -= 8;
        }
        this->f318[0] = func_L39_006C9860(buf, 4) == 0;
        this->f318[1] = func_L39_006C9860(buf, 5) == 0;
        this->f318[2] = func_L39_006C9860(buf, 6) == 0;
        this->f318[3] = func_L39_006C9860(buf, 7) == 0;
        this->f318[4] = func_L39_006C9860(buf, 8) == 0;
        this->f318[5] = func_L39_006C9860(buf, 9) == 0;
        this->f318[6] = func_L39_006C9860(buf, 10) == 0;
        this->f318[7] = func_L39_006C9860(buf, 11) == 0;
        func_L39_006C9668(buf, 2);
      }
    }
    this->f2C4 = func_L39_006D2140(list, this->f2A8, &this->f2BC);
    if (this->f2C4 != 0) {
        char names[8][15];
        char *ptrs[8];
        char **items;
        E_006A1D00 e;

        if (this->f2BC > 8) {
            this->f2BC = 8;
        }
        items = ptrs;
        for (i = 7; i >= 0; i--) {
            items[i] = names[i];
        }
        w = this->f164;
        sel = -1;
        id = w->vt->getSel(w);
        if (id != -1) {
            sel = this->f2D0[id];
        }
        total = this->f2BC;
        selIdx = 0;
        for (i = 0; i < this->f2BC; i++) {
            e = this->f2C4[i].e;
            if (e.f22 != 0) {
                total++;
                func_00120048(names[i], D_L39_002488E8, i + 1, this->f2C4[i].name);
            } else {
                func_00120048(names[i], D_L39_002488F8, i + 1, this->f2C4[i].name);
            }
            this->f2D0[i] = this->f2C4[i].f20;
            if (this->f2D0[i] == sel) {
                selIdx = i;
            }
        }
        this->f164->vt->setItems(this->f164, this->f2BC, items);
        this->f164->vt->setSel(this->f164, selIdx);
    }
    func_00120048((char *)(this->f160 + 0x14), D_L39_00248900, func_0037DF98(0x1005), total, this->f2C0);
}
/* localdecomp:end func_L39_006A1D00 */
