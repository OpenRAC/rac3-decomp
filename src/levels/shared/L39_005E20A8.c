#include "common.h"

/* localdecomp:start func_L39_005E20A8 */
extern s32 *D_L39_00241120;
extern s32 D_L39_002439C0;
extern u8 D_L39_002439C4;
extern s32 func_L01_0047C4A8(s32);
extern s32 func_L39_00610490(s32);
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00479280(void);

void func_L39_005E20A8(s32 arg0, s32 arg1) {
    if (func_L39_00610490(func_L01_0047C4A8(0)) == 1) {
        func_003E82F8((*D_L39_00241120 < 2) ? 0 : 4);
        D_L39_002439C0 = arg1;
        D_L39_002439C4 = 0;
        func_L01_00516AA0(0x40000, 1, 1);
    } else if (func_L39_00610490(func_L01_0047C4A8(0)) == 2) {
        func_L01_00479280();
    }
}
/* localdecomp:end func_L39_005E20A8 */
