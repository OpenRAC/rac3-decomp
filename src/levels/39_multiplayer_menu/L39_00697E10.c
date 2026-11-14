#include "common.h"

/* declared by functions of L39_006979B0.c, which this file was cut from */
typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_00697B28_inner;
typedef struct {
    char pad[0x38];
    S_00697B28_inner *f38;
} S_00697B28_outer;
extern S_00697B28_outer *D_L39_0024D760;

/* localdecomp:start func_L39_00697E10 */
typedef struct Widget_00697E10 Widget_00697E10;

typedef struct {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ void (*unk1C)(Widget_00697E10 *, s32, s32);
    /* 0x20 */ u8 pad20[0x94];
    /* 0xB4 */ void (*unkB4)(Widget_00697E10 *);
    /* 0xB8 */ void (*unkB8)(Widget_00697E10 *, char *);
    /* 0xBC */ u8 padBC[0x28];
    /* 0xE4 */ void (*unkE4)(Widget_00697E10 *, f32);
} WidgetVtbl_00697E10;

struct Widget_00697E10 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ WidgetVtbl_00697E10 *vtbl;
};

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4[0x2C];
    /* 0x30 */ char unk30[4];
} Net_00697E10;

typedef struct {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[0x20];
    /* 0x38 */ Net_00697E10 *unk38;
    /* 0x3C */ u8 pad3C[8];
    /* 0x44 */ void *unk44;
} Root_00697E10;

typedef struct {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ u8 pad10[0x180];
} Stats_00697E10;

typedef struct {
    /* 0x000 */ u8 pad0[0x124];
    /* 0x124 */ Widget_00697E10 *unk124;
    /* 0x128 */ Widget_00697E10 *unk128;
    /* 0x12C */ Widget_00697E10 *unk12C;
    /* 0x130 */ Widget_00697E10 *unk130;
    /* 0x134 */ u8 pad134[0xC];
    /* 0x140 */ Widget_00697E10 *unk140;
    /* 0x144 */ Widget_00697E10 *unk144;
    /* 0x148 */ Widget_00697E10 *unk148;
    /* 0x14C */ u8 pad14C[0x26C];
    /* 0x3B8 */ s32 unk3B8;
} S_00697E10;

extern char D_L39_00248030[];
extern char D_L39_00248040[];

extern s32 func_0038CAD0(s32 *);
extern s32 func_L39_006CEA18(Net_00697E10 *, s32);
extern void func_L39_00689BD8(S_00697E10 *, u8 *);
extern s32 func_L39_006D2F18(Net_00697E10 *, s32 *, s32 *);
extern char *func_L39_006D31B8(Net_00697E10 *, s32, s32);
extern s32 func_L39_006D2EF0(Net_00697E10 *, s32, s32);
extern char *func_00381FF0(s32);
extern void func_00120D28(char *, char *, s32);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_L39_006D6E50(void *, s32, s32, Stats_00697E10 *);

void func_L39_00697E10(S_00697E10 *this) {
    char tag[8];
    char tagText[0x10];
    Stats_00697E10 stats;
    char text[0x10];
    s32 a;
    s32 b;
    Net_00697E10 *net = ((Root_00697E10 *)D_L39_0024D760)->unk38;
    char *name;

    func_0038CAD0(&this->unk3B8);
    if (this->unk3B8 > 0) {
        return;
    }
    func_L39_006CEA18(net, 0);
    this->unk3B8 = 0x2EE;
    func_L39_00689BD8(this, net->unk4);
    if (func_L39_006D2F18(net, &a, &b) != 0) {
        name = func_L39_006D31B8(net, b, a);
        if (name != 0) {
            this->unk130->vtbl->unkB8(this->unk130, name + 0x20);
            this->unk130->vtbl->unkE4(this->unk130, 0.25f);
            this->unk140->vtbl->unk1C(this->unk140, 0, 0);
            this->unk144->vtbl->unk1C(this->unk144, 3, 0);
            this->unk148->vtbl->unk1C(this->unk148, 3, 0);
        } else {
            ((Root_00697E10 *)D_L39_0024D760)->unk14 = 0;
            func_L39_006D2EF0(net, -1, -1);
            this->unk130->vtbl->unkB8(this->unk130, func_00381FF0(0x1328));
            this->unk140->vtbl->unk1C(this->unk140, 3, 0);
            this->unk144->vtbl->unk1C(this->unk144, 0, 0);
            this->unk148->vtbl->unk1C(this->unk148, 2, 0);
        }
    } else {
        this->unk140->vtbl->unk1C(this->unk140, 3, 0);
        this->unk144->vtbl->unk1C(this->unk144, 0, 0);
        this->unk148->vtbl->unk1C(this->unk148, 2, 0);
        this->unk130->vtbl->unkB8(this->unk130, func_00381FF0(0x1328));
    }
    func_00120D28(tag, net->unk30, 4);
    tag[4] = 0;
    func_00120048(tagText, D_L39_00248030, tag);
    this->unk12C->vtbl->unkB8(this->unk12C, tagText);
    if (func_L39_006D6E50(((Root_00697E10 *)D_L39_0024D760)->unk44, net->unk0, 1, &stats) != 0) {
        func_00120048(text, D_L39_00248040, stats.unk8, stats.unkC);
        this->unk124->vtbl->unkB8(this->unk124, text);
        func_00120048(text, D_L39_00248040, stats.unk0, stats.unk4);
        this->unk128->vtbl->unkB8(this->unk128, text);
    } else {
        this->unk124->vtbl->unkB4(this->unk124);
        this->unk128->vtbl->unkB4(this->unk128);
    }
}
/* localdecomp:end func_L39_00697E10 */

