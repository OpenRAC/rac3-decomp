#include "common.h"

/* localdecomp:start func_L39_0057D548 */
extern u8 D_L39_00242460[];
extern u8 D_L39_00242470[];
extern u8 D_L39_00242480[];
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[0xC0];
} S_0057D548;

extern S_0057D548 D_001A6A80;
extern s32 func_00118F88(s32);
extern s32 func_001205B0(s32, s32);
extern s32 func_00120B70(u8 *, u8 *, s32);

s32 func_L39_0057D548(s32 arg0, s32 arg1) {
    s32 value = func_00118F88(arg1);
    u32 idx;

    if (func_001205B0(arg0, (s32)D_L39_00242460) == 0) {
        D_001A6A80.unk0 = value;
    } else if (func_001205B0(arg0, (s32)D_L39_00242470) == 0) {
        D_001A6A80.unk4 = value;
    } else if (func_00120B70((u8 *)arg0, D_L39_00242480, 5) == 0) {
        idx = func_00118F88(arg0 + 5);
        if (idx < 0xC0) {
            D_001A6A80.unkC[idx] = value;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0057D548 */
