#include "common.h"

/* declared by functions of L21_00336EF0.c, which this file was cut from */
extern s32 D_L21_001DED9C[];

/* localdecomp:start func_L21_00338CC8 */
extern s32 D_L21_001DED9C[];

s32 func_L21_00338CC8(void *arg0, u8 *arg1) {
    s32 base;
    s32 prod;
    s32 r;
    u8 *q;
    f32 lim;
    base = D_L21_001DED9C[0];
    base += *(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x68)) + 0x24) << 8;
    q = *(u8 **)(base + 0x68);
    if (arg1 != 0) {
        prod = *(s16 *)(q + 0x34) * *arg1;
        lim = (f32)prod * 0.01f;
        r = 1;
        if (!(*(f32 *)(q + 0x30) < lim)) {
            r = 0;
        }
        return r;
    }
    return 0;
}
/* localdecomp:end func_L21_00338CC8 */
