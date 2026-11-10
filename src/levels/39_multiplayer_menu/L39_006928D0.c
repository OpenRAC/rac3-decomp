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

INCLUDE_ASM("asm/levels", func_L39_00692F20);

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

INCLUDE_ASM("asm/levels", func_L39_00693910);

/* localdecomp:start func_L39_00693F40 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00693F40(void *);

extern void func_L39_0067F168();
void func_L39_00693F40(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00693F40 */

INCLUDE_ASM("asm/levels", func_L39_00693F70);
