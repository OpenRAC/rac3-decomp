#include "common.h"

/* NTSC-U counterpart of func_L24_00401EE0 (src/levels/24_insomniac_museum/L24_00401EE0.c) */
/* localdecomp:start func_L24_003FF720 */
typedef struct { int key; int off; } S_401EE0;
extern S_401EE0 D_L24_002CF4C0[];
__asm__(".extern D_L24_002CF4C0, 16");
extern unsigned char D_001D5570[8];
__asm__(".extern D_001D5570, 16");
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_00417EA0(int a0, int a1);

int func_L24_003FF720(int a0, int a1) {
    int i;
    if (func_L01_00417EA0(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L24_002CF4C0[i].key != 0; i++) {
        if (a0 == D_L24_002CF4C0[i].key) {
            if (D_L24_002CF4C0[i].off == a1 || D_001D5570[D_L24_002CF4C0[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L24_003FF720 */