/* localdecomp:start func_L39_006980F8 */
typedef struct O_006980F8 O_006980F8;
typedef struct {
    char pad[0x8C];
    s32 (*f8C)(O_006980F8 *);
    char pad90[0xB4 - 0x90];
    void (*fB4)(O_006980F8 *);
    void (*fB8)(O_006980F8 *, s32);
} V_006980F8;
struct O_006980F8 {
    char pad[0x60];
    V_006980F8 *f60;
};
typedef struct {
    char pad[0x114];
    O_006980F8 *f114;
    char pad118[4];
    O_006980F8 *f11C;
    O_006980F8 *f120;
    char pad124[0x290 - 0x124];
    s32 f290;
    char pad294[0x2B4 - 0x294];
    s32 f2B4[130];
    s32 f4BC;
    s32 f4C0;
} P_006980F8;
typedef struct {
    char pad[0x30];
    s32 *f30;
    char pad34[4];
    u8 *f38;
    void *f3C;
    char pad40[4];
    void *f44;
    void *f48;
} M_006980F8;
typedef struct {
    char pad[0x40];
    s32 f40;
    s32 f44;
} A_006980F8;
typedef struct {
    char pad[0x1C];
    s32 f1C;
} R_006980F8;

extern M_006980F8 *D_001E2050_sda;
extern u8 D_L39_00248048[];
A_006980F8 *func_L39_006D98C8(void *, s32);
extern A_006980F8 *func_L39_006D9328(void *, s32);
R_006980F8 *func_L39_006D6CF8(void *, s32, s32, s32);
void *func_L39_006D4380(void *, s32);
void *func_L39_006CC120(void *);
void func_L39_006CC4F8(void *, void *);
s32 func_L39_006CC350(s32 *, s32);
void func_L39_006CC158(void *, s32);

void func_L39_006980F8(P_006980F8 *p)
{
    M_006980F8 *m = (M_006980F8 *)D_L39_0024D760;
    void *db = m->f48;
    A_006980F8 *a;
    A_006980F8 *b;
    R_006980F8 *r;
    void *t;
    s32 kind;
    s32 slot;
    s32 ok;
    s32 limit = 7;
    u8 str[16];
    u8 buf[0x1E0];

    if (p->f290 == 1 && p->f114->f60->f8C(p->f114) >= 0) {
        p->f4C0 = p->f2B4[p->f114->f60->f8C(p->f114)];
    }
    if (m->f38[0x3BC] != 0) {
        return;
    }
    if (p->f4C0 < 0) {
        p->f11C->f60->fB4(p->f11C);
        p->f120->f60->fB4(p->f120);
        return;
    }
    if (p->f4C0 == p->f4BC) {
        return;
    }
    kind = 0;
    a = func_L39_006D98C8(db, p->f4C0);
    slot = -1;
    b = func_L39_006D9328(db, p->f4C0);
    p->f4BC = p->f4C0;
    if (a != 0) {
        slot = a->f44;
        if (a->f40 == 0) {
            kind = 3;
        } else {
            kind = (a->f40 == 1) ? 2 : 0;
        }
    } else if (b != 0) {
        kind = b->f40;
    }
    if (b != 0) {
        r = func_L39_006D6CF8(m->f44, p->f4C0, 1, 0);
        if (r != 0) {
            func_00120048(str, D_L39_00248048, r->f1C);
            p->f120->f60->fB8(p->f120, (s32)str);
        } else {
            p->f120->f60->fB4(p->f120);
        }
    }
    if (((M_006980F8 *)D_L39_0024D760)->f30[0] == p->f4C0) {
        p->f11C->f60->fB8(p->f11C, func_00381FF0(0xFAE));
    } else if (kind == 0) {
        p->f11C->f60->fB8(p->f11C, func_00381FF0(0xFAD));
    } else if (kind == 1) {
        p->f11C->f60->fB8(p->f11C, func_00381FF0(0xF76));
    } else if (kind == 2) {
        p->f11C->f60->fB8(p->f11C, func_00381FF0(0xFAF));
    } else if (kind == 3) {
        ok = 1;
        if (slot >= 0) {
            t = func_L39_006D4380(m->f3C, slot);
            if (t != 0) {
                func_L39_006CC120(buf);
                func_L39_006CC4F8(buf, t);
                if (func_L39_006CC350((s32 *)buf, 3) > limit) {
                    ok = 0;
                }
                func_L39_006CC158(buf, 2);
            }
        }
        if (ok) {
            p->f11C->f60->fB8(p->f11C, func_00381FF0(0xFB0));
        } else {
            p->f11C->f60->fB8(p->f11C, func_00381FF0(0xFB1));
        }
    }
}
/* localdecomp:end func_L39_006980F8 */

