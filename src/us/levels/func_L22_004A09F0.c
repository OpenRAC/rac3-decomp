#include "common.h"

/* NTSC-U counterpart of func_L22_004A43D8 (src/levels/22_mylon/L22_004A43D8.c) */
/* localdecomp:start func_L22_004A09F0 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_4A43D8;
extern E_4A43D8 D_L22_002EE188[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_001D93C8_sda;
__asm__(".extern D_001D93C8_sda, 4");

void func_L22_004A09F0(void) {
    s32 i = 0;
    s32 n;
    while (D_L22_002EE188[i].f0 != 0) {
        switch (D_L22_002EE188[i].mode) {
        case 1: {
            s32 k;
            D_L22_002EE188[i].flag = 1;
            n = i + 1;
            for (k = 0; D_L22_002EE188[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if ((D_L22_002EE188[i].flag && (D_00142BA0[D_L22_002EE188[i].c.list[k] >> 2] & (1 << (D_L22_002EE188[i].c.list[k] & 31)))) || D_001D93C8_sda) v = 1;
                D_L22_002EE188[i].flag = v;
            }
            break;
        }
        case 0:
        case 2: {
            E_4A43D8 *e = &D_L22_002EE188[i];
            u8 v = 0;
            if ((D_00142BA0[D_L22_002EE188[i].c.bit >> 2] & (1 << (D_L22_002EE188[i].c.bit & 31))) || D_001D93C8_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3: {
            E_4A43D8 *e = &D_L22_002EE188[i];
            u8 v = 0;
            if (D_00142693[0] || D_001D93C8_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 4:
        default:
            D_L22_002EE188[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L22_004A09F0 */
