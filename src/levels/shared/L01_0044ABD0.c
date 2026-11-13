#include "common.h"

/* localdecomp:start func_L01_0044ABD0 */
extern s32 func_0038CB00(u8 *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
void func_L01_0044ABD0(void *owner, u8 *obj) {
    s32 r, g, b;
    f32 limit, f;
    if (*(s16 *)obj == 0) return;
    if (func_0038CB00(obj) != 0) {
        if (*(s16 *)(obj + 2) != 0) {
            func_L01_0043B9E8(owner, obj[4], obj[5], obj[6]);
            return;
        }
        *(s16 *)(obj + 2) = 1;
        *(s16 *)obj = (*(s16 *)(obj + 0xE) * 5 + 2) / 6;
    }
    if (*(s16 *)(obj + 2) == 0) {
        limit = (f32)((*(s16 *)(obj + 0xC) * 5 + 2) / 6);
        f = (limit - (f32)*(s16 *)obj) / limit;
        r = obj[7] ? (s32)((f32)obj[4] + (f32)(obj[7] - obj[4]) * f) : obj[4];
        g = obj[8] ? (s32)((f32)obj[5] + (f32)(obj[8] - obj[5]) * f) : obj[5];
        b = obj[9] ? (s32)((f32)obj[6] + (f32)(obj[9] - obj[6]) * f) : obj[6];
    } else {
        limit = (f32)((*(s16 *)(obj + 0xE) * 5 + 2) / 6);
        f = (limit - (f32)*(s16 *)obj) / limit;
        r = obj[7] ? (s32)((f32)obj[7] + (f32)(obj[4] - obj[7]) * f) : obj[4];
        g = obj[8] ? (s32)((f32)obj[8] + (f32)(obj[5] - obj[8]) * f) : obj[5];
        b = obj[9] ? (s32)((f32)obj[9] + (f32)(obj[6] - obj[9]) * f) : obj[6];
    }
    func_L01_0043B9E8(owner, r, g, b);
}
/* localdecomp:end func_L01_0044ABD0 */

INCLUDE_ASM("asm/levels", func_L01_0044AE78);

/* localdecomp:start func_L01_0044AEB8 */
extern s32 func_003C4B50(u8 *a0);
s32 func_L01_0044AEB8(u8 *a0) {
    if (a0 == 0) return 0;
    if (func_003C4B50(a0) != 0) return *(s16 *)(a0 + 0xAA) == 0x1F6;
    return 1;
}
/* localdecomp:end func_L01_0044AEB8 */
