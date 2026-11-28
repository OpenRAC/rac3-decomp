/* wave 13c c43 (2026-11-28): 378 diff under the line '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'
 * (tools/check.py --flags=@ps2as; L39_006A3690.c's line): the li.s constants and the length now match retail. This
 * attempt declares the pointer variables in the order of retail's spill slots (0xEB4 f3, 0xEB8 menu, 0xEC0 f1, ...);
 * left: the slot permutation, fp/s7 roles (retail fp = self, s7 = &pk, s6 = %hi(D_L39_004B0430)) and an extra $f23
 * save. Without any pointer variable (plain &f1 ... &menu) -fopt-stack itself hoists every reused stack address
 * after the box init as retail does (429 diff, in another spill order), so the original most likely had none and the
 * residue is -fopt-stack's pseudo order. r28's notes follow.
 * PAL near miss (wave 13 r28, 2026-11-28), first draft (fresh entry): 429 positional diff under the file's line.
 * Blocker: L39_006A29D0.c's line has no @ps2as, so GNU as turns every li.s of a float literal with a non-zero low
 * half (0.50025, 0.2175, 0.815, 0.15, 0.69, 0.86, 0.335, 0.695, 0.834) into a $gp .lit4 lwc1, where retail has
 * lui/ori/mtc1 (SN's assembler; the sibling menu constructors' files, e.g. L39_006A61A0.c and L39_006B32A8.c,
 * have @ps2as): 20 words shorter, so it cannot match under this line. The rest follows retail: inline cell init
 * in do/while (--n != -1) loops, pointer variables taken after the box init (retail spills them to 0xEB0-0xEE8),
 * direct x.h.type = 0 stores with the pointer passed to func_L39_0068CD28, the name fetched before the type store,
 * const D_L39_004B0430 (t[5]/t[1] stay in f20/f21 across calls), max/sel/f48/w/h stores through the pointers.
 * Left besides li.s: register and spill-slot choice (retail keeps the table's %hi in  and pk's pointer in ). */
#include "common.h"

/* localdecomp:start func_L39_006A2F50 */
typedef struct H_006A2F50 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_006A2F50;
typedef struct P_006A2F50 {
    H_006A2F50 h;
    u8 b48;
    s32 f4C;
} P_006A2F50;
typedef struct T_006A2F50 {
    H_006A2F50 h;
    char text[0x50];
    u8 pad98[0x8];
} T_006A2F50;
typedef struct S_006A2F50 {
    H_006A2F50 h;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    s32 f58;
    s32 f5C;
} S_006A2F50;
typedef struct F_006A2F50 {
    H_006A2F50 h;
    u8 b48;
    u8 pad49[0xC7];
    s32 max;
    u8 b114;
    u8 b115;
    u8 b116;
    u8 pad117[9];
} F_006A2F50;
typedef struct N_006A2F50 {
    H_006A2F50 h;
    s32 f48;
    s32 f4C;
    s32 data;
    s32 max;
    s32 f58;
    s32 f5C;
    s32 sel;
    f32 f64;
    u8 pad68[8];
} N_006A2F50;
typedef struct K_006A2F50 {
    H_006A2F50 h;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0xC];
} K_006A2F50;
typedef struct M_006A2F50 {
    H_006A2F50 h;
    s32 f48;
    s32 n;
    void *items[0x60];
} M_006A2F50;

extern u8 D_L39_0047D858[];
extern char D_L39_00248698[];
extern const f32 D_L39_004B0430[];
extern s32 D_L39_002487C0[];

static __inline__ void item_006A2F50(void *it, void *name, f32 x, f32 y, f32 w, f32 h) {
    extern void func_L39_0068CD28(void *, void *, f32, f32, f32, f32);
    ((H_006A2F50 *)it)->type = 0;
    func_L39_0068CD28(it, name, x, y, w, h);
}

