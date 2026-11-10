#include "common.h"

/* declared by functions of L39_006979B0.c, which this file was cut from */
typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_00697B28_inner;
typedef struct {
    char pad[0x38];
    S_00697B28_inner *f38;
} S_00697B28_outer;
extern S_00697B28_outer *D_L39_0024D760;

/* localdecomp:start func_L39_00697E10 */
typedef struct Widget_00697E10 Widget_00697E10;

typedef struct {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ void (*unk1C)(Widget_00697E10 *, s32, s32);
    /* 0x20 */ u8 pad20[0x94];
    /* 0xB4 */ void (*unkB4)(Widget_00697E10 *);
    /* 0xB8 */ void (*unkB8)(Widget_00697E10 *, char *);
    /* 0xBC */ u8 padBC[0x28];
    /* 0xE4 */ void (*unkE4)(Widget_00697E10 *, f32);
} WidgetVtbl_00697E10;

struct Widget_00697E10 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ WidgetVtbl_00697E10 *vtbl;
};

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4[0x2C];
    /* 0x30 */ char unk30[4];
} Net_00697E10;

typedef struct {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[0x20];
    /* 0x38 */ Net_00697E10 *unk38;
    /* 0x3C */ u8 pad3C[8];
    /* 0x44 */ void *unk44;
} Root_00697E10;

typedef struct {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ u8 pad10[0x180];
} Stats_00697E10;

typedef struct {
    /* 0x000 */ u8 pad0[0x124];
    /* 0x124 */ Widget_00697E10 *unk124;
    /* 0x128 */ Widget_00697E10 *unk128;
    /* 0x12C */ Widget_00697E10 *unk12C;
    /* 0x130 */ Widget_00697E10 *unk130;
    /* 0x134 */ u8 pad134[0xC];
    /* 0x140 */ Widget_00697E10 *unk140;
    /* 0x144 */ Widget_00697E10 *unk144;
    /* 0x148 */ Widget_00697E10 *unk148;
    /* 0x14C */ u8 pad14C[0x26C];
    /* 0x3B8 */ s32 unk3B8;
} S_00697E10;

extern char D_L39_00248030[];
extern char D_L39_00248040[];

extern s32 func_0038CAD0(s32 *);
extern s32 func_L39_006CEA18(Net_00697E10 *, s32);
extern void func_L39_00689BD8(S_00697E10 *, u8 *);
extern s32 func_L39_006D2F18(Net_00697E10 *, s32 *, s32 *);
extern char *func_L39_006D31B8(Net_00697E10 *, s32, s32);
extern s32 func_L39_006D2EF0(Net_00697E10 *, s32, s32);
extern char *func_00381FF0(s32);
extern void func_00120D28(char *, char *, s32);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_L39_006D6E50(void *, s32, s32, Stats_00697E10 *);

void func_L39_00697E10(S_00697E10 *this) {
    char tag[8];
    char tagText[0x10];
    Stats_00697E10 stats;
    char text[0x10];
    s32 a;
    s32 b;
    Net_00697E10 *net = ((Root_00697E10 *)D_L39_0024D760)->unk38;
    char *name;

    func_0038CAD0(&this->unk3B8);
    if (this->unk3B8 > 0) {
        return;
    }
    func_L39_006CEA18(net, 0);
    this->unk3B8 = 0x2EE;
    func_L39_00689BD8(this, net->unk4);
    if (func_L39_006D2F18(net, &a, &b) != 0) {
        name = func_L39_006D31B8(net, b, a);
        if (name != 0) {
            this->unk130->vtbl->unkB8(this->unk130, name + 0x20);
            this->unk130->vtbl->unkE4(this->unk130, 0.25f);
            this->unk140->vtbl->unk1C(this->unk140, 0, 0);
            this->unk144->vtbl->unk1C(this->unk144, 3, 0);
            this->unk148->vtbl->unk1C(this->unk148, 3, 0);
        } else {
            ((Root_00697E10 *)D_L39_0024D760)->unk14 = 0;
            func_L39_006D2EF0(net, -1, -1);
            this->unk130->vtbl->unkB8(this->unk130, func_00381FF0(0x1328));
            this->unk140->vtbl->unk1C(this->unk140, 3, 0);
            this->unk144->vtbl->unk1C(this->unk144, 0, 0);
            this->unk148->vtbl->unk1C(this->unk148, 2, 0);
        }
    } else {
        this->unk140->vtbl->unk1C(this->unk140, 3, 0);
        this->unk144->vtbl->unk1C(this->unk144, 0, 0);
        this->unk148->vtbl->unk1C(this->unk148, 2, 0);
        this->unk130->vtbl->unkB8(this->unk130, func_00381FF0(0x1328));
    }
    func_00120D28(tag, net->unk30, 4);
    tag[4] = 0;
    func_00120048(tagText, D_L39_00248030, tag);
    this->unk12C->vtbl->unkB8(this->unk12C, tagText);
    if (func_L39_006D6E50(((Root_00697E10 *)D_L39_0024D760)->unk44, net->unk0, 1, &stats) != 0) {
        func_00120048(text, D_L39_00248040, stats.unk8, stats.unkC);
        this->unk124->vtbl->unkB8(this->unk124, text);
        func_00120048(text, D_L39_00248040, stats.unk0, stats.unk4);
        this->unk128->vtbl->unkB8(this->unk128, text);
    } else {
        this->unk124->vtbl->unkB4(this->unk124);
        this->unk128->vtbl->unkB4(this->unk128);
    }
}
/* localdecomp:end func_L39_00697E10 */

INCLUDE_ASM("asm/levels", func_L39_006980F8);

INCLUDE_ASM("asm/levels", func_L39_006983B8);

LINKER_REMNANT("asm/levels", func_L39_00698C18);

INCLUDE_ASM("asm/levels", func_L39_00698C28);

LINKER_REMNANT("asm/levels", func_L39_00698F48);
