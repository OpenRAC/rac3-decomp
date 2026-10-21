#include "common.h"

/* localdecomp:start func_L01_0045E420 */
typedef struct {
    u8 data[36];
} Ent45B118;

extern u8 D_L01_001FDBD0[];
extern s16 D_L01_001FD9F0[];
extern u8 D_L01_001FD900[];
extern u8 D_L01_001FFDD0[];
extern Ent45B118 D_L01_002F7334[];

Ent45B118 *func_L01_0045E420(s32 id) {
    u8 idx = D_L01_001FDBD0[id];
    if (idx == 255) {
        return 0;
    }
    if (D_L01_001FD9F0[idx] != id) {
        return &D_L01_002F7334[D_L01_001FFDD0[idx]];
    }
    return &D_L01_002F7334[D_L01_001FD900[idx]];
}
/* localdecomp:end func_L01_0045E420 */

INCLUDE_ASM("asm/levels", func_L01_0045E4B0);
