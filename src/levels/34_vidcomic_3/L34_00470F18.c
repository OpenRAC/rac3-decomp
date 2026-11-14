#include "common.h"

/* localdecomp:start func_L34_00470F18 */
/* same code as func_L32_00473368 (level 32) */
typedef struct S_00470F18 {
    s32 a0;
    s32 a4;
    s32 a8;
    u32 c;
    s32 kind;
    u8 flag;
} S_00470F18;
extern S_00470F18 D_L34_002EC7A8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
s32 func_L01_0041A4F0(void);

void func_L34_00470F18(void) {
    s32 i;
    s32 j;
    for (i = 0; D_L34_002EC7A8[i].a0 != 0; i++) {
        switch (D_L34_002EC7A8[i].kind) {
        case 0:
            D_L34_002EC7A8[i].flag = (D_00142BA0[D_L34_002EC7A8[i].c >> 2] & (1 << (D_L34_002EC7A8[i].c & 0x1F))) || func_L01_0041A4F0();
            break;
        case 1:
            D_L34_002EC7A8[i].flag = 0;
            for (j = 0; ((u32 *)D_L34_002EC7A8[i].c)[j] != 0; j++) {
                D_L34_002EC7A8[i].flag = D_L34_002EC7A8[i].flag ||
                    (D_00142BA0[((u32 *)D_L34_002EC7A8[i].c)[j] >> 2] & (1 << (((u32 *)D_L34_002EC7A8[i].c)[j] & 0x1F))) ||
                    func_L01_0041A4F0();
            }
            break;
        case 2:
            D_L34_002EC7A8[i].flag = (D_00142BA0[D_L34_002EC7A8[i].c >> 2] & (1 << (D_L34_002EC7A8[i].c & 0x1F))) || func_L01_0041A4F0();
            break;
        case 3:
            D_L34_002EC7A8[i].flag = D_00142693[0] || func_L01_0041A4F0();
            break;
        case 4:
        default:
            D_L34_002EC7A8[i].flag = D_00142693[0] || func_L01_0041A4F0();
            break;
        }
    }
}
/* localdecomp:end func_L34_00470F18 */
