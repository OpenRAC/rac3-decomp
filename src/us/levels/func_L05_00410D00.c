#include "common.h"

/* NTSC-U counterpart of func_L05_00413A00 (src/levels/05_daxx/L05_00413A00.c) */
/* localdecomp:start func_L05_00410D00 */
typedef struct { int key; int off; } S_413A00;
extern S_413A00 D_L05_002D3F40[];
__asm__(".extern D_L05_002D3F40, 16");
extern unsigned char D_001D5570[8];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_00417EA0(int a0, int a1);

int func_L05_00410D00(int a0, int a1) {
    int i;
    if (func_L01_00417EA0(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L05_002D3F40[i].key != 0; i++) {
        if (a0 == D_L05_002D3F40[i].key) {
            if (D_L05_002D3F40[i].off == a1 || D_001D5570[D_L05_002D3F40[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L05_00410D00 */
