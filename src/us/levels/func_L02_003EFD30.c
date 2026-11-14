#include "common.h"

/* NTSC-U counterpart of func_L02_003F2870 (src/levels/02_florana/L02_003F2870.c) */
/* localdecomp:start func_L02_003EFD30 */
typedef struct { int key; int off; } E_3F2870;
extern int func_L01_00417EA0(int, int);
extern E_3F2870 D_L02_002CF140[];
extern unsigned char D_0014271D[];
extern unsigned char D_001D5570[] __attribute__((section(".sdata")));

int func_L02_003EFD30(int a, int b) {
    int i;

    if (func_L01_00417EA0(a, b) != 0) return 1;
    if (a == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L02_002CF140[i].key != 0; i++) {
        if (a == D_L02_002CF140[i].key) {
            if (D_L02_002CF140[i].off == b || D_001D5570[D_L02_002CF140[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L02_003EFD30 */
