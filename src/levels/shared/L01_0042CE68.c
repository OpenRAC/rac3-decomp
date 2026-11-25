#include "common.h"

/* localdecomp:start func_L01_0042CE68 */
typedef struct { s32 sector; s32 count; } Range_0042CE68;
/* The gadget WAD's table in the table of contents: 48 entries of 20 bytes */
typedef struct {
    s32 id;                /* the gadget's class */
    Range_0042CE68 file;   /* 0x4: its file, sectors from the WAD's first */
    Range_0042CE68 sounds; /* 0xC: its sound bank */
} Gadget_0042CE68;
typedef struct {
    u8 pad0[0x4590];
    Gadget_0042CE68 gadgets[48];
} Toc_0042CE68;
/* A gadget's file: where its class and its textures are (offsets in bytes from the WAD's first
   sector), each a WAD */
typedef struct {
    s32 class_offset;
    s32 class_size;
    s32 texture_offset;
    s32 texture_size;
} GadgetFile_0042CE68;
typedef struct {
    s32 slot;              /* 0x0 */
    u8 pad4[0xA - 0x4];
    u16 palette;           /* 0xA */
    u8 padC[0x10 - 0xC];
    s16 texture;           /* 0x10 */
    s16 class_slot;        /* 0x12 */
} GadgetState_0042CE68;
typedef struct { u8 pad0[0x60]; } __attribute__((aligned(16))) LoadImage_0042CE68;
/* A sound table entry of a moby class: +0x1C the bank (0 the level's, 4 a gun's own) */
typedef struct {
    u8 pad0[0x1C];
    s32 bank;
} ClassSound_0042CE68;
typedef struct {
    u8 pad0[0xD];
    u8 sound_count;              /* 0xD */
    u8 padE[0x28 - 0xE];
    ClassSound_0042CE68 *sounds; /* 0x28 */
} MobyClass_0042CE68;
extern Toc_0042CE68 D_00160C40_0042CE68;
extern GadgetState_0042CE68 D_0016C690_0042CE68;
extern s32 D_00191ED0[];
extern s32 D_00191EE8[];
extern u8 D_00191F00[];
extern u8 D_00192300[];
extern s32 D_001A1ED0[];
extern s32 D_L01_001E0000;
extern u8 D_L01_001FDBD0[];
extern MobyClass_0042CE68 *D_L01_001FD180[];
extern s32 D_L01_00200670[];
extern void func_0011F0A0(s32);
extern void func_003A0760(u8 *, s32 *);
/* s32, as the core's: the result it leaves in $v0 changes how sched2 orders the next call's set-up */
extern s32 func_0012C9A0(void *, s16, s16, s16, s16, s16, s16, s16);
extern void func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);
extern void func_00399D68(s32 *, void *, void *, s32);

/* gadget_install: sends a gadget's texture to its GS slot, unpacks its class into the class
   buffer and registers it with that texture as its texture 0. */
