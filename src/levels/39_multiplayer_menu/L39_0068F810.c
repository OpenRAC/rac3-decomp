#include "common.h"

/* localdecomp:start func_L39_0068F810 */
typedef struct VT_0068F810 {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x6C - 0x24];
    void (*f6C)(void *, s32, u8 **);
    u8 pad70[0x88 - 0x70];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} VT_0068F810;

typedef struct Obj_0068F810 {
    u8 pad0[0x60];
    VT_0068F810 *vt;
} Obj_0068F810;

typedef struct Item_0068F810 {
    u8 pad0[0x1C];
    s32 id;
    u8 name[1];
} Item_0068F810;

typedef struct Entry_0068F810 {
    s32 pad0;
    s32 count;
    Item_0068F810 **items;
} Entry_0068F810;

typedef struct List_0068F810 {
    u8 active;
    u8 pad1[3];
    s32 index;
    u8 busy;
    u8 pad9[7];
    s32 stamp;
    u8 pad14[0x28 - 0x14];
    Entry_0068F810 entries[1];
} List_0068F810;

typedef struct Self_0068F810 {
    u8 pad0[0x110];
    Obj_0068F810 *menu;
    u8 pad114[0x2A8 - 0x114];
    u8 dirty;
    u8 pad2A9[3];
    s32 stamp;
    s32 count;
    s32 ids[64];
} Self_0068F810;

__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern s32 func_L39_006D5D68(void *);
extern void func_L39_005958F8(u8 *, u8 *, s32);
extern s32 func_00120884(u8 *);
extern u8 D_L39_004AE3A0[][0x40];

void func_L39_0068F810(Self_0068F810 *self)
{
    u8 *names[64];
    List_0068F810 *list = ((List_0068F810 **)D_L39_0024D760)[0x40 / 4];
    Entry_0068F810 *entry = 0;
    s32 sel;
    s32 cur;
    s32 i;
    s32 r;
    Item_0068F810 *item;
    u8 *name;

    if (list->active && list->index >= 0) {
        entry = &list->entries[list->index];
    }
    if (self->dirty == 1 && !list->busy) {
        func_L39_006D5D68(list);
        self->stamp = list->stamp;
        self->dirty = 0;
    }
    if (entry != 0 && list->stamp != self->stamp) {
        self->stamp = list->stamp;
        self->count = entry->count;
        if (self->count > 64) {
            self->count = 64;
        }
        cur = -1;
        sel = 0;
        r = self->menu->vt->f8C(self->menu);
        if (r != -1) {
            cur = self->ids[r];
        }
        for (i = 0; i < self->count; i++) {
            item = entry->items[i];
            name = item->name;
            func_L39_005958F8(D_L39_004AE3A0[i], name, func_00120884(name));
            names[i] = D_L39_004AE3A0[i];
            self->ids[i] = item->id;
            if (cur == item->id) {
                sel = i;
            }
        }
        self->menu->vt->f6C(self->menu, self->count, names);
        self->menu->vt->f88(self->menu, sel);
        if (self->count > 0) {
            self->menu->vt->f20(self->menu, 3, 0);
        } else {
            self->menu->vt->f20(self->menu, 2, 0);
        }
    }
}
/* localdecomp:end func_L39_0068F810 */

/* localdecomp:start func_L39_0068FA28 */
void func_L39_0068FA28(char *arg0) {
    char **p = (char **)(arg0 + 0x124);
    s32 i;

    *(s32 *)(arg0 + 0x3B8) = -1;
    i = 5;
    do {
        char *v;
        i--;
        v = *p;
        (*(void (**)(char *))((*(char **)(v + 0x60)) + 0xB4))(v);
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L39_0068FA28 */
