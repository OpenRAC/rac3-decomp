#include "common.h"

/* NTSC-U counterpart of func_L05_004972F8 (src/levels/05_daxx/L05_004972F8.c) */
/* localdecomp:start func_L05_004933D8 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_4972F8;
extern E_4972F8 D_L05_002EF248[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_001D9448_sda;
__asm__(".extern D_001D9448_sda, 4");

void func_L05_004933D8(void) {
    s32 i = 0;
    s32 n;
    while (D_L05_002EF248[i].f0 != 0) {
        switch (D_L05_002EF248[i].mode) {
        case 1: {
            s32 k;
            D_L05_002EF248[i].flag = 1;
            n = i + 1;
            for (k = 0; D_L05_002EF248[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if ((D_L05_002EF248[i].flag && (D_00142BA0[D_L05_002EF248[i].c.list[k] >> 2] & (1 << (D_L05_002EF248[i].c.list[k] & 31)))) || D_001D9448_sda) v = 1;
                D_L05_002EF248[i].flag = v;
            }
            break;
        }
        case 0:
        case 2: {
            E_4972F8 *e = &D_L05_002EF248[i];
            u8 v = 0;
            if ((D_00142BA0[D_L05_002EF248[i].c.bit >> 2] & (1 << (D_L05_002EF248[i].c.bit & 31))) || D_001D9448_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3: {
            E_4972F8 *e = &D_L05_002EF248[i];
            u8 v = 0;
            if (D_00142693[0] || D_001D9448_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 4:
        default:
            D_L05_002EF248[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L05_004933D8 */
