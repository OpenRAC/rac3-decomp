#include "common.h"

/* localdecomp:start func_L35_0046B230 */
/* same code as func_L32_00473368 (level 32, func_L34_00470F18 in level 34) */
typedef struct S_0046B230 {
    s32 a0;
    s32 a4;
    s32 a8;
    u32 c;
    s32 kind;
    u8 flag;
} S_0046B230;
extern S_0046B230 D_L35_002EC868[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
s32 func_L01_0041A4F0(void);

void func_L35_0046B230(void) {
    s32 i;
    s32 j;
    for (i = 0; D_L35_002EC868[i].a0 != 0; i++) {
        switch (D_L35_002EC868[i].kind) {
        case 0:
            D_L35_002EC868[i].flag = (D_00142BA0[D_L35_002EC868[i].c >> 2] & (1 << (D_L35_002EC868[i].c & 0x1F))) || func_L01_0041A4F0();
            break;
        case 1:
            D_L35_002EC868[i].flag = 0;
            for (j = 0; ((u32 *)D_L35_002EC868[i].c)[j] != 0; j++) {
                D_L35_002EC868[i].flag = D_L35_002EC868[i].flag ||
                    (D_00142BA0[((u32 *)D_L35_002EC868[i].c)[j] >> 2] & (1 << (((u32 *)D_L35_002EC868[i].c)[j] & 0x1F))) ||
                    func_L01_0041A4F0();
            }
            break;
        case 2:
            D_L35_002EC868[i].flag = (D_00142BA0[D_L35_002EC868[i].c >> 2] & (1 << (D_L35_002EC868[i].c & 0x1F))) || func_L01_0041A4F0();
            break;
        case 3:
            D_L35_002EC868[i].flag = D_00142693[0] || func_L01_0041A4F0();
            break;
        case 4:
        default:
            D_L35_002EC868[i].flag = D_00142693[0] || func_L01_0041A4F0();
            break;
        }
    }
}
/* localdecomp:end func_L35_0046B230 */
