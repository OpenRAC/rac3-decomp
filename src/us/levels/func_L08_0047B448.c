#include "common.h"

/* NTSC-U counterpart of func_L08_0047F170 (src/levels/08_aquatos/L08_0047F170.c) */
/* localdecomp:start func_L08_0047B448 */
typedef struct S_L08_0047B448 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_L08_0047B448;
extern S_L08_0047B448 D_L08_002EBB78[];
__asm__(".extern D_L08_002EBB78, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_00417EA0(void);

void func_L08_0047B448(void) {
    int i;
    int j;
    int n;
    i = 0;
    while (D_L08_002EBB78[i].a0) {
        switch (D_L08_002EBB78[i].kind) {
        case 0:
            D_L08_002EBB78[i].flag = (D_00142BA0[D_L08_002EBB78[i].c >> 2] & (1 << (D_L08_002EBB78[i].c & 0x1F))) || func_L01_00417EA0();
            n = i + 1;
            break;
        case 1:
            D_L08_002EBB78[i].flag = 0;
            n = i + 1;
            for (j = 0; ((unsigned *)D_L08_002EBB78[i].c)[j]; j++) {
                D_L08_002EBB78[i].flag = D_L08_002EBB78[i].flag ||
                    (D_00142BA0[((unsigned *)D_L08_002EBB78[i].c)[j] >> 2] & (1 << (((unsigned *)D_L08_002EBB78[i].c)[j] & 0x1F))) ||
                    func_L01_00417EA0();
            }
            i = n;
            continue;
        case 2:
            D_L08_002EBB78[i].flag = (D_00142BA0[D_L08_002EBB78[i].c >> 2] & (1 << (D_L08_002EBB78[i].c & 0x1F))) || func_L01_00417EA0();
            n = i + 1;
            break;
        case 3:
        case 4:
        default:
            D_L08_002EBB78[i].flag = D_00142693[0] || func_L01_00417EA0();
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L08_0047B448 */
