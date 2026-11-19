/* functional: high. Texture residency: for sprite/image slot `index` (two 16-bit indices into two 8-byte tables {data, address, w, h}), allocates GS memory for the CLUT and/or image if they have no address yet (address = top>>8, top advances by 0x400 for a CLUT or 1<<(2*max(w,h)) for an image), queues an upload entry in D_00225C00[count] (16 bytes, up to 64) and returns the packed 64-bit GS TEX0-style value. Verified block by block against PAL asm (the 0x3FF0 scratch entry write is unconditional, even when count>=64, as retail). */
typedef struct Image_00396E18 {
    void *data;
    u16 address;
    u8 width, height;
} Image_00396E18;
typedef struct Upload_00396E18 {
    void *clut;
    u16 zero, clutAddress;
    void *image;
    u8 width, height;
    u16 address;
} Upload_00396E18;
typedef struct { s16 a, b; } Idx_00396E18;
extern Idx_00396E18 *D_001D9EA8;
extern Image_00396E18 *D_001D9EB0;
extern Image_00396E18 *D_001D9EAC;
extern s32 D_001D9BFC;
extern s32 D_001D4BB0;
extern s32 D_001A1ED4;
extern Upload_00396E18 D_00225C00[];

unsigned long func_00396E18(s32 index)
{
    Idx_00396E18 *p = D_001D9EA8 + index;
    Image_00396E18 *clut = &D_001D9EB0[p->a];
    Image_00396E18 *image = &D_001D9EAC[p->b];
    s32 added = 0;
    u32 dimension;
    s32 width;
    s32 format;
    unsigned long result, palette;

    if (!clut->address || !image->address) {
        D_00225C00[D_001D9BFC].clut = clut->data;
        D_00225C00[D_001D9BFC].zero = 0;
        D_00225C00[D_001D9BFC].clutAddress = 0x3FF0;
        D_00225C00[D_001D9BFC].image = clut->data;
        D_00225C00[D_001D9BFC].width = 5;
        D_00225C00[D_001D9BFC].height = 5;
        D_00225C00[D_001D9BFC].address = 0x3FF0;
    }
    if (!clut->address) {
        s32 top = D_001D4BB0;
        clut->address = top >> 8;
        D_001D4BB0 = top + 0x400;
        if (D_001D9BFC < 64) {
            D_00225C00[D_001D9BFC].clut = clut->data;
            D_00225C00[D_001D9BFC].zero = 0;
            D_00225C00[D_001D9BFC].clutAddress = clut->address;
            added = 1;
        }
    }
    if (!image->address) {
        s32 top = D_001D4BB0;
        dimension = image->height;
        image->address = top >> 8;
        if (dimension < image->width) {
            dimension = image->width;
        }
        D_001D4BB0 = top + (1 << (dimension * 2));
        if (D_001D9BFC < 64) {
            D_00225C00[D_001D9BFC].image = image->data;
            D_00225C00[D_001D9BFC].width = image->width;
            D_00225C00[D_001D9BFC].height = image->height;
            D_00225C00[D_001D9BFC].address = image->address;
            added = 1;
        }
    }
    if (added) {
        D_001D9BFC++;
    }
    width = image->width - 6;
    if (width < 0) {
        width = 0;
    }
    format = image->address < (D_001A1ED4 >> 8) ? 27 : 19;
    result = image->address | ((unsigned long)(1 << width) << 14) |
        ((unsigned long)format << 20) | ((unsigned long)image->width << 26) |
        ((unsigned long)image->height << 30);
    palette = ((unsigned long)clut->address << 37) | (0x8000UL << 19);
    return result | palette | ((unsigned long)-1 << 63);
}
