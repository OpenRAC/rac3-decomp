#include "common.h"

/* localdecomp:start func_L39_006928D0 */
__asm__(".extern D_L39_0024D760, 16");

typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_006928D0_inner;

typedef struct {
    char pad[0x38];
    S_006928D0_inner *f38;
} S_006928D0_outer;

typedef struct {
    char pad[0x284];
    s32 f284;
} S_006928D0_slot;

extern S_006928D0_outer *D_L39_0024D760;
extern S_006928D0_slot *D_001DC204_sda;

s32 func_L39_006928D0(void)
{
    S_006928D0_inner *inner = D_L39_0024D760->f38;
    s32 result = 0;

    if (inner->f34 == 0) {
        if (inner->f0 == -1) {
            D_001DC204_sda->f284 = 8;
            result = 1;
        } else {
            D_001DC204_sda->f284 = 6;
            result = 1;
        }
    }
    return result;
}
/* localdecomp:end func_L39_006928D0 */

INCLUDE_ASM("asm/levels", func_L39_00692918);

/* localdecomp:start func_L39_00692C38 */
__asm__(".extern D_L39_0024D760, 16");

typedef struct {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ u8 pad24[0x19C];
    /* 0x1C0 */ s32 unk1C0;
} Item_00692C38;

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 count;
    /* 0x8 */ Item_00692C38 **items;
} List_00692C38;

typedef struct {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4D8];
    /* 0x4DC */ u8 unk4DC;
    /* 0x4E0 */ s32 unk4E0;
    /* 0x4E4 */ u8 unk4E4;
    /* 0x4E8 */ s32 unk4E8;
    /* 0x4EC */ s32 unk4EC;
    /* 0x4F0 */ s32 unk4F0;
    /* 0x4F4 */ List_00692C38 lists[1];
} Net_00692C38;

typedef struct Widget_00692C38 Widget_00692C38;

typedef struct {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ void (*unk1C)(Widget_00692C38 *, s32, s32);
    /* 0x20 */ u8 pad20[0x4C];
    /* 0x6C */ void (*unk6C)(Widget_00692C38 *, s32, char **);
    /* 0x70 */ u8 pad70[0x18];
    /* 0x88 */ void (*unk88)(Widget_00692C38 *, s32);
    /* 0x8C */ s32 (*unk8C)(Widget_00692C38 *);
} WidgetVtbl_00692C38;

struct Widget_00692C38 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0x58];
    /* 0x60 */ WidgetVtbl_00692C38 *vtbl;
};

typedef struct {
    /* 0x000 */ u8 pad0[0x114];
    /* 0x114 */ Widget_00692C38 *unk114;
    /* 0x118 */ u8 pad118[0x195];
    /* 0x2AD */ u8 unk2AD;
    /* 0x2AE */ u8 pad2AE[0x246];
    /* 0x4F4 */ s32 unk4F4;
    /* 0x4F8 */ u8 unk4F8;
    /* 0x4F9 */ u8 unk4F9;
    /* 0x4FC */ s32 unk4FC;
    /* 0x500 */ s32 unk500[16];
    /* 0x540 */ char unk540[16][0x20];
    /* 0x740 */ u8 pad740[5];
    /* 0x745 */ u8 unk745;
} S_00692C38;

extern void func_L39_006D2500(Net_00692C38 *, s32, s32);
extern char *func_L39_006D31B8(Net_00692C38 *, s32, s32);
extern void *func_001206F4(void *, void *);
extern s32 func_00120884(char *);
extern void func_L39_005958F8(char *, char *, s32);

