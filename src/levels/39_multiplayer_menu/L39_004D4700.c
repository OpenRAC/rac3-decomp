#include "common.h"

/* localdecomp:start func_L39_004D4700 */
extern s32 func_L39_004D1DC8(s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004D4700(s32 arg0, s32 arg1, s32 arg2)
{
    return func_L39_004D1DC8(arg1, arg2, arg2 + 8, arg2 + 16, arg0, arg2 + 24, 1);
}
/* localdecomp:end func_L39_004D4700 */

INCLUDE_ASM("asm/levels", func_L39_004D4730);

LINKER_REMNANT("asm/levels", func_L39_004D4D10);

INCLUDE_ASM("asm/levels", func_L39_004D4D18);

INCLUDE_ASM("asm/levels", func_L39_004D4E68);

INCLUDE_ASM("asm/levels", func_L39_004D5030);

LINKER_REMNANT("asm/levels", func_L39_004D51E8);

INCLUDE_ASM("asm/levels", func_L39_004D51F0);

/* localdecomp:start func_L39_004D5288 */
extern s32 func_00129E18(void *, s32, s32, s32, s32, void *, s32, s32, s32);
extern s32 func_00127108(s32);

/* call the RPC, retrying up to 100 times with a 10 ms delay between tries */
s32 func_L39_004D5288(void *cd, s32 fno, s32 mode, s32 send, s32 ssize, void *recv, s32 rsize, s32 end, s32 arg) {
    s32 i;
    s32 ret;

    i = 0;
    for (;;) {
        i++;
        if (i > 100) {
            ret = -1;
            break;
        }
        if (func_00129E18(cd, fno, mode, send, ssize, recv, rsize, end, arg) == 0) {
            ret = 0;
            break;
        }
        if (func_00127108(10000) < 0) {
            ret = -1;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004D5288 */

/* localdecomp:start func_L39_004D5370 */
extern u8 D_L39_00453FB0[];
extern s32 func_001262A0(s32);
extern s32 func_L39_004D5488(s32, s32, s32);

void func_L39_004D5370(s32 arg0, s32 arg1)
{
    u8 *p = D_L39_00453FB0;
    u8 *q = p + 0x10544;
    u32 i;

    (*(void (**)(void))(p + 0x10720))();
    for (i = 0; i < 0x20; i++) {
        q[i] = 0;
    }
    p = D_L39_00453FB0;
    func_001262A0(*(s32 *)(p + 0x106D4));
    func_L39_004D5488(0, arg1 ? -1 : *(s32 *)(p + 0x106B4), arg0);
}
/* localdecomp:end func_L39_004D5370 */

/* localdecomp:start func_L39_004D5420 */
extern u8 D_L39_00453FB0[];
extern void func_L39_004D5370(s32, s32);
extern void func_001262B0(s32);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);

void func_L39_004D5420(void)
{
    u8 *p = D_L39_00453FB0;

    func_L39_004D5370(0, 1);
    func_001262B0(*(s32 *)(p + 0x106C4));
    func_001262A0(*(s32 *)(p + 0x106C8));
    *(s32 *)(p + 0x106F4) = 0;
    func_00126280(*(s32 *)(p + 0x106C8));
}
/* localdecomp:end func_L39_004D5420 */

/* localdecomp:start func_L39_004D5488 */
extern u8 D_L39_00453FB0[];
extern void func_001262B0(s32);

typedef struct {
    u8 pad0[0x10684];
    u8 b0;
    u8 b1;
    u8 b2;
    u8 pad1[0x106B4 - 0x10687];
    s32 state;
    s32 pad2;
    s32 semB;
    s32 pad3;
    s32 semA;
    s32 lock;
} S_004D5488;

typedef struct {
    s32 count;
    s32 maxCount;
    s32 initCount;
    s32 waitThreads;
    s32 attr;
    u32 option;
} SEMA_004D5488;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} O_004D5488;


extern O_004D5488 D_L39_004646B0;
extern s32 func_001262A0(s32);
extern void func_00126280(s32);
extern s32 func_001262D0(s32, SEMA_004D5488 *);


static __inline__ s32 word_004D5488(s32 c) {
    s32 b0 = ((S_004D5488 *)D_L39_00453FB0)->b0;
    s32 b1 = ((S_004D5488 *)D_L39_00453FB0)->b1;
    s32 b2 = ((S_004D5488 *)D_L39_00453FB0)->b2;

    return (((b1 << 4) | (b0 << 8)) & 0x3F0) | ((c << 24) | (b2 << 2));
}

s32 func_L39_004D5488(s32 op, s32 a1, s32 a2) {
    s32 ret = 0;
    SEMA_004D5488 sema;
    s32 i;
    s32 c;
    O_004D5488 *o = &D_L39_004646B0;

    func_001262A0(((S_004D5488 *)D_L39_00453FB0)->lock);
    switch (op) {
    case 0:
        ret = func_001262D0(((S_004D5488 *)D_L39_00453FB0)->semA, &sema);
        if (ret < 0) goto out;
        for (i = 0; i < sema.count; i++) ((s32 (*)(s32))func_001262B0)(((S_004D5488 *)D_L39_00453FB0)->semA);
        ret = func_001262D0(((S_004D5488 *)D_L39_00453FB0)->semB, &sema);
        if (ret < 0) goto out;
        for (i = 0; i < sema.count; i++) ((s32 (*)(s32))func_001262B0)(((S_004D5488 *)D_L39_00453FB0)->semB);
        if (a1 < 0) {
            o->f0 = 2;
            o->f4 = 0;
        } else if (a1 == 10 || a1 == 11) {
            if (a1 == 10) {
                o->f0 = 6;
            } else if (a1 == 11) {
                o->f0 = 7;
            }
            o->f4 = a2;
        } else {
            switch (a1) {
            case 4: c = 1; o->f0 = 5; break;
            case 8: c = 2; o->f0 = 5; break;
            case 7: c = 3; o->f0 = 5; break;
            case 13: c = 4; o->f0 = 5; break;
            default: ret = -1; goto out;
            }
            o->f4 = word_004D5488(c);
        }
        o->f8 = 0;
        break;
    case 1:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 0) { ret = -1; goto out; }
        break;
    case 2:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 1) { ret = -1; goto out; }
        break;
    case 3:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 2) { ret = -1; goto out; }
        o->f8 = 2;
        break;
    case 4:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 3) { ret = -1; goto out; }
        break;
    case 5:
        switch (((S_004D5488 *)D_L39_00453FB0)->state) {
        case 4:
            o->f8 = 3;
            break;
        case 7:
            o->f0 = 8;
            o->f8 = 7;
            o->f4 = word_004D5488(3);
            break;
        default:
            ret = -1;
            goto out;
        }
        break;
    case 7:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 5) { ret = -1; goto out; }
        o->f8 = 5;
        break;
    case 12:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 4) { ret = -1; goto out; }
        o->f8 = 3;
        break;
    case 13:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 12) { ret = -1; goto out; }
        o->f8 = 8;
        break;
    case 6:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 4) { ret = -1; goto out; }
        o->f8 = 3;
        break;
    case 8:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 6) { ret = -1; goto out; }
        o->f8 = 4;
        break;
    }
    ((S_004D5488 *)D_L39_00453FB0)->state = op;
out:
    func_00126280(((S_004D5488 *)D_L39_00453FB0)->lock);
    return ret;
}
/* localdecomp:end func_L39_004D5488 */
