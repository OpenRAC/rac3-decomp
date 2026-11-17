#include "common.h"

/* localdecomp:start func_L39_006C99F0 */
s32 func_L39_00688340(s32, s32, s32);
void func_L39_0068B2F8(void *, s32, s32);

typedef struct V_006C99F0 {
    u8 pad[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x78 - 0x24];
    s32 (*f78)(void *);
    u8 pad7C[0x80 - 0x7C];
    void (*f80)(void *, s32);
    u8 pad84[0x88 - 0x84];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} V_006C99F0;

typedef struct O_006C99F0 {
    u8 pad[0x60];
    V_006C99F0 *vt;
} O_006C99F0;

typedef struct S_006C99F0 {
    u8 pad[0x110];
    O_006C99F0 *items[0x60];
    u32 cur;
} S_006C99F0;

s32 func_L39_006C99F0(S_006C99F0 *arg0, s32 arg1)
{
    if (arg0->cur < 2) {
        if (arg1 == 1 && arg0->items[arg0->cur]->vt->f8C(arg0->items[arg0->cur]) <= 0) {
            func_L39_00688340(3, 0, 0);
            arg0->items[arg0->cur]->vt->f88(arg0->items[arg0->cur],
                arg0->items[arg0->cur]->vt->f78(arg0->items[arg0->cur]) - 1);
            return 1;
        }
        if (arg1 == 2 && arg0->items[arg0->cur]->vt->f8C(arg0->items[arg0->cur]) ==
                arg0->items[arg0->cur]->vt->f78(arg0->items[arg0->cur]) - 1) {
            func_L39_00688340(3, 0, 0);
            arg0->items[arg0->cur]->vt->f88(arg0->items[arg0->cur], 0);
            return 1;
        }
        if (arg1 == 5) {
            func_L39_00688340(0x17, 0, 0);
            arg0->items[arg0->cur]->vt->f80(arg0->items[arg0->cur], 0);
            arg0->items[arg0->cur]->vt->f20(arg0->items[arg0->cur], 2, 0);
            if (arg0->cur == 1) {
                func_L39_0068B2F8(arg0, 3, 0);
            } else if (arg0->cur == 0) {
                func_L39_0068B2F8(arg0, 2, 0);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006C99F0 */

/* localdecomp:start func_L39_006C9BF0 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");

typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_006C9BF0_inner;

typedef struct {
    char pad[0x38];
    S_006C9BF0_inner *f38;
} S_006C9BF0_outer;

typedef struct {
    char pad[0x284];
    s32 f284;
} S_006C9BF0_slot;

extern s32 *D_L39_0024D760;
extern u8 *D_L39_00247914;
extern S_006C9BF0_slot *D_001DC204_sda;

s32 func_L39_006C9BF0(void)
{
    S_006C9BF0_inner *inner = ((S_006C9BF0_outer *)D_L39_0024D760)->f38;

    if (inner->f0 == -1) {
        ((S_006C9BF0_slot *)D_L39_00247914)->f284 = 8;
        return 1;
    }
    if (inner->f34 == 0) {
        D_001DC204_sda->f284 = 6;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_006C9BF0 */

/* localdecomp:start func_L39_006C9C48 */
extern s32 *D_L39_0024D760;
__asm__(".extern D_L39_0024D760, 16");
extern u8 D_L39_00384A20[][0x50];
extern s32 func_00120884(void *);
void func_L39_005958F8(void *, void *, s32);
void func_L39_006D1658(void *);
void func_L39_0068B2F8(void *, s32, s32);

typedef struct E_006C9C48 {
    s32 x0;
    s32 n;
    u8 **items;
} E_006C9C48;

typedef struct V_006C9C48 {
    u8 pad[0x1C];
    void (*f1C)(void *, s32, s32);
    u8 pad20[0x6C - 0x20];
    void (*f6C)(void *, s32, u8 **);
    u8 pad70[0x88 - 0x70];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} V_006C9C48;

typedef struct O_006C9C48 {
    u8 pad[0x60];
    V_006C9C48 *vt;
} O_006C9C48;

typedef struct S_006C9C48 {
    u8 pad[0x110];
    O_006C9C48 *items[0x60];
    s32 cur;
    u8 pad294[0x2A8 - 0x294];
    u8 dirty;
    s32 last;
    s32 count;
    s32 ids[0x40];
} S_006C9C48;

void func_L39_006C9C48(S_006C9C48 *arg0)
{
    u8 *names[0x40];
    u8 *t;
    E_006C9C48 *e;
    s32 sel;
    s32 id;
    s32 i;
    s32 j;
    s32 n;
    u8 *p;

    t = (u8 *)D_L39_0024D760[0x38 / 4];
    e = 0;
    if (t[0x424] != 0 && *(s32 *)(t + 0x428) >= 0) {
        e = (E_006C9C48 *)(t + 0x43C + *(s32 *)(t + 0x428) * 12);
    }
    if (arg0->dirty && t[0x42C] == 0) {
        arg0->last = *(s32 *)(t + 0x434);
        func_L39_006D1658(t);
        arg0->dirty = 0;
    }
    if (e != 0 && *(s32 *)(t + 0x434) != arg0->last) {
        arg0->last = *(s32 *)(t + 0x434);
        n = 0x40;
        if (e->n <= 0x3F) {
            n = e->n;
        }
        arg0->count = n;
        id = -1;
        sel = arg0->items[0]->vt->f8C(arg0->items[0]);
        if (sel != -1) {
            id = arg0->ids[sel];
        }
        for (j = 0; j < arg0->count; j++) {
            p = e->items[j];
            names[j] = p + 0x20;
            arg0->ids[j] = *(s32 *)(p + 0x1C);
            if (id == *(s32 *)(p + 0x1C)) {
                sel = j;
            }
        }
        for (i = 0; i < arg0->count; i++) {
            func_L39_005958F8(D_L39_00384A20[i], names[i], func_00120884(names[i]));
            names[i] = D_L39_00384A20[i];
        }
        arg0->items[0]->vt->f6C(arg0->items[0], arg0->count, names);
        arg0->items[0]->vt->f88(arg0->items[0], sel);
    }
    if (arg0->cur == 0 && arg0->count <= 0) {
        func_L39_0068B2F8(arg0, 2, 0);
        arg0->items[0]->vt->f1C(arg0->items[0], 2, 0);
    }
}
/* localdecomp:end func_L39_006C9C48 */

/* localdecomp:start func_L39_006C9E50 */
typedef struct VT_006C9E50 {
    u8 pad0[0x1C];
    void (*f1C)(void *, s32, s32);
    u8 pad20[0x6C - 0x20];
    void (*f6C)(void *, s32, u8 **);
    u8 pad70[0x88 - 0x70];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} VT_006C9E50;

typedef struct Obj_006C9E50 {
    u8 pad0[0x60];
    VT_006C9E50 *vt;
} Obj_006C9E50;

typedef struct Item_006C9E50 {
    u8 pad0[0x1C];
    s32 id;
    u8 name[1];
} Item_006C9E50;

typedef struct Entry_006C9E50 {
    s32 pad0;
    s32 count;
    Item_006C9E50 **items;
} Entry_006C9E50;

typedef struct List_006C9E50 {
    u8 active;
    u8 pad1[3];
    s32 index;
    u8 busy;
    u8 pad9[7];
    s32 stamp;
    u8 pad14[0x28 - 0x14];
    Entry_006C9E50 entries[1];
} List_006C9E50;

typedef struct Self_006C9E50 {
    u8 pad0[0x114];
    Obj_006C9E50 *menu;
    u8 pad118[0x290 - 0x118];
    s32 state;
    u8 pad294[0x3B4 - 0x294];
    u8 dirty;
    u8 pad3B5[3];
    s32 stamp;
    s32 count;
    s32 ids[64];
} Self_006C9E50;

extern void func_L39_006CD768(List_006C9E50 *);
extern void func_L39_0068B2F8(void *, s32, s32);
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern u8 D_L39_00385E20[][0x50];

void func_L39_006C9E50(Self_006C9E50 *self)
{
    u8 *names[64];
    List_006C9E50 *list = ((List_006C9E50 **)D_L39_0024D760)[0x34 / 4];
    Entry_006C9E50 *entry = 0;
    s32 sel;
    s32 cur;
    s32 i;
    s32 r;
    s32 j;
    s32 n;
    s32 max;
    Obj_006C9E50 *menu;

    if (list->active && list->index >= 0) {
        entry = &list->entries[list->index];
    }
    if (self->dirty && !list->busy) {
        self->stamp = list->stamp;
        func_L39_006CD768(list);
        self->dirty = 0;
    }
    if (entry != 0 && list->stamp != self->stamp) {
        self->stamp = list->stamp;
        menu = self->menu;
        n = entry->count;
        max = 63;
        self->count = max < n ? 64 : n;
        sel = 0;
        cur = -1;
        r = menu->vt->f8C(menu);
        if (r != -1) {
            cur = self->ids[r];
        }
        for (i = 0; i < self->count; i++) {
            Item_006C9E50 *item = entry->items[i];
            names[i] = item->name;
            self->ids[i] = item->id;
            if (cur == item->id) {
                sel = i;
            }
        }
        for (j = 0; j < self->count; j++) {
            func_L39_005958F8(D_L39_00385E20[j], names[j], func_00120884(names[j]));
            names[j] = D_L39_00385E20[j];
        }
        self->menu->vt->f6C(self->menu, self->count, names);
        self->menu->vt->f88(self->menu, sel);
    }
    if (self->state == 1 && self->count <= 0) {
        func_L39_0068B2F8(self, 3, 0);
        self->menu->vt->f1C(self->menu, 2, 0);
    }
}
/* localdecomp:end func_L39_006C9E50 */