void func_L39_00692C38(S_00692C38 *this) {
    char *names[16];
    char bufs[16][0x50];
    Net_00692C38 *net = (Net_00692C38 *)D_L39_0024D760->f38;
    List_00692C38 *list;
    s32 count;
    s32 cur;
    s32 sel;
    s32 i;
    s32 j;
    s32 old;

    if (this->unk4F8 == 1) {
        if (net->unk4E4 != 0) {
            return;
        }
        if (this->unk2AD == 0 && this->unk4F9 == 0 && this->unk745 == 0) {
            func_L39_006D2500(net, 0, 0);
            this->unk4F9 = 1;
            this->unk4F4 = net->unk4EC;
            this->unk4F8 = 0;
        }
    }
    if (net->unk4E4 != 0) {
        return;
    }
    if (this->unk4F9 == 0) {
        return;
    }
    if (net->unk4EC == this->unk4F4) {
        return;
    }
    list = 0;
    if (net->unk4DC != 0 && net->unk4E0 >= 0) {
        list = &net->lists[net->unk4E0];
    }
    this->unk4F9 = 0;
    if (list == 0) {
        return;
    }
    if (net->unk4EC == this->unk4F4) {
        return;
    }
    cur = -1;
    this->unk4F4 = net->unk4EC;
    count = list->count;
    this->unk4FC = 0;
    sel = 0;
    old = this->unk114->vtbl->unk8C(this->unk114);
    if (old != -1) {
        cur = this->unk500[old];
    }
    for (i = 0; i < count && this->unk4FC < 16; i++) {
        Item_00692C38 *item = list->items[i];
        char *name;

        if (item->unk20 == net->unk0) {
            this->unk500[this->unk4FC] = item->unk1C0;
            name = func_L39_006D31B8(net, item->unk1C, item->unk1C);
            func_001206F4(this->unk540[this->unk4FC], name + 0x20);
            names[this->unk4FC] = this->unk540[this->unk4FC];
            if (cur == this->unk500[this->unk4FC]) {
                sel = this->unk4FC;
            }
            this->unk4FC++;
        }
    }
    for (j = 0; j < this->unk4FC; j++) {
        func_L39_005958F8(bufs[j], names[j], func_00120884(names[j]));
        names[j] = bufs[j];
    }
    this->unk114->vtbl->unk6C(this->unk114, this->unk4FC, names);
    this->unk114->vtbl->unk88(this->unk114, sel);
    if (this->unk4FC > 0) {
        if (this->unk114->unk4 < 3) {
            this->unk114->vtbl->unk1C(this->unk114, 3, 0);
        }
    } else {
        if (this->unk114->unk4 >= 3) {
            this->unk114->vtbl->unk1C(this->unk114, 2, 0);
        }
    }
}
/* localdecomp:end func_L39_00692C38 */

/* localdecomp:start func_L39_00692F20 */
__asm__(".extern D_L39_0024D760, 16");

typedef struct S_00692F20_item {
    char pad0[0x1C];
    s32 f1C;
    s32 f20;
    char pad24[0x19C];
    s32 f1C0;
} S_00692F20_item;

typedef struct S_00692F20_entry {
    s32 f0;
    s32 f4;
    S_00692F20_item **f8;
} S_00692F20_entry;

typedef struct S_00692F20_mgr {
    s32 f0;
    char pad4[0x4D8];
    u8 f4DC;
    s32 f4E0;
    u8 f4E4;
    s32 f4E8;
    s32 f4EC;
    s32 f4F0;
    S_00692F20_entry f4F4[1];
} S_00692F20_mgr;

typedef struct S_00692F20_info {
    char pad0[0x20];
    char f20[0x20];
    s32 f40;
    char f44[0x20];
} S_00692F20_info;

typedef struct S_00692F20_list S_00692F20_list;

typedef struct S_00692F20_vt {
    char pad0[0x1C];
    void (*f1C)(S_00692F20_list *, s32, s32);
    char pad20[0x4C];
    void (*f6C)(S_00692F20_list *, s32, char **);
    char pad70[0x18];
    void (*f88)(S_00692F20_list *, s32);
    s32 (*f8C)(S_00692F20_list *);
} S_00692F20_vt;

struct S_00692F20_list {
    s32 f0;
    s32 f4;
    char pad8[0x58];
    S_00692F20_vt *f60;
};

