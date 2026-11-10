#include "common.h"

/* localdecomp:start func_L39_004C59D8 */
typedef struct S50_004C59D8 {
    u8 pad0[0x10];
    s32 f10;
} S50_004C59D8;

typedef struct S_004C59D8 S_004C59D8;
typedef void (*Cb_004C59D8)(S_004C59D8 *, s32, s32);

typedef struct SDC_004C59D8 {
    u8 pad0[0x88];
    Cb_004C59D8 f88;
    s32 f8C;
} SDC_004C59D8;

struct S_004C59D8 {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    s32 (*f20)(S_004C59D8 *);
    u8 pad24[0x50 - 0x24];
    S50_004C59D8 *f50;
    u8 pad54[0xCC - 0x54];
    Cb_004C59D8 fCC;
    s32 fD0;
    s32 fD4;
    u8 padD8[0xDC - 0xD8];
    SDC_004C59D8 *fDC;
};

extern s32 func_L39_004C4EE0(S_004C59D8 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004C6120(S_004C59D8 *);
extern s32 *func_11A6E0(void);
extern s32 func_L39_004C5C88(S_004C59D8 *, s32, s32);

s32 func_L39_004C59D8(S_004C59D8 *s, s32 buf, s32 len)
{
    Cb_004C59D8 cb = 0;
    s32 cbarg = 0;
    s32 done;
    s32 r;

    if ((func_L39_004C4EE0(s) & 0x3000) && s->f1C == 0) {
        if (s->f20 == 0) {
            func_L39_004BC6C8(0x14, 0x7F, 0x44D, 0, 0);
            return -1;
        }
        r = s->f20(s);
        if (r < 0) {
            return r;
        }
        if (r == 0) {
            func_L39_004BC6C8(0x14, 0x7F, 0xE5, 0, 0);
            return -1;
        }
    }
    if (s->fD4 != 0) {
        func_L39_004C6120(s);
        if (s->fD4 != 0) {
            return -1;
        }
    }
    *func_11A6E0() = 0;
    s->f18 = 1;
    if (len <= 0) {
        return len;
    }
    done = s->f50->f10;
    s->f50->f10 = 0;
    len -= done;
    for (;;) {
        r = func_L39_004C5C88(s, buf + done, len);
        if (s->f1C == 0) {
            if (s->fCC != 0) {
                cb = s->fCC;
                cbarg = s->fD0;
            } else if (s->fDC->f88 != 0) {
                cbarg = s->fDC->f8C;
                cb = s->fDC->f88;
            }
            if (cb != 0) {
                cb(s, 8, cbarg);
            }
        }
        if (r <= 0) {
            s->f50->f10 = done;
            return r;
        }
        if (r == len) {
            return done + r;
        }
        len -= r;
        done += r;
    }
}
/* localdecomp:end func_L39_004C59D8 */

INCLUDE_ASM("asm/levels", func_L39_004C5B80);

INCLUDE_ASM("asm/levels", func_L39_004C5C88);
