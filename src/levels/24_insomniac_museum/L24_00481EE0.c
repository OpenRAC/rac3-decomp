#include "common.h"

/* localdecomp:start func_L24_00481EE0 */
typedef struct S_00481EE0 {
    s32 a0;
    s32 a4;
    s32 a8;
    u32 c;
    s32 kind;
    u8 flag;
} S_00481EE0;
extern S_00481EE0 D_L24_002EA268[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
s32 func_L01_0041A4F0(void);

/* same shape as func_L08_0047F170 and func_L32_00473368 */
void func_L24_00481EE0(void) {
    s32 i;
    s32 j;
    for (i = 0; D_L24_002EA268[i].a0 != 0; i++) {
        switch (D_L24_002EA268[i].kind) {
        case 0:
            D_L24_002EA268[i].flag = (D_00142BA0[D_L24_002EA268[i].c >> 2] & (1 << (D_L24_002EA268[i].c & 0x1F))) || func_L01_0041A4F0();
            break;
        case 1:
            D_L24_002EA268[i].flag = 0;
            for (j = 0; ((u32 *)D_L24_002EA268[i].c)[j] != 0; j++) {
                D_L24_002EA268[i].flag = D_L24_002EA268[i].flag ||
                    (D_00142BA0[((u32 *)D_L24_002EA268[i].c)[j] >> 2] & (1 << (((u32 *)D_L24_002EA268[i].c)[j] & 0x1F))) ||
                    func_L01_0041A4F0();
            }
            break;
        case 2:
            D_L24_002EA268[i].flag = (D_00142BA0[D_L24_002EA268[i].c >> 2] & (1 << (D_L24_002EA268[i].c & 0x1F))) || func_L01_0041A4F0();
            break;
        case 3:
            D_L24_002EA268[i].flag = D_00142693[0] || func_L01_0041A4F0();
            break;
        case 4:
        default:
            D_L24_002EA268[i].flag = D_00142693[0] || func_L01_0041A4F0();
            break;
        }
    }
}
/* localdecomp:end func_L24_00481EE0 */
