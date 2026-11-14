#include "common.h"

/* localdecomp:start func_L39_006ABC38 */
extern u8 D_L39_0047DCA0[];
extern u8 D_L39_00248AA0[];
extern void *func_L39_00688388(void *);
extern s32 func_00381FF0(s32);
extern void func_0019AE60(void);
extern void func_L39_0068CD28(u8 *, void *, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

typedef struct {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_006ABC38;

typedef struct {
    H_006ABC38 h;
    s32 count;
    s32 *values;
    s32 x50, x54, x58, x5C, x60;
    u8 pad64[0x70 - 0x64];
} N_006ABC38;

typedef struct {
    H_006ABC38 h;
    u8 b48;
    u8 pad49[3];
    s32 x4C;
} A_006ABC38;

typedef struct {
    H_006ABC38 h;
    s32 x48;
    s32 x4C;
    void *items[0x60];
} D_006ABC38;

typedef struct {
    u8 pad0[0x60];
    void *vt60;
    u8 pad64[0x2A4 - 0x64];
    char *text_ptr;
    s32 x2A8;
    s32 x2AC;
    s32 x2B0, x2B4, x2B8, x2BC, x2C0, x2C4, x2C8, x2CC;
    u8 flags[8];
    s32 x2D8;
    s32 x2DC;
    s32 x2E0;
    u8 x2E4;
    u8 pad2E5[3];
    char text[1];
} Obj_006ABC38;

static __inline__ void lab_006ABC38(H_006ABC38 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void S_init_006ABC38(N_006ABC38 *t, void *text, f32 x, f32 y, f32 w, f32 h, s32 count, s32 *values) {
    lab_006ABC38(&t->h, text, x, y, w, h);
    t->h.type = 3;
    t->count = count;
    t->values = values;
    t->x50 = 0;
}

static __inline__ void N_init_006ABC38(N_006ABC38 *t, void *text, f32 x, f32 y, f32 w, f32 h, s32 value, s32 a, s32 b, s32 c, s32 d, s32 e) {
    lab_006ABC38(&t->h, text, x, y, w, h);
    t->h.type = 6;
    t->count = value;
    t->values = 0;
    t->x50 = a;
    t->x54 = b;
    t->x58 = c;
    t->x60 = e;
    t->x5C = d;
}

static __inline__ void A_init_006ABC38(A_006ABC38 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006ABC38(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void B_init_006ABC38(A_006ABC38 *t, void *text, f32 x, f32 y, f32 w, f32 h, s32 n) {
    lab_006ABC38(&t->h, text, x, y, w, h);
    t->h.type = 4;
    t->x4C = n;
    t->b48 = 0;
}

static __inline__ void D_init_006ABC38(D_006ABC38 *t) {
    lab_006ABC38(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_006ABC38(Obj_006ABC38 *self) {
    func_L39_00688388(self);
    self->vt60 = D_L39_0047DCA0;
    self->text_ptr = self->text;
    {
        s32 a[10] = { func_00381FF0(0xBB1), func_00381FF0(0xBB2), func_00381FF0(0xDA), func_00381FF0(0xBB4), func_00381FF0(0xD8), func_00381FF0(0xD4), func_00381FF0(0x18C4), func_00381FF0(0x18C5), func_00381FF0(0x18C6), func_00381FF0(0x18C7) };
        s32 b[3] = { func_00381FF0(0x1024), func_00381FF0(0x10E2), func_00381FF0(0x1026) };
        N_006ABC38 i0, i1, i2;
        A_006ABC38 i3, i4, i5, i6;
        D_006ABC38 d;
        s32 i;
        u8 *p;

        func_0019AE60();
        self->x2E4 = 1;
        self->x2DC = 0x14;
        self->x2E0 = 3;
        self->x2A8 = 0;
        self->x2D8 = 0;
        self->x2B0 = 0;
        self->x2B4 = 1;
        self->x2B8 = 1;
        self->x2BC = 0;
        self->x2C0 = 1;
        self->x2C4 = 0;
        self->x2C8 = 0;
        self->x2CC = 0;
        i = 7;
        p = &self->flags[7];
        for (; i >= 0; i--) {
            *p-- = 1;
        }
        S_init_006ABC38(&i0, (void *)func_00381FF0(0xFE9), 0.10800001f, 0.17267853f, 0.37f, 0.05f, 10, a);
        S_init_006ABC38(&i1, (void *)func_00381FF0(0xFBB), 0.10800001f, 0.273392856f, 0.37f, 0.05f, 3, b);
        N_init_006ABC38(&i2, (void *)func_00381FF0(0x10E7), 0.10800001f, 0.374107122f, 0.37f, 0.05f, self->x2D8, 0x23, 5, 0x102C, 0x116B, 0x116B);
        A_init_006ABC38(&i3, (void *)func_00381FF0(0x116D), 0.293f, 0.474821419f, 0.37f, 0.05f);
        A_init_006ABC38(&i4, (void *)func_00381FF0(0x10E3), 0.293f, 0.575535715f, 0.37f, 0.05f);
        B_init_006ABC38(&i5, D_L39_00248AA0, 0.708f, 0.266f, 0.385f, 0.235f, 7);
        B_init_006ABC38(&i6, D_L39_00248AA0, 0.708f, 0.631f, 0.385f, 0.440999985f, 0x11);
        D_init_006ABC38(&d);
        d.x4C = 7;
        d.items[0] = &i0;
        d.items[1] = &i1;
        d.items[2] = &i2;
        d.items[3] = &i3;
        d.items[4] = &i4;
        d.items[5] = &i5;
        d.items[6] = &i6;
        func_L39_00689670(self, &d);
    }
    return self;
}
/* localdecomp:end func_L39_006ABC38 */

LINKER_REMNANT("asm/levels", func_L39_006AC170);
