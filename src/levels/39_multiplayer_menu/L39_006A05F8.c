#include "common.h"

/* localdecomp:start func_L39_006A05F8 */
typedef struct {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_006A05F8;

typedef struct {
    H_006A05F8 h;
    u8 pad48[8];
} A_006A05F8;

typedef struct {
    H_006A05F8 h;
    u8 b48;
    u8 pad49[0x407];
} L_006A05F8;

typedef struct {
    H_006A05F8 h;
    s32 x48;
    s32 x4C;
    void *items[8];
    u8 pad70[0x1D0 - 0x70];
} D_006A05F8;

extern int D_L39_0047D628[];
extern char D_00248568[];
extern void *func_L39_00688388(void *);
extern void *func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

static __inline__ void lab_006A05F8(H_006A05F8 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void A_init_006A05F8(A_006A05F8 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006A05F8(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void L_init_006A05F8(L_006A05F8 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006A05F8(&t->h, text, x, y, w, h);
    t->h.type = 9;
    t->b48 = 0;
}

static __inline__ void D_init_006A05F8(D_006A05F8 *t) {
    lab_006A05F8(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_006A05F8(s32 arg) {
    u8 *self = (u8 *)arg;
    A_006A05F8 title;
    L_006A05F8 list;
    A_006A05F8 i1, i2, i3, i4, i5, i6;
    D_006A05F8 d;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x2D0;
    *(int **)(self + 0x60) = D_L39_0047D628;

    A_init_006A05F8(&title, func_00381FF0(0xFDE), 0.5f, 0.41f, 1.0f, 1.0f);
    L_init_006A05F8(&list, D_00248568, 0.5f, 0.49f, 0.44f, 0.2f);
    A_init_006A05F8(&i1, func_00381FF0(0x102B), 0.4f, 0.6f, 0.6f, 0.05f);
    A_init_006A05F8(&i2, func_00381FF0(0x102C), 0.6f, 0.6f, 0.6f, 0.05f);
    A_init_006A05F8(&i3, func_00381FF0(0x102D), 0.5f, 0.6f, 0.6f, 0.05f);
    A_init_006A05F8(&i4, func_00381FF0(0x102E), 0.6f, 0.6f, 0.6f, 0.05f);
    A_init_006A05F8(&i5, func_00381FF0(0x102F), 0.36f, 0.6f, 0.6f, 0.05f);
    A_init_006A05F8(&i6, func_00381FF0(0xF5F), 0.6f, 0.6f, 0.6f, 0.05f);
    D_init_006A05F8(&d);
    *(s32 *)(self + 0x2A8) = 0;
    d.x4C = 8;
    d.items[0] = &title;
    d.items[1] = &list;
    d.items[2] = &i1;
    d.items[3] = &i2;
    d.items[4] = &i3;
    d.items[5] = &i4;
    d.items[6] = &i5;
    d.items[7] = &i6;
    func_L39_00689670(self, &d);
    *(s32 *)(self + 0x2B0) = -1;
    *(s32 *)(self + 0x2B4) = -1;
    *(s32 *)(self + 0x2B8) = -1;
    *(s32 *)(self + 0x2BC) = -1;
    *(s32 *)(self + 0x2C4) = -1;
    *(s32 *)(self + 0x2C8) = -1;
    *(s32 *)(self + 0x2C0) = -1;
    *(u8 *)(self + 0x2CC) = 0;
    return self;
}
/* localdecomp:end func_L39_006A05F8 */

LINKER_REMNANT("asm/levels", func_L39_006A0948);
