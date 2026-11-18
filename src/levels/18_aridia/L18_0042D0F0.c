#include "common.h"

/* localdecomp:start func_L18_0042D0F0 */
typedef struct { s32 key; s32 off; } E_42D0F0;
extern E_42D0F0 D_L18_002D1E40[];
extern u8 D_001D5570[] __attribute__((section(".sdata")));
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
