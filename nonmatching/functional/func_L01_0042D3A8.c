/* functional: high. The id 10 descriptor is D_L01_001D6D10 (its gp slot moves between levels; the sda name pointed at level 01s slot everywhere). Prior near-miss draft re-verified against the PAL asm; fixed two behaviour bugs in it (pixel pointer is tex+0x420 not +0x20; the original draft constant 0x0040000400004000 for id 10 is correct (dsll 20/19 recomputed)). The retail plzcw is a bit-count loop here (same value, incl. width 0 -> -1); bytes differ a lot, behaviour does not. */
typedef unsigned int Q_0042D3A8 __attribute__((mode(TI)));
typedef struct { s32 count; s32 ids[8], starts[8], slots[8], addresses[8], flags[8]; } Queue_0042D3A8;
typedef struct { s32 unused[2]; s32 width, height; s32 unused10[3]; s32 format; u8 data[0x400]; } Texture_0042D3A8;
typedef struct { u32 unused; s16 width,height,format,base,palette,unusedE; } Record_0042D3A8;
extern u8 D_L01_001FDBD0[];
extern Queue_0042D3A8 D_L01_0021F5E0;
extern s32 D_L01_001E0000_0042D3A8[], D_L01_001E000C_0042D3A8[];
extern s32 D_001D4BB4_0042D3A8[], D_001D4BB0_0042D3A8[];
extern u64 D_001D4BA8_0042D3A8[];
extern u64 D_L01_001F3DC0[];
extern u8 D_L01_001D6D10[];   /* addiu $a2, $gp, -0x5BA0 at level 01: a level .sdata slot that moves per level (01 0x1D6D10, 02 0x1D6BD0, 03 0x1D6D50...), so not a fixed sda name */
extern s32 D_L01_00200670[];
extern u32 D_L01_001FFE70[];
extern s32 D_001A1ED0[];
void func_L01_0042D3A8(s32 id, s32 arg, s32 *data) {
    void func_003A92F0(s32);
    void func_00399D68(s32, void *, void *, s32);
    void func_0012C9A0(void *, s16, s32, s32, s32, s32, s16, s16);
    void func_0011F0A0(s32);
    void func_0012CCC8(void *, void *);
    void func_0012A9F0(s32, s32);
    struct { Q_0042D3A8 head; Record_0042D3A8 rows[15]; } upload;
    u8 packet[96];
    s32 *offsets;
    Texture_0042D3A8 *tex;
    s32 i, count, slotBytes;
    if (D_L01_001FDBD0[id] != 255) return;
    if (D_L01_0021F5E0.count >= 8) return;
    func_003A92F0(1);
    upload.head = 0;
    D_L01_0021F5E0.ids[D_L01_0021F5E0.count] = id;
    D_L01_0021F5E0.starts[D_L01_0021F5E0.count] = D_L01_001E0000_0042D3A8[0];
    D_L01_0021F5E0.slots[D_L01_0021F5E0.count] = D_L01_001E000C_0042D3A8[0];
    D_L01_0021F5E0.addresses[D_L01_0021F5E0.count] = D_001D4BB4_0042D3A8[0];
    D_L01_0021F5E0.flags[D_L01_0021F5E0.count] = 0;
    D_L01_0021F5E0.count++;
    if (id == 10) {
        D_L01_001F3DC0[0] = D_001D4BA8_0042D3A8[0];
        D_L01_001F3DC0[2] = 0x0040000400004000ULL;
        D_L01_001F3DC0[1] = 0xFFA0000000E0ULL;
        func_00399D68(arg, 0, D_L01_001D6D10, id);
        D_L01_00200670[D_L01_001E0000_0042D3A8[0] - 1] = 0xFFFC0000;
        return;
    }
    slotBytes = D_L01_001E000C_0042D3A8[0] * 16;
    if (data) {
        offsets = data;
        count = *offsets++;
        for (i = 0; i < count; i++, offsets++) {
            s32 exponent, amount;
            u32 n;
            tex = (Texture_0042D3A8 *)((u8 *)data + *offsets);
            ((u8 *)&upload.head)[i] = D_L01_001E000C_0042D3A8[0];
            D_L01_001FFE70[D_L01_001E000C_0042D3A8[0]] = (u32)tex + 0x420;
            n = tex->width < 0 ? ~tex->width : tex->width;
            exponent = -1;
            while (n != 0) { exponent++; n >>= 1; }
            D_L01_001FFE70[D_L01_001E000C_0042D3A8[0]] += exponent << 28;
            if (D_L01_001E000C_0042D3A8[0] < 256) D_L01_001E000C_0042D3A8[0]++;
            upload.rows[i].width = tex->width;
            upload.rows[i].height = tex->height;
            upload.rows[i].format = tex->format;
            if (upload.rows[i].format >= 4) upload.rows[i].format = 3;
            func_0012C9A0(packet, D_001D4BB4_0042D3A8[0] >> 8, 1, 0, 0, 0, 16, 16);
            func_0011F0A0(0);
            func_0012CCC8(packet, (u8 *)tex + 0x20);
            func_0012A9F0(0, 0);
            upload.rows[i].base = (D_001D4BB4_0042D3A8[0] - D_001A1ED0[8]) >> 8;
            D_001D4BB4_0042D3A8[0] += 0x400;
            if (tex->format >= 3) {
                func_0012C9A0(packet, D_001D4BB4_0042D3A8[0] >> 8, 1, 19, 0, 0, tex->width >> 2, tex->height >> 2);
                func_0011F0A0(0);
                func_0012CCC8(packet, (u8 *)tex + 0x420 + ((tex->width * tex->height * 5) >> 2));
                func_0012A9F0(0, 0);
                upload.rows[i].palette = (D_001D4BB4_0042D3A8[0] - D_001A1ED0[8]) >> 8;
                upload.rows[i].unusedE = 0;
                amount = (tex->width * tex->height) >> 4;
                D_001D4BB4_0042D3A8[0] += amount > 255 ? amount : 256;
            }
        }
        D_001D4BB0_0042D3A8[0] = D_001D4BB4_0042D3A8[0];
    }
    func_00399D68(arg, (u8 *)upload.rows - slotBytes, &upload.head, id);
}
