#include "common.h"

/* localdecomp:start func_L39_0069C138 */
typedef struct {
    char *a;
    char *b;
} Pair_0069C138;

typedef struct {
    s32 type;
    u8 text[0x34];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    s32 u48;
    void *u4C;
} Item_0069C138;

typedef struct {
    Item_0069C138 b;
    s32 u50;
    s32 u54;
    s32 u58;
    s32 u5C;
    s32 u60;
    u8 pad64[0xC];
} Big_0069C138;

typedef struct {
    Item_0069C138 b;
    s32 u50;
    u8 pad54[0x1C];
} Opt_0069C138;

typedef struct {
    s32 type;
    u8 text[0x34];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    s32 u48;
    s32 count;
    void *items[0x60];
} Menu_0069C138;

extern u8 D_L39_0047D110[];
extern void *func_L39_00688388(void *);
extern char *func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

static __inline__ void item_0069C138(Item_0069C138 *it, char *s, f32 x, f32 y, f32 w, f32 h)
{
    it->type = 0;
    func_L39_0068CD28((u8 *)it, (s32)s, x, y, w, h);
    it->type = 2;
}

static __inline__ void big_0069C138(Big_0069C138 *it, char *s, f32 x, f32 y, f32 w, f32 h, s32 a, s32 b, s32 c)
{
    item_0069C138(&it->b, s, x, y, w, h);
    it->b.type = 6;
    it->b.u48 = 0;
    it->b.u4C = 0;
    it->u50 = a;
    it->u54 = b;
    it->u58 = c;
    it->u60 = -1;
    it->u5C = -1;
}

static __inline__ void opt_0069C138(Opt_0069C138 *it, char *s, f32 x, f32 y, f32 w, f32 h, Pair_0069C138 *pairs)
{
    item_0069C138(&it->b, s, x, y, w, h);
    it->b.type = 3;
    it->b.u48 = 2;
    it->b.u4C = pairs;
    it->u50 = 0;
}

static __inline__ void menu_0069C138(Menu_0069C138 *m)
{
    m->type = 0;
    func_L39_0068CD28((u8 *)m, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    m->u48 = 0x2E;
    m->count = 0;
    m->f38 = 0.0f;
    m->f3C = 0.0f;
    m->f40 = 1.0f;
    m->f44 = 1.0f;
}

void *func_L39_0069C138(void *p)
{
    func_L39_00688388(p);
    *(u8 **)((u8 *)p + 0x2A4) = (u8 *)p + 0x2E0;
    *(u8 **)((u8 *)p + 0x60) = D_L39_0047D110;
    {
        Pair_0069C138 p0 = { func_00381FF0(0x1658), func_00381FF0(0x1659) };
        Pair_0069C138 p1 = { func_00381FF0(0x1658), func_00381FF0(0x18B6) };
        Item_0069C138 i0;
        Item_0069C138 i1;
        Item_0069C138 i2;
        Item_0069C138 i3;
        Item_0069C138 i4;
        Item_0069C138 i5;
        Item_0069C138 i6;
        Big_0069C138 i7;
        Item_0069C138 i8;
        Opt_0069C138 i9;
        Big_0069C138 i10;
        Opt_0069C138 i11;
        Menu_0069C138 menu;

        item_0069C138(&i0, func_00381FF0(0xF41), 0.3845f, 0.39388889f, 0.435f, 0.05f);
        item_0069C138(&i1, func_00381FF0(0x1628), 0.3845f, 0.44666669f, 0.435f, 0.05f);
        item_0069C138(&i2, func_00381FF0(0x1642), 0.3845f, 0.49944445f, 0.435f, 0.05f);
        item_0069C138(&i3, func_00381FF0(0x17F0), 0.3845f, 0.55222225f, 0.435f, 0.05f);
        item_0069C138(&i4, func_00381FF0(0x17F1), 0.3845f, 0.605f, 0.435f, 0.05f);
        item_0069C138(&i5, func_00381FF0(0x17F2), 0.3845f, 0.65777779f, 0.435f, 0.05f);
        item_0069C138(&i6, func_00381FF0(0x17F3), 0.3845f, 0.71055555f, 0.435f, 0.05f);
        big_0069C138(&i7, func_00381FF0(0xF52), 0.3845f, 0.76333332f, 0.435f, 0.05f, 0x23, 5, 0x1328);
        item_0069C138(&i8, func_00381FF0(0x162B), 0.3845f, 0.81611115f, 0.435f, 0.05f);
        opt_0069C138(&i9, func_00381FF0(0x1629), 0.3845f, 0.76333332f, 0.435f, 0.05f, &p0);
        big_0069C138(&i10, func_00381FF0(0x1656), 0.3845f, 0.81611115f, 0.435f, 0.05f, 0xF, 1, 0x1657);
        opt_0069C138(&i11, func_00381FF0(0x18B5), 0.3845f, 0.76333332f, 0.435f, 0.05f, &p1);
        menu_0069C138(&menu);
        menu.count = 12;
        menu.items[0] = &i0;
        menu.items[1] = &i1;
        menu.items[2] = &i2;
        menu.items[3] = &i3;
        menu.items[4] = &i4;
        menu.items[5] = &i5;
        menu.items[6] = &i6;
        menu.items[7] = &i7;
        menu.items[8] = &i8;
        menu.items[9] = &i9;
        menu.items[10] = &i10;
        menu.items[11] = &i11;
        func_L39_00689670(p, &menu);
    }
    return p;
}
/* localdecomp:end func_L39_0069C138 */

LINKER_REMNANT("asm/levels", func_L39_0069C708);
