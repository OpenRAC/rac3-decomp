#include "common.h"

/* localdecomp:start func_L39_006915C8 */
extern s32 func_00120884(u8 *);
extern void func_L39_005958F8(u8 *, u8 *, s32);
extern s32 func_L39_006CD768(u8 *);
extern u8 D_L39_004AF3A0[][64];

typedef struct {
    s32 data[0x8C / 4];
} Rec_006915C8;

typedef struct {
    u8 pad0[0x1C];
    s32 id;
    u8 name[0x20];
    Rec_006915C8 rec;
} E_006915C8;

typedef struct {
    u8 pad0[4];
    s32 count;
    E_006915C8 **entries;
} L_006915C8;

typedef struct {
    u8 active;
    u8 pad1[3];
    s32 cur;
    u8 busy;
    u8 pad9[7];
    s32 serial;
    u8 pad14[0x28 - 0x14];
    L_006915C8 lists[1];
} M_006915C8;

typedef struct {
    u8 pad[0x34];
    M_006915C8 *mgr;
} G_006915C8;
__asm__(".extern D_L39_0024D760, 16");
extern G_006915C8 *D_L39_0024D760;

typedef struct W_006915C8 W_006915C8;
typedef struct {
    u8 pad0[0x20];
    void (*show)(W_006915C8 *, s32, void *);
    u8 pad24[0x6C - 0x24];
    void (*set)(W_006915C8 *, s32, void *);
    u8 pad70[0x88 - 0x70];
    void (*select)(W_006915C8 *, s32);
    s32 (*selected)(W_006915C8 *);
} VT_006915C8;
struct W_006915C8 {
    u8 pad[0x60];
    VT_006915C8 *vt;
};

typedef struct {
    u8 pad0[0x110];
    W_006915C8 *list;
    u8 pad114[0x2A8 - 0x114];
    u8 pending;
    u8 pad2A9[3];
    s32 serial;
    s32 count;
    s32 ids[64];
    Rec_006915C8 recs[64];
} S_006915C8;

void func_L39_006915C8(S_006915C8 *self) {
    u8 *names[64];
    M_006915C8 *mgr;
    L_006915C8 *list;
    E_006915C8 *e;
    s32 sel;
    s32 idx;
    s32 found;
    s32 i;

    list = 0;
    mgr = D_L39_0024D760->mgr;
    if (mgr->active && mgr->cur >= 0) {
        list = &mgr->lists[mgr->cur];
    }
    if (self->pending == 1 && !mgr->busy) {
        func_L39_006CD768((u8 *)mgr);
        self->serial = mgr->serial;
        self->pending = 0;
    }
    if (list == 0 || mgr->serial == self->serial) {
        return;
    }
    self->serial = mgr->serial;
    self->count = list->count;
    if (self->count > 64) {
        self->count = 64;
    }
    sel = -1;
    idx = self->list->vt->selected(self->list);
    if (idx != -1) {
        sel = self->ids[idx];
    }
    found = 0;
    for (i = 0; i < self->count; i++) {
        e = list->entries[i];
        func_L39_005958F8(D_L39_004AF3A0[i], e->name, func_00120884(e->name));
        names[i] = D_L39_004AF3A0[i];
        self->ids[i] = e->id;
        self->recs[i] = e->rec;
        if (sel == e->id) {
            found = i;
        }
    }
    self->list->vt->set(self->list, self->count, names);
    self->list->vt->select(self->list, found);
    if (self->count > 0) {
        self->list->vt->show(self->list, 3, 0);
    } else {
        self->list->vt->show(self->list, 2, 0);
    }
}
/* localdecomp:end func_L39_006915C8 */

/* localdecomp:start func_L39_006918A8 */
void func_L39_006918A8(u8 *self) {
    u8 **p = (u8 **)(self + 0x124);
    s32 i = 5;
    u8 *obj;
    void (*fn)(u8 *);

    *(s32 *)(self + 0x27C4) = -1;
    do {
        obj = *p;
        i--;
        fn = *(void (**)(u8 *))(*(u8 **)(obj + 0x60) + 0xB4);
        fn(obj);
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L39_006918A8 */
