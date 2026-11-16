#include "common.h"

/* NTSC-U counterpart of func_L22_004A32D0 (src/levels/22_mylon/L22_004A32D0.c) */
/* localdecomp:start func_L22_0049F8E8 */
typedef struct S_4961F0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_4961F0;
extern S_4961F0 D_L22_002EDD98[];
__asm__(".extern D_L22_002EDD98, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_00417EA0(void);

/* Walks the table at D_L22_002EDD98 until an entry with a0 of 0 and sets each entry's flag if its
 * bit (or any bit of its list) is set in D_00142BA0, or by D_00142693, or challenge_mode_active. */
void func_L22_0049F8E8(void) {
    int i;
    int j;
    int n;
    i = 0;
    while (D_L22_002EDD98[i].a0) {
        switch (D_L22_002EDD98[i].kind) {
        case 0:
            D_L22_002EDD98[i].flag = (D_00142BA0[D_L22_002EDD98[i].c >> 2] & (1 << (D_L22_002EDD98[i].c & 0x1F))) || func_L01_00417EA0();
            n = i + 1;
            break;
        case 1:
            D_L22_002EDD98[i].flag = 0;
            n = i + 1;
            for (j = 0; ((unsigned *)D_L22_002EDD98[i].c)[j]; j++) {
                D_L22_002EDD98[i].flag = D_L22_002EDD98[i].flag ||
                    (D_00142BA0[((unsigned *)D_L22_002EDD98[i].c)[j] >> 2] & (1 << (((unsigned *)D_L22_002EDD98[i].c)[j] & 0x1F))) ||
                    func_L01_00417EA0();
            }
            i = n;
            continue;
        case 2:
            D_L22_002EDD98[i].flag = (D_00142BA0[D_L22_002EDD98[i].c >> 2] & (1 << (D_L22_002EDD98[i].c & 0x1F))) || func_L01_00417EA0();
            n = i + 1;
            break;
        case 3:
        case 4:
        default:
            D_L22_002EDD98[i].flag = D_00142693[0] || func_L01_00417EA0();
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L22_0049F8E8 */
