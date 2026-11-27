/* func_L39_004D7770: the C from #131 differs in level 39's full build at +0x84: the switch's table address is loaded where retail has lui %hi(jtbl_00476120) (reverted from src/levels/39_multiplayer_menu/L39_004D7740.c, 2026-11-27). */
#include "common.h"
/* localdecomp:start func_L39_004D7770 */
typedef struct S_004D7770 {
    /* 0x00000 */ u8 pad0[0x1069C];
    /* 0x1069C */ s32 f1069C;
    /* 0x106A0 */ s32 f106A0;
    /* 0x106A4 */ s32 f106A4;
    /* 0x106A8 */ s32 f106A8;
} S_004D7770;

extern S_004D7770 D_L39_00453FB0;
extern s32 func_L39_004D7508(s32, s32, s32);
extern s32 func_L39_004D7568(s32);
extern s32 func_L39_004D7658(s32);
extern s32 func_L39_004D76B0(s32, s32);
extern s32 func_L39_004D7700(s32, s32);
extern s32 func_L39_004D7720(s32, s32);
extern s32 func_L39_004D6E78(s32, s32, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void wipe_004D7770(void *buf, u32 n) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < n; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004D7770(s32 op, s32 arg1, s32 arg2) {
    s32 a;
    s32 ret;
    s32 c;
    s32 d;
    s32 result;
    S_004D7770 *p;

    ret = 0;
    d = D_L39_00453FB0.f106A4;
    c = 0;
    a = func_L39_004D7508(op, arg2, d);
    d += a;
    c += a;
    switch (op) {
    case 0:
        ret = func_L39_004D7568(d);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 1:
        ret = func_L39_004D7658(d);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 3:
        ret = func_L39_004D76B0(d, arg1);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 8:
        ret = func_L39_004D7700(d, arg1);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 2:
        ret = func_L39_004D7720(d, arg1);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    default:
        result = -0x6B;
        goto wipe;
    }
    p = &D_L39_00453FB0;
    d = p->f106A4;
    func_L39_004D7740((S_004D7740 *)d, ret);
    p->f106A8 = a + ret;
    ret = func_L39_004D6E78(op, c, p->f1069C);
    if (ret < 0) {
        result = ret;
        goto wipe;
    }
    p->f106A0 = ret;
    result = ret + c;
wipe:
    wipe_004D7770(&a, sizeof(a));
    wipe_004D7770(&ret, sizeof(ret));
    wipe_004D7770(&c, sizeof(c));
    wipe_004D7770(&d, sizeof(d));
    return result;
}
/* localdecomp:end func_L39_004D7770 */
