#include "common.h"

/* localdecomp:start func_L01_0042CE68 */
typedef struct {
    s32 id;
    s32 sector;          /* 0x4: where its data starts on the disc, in 2048-byte sectors */
    u8 pad8[0x14 - 0x8];
} Gadget_0042CE68;
typedef struct {
    u8 pad0[0x4590];
    Gadget_0042CE68 gadgets[48];
} Gadgets_0042CE68;
typedef struct {
    s32 f0;
    u8 pad4[0xA - 0x4];
    u16 fA;
    u8 padC[0x10 - 0xC];
    s16 f10;
    s16 f12;
} State_0042CE68;
typedef struct {
    u8 pad0[0x20];
    s32 f20;
    u8 pad24[0x34 - 0x24];
    s32 f34;
} Image_0042CE68;
typedef struct {
    s32 off0;
    s32 size0;
    s32 off1;
    s32 size1;
} Buffer_0042CE68;
typedef struct {
    u8 pad0[0xD];
    u8 count;
    u8 padE[0x28 - 0xE];
    u8 *items;
} Object_0042CE68;
extern Gadgets_0042CE68 D_00160C40_0042CE68;
extern State_0042CE68 D_0016C690_0042CE68;
extern s32 D_00191ED0[];
extern s32 D_00191EE8[];
extern u8 D_00191F00[];
extern u8 D_00192300[];
extern Image_0042CE68 D_001A1ED0;
extern s32 D_L01_001E0000;
extern u8 D_L01_001FDBD0[];
extern u8 *D_L01_001FD180[];
extern s32 D_L01_00200670[];
extern void func_0011F0A0(s32);
extern void func_003A0760(u8 *, s32 *);
extern s32 func_0012C9A0(void *, s16, s16, s16, s16, s16, s16, s16);
extern s32 func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);
extern void func_00399D68(s32 *, u8 *, u8 *, s32);

void func_L01_0042CE68(s32 class, s32 row, u8 *buffer) {
    Buffer_0042CE68 *b = (Buffer_0042CE68 *)buffer;
    u8 image[0x60];
    u8 *data0;
    u8 *data1;
    s32 saved;
    Object_0042CE68 *obj;
    s32 i;
    s32 width;
    u8 *pixels;

    if (b->size1 != 0) {
        data1 = buffer + b->off1;
        data1 -= D_00160C40_0042CE68.gadgets[row].sector << 11;
        func_0011F0A0(0);
        func_003A0760(data1, D_00191ED0);
        func_0011F0A0(0);
        if (D_00191ED0[0] == 1) {
            func_0012C9A0(image, D_0016C690_0042CE68.fA + (D_001A1ED0.f20 >> 8), 1, 0, 0, 0, 16, 16);
            func_0011F0A0(0);
            func_0012CCC8(image, D_00191F00);
            func_0012A9F0(0, 0);
            width = D_00191EE8[0];
            pixels = D_00192300;
            func_0012C9A0(image, (D_001A1ED0.f34 + D_0016C690_0042CE68.f0 * 4) >> 8,
                (width >> 6) > 0 ? (width >> 6) : 1, 27, 0, 0, width, width);
            func_0011F0A0(0);
            func_0012CCC8(image, pixels);
            func_0012A9F0(0, 0);
        }
    }
    data0 = buffer + b->off0;
    data0 -= D_00160C40_0042CE68.gadgets[row].sector << 11;
    func_0011F0A0(0);
    func_003A0760(data0, D_00191ED0);
    func_0011F0A0(0);
    image[0] = D_0016C690_0042CE68.f10;
    saved = D_L01_001E0000;
    D_L01_001E0000 = D_0016C690_0042CE68.f12;
    func_00399D68(D_00191ED0, (u8 *)&D_0016C690_0042CE68 - D_0016C690_0042CE68.f10 * 16, image, class);
    D_L01_00200670[D_0016C690_0042CE68.f12] = 0xFFF00000;
    obj = (Object_0042CE68 *)D_L01_001FD180[D_L01_001FDBD0[class]];
    D_L01_001E0000 = saved;
    for (i = 0; i < obj->count; i++) {
        *(s32 *)(obj->items + i * 32 + 0x1C) = 4;
    }
}
/* localdecomp:end func_L01_0042CE68 */

/* localdecomp:start func_L01_0042D110 */
typedef struct {
    s32 id;              /* the gadget's class */
    u8 pad4[0x10 - 0x4];
    s32 sound_bank;      /* 0x10 */
} Gadget_0042D110;
typedef struct {
    u8 pad0[0x4590];
    Gadget_0042D110 gadgets[48];
} Gadgets_0042D110;
typedef struct {
    u8 pad0[0x14];
    s16 current;         /* 0x14: row of the gadget out */
    s16 slot;            /* 0x16: its buffer */
    u8 pad18[0x30 - 0x18];
    s32 sound;           /* 0x30 */
    s32 slots[3];        /* 0x34: the row in each buffer */
    u8 buffers[3][0xC800]; /* 0x40 */
} GadgetState_0042D110;
typedef struct {
    u8 pad0[0x1C];
    s32 x1C;
} Effect_0042D110;
typedef struct {
    u8 pad0[0x20];
    s32 sound;           /* 0x20 */
    u8 pad24[0x44 - 0x24];
    Effect_0042D110 *effect; /* 0x44 */
    u8 pad48[0x80 - 0x48];
} Slot_0042D110;
extern Gadgets_0042D110 D_00160C40_0042D110;
extern GadgetState_0042D110 D_0016C690;
typedef struct {
    Slot_0042D110 slots[53];
} Slots_0042D110;
extern Slots_0042D110 D_001A30B0;
__asm__(".extern D_L01_001D6DF0, 8");
extern s32 D_L01_001D6DF0[2];
extern u8 *D_L01_001E1060[];
extern s32 D_L01_001E1070; /* a plain small scalar: Ps2EeAs expands its load in place, as retail */
extern u8 *D_001D4B38;
extern void func_003A92F0(s32);
extern void func_L01_0042CD88(s32, s32);
extern void func_L01_004369B8(u8 *, u8 *, s32);
extern void func_0013BF00(s32);
extern s32 func_0013B620(void);
extern s32 func_0013BD58(u8 *);
extern void func_0013BED0(void);
extern void func_L01_0042CE68(s32, s32, u8 *);

