/* Wave 13 (r21, 2026-11-28) replaces the earlier draft of this function (k6 Opus near miss (2026-11-26)). */
/* PAL near miss (wave 13 r21, 2026-11-28): 11 differences (build/codex/wave10/p10/check.py, level 39, the file's flags), down from the k6 draft's 13. Changed against the draft: the state byte is tested directly (this->unk2AD = 1, as the matched sibling func_L39_00692C38 does; same code as the draft's i local), and one local id carries net->unk4EC through the second refresh block and the following compare/store (this->unk2A8 = id), which gives retail's v1 for that copy. Left: only the prologue schedule (retail: sd s2, sd s1, move s2, sd s3..ra, sd s0, lbu s1, li v0 1; ours: li 1 hoisted to the second slot, sd s0 second and sd s1 last). Block 0's insns, their order after sched1 and their dependencies are the same as in the sibling, whose retail schedules like ours; tried: state read into a local (also as the loop counter), state read before net, a flat && condition for the first block, a temporary for the first copy. */
#include "common.h"
/* localdecomp:start func_L39_00692918 */
__asm__(".extern D_L39_0024D760, 16");


typedef struct {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ u8 pad24[0x19C];
    /* 0x1C0 */ s32 unk1C0;
} Item_00692918;

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 count;
    /* 0x8 */ Item_00692918 **items;
} List_00692918;

typedef struct {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 pad4[0x4D8];
    /* 0x4DC */ u8 unk4DC;
    /* 0x4E0 */ s32 unk4E0;
    /* 0x4E4 */ u8 unk4E4;
    /* 0x4E8 */ s32 unk4E8;
    /* 0x4EC */ s32 unk4EC;
    /* 0x4F0 */ s32 unk4F0;
    /* 0x4F4 */ List_00692918 lists[1];
} Net_00692918;

typedef struct Widget_00692918 Widget_00692918;

typedef struct {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ void (*unk1C)(Widget_00692918 *, s32, s32);
    /* 0x20 */ u8 pad20[0x4C];
    /* 0x6C */ void (*unk6C)(Widget_00692918 *, s32, char **);
    /* 0x70 */ u8 pad70[0x18];
    /* 0x88 */ void (*unk88)(Widget_00692918 *, s32);
    /* 0x8C */ s32 (*unk8C)(Widget_00692918 *);
} WidgetVtbl_00692918;

struct Widget_00692918 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0x58];
    /* 0x60 */ WidgetVtbl_00692918 *vtbl;
};

typedef struct {
    /* 0x000 */ u8 pad0[0x110];
    /* 0x110 */ Widget_00692918 *unk110;
    /* 0x114 */ u8 pad114[0x2A8 - 0x114];
    /* 0x2A8 */ s32 unk2A8;
    /* 0x2AC */ u8 unk2AC;
    /* 0x2AD */ u8 unk2AD;
    /* 0x2B0 */ s32 unk2B0;
    /* 0x2B4 */ s32 unk2B4[16];
    /* 0x2F4 */ char unk2F4[16][0x20];
    /* 0x4F4 */ u8 pad4F4[5];
    /* 0x4F9 */ u8 unk4F9;
    /* 0x4FA */ u8 pad4FA[0x745 - 0x4FA];
    /* 0x745 */ u8 unk745;
} S_00692918;

extern void func_L39_006D2500(Net_00692918 *, s32, s32);
extern char *func_L39_006D31B8(Net_00692918 *, s32, s32);
extern void *func_001206F4(void *, void *);
extern s32 func_00120884(char *);
extern void func_L39_005958F8(char *, char *, s32);

void func_L39_00692918(S_00692918 *this) {
    char *names[16];
    char bufs[16][0x50];
    Net_00692918 *net = (Net_00692918 *)D_L39_0024D760->f38;
    List_00692918 *list;
    s32 count;
    s32 cur;
    s32 sel;
    s32 i;
    s32 j;
    s32 old;
    s32 id;

    if (this->unk2AC == 1) {
        if (net->unk4E4 != 0) {
            return;
        }
        if (this->unk2AD == 0 && this->unk4F9 == 0 && this->unk745 == 0) {
            func_L39_006D2500(net, 0, 0);
            this->unk2AD = 1;
            this->unk2A8 = net->unk4EC;
            this->unk2AC = 0;
        }
    }
    if (net->unk4E4 != 0) {
        return;
    }
    if (this->unk2AD == 0) {
        return;
    }
    if (net->unk4EC == this->unk2A8) {
        return;
    }
    list = 0;
    if (net->unk4DC != 0 && net->unk4E0 >= 0) {
        list = &net->lists[net->unk4E0];
    }
    this->unk2AD = 0;
    if (this->unk2AC == 1 && net->unk4E4 == 0) {
        func_L39_006D2500(net, 0, 0);
        id = net->unk4EC;
        this->unk2A8 = id;
        this->unk2AC = 0;
    }
    if (list == 0) {
        return;
    }
    id = net->unk4EC;
    if (id == this->unk2A8) {
        return;
    }
    cur = -1;
    this->unk2A8 = id;
    count = list->count;
    this->unk2B0 = 0;
    sel = 0;
    old = this->unk110->vtbl->unk8C(this->unk110);
    if (old != -1) {
        cur = this->unk2B4[old];
    }
    for (i = 0; i < count && this->unk2B0 < 16; i++) {
        Item_00692918 *item = list->items[i];
        char *name;

        if (item->unk1C == net->unk0) {
            this->unk2B4[this->unk2B0] = item->unk1C0;
            name = func_L39_006D31B8(net, item->unk20, item->unk20);
            func_001206F4(this->unk2F4[this->unk2B0], name + 0x20);
            names[this->unk2B0] = this->unk2F4[this->unk2B0];
            if (cur == this->unk2B4[this->unk2B0]) {
                sel = this->unk2B0;
            }
            this->unk2B0++;
        }
    }
    for (j = 0; j < this->unk2B0; j++) {
        func_L39_005958F8(bufs[j], names[j], func_00120884(names[j]));
        names[j] = bufs[j];
    }
    this->unk110->vtbl->unk6C(this->unk110, this->unk2B0, names);
    this->unk110->vtbl->unk88(this->unk110, sel);
    if (this->unk2B0 > 0) {
        if (this->unk110->unk4 < 3) {
            this->unk110->vtbl->unk1C(this->unk110, 3, 0);
        }
    } else {
        if (this->unk110->unk4 >= 3) {
            this->unk110->vtbl->unk1C(this->unk110, 2, 0);
        }
    }
}
/* localdecomp:end func_L39_00692918 */
