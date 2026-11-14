#include "common.h"

/* localdecomp:start func_L04_00427EE0 */
typedef struct { int key; int off; } S_L04_00427EE0;
extern S_L04_00427EE0 D_L04_002D1EC0[];
__asm__(".extern D_L04_002D1EC0, 16");
extern unsigned char D_001D5570[8];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int func_L01_00417EA0(int a0, int a1);

/* Returns 1 when challenge_mode_active says so, or for key 0x67 when a byte flag is set; otherwise
 * looks the key up in a table and returns 1 if the stored offset equals a1 or the byte at that
 * offset in D_001D5570 is set, else 0. */
int func_L04_00427EE0(int a0, int a1) {
    int i;
    if (func_L01_00417EA0(a0, a1) != 0) return 1;
    if (a0 == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L04_002D1EC0[i].key != 0; i++) {
        if (a0 == D_L04_002D1EC0[i].key) {
            if (D_L04_002D1EC0[i].off == a1 || D_001D5570[D_L04_002D1EC0[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L04_00427EE0 */
