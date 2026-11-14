#include "common.h"

/* NTSC-U counterpart of the PAL function at the same position (L01 shared, @ps2as) */
/* localdecomp:start func_L01_00461F70 */
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);

void func_L01_00461F70(u8 *obj) {
    u8 *rec = obj + 0x20;

    obj[8] += rec[8];
    *(f32 *)(obj + 0x18) += *(f32 *)(rec + 0x10);
    *(f32 *)(obj + 0xC) *= *(f32 *)(rec + 0xC);
    if (*(s32 *)(rec + 4) == 0) {
        if (func_003883C8(obj + 0xA) != 0) {
            *(s32 *)(rec + 4) = 1;
            *(s16 *)(obj + 0xA) = 0x1E;
            *(s32 *)(obj + 4) = *(s32 *)(rec + 0x14) | 0x7F000000;
        } else {
            *(s32 *)(obj + 4) = (((s32)((f32)(10 - *(s16 *)(obj + 0xA)) * 9.6f) + 0x20) << 24) | *(s32 *)(rec + 0x14);
        }
    } else {
        if (func_003883C8(obj + 0xA) != 0) {
            func_003C7CE0(obj);
            return;
        }
        *(s32 *)(obj + 4) = ((s32)((f32) * (s16 *)(obj + 0xA) * 4.2333333f) << 24) | *(s32 *)(rec + 0x14);
    }
}
/* localdecomp:end func_L01_00461F70 */
