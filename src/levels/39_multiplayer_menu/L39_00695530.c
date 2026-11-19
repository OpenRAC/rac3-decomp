#include "common.h"

/* declared by functions of L39_00695368.c, which this file was cut from */
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L39_00695530 */
typedef struct A_00695530 {
    s32 type;
    u8 name[0x34];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u8 f48;
    s32 f4C;
} A_00695530;
typedef struct B_00695530 {
    s32 type;
    u8 name[0x34];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad68[8];
} B_00695530;
typedef struct C_00695530 {
    s32 type;
    u8 name[0x34];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u8 f48;
    u8 pad49[0x450 - 0x49];
} C_00695530;
typedef struct D_00695530 {
    s32 type;
    u8 name[0x34];
    s32 f38;
    s32 f3C;
    f32 f40;
    f32 f44;
    s32 f48;
    s32 f4C;
    void *items[0x60];
} D_00695530;
extern u8 D_L39_00247FC0[];
extern u8 D_L39_0047CC68[];
extern s32 func_00381FF0(s32);
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

/* construct a label with its text and colour */
static __inline__ void label_init_00695530(void *l, s32 text, f32 r, f32 g, f32 b, f32 a)
{
    *(s32 *)l = 0;
    func_L39_0068CD28((u8 *)l, text, r, g, b, a);
}

void *func_L39_00695530(u8 *self) {
    A_00695530 e0;
    A_00695530 e1;
    B_00695530 e2;
    C_00695530 e3;
    D_00695530 e4;
    s32 t;
    u8 *tex;
    s32 n5 = 5;
    s32 n7 = 7;
    s32 m1 = -1;
    A_00695530 *p1;
    B_00695530 *p2;
    C_00695530 *p3;
    D_00695530 *p4;

    func_L39_00688388(self);
    tex = D_L39_00247FC0;
    *(u8 **)(self + 0x2A4) = self + 0x408;
    *(u8 **)(self + 0x60) = D_L39_0047CC68;
    label_init_00695530(&e0, (s32)tex, 0.688f, 0.418f, 0.42499998f, 0.53400004f);
    e0.type = 4;
    e0.f48 = 0;
    e0.f4C = n5;
    t = func_00381FF0(0xFC9);
    p1 = &e1;
    label_init_00695530(p1, t, 0.274f, 0.1777f, 0.32500002f, 0.05f);
    e1.type = 1;
    t = func_00381FF0(0x101D);
    p2 = &e2;
    label_init_00695530(p2, (s32)tex, 0.274f, 0.4447f, 0.32500002f, 0.48060006f);
    e2.type = n5;
    e2.f50 = t;
    e2.f48 = 0;
    e2.f4C = 0;
    p2->f54 = n7;
    e2.f58 = 0;
    e2.f5C = 0;
    p2->f60 = m1;
    e2.f64 = 0;
    p3 = &e3;
    label_init_00695530(p3, (s32)tex, 0.501f, 0.783f, 0.8f, 0.135f);
    e3.type = 9;
    e3.f48 = 0;
    p4 = &e4;
    label_init_00695530(p4, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p4->f48 = 0x2E;
    e4.f4C = 0;
    e4.f38 = 0;
    e4.f3C = 0;
    p4->f40 = 1.0f;
    p4->f44 = 1.0f;
    e4.f4C = 4;
    e4.items[1] = p1;
    e4.items[2] = p2;
    e4.items[3] = p3;
    e4.items[0] = &e0;
    func_L39_00689670(self, p4);
    return self;
}
/* localdecomp:end func_L39_00695530 */
