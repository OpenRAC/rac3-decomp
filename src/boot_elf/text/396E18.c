#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 396D48.c's earlier functions */
typedef struct { s16 a; s16 b; } P_392108;

/* localdecomp:start func_00396E18 */
typedef struct {
    void *data;
    u16 address;
    u8 width;
    u8 height;
} Tex_00396E18;
typedef struct {
    void *clut;
    u16 zero;
    u16 clutAddress;
    void *image;
    u8 width;
    u8 height;
    u16 address;
} Upload_00396E18;
extern s32 D_001D9BFC;
extern s32 D_001D4BB0;
extern P_392108 *D_001D9EA8_00396E18;
extern Tex_00396E18 *D_001D9EAC_00396E18;
extern Tex_00396E18 *D_001D9EB0_00396E18;
extern s32 D_001A1ED4[];
extern Upload_00396E18 D_00225C00[];
unsigned long func_00396E18(s32 index) {
    P_392108 *p = (P_392108 *)((index << 2) + (s32)D_001D9EA8_00396E18);
    Tex_00396E18 *clut = &D_001D9EB0_00396E18[p->a];
    Tex_00396E18 *image = &D_001D9EAC_00396E18[p->b];
    s32 added = 0;
    s32 width;
    s32 format;
    unsigned long result, palette;

    if (!clut->address || !image->address) {
        Upload_00396E18 *u = &D_00225C00[D_001D9BFC];
        u->clut = clut->data;
        u->zero = 0;
        u->clutAddress = 0x3FF0;
        D_00225C00[D_001D9BFC].image = clut->data;
        u->width = 5;
        u->height = 5;
        u->address = 0x3FF0;
    }
    if (!clut->address) {
        s32 top = D_001D4BB0;
        clut->address = top >> 8;
        D_001D4BB0 = top + 0x400;
        if (D_001D9BFC < 64) {
            Upload_00396E18 *u = &D_00225C00[D_001D9BFC];
            u->clut = clut->data;
            u->zero = 0;
            u->clutAddress = clut->address;
            added = 1;
        }
    }
    if (!image->address) {
        s32 top = D_001D4BB0;
        u8 size;
        image->address = top >> 8;
        size = image->height < image->width ? image->width : image->height;
        D_001D4BB0 = top + (1 << (size * 2));
        if (D_001D9BFC < 64) {
            Upload_00396E18 *u = &D_00225C00[D_001D9BFC];
            D_00225C00[D_001D9BFC].image = image->data;
            u->width = image->width;
            u->height = image->height;
            u->address = image->address;
            added = 1;
        }
    }
    if (added) D_001D9BFC++;
    width = image->width - 6;
    if (width < 0) width = 0;
    width = 1 << width;
    format = image->address < (D_001A1ED4[0] >> 8) ? 27 : 19;
    result = image->address | ((unsigned long)width << 14) |
        ((unsigned long)format << 20) | ((unsigned long)image->width << 26) |
        ((unsigned long)image->height << 30);
    palette = ((unsigned long)clut->address << 37) | (0x8000UL << 19);
    return result | palette | ((unsigned long)-1 << 63);
}
/* localdecomp:end func_00396E18 */
