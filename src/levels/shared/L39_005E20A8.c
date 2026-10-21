#include "common.h"

/* localdecomp:start func_L39_005E20A8 */
extern s32 *D_L39_001D5A10;
extern s32 D_L39_001D82B0;
extern u8 D_L39_001D82B4;
extern s32 func_L01_0047C4A8(s32);
extern s32 func_L39_00610490(s32);
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00479280(void);

void func_L39_005E20A8(s32 arg0, s32 arg1) {
    if (func_L39_00610490(func_L01_0047C4A8(0)) == 1) {
        func_003E82F8((*D_L39_001D5A10 < 2) ? 0 : 4);
        D_L39_001D82B0 = arg1;
        D_L39_001D82B4 = 0;
        func_L01_00516AA0(0x40000, 1, 1);
    } else if (func_L39_00610490(func_L01_0047C4A8(0)) == 2) {
        func_L01_00479280();
    }
}
/* localdecomp:end func_L39_005E20A8 */

INCLUDE_ASM("asm/levels", func_L39_005E2140);

INCLUDE_ASM("asm/levels", func_L39_005E2890);

/* localdecomp:start func_L39_005E2B30 */
extern u8 D_L39_001D82B5;
extern s32 func_L39_006121B0();
void func_L39_005E2B30(void) {
    D_L39_001D82B5 = 0;
    func_L39_006121B0(22);
}
/* localdecomp:end func_L39_005E2B30 */
