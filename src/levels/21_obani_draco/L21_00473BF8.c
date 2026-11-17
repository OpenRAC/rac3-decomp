#include "common.h"

typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_47C860;

/* localdecomp:start func_L21_00473BF8 */
/* PAL port of the NTSC-U match src/us/levels/func_L21_00470418.c */

extern E_47C860 D_L21_002F4E88[];
extern u32 D_142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0();

void func_L21_00473BF8(void) {
    s32 i = 0;
    s32 n;
    while (D_L21_002F4E88[i].f0 != 0) {
        switch (D_L21_002F4E88[i].mode) {
        case 0: {
            E_47C860 *e = &D_L21_002F4E88[i];
            u8 v = 0;
            if ((D_142BA0[D_L21_002F4E88[i].c.bit >> 2] & (1 << (D_L21_002F4E88[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L21_002F4E88[i].flag = 0;
            n = i + 1;
            for (k = 0; D_L21_002F4E88[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L21_002F4E88[i].flag || (D_142BA0[D_L21_002F4E88[i].c.list[k] >> 2] & (1 << (D_L21_002F4E88[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L21_002F4E88[i].flag = v;
            }
            break;
        }
        case 2: {
            E_47C860 *e = &D_L21_002F4E88[i];
            u8 v = 0;
            if ((D_142BA0[D_L21_002F4E88[i].c.bit >> 2] & (1 << (D_L21_002F4E88[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            do { n = i + 1; } while (0);
            break;
        }
        case 3:
        case 4:
        default: {
            E_47C860 *e = &D_L21_002F4E88[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            do { n = i + 1; } while (0);
            break;
        }
        }
        i = n;
    }
}
/* localdecomp:end func_L21_00473BF8 */