INCLUDE_ASM("asm/levels", func_L39_006983B8);

LINKER_REMNANT("asm/levels", func_L39_00698C18);

/* localdecomp:start func_L39_00698C28 */
typedef struct H_00698C28 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_00698C28;
typedef struct I50_00698C28 {
    H_00698C28 h;
    u8 b48;
    s32 f4C;
} I50_00698C28;
typedef struct I450_00698C28 {
    H_00698C28 h;
    u8 b48;
    char _p0[0x407];
} I450_00698C28;
typedef struct M_00698C28 {
    H_00698C28 h;
    s32 f48;
    s32 f4C;
    void *items[0x60];
} M_00698C28;

extern f32 D_001DC9A4_sda;
__asm__(".extern D_001DC9A4_sda, 4");
extern f32 D_001DC9A8_sda;
__asm__(".extern D_001DC9A8_sda, 4");
extern f32 D_001DC9AC_sda;
__asm__(".extern D_001DC9AC_sda, 4");
extern f32 D_001DC9B0_sda;
__asm__(".extern D_001DC9B0_sda, 4");
extern char D_L39_002480C8[];
extern f32 D_L39_002480D0;
extern f32 D_L39_002480D4;
extern f32 D_L39_002480D8;
extern u8 D_L39_0047CEB0[];
void func_L39_00688388(void *);
void func_L39_00689670(void *, void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

static __inline__ void *item_00698C28(void *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    ((H_00698C28 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
    return it;
}

void *func_L39_00698C28(void *arg0) {
    I450_00698C28 title;
    I50_00698C28 it0;
    I50_00698C28 it1;
    I50_00698C28 it2;
    I50_00698C28 it3;
    I50_00698C28 it4;
    I50_00698C28 it5;
    M_00698C28 menu;
    I50_00698C28 *p0, *p1, *p2, *p3, *p4, *p5;
    M_00698C28 *pm;
    s32 name;
    f32 x, y, w, h;

    func_L39_00688388(arg0);
    x = D_001DC9A4_sda;
    y = D_001DC9A8_sda;
    w = D_001DC9AC_sda - 0.02f;
    h = D_001DC9B0_sda - 0.02f;
    *(void **)((u8 *)arg0 + 0x2A4) = (u8 *)arg0 + 0x2B8;
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047CEB0;

    item_00698C28(&title, (s32)D_L39_002480C8, x, y, w, h);
    title.h.type = 9;
    title.b48 = 0;

    name = (s32)func_00381FF0(0x102B);
    p0 = &it0;
    item_00698C28(p0, name, D_L39_002480D0, 0.6125f, 0.2f, 0.05f);
    it0.h.type = 1;
    name = (s32)func_00381FF0(0x102C);
    p1 = &it1;
    item_00698C28(p1, name, D_L39_002480D8, 0.6125f, 0.2f, 0.05f);
    it1.h.type = 1;
    name = (s32)func_00381FF0(0x102D);
    p2 = &it2;
    item_00698C28(p2, name, D_L39_002480D4, 0.6125f, 0.2f, 0.05f);
    it2.h.type = 1;
    name = (s32)func_00381FF0(0x102E);
    p3 = &it3;
    item_00698C28(p3, name, D_L39_002480D0, 0.6125f, 0.2f, 0.05f);
    it3.h.type = 1;
    name = (s32)func_00381FF0(0x102F);
    p4 = &it4;
    item_00698C28(p4, name, D_L39_002480D0, 0.6125f, 0.2f, 0.05f);
    it4.h.type = 1;
    name = (s32)func_00381FF0(0xF5F);
    p5 = &it5;
    item_00698C28(p5, name, D_L39_002480D8, 0.6125f, 0.2f, 0.05f);
    it5.h.type = 1;

    pm = &menu;
    item_00698C28(pm, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pm->f48 = 0x2E;
    menu.f4C = 0;
    menu.h.x = 0;
    menu.h.y = 0;
    pm->h.w = 1.0f;
    pm->h.h = 1.0f;
    *((u8 *)arg0 + 0x2B5) = 0;
    menu.items[1] = p0;
    menu.items[2] = p1;
    menu.items[3] = p2;
    menu.items[4] = p3;
    menu.items[5] = p4;
    menu.items[6] = p5;
    menu.f4C = 7;
    menu.items[0] = &title;
    func_L39_00689670(arg0, pm);
    *((u8 *)arg0 + 0x2B4) = 0;
    *(f32 *)((u8 *)arg0 + 0x2B0) = 0.6f;
    return arg0;
}
/* localdecomp:end func_L39_00698C28 */

LINKER_REMNANT("asm/levels", func_L39_00698F48);
