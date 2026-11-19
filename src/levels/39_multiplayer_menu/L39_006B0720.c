#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_006B0720);

/* localdecomp:start func_L39_006B0728 */
typedef struct {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_006B0728;

typedef struct {
    H_006B0728 h;
    u8 pad48[8];
} A_006B0728;

typedef struct {
    H_006B0728 h;
    u8 b48;
    u8 pad49[0x407];
} L_006B0728;

typedef struct {
    H_006B0728 h;
    s32 x48;
    s32 x4C;
    void *items[5];
    u8 pad64[0x1D0 - 0x64];
} D_006B0728;

extern u8 D_L39_0047E0A0[];
extern char D_L39_00248E18[];
extern void *func_L39_00688388(void *);
extern void *func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

static __inline__ void lab_006B0728(H_006B0728 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void A_init_006B0728(A_006B0728 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006B0728(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void L_init_006B0728(L_006B0728 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006B0728(&t->h, text, x, y, w, h);
    t->b48 = 0;
    t->h.type = 9;
}

static __inline__ void D_init_006B0728(D_006B0728 *t) {
    lab_006B0728(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_006B0728(s32 arg) {
    u8 *self = (u8 *)arg;
    A_006B0728 i1, i2, i3, i4;
    L_006B0728 list;
    D_006B0728 d;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x2B0;
    *(u8 **)(self + 0x60) = D_L39_0047E0A0;

    A_init_006B0728(&i1, func_00381FF0(0xF56), 0.501f, 0.386625f, 0.432f, 0.05f);
    A_init_006B0728(&i2, func_00381FF0(0xF58), 0.501f, 0.464875f, 0.432f, 0.05f);
    A_init_006B0728(&i3, func_00381FF0(0x18CC), 0.501f, 0.54312503f, 0.432f, 0.05f);
    A_init_006B0728(&i4, func_00381FF0(0x15CE), 0.501f, 0.621375f, 0.432f, 0.05f);
    L_init_006B0728(&list, D_L39_00248E18, 0.5f, 0.85f, 0.82f, 0.15f);
    D_init_006B0728(&d);
    d.items[0] = &i1;
    d.items[1] = &i2;
    d.items[2] = &i3;
    d.items[3] = &i4;
    d.items[4] = &list;
    d.x4C = 5;
    func_L39_00689670(self, &d);
    *(u8 *)(self + 0x2A8) = 0;
    return self;
}
/* localdecomp:end func_L39_006B0728 */
