#include "common.h"

/* declared by functions of L39_0068F810.c, which this file was cut from */
extern s32 *D_L39_0024D760;

/* localdecomp:start func_L39_0068FA80 */
extern u8 D_L39_00247CD8[];
extern s32 func_L39_006D6E50(s32, s32, s32, void *);
extern s32 func_L39_006D31B8(s32, s32, s32);
extern char *func_L39_006D6CF8(s32, s32, s32, s32);
extern char *func_L39_006D98C8(s32, s32);
extern char *func_L39_006D9328(s32, s32);
extern s32 func_L39_006DF598(f32, f32);
extern char *func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);

typedef struct {
    s32 pad0[2];
    s32 f08;
    s32 f0C;
    s32 pad10;
    s32 f14;
    s32 f18;
    s32 pad1C[3];
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 pad34[0x57];
} S_0068FA80_Info;

typedef struct {
    f32 a[4];
    f32 b[4];
    s32 rest[5];
} S_0068FA80_Ranges;

typedef struct S_0068FA80_Obj S_0068FA80_Obj;
typedef struct {
    u8 pad0[0x1C];
    void (*setVisible)(S_0068FA80_Obj *, s32, s32);
    u8 pad20[0x24];
    void (*setScale)(S_0068FA80_Obj *, s32, f32, f32);
    u8 pad48[0x44];
    s32 (*getSelected)(S_0068FA80_Obj *);
    u8 pad90[0x28];
    void (*setText)(S_0068FA80_Obj *, void *);
} S_0068FA80_Vt;
struct S_0068FA80_Obj {
    u8 pad0[0x60];
    S_0068FA80_Vt *vt;
};
typedef struct {
    u8 pad0[0x110];
    S_0068FA80_Obj *list;
    u8 pad114[0x10];
    S_0068FA80_Obj *title;
    S_0068FA80_Obj *desc;
    S_0068FA80_Obj *name;
    S_0068FA80_Obj *t130;
    u8 pad134[4];
    S_0068FA80_Obj *t138;
    S_0068FA80_Obj *t13C;
    S_0068FA80_Obj *t140;
    S_0068FA80_Obj *t144;
    S_0068FA80_Obj *t148;
    S_0068FA80_Obj *t14C;
    S_0068FA80_Obj *star[4];
    u8 pad160[0x150];
    s32 enabled;
    s32 ids[0x40];
    s32 cur;
    s32 prev;
} S_0068FA80_Self;

void func_L39_0068FA80(char *arg0) {
    S_0068FA80_Self *s = (S_0068FA80_Self *)arg0;
    S_0068FA80_Info info;
    u8 str[0x100];
    S_0068FA80_Ranges r;
    char *g;
    s32 idx;
    s32 id;
    s32 list;
    s32 stats;
    s32 res;
    char *e;
    char *p;
    char *q;
    s32 mode;
    s32 n;
    s32 i;
    f32 *pa;
    f32 *pb;

    if (s->enabled == 0) {
        return;
    }
    idx = s->list->vt->getSelected(s->list);
    if (idx == -1) {
        return;
    }
    id = s->ids[idx];
    s->cur = id;
    if (id == s->prev) {
        return;
    }
    g = (char *)D_L39_0024D760;
    list = *(s32 *)(g + 0x44);
    s->prev = id;
    if (func_L39_006D6E50(list, id, 0, &info) == 0) {
        return;
    }
    res = 0;
    if (info.f30 >= 0) {
        res = func_L39_006D31B8(*(s32 *)(g + 0x38), s->cur, info.f30);
    }
    if (res != 0) {
        s->name->vt->setText(s->name, (void *)(res + 0x20));
    } else {
        s->name->vt->setText(s->name, func_00381FF0(0x12C6));
    }
    s->name->vt->setScale(s->name, 1, 1.0f, 0.0f);

    e = func_L39_006D6CF8(list, s->cur, 1, 0);
    if (e != 0) {
        func_00120048(str, D_L39_00247CD8, *(s32 *)(e + 0x1C));
    } else {
        str[0] = 0;
    }
    mode = 0;
    s->t130->vt->setText(s->t130, str);
    func_00120048(str, D_L39_00247CD8, info.f08);
    s->t13C->vt->setText(s->t13C, str);
    func_00120048(str, D_L39_00247CD8, info.f0C);
    s->t140->vt->setText(s->t140, str);
    func_00120048(str, D_L39_00247CD8, info.f14);
    s->t144->vt->setText(s->t144, str);
    func_00120048(str, D_L39_00247CD8, info.f18);
    s->t148->vt->setText(s->t148, str);
    func_00120048(str, D_L39_00247CD8, info.f28);
    s->t14C->vt->setText(s->t14C, str);
    func_00120048(str, D_L39_00247CD8, info.f2C);
    s->t138->vt->setText(s->t138, str);

    stats = *(s32 *)(g + 0x48);
    p = func_L39_006D98C8(stats, s->cur);
    q = func_L39_006D9328(stats, s->cur);
    if (p != 0) {
        if (*(s32 *)(p + 0x40) == 0) {
            mode = 3;
        } else {
            mode = (*(s32 *)(p + 0x40) == 1) ? 2 : 0;
        }
    } else if (q != 0) {
        mode = *(s32 *)(q + 0x40);
    }
    if (q != 0) {
        n = 1;
        r = *(S_0068FA80_Ranges *)(q + 0x48);
        pb = r.b;
        pa = r.a;
        for (i = 3; i >= 0; i--) {
            if (*pa > 0.0f) {
                n = (func_L39_006DF598(*pa, *pb) < n) ? n : func_L39_006DF598(*pa, *pb);
            }
            pb++;
            pa++;
        }
        s->star[0]->vt->setVisible(s->star[0], n > 0, 0);
        s->star[1]->vt->setVisible(s->star[1], n >= 2, 0);
        s->star[2]->vt->setVisible(s->star[2], n >= 3, 0);
        s->star[3]->vt->setVisible(s->star[3], n >= 4, 0);
    }

    if (**(s32 **)((char *)D_L39_0024D760 + 0x30) == s->cur) {
        s->title->vt->setText(s->title, func_00381FF0(0xFAE));
        s->desc->vt->setText(s->desc, func_00381FF0(0xFAC));
    } else if (mode == 0) {
        s->title->vt->setText(s->title, func_00381FF0(0xFAD));
        s->desc->vt->setText(s->desc, func_00381FF0(0xFAD));
    } else if (mode == 1) {
        s->title->vt->setText(s->title, func_00381FF0(0xFAE));
        s->desc->vt->setText(s->desc, func_00381FF0(0xF76));
    } else if (mode == 2) {
        s->title->vt->setText(s->title, func_00381FF0(0xFAE));
        s->desc->vt->setText(s->desc, func_00381FF0(0xFAF));
    } else if (mode == 3) {
        s->title->vt->setText(s->title, func_00381FF0(0xFAE));
        s->desc->vt->setText(s->desc, func_00381FF0(0xFB1));
    }
}
/* localdecomp:end func_L39_0068FA80 */

LINKER_REMNANT("asm/levels", func_L39_0068FFC8);

INCLUDE_ASM("asm/levels", func_L39_0068FFD8);

LINKER_REMNANT("asm/levels", func_L39_00690860);
