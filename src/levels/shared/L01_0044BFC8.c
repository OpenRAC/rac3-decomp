#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0044BFC8);

INCLUDE_ASM("asm/levels", func_L01_0044C078);

LINKER_REMNANT("asm/levels", func_L01_0044C0F8);

/* localdecomp:start func_L01_0044C108 */
typedef struct {
    s32 cur;
    u8 pad4[8];
    s32 count;
} Struct_001F3FC0;

extern Struct_001F3FC0 D_L01_001F3F40;
extern u8 D_L01_001F3F60[][16];
extern s32 func_L01_0040F5B8(s32, void *, void *);

s32 func_L01_0044C108(s32 a0)
{
    s32 i;
    s32 r = 0;

    for (i = D_L01_001F3F40.count - 1; i >= 0; i--) {
        if (func_L01_0040F5B8(a0, D_L01_001F3F60[i], D_L01_001F3F60[i + 2])) {
            r = i + 1;
            break;
        }
    }
    return r == D_L01_001F3F40.cur;
}
/* localdecomp:end func_L01_0044C108 */

LINKER_REMNANT("asm/levels", func_L01_0044C198);

/* localdecomp:start func_L01_0044C1B8 */
extern f32 func_0038DAB8(f32, f32);

void func_L01_0044C1B8(f32 *a0, f32 *a1) {
    a0[2] = func_0038DAB8(a0[2], a1[2]);
    a0[1] = func_0038DAB8(a0[1], a1[1]);
    a0[0] = func_0038DAB8(a0[0], a1[0]);
}
/* localdecomp:end func_L01_0044C1B8 */

LINKER_REMNANT("asm/levels", func_L01_0044C218);
