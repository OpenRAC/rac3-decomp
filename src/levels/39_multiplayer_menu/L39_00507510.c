#include "common.h"

/* localdecomp:start func_L39_00507510 */
s32 func_L39_00508278(s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 (*unk8)(s32, s32);
    s32 unkC;
    s32 (*unk10)(s32, s32, s32);
} S_00507510_ops;

typedef struct {
    u8 pad0[0xC];
    S_00507510_ops *unkC;
    u8 pad10[0x4];
    s32 unk14;
    u8 pad18[0x4];
    s32 unk1C;
    u8 pad20[0x8];
    s32 unk28;
} S_00507510;

s32 func_L39_00507510(S_00507510 *arg0, s32 arg1, s32 arg2) {
    s32 ret;

    if (arg0->unk28 == 1) {
        ret = arg0->unkC->unk8(arg0->unk1C, arg0->unk14);
        if (ret != 0) {
            return func_L39_00508278(ret);
        }
    }
    arg0->unk28 = 0;
    ret = arg0->unkC->unk10(arg0->unk1C, arg1, arg2);
    if (ret != 0) {
        return func_L39_00508278(ret);
    }
    return 0;
}
/* localdecomp:end func_L39_00507510 */
