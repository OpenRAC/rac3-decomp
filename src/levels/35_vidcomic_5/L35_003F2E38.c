#include "common.h"

/* localdecomp:start func_L35_003F2E38 */
typedef struct { int key; int off; } S_L35_003F2E38;

extern S_L35_003F2E38 D_L35_002D1B00[];
__asm__(".extern D_L35_002D1B00, 16");
extern unsigned char D_001D5570[8];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_0041A4F0(int a0, int a1);

int func_L35_003F2E38(int a0, int a1) {
    int i;
    int r;

    r = func_L01_0041A4F0(a0, a1);
    if (r != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L35_002D1B00[i].key != 0; i++) {
        if (a0 == D_L35_002D1B00[i].key) {
            if (D_L35_002D1B00[i].off == a1 || D_001D5570[D_L35_002D1B00[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L35_003F2E38 */
