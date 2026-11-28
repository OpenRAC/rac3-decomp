/* func_L39_0068FFD8 (level 39, L39_0068FA80.c): first draft (fresh entry), wave 13 r22.
 * check.py 28 diff at level 39; aligned, only 2 rows differ (one instruction placed elsewhere).
 * The multiplayer-menu screen constructor: base ctor func_L39_00688388, vtable at +0x60,
 * +0x2A4 = self + 0x27C8, then a panel (type 5), 4 labels (type 1), 11 text rows (type 8),
 * 4 colour bars (type 0xC) and the list (type 0x2E, 20 items) handed to func_L39_00689670.
 * Every element is built by the label helper func_L39_0068CD28 through the sibling file's
 * inline-init idioms (lab/B/A/T/C/D); float constants as single-set locals (tx, tw, bh, zero)
 * and the C/D helpers take the 0.0f as a parameter so the constants land in f20-f25 as retail.
 * Still differs: the reload of self (lw $a0, 0x1160($sp)) for the last call. Here sched1
 * hoists the a0 argument move to just after the list's label call, so sched2 puts the
 * reload among the list's own field stores; retail has it later, between items[14] and
 * items[13] (after sw $s2, 0x1018($sp)). Tried: count store at the end (34), inline add or
 * put helpers (same 28), literal 0.0f in the list init (same), do { } while (0) around the
 * call (93, a barrier), &self through an inline helper (49, self gets a late slot), a char[4]
 * stack copy of self (541, moves the reload to just before the jal but grows the frame).
 */
#include "common.h"

