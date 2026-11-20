#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0042CE68);

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

INCLUDE_ASM("asm/levels", func_L01_0042D798);
