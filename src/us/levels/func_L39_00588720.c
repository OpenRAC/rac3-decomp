#include "common.h"

/* NTSC-U counterpart of func_L39_00589890 (src/levels/shared/L39_00589890.c) */
/* localdecomp:start func_L39_00588720 */
typedef struct {
    unsigned long tex0;
    u16 image;
    u16 palette;
    u8 width;
    u8 height;
    s16 format;
} Entry_00589890;
typedef struct {
    u32 palette;
    s16 zero;
    s16 paletteAddress;
    u32 image;
    u8 width;
    u8 height;
    s16 imageAddress;
} Upload_00589890;

__asm__(".extern D_L39_0024CBD0, 16");
__asm__(".extern D_L39_00240470, 16");
__asm__(".extern D_L39_00245D34, 16");
__asm__(".extern D_L39_0024BAFC, 16");
__asm__(".extern D_L39_0024BB04, 16");
__asm__(".extern D_L39_0024CBD0_b, 4");
extern u32 *D_L39_0024CBD0;
extern u32 *D_L39_0024CBD0_b;
extern s32 D_L39_00240470;
extern s32 D_L39_00245D34;
extern s32 D_L39_0024BAFC;
extern u8 *D_L39_0024BB04;
extern Entry_00589890 D_L39_0025DEC0[];
extern Upload_00589890 D_L39_0025DAC0[];
extern s32 D_L39_001FC5D0[];
__asm__(".extern D_001D6E30_sda_00588720, 4");
extern s32 D_001D6E30_sda_00588720;
__asm__(".extern D_001D6E20_sda_00588720, 8");
extern unsigned long D_001D6E20_sda_00588720;
__asm__(".extern D_001D6E28_sda_00588720, 8");
extern unsigned long D_001D6E28_sda_00588720;
extern u8 D_001A3C00[];
extern u8 D_001A3EF0[];

unsigned long func_L39_00588720(int index)
{
    Entry_00589890 *e;

    if (index < 0) {
        if (index == -5) {
            return ((long)D_L39_001FC5D0[2] >> 8) | 0x27020000 | 0x640000000L;
        } else if (index == -8) {
            unsigned long t = ((long)D_L39_001FC5D0[1] >> 8) | 0x25B20000;
            unsigned long u = ((long)D_001D6E30_sda_00588720 << 37) | 0x640000000L;
            return (t | u) | 0x2000000000000000L;
        } else if (index == -7) {
            return ((long)D_L39_001FC5D0[0] >> 8) | 0x24020000 | 0x640000000L;
        } else if (index == -6) {
            return ((long)D_L39_001FC5D0[1] >> 8) | 0x24020000 | 0x640000000L;
        } else if (index == -2 || index == -1) {
            unsigned long r;
            s32 base;
            if (D_001D6E20_sda_00588720)
                return D_001D6E20_sda_00588720;
            base = (D_L39_00240470 + 0x1FFF) & -0x2000;
            D_L39_00240470 = base + 0x20000;
            r = ((base >> 8) | 0x20210000) | 0x600000000L;
            D_L39_0024CBD0[0] = 0x10000003;
            D_L39_0024CBD0[1] = 0;
            D_L39_0024CBD0[2] = 0;
            D_L39_0024CBD0[3] = 0x50000003;
            D_L39_0024CBD0[4] = 0x8001;
            D_L39_0024CBD0[5] = 0x20000000;
            D_L39_0024CBD0[6] = 0xEE;
            D_L39_0024CBD0[7] = 0;
            *(unsigned long *)&D_L39_0024CBD0[8] = (base >> 13) | 0x2040000;
            D_L39_0024CBD0[10] = 0x4D;
            D_L39_0024CBD0[11] = 0;
            *(unsigned long *)&D_L39_0024CBD0[12] = ((long)D_L39_001FC5D0[1] >> 8) | 0x24020000 | 0x640000000L;
            D_L39_0024CBD0[14] = 7;
            D_L39_0024CBD0[15] = 0;
            D_L39_0024CBD0[16] = 0x3000002F;
            D_L39_0024CBD0[17] = (u32)D_001A3C00;
            D_L39_0024CBD0[18] = 0;
            D_L39_0024CBD0[19] = 0x5000002F;
            D_001D6E20_sda_00588720 = r;
            D_L39_0024CBD0_b = D_L39_0024CBD0 + 20;
            return r;
        } else if (index == -4 || index == -3) {
            unsigned long r;
            s32 base;
            if (D_001D6E28_sda_00588720)
                return D_001D6E28_sda_00588720;
            base = (D_L39_00240470 + 0x1FFF) & -0x2000;
            D_L39_00240470 = base + 0x2000;
            r = ((base >> 8) | 0x18204000) | 0x580000000L;
            D_L39_0024CBD0[0] = 0x10000003;
            D_L39_0024CBD0[1] = 0;
            D_L39_0024CBD0[2] = 0;
            D_L39_0024CBD0[3] = 0x50000003;
            D_L39_0024CBD0[4] = 0x8002;
            D_L39_0024CBD0[5] = 0x10000000;
            D_L39_0024CBD0[6] = 0xEE;
            D_L39_0024CBD0[7] = 0;
            *(unsigned long *)&D_L39_0024CBD0[8] = (base >> 13) | 0x2010000;
            D_L39_0024CBD0[10] = 0x4D;
            D_L39_0024CBD0[11] = 0;
            *(unsigned long *)&D_L39_0024CBD0[12] = ((long)D_L39_001FC5D0[1] >> 8) | 0x24020000 | 0x640000000L;
            D_L39_0024CBD0[14] = 7;
            D_L39_0024CBD0[15] = 0;
            D_L39_0024CBD0[16] = 0x3000002F;
            D_L39_0024CBD0[17] = (u32)D_001A3EF0;
            D_L39_0024CBD0[18] = 0;
            D_L39_0024CBD0[19] = 0x5000002F;
            D_001D6E28_sda_00588720 = r;
            D_L39_0024CBD0_b = D_L39_0024CBD0 + 20;
            return r;
        }
    } else {
        e = &D_L39_0025DEC0[index];
        if (e->tex0 == 0) {
            s32 pal, img, shift;
            unsigned long pw;
            shift = e->width - 6;
            if (shift < 0)
                shift = 0;
            pal = D_L39_00240470 >> 8;
            D_L39_00240470 += 0x400;
            img = D_L39_00240470 >> 8;
            D_L39_00240470 += 1 << (e->width + e->height);
            pw = (unsigned long)pal << 37;
            pw |= 0x8000UL << 19;
            e->tex0 = (img | ((unsigned long)(1 << shift) << 14) | ((unsigned long)e->format << 20) | ((unsigned long)e->width << 26) | ((unsigned long)e->height << 30) | pw) | 0x8000000000000000UL;
            if (0x3FF000 - D_L39_00245D34 < D_L39_00240470)
                return e->tex0;
            if (D_L39_0024BAFC < 64) {
                Upload_00589890 *slot = D_L39_0025DAC0 + D_L39_0024BAFC;
                slot->palette = (u32)D_L39_0024BB04 + (e->palette << 6);
                slot->zero = 0;
                slot->paletteAddress = pal;
                ((u32 *)D_L39_0025DAC0)[D_L39_0024BAFC * 4 + 2] = (u32)D_L39_0024BB04 + (e->image << 6);
                slot->width = e->width;
                slot->height = e->height;
                slot->imageAddress = img;
                D_L39_0024BAFC++;
            }
        }
    }
    return D_L39_0025DEC0[index].tex0;
}
/* localdecomp:end func_L39_00588720 */
