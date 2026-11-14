#include "common.h"

/* localdecomp:start func_L40_004132C8 */
extern void func_L39_00662B18(u8 *, void *, s32);
extern void func_L40_005164F0(u8 *g, void *pos, s32 a2, s32 a3, f32 f);
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");

void func_L40_004132C8(u8 *self, u8 *buf) {
    s32 *vars = *(s32 **)(self + 0x68);
    s32 pos[4];
    s32 idx;
    f32 f;
    s32 b;

    if ((*(u32 *)buf & 0xF) < 8) {
        func_L39_00662B18(buf, &idx, 4);
        func_L39_00662B18(buf, pos, 16);
        func_L39_00662B18(buf, &f, 4);
        func_L39_00662B18(buf, &b, 4);
        if (D_L40_00249330[idx] != 0) {
            func_L40_005164F0(D_L40_00249330[idx], pos, (s32)(D_L40_0024845C + (vars[0] << 8)), 0x32, f);
            D_L40_00249330[idx][0x1A15] = b;
        }
    }
}
/* localdecomp:end func_L40_004132C8 */

INCLUDE_ASM("asm/levels", func_L40_004133A8);

LINKER_REMNANT("asm/levels", func_L40_00413968);

INCLUDE_ASM("asm/levels", func_L40_00413978);
