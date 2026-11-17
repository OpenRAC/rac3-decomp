#include "common.h"

/* localdecomp:start func_L39_00677D08 */
s32 func_L39_005B43C8(s32, s32);
void func_L39_0060AE30(s32, s32);
extern s32 D_L39_0024D028[];
extern s32 D_L39_0024D02C[];
extern s32 D_L39_0024D030[];
extern s32 D_L39_0024D034[];
extern s32 D_L39_0024D038[];
extern f32 D_L39_0024D03C[];

s32 func_L39_00677D08(s32 arg0) {
    D_L39_0024D030[0] = arg0;
    D_L39_0024D03C[0] = 1.0f;
    D_L39_0024D02C[0] = 0x4B;
    D_L39_0024D028[0] = 0;
    D_L39_0024D034[0] = 0;
    D_L39_0024D038[0] = func_L39_005B43C8(0x1A, 0x23);
    func_L39_0060AE30(0, 0);
    return 1;
}
/* localdecomp:end func_L39_00677D08 */
