#include "common.h"

/* localdecomp:start func_L39_004D2710 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_L39_004D1CA0(s32, s32, s32, s32);

s32 func_L39_004D2710(s32 a0, s32 a1, s32 a2) {
    s32 ret = -1;

    DNAS_BEGIN(func_L39_004D2710, 0, func_L39_004F7890);
    if (func_L39_004D1CA0(a1, a0, a2, 2) >= 0) {
        ret = 1;
    }
    DNAS_END(func_L39_004D2710, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D2710 */

/* localdecomp:start func_L39_004D2828 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern void func_L39_004D3160(s32, s32, u8, u32, u32, u8 *);
extern s32 func_L39_004D2710(s32, s32, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004D2828(void *dst, void *src, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        ((u8 *)dst)[i] = ((u8 *)src)[i];
    }
}

static __inline__ void randfill_004D2828(u8 *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004D2828(s32 a0, s32 a1, u8 *a2, s32 a3) {
    u8 out[16];
    u8 key[16];
    u32 w0;
    u32 w1;
    s32 ret;

    DNAS_BEGIN(func_L39_004D2828, 0, func_L39_004F7890);
    copy_004D2828(&w0, a2, 4);
    copy_004D2828(&w1, a2 + 4, 4);
    func_L39_004D3160(a0, a1, a2[0x18], w0, w1, out);
    copy_004D2828(key, a2 + 8, 16);
    ret = -1;
    if (func_L39_004D2710((s32)out, (s32)key, a3) >= 0) {
        ret = 1;
    }
    w0 = 0;
    w1 = 0;
    randfill_004D2828(out, 8);
    randfill_004D2828(key, 16);
    DNAS_END(func_L39_004D2828, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D2828 */