typedef struct S_00692F20_self {
    char pad0[0x118];
    S_00692F20_list *f118;
    char pad11C[0x191];
    u8 f2AD;
    char pad2AE[0x24B];
    u8 f4F9;
    char pad4FA[0x246];
    s32 f740;
    u8 f744;
    u8 f745;
    s32 f748;
    s32 f74C[16];
    char f78C[16][0xC8];
    u8 f140C[16];
    s32 f141C[16];
    s32 f145C[16];
    char f149C[16][0x20];
} S_00692F20_self;

extern void func_L39_006D2500(Net_00692C38 *, s32, s32);
extern char *func_L39_006D31B8(Net_00692C38 *, s32, s32);
extern void *func_001206F4(void *, void *);
extern s32 func_00120884(char *);
extern void func_L39_005958F8(char *, char *, s32);

void func_L39_00692F20(S_00692F20_self *self)
{
    char *names[16];
    char bufs[16][0x50];
    S_00692F20_mgr *m = (S_00692F20_mgr *)D_L39_0024D760->f38;
    S_00692F20_entry *entry;
    s32 sel;
    s32 selIdx;
    s32 i;
    s32 r;
    s32 j;
    s32 id;

    if (self->f744 == 1) {
        if (m->f4E4) {
            return;
        }
        if (!self->f2AD && !self->f4F9 && !self->f745) {
            func_L39_006D2500((Net_00692C38 *)m, 0, 1);
            self->f745 = 1;
            id = m->f4EC;
            self->f744 = 0;
            self->f740 = id;
        }
    }
    if (m->f4E4 == 0 && self->f745 != 0 && m->f4EC != self->f740) {
        entry = 0;
        if (m->f4DC && m->f4E0 >= 0) {
            entry = &m->f4F4[m->f4E0];
        }
        self->f745 = 0;
        if (entry && m->f4EC != self->f740) {
            self->f740 = m->f4EC;
            self->f748 = entry->f4;
            if (self->f748 > 16) {
                self->f748 = 16;
            }
            sel = -1;
            selIdx = 0;
            r = self->f118->f60->f8C(self->f118);
            if (r != -1) {
                sel = self->f74C[r];
            }
            for (i = 0; i < self->f748; i++) {
                S_00692F20_item *p = entry->f8[i];
                S_00692F20_info *info;

                self->f74C[i] = p->f1C0;
                if (p->f20 == m->f0) {
                    info = (S_00692F20_info *)func_L39_006D31B8((Net_00692C38 *)m, p->f1C, p->f1C);
                    func_001206F4(self->f78C[i], info->f20);
                    self->f140C[i] = 0;
                    names[i] = self->f78C[i];
                    self->f145C[i] = info->f40;
                    func_001206F4(self->f149C[i], info->f44);
                } else {
                    info = (S_00692F20_info *)func_L39_006D31B8((Net_00692C38 *)m, p->f20, p->f20);
                    func_001206F4(self->f78C[i], info->f20);
                    names[i] = self->f78C[i];
                    self->f140C[i] = 1;
                    self->f141C[i] = p->f20;
                    self->f145C[i] = info->f40;
                    func_001206F4(self->f149C[i], info->f44);
                }
                if (sel == self->f74C[i]) {
                    selIdx = i;
                }
            }
            for (j = 0; j < self->f748; j++) {
                func_L39_005958F8(bufs[j], names[j], func_00120884(names[j]));
                names[j] = bufs[j];
            }
            self->f118->f60->f6C(self->f118, self->f748, names);
            self->f118->f60->f88(self->f118, selIdx);
            if (self->f748 > 0) {
                if (self->f118->f4 < 3) {
                    self->f118->f60->f1C(self->f118, 3, 0);
                }
            } else {
                if (self->f118->f4 >= 3) {
                    self->f118->f60->f1C(self->f118, 2, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L39_00692F20 */

LINKER_REMNANT("asm/levels", func_L39_006932C8);

INCLUDE_ASM("asm/levels", func_L39_006932E8);

LINKER_REMNANT("asm/levels", func_L39_006938E0);

/* localdecomp:start func_L39_006938E8 */
extern u8 D_L39_0047CA68[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006938E8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047CA68;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006938E8 */
