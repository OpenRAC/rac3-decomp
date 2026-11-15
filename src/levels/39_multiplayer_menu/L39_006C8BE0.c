#include "common.h"

/* declared by functions of L39_006C87E8.c, which this file was cut from */
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L39_006C8BE0 */
typedef struct Base_006C8BE0 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} Base_006C8BE0;
typedef struct Item50_006C8BE0 {
    Base_006C8BE0 b;
    s32 f48;
    s32 f4C;
} Item50_006C8BE0;
typedef struct Item70_006C8BE0 {
    Item50_006C8BE0 i;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad68[8];
} Item70_006C8BE0;
typedef struct List_006C8BE0 {
    Item50_006C8BE0 i;
    Item50_006C8BE0 *items[96];
} List_006C8BE0;
extern u8 D_L39_0047ECB8[];
extern u8 D_L39_002498D0[];
extern void *func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

/* the item constructor: clears the type word, then the base constructor */
static __inline__ void ctor_006C8BE0(Base_006C8BE0 *it, s32 name, f32 x, f32 y, f32 w, f32 h)
{
    it->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
}

void *func_L39_006C8BE0(u8 *self)
{
    Item70_006C8BE0 b0;
    Item70_006C8BE0 b1;
    Item50_006C8BE0 l2;
    Item50_006C8BE0 l3;
    Item50_006C8BE0 l4;
    Item50_006C8BE0 l5;
    List_006C8BE0 list;
    s32 kind = 0x23;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 name0;
    s32 label0;
    s32 name1;
    s32 label1;
    Item70_006C8BE0 *p1;
    Item50_006C8BE0 *p2;
    Item50_006C8BE0 *p3;
    Item50_006C8BE0 *p4;
    Item50_006C8BE0 *p5;
    List_006C8BE0 *pl;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047ECB8;
    *(u8 **)(self + 0x2A4) = self + 0x4C0;

    name0 = func_00381FF0(0xFC9);
    label0 = func_00381FF0(0x101D);
    ctor_006C8BE0((Base_006C8BE0 *)&b0, name0, 0.291f, 0.323f, 0.36200002f, 0.245f);
    b0.i.b.type = 5;
    b0.f50 = label0;
    b0.f54 = 5;
    b0.f60 = -1;
    b0.i.f48 = 0;
    b0.i.f4C = 0;
    b0.f58 = 0;
    b0.f5C = 0;
    b0.f64 = 0;

    name1 = func_00381FF0(0x132C);
    label1 = func_00381FF0(0x101A);
    p1 = &b1;
    ctor_006C8BE0((Base_006C8BE0 *)p1, name1, 0.291f, 0.649f, 0.36200002f, 0.245f);
    b1.f50 = label1;
    b1.i.b.type = 5;
    b1.i.f48 = 0;
    b1.i.f4C = 0;
    p1->f54 = 5;
    b1.f58 = 0;
    b1.f5C = 0;
    p1->f60 = -1;
    b1.f64 = 0;

    t2 = func_00381FF0(0x132D);
    p2 = &l2;
    ctor_006C8BE0((Base_006C8BE0 *)p2, t2, 0.291f, 0.1645f, 0.382f, 0.05f);
    l2.b.type = 1;
    t3 = func_00381FF0(0x132C);
    p3 = &l3;
    ctor_006C8BE0((Base_006C8BE0 *)p3, t3, 0.291f, 0.49050003f, 0.382f, 0.05f);
    l3.b.type = 1;
    t4 = func_00381FF0(0xFD1);
    p4 = &l4;
    ctor_006C8BE0((Base_006C8BE0 *)p4, t4, 0.291f, 0.825f, 0.382f, 0.05f);
    l4.b.type = 1;
    p5 = &l5;
    ctor_006C8BE0((Base_006C8BE0 *)p5, (s32)D_L39_002498D0, 0.706f, 0.5f, 0.39f, 0.70000005f);
    l5.b.type = 4;
    p5->f4C = kind;
    *(u8 *)&l5.f48 = 0;

    pl = &list;
    ctor_006C8BE0((Base_006C8BE0 *)pl, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pl->i.f48 = 0x2E;
    list.i.f4C = 0;
    list.i.b.x = 0.0f;
    list.i.b.y = 0.0f;
    pl->i.b.w = 1.0f;
    pl->i.b.h = 1.0f;
    list.i.f4C = 6;
    list.items[0] = (Item50_006C8BE0 *)&b0;
    list.items[1] = (Item50_006C8BE0 *)p1;
    list.items[2] = p2;
    list.items[3] = p3;
    list.items[4] = p4;
    list.items[5] = p5;
    func_L39_00689670(self, &list);
    return self;
}
/* localdecomp:end func_L39_006C8BE0 */

LINKER_REMNANT("asm/levels", func_L39_006C8F28);
