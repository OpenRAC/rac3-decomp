#include "common.h"

/* localdecomp:start func_L13_003FB2E8 */
typedef struct { int key; int off; } S_003FB2E8;
extern S_003FB2E8 D_L13_002CFE80[];
__asm__(".extern D_L13_002CFE80, 16");
extern unsigned char D_001D5570[8];
__asm__(".extern D_001D5570, 16");
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_0041A4F0(int a0, int a1);

int func_L13_003FB2E8(int a0, int a1) {
    int i;
    if (func_L01_0041A4F0(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L13_002CFE80[i].key != 0; i++) {
        if (a0 == D_L13_002CFE80[i].key) {
            if (D_L13_002CFE80[i].off == a1 || D_001D5570[D_L13_002CFE80[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L13_003FB2E8 */
