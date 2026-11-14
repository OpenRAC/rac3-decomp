#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C8050 */
typedef struct {
    s32 kind;
    char text[0x34];
    f32 r, g, b, a;
    s32 unk48;
    s32 unk4C;
} T_006C8050;
typedef struct {
    T_006C8050 t;
    s32 text;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 pad[2];
} B_006C8050;
typedef struct {
    T_006C8050 t;
    T_006C8050 *a;
    B_006C8050 *b;
    T_006C8050 *c;
    u8 pad5C[0x1D0 - 0x5C];
} D_006C8050;
extern char D_L39_00249860[];
extern u8 D_L39_0047EBA0[];
extern s32 func_00381FF0(s32);
void func_L39_00688388(void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_L39_00689670(void *, D_006C8050 *);

static __inline__ void lab_006C8050(T_006C8050 *t, s32 text, f32 r, f32 g, f32 b, f32 a) {
    t->kind = 0;
    func_L39_0068CD28((u8 *)t, text, r, g, b, a);
}

static __inline__ void A_init_006C8050(T_006C8050 *t, s32 text, f32 r, f32 g, f32 b, f32 a) {
    lab_006C8050(t, text, r, g, b, a);
    t->kind = 1;
}

static __inline__ void B_init_006C8050(B_006C8050 *t, s32 text, s32 n) {
    lab_006C8050(&t->t, (s32)D_L39_00249860, 0.5f, 0.55f, 0.4f, 0.4f);
    t->text = text;
    t->t.kind = 5;
    t->t.unk48 = 0;
    t->t.unk4C = 0;
    t->unk54 = n;
    t->unk58 = 0;
    t->unk5C = 0;
    t->unk60 = -1;
    t->unk64 = 0;
}

static __inline__ void D_init_006C8050(D_006C8050 *t) {
    lab_006C8050(&t->t, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->t.unk48 = 0x2E;
    t->t.unk4C = 0;
    t->t.r = 0;
    t->t.g = 0;
    t->t.b = 1.0f;
    t->t.a = 1.0f;
}

void *func_L39_006C8050(u8 *self) {
    T_006C8050 a;
    B_006C8050 b;
    T_006C8050 c;
    D_006C8050 d;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x3AC;
    *(u8 **)(self + 0x60) = D_L39_0047EBA0;

    A_init_006C8050(&a, func_00381FF0(0xFB6), 0.5f, 0.32f, 1.0f, 1.0f);
    B_init_006C8050(&b, func_00381FF0(0x1019), 7);
    A_init_006C8050(&c, func_00381FF0(0x124), 0.624f, 0.772f, 1.0f, 1.0f);
    D_init_006C8050(&d);
    d.b = &b;
    d.c = &c;
    d.t.unk4C = 3;
    d.a = &a;
    func_L39_00689670(self, &d);

    *(s32 *)(self + 0x380) = -1;
    *(s32 *)(self + 0x384) = -1;
    *(s32 *)(self + 0x388) = -1;
    *(s32 *)(self + 0x38C) = -1;
    *(s32 *)(self + 0x398) = -1;
    *(s32 *)(self + 0x390) = -1;
    *(s32 *)(self + 0x39C) = -1;
    *(s32 *)(self + 0x3A0) = -1;
    *(s32 *)(self + 0x3A4) = -1;
    *(s32 *)(self + 0x3A8) = 0;
    return self;
}
/* localdecomp:end func_L39_006C8050 */

LINKER_REMNANT("asm/levels", func_L39_006C8248);