void func_L01_0042CE68(s32 class, s32 row, u8 *file) {
    /* the load-image packet, then the class's texture map (its texture 0 is the gadget's) */
    union {
        LoadImage_0042CE68 li;
        u8 textures[0x60];
    } stack;
    u8 *texture_data;
    u8 *class_data;
    s32 saved;
    MobyClass_0042CE68 *moby_class;
    s32 i;
    s32 width;
    u8 *pixels;

    if (((GadgetFile_0042CE68 *)file)->texture_size != 0) {
        texture_data = file + ((GadgetFile_0042CE68 *)file)->texture_offset;
        texture_data -= D_00160C40_0042CE68.gadgets[row].file.sector << 11;
        func_0011F0A0(0);
        func_003A0760(texture_data, D_00191ED0);
        func_0011F0A0(0);
        if (D_00191ED0[0] == 1) {
            func_0012C9A0(&stack.li, D_0016C690_0042CE68.palette + (D_001A1ED0[8] >> 8), 1, 0, 0, 0, 16, 16);
            func_0011F0A0(0);
            func_0012CCC8(&stack.li, D_00191F00);
            func_0012A9F0(0, 0);
            width = D_00191EE8[0];
            pixels = D_00192300;
            func_0012C9A0(&stack.li, (D_001A1ED0[13] + D_0016C690_0042CE68.slot * 4) >> 8,
                (width >> 6) > 0 ? (width >> 6) : 1, 0x1B, 0, 0, width, width);
            func_0011F0A0(0);
            func_0012CCC8(&stack.li, pixels);
            func_0012A9F0(0, 0);
        }
    }
    class_data = file + ((GadgetFile_0042CE68 *)file)->class_offset;
    class_data -= D_00160C40_0042CE68.gadgets[row].file.sector << 11;
    func_0011F0A0(0);
    func_003A0760(class_data, D_00191ED0);
    func_0011F0A0(0);
    stack.textures[0] = D_0016C690_0042CE68.texture;
    saved = D_L01_001E0000;
    D_L01_001E0000 = D_0016C690_0042CE68.class_slot;
    func_00399D68(D_00191ED0, (u8 *)&D_0016C690_0042CE68 - D_0016C690_0042CE68.texture * 16, stack.textures, class);
    D_L01_00200670[D_0016C690_0042CE68.class_slot] = 0xFFF00000;
    moby_class = D_L01_001FD180[D_L01_001FDBD0[class]];
    D_L01_001E0000 = saved;
    for (i = 0; i < moby_class->sound_count; i++) {
        moby_class->sounds[i].bank = 4;
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

/* localdecomp:start func_L01_0042D3A8 */
#include "vu0.h"
typedef struct {
    s32 count;
    s32 ids[8];
    s32 starts[8];
    s32 slots[8];
    s32 addresses[8];
    s32 flags[8];
} Queue_0042D3A8;
typedef struct {
    s32 unused[2];
    s32 width;
    s32 height;
    s32 unused10[3];
    s32 format;
    u8 clut[0x400];
    u8 data[1];
} Texture_0042D3A8;
typedef struct {
    u32 unused;
    s16 width;
    s16 height;
    s16 format;
    s16 base;
    s16 palette;
    s16 unusedE;
} Record_0042D3A8;
typedef struct {
    u8 pad[0x20];
    s32 f20;
} Image_0042D3A8;
extern Image_0042D3A8 D_001A1ED0_0042D3A8;
extern s32 func_0012CCC8_0042D3A8(void *, void *);
extern Queue_0042D3A8 D_L01_0021F5E0_0042D3A8;
extern s32 D_L01_001E0000;
extern s32 D_L01_001E000C;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern unsigned long D_001D4BA8;
__asm__(".extern D_L01_001E0000, 16");
__asm__(".extern D_L01_001E000C, 16");
__asm__(".extern D_001D4BB4, 16");
__asm__(".extern D_001D4BB0, 16");
__asm__(".extern D_001D4BA8, 16");
extern unsigned long D_L01_001F3DC0[];
extern u8 D_L01_001D6D10_sda[4];
__asm__(".extern D_L01_001D6D10_sda, 4");
extern u32 D_L01_001FFE70[];

void func_L01_0042D3A8(s32 id, s32 *arg, s32 *data) {
    u8 head[16] __attribute__((aligned(16)));
    Record_0042D3A8 rows[15];
    u8 packet[96];
    s32 *offsets;
    Texture_0042D3A8 *tex;
    Record_0042D3A8 *row;
    s32 i, count, slotBytes;

    if (D_L01_001FDBD0[id] != 255) {
        return;
    }
    if (D_L01_0021F5E0_0042D3A8.count >= 8) {
        return;
    }
    func_003A92F0(1);
    qzero(head);
    D_L01_0021F5E0_0042D3A8.ids[D_L01_0021F5E0_0042D3A8.count] = id;
    D_L01_0021F5E0_0042D3A8.starts[D_L01_0021F5E0_0042D3A8.count] = D_L01_001E0000;
    D_L01_0021F5E0_0042D3A8.slots[D_L01_0021F5E0_0042D3A8.count] = D_L01_001E000C;
    D_L01_0021F5E0_0042D3A8.addresses[D_L01_0021F5E0_0042D3A8.count] = D_001D4BB4;
    D_L01_0021F5E0_0042D3A8.flags[D_L01_0021F5E0_0042D3A8.count] = 0;
    D_L01_0021F5E0_0042D3A8.count++;
    if ((id ^ 10) == 0) {
        D_L01_001F3DC0[0] = D_001D4BA8;
        D_L01_001F3DC0[1] = 0xFFA0000000E0UL;
        D_L01_001F3DC0[2] = 0x40000400004000UL;
        func_00399D68(arg, 0, D_L01_001D6D10_sda, id);
        D_L01_00200670[D_L01_001E0000 - 1] = 0xFFFC0000;
        return;
    }
    slotBytes = D_L01_001E000C * 16;
    if (data) {
        offsets = data;
        count = *offsets++;
        for (i = 0; i < count; i++, offsets++) {
            s32 amount;
            row = &rows[i];
            tex = (Texture_0042D3A8 *)((u8 *)data + *offsets);
            head[i] = D_L01_001E000C;
            D_L01_001FFE70[D_L01_001E000C] = (u32)tex->data;
            D_L01_001FFE70[D_L01_001E000C] += (30 - plzcw_asm(tex->width)) << 28;
            if (D_L01_001E000C < 256) {
                D_L01_001E000C++;
            }
            row->width = tex->width;
            row->height = tex->height;
            row->format = tex->format;
            if (row->format >= 4) {
                row->format = 3;
            }
            func_0012C9A0(packet, D_001D4BB4 >> 8, 1, 0, 0, 0, 16, 16);
            func_0011F0A0(0);
            func_0012CCC8_0042D3A8(packet, tex->clut);
            func_0012A9F0(0, 0);
            row->base = (D_001D4BB4 - D_001A1ED0_0042D3A8.f20) >> 8;
            D_001D4BB4 += 0x400;
            if (tex->format >= 3) {
                func_0012C9A0(packet, D_001D4BB4 >> 8, 1, 19, 0, 0, tex->width >> 2, tex->height >> 2);
                func_0011F0A0(0);
                func_0012CCC8_0042D3A8(packet, tex->data + ((tex->width * tex->height * 5) >> 2));
                func_0012A9F0(0, 0);
                row->palette = (D_001D4BB4 - D_001A1ED0_0042D3A8.f20) >> 8;
                row->unusedE = 0;
                amount = (tex->width * tex->height) >> 4;
                if (amount < 256) {
                    amount = 256;
                }
                D_001D4BB4 += amount;
            }
        }
        D_001D4BB0 = D_001D4BB4;
    }
    func_00399D68(arg, (u8 *)rows - slotBytes, head, id);
}
/* localdecomp:end func_L01_0042D3A8 */

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
extern u8 *D_L01_001FD180_0042D798[];
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
        D_L01_001FD180_0042D798[n] = 0;
        D_L01_001FDBD0[id] = 255;
        D_L01_00200670[n] = 0;
        D_L01_0021F5E0.other[D_L01_0021F5E0.count] = 0;
        D_L01_001E000C = saved;
        D_001D4BB4 = other;
        D_L01_0021F5E0.tail[D_L01_0021F5E0.count] = 0;
    }
}
/* localdecomp:end func_L01_0042D798 */