static __inline__ void cell_006A2F50(S_006A2F50 *it) {
    item_006A2F50(it, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    it->h.type = 12;
    it->f58 = -1;
    it->f50 = 0.0f;
    it->f48 = 0.0f;
    it->f54 = 1.0f;
    it->f4C = 1.0f;
    it->f5C = 0x706EC8FF;
}

void *func_L39_006A2F50(u8 *self) {
    extern void func_L39_00688388(void *);
    extern void func_00120D28(void *, void *, s32);
    extern void func_L39_00689670(void *, void *);
    extern void func_L39_0068CD28(void *, void *, f32, f32, f32, f32);
    P_006A2F50 box;
    S_006A2F50 c0[4];
    S_006A2F50 c1[8];
    F_006A2F50 f1;
    F_006A2F50 f2;
    F_006A2F50 f3;
    F_006A2F50 f4;
    T_006A2F50 txt;
    F_006A2F50 f6;
    P_006A2F50 l7;
    P_006A2F50 l8;
    N_006A2F50 spin;
    K_006A2F50 pk;
    P_006A2F50 l11;
    M_006A2F50 menu;
    F_006A2F50 *pf3;
    M_006A2F50 *pm;
    F_006A2F50 *pf1;
    P_006A2F50 *pl8;
    F_006A2F50 *pf4;
    F_006A2F50 *pf6;
    S_006A2F50 *pc1;
    F_006A2F50 *pf2;
    N_006A2F50 *pspin;
    P_006A2F50 *pl11;
    T_006A2F50 *ptxt;
    P_006A2F50 *pl7;
    K_006A2F50 *ppk;
    S_006A2F50 *q;
    s32 n;
    s32 i;
    void *data;
    void *nm;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x340;
    *(void **)(self + 0x60) = D_L39_0047D858;

    item_006A2F50(&box, D_L39_00248698, 0.50025f, 0.2175f, 0.815f, 0.15f);
    box.f4C = -1;
    box.h.type = 4;
    box.b48 = 0;
    pc1 = c1;
    pf1 = &f1;
    pf2 = &f2;
    pf3 = &f3;
    pf4 = &f4;
    ptxt = &txt;
    pf6 = &f6;
    pl7 = &l7;
    pl8 = &l8;
    pspin = &spin;
    ppk = &pk;
    pl11 = &l11;
    pm = &menu;

    q = c0;
    n = 3;
    do {
        cell_006A2F50(q);
        q++;
    } while (--n != -1);
    q = pc1;
    n = 7;
    do {
        cell_006A2F50(q);
        q++;
    } while (--n != -1);

    nm = func_00381FF0(0xFE6);
    f1.h.type = 0;
    func_L39_0068CD28(pf1, nm, D_L39_004B0430[0], D_L39_004B0430[5] * 0.0f + D_L39_004B0430[1], D_L39_004B0430[2], D_L39_004B0430[3]);
    f1.h.type = 8;
    f1.b48 = 0;
    f1.b114 = 0;
    pf1->max = 0x20;
    f1.b115 = 0;
    f1.b116 = 0;
    nm = func_00381FF0(0xFE9);
    f2.h.type = 0;
    func_L39_0068CD28(pf2, nm, D_L39_004B0430[0], D_L39_004B0430[5] + D_L39_004B0430[1], D_L39_004B0430[2], D_L39_004B0430[3]);
    f2.h.type = 8;
    f2.b48 = 0;
    f2.b114 = 0;
    pf2->max = 0x20;
    f2.b115 = 0;
    f2.b116 = 0;
    nm = func_00381FF0(0xFEA);
    f3.h.type = 0;
    func_L39_0068CD28(pf3, nm, D_L39_004B0430[0], D_L39_004B0430[5] * 2.0f + D_L39_004B0430[1], D_L39_004B0430[2], D_L39_004B0430[3]);
    f3.h.type = 8;
    f3.b48 = 0;
    f3.b114 = 0;
    pf3->max = 0x20;
    f3.b115 = 0;
    f3.b116 = 0;
    nm = func_00381FF0(0x116C);
    f4.h.type = 0;
    func_L39_0068CD28(pf4, nm, D_L39_004B0430[0], D_L39_004B0430[5] * 3.0f + D_L39_004B0430[1], D_L39_004B0430[2], D_L39_004B0430[3]);
    f4.h.type = 8;
    f4.b48 = 0;
    f4.b114 = 0;
    pf4->max = 0x20;
    f4.b115 = 0;
    f4.b116 = 0;
    nm = func_00381FF0(0x1607);
    txt.h.type = 0;
    func_L39_0068CD28(ptxt, nm, D_L39_004B0430[0], D_L39_004B0430[5] * 4.0f + D_L39_004B0430[1], D_L39_004B0430[2], D_L39_004B0430[3]);
    txt.h.type = 7;
    if (D_L39_00248698 != 0) {
        func_00120D28(txt.text, D_L39_00248698, 0x4F);
        txt.text[0x4F] = 0;
    } else {
        txt.text[0] = 0;
    }
    nm = func_00381FF0(0x116D);
    f6.h.type = 0;
    func_L39_0068CD28(pf6, nm, D_L39_004B0430[0], D_L39_004B0430[5] * 5.0f + D_L39_004B0430[1], D_L39_004B0430[2], D_L39_004B0430[3]);
    f6.h.type = 8;
    f6.b48 = 0;
    f6.b114 = 0;
    pf6->max = 0x20;
    f6.b115 = 0;
    f6.b116 = 0;
    nm = func_00381FF0(0x169D);
    l7.h.type = 0;
    func_L39_0068CD28(pl7, nm, D_L39_004B0430[0], D_L39_004B0430[5] * 10.0f + D_L39_004B0430[1], D_L39_004B0430[2], D_L39_004B0430[3]);
    l7.h.type = 1;
    l8.h.type = 0;
    func_L39_0068CD28(pl8, D_L39_00248698, 0.0f, 0.0f, 0.0f, 0.0f);
    l8.h.type = 1;

    data = func_00381FF0(0x1015);
    spin.h.type = 0;
    func_L39_0068CD28(pspin, D_L39_00248698, 0.69f, 0.86f, 0.335f, 1.0f);
    spin.data = (s32)data;
    spin.h.type = 5;
    spin.f48 = 0;
    spin.f4C = 0;
    pspin->max = 8;
    spin.f58 = 0;
    spin.f5C = 0;
    pspin->sel = -1;
    spin.f64 = 0.0f;

    nm = func_00381FF0(0xFE7);
    pk.h.type = 0;
    func_L39_0068CD28(ppk, nm, D_L39_004B0430[12], D_L39_004B0430[17] * 0.0f + D_L39_004B0430[13], D_L39_004B0430[14], D_L39_004B0430[15]);
    pk.h.type = 6;
    ppk->f50 = 2;
    ppk->f5C = -1;
    ppk->f48 = 1;
    ppk->f4C = 1;
    ppk->f54 = 1;
    ppk->f58 = -1;
    ppk->f60 = -1;

    nm = func_00381FF0(0xF8C);
    l11.h.type = 0;
    func_L39_0068CD28(pl11, nm, 0.695f, 0.834f, 1.0f, 1.0f);
    l11.h.type = 1;

    menu.h.type = 0;
    func_L39_0068CD28(pm, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pm->f48 = 0x2E;
    menu.n = 0;
    menu.h.x = 0.0f;
    menu.h.y = 0.0f;
    pm->h.w = 1.0f;
    pm->h.h = 1.0f;
    menu.n = 24;
    menu.items[0] = &box;
    for (i = 0; i < 4; i++) {
        c0[i].f58 = 0xED26;
        pm->items[1 + i] = &c0[i];
    }
    for (i = 0; i < 8; i++) {
        pc1[i].f58 = D_L39_002487C0[i];
        pm->items[5 + i] = &pc1[i];
    }
    menu.items[13] = pf1;
    menu.items[14] = pf2;
    menu.items[15] = pf3;
    menu.items[16] = pf4;
    menu.items[17] = ptxt;
    menu.items[18] = pf6;
    menu.items[19] = pl7;
    menu.items[20] = pl8;
    menu.items[21] = pspin;
    menu.items[22] = ppk;
    menu.items[23] = pl11;
    func_L39_00689670(self, pm);
    *(s32 *)(self + 0x310) = 1;
    *(s32 *)(self + 0x2C0) = 0;
    return self;
}
/* localdecomp:end func_L39_006A2F50 */
