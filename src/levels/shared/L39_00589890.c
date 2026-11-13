#include "common.h"

/* localdecomp:start func_L39_00589890 */
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

__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_002402F0, 16");
__asm__(".extern D_L39_00245BB4, 16");
__asm__(".extern D_L39_0024B9FC, 16");
__asm__(".extern D_L39_0024BA04, 16");
__asm__(".extern D_L39_0024CAD0_b, 4");
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
extern s32 D_L39_002402F0;
extern s32 D_L39_00245BB4;
extern s32 D_L39_0024B9FC;
extern u8 *D_L39_0024BA04;
extern Entry_00589890 D_L39_0025DDC0[];
extern Upload_00589890 D_L39_0025D9C0[];
extern s32 D_001FC450[];
__asm__(".extern D_001D6E30_sda, 4");
extern s32 D_001D6E30_sda;
__asm__(".extern D_001D6E20_sda, 8");
extern unsigned long D_001D6E20_sda;
__asm__(".extern D_001D6E28_sda, 8");
extern unsigned long D_001D6E28_sda;
extern u8 D_1A3A80[];
extern u8 D_1A3D70[];

unsigned long func_L39_00589890(int index)
{
    Entry_00589890 *e;

    if (index < 0) {
        if (index == -5) {
            return ((long)D_001FC450[2] >> 8) | 0x27020000 | 0x640000000L;
        } else if (index == -8) {
            unsigned long t = ((long)D_001FC450[1] >> 8) | 0x25B20000;
            unsigned long u = ((long)D_001D6E30_sda << 37) | 0x640000000L;
            return (t | u) | 0x2000000000000000L;
        } else if (index == -7) {
            return ((long)D_001FC450[0] >> 8) | 0x24020000 | 0x640000000L;
        } else if (index == -6) {
            return ((long)D_001FC450[1] >> 8) | 0x24020000 | 0x640000000L;
        } else if (index == -2 || index == -1) {
            unsigned long r;
            s32 base;
            if (D_001D6E20_sda)
                return D_001D6E20_sda;
            base = (D_L39_002402F0 + 0x1FFF) & -0x2000;
            D_L39_002402F0 = base + 0x20000;
            r = ((base >> 8) | 0x20210000) | 0x600000000L;
            D_L39_0024CAD0[0] = 0x10000003;
            D_L39_0024CAD0[1] = 0;
            D_L39_0024CAD0[2] = 0;
            D_L39_0024CAD0[3] = 0x50000003;
            D_L39_0024CAD0[4] = 0x8001;
            D_L39_0024CAD0[5] = 0x20000000;
            D_L39_0024CAD0[6] = 0xEE;
            D_L39_0024CAD0[7] = 0;
            *(unsigned long *)&D_L39_0024CAD0[8] = (base >> 13) | 0x2040000;
            D_L39_0024CAD0[10] = 0x4D;
            D_L39_0024CAD0[11] = 0;
            *(unsigned long *)&D_L39_0024CAD0[12] = ((long)D_001FC450[1] >> 8) | 0x24020000 | 0x640000000L;
            D_L39_0024CAD0[14] = 7;
            D_L39_0024CAD0[15] = 0;
            D_L39_0024CAD0[16] = 0x3000002F;
            D_L39_0024CAD0[17] = (u32)D_1A3A80;
            D_L39_0024CAD0[18] = 0;
            D_L39_0024CAD0[19] = 0x5000002F;
            D_001D6E20_sda = r;
            D_L39_0024CAD0_b = D_L39_0024CAD0 + 20;
            return r;
        } else if (index == -4 || index == -3) {
            unsigned long r;
            s32 base;
            if (D_001D6E28_sda)
                return D_001D6E28_sda;
            base = (D_L39_002402F0 + 0x1FFF) & -0x2000;
            D_L39_002402F0 = base + 0x2000;
            r = ((base >> 8) | 0x18204000) | 0x580000000L;
            D_L39_0024CAD0[0] = 0x10000003;
            D_L39_0024CAD0[1] = 0;
            D_L39_0024CAD0[2] = 0;
            D_L39_0024CAD0[3] = 0x50000003;
            D_L39_0024CAD0[4] = 0x8002;
            D_L39_0024CAD0[5] = 0x10000000;
            D_L39_0024CAD0[6] = 0xEE;
            D_L39_0024CAD0[7] = 0;
            *(unsigned long *)&D_L39_0024CAD0[8] = (base >> 13) | 0x2010000;
            D_L39_0024CAD0[10] = 0x4D;
            D_L39_0024CAD0[11] = 0;
            *(unsigned long *)&D_L39_0024CAD0[12] = ((long)D_001FC450[1] >> 8) | 0x24020000 | 0x640000000L;
            D_L39_0024CAD0[14] = 7;
            D_L39_0024CAD0[15] = 0;
            D_L39_0024CAD0[16] = 0x3000002F;
            D_L39_0024CAD0[17] = (u32)D_1A3D70;
            D_L39_0024CAD0[18] = 0;
            D_L39_0024CAD0[19] = 0x5000002F;
            D_001D6E28_sda = r;
            D_L39_0024CAD0_b = D_L39_0024CAD0 + 20;
            return r;
        }
    } else {
        e = &D_L39_0025DDC0[index];
        if (e->tex0 == 0) {
            s32 pal, img, shift;
            unsigned long pw;
            shift = e->width - 6;
            if (shift < 0)
                shift = 0;
            pal = D_L39_002402F0 >> 8;
            D_L39_002402F0 += 0x400;
            img = D_L39_002402F0 >> 8;
            D_L39_002402F0 += 1 << (e->width + e->height);
            pw = (unsigned long)pal << 37;
            pw |= 0x8000UL << 19;
            e->tex0 = (img | ((unsigned long)(1 << shift) << 14) | ((unsigned long)e->format << 20) | ((unsigned long)e->width << 26) | ((unsigned long)e->height << 30) | pw) | 0x8000000000000000UL;
            if (0x3FF000 - D_L39_00245BB4 < D_L39_002402F0)
                return e->tex0;
            if (D_L39_0024B9FC < 64) {
                Upload_00589890 *slot = D_L39_0025D9C0 + D_L39_0024B9FC;
                slot->palette = (u32)D_L39_0024BA04 + (e->palette << 6);
                slot->zero = 0;
                slot->paletteAddress = pal;
                ((u32 *)D_L39_0025D9C0)[D_L39_0024B9FC * 4 + 2] = (u32)D_L39_0024BA04 + (e->image << 6);
                slot->width = e->width;
                slot->height = e->height;
                slot->imageAddress = img;
                D_L39_0024B9FC++;
            }
        }
    }
    return D_L39_0025DDC0[index].tex0;
}
/* localdecomp:end func_L39_00589890 */
