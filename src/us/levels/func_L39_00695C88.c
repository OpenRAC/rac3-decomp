#include "common.h"

/* NTSC-U counterpart of func_L39_006983B8 (src/levels/39_multiplayer_menu/L39_00697E10.c) */
typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_00697B28_inner;
typedef struct {
    char pad[0x38];
    S_00697B28_inner *f38;
} S_00697B28_outer;
extern S_00697B28_outer *D_L39_0024D860;
typedef struct Widget_00697E10 Widget_00697E10;
typedef struct {
     u8 pad0[0x1C];
     void (*unk1C)(Widget_00697E10 *, s32, s32);
     u8 pad20[0x94];
     void (*unkB4)(Widget_00697E10 *);
     void (*unkB8)(Widget_00697E10 *, char *);
     u8 padBC[0x28];
     void (*unkE4)(Widget_00697E10 *, f32);
} WidgetVtbl_00697E10;
struct Widget_00697E10 {
     u8 pad0[0x60];
     WidgetVtbl_00697E10 *vtbl;
};
typedef struct {
     s32 unk0;
     u8 unk4[0x2C];
     char unk30[4];
} Net_00697E10;
typedef struct {
     u8 pad0[0x124];
     Widget_00697E10 *unk124;
     Widget_00697E10 *unk128;
     Widget_00697E10 *unk12C;
     Widget_00697E10 *unk130;
     u8 pad134[0xC];
     Widget_00697E10 *unk140;
     Widget_00697E10 *unk144;
     Widget_00697E10 *unk148;
     u8 pad14C[0x26C];
     s32 unk3B8;
} S_00697E10;
extern char *func_L39_006D0A30(Net_00697E10 *, s32, s32);
extern s32 func_L39_006D0768(Net_00697E10 *, s32, s32);
extern char *func_0037DF98(s32);
extern s32 func_00120048(char *, char *, ...);
typedef struct {
    char pad[0x30];
    s32 *f30;
    char pad34[4];
    u8 *f38;
    void *f3C;
    char pad40[4];
    void *f44;
    void *f48;
} M_006980F8;
typedef struct {
    char pad[0x40];
    s32 f40;
    s32 f44;
} A_006980F8;
extern M_006980F8 *D_001E1FD0_sda;
extern A_006980F8 *func_L39_006D67D0(void *, s32);

/* localdecomp:start func_L39_00695C88 */
typedef struct {
    s32 id;
    s32 pad4[9];
} Slot_006983B8;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    s32 unk20;
} Item_006983B8;

typedef struct {
    s32 unk0;
    s32 unk4;
    Item_006983B8 **unk8;
} List_006983B8;

typedef struct {
    u8 pad0[0x20];
    char unk20[0x20];
    s32 unk40;
} Name_006983B8;

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
} Q_006983B8;

typedef struct {
    u8 pad0[0x40];
    s32 unk40;
    u8 pad44[4];
    Q_006983B8 unk48;
} Player_006983B8;

typedef struct {
    u8 unk0;
    u8 pad1[3];
    s32 unk4;
    u8 pad8[0x20];
    List_006983B8 unk28[1];
} Src1_006983B8;

typedef struct {
    u8 pad0[0x170];
    s32 unk170;
    u8 pad174[4];
    List_006983B8 unk178[1];
} Src2_006983B8;

typedef struct {
    u8 pad0[0x34];
    Src1_006983B8 *unk34;
    Net_00697E10 *unk38;
    u8 pad3C[0xC];
    void *unk48;
    Src2_006983B8 *unk4C;
} Root_006983B8;

typedef struct {
    u8 pad0[0xE0];
    void *unkE0;
    u8 padE4[0x1A0];
    s32 unk284;
} Menu_006983B8;

__asm__(".extern D_L39_00247A74_00695C88, 16");
extern Menu_006983B8 *D_L39_00247A74_00695C88;
extern Slot_006983B8 D_L39_001FD7B0[];
extern char D_L39_003743C0[][0x20];
extern char *D_L39_00374640[];
extern char D_L39_00248180[];
extern char D_L39_002481B0[];
__asm__(".extern D_001DC8F0_sda, 4");
extern char D_001DC8F0_sda[];

