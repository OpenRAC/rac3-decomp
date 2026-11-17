#include "common.h"

/* localdecomp:start func_L39_006A29D0 */
typedef struct S_006A29D0_Item { u8 pad[0x18]; s32 id; u8 data[1]; } S_006A29D0_Item;
typedef struct S_006A29D0_List { s32 pad0; s32 count; S_006A29D0_Item **items; } S_006A29D0_List;
typedef struct S_006A29D0_Obj { u8 pad[0xD]; u8 has_list; u8 pad2[6]; S_006A29D0_List list; } S_006A29D0_Obj;
typedef struct S_006A29D0_Root { u8 pad[0x78]; S_006A29D0_Obj *obj; } S_006A29D0_Root;
__asm__(".extern D_L39_0024D760, 16");
extern S_006A29D0_Root *D_L39_0024D760;
extern u8 D_L39_00248628[];
extern void *func_00381FF0(s32);

void *func_L39_006A29D0(s32 unused, s32 id) {
    S_006A29D0_List *list = D_L39_0024D760->obj->has_list ? &D_L39_0024D760->obj->list : 0;
    s32 i;
    s32 n;

    if (id == 0) {
        return func_00381FF0(0xFBF);
    }
    if (list) {
        n = list->count;
        for (i = 0; i < n; i++) {
            if (list->items[i]->id == id) {
                return list->items[i]->data;
            }
        }
    }
    return D_L39_00248628;
}
/* localdecomp:end func_L39_006A29D0 */

/* localdecomp:start func_L39_006A2A58 */
typedef struct S_006A2A58_Item {
    u8 pad0[0x1C];
    s32 id;
    u8 pad20[0x20];
    s32 a40;
    u8 pad44[0x8];
    u8 name[0x12];
    u8 b5E;
} S_006A2A58_Item;
typedef struct S_006A2A58_Group { s32 pad0; s32 count; S_006A2A58_Item **items; } S_006A2A58_Group;
typedef struct S_006A2A58_Obj {
    u8 pad0[0x18];
    s32 idx;
    u8 b1C;
    u8 pad1D[7];
    s32 a24;
    u8 pad28[4];
    S_006A2A58_Group groups[1];
} S_006A2A58_Obj;
typedef struct S_006A2A58_Root { u8 pad[0x70]; S_006A2A58_Obj *obj; } S_006A2A58_Root;
typedef struct S_006A2A58_VT {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x48];
    void (*f6C)(void *, s32, u8 **);
    u8 pad70[0x18];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} S_006A2A58_VT;
typedef struct S_006A2A58_W { u8 pad[0x60]; S_006A2A58_VT *vt; } S_006A2A58_W;
typedef struct S_006A2A58_Self {
    u8 pad0[0x130];
    S_006A2A58_W *list;
    u8 pad134[0x2AC - 0x134];
    s32 a2AC;
    s32 a2B0;
    s32 a2B4;
    u8 b2B8;
    u8 b2B9;
    u8 b2BA;
    u8 pad2BB;
    s32 a2BC;
    s32 count;
    s32 ids[0xE0];
    s32 a644[0xE0];
    s32 a9C4[0xE0];
    s32 aD44[0xE0];
    u8 pad10C4[0x1640 - 0x10C4];
    void *p1640;
} S_006A2A58_Self;
typedef struct S_006A2A58_Ctx { u8 data[0x1E0]; } S_006A2A58_Ctx;

