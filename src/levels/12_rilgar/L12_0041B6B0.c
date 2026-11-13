#include "common.h"

/* localdecomp:start func_L12_0041B6B0 */
typedef struct { s32 key; s32 off; } E_41B6B0;
extern E_41B6B0 D_L12_002D1580[];
extern u8 D_001D5570[8];
extern u8 D_0014271D[];
extern s32 func_L01_0041A4F0(s32, s32);

s32 func_L12_0041B6B0(s32 id, s32 a1) {
    s32 i;

    if (func_L01_0041A4F0(id, a1) != 0) {
        return 1;
    }
    if (id == 0x67) {
        return D_0014271D[0] != 0;
    }
    for (i = 0; D_L12_002D1580[i].key != 0; i++) {
        if (id == D_L12_002D1580[i].key) {
            if (D_L12_002D1580[i].off == a1 || D_001D5570[D_L12_002D1580[i].off] != 0) {
                return 1;
            }
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L12_0041B6B0 */
