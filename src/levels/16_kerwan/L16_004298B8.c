#include "common.h"

typedef struct { int key; int off; } S_00426FF8;

/* localdecomp:start func_L16_004298B8 */
/* PAL port of the NTSC-U match src/us/levels/func_L16_00426FF8.c */

extern S_00426FF8 D_L16_002DCFC0[];
__asm__(".extern D_L16_002DCFC0, 16");
extern unsigned char D_1D5570[8];
__asm__(".extern D_1D5570, 16");
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_0041A4F0(int a0, int a1);

int func_L16_004298B8(int a0, int a1) {
    int i;
    if (func_L01_0041A4F0(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L16_002DCFC0[i].key != 0; i++) {
        if (a0 == D_L16_002DCFC0[i].key) {
            if (D_L16_002DCFC0[i].off == a1 || D_1D5570[D_L16_002DCFC0[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L16_004298B8 */
