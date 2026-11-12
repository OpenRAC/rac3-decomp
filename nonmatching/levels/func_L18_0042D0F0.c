/* near miss: level 18, 15 diff (the register of the table pointer and the `move $v0,$zero` in the first test's delay slot differ); default level flags */
#include "common.h"

/* localdecomp:start func_L18_0042D0F0 */
typedef struct { s32 key; s32 off; } E_42D0F0;
extern E_42D0F0 D_L18_002D1E40[];
extern u8 D_001D5570[];
extern u8 D_0014271D[];
extern s32 func_L18_0042D9C8(s32, s32);

s32 func_L18_0042D0F0(s32 a, s32 b) {
    E_42D0F0 *p;
    if (func_L18_0042D9C8(a, b) != 0) return 1;
    if (a == 0x67) return D_0014271D[0] != 0;
    if (D_L18_002D1E40[0].key != 0) {
        p = D_L18_002D1E40;
        do {
            if (a == p->key) {
                if (p->off == b || D_001D5570[p->off] != 0) return 1;
                return 0;
            }
            p++;
        } while (p->key != 0);
    }
    return 0;
}
/* localdecomp:end func_L18_0042D0F0 */
