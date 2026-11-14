#include "common.h"

/* localdecomp:start func_L39_004BB4C0 */
extern s32 func_L39_004BB4B0(void);
extern void *func_L39_004DA968(s32);
extern void func_L39_004DAE28(s32, s32, s32, s32);

void *func_L39_004BB4C0(s32 arg0, s32 arg1) {
    void *p;

    p = func_L39_004DA968(func_L39_004BB4B0());
    if (p == 0) {
        return 0;
    }
    func_L39_004DAE28((s32)p, 0x68, arg1, arg0);
    return p;
}
/* localdecomp:end func_L39_004BB4C0 */

/* localdecomp:start func_L39_004BB528 */
typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x4];
    s32 unk14;
    u8 pad18[0x4];
    s32 unk1C;
    s32 unk20;
} S_004BB528;

s32 func_L39_004BB528(S_004BB528 *arg0) {
    arg0->unkC = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk14 = 0;
    return 1;
}
/* localdecomp:end func_L39_004BB528 */

/* localdecomp:start func_L39_004BB540 */
typedef struct S_004BB540 {
    s32 pad0[3];
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 pad18;
    s32 f1C;
} S_004BB540;

extern s32 func_L01_00422FE0(s32, s32);

s32 func_L39_004BB540(void *arg0) {
    S_004BB540 *p = arg0;

    if (p == 0) {
        return 0;
    }
    if (p->f10 == 0) {
        return 1;
    }
    if (p->f0C == 0) {
        p->f14 = 0;
    } else {
        func_L01_00422FE0(p->f1C, 2);
        func_L01_00422FE0(p->f1C, 2);
        p->f14 = 0;
    }
    p->f0C = 0;
    return 1;
}
/* localdecomp:end func_L39_004BB540 */

/* localdecomp:start func_L39_004BB5A8 */
/* log: 1) twin of func_L39_00500568 (L39_005000E0.c): missing sign-extend; 2) callee returns s64 */
typedef struct S_004BB5A8 {
    s32 pad0[7];
    s32 f1C;
} S_004BB5A8;

extern s32 *func_L01_003E4008(void);
extern s64 func_L01_00412E50(s32, void *, s32, s32);
extern void func_L39_004BB428(void *);
extern void func_L39_004BB400(void *);
extern s32 func_L39_004CA228(s32);

s32 func_L39_004BB5A8(S_004BB5A8 *arg0, void *arg1, s32 arg2) {
    s32 r = 0;

    if (arg1 != 0) {
        *func_L01_003E4008() = 0;
        r = func_L01_00412E50(arg0->f1C, arg1, arg2, 0);
        func_L39_004BB428(arg0);
        if (r <= 0 && func_L39_004CA228(r) != 0) {
            func_L39_004BB400(arg0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_004BB5A8 */

INCLUDE_ASM("asm/levels", func_L39_004BB648);

/* localdecomp:start func_L39_004BB6D0 */
typedef struct S_004BB6D0 {
    s32 pad0[3];
    s32 init;
    s32 shutdown;
    s32 pad14[2];
    s32 num;
} S_004BB6D0;

extern s32 func_L39_004BB540(void *);
extern s32 func_L39_004CA1F8(s32, s32);

s64 func_L39_004BB6D0(S_004BB6D0 *b, s32 cmd, s64 num, s32 *ptr) {
    s64 ret = 1;

    switch (cmd) {
    case 1:
    case 0x80:
        ret = 1;
        break;
    case 0x68:
        func_L39_004BB540(b);
        b->num = *ptr;
        b->shutdown = (num & 1) ? 1 : 0;
        b->init = 1;
        break;
    case 0x69:
        if (b->init) {
            if (ptr != 0) {
                *ptr = b->num;
            }
            ret = b->num;
        } else {
            ret = -1;
        }
        break;
    case 8:
        ret = b->shutdown;
        break;
    case 9:
        b->shutdown = (num & 1) ? 1 : 0;
        break;
    case 0x66:
        ret = func_L39_004CA1F8(b->num, num);
        break;
    case 3:
    case 0x85:
    case 10:
    case 13:
        ret = 0;
        break;
    case 11:
    case 12:
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004BB6D0 */

/* localdecomp:start func_L39_004BB838 */
extern s32 func_00120884(const char *);
extern s32 func_L39_004BB648(void *, const char *, s32);

s32 func_L39_004BB838(void *arg0, const char *arg1) {
    return func_L39_004BB648(arg0, arg1, func_00120884(arg1));
}
/* localdecomp:end func_L39_004BB838 */

/* localdecomp:start func_L39_004BB880 */
extern s32 D_L39_004433B8[];
extern void func_0011D534(void *, s32, s32);

void func_L39_004BB880(void) {
    func_0011D534(D_L39_004433B8, 0, 0xE8);
}
/* localdecomp:end func_L39_004BB880 */
