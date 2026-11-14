#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006A4510);

/* localdecomp:start func_L39_006A4CB8 */
/* best: 13 diff with --mode S --as ps2as (190 with the file's default: default mode puts the
 * float literals in $gp, retail builds them with lui/ori, so this file likely wants S+ps2as).
 * Left: (1) retail keeps arg0+0x110 in $s3 from the prologue and starts loop 2 at $s3+0x34
 * (tried plain indexing, a sub-struct at 0x110: no change); (2) D_L39_00248730 (=0.37f,
 * lit.data) is loaded `lui $at; lwc1 ($at)` (a ps2as macro, unsplit) while ours splits via $v0;
 * (3) final 0x17 store uses $v0 not $v1. */
typedef struct VT_006A4CB8 {
    u8 pad0[0x1C];
    void (*fn1C)(void *, s32, s32);
    void (*fn20)(void);
    void (*fn24)(void *, s32);
    void (*fn28)(void *, f32, f32);
    void (*fn2C)(void *, f32, f32);
    u8 pad30[0x38 - 0x30];
    void (*fn38)(void *, f32, f32);
    u8 pad3C[0x40 - 0x3C];
    void (*fn40)(void *, s32);
    u8 pad44[0x4C - 0x44];
    void (*fn4C)(void *, s32, s32);
    u8 pad50[0x90 - 0x50];
    void (*fn90)(void *, f32);
    u8 pad94[0xE4 - 0x94];
    void (*fnE4)(void *, f32);
} VT_006A4CB8;
typedef struct Obj_006A4CB8 {
    u8 pad0[0x60];
    VT_006A4CB8 *vt;
} Obj_006A4CB8;
typedef struct S_006A4CB8 {
    u8 pad0[0x110];
    Obj_006A4CB8 *o[24];
    u8 pad170[0x314 - 0x170];
    s32 f314;
} S_006A4CB8;
extern f32 D_L39_004B0430[];
extern f32 D_L39_00248728[] __attribute__((section(".sdata")));
extern s32 func_00381FF0(s32);
s32 func_L39_0068B2F8(void *, s32, s32);

void func_L39_006A4CB8(S_006A4CB8 *arg0) {
    s32 i;
    VT_006A4CB8 *vt;

    for (i = 0; i < 8; i++) {
        arg0->o[5 + i]->vt->fn1C(arg0->o[5 + i], 1, 0);
    }
    for (i = 0; i < 7; i++) {
        arg0->o[13 + i]->vt->fn4C(arg0->o[13 + i], 0x40, 1);
        arg0->o[13 + i]->vt->fn1C(arg0->o[13 + i], 1, 0);
        arg0->o[13 + i]->vt->fn40(arg0->o[13 + i], 1);
        arg0->o[13 + i]->vt->fn28(arg0->o[13 + i], D_L39_004B0430[0], i * D_L39_004B0430[5] + D_L39_004B0430[1]);
        arg0->o[13 + i]->vt->fn2C(arg0->o[13 + i], D_L39_004B0430[2], D_L39_004B0430[3]);
    }
    arg0->o[19]->vt->fn1C(arg0->o[19], 3, 0);
    arg0->o[19]->vt->fn28(arg0->o[19], 0.2925f, D_L39_004B0430[5] * 10.0f + D_L39_004B0430[1]);
    arg0->o[20]->vt->fn40(arg0->o[20], 1);
    arg0->o[20]->vt->fn1C(arg0->o[20], 3, 0);
    arg0->o[20]->vt->fn4C(arg0->o[20], 0x40, 1);
    arg0->o[20]->vt->fn28(arg0->o[20], 0.645f, 0.335f);
    arg0->o[20]->vt->fn38(arg0->o[20], 1.0f, 1.0f);
    arg0->o[21]->vt->fn40(arg0->o[21], 1);
    arg0->o[21]->vt->fn28(arg0->o[21], 0.69f, 0.86f);
    arg0->o[21]->vt->fn38(arg0->o[21], 0.335f, 1.0f);
    arg0->o[21]->vt->fn90(arg0->o[21], 0.0505f);
    arg0->o[21]->vt->fn1C(arg0->o[21], 2, 0);
    arg0->o[21]->vt->fn4C(arg0->o[21], 0x200, 1);
    arg0->o[21]->vt->fn4C(arg0->o[21], 0x800, 1);
    arg0->o[21]->vt->fnE4(arg0->o[21], D_L39_00248728[2]);
    arg0->o[22]->vt->fn28(arg0->o[22], 0.5225f, 0.795f);
    arg0->o[22]->vt->fn38(arg0->o[22], 1.0f, 1.0f);
    arg0->o[22]->vt->fn40(arg0->o[22], 1);
    arg0->o[22]->vt->fn1C(arg0->o[22], 3, 0);
    arg0->o[22]->vt->fn4C(arg0->o[22], 0x40, 1);
    arg0->o[23]->vt->fn28(arg0->o[23], 0.695f, 0.834f);
    arg0->o[23]->vt->fn38(arg0->o[23], 1.0f, 1.0f);
    arg0->o[23]->vt->fn1C(arg0->o[23], 3, 0);
    arg0->o[23]->vt->fn4C(arg0->o[23], 0x40, 1);
    arg0->o[23]->vt->fn40(arg0->o[23], 0);
    vt = arg0->o[23]->vt;
    vt->fn24(arg0->o[23], func_00381FF0(0xF8C));

    func_L39_0068B2F8(arg0, 0x17, 0);
    arg0->f314 = 0x17;
}
/* localdecomp:end func_L39_006A4CB8 */

