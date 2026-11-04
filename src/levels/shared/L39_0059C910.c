#include "common.h"

typedef struct {
    u32 data;
    u16 address;
    u8 width;
    u8 height;
} TextureEntry_0059C910;
typedef struct {
    u32 palette;
    s16 zero;
    s16 paletteAddress;
    u32 image;
    u8 width;
    u8 height;
    s16 imageAddress;
} Upload_0059C910;
typedef struct { s32 w0; s32 w4; u8 p8[0x38]; } Cfg_0059C910;

/* localdecomp:start func_L39_0059C910 */
extern s32 *D_L39_0024BD00;
extern TextureEntry_0059C910 *D_L39_0024BD04;
extern TextureEntry_0059C910 *D_L39_0024BD08;
extern s32 D_L39_0024B9FC;
extern Upload_0059C910 D_L39_0025D9C0[];
extern s32 D_L39_002402F0;
extern s32 D_001D4BE0;

extern Cfg_0059C910 D_001FC450;

unsigned long func_L39_0059C910(int index)
{
    int queued = 0;
    short *pair = (short *)((index << 2) + (u32)D_L39_0024BD00);
    TextureEntry_0059C910 *palette = D_L39_0024BD08 + pair[0];
    TextureEntry_0059C910 *image = D_L39_0024BD04 + pair[1];
    int shift, format;
    unsigned long result;
    unsigned long paletteWord;

    if (!palette->address || !image->address) {
        Upload_0059C910 *slot = D_L39_0025D9C0 + D_L39_0024B9FC;
        slot->palette = palette->data;
        slot->zero = 0;
        slot->paletteAddress = 0x3ff0;
        D_L39_0025D9C0[D_L39_0024B9FC].image = palette->data;
        slot->width = 5;
        slot->height = 5;
        slot->imageAddress = 0x3ff0;
    }
    if (!palette->address) {
        palette->address = D_L39_002402F0 >> 8;
        D_001D4BE0 = D_L39_002402F0 + 0x400;
        if (D_L39_0024B9FC < 64) {
            Upload_0059C910 *slot = D_L39_0025D9C0 + D_L39_0024B9FC;
            queued = 1;
            slot->palette = palette->data;
            slot->zero = 0;
            slot->paletteAddress = palette->address;
        }
    }
    if (!image->address) {
        int base = D_001D4BE0;
        u8 ih = image->height;
        u8 iw = image->width;
        image->address = base >> 8;
        if (ih < iw) {
            ih += iw - ih;
        }
        D_001D4BE0 = base + (1 << (ih * 2));
        if (D_L39_0024B9FC < 64) {
            Upload_0059C910 *slot = D_L39_0025D9C0 + D_L39_0024B9FC;
            queued = 1;
            *(u32 *)((u8 *)D_L39_0025D9C0 + D_L39_0024B9FC * 16 + 8) = image->data;
            slot->width = image->width;
            slot->height = image->height;
            slot->imageAddress = image->address;
        }
    }
    if (queued)
        D_L39_0024B9FC++;
    shift = image->width - 6;
    if (shift < 0)
        shift = 0;
    shift = 1 << shift;
    format = 0x13;
    if (image->address < (D_001FC450.w4 >> 8))
        format = 0x1b;
    result = image->address | ((unsigned long)shift << 14);
    result |= (unsigned long)format << 20;
    result |= (unsigned long)image->width << 26;
    result |= (unsigned long)image->height << 30;
    paletteWord = (unsigned long)palette->address << 37;
    paletteWord |= (unsigned long)0x8000 << 19;
    result |= paletteWord;
    return result | 0x8000000000000000UL;
}
/* localdecomp:end func_L39_0059C910 */
