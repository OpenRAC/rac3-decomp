/* near miss: level 18, 14 diff (default level flags). The table is indexed (D_L18_002D1E40[i]), which keeps the walk pointer in $v1 as retail has it. Left: the high half of D_001D5570's address lands in $v0, so reorg cannot put retail's `move $v0,$zero` into the two delay slots (after the table[0] test and the loop's bottom test); a hoisted base pointer, a result variable, while/for shapes and split return tests did not move it. The callee is func_L01_0041A4F0 (the catalogue name of level 18's 0x42D9C8). */
#include "common.h"

/* localdecomp:start func_L18_0042D0F0 */
typedef struct { s32 key; s32 off; } E_42D0F0;
extern E_42D0F0 D_L18_002D1E40[];
extern u8 D_001D5570[];
extern u8 D_0014271D[];
extern s32 func_L01_0041A4F0(s32, s32);

s32 func_L18_0042D0F0(s32 a, s32 b) {
    s32 i;
    if (func_L01_0041A4F0(a, b) != 0) return 1;
    if (a == 0x67) return D_0014271D[0] != 0;
    for (i = 0; D_L18_002D1E40[i].key != 0; i++) {
        if (a == D_L18_002D1E40[i].key) {
            if (D_L18_002D1E40[i].off == b || D_001D5570[D_L18_002D1E40[i].off] != 0) return 1;
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L18_0042D0F0 */