INCLUDE_ASM("asm/levels", func_L39_006A50F8);

/* localdecomp:start func_L39_006A55B0 */
typedef struct S_006A55B0_item {
    char pad0[0x18];
    s32 f18;
    u8 f1C[4];
} S_006A55B0_item;

typedef struct S_006A55B0_list {
    s32 f0;
    s32 f4;
    S_006A55B0_item **f8;
} S_006A55B0_list;

typedef struct S_006A55B0_net {
    u8 f0;
    char pad1[0xC];
    u8 fD;
    char padE[6];
    S_006A55B0_list f14;
} S_006A55B0_net;

typedef struct S_006A55B0_g {
    char pad0[0x4C];
    void *f4C;
    char pad50[0x28];
    S_006A55B0_net *f78;
} S_006A55B0_g;

extern S_006A55B0_g *D_L39_0024D760;
extern u8 D_L39_00248640[];
extern u8 D_L39_00248648[];
extern u8 *func_L39_006DB750(void *);
extern s32 func_001200E0(void *, void *, ...);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_L39_006D7018(S_006A55B0_net *);
extern void func_00195410(void);
extern void func_L39_006D8B88(S_006A55B0_g *);

u8 *func_L39_006A55B0(void)
{
    s32 x;
    s32 y;
    S_006A55B0_net *net;
    S_006A55B0_list *list;
    u8 *r;
    u8 *name;
    s32 id;
    s32 start;
    s32 i;
    u8 c;
    s32 *px;
    s32 *py;

    net = D_L39_0024D760->f78;
    list = net->fD ? &net->f14 : 0;
    r = func_L39_006DB750(D_L39_0024D760->f4C);
    if (r == 0) {
        return 0;
    }
    name = r + 0x1C;
    px = &x;
    py = &y;
    if (name[0] == 'C') {
        c = name[1];
        if (c == 'Y' || c == 'R') {
            func_001200E0(r + 0x1E, D_L39_00248640, px, py);
        } else if (c == 'C') {
            func_001200E0(r + 0x1E, D_L39_00248648, px);
        }
    } else if (name[0] == 'H') {
        func_001200E0(r + 0x1E, D_L39_00248640, px, py);
    }
    id = x + 0x28;
    start = func_00130760(func_0012DCB0(), 0x24000);
    while (list == 0) {
        func_L39_006D7018(net);
        c = net->f0;
        if (c) {
            do {
                func_00195410();
                if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                    return 0;
                }
                if (D_L39_0024D760 != 0) {
                    func_L39_006D8B88(D_L39_0024D760);
                }
            } while (net->f0);
        }
        list = net->fD ? &net->f14 : 0;
    }
    for (i = 0; i < list->f4; i++) {
        if (list->f8[i]->f18 == id) {
            return list->f8[i]->f1C;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006A55B0 */

LINKER_REMNANT("asm/levels", func_L39_006A57A0);

/* localdecomp:start func_L39_006A57B0 */
typedef struct H_006A57B0 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_006A57B0;
typedef struct I50_006A57B0 {
    H_006A57B0 h;
    s32 f48;
    s32 f4C;
} I50_006A57B0;
typedef struct M_006A57B0 {
    H_006A57B0 h;
    s32 f48;
    s32 f4C;
    void *items[0x60];
} M_006A57B0;
typedef struct E_006A57B0 {
    char pad[0x20];
} E_006A57B0;
typedef struct P_006A57B0 {
    E_006A57B0 elems[64];
    E_006A57B0 *ptrs[64];
    u8 pad[0x10C];
} P_006A57B0;
typedef struct S_006A57B0 {
    char pad0[0x60];
    u8 *f60;
    char pad64[0x240];
    u8 *f2A4;
    char pad2A8[0x114];
    P_006A57B0 f3BC;
    P_006A57B0 fDC8;
} S_006A57B0;

extern u8 D_L39_0047D978[];
void *func_L39_00688388(void *);
void func_L39_00689670(void *, void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern s32 func_00381FF0(s32);

static __inline__ void *item_006A57B0(void *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    ((H_006A57B0 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
    return it;
}

void *func_L39_006A57B0(S_006A57B0 *arg0) {
    I50_006A57B0 it0;
    I50_006A57B0 it1;
    I50_006A57B0 it2;
    I50_006A57B0 it3;
    I50_006A57B0 it4;
    M_006A57B0 menu;
    I50_006A57B0 *p0, *p1, *p2, *p3, *p4;
    M_006A57B0 *pm;
    s32 name;
    s32 i;

    func_L39_00688388(arg0);
    arg0->f60 = D_L39_0047D978;
    arg0->f2A4 = (u8 *)arg0 + 0x1728;

    name = func_00381FF0(0xFC1);
    p0 = &it0;
    item_006A57B0(p0, name, 0.502f, 0.3878f, 0.435f, 0.05f);
    it0.h.type = 1;
    name = func_00381FF0(0xFCD);
    p1 = &it1;
    item_006A57B0(p1, name, 0.502f, 0.4464f, 0.435f, 0.05f);
    it1.h.type = 1;
    name = func_00381FF0(0x10ED);
    p2 = &it2;
    item_006A57B0(p2, name, 0.502f, 0.505f, 0.435f, 0.05f);
    it2.h.type = 1;
    name = func_00381FF0(0xFD0);
    p3 = &it3;
    item_006A57B0(p3, name, 0.502f, 0.5636f, 0.435f, 0.05f);
    it3.h.type = 1;
    name = func_00381FF0(0x1030);
    p4 = &it4;
    item_006A57B0(p4, name, 0.502f, 0.6222f, 0.435f, 0.05f);
    it4.h.type = 1;

    pm = &menu;
    item_006A57B0(pm, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pm->f48 = 0x2E;
    menu.f4C = 0;
    menu.h.x = 0;
    menu.h.y = 0;
    pm->h.w = 1.0f;
    pm->h.h = 1.0f;
    menu.f4C = 5;
    menu.items[1] = p1;
    menu.items[2] = p2;
    menu.items[3] = p3;
    menu.items[4] = p4;
    menu.items[0] = p0;
    func_L39_00689670(arg0, pm);

    for (i = 63; i >= 0; i--) {
        arg0->fDC8.ptrs[i] = &arg0->fDC8.elems[i];
    }
    for (i = 63; i >= 0; i--) {
        arg0->f3BC.ptrs[i] = &arg0->f3BC.elems[i];
    }
    return arg0;
}
/* localdecomp:end func_L39_006A57B0 */

LINKER_REMNANT("asm/levels", func_L39_006A5A70);