/* gadget_select: makes the gadget of a class the one out: finds its buffer or loads it into
   buffer 0, re-points the effects that used the old one and installs it. */
void func_L01_0042D110(s32 class) {
    s32 row;
    s32 slot;
    s32 i;
    u8 *buffer;
    u8 *copy;
    Slot_0042D110 *s;

    for (row = 0; row < 48; row++) {
        if (D_00160C40_0042D110.gadgets[row].id == class) {
            break;
        }
    }
    if (row == 48 || row == D_0016C690.current) {
        return;
    }
    D_0016C690.current = row;
    for (slot = 0; slot < 3; slot++) {
        if (D_0016C690.slots[slot] == row) {
            break;
        }
    }
    func_003A92F0(1);
    if (slot == 3) {
        slot = 0;
        func_L01_0042CD88(class, 0);
    }
    D_0016C690.slot = slot;
    buffer = D_0016C690.buffers[slot];
    if ((s32)buffer <= 0xFFFFF) {
        copy = D_L01_001E1060[0] + D_L01_001E1070 - 0xC800;
        func_L01_004369B8(copy, buffer, 0xC80);
        buffer = copy;
    }
    for (i = 0; i < 52; i++) {
        s = &D_001A30B0.slots[i];
        if (s[1].effect != 0 && s[1].effect->x1C == 4) {
            s[1].effect = (Effect_0042D110 *)D_L01_001D6DF0;
        }
    }
    if (D_0016C690.sound != 0) {
        func_0013BF00(D_0016C690.sound);
        while (func_0013B620() != 0) {
        }
    }
    if (D_00160C40_0042D110.gadgets[row].sound_bank != 0) {
        D_0016C690.sound = D_001A30B0.slots[1].sound = func_0013BD58(D_001D4B38 + slot * 0xC800);
    } else {
        D_0016C690.sound = 0;
    }
    func_0013BED0();
    func_L01_0042CE68(class, row, buffer);
}
/* localdecomp:end func_L01_0042D110 */

/* localdecomp:start func_L01_0042D330 */
typedef struct {
    s32 id;
    u8 pad[16];
} E_42A520;

typedef struct {
    u8 pad[17808];
    E_42A520 e[48];
} T_160C40;

extern T_160C40 D_00160C40;
extern s16 D_0016C6A4[];
extern void func_0039A8B8(s32, s32, s32, s32);

void func_L01_0042D330(s32 a0, s32 a1) {
    s32 i;
    for (i = 0; i < 48; i++) {
        if (D_00160C40.e[i].id == a0) {
            break;
        }
    }
    if (i != 48) {
        D_0016C6A4[0] = i;
        func_0039A8B8(i, -1, a1, 1);
    }
}
/* localdecomp:end func_L01_0042D330 */

LINKER_REMNANT("asm/levels", func_L01_0042D3A0);

INCLUDE_ASM("asm/levels", func_L01_0042D3A8);

/* localdecomp:start func_L01_0042D798 */
typedef struct {
    s32 count;
    s32 ids[8];
    s32 values[8];
    s32 saved[8];
    s32 other[8];
    s32 tail[8];
} Stack_0042D798;
extern Stack_0042D798 D_L01_0021F5E0;
extern s32 D_L01_001E0000;
extern s32 D_L01_001E000C;
extern s32 D_001D4BB4;
extern u8 D_L01_001FDBD0[];
extern s16 D_L01_001FD9F0[];
extern s32 D_L01_00200670[];
extern u8 *D_L01_001FD180[];
__asm__(".extern D_L01_001E0000, 16");
__asm__(".extern D_L01_001E000C, 16");
__asm__(".extern D_001D4BB4, 16");
void func_L01_0042D798(void) {
    s32 id, saved, other, n;
    if (D_L01_0021F5E0.count != 0) {
        --D_L01_0021F5E0.count;
        id = D_L01_0021F5E0.ids[D_L01_0021F5E0.count];
        saved = D_L01_0021F5E0.saved[D_L01_0021F5E0.count];
        other = D_L01_0021F5E0.other[D_L01_0021F5E0.count];
        D_L01_0021F5E0.ids[D_L01_0021F5E0.count] = 0;
        n = D_L01_001E0000 - 1;
        D_L01_0021F5E0.values[D_L01_0021F5E0.count] = 0;
        D_L01_0021F5E0.saved[D_L01_0021F5E0.count] = 0;
        D_L01_001FD9F0[n] = -1;
        D_L01_001E0000 = n;
        D_L01_001FD180[n] = 0;
        D_L01_001FDBD0[id] = 255;
        D_L01_00200670[n] = 0;
        D_L01_0021F5E0.other[D_L01_0021F5E0.count] = 0;
        D_L01_001E000C = saved;
        D_001D4BB4 = other;
        D_L01_0021F5E0.tail[D_L01_0021F5E0.count] = 0;
    }
}
/* localdecomp:end func_L01_0042D798 */
