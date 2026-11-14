#include "common.h"

/* localdecomp:start func_L39_004D98F8 */
typedef struct S_004D98F8 {
    /* 0x00000 */ u8 pad0[0x1069C];
    /* 0x1069C */ s32 f1069C;
    /* 0x106A0 */ s32 f106A0;
    /* 0x106A4 */ u8 *f106A4;
    /* 0x106A8 */ s32 f106A8;
    /* 0x106AC */ u8 pad1[0x106D0 - 0x106AC];
    /* 0x106D0 */ s32 sema;
    /* 0x106D4 */ u8 pad2[0x1071C - 0x106D4];
    /* 0x1071C */ s32 (*send)(u8 *, s32);
    /* 0x10720 */ s32 (*reset)(void);
} S_004D98F8;

extern S_004D98F8 D_L39_00453FB0;
extern s32 func_L39_004D8660(s32, s32 *);
extern s32 func_L39_004D5B40(void);
extern s32 func_L39_004D0C78(void);
extern void func_00126280(s32);
extern s32 func_001262B0(s32);
extern s32 func_L39_004D9650(s32, s32, s32, s32, s32 *);

static __inline__ void wipe_004D98F8(void *buf) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < 0x8033; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004D98F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 len;
    s32 flag;
    s32 ret;
    s32 i;
    u8 *q;

    flag = 0;
    ret = func_L39_004D8660(D_L39_00453FB0.f1069C, &len);
    if (ret < 0) goto wipe;
    D_L39_00453FB0.f106A0 = ret;
    ret = -0x259;
    if (func_L39_004D5B40() > 0) goto wipe;
    q = (u8 *)D_L39_00453FB0.f1069C;
    for (i = 0; i < 0x400; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    func_00126280(D_L39_00453FB0.sema);
    ret = D_L39_00453FB0.send(D_L39_00453FB0.f106A4, len);
    func_001262B0(D_L39_00453FB0.sema);
    if (ret < 0) goto wipe;
    if (ret != len) {
        ret = -0x6B;
        goto wipe;
    }
    D_L39_00453FB0.f106A8 = ret;
    ret = func_L39_004D9650(arg0, ret, arg1, arg2, &flag);
    if (ret < 0) goto wipe;
    wipe_004D98F8(D_L39_00453FB0.f106A4);
    func_00126280(D_L39_00453FB0.sema);
    ret = D_L39_00453FB0.reset();
    func_001262B0(D_L39_00453FB0.sema);
    if (ret < 0) return ret;
    if (func_L39_004D5B40() > 0) return -0x259;
    if (flag != 0) return flag;
    return D_L39_00453FB0.f106A0 + D_L39_00453FB0.f106A8;
wipe:
    wipe_004D98F8(D_L39_00453FB0.f106A4);
    func_00126280(D_L39_00453FB0.sema);
    D_L39_00453FB0.reset();
    func_001262B0(D_L39_00453FB0.sema);
    return ret;
}
/* localdecomp:end func_L39_004D98F8 */
