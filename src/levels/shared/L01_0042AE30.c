#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0042AE30);

/* localdecomp:start func_L01_0042AEC0 */
typedef struct {
    s32 cur;
    u8 pad4[8];
    s32 count;
    u8 pad10[16];
    u8 entries[1][16];
} Struct_001F3FC0;

extern Struct_001F3FC0 D_L01_001F3F40;
extern s32 func_L01_0040F5B8(s32, void *, void *);

s32 func_L01_0042AEC0(s32 a0)
{
    s32 i;

    for (i = D_L01_001F3F40.count - 1; i >= 0; i--) {
        if (func_L01_0040F5B8(a0, D_L01_001F3F40.entries[i], D_L01_001F3F40.entries[i + 2])) {
            return i + 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0042AEC0 */

INCLUDE_ASM("asm/levels", func_L01_0042AF50);

INCLUDE_ASM("asm/levels", func_L01_0042B068);