__asm__(".extern D_L39_0024D760, 16");
extern u8 D_L39_00374590[][0x45];
extern u8 D_L39_00248638[];
extern u8 D_L39_003781F0[];
extern u8 D_001DCF1E_sda;
extern u8 D_001DCF1F_sda;
extern u8 D_001DCF20_sda;
extern s32 D_001DCF24_sda;
extern void func_L39_006CC8F0(void *, s32, s32, s32);
extern void func_L39_006CC918(void *, s32);
extern s32 func_L39_006CC930(void *);
extern s32 func_L39_006D5AB8(u8 *);
extern s32 func_L39_006CCA88(void *, S_006A2A58_Item *, s32);
extern void *func_L39_006CC120(void *);
extern void func_L39_006CC648(S_006A2A58_Ctx *, S_006A2A58_Item *);
extern s32 func_L39_006CC350(S_006A2A58_Ctx *, s32);
extern void func_L39_006CC158(S_006A2A58_Ctx *, s32);
extern void func_L39_005958F8(u8 *, u8 *, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_00120884(u8 *);

void func_L39_006A2A58(S_006A2A58_Self *self) {
    u8 *ptrs[0xE0];
    S_006A2A58_Ctx ctx;
    S_006A2A58_Group *grp = 0;
    S_006A2A58_Obj *obj = ((S_006A2A58_Root *)D_L39_0024D760)->obj;
    S_006A2A58_Item *item;
    s32 i;
    s32 n;
    s32 m;
    s32 j;
    s32 len;
    s32 c;
    s32 sel;
    s32 found;
    s32 k;
    u8 *s;

    if (obj->idx >= 0) {
        grp = &obj->groups[obj->idx];
    }
    if (self->b2B9 == 1) {
        if (!obj->b1C) {
            func_L39_006CC8F0(self->p1640, 0xD, 2, self->a2AC);
            if (self->a2B0 == 0) {
                func_L39_006CC918(self->p1640, 0xE);
            } else {
                func_L39_006CC8F0(self->p1640, 0xE, 2, self->a2B0);
            }
            func_L39_006CC930(self->p1640);
            func_L39_006D5AB8((u8 *)obj);
            self->a2BC = obj->a24;
            D_001DCF1E_sda = 1;
            D_001DCF1F_sda = 0;
            self->b2B9 = 0;
            D_001DCF20_sda = 1;
        }
    } else if (self->b2BA == 1) {
        if (!obj->b1C) {
            if (self->a2B0 == 0) {
                func_L39_006CC918(self->p1640, 0xD);
            } else {
                func_L39_006CC8F0(self->p1640, 0xD, 2, self->a2B0);
            }
            func_L39_006CC8F0(self->p1640, 0xE, 2, self->a2AC);
            func_L39_006CC930(self->p1640);
            func_L39_006D5AB8((u8 *)obj);
            self->a2BC = obj->a24;
            D_001DCF1F_sda = 1;
            D_001DCF1E_sda = 0;
            self->b2BA = 0;
            D_001DCF20_sda = 0;
        }
    } else if (self->b2B8 == 1 && !obj->b1C) {
        func_L39_006D5AB8((u8 *)obj);
        self->a2BC = obj->a24;
        D_001DCF1E_sda = 1;
        D_001DCF1F_sda = 1;
        self->b2B8 = 0;
        D_001DCF20_sda = 0;
    }

    if (grp == 0 || obj->a24 == self->a2BC) {
        return;
    }
    if (D_001DCF20_sda == 1) {
        D_001DCF20_sda = 0;
        self->b2BA = 1;
    }
    if (D_001DCF1E_sda == 1) {
        D_001DCF24_sda = 0;
    }
    self->a2BC = obj->a24;
    n = 0xE0 - D_001DCF24_sda;
    c = grp->count;
    self->count = c;
    if (n < c) {
        self->count = n;
    }
    for (j = 0xDF; j >= 0; j--) {
        ptrs[j] = D_L39_00374590[j];
    }
    sel = -1;
    k = self->list->vt->f8C(self->list);
    if (k != -1) {
        sel = self->ids[k];
    }
    found = 0;
    for (i = 0; i < self->count; i++) {
        item = grp->items[i];
        if (func_L39_006CCA88(self->p1640, item, self->a2B4)) {
            func_L39_006CC120(&ctx);
            func_L39_006CC648(&ctx, item);
            self->ids[D_001DCF24_sda] = item->id;
            self->aD44[D_001DCF24_sda] = item->a40;
            self->a9C4[D_001DCF24_sda] = func_L39_006CC350(&ctx, 2);
            item->b5E = 0;
            func_00120048(D_L39_00374590[D_001DCF24_sda], D_L39_00248638, item->name);
            D_L39_00374590[D_001DCF24_sda][0x44] = 0;
            s = D_L39_00374590[D_001DCF24_sda];
            len = func_00120884(s) - 1;
            while (len > 0 && s[len] == ' ') {
                len--;
            }
            s[len + 1] = 0;
            if (sel == item->id) {
                found = D_001DCF24_sda;
            }
            D_001DCF24_sda++;
            func_L39_006CC158(&ctx, 2);
        }
    }
    if (D_001DCF1F_sda == 1) {
        self->count = D_001DCF24_sda;
        for (j = D_001DCF24_sda; j < 0xE0; j++) {
            self->ids[j] = -1;
            self->aD44[j] = 0;
            self->a9C4[j] = -1;
        }
        for (m = 0; m < self->count; m++) {
            func_L39_005958F8(D_L39_003781F0 + m * 0x50, ptrs[m], func_00120884(ptrs[m]));
            ptrs[m] = D_L39_003781F0 + m * 0x50;
        }
        self->list->vt->f6C(self->list, self->count, ptrs);
        self->list->vt->f88(self->list, found);
        if (self->count > 0) {
            self->list->vt->f20(self->list, 3, 0);
        } else {
            self->list->vt->f20(self->list, 2, 0);
        }
    }
}
/* localdecomp:end func_L39_006A2A58 */

LINKER_REMNANT("asm/levels", func_L39_006A2F38);

INCLUDE_ASM("asm/levels", func_L39_006A2F50);

LINKER_REMNANT("asm/levels", func_L39_006A3660);

/* localdecomp:start func_L39_006A3668 */
extern u8 D_L39_0047D858[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006A3668(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D858;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006A3668 */
