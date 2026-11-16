/* PAL near miss (Codex wave 7): near miss: 93 words differ with the file's flags.
 * Worker's note: 93 diff, w364/396E18-final.log; prologue exact through first address check. Upload queue register allocation, absolute-counter increment, unsigned-max lowering and 64-bit return packing remain. Eight attempts with fixed flags.
 */
#include "common.h"
/* localdecomp:start func_00396E18 */
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
typedef struct Count_00396E18 { s32 value; u8 pad[12]; } Count_00396E18;
extern Count_00396E18 D_001D9BFC;
extern s32 D_001D4BB0[];
extern s32 D_001D4BB0_00396E18;
extern s32 D_001A1ED4[];
extern Upload_00396E18 D_00225C00[];
unsigned long func_00396E18(s32 index)
{
    P_392108 *p = (P_392108 *)((index << 2) + (s32)D_001D9EA8[0]);
    Image_00396E18 *clut = (Image_00396E18 *)&D_001D9EB0[0][p->a];
    Image_00396E18 *image = (Image_00396E18 *)&D_001D9EAC[0][p->b];
    s32 added = 0;
    u32 dimension;
    s32 width;
    s32 format;
    unsigned long result, palette;
    if (!clut->address || !image->address) {
        D_00225C00[D_001D9BFC.value].clut = clut->data;
        D_00225C00[D_001D9BFC.value].zero = 0;
        D_00225C00[D_001D9BFC.value].clutAddress = 0x3FF0;
        D_00225C00[D_001D9BFC.value].image = clut->data;
        D_00225C00[D_001D9BFC.value].width = 5;
        D_00225C00[D_001D9BFC.value].height = 5;
        D_00225C00[D_001D9BFC.value].address = 0x3FF0;
    }
    if (!clut->address) {
        s32 top = D_001D4BB0[0];
        clut->address = top >> 8;
        D_001D4BB0_00396E18 = top + 0x400;
        if (D_001D9BFC.value < 64) {
            D_00225C00[D_001D9BFC.value].clut = clut->data;
            D_00225C00[D_001D9BFC.value].zero = 0;
            D_00225C00[D_001D9BFC.value].clutAddress = clut->address;
            added = 1;
        }
    }
    if (!image->address) {
        s32 top = D_001D4BB0_00396E18;
        dimension = image->height;
        image->address = top >> 8;
        if (dimension < image->width) dimension = image->width;
        D_001D4BB0_00396E18 = top + (1 << (dimension * 2));
        if (D_001D9BFC.value < 64) {
            D_00225C00[D_001D9BFC.value].image = image->data;
            D_00225C00[D_001D9BFC.value].width = image->width;
            D_00225C00[D_001D9BFC.value].height = image->height;
            D_00225C00[D_001D9BFC.value].address = image->address;
            added = 1;
        }
    }
    if (added) D_001D9BFC.value++;
    width = image->width - 6;
    if (width < 0) width = 0;
    format = image->address < (D_001A1ED4[0] >> 8) ? 27 : 19;
    result = image->address | ((unsigned long)(1 << width) << 14) |
        ((unsigned long)format << 20) | ((unsigned long)image->width << 26) |
        ((unsigned long)image->height << 30);
    palette = ((unsigned long)clut->address << 37) | (0x8000UL << 19);
    return result | palette | ((unsigned long)-1 << 63);
}
/* localdecomp:end func_00396E18 */
