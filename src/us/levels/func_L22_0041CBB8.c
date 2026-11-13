#include "common.h"

/* NTSC-U counterpart of func_L22_0041F3B8 (src/levels/22_mylon/L22_0041F3B8.c) */
/* localdecomp:start func_L22_0041CBB8 */
typedef struct { int key; int off; } S_41F3B8;
extern S_41F3B8 D_L22_002D2FC0[];
__asm__(".extern D_L22_002D2FC0, 16");
extern unsigned char D_001D5570[8];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_00417EA0(int a0, int a1);

int func_L22_0041CBB8(int a0, int a1) {
    int i;
    if (func_L01_00417EA0(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L22_002D2FC0[i].key != 0; i++) {
        if (a0 == D_L22_002D2FC0[i].key) {
            if (D_L22_002D2FC0[i].off == a1 || D_001D5570[D_L22_002D2FC0[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L22_0041CBB8 */
