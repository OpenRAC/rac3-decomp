#include "common.h"

/* localdecomp:start func_L39_006B2D50 */
typedef struct {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_006B2D50;

typedef struct {
    H_006B2D50 h;
    u8 pad48[8];
} A_006B2D50;

typedef struct {
    H_006B2D50 h;
    char str[0x50];
    u8 pad98[8];
} L_006B2D50;

typedef struct {
    H_006B2D50 h;
    char str[0xC8];
    s32 x110;
    u8 x114;
    u8 x115;
    u8 x116;
    u8 pad117[9];
} T_006B2D50;

typedef struct {
    H_006B2D50 h;
    s32 x48;
    s32 x4C;
    void *items[4];
    u8 pad60[0x1D0 - 0x60];
} D_006B2D50;

extern u8 D_L39_0047E310[];
extern char D_L39_00248F00[];
extern char D_L39_00248F08[];
extern void *func_L39_00688388(void *);
extern void *func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_00120D28(char *, char *, s32);
extern void func_L39_00689670(void *, void *);

static __inline__ void lab_006B2D50(H_006B2D50 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void A_init_006B2D50(A_006B2D50 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006B2D50(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void L_init_006B2D50(L_006B2D50 *t, void *text, f32 x, f32 y, f32 w, f32 h, char *s) {
    lab_006B2D50(&t->h, text, x, y, w, h);
    t->h.type = 7;
    if (s != 0) {
        func_00120D28(t->str, s, 0x4F);
        t->str[0x4F] = 0;
    } else {
        t->str[0] = 0;
    }
}

static __inline__ void T_init_006B2D50(T_006B2D50 *t, void *text, f32 x, f32 y, f32 w, f32 h, char *src, s32 n, u8 c0, u8 c1, u8 c2) {
    lab_006B2D50(&t->h, text, x, y, w, h);
    t->h.type = 8;
    if (src == 0) {
        t->str[0] = 0;
    } else {
        func_00120D28(t->str, src, 0xC7);
        t->str[0xC7] = 0;
    }
    t->x114 = c0;
    t->x110 = n;
    t->x115 = c1;
    t->x116 = c2;
}

static __inline__ void D_init_006B2D50(D_006B2D50 *t) {
    lab_006B2D50(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_006B2D50(s32 arg) {
    u8 *self = (u8 *)arg;
    L_006B2D50 l;
    T_006B2D50 t;
    A_006B2D50 a1, a2;
    D_006B2D50 d;

    func_L39_00688388(self);
    *(u8 **)(self + 0x60) = D_L39_0047E310;
    *(u8 **)(self + 0x2A4) = self + 0x2B0;

    L_init_006B2D50(&l, D_L39_00248F00, 0.5f, 0.3f, 0.475f, 0.485f, func_00381FF0(0x1183));
    T_init_006B2D50(&t, func_00381FF0(0xF5D), 0.502f, 0.705f, 0.475f, 0.485f, D_L39_00248F08, 0xE, 0, 0, 0);
    A_init_006B2D50(&a1, func_00381FF0(0x102D), 0.2f, 0.25f, 1.0f, 1.0f);
    A_init_006B2D50(&a2, func_00381FF0(0x102E), 0.2f, 0.3f, 1.0f, 1.0f);
    D_init_006B2D50(&d);
    d.items[0] = &l;
    d.items[1] = &t;
    d.items[2] = &a1;
    d.items[3] = &a2;
    d.x4C = 4;
    func_L39_00689670(self, &d);
    return self;
}
/* localdecomp:end func_L39_006B2D50 */

LINKER_REMNANT("asm/levels", func_L39_006B2FC0);
