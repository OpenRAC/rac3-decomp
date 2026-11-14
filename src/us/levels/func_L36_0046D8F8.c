#include "common.h"

/* NTSC-U counterpart of func_L36_00470E10 (src/levels/36_vidcomic_1_special_edition/L36_00470E10.c) */
/* localdecomp:start func_L36_0046D8F8 */
typedef struct S_4961F0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_4961F0;
extern S_4961F0 D_L36_002EC9F8[];
__asm__(".extern D_L36_002EC9F8, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_00417EA0(void);

void func_L36_0046D8F8(void) {
    int i;
    int j;
    int n;
    i = 0;
    while (D_L36_002EC9F8[i].a0) {
        switch (D_L36_002EC9F8[i].kind) {
        case 0:
            D_L36_002EC9F8[i].flag = (D_00142BA0[D_L36_002EC9F8[i].c >> 2] & (1 << (D_L36_002EC9F8[i].c & 0x1F))) || func_L01_00417EA0();
            n = i + 1;
            break;
        case 1:
            D_L36_002EC9F8[i].flag = 0;
            n = i + 1;
            for (j = 0; ((unsigned *)D_L36_002EC9F8[i].c)[j]; j++) {
                D_L36_002EC9F8[i].flag = D_L36_002EC9F8[i].flag ||
                    (D_00142BA0[((unsigned *)D_L36_002EC9F8[i].c)[j] >> 2] & (1 << (((unsigned *)D_L36_002EC9F8[i].c)[j] & 0x1F))) ||
                    func_L01_00417EA0();
            }
            i = n;
            continue;
        case 2:
            D_L36_002EC9F8[i].flag = (D_00142BA0[D_L36_002EC9F8[i].c >> 2] & (1 << (D_L36_002EC9F8[i].c & 0x1F))) || func_L01_00417EA0();
            n = i + 1;
            break;
        case 3:
        case 4:
        default:
            D_L36_002EC9F8[i].flag = D_00142693[0] || func_L01_00417EA0();
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L36_0046D8F8 */
