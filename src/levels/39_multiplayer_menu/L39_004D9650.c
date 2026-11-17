#include "common.h"

/* localdecomp:start func_L39_004D9650 */
#include "dnas.h"

typedef struct S_004D9650 {
    /* 0x00000 */ u8 pad0[0x106A4];
    /* 0x106A4 */ s32 buf;
    /* 0x106A8 */ u8 pad106A8[0x10738 - 0x106A8];
    /* 0x10738 */ s32 err;
} S_004D9650;

extern S_004D9650 D_L39_00453FB0;
extern void func_L39_004BD350(s32, s32, s32, u32);
extern s32 func_L39_004D8F00(s32, s32, s32 *, s32, s32 *);
extern s32 func_L39_004D8FD0(u8 *, s32);
extern s32 func_L39_004D9058(s32, s32);
extern s32 func_L39_004D9168(s32, s32, s32, s32);
extern s32 func_L39_004D9330(s32, s32, s32, s32);
extern s32 func_L39_004D9508(s32, s32, s32, s32);

s32 func_L39_004D9650(s32 type, s32 len, s32 arg2, s32 arg3, s32 arg4) {
    s32 p = D_L39_00453FB0.buf;
    s32 size = 0;
    s32 flag = 0;
    s32 n;
    s32 r;

    n = func_L39_004D8F00(type, arg3, &size, p, &flag);
    if (n < 0) {
        return n;
    }
    len -= n;
    p += n;
    if (len != size) {
        return -0x6A;
    }
    if (flag > 0) {
        DNAS_BEGIN(func_L39_004D9650, 0, func_L39_004BD350);
        switch (D_L39_00453FB0.err) {
        case -0x191:
            return -0x191;
        case -0x193:
            return -0x193;
        case -0x192:
            return -0x192;
        case -0x6B:
            return -0x6B;
        case -0x6A:
            return -0x6A;
        }
        DNAS_END(func_L39_004D9650, 0, func_L39_004BD350);
        r = func_L39_004D9610(p, len, arg4);
        if (r < 0) {
            return r;
        }
        p += r;
    } else {
        switch (type) {
        case 5:
            r = func_L39_004D8FD0((u8 *)p, len);
            if (r < 0) {
                return r;
            }
            p += r;
            break;
        case 6:
            r = func_L39_004D9058(p, len);
            if (r < 0) {
                return r;
            }
            p += r;
            break;
        case 7:
            r = func_L39_004D9168(p, len, arg2, arg4);
            if (r < 0) {
                return r;
            }
            p += r;
            break;
        case 13:
            r = func_L39_004D9330(p, len, arg2, arg4);
            if (r < 0) {
                return r;
            }
            p += r;
            break;
        case 12:
            r = func_L39_004D9508(p, len, arg2, arg4);
            if (r < 0) {
                return r;
            }
            p += r;
            break;
        default:
            return -0x6A;
        }
    }
    return p - D_L39_00453FB0.buf;
}
/* localdecomp:end func_L39_004D9650 */
