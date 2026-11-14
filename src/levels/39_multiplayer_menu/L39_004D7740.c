#include "common.h"

/* localdecomp:start func_L39_004D7740 */
u32 func_L39_004B5910(u32);

typedef struct S_004D7740 { char pad[0x24]; u32 val; } S_004D7740;

void func_L39_004D7740(S_004D7740 *arg0, u32 arg1) {
    arg0->val = func_L39_004B5910(arg1);
}
/* localdecomp:end func_L39_004D7740 */

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

INCLUDE_ASM("asm/levels", func_L39_004D7B38);

/* localdecomp:start func_L39_004D8110 */
s32 func_L39_004D8110(u8 *arg0, u8 *arg1, u32 arg2) {
    u32 i;

    for (i = 0; i < arg2; i++) {
        if (arg0[i] < arg1[i]) {
            return -1;
        }
        if (arg1[i] < arg0[i]) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004D8110 */

INCLUDE_ASM("asm/levels", func_L39_004D8168);

INCLUDE_ASM("asm/levels", func_L39_004D83E0);

INCLUDE_ASM("asm/levels", func_L39_004D8660);

INCLUDE_ASM("asm/levels", func_L39_004D8BC0);

INCLUDE_ASM("asm/levels", func_L39_004D8CB0);

INCLUDE_ASM("asm/levels", func_L39_004D8E10);

/* localdecomp:start func_L39_004D8F00 */
extern s32 func_L39_004D8BC0(s32);
extern s32 func_L39_004D8CB0(s32, s32, s32);
extern void func_L39_004B4520(s32);
extern s32 func_L39_004D8E10(s32);

s32 func_L39_004D8F00(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 *arg4) {
    s32 n;
    if (func_L39_004D8BC0(arg3) < 0) return -0x6A;
    n = func_L39_004D8CB0(arg0, arg1, arg3);
    if (n < 0) return -0x6A;
    if (n == 0) *arg4 = 1;
    if (arg0 == 5) {
        func_L39_004B4520(arg3 + 4);
    } else if (func_L39_004D8E10(arg3) < 0) {
        return -0x6A;
    }
    *arg2 = func_L39_004B5910(*(u32 *)(arg3 + 0x24));
    return 0x28;
}
/* localdecomp:end func_L39_004D8F00 */

/* localdecomp:start func_L39_004D8FD0 */
extern s32 D_L39_00464668[];
s32 func_L39_004CDC00(void);
s32 func_L39_004B4620(u8 *);
s32 func_L39_004B4700(u8 *);
s32 func_L39_004D8FD0(u8 *arg0, s32 arg1) {
    s32 ret = func_L39_004CDC00();
    u8 *p = arg0;
    s32 n;
    if (ret < 0) return ret;
    if (ret != 0 && !(D_L39_00464668[0] & 1)) p = arg0 + func_L39_004B4620(arg0);
    p += func_L39_004B4700(p);
    n = p - arg0;
    if (arg1 != n) return -0x6A;
    return n;
}
/* localdecomp:end func_L39_004D8FD0 */

INCLUDE_ASM("asm/levels", func_L39_004D9058);

INCLUDE_ASM("asm/levels", func_L39_004D9168);

INCLUDE_ASM("asm/levels", func_L39_004D9330);

INCLUDE_ASM("asm/levels", func_L39_004D9508);
