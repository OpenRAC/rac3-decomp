#include "common.h"

/* NTSC-U counterpart of func_L35_003F2E38 (src/levels/35_vidcomic_5/L35_003F2E38.c) */
/* localdecomp:start func_L35_003F0958 */
typedef struct { int key; int off; } S_L35_003F2E38;

extern S_L35_003F2E38 D_L35_002D1B40[];
__asm__(".extern D_L35_002D1B40, 16");
extern unsigned char D_001D5570[8];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_00417EA0(int a0, int a1);

int func_L35_003F0958(int a0, int a1) {
    int i;
    int r;

    r = func_L01_00417EA0(a0, a1);
    if (r != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L35_002D1B40[i].key != 0; i++) {
        if (a0 == D_L35_002D1B40[i].key) {
            if (D_L35_002D1B40[i].off == a1 || D_001D5570[D_L35_002D1B40[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L35_003F0958 */
