#include "common.h"

/* localdecomp:start func_L32_003FA310 */
typedef struct { int key; int off; } S_003FA310;
extern int func_L01_0041A4F0(int, int);
extern S_003FA310 D_L32_002D1DC0[];
extern unsigned char D_0014271D[];
extern unsigned char D_001D5570[] __attribute__((section(".sdata")));

/* from func_L17_003F53F8 */
int func_L32_003FA310(int a, int b) {
    int i;

    if (func_L01_0041A4F0(a, b) != 0) return 1;
    if (a == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L32_002D1DC0[i].key != 0; i++) {
        if (a == D_L32_002D1DC0[i].key) {
            if (D_L32_002D1DC0[i].off == b || D_001D5570[D_L32_002D1DC0[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L32_003FA310 */
