#include "common.h"

/* localdecomp:start func_L39_006CB4D8 */
typedef struct S8_006CB4D8 { s32 s[8]; } S8_006CB4D8;
typedef struct Names_006CB4D8 { s32 s[22]; } Names_006CB4D8;
typedef struct Item_006CB4D8 {
    s32 type;
    u8 pad4[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    s32 count;
    void *labels;
    s32 f50;
    u8 pad54[0x70 - 0x54];
} Item_006CB4D8;

typedef struct List_006CB4D8 {
    s32 type;
    u8 pad4[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    s32 f48;
    s32 count;
    void *items[2];
    u8 pad58[0x1D0 - 0x58];
} List_006CB4D8;

extern u8 D_L39_0047EFC0[];
extern void *func_L39_00688388(void *);
extern s32 func_00381FF0(s32);
extern s32 func_L39_0066C7D8(s32);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(u8 *, void *);

static __inline__ void item_006CB4D8(Item_006CB4D8 *item, s32 text, f32 x, f32 y, f32 w, f32 h, s32 count, void *labels)
{
    item->type = 0;
    func_L39_0068CD28((u8 *)item, text, x, y, w, h);
    item->type = 3;
    item->count = count;
    item->labels = labels;
    item->f50 = 0;
}

static __inline__ void list_006CB4D8(List_006CB4D8 *list)
{
    list->type = 0;
    func_L39_0068CD28((u8 *)list, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    list->f48 = 0x2E;
    list->count = 0;
    list->x = 0;
    list->y = 0;
    list->w = 1.0f;
    list->h = 1.0f;
}

void *func_L39_006CB4D8(s32 arg)
{
    u8 *obj = (u8 *)arg;

    func_L39_00688388(obj);
    *(void **)(obj + 0x60) = D_L39_0047EFC0;
    *(u8 **)(obj + 0x2A4) = obj + 0x2C4;
    {
        Names_006CB4D8 names = { {
            func_00381FF0(0xF22), func_00381FF0(0xF23), func_00381FF0(0xF24), func_00381FF0(0xF25),
            func_00381FF0(0xF26), func_00381FF0(0xF27), func_00381FF0(0xF28), func_00381FF0(0x1634),
            func_00381FF0(0x1635), func_00381FF0(0x1636), func_00381FF0(0x1637), func_00381FF0(0x1638),
            func_00381FF0(0x1639), func_00381FF0(0x163A), func_00381FF0(0x163B), func_00381FF0(0x163C),
            func_00381FF0(0x163D), func_00381FF0(0x163E), func_00381FF0(0x163F), func_00381FF0(0x1640),
            func_00381FF0(0x1641), func_00381FF0(0x1767) } };
        S8_006CB4D8 colors = { {
            func_L39_0066C7D8(0), func_L39_0066C7D8(1), func_L39_0066C7D8(2), func_L39_0066C7D8(3),
            func_L39_0066C7D8(4), func_L39_0066C7D8(5), func_L39_0066C7D8(6), func_L39_0066C7D8(7) } };
        Item_006CB4D8 item1;
        Item_006CB4D8 item2;
        List_006CB4D8 list;

        item_006CB4D8(&item1, func_00381FF0(0x1631), 0.3945f, 0.63449997f, 0.41500002f, 0.05f, 8, &colors);
        item_006CB4D8(&item2, func_00381FF0(0x1632), 0.3945f, 0.6995f, 0.41500002f, 0.05f, 0x16, &names);
        list_006CB4D8(&list);
        list.items[0] = &item1;
        list.items[1] = &item2;
        list.count = 2;
        func_L39_00689670(obj, &list);
    }
    *(s32 *)(obj + 0x2B4) = 2;
    *(f32 *)(obj + 0x2BC) = 0.5f;
    *(f32 *)(obj + 0x2C0) = 0.5f;
    *(s32 *)(obj + 0x2B0) = 0;
    return obj;
}
/* localdecomp:end func_L39_006CB4D8 */
