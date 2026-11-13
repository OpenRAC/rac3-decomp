#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* localdecomp:start func_L39_00667908 */
typedef struct {
    u8 pad0[0x252C];
    s32 *x252C;
    u8 pad2530[0x254C - 0x2530];
    s32 x254C;
} S_00667908;

typedef struct {
    s32 count;
} T_00667908;

extern T_00667908 *D_L39_00241120;
extern S_00667908 *func_L39_0061BF38(s32);

void func_L39_00667908(s32 a, s32 b)
{
    s32 i;
    S_00667908 *p;

    for (i = 0; i < D_L39_00241120->count; i++) {
        p = func_L39_0061BF38(i);
        if (p->x254C == a && p->x252C != 0 && *p->x252C == b) {
            p->x254C = 0;
        }
    }
}
/* localdecomp:end func_L39_00667908 */

INCLUDE_ASM("asm/levels", func_L39_006679A0);

INCLUDE_ASM("asm/levels", func_L39_00667B68);
