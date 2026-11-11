#include "common.h"

/* localdecomp:start func_L36_003F8850 */
typedef struct { int key; int off; } S_3F8850;
extern S_3F8850 D_L36_002D1CC0[];
__asm__(".extern D_L36_002D1CC0, 16");
extern unsigned char D_001D5570[8];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_003F9128(int a0, int a1);

int func_L36_003F8850(int a0, int a1) {
    int i;
    if (func_003F9128(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L36_002D1CC0[i].key != 0; i++) {
        if (a0 == D_L36_002D1CC0[i].key) {
            if (D_L36_002D1CC0[i].off == a1 || D_001D5570[D_L36_002D1CC0[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L36_003F8850 */
