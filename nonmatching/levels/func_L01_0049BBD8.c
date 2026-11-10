/* Level 01. 106 diff of 170, default flags. Same table walk as the matched func_L01_0049DE10 (table D_L01_002EBED8) with calls to func_L01_0041A4F0. Case bodies match retail; open: retail keeps n = i+1 in $s3 separate from i ($s2) and ends each case with "move $s2,$s3", and case 1 reuses $s2 for v; gcc coalesces n into i. Delete the INCLUDE_RODATA jtbl line when integrating. */
#include "common.h"

typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_9BBD8;
extern E_9BBD8 D_L01_002EBED8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L01_0049BBD8(void) {
    s32 i = 0;
    s32 n;
    while (D_L01_002EBED8[i].f0 != 0) {
        switch (D_L01_002EBED8[i].mode) {
        case 0: {
            E_9BBD8 *e = &D_L01_002EBED8[i];
            u8 v = 0;
            if (func_L01_0041A4F0() || (D_00142BA0[D_L01_002EBED8[i].c.bit >> 2] & (1 << (D_L01_002EBED8[i].c.bit & 31)))) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            E_9BBD8 *e = &D_L01_002EBED8[i];
            s32 k;
            e->flag = 1;
            n = i + 1;
            for (k = 0; D_L01_002EBED8[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (func_L01_0041A4F0() || (e->flag && (D_00142BA0[D_L01_002EBED8[i].c.list[k] >> 2] & (1 << (D_L01_002EBED8[i].c.list[k] & 31))))) v = 1;
                e->flag = v;
            }
            break;
        }
        case 2: {
            E_9BBD8 *e = &D_L01_002EBED8[i];
            n = i + 1;
            e->flag = (D_00142BA0[D_L01_002EBED8[i].c.bit >> 2] & (1 << (D_L01_002EBED8[i].c.bit & 31))) != 0;
            break;
        }
        case 3: {
            E_9BBD8 *e = &D_L01_002EBED8[i];
            n = i + 1;
            e->flag = D_00142693[0] != 0;
            e->flag = func_L01_0041A4F0();
            break;
        }
        case 4:
        default: {
            E_9BBD8 *e = &D_L01_002EBED8[i];
            if (e->f0 == 0x1C3) {
                n = i + 1;
                e->flag = 1;
            } else {
                n = i + 1;
                e->flag = D_00142693[0] != 0;
                e->flag = func_L01_0041A4F0();
            }
            break;
        }
        }
        i = n;
    }
}
