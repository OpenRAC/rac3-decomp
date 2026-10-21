#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_0044A2F8);

/* localdecomp:start func_L40_0044A430 */
typedef struct {
    s32 a;
    s16 b;
    s16 c;
    s32 id;
    s32 pad;
} Ent00449588;
extern Ent00449588 D_L40_00257F40[];
extern s32 D_L40_001D6D2C;
extern s32 D_L40_001D6D18;
extern u16 D_L40_001D6D14;
extern s32 func_L40_0044A2F8(s32 a0, s32 *a1, s16 *a2);
s32 func_L40_0044A430(s32 a0) {
    s32 id;
    if (func_L40_0044A2F8(a0, &D_L40_00257F40[D_L40_001D6D2C].a, &D_L40_00257F40[D_L40_001D6D2C].b) != 0) {
        D_L40_00257F40[D_L40_001D6D2C].c = 1;
        id = (s16)(D_L40_001D6D14 | (*(u16 *)&D_L40_001D6D18 << 6));
        D_L40_00257F40[D_L40_001D6D2C].id = id;
        D_L40_001D6D18++;
        D_L40_001D6D2C = (D_L40_001D6D2C + 1) & 15;
        return id;
    }
    return 0;
}
/* localdecomp:end func_L40_0044A430 */

INCLUDE_ASM("asm/levels", func_L40_0044A4C8);
