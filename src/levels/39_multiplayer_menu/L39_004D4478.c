#include "common.h"

/* localdecomp:start func_L39_004D4478 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_L39_004D1CA0(s32, s32, u8 *, s32);
extern s32 func_L39_004D1FB8(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004D4478(u8 *dst, u32 size, u32 *len, s32 key, u32 n, s32 a5, s32 a6) {
    u8 buf[32];
    u8 *p;
    u8 *q;
    u32 i;
    s32 j;
    s32 ret = -1;

    i = 0;
    DNAS_BEGIN(func_L39_004D4478, 0, func_L39_004F7890);
    if (size >= n
        && func_L39_004D1CA0(a5, a6, buf, 4) >= 0
        && func_L39_004D1FB8(key, (s32)buf, (s32)(buf + 8), (s32)(buf + 16), (s32)dst, (s32)(buf + 24), n >> 3) >= 0) {
        p = dst + 0x20;
        if (func_L39_004D1FB8((s32)p, (s32)dst, (s32)(dst + 8), (s32)(dst + 16), (s32)p, (s32)(dst + 24), (n - 0x20) >> 3) >= 0) {
            func_L39_004D4448((s32 *)len, p);
            if (*len + 0x28 <= size) {
                for (i = 0; i < *len; i++) {
                    dst[i] = dst[i + 0x28];
                }
                ret = 0;
            }
        }
    }
    q = buf;
    for (j = 0; j < 32; j++) {
        q[j] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    DNAS_END(func_L39_004D4478, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D4478 */
