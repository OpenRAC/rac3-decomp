#include "common.h"

/* localdecomp:start func_L39_006B63B8 */
typedef struct {
    s32 kind;
    char text[0x34];
    f32 r, g, b, a;
    u8 unk48;
    u8 pad49[3];
    s32 unk4C;
} T_006B63B8;
typedef struct {
    T_006B63B8 t;
    u8 pad50[0x450 - 0x50];
} B_006B63B8;
typedef struct {
    s32 kind;
    char text[0x34];
    f32 r, g, b, a;
    s32 unk48;
    s32 unk4C;
    void *items[6];
    u8 pad68[0x1D0 - 0x68];
} Z_006B63B8;
extern char D_L39_002490D8[];
extern int D_L39_0047E540[];
extern void *func_00381FF0(s32);
extern void *func_L39_00688388(void *);
void func_L39_0068CD28(u8 *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_L39_00689670(void *, void *);

static __inline__ void lab_006B63B8(T_006B63B8 *t, void *text, f32 r, f32 g, f32 b, f32 a) {
    t->kind = 0;
    func_L39_0068CD28((u8 *)t, text, r, g, b, a);
}

static __inline__ void A_init_006B63B8(T_006B63B8 *t, void *text, f32 r, f32 g, f32 b, f32 a) {
    lab_006B63B8(t, text, r, g, b, a);
    t->kind = 1;
}

static __inline__ void B_init_006B63B8(B_006B63B8 *t) {
    lab_006B63B8(&t->t, D_L39_002490D8, 0.5f, 0.52f, 0.42f, 0.3f);
    t->t.kind = 9;
    t->t.unk48 = 0;
}

static __inline__ void Z_init_006B63B8(Z_006B63B8 *t) {
    lab_006B63B8((T_006B63B8 *)t, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->unk48 = 0x2E;
    t->unk4C = 0;
    t->r = 0;
    t->g = 0;
    t->b = 1.0f;
    t->a = 1.0f;
}

void *func_L39_006B63B8(s32 arg) {
    u8 *self = (u8 *)arg;
    T_006B63B8 a;
    B_006B63B8 b;
    T_006B63B8 c;
    T_006B63B8 d;
    T_006B63B8 e;
    T_006B63B8 f;
    Z_006B63B8 z;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x320;
    *(int **)(self + 0x60) = D_L39_0047E540;

    A_init_006B63B8(&a, func_00381FF0(0xFE0), 0.5f, 0.33f, 1.0f, 1.0f);
    B_init_006B63B8(&b);
    A_init_006B63B8(&c, func_00381FF0(0xFE3), 0.4f, 0.68f, 1.0f, 1.0f);
    A_init_006B63B8(&d, func_00381FF0(0x1030), 0.6f, 0.68f, 1.0f, 1.0f);
    A_init_006B63B8(&e, func_00381FF0(0xFFD), 0.4f, 0.68f, 1.0f, 1.0f);
    A_init_006B63B8(&f, func_00381FF0(0x1185), 0.6f, 0.68f, 1.0f, 1.0f);
    Z_init_006B63B8(&z);
    z.items[0] = &a;
    z.items[1] = &b;
    z.items[2] = &c;
    z.items[3] = &d;
    z.items[4] = &e;
    z.items[5] = &f;
    z.unk4C = 6;
    func_L39_00689670(self, &z);
    return self;
}
/* localdecomp:end func_L39_006B63B8 */

LINKER_REMNANT("asm/levels", func_L39_006B6648);
