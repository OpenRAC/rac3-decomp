#include "common.h"

/* NTSC-U counterpart of func_L01_0044ABD0 (src/levels/shared/L01_0044ABD0.c) */
/* localdecomp:start func_L01_004479A8 */
extern s32 func_003883C8(u8 *);
extern void func_L01_00438908(void *, s32, s32, s32);
void func_L01_004479A8(void *owner, u8 *obj) {
    s32 r, g, b;
    f32 limit, f;
    if (*(s16 *)obj == 0) return;
    if (func_003883C8(obj) != 0) {
        if (*(s16 *)(obj + 2) != 0) {
            func_L01_00438908(owner, obj[4], obj[5], obj[6]);
            return;
        }
        *(s16 *)(obj + 2) = 1;
        *(s16 *)obj = *(u16 *)(obj + 0xE);
    }
    if (*(s16 *)(obj + 2) == 0) {
        limit = (f32)*(s16 *)(obj + 0xC);
        f = (limit - (f32)*(s16 *)obj) / limit;
        r = obj[7] ? (s32)((f32)obj[4] + (f32)(obj[7] - obj[4]) * f) : obj[4];
        g = obj[8] ? (s32)((f32)obj[5] + (f32)(obj[8] - obj[5]) * f) : obj[5];
        b = obj[9] ? (s32)((f32)obj[6] + (f32)(obj[9] - obj[6]) * f) : obj[6];
    } else {
        limit = (f32)*(s16 *)(obj + 0xE);
        f = (limit - (f32)*(s16 *)obj) / limit;
        r = obj[7] ? (s32)((f32)obj[7] + (f32)(obj[4] - obj[7]) * f) : obj[4];
        g = obj[8] ? (s32)((f32)obj[8] + (f32)(obj[5] - obj[8]) * f) : obj[5];
        b = obj[9] ? (s32)((f32)obj[9] + (f32)(obj[6] - obj[9]) * f) : obj[6];
    }
    func_L01_00438908(owner, r, g, b);
}
/* localdecomp:end func_L01_004479A8 */
