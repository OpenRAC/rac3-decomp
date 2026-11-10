#include "common.h"

/* localdecomp:start func_L39_004C91C0 */
typedef struct S54_004C91C0 {
    u8 pad0[0xE4];
    s32 fE4;
} S54_004C91C0;

typedef struct S_004C91C0 S_004C91C0;
typedef void (*Cb_004C91C0)(S_004C91C0 *, s32, s32);

typedef struct SDC_004C91C0 {
    u8 pad0[0x88];
    Cb_004C91C0 f88;
    s32 f8C;
} SDC_004C91C0;

struct S_004C91C0 {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    s32 (*f20)(S_004C91C0 *);
    u8 pad24[0x54 - 0x24];
    S54_004C91C0 *f54;
    u8 pad58[0xCC - 0x58];
    Cb_004C91C0 fCC;
    s32 fD0;
    u8 padD4[0xDC - 0xD4];
    SDC_004C91C0 *fDC;
    u8 padE0[0x110 - 0xE0];
    u32 f110;
};

extern s32 func_L39_004C4EE0(S_004C91C0 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004C9368(S_004C91C0 *, s32, s32, s32);
extern void func_L39_004C23F8(S_004C91C0 *, s32, s32);

s32 func_L39_004C91C0(S_004C91C0 *s, s32 type, s32 buf, s32 len)
{
    Cb_004C91C0 cb = 0;
    s32 cbarg = 0;
    s32 done;
    s32 r;
    s32 p;

    s->f18 = 1;
    done = s->f54->fE4;
    s->f54->fE4 = 0;
    if ((func_L39_004C4EE0(s) & 0x3000) && s->f1C == 0) {
        if (s->f20 == 0) {
            func_L39_004BC6C8(0x14, 0x9F, 0x44D, 0, 0);
            return -1;
        }
        r = s->f20(s);
        if (r < 0) {
            return r;
        }
        if (r == 0) {
            func_L39_004BC6C8(0x14, 0x9F, 0xE5, 0, 0);
            return -1;
        }
    }
    len -= done;
    for (;;) {
        p = buf + done;
        r = func_L39_004C9368(s, type, p, s->f110 < len ? s->f110 : len);
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
            s->f54->fE4 = done;
            return r;
        }
        if (type == 0x16) {
            func_L39_004C23F8(s, p, r);
        }
        if (r == len) {
            return done + r;
        }
        len -= r;
        done += r;
    }
}
/* localdecomp:end func_L39_004C91C0 */

INCLUDE_ASM("asm/levels", func_L39_004C9368);

INCLUDE_ASM("asm/levels", func_L39_004C9568);

INCLUDE_ASM("asm/levels", func_L39_004C9678);

INCLUDE_ASM("asm/levels", func_L39_004C9E08);

INCLUDE_ASM("asm/levels", func_L39_004C9F50);

INCLUDE_ASM("asm/levels", func_L39_004CA000);

INCLUDE_ASM("asm/levels", func_L39_004CA180);
