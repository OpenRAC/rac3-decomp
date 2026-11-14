#include "common.h"

/* NTSC-U counterpart of func_L17_003F53F8 (src/levels/17_crash_site/L17_003F53F8.c) */
/* localdecomp:start func_L17_003F2EB8 */
typedef struct { int key; int off; } E_3F53F8;
extern int func_L01_00417EA0(int, int);
extern E_3F53F8 D_L17_002D8E80[];
extern unsigned char D_0014271D[];
extern unsigned char D_001D5570[] __attribute__((section(".sdata")));

int func_L17_003F2EB8(int a, int b) {
    int i;

    if (func_L01_00417EA0(a, b) != 0) return 1;
    if (a == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L17_002D8E80[i].key != 0; i++) {
        if (a == D_L17_002D8E80[i].key) {
            if (D_L17_002D8E80[i].off == b || D_001D5570[D_L17_002D8E80[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L17_003F2EB8 */