/* localdecomp:start func_L39_0068FFD8 */
typedef struct {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_0068FFD8;

typedef struct {
    H_0068FFD8 h;
    s32 x48;
    s32 x4C;
    void *help;
    s32 x54;
    s32 x58;
    s32 x5C;
    s32 x60;
    s32 x64;
    u8 pad68[8];
} B_0068FFD8;

typedef struct {
    H_0068FFD8 h;
    u8 pad48[8];
} A_0068FFD8;

typedef struct {
    H_0068FFD8 h;
    char str[0xC8];
    s32 x110;
    u8 x114;
    u8 x115;
    u8 x116;
    u8 pad117[9];
} T_0068FFD8;

typedef struct {
    H_0068FFD8 h;
    f32 x48;
    f32 x4C;
    f32 x50;
    f32 x54;
    s32 x58;
    s32 x5C;
} C_0068FFD8;

typedef struct {
    H_0068FFD8 h;
    s32 x48;
    s32 x4C;
    void *items[20];
    u8 pad[0x1D0 - 0xA0];
} D_0068FFD8;

extern u8 D_L39_0047C820[];
extern u8 D_L39_00247D38[];
__asm__(".extern D_L39_00247D38, 4");
extern f32 D_L39_00247D34;
__asm__(".extern D_L39_00247D34, 4");
extern void *func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

static __inline__ void lab_0068FFD8(H_0068FFD8 *t, s32 text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void B_init_0068FFD8(B_0068FFD8 *t, s32 text, void *help, f32 x, f32 y, f32 w, f32 h, s32 n, s32 sel) {
    lab_0068FFD8(&t->h, text, x, y, w, h);
    t->help = help;
    t->h.type = 5;
    t->x48 = 0;
    t->x4C = 0;
    t->x54 = n;
    t->x58 = 0;
    t->x5C = 0;
    t->x60 = sel;
    t->x64 = 0;
}

static __inline__ void A_init_0068FFD8(A_0068FFD8 *t, s32 text, f32 x, f32 y, f32 w, f32 h) {
    lab_0068FFD8(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void T_init_0068FFD8(T_0068FFD8 *t, s32 text, f32 x, f32 y, f32 w, f32 h, s32 n, u8 c0, u8 c1, u8 c2) {
    lab_0068FFD8(&t->h, text, x, y, w, h);
    t->h.type = 8;
    t->str[0] = 0;
    t->x114 = c0;
    t->x110 = n;
    t->x115 = c1;
    t->x116 = c2;
}

static __inline__ void C_init_0068FFD8(C_0068FFD8 *t, s32 text, f32 x, f32 y, f32 w, f32 h, s32 id, s32 col, f32 u0, f32 u1) {
    lab_0068FFD8(&t->h, text, x, y, w, h);
    t->h.type = 0xC;
    t->x58 = id;
    t->x48 = u0;
    t->x50 = u0;
    t->x4C = u1;
    t->x54 = u1;
    t->x5C = col;
}

static __inline__ void D_init_0068FFD8(D_0068FFD8 *t, f32 u0) {
    lab_0068FFD8(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = u0;
    t->h.y = u0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_0068FFD8(u8 *self) {
    B_0068FFD8 panel;
    A_0068FFD8 lab0;
    A_0068FFD8 lab1;
    A_0068FFD8 lab2;
    A_0068FFD8 lab3;
    T_0068FFD8 txt0;
    T_0068FFD8 txt1;
    T_0068FFD8 txt2;
    T_0068FFD8 txt3;
    C_0068FFD8 bar0;
    C_0068FFD8 bar1;
    C_0068FFD8 bar2;
    C_0068FFD8 bar3;
    T_0068FFD8 txt4;
    T_0068FFD8 txt5;
    T_0068FFD8 txt6;
    T_0068FFD8 txt7;
    T_0068FFD8 txt8;
    T_0068FFD8 txt9;
    T_0068FFD8 txt10;
    D_0068FFD8 list;
    f32 y;
    f32 ly;
    f32 tx = 0.475f;
    f32 tw = 0.41f;
    f32 bh = 0.04f;
    f32 zero = 0.0f;

    func_L39_00688388(self);
    *(u8 **)(self + 0x60) = D_L39_0047C820;
    *(u8 **)(self + 0x2A4) = self + 0x27C8;
    B_init_0068FFD8(&panel, (s32)D_L39_00247D38, func_00381FF0(0x101A), 0.275f, 0.535f, 0.345f, 0.618f, 0xB, -1);
    ly = D_L39_00247D34;
    A_init_0068FFD8(&lab0, (s32)func_00381FF0(0xF8E), 0.687f, ly, 1.0f, 1.0f);
    ly += 0.05f;
    A_init_0068FFD8(&lab1, (s32)func_00381FF0(0x10ED), 0.687f, ly, 1.0f, 1.0f);
    ly += 0.05f;
    A_init_0068FFD8(&lab2, (s32)func_00381FF0(0xFC2), 0.687f, ly, 1.0f, 1.0f);
    A_init_0068FFD8(&lab3, (s32)func_00381FF0(0xFC1), 0.27f, 0.185f, 1.0f, 1.0f);
    y = 0.182f;
    T_init_0068FFD8(&txt0, (s32)func_00381FF0(0xF8A), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt1, (s32)func_00381FF0(0x10FC), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt2, (s32)func_00381FF0(0x1322), 0.48f, y, 0.39f, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt3, (s32)func_00381FF0(0x1101), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    C_init_0068FFD8(&bar0, (s32)D_L39_00247D38, 0.877f, y, 0.03f, bh, 0xED26, 0x706EC8FF, zero, 1.0f);
    C_init_0068FFD8(&bar1, (s32)D_L39_00247D38, 0.877f - bh, y, 0.03f, bh, 0xED26, 0x706EC8FF, zero, 1.0f);
    C_init_0068FFD8(&bar2, (s32)D_L39_00247D38, 0.877f - 2 * bh, y, 0.03f, bh, 0xED26, 0x706EC8FF, zero, 1.0f);
    C_init_0068FFD8(&bar3, (s32)D_L39_00247D38, 0.877f - 3 * bh, y, 0.03f, bh, 0xED26, 0x706EC8FF, zero, 1.0f);
    T_init_0068FFD8(&txt4, (s32)func_00381FF0(0x160B), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt5, (s32)func_00381FF0(0x12A4), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt6, (s32)func_00381FF0(0x1334), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt7, (s32)func_00381FF0(0x1335), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt8, (s32)func_00381FF0(0x1336), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt9, (s32)func_00381FF0(0x1337), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    y += 0.047f;
    T_init_0068FFD8(&txt10, (s32)func_00381FF0(0x133E), tx, y, tw, 1.0f, 0x20, 0, 0, 0);
    D_init_0068FFD8(&list, zero);
    list.x4C = 20;
    list.items[0] = &panel;
    list.items[1] = &lab0;
    list.items[2] = &lab1;
    list.items[3] = &lab2;
    list.items[4] = &lab3;
    list.items[5] = &txt0;
    list.items[6] = &txt1;
    list.items[7] = &txt2;
    list.items[8] = &txt3;
    list.items[9] = &txt4;
    list.items[10] = &txt5;
    list.items[11] = &txt6;
    list.items[12] = &txt7;
    list.items[13] = &txt8;
    list.items[14] = &txt9;
    list.items[15] = &txt10;
    list.items[16] = &bar0;
    list.items[17] = &bar1;
    list.items[18] = &bar2;
    list.items[19] = &bar3;
    func_L39_00689670(self, &list);
    return self;
}
/* localdecomp:end func_L39_0068FFD8 */