extern void func_001206F4(void *, void *);
extern s32 func_00120884(char *);
extern void func_L39_00594648(char *, char *, s32);
extern s32 func_L39_00684CE0(Menu_006983B8 *, char *, char **, s32, s32);
extern s32 func_L39_00684930(Menu_006983B8 *, char *, u8 *, s32, s32, s32, s32);
extern Item_006983B8 *func_L39_006D0818(Net_00697E10 *, u8 *);
extern s32 func_L39_006847C8(Menu_006983B8 *, char *, char *, s32, s32, f32);
extern s32 func_L39_006D7310(void *, s32, char *, s32);
extern s32 func_L39_006D96D0(void *, s32, s32, s32 *);
extern void func_L39_006BA8F0(void *, s32);

static __inline__ u8 valid_006983B8(void *db, s32 id) {
    A_006980F8 *p = func_L39_006D67D0(db, id);
    u8 ok;
    return ok = p != 0 && p->f40 != 0;
}

void func_L39_00695C88(S_00697E10 *this) {
    s32 ids[20];
    s32 vals[20];
    char names[20][0x20];
    char *ptrs[0x20];
    u8 buf[0x20];
    char text[0x80];
    char formatted[0x50];
    s32 sel;
    s32 idx;
    List_006983B8 *list;
    List_006983B8 *list2;
    void *db = ((Root_006983B8 *)D_L39_0024D860)->unk48;
    Net_00697E10 *net = ((Root_006983B8 *)D_L39_0024D860)->unk38;
    s32 count = 1;
    s32 i;
    s32 id;
    s32 val;
    s32 k;
    Item_006983B8 *found;

    list = 0;
    ptrs[0] = func_0037DF98(0x1704);
    ids[0] = -1;
    if (((Root_006983B8 *)D_L39_0024D860)->unk34->unk0 != 0 && ((Root_006983B8 *)D_L39_0024D860)->unk34->unk4 >= 0) {
        list = &((Root_006983B8 *)D_L39_0024D860)->unk34->unk28[((Root_006983B8 *)D_L39_0024D860)->unk34->unk4];
    }
    if (list != 0) {
        for (i = 0; i < list->unk4 && count < 20; i++) {
            Item_006983B8 *item = list->unk8[i];
            Player_006983B8 *pl;
            Q_006983B8 *q;
            Name_006983B8 *name;
            if (item != 0 && item->unk1C >= 0) {
                pl = (Player_006983B8 *)func_L39_006D67D0(db, item->unk1C);
                if (pl != 0 && pl->unk40 != 0) {
                    q = &pl->unk48;
                    if (q->unk24 != net->unk0 && q->unk24 >= 0) {
                        s32 k;
                        s32 dup = 0;
                        for (k = 0; k < count; k++) {
                            dup |= ids[k] == q->unk24;
                        }
                        if (!dup) {
                            name = (Name_006983B8 *)func_L39_006D0A30(net, item->unk1C, q->unk24);
                            if (name != 0) {
                                if (name->unk40 == item->unk1C || valid_006983B8(db, name->unk40)) {
                                    ptrs[count] = names[count];
                                    ids[count] = q->unk24;
                                    vals[count] = name->unk40;
                                    func_001206F4(ptrs[count], name->unk20);
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 11 && count < 20; i++) {
        if (D_L39_001FD7B0[i].id >= 0) {
            Player_006983B8 *pl;
            Q_006983B8 *q;
            Name_006983B8 *name;
            pl = (Player_006983B8 *)func_L39_006D67D0(db, D_L39_001FD7B0[i].id);
            if (pl != 0 && pl->unk40 != 0) {
                q = &pl->unk48;
                if (q->unk24 != net->unk0 && q->unk24 >= 0) {
                    s32 k;
                    s32 dup = 0;
                    for (k = 0; k < count; k++) {
                        dup |= ids[k] == q->unk24;
                    }
                    if (!dup) {
                        name = (Name_006983B8 *)func_L39_006D0A30(net, D_L39_001FD7B0[i].id, q->unk24);
                        if (name != 0) {
                            if (name->unk40 == D_L39_001FD7B0[i].id || valid_006983B8(db, name->unk40)) {
                                ptrs[count] = names[count];
                                ids[count] = q->unk24;
                                vals[count] = name->unk40;
                                func_001206F4(ptrs[count], name->unk20);
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    list2 = 0;
    if (((Root_006983B8 *)D_L39_0024D860)->unk4C->unk170 >= 0) {
        list2 = &((Root_006983B8 *)D_L39_0024D860)->unk4C->unk178[((Root_006983B8 *)D_L39_0024D860)->unk4C->unk170];
    }
    if (list2 != 0) {
        for (i = 0; i < list2->unk4 && count < 20; i++) {
            Item_006983B8 *item = list2->unk8[i];
            Player_006983B8 *pl;
            Q_006983B8 *q;
            Name_006983B8 *name;
            if (item != 0 && item->unk1C >= 0) {
                pl = (Player_006983B8 *)func_L39_006D67D0(db, item->unk1C);
                if (pl != 0 && pl->unk40 != 0) {
                    q = &pl->unk48;
                    if (q->unk24 != net->unk0 && q->unk24 >= 0) {
                        s32 k;
                        s32 dup = 0;
                        for (k = 0; k < count; k++) {
                            dup |= ids[k] == q->unk24;
                        }
                        if (!dup) {
                            name = (Name_006983B8 *)func_L39_006D0A30(net, item->unk1C, q->unk24);
                            if (name != 0) {
                                if (name->unk40 == item->unk1C || valid_006983B8(db, name->unk40)) {
                                    ptrs[count] = names[count];
                                    ids[count] = q->unk24;
                                    vals[count] = name->unk40;
                                    func_001206F4(ptrs[count], name->unk20);
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    id = -1;
    val = -1;
    if (count >= 2) {
        for (k = 0; k < count; k++) {
            func_L39_00594648(D_L39_003743C0[k], *(ptrs + k), func_00120884(*(ptrs + k)));
            D_L39_00374640[k] = D_L39_003743C0[k];
        }
        {
            Menu_006983B8 *m = D_L39_00247A74_00695C88;
            idx = func_L39_00684CE0(m, func_0037DF98(0x1705), D_L39_00374640, count, 0);
        }
        if (idx >= 0) {
            id = ids[idx];
            val = vals[idx];
            func_001206F4(buf, ptrs[idx]);
        } else {
            return;
        }
    }
    if (id < 0) {
        buf[0] = 0;
        func_L39_00684930(D_L39_00247A74_00695C88, D_001DC8F0_sda, buf, 0, 0x20, 0, 0);
        if (buf[0] == 0) {
            return;
        }
        found = func_L39_006D0818(((M_006980F8 *)D_001E1FD0_sda)->f38, buf);
        if (found == 0) {
            func_00120048(text, func_0037DF98(0x1694), buf);
            func_L39_006847C8(D_L39_00247A74_00695C88, text, D_001DC8F0_sda, 4, 0, 0.6f);
            return;
        }
        id = found->unk1C;
        val = found->unk20;
    }
    if (id == net->unk0) {
        {
            Menu_006983B8 *m = D_L39_00247A74_00695C88;
            func_L39_006847C8(m, func_0037DF98(0x1693), D_L39_00248180, 4, 0, 0.6f);
        }
        return;
    }
    if (!valid_006983B8(D_001E1FD0_sda->f48, val)) {
        func_00120048(text, func_0037DF98(0x1695), buf);
        func_L39_006847C8(D_L39_00247A74_00695C88, text, D_001DC8F0_sda, 4, 0, 0.6f);
        return;
    }
    sel = -1;
    text[0] = 'C';
    func_00120048(formatted, func_0037DF98(0x1696), net->unk4);
    func_00120048(text + 1, D_L39_002481B0, net->unk0, formatted);
    if (func_L39_006D7310(((Root_006983B8 *)D_L39_0024D860)->unk48, val, text, 0) == 0) {
        return;
    }
    if (func_L39_006D96D0(((Root_006983B8 *)D_001E1FD0_sda)->unk4C, net->unk0, id, &sel) == 0) {
        return;
    }
    func_L39_006D0768(net, id, val);
    {
        Menu_006983B8 *m = D_L39_00247A74_00695C88;
        func_L39_006847C8(m, func_0037DF98(0x1698), D_L39_00248180, 4, 0, 0.6f);
    }
    func_L39_006BA8F0(D_L39_00247A74_00695C88->unkE0, sel);
    D_L39_00247A74_00695C88->unk284 = 0x1F;
    this->unk140->vtbl->unk1C(this->unk140, 0, 0);
    this->unk144->vtbl->unk1C(this->unk144, 3, 0);
    this->unk148->vtbl->unk1C(this->unk148, 3, 0);
}
/* localdecomp:end func_L39_00695C88 */
