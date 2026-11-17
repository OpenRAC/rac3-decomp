#include "common.h"

typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_0046A100;

/* localdecomp:start func_L35_0046A100 */
extern E_0046A100 D_L35_002EC3D8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L35_0046A100(void) {
    s32 i = 0;
    s32 n;
    while (D_L35_002EC3D8[i].f0 != 0) {
        switch (D_L35_002EC3D8[i].mode) {
        case 0: {
            E_0046A100 *e = &D_L35_002EC3D8[i];
            u8 v = 0;
            if (func_L01_0041A4F0() || (D_00142BA0[D_L35_002EC3D8[i].c.bit >> 2] & (1 << (D_L35_002EC3D8[i].c.bit & 31)))) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L35_002EC3D8[i].flag = 1;
            n = i + 1;
            for (k = 0; D_L35_002EC3D8[i].c.list[k] != 0; k++) {
                E_0046A100 *e = &D_L35_002EC3D8[i];
                u8 v = 0;
                if (func_L01_0041A4F0() || (e->flag && (D_00142BA0[D_L35_002EC3D8[i].c.list[k] >> 2] & (1 << (D_L35_002EC3D8[i].c.list[k] & 31))))) v = 1;
                e->flag = v;
            }
            break;
        }
        case 2: {
            E_0046A100 *e = &D_L35_002EC3D8[i];
            n = i + 1;
            e->flag = (D_00142BA0[D_L35_002EC3D8[i].c.bit >> 2] & (1 << (D_L35_002EC3D8[i].c.bit & 31))) != 0;
            break;
        }
        case 3: {
            E_0046A100 *e = &D_L35_002EC3D8[i];
            n = i + 1;
            e->flag = D_00142693[0] != 0;
            e->flag = func_L01_0041A4F0();
            break;
        }
        case 4:
        default: {
            E_0046A100 *e = &D_L35_002EC3D8[i];
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
/* localdecomp:end func_L35_0046A100 */
