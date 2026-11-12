#include "common.h"

/* localdecomp:start func_L02_003F2870 */
typedef struct { int key; int off; } E_3F2870;
extern int func_L01_0041A4F0(int, int);
extern E_3F2870 D_L02_002CF100[];
extern unsigned char D_0014271D[];
extern unsigned char D_001D5570[] __attribute__((section(".sdata")));

int func_L02_003F2870(int a, int b) {
    int i;

    if (func_L01_0041A4F0(a, b) != 0) return 1;
    if (a == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L02_002CF100[i].key != 0; i++) {
        if (a == D_L02_002CF100[i].key) {
            if (D_L02_002CF100[i].off == b || D_001D5570[D_L02_002CF100[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L02_003F2870 */
