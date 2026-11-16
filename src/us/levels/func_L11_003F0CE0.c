#include "common.h"

/* NTSC-U counterpart of func_L11_003F3560 (src/levels/11_obani_moons/L11_003F3560.c) */
/* localdecomp:start func_L11_003F0CE0 */
typedef struct { int key; int off; } S_3F3560;
extern S_3F3560 D_L11_002D44C0[];
__asm__(".extern D_L11_002D44C0, 16");
extern unsigned char D_001D5570[8];
__asm__(".extern D_001D5570, 16");
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_00417EA0(int a0, int a1);

/* the code of func_L05_00413A00, with level 11's table */
/* Returns 1 when challenge_mode_active says so, when a0 is 0x67 and a flag is set, or when a0
 * matches a key in level 11's table and its entry or a flag is set; else 0. */
int func_L11_003F0CE0(int a0, int a1) {
    int i;
    if (func_L01_00417EA0(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L11_002D44C0[i].key != 0; i++) {
        if (a0 == D_L11_002D44C0[i].key) {
            if (D_L11_002D44C0[i].off == a1 || D_001D5570[D_L11_002D44C0[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003F0CE0 */
