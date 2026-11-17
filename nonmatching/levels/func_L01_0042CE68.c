/* Near miss (69 differing words; open-rac-engine: gadget_install). Needs `@ps2as` on
 * src/levels/shared/L01_0042CE68.c (check with `--flags=@ps2as`). Structure, frame (0xB0, the
 * packet buffer reused for the slot byte) and calls match; what differs: retail keeps `class` in
 * $fp and the three high halves in $s5-$s7 (one saved register more than this C, which shifts
 * every saved register by one), and in the second half it reads the old D_L01_001E0000 (through
 * the small alias, a `lui`/`lw` macro) before the call and puts the `$gp` store of the new one
 * in the `jal` delay slot, where this C does the reverse.
 * Found: D_00191F00/D_00191EE8/D_00192300 are the unpack buffer's palette, width and pixels
 * (D_00191ED0 + 0x30/0x18/0x430; wrench_load reads the same layout through a pointer), each its
 * own symbol in retail (separate `lui`s); the pixels address is a local set before the second
 * upload (retail keeps it in $s0 across two calls); D_L01_001E0000 is written through `$gp`
 * (`.extern` 4) but read and restored through an unsized alias (`$at` in the store). */
typedef struct {
    s32 id;              /* the gadget's class */
    s32 texture_pages;   /* 0x04: 2 KB pages its texture is short of the buffer's end */
    u8 pad8[0x10 - 0x8];
    s32 sound_bank;      /* 0x10 */
} Gadget_0042CE68;
typedef struct {
    u8 pad0[0x4590];
    Gadget_0042CE68 gadgets[48];
} Gadgets_0042CE68;
typedef struct {
    s32 class_offset;    /* 0x00: the class's offset in the buffer */
    u8 pad4[4];
    s32 texture_offset;  /* 0x08 */
    s32 has_texture;     /* 0x0C */
} GadgetFile_0042CE68;
typedef struct {
    s32 w[0x18 / 4];     /* w[0]: 1 for a paletted texture */
} Unpacked_0042CE68;
typedef struct {
    s32 base;            /* 0x00 */
    u8 pad4[0xA - 0x4];
    u16 vram_page;       /* 0x0A */
    u8 padC[0x10 - 0xC];
    s16 slot;            /* 0x10 */
    s16 index;           /* 0x12 */
} GadgetState_0042CE68;
typedef struct {
    u8 pad0[0x20];
    s32 clut_base;       /* 0x20 */
    u8 pad24[0x34 - 0x24];
    s32 texture_base;    /* 0x34 */
} Vram_0042CE68;
typedef struct {
    u8 pad0[0xD];
    u8 count;            /* 0x0D */
    u8 pad_E[0x28 - 0xE];
    u8 *entries;         /* 0x28: 0x20 bytes each */
} Class_0042CE68;

extern Gadgets_0042CE68 D_00160C40_0042CE68;
extern GadgetState_0042CE68 D_0016C690_0042CE68;
extern Unpacked_0042CE68 D_00191ED0;
extern s32 D_00191EE8;
extern u8 D_00191F00[];
extern u8 D_00192300[];
extern Vram_0042CE68 D_001A1ED0_0042CE68;
__asm__(".extern D_L01_001E0000, 4");
extern s32 D_L01_001E0000;
extern s32 D_L01_001E0000_0042CE68;
extern u8 D_L01_001FDBD0[];
extern Class_0042CE68 *D_L01_001FD180[];
extern s32 D_L01_00200670[];
extern void func_0011F0A0(s32);
extern void func_003A0760(u8 *, u32);
extern void func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern s32 func_0012CCC8(void *, void *);
extern void func_0012A9F0(s32, s32);
extern void func_00399D68(void *, void *, u8 *, s32);

/* gadget_install: sends a gadget's texture to its GS slot, unpacks its class into 0x191ED0 and
   registers it */
void func_L01_0042CE68(s32 class, s32 row, GadgetFile_0042CE68 *file)
{
    u8 packet[0x60];
    u8 *texture;
    u8 *model;
    s32 kind;
    s32 width;
    u8 *pixels;
    s32 height;
    s32 saved;
    Class_0042CE68 *cls;
    s32 i;

    if (file->has_texture != 0) {
        texture = (u8 *)file + file->texture_offset;
        texture -= D_00160C40_0042CE68.gadgets[row].texture_pages << 11;
        func_0011F0A0(0);
        func_003A0760(texture, (u32)&D_00191ED0);
        func_0011F0A0(0);
        kind = D_00191ED0.w[0];
        if (kind == 1) {
            func_0012C9A0(packet, D_0016C690_0042CE68.vram_page + (D_001A1ED0_0042CE68.clut_base >> 8), 1, 0, 0, 0, 16, 16);
            func_0011F0A0(0);
            func_0012CCC8(packet, D_00191F00);
            func_0012A9F0(0, 0);
            width = D_00191EE8;
            pixels = D_00192300;
            height = width >> 6;
            if (height <= 0) {
                height = kind;
            }
            func_0012C9A0(packet, (D_001A1ED0_0042CE68.texture_base + D_0016C690_0042CE68.base * 4) >> 8, height, 0x1B, 0, 0, width, width);
            func_0011F0A0(0);
            func_0012CCC8(packet, pixels);
            func_0012A9F0(0, 0);
        }
    }
    model = (u8 *)file + file->class_offset;
    model -= D_00160C40_0042CE68.gadgets[row].texture_pages << 11;
    func_0011F0A0(0);
    func_003A0760(model, (u32)&D_00191ED0);
    func_0011F0A0(0);
    saved = D_L01_001E0000_0042CE68;
    packet[0] = D_0016C690_0042CE68.slot;
    D_L01_001E0000 = D_0016C690_0042CE68.index;
    func_00399D68(&D_00191ED0, (u8 *)&D_0016C690_0042CE68 - D_0016C690_0042CE68.slot * 16, packet, class);
    cls = D_L01_001FD180[D_L01_001FDBD0[class]];
    D_L01_00200670[D_0016C690_0042CE68.index] = 0xFFF00000;
    D_L01_001E0000_0042CE68 = saved;
    if (cls->count != 0) {
        for (i = 0; i < cls->count; i++) {
            *(s32 *)(cls->entries + i * 0x20 + 0x1C) = 4;
        }
    }
}
