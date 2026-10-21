#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005A12B8);

/* localdecomp:start func_L39_005A3D98 */
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x670 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_L39_001F0A00;
extern s32 *D_L39_00240290;
extern u8 D_L39_01F37FF0[];
extern s32 func_L39_005C2A40();
s32 func_L39_005A3D98(void) {
    S_395360 *s = &D_L39_001F0A00;
    u32 x;
    s32 *p;
    x = ((s->f66C << 11) + 0x1057) & 0xFFFFF000;
    p = (s32 *)((s32)((u32)D_L39_01F37FF0 - x) & -16);
    D_L39_00240290 = p;
    *p = 0x60;
    func_L39_005C2A40((s32)D_L39_00240290 + D_L39_00240290[0], s->f668 + s->f64C, s->f66C);
    return 1;
}
/* localdecomp:end func_L39_005A3D98 */
