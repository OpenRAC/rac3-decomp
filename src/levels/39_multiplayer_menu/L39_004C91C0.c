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

/* localdecomp:start func_L39_004C9568 */
typedef struct S2_004C9568 {
    u8 pad0[0xA4];
    s32 xA4;
    s32 xA8;
    s32 xAC;
    u8 padB0[0x38];
    s32 xE8;
    s32 xEC;
    s32 xF0;
    s32 xF4;
} S2_004C9568;

typedef struct S_004C9568 {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[4];
    s32 x18;
    u8 pad1C[0x38];
    S2_004C9568 *p54;
} S_004C9568;

extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004DACB0(s32, s32, s32);

s32 func_L39_004C9568(S_004C9568 *a, s32 a1, s32 a2, s32 a3) {
    s32 r;
    if (a3 < a->p54->xE8 || a->p54->xF4 != a2 || a->p54->xEC != a1) {
        func_L39_004BC6C8(0x14, 0xA0, 0x7F, 0, 0);
        return -1;
    }
    for (;;) {
        *func_0011A6E0() = 0;
        if (a->x10 != 0) {
            a->x18 = 2;
            r = func_L39_004DACB0(a->x10, a->p54->xAC + a->p54->xA8, a->p54->xA4);
        } else {
            func_L39_004BC6C8(0x14, 0xA0, 0x80, 0, 0);
            r = -1;
        }
        if (r == a->p54->xA4) {
            a->p54->xA4 = 0;
            a->x18 = 1;
            return a->p54->xF0;
        }
        if (r <= 0) {
            return r;
        }
        a->p54->xA8 += r;
        a->p54->xA4 -= r;
    }
}
/* localdecomp:end func_L39_004C9568 */

/* localdecomp:start func_L39_004C9678 */
typedef struct REC_004C9678 {
    s32 type;
    u32 length;
    s32 off;
    u8 *data;
} REC_004C9678;

typedef struct S3_004C9678 {
    u64 flags;
    u8 pad8[0x94 - 8];
    s32 f94;
    u8 pad98[0xB4 - 0x98];
    REC_004C9678 rrec;
    u8 padC4[0x100 - 0xC4];
    s32 f100;
    s32 f104;
    s32 f108;
    u8 pad10C[0x114 - 0x10C];
    s32 f114;
    s32 f118;
    u8 pad11C[0x120 - 0x11C];
    s32 f120;
} S3_004C9678;

typedef struct SESS_004C9678 {
    u8 pad0[0xAC];
    s32 fAC;
} SESS_004C9678;

typedef struct S_004C9678 S_004C9678;
typedef void (*Cb3_004C9678)(S_004C9678 *, s32, s32);
typedef void (*Cb4_004C9678)(S_004C9678 *, s32, s32, s32);

typedef struct CTX_004C9678 {
    u8 pad0[0x7C];
    Cb3_004C9678 f7C;
    Cb4_004C9678 f80;
    s32 f84;
    Cb3_004C9678 f88;
    s32 f8C;
} CTX_004C9678;

struct S_004C9678 {
    s32 f0;
    u8 pad4[0x18 - 4];
    s32 f18;
    s32 f1C;
    s32 (*f20)(S_004C9678 *);
    u8 pad24[4];
    s32 f28;
    s32 f2C;
    s32 f30;
    u8 pad34[4];
    s32 f38;
    u8 pad3C[0x54 - 0x3C];
    S3_004C9678 *f54;
    u8 pad58[0x70 - 0x58];
    s32 f70;
    u8 pad74[0xB0 - 0x74];
    SESS_004C9678 *fB0;
    u8 padB4[0xC0 - 0xB4];
    Cb3_004C9678 fC0;
    Cb4_004C9678 fC4;
    s32 fC8;
    Cb3_004C9678 fCC;
    s32 fD0;
    u8 padD4[0xDC - 0xD4];
    CTX_004C9678 *fDC;
};

extern s32 func_L39_004C21E0(void *);
extern s32 func_L39_004C8E30(void *);
extern void func_L39_004C3198(void *);
extern s32 func_L39_004C31D8(void *);
extern s32 func_L39_004C9E08(void *);
extern void func_L39_004CBA18(void *, void *);
extern void *func_L39_004EC7B8(void *);
extern void func_L39_004BB428(void *);
extern void func_L39_004BB400(void *);
extern void func_L39_004DE348(s32, ...);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void *func_0011D380(void *, const void *, unsigned int);
extern u8 D_L39_00475C40[];
extern u8 D_L39_00475C48[];
extern s32 func_L39_004C9F50(void *, s32, s32);

s32 func_L39_004C9678(S_004C9678 *s, s32 type, s32 buf, s32 len)
{
    REC_004C9678 *rr;
    u8 tmp[16];
    Cb3_004C9678 cbh = 0;
    Cb3_004C9678 cb = 0;
    Cb4_004C9678 cb4 = 0;
    s32 cb4arg = 0;
    s32 cbarg = 0;
    s32 al;
    s32 i;
    s32 j;
    s32 ret;
    u32 n;

    if (s->f54->f94 == 0) {
        if (func_L39_004C21E0(s) == 0) {
            return -1;
        }
    }
    if (s->f1C == 0 && (func_L39_004C4EE0((S_004C91C0 *)s) & 0x3000)) {
        if (s->f20 == 0) {
            func_L39_004BC6C8(0x14, 0x95, 0x44D, 0, 0);
            goto err;
        }
        i = s->f20(s);
        if (i < 0) {
            return i;
        }
        if (i == 0) {
            func_L39_004BC6C8(0x14, 0x95, 0xE5, 0, 0);
            goto err;
        }
    }
start:
    s->f18 = 1;
    rr = &s->f54->rrec;
    if (rr->length == 0 || s->f38 == 0xF1) {
        ret = func_L39_004C8E30(s);
        if (ret <= 0) {
            return ret;
        }
    }
    if ((s->f54->f100 != 0 && rr->type != 0x16) ||
        ((s->f54->flags & 0x800000) && rr->type != 0x14)) {
        func_L39_004BC6C8(0x14, 0x95, 0x91, 0, 0);
        goto err;
    }
    if (s->f2C & 2) {
        rr->length = 0;
        s->f18 = 1;
        return 0;
    }
    if (rr->type == 0x16 && rr->length == 4 && rr->data[0] == 0 && s->fB0 != 0 && s->fB0->fAC != 0) {
        if (rr->data[1] != 0 || rr->data[2] != 0 || rr->data[3] != 0) {
            func_L39_004BC6C8(0x14, 0x95, 0x69, 0, 0);
            goto err;
        }
        if (s->fC0 != 0) {
            cbh = s->fC0;
        } else if (s->fDC->f7C != 0) {
            cbh = s->fDC->f7C;
        }
        if (cbh != 0) {
            s32 save = s->f30;
            s->f30 = 0x1101;
            cbh(s, 0x1001, 1);
            s->f30 = save;
        }
        if (func_L39_004C4EE0((S_004C91C0 *)s) == 3 && !(s->f54->flags & 1) && s->f54->f114 == 0) {
            func_L39_004C3198(s);
            if (func_L39_004C31D8(s) != 0) {
                j = s->f20(s);
                if (j < 0) {
                    return j;
                }
                if (j == 0) {
                    func_L39_004BC6C8(0x14, 0x95, 0xE5, 0, 0);
                    goto err;
                }
            }
        }
        rr->length = 0;
        goto start;
    }
    if (rr->type != type || (s->f2C & 1)) {
        if (rr->type == 0x15) {
            al = 0x32;
            if (rr->length != 2 || rr->off != 0) {
                func_L39_004BC6C8(0x14, 0x95, 0x65, 0, 0);
                goto f_err;
            }
            i = rr->data[0];
            j = rr->data[1];
            rr->length = 0;
            if (s->fC0 != 0) {
                cb = s->fC0;
            } else if (s->fDC->f7C != 0) {
                cb = s->fDC->f7C;
            }
            if (s->fC4 != 0) {
                cb4 = s->fC4;
                cb4arg = s->fC8;
            } else if (s->fDC->f80 != 0) {
                cb4arg = s->fDC->f84;
                cb4 = s->fDC->f80;
            }
            if (cb != 0) {
                cb(s, 0x4004, (i << 8) | j);
            }
            if (cb4 != 0) {
                cb4(s, 0x4004, (i << 8) | j, cb4arg);
            }
            if (i == 1) {
                s->f54->f104 = j;
                if (j == 0) {
                    s->f2C |= 2;
                    return 0;
                }
                rr->length = 0;
                goto start;
            }
            if (i == 2) {
                s->f18 = 1;
                s->f54->f108 = j;
                func_L39_004BC6C8(0x14, 0x95, j + 0x3E8, 0, 0);
                func_00120048(tmp, D_L39_00475C40, j);
                func_L39_004DE348(2, D_L39_00475C48, tmp);
                s->f2C |= 2;
                func_L39_004CBA18(s->fDC, s->fB0);
                return 0;
            }
            al = 0x2F;
            func_L39_004BC6C8(0x14, 0x95, 0xF6, 0, 0);
            goto f_err;
        }
        if (s->f2C & 1) {
            s->f18 = 1;
            rr->length = 0;
            return 0;
        }
        if (rr->type == 0x14) {
            if (rr->length != 1 || rr->off != 0 || rr->data[0] != 1) {
                func_L39_004BC6C8(0x14, 0x95, 0x67, 0, 0);
                goto err;
            }
            rr->length = 0;
            s->f54->f100 = 1;
            if (func_L39_004C9E08(s) == 0) {
                goto err;
            }
            goto start;
        }
        if (rr->type == 0x16 && s->f1C == 0) {
            if ((s->f30 & 0xFFF) == 3 && !(s->f54->flags & 1)) {
                if (s->f54->flags & 0x10) {
                    s->f30 = 0x11D0;
                    s->f54->flags &= ~0x10;
                } else {
                    s->f30 = 0x2000;
                    s->f28 = 1;
                }
            }
            j = s->f20(s);
            if (j < 0) {
                return j;
            }
            if (j == 0) {
                func_L39_004BC6C8(0x14, 0x95, 0xE5, 0, 0);
                return -1;
            }
            s->f18 = 3;
            {
                void *bio = func_L39_004EC7B8(s);
                func_L39_004BB428(bio);
                func_L39_004BB400(bio);
            }
            return -1;
        }
        switch (rr->type) {
        default:
            if (s->f0 == 0x301) {
                goto start;
            }
        case 0x14:
        case 0x15:
        case 0x16:
            al = 0xA;
            func_L39_004BC6C8(0x14, 0x95, 0xF5, 0, 0);
            goto f_err;
        case 0x17:
            if (s->f54->f120 != 0 && s->f54->f118 != 0 &&
                (((s->f30 & 0x1000) && s->f30 >= 0x1110 && s->f30 < 0x1121) ||
                 ((s->f30 & 0x2000) && s->f30 < 0x2121 && s->f30 >= 0x2110))) {
                s->f54->f120 = 0;
                return -1;
            }
            al = 0xA;
            func_L39_004BC6C8(0x14, 0x95, 0xF5, 0, 0);
            goto f_err;
        }
    } else {
        if ((func_L39_004C4EE0((S_004C91C0 *)s) & 0x3000) && type == 0x17 && s->f70 == 0) {
            al = 0xA;
            func_L39_004BC6C8(0x14, 0x95, 0x64, 0, 0);
            goto f_err;
        }
        if (s->f1C == 0) {
            if (s->fCC != 0) {
                cb = s->fCC;
                cbarg = s->fD0;
            } else if (s->fDC->f88 != 0) {
                cbarg = s->fDC->f8C;
                cb = s->fDC->f88;
            }
            if (cb != 0) {
                cb(s, 4, cbarg);
            }
        }
        if (len <= 0) {
            return len;
        }
        n = len;
        if (rr->length < n) {
            n = rr->length;
        }
        func_0011D380((void *)buf, rr->data + rr->off, n);
        rr->length -= n;
        rr->off += n;
        if (rr->length == 0) {
            s->f38 = 0xF0;
            rr->off = 0;
        }
        if (type == 0x16) {
            func_L39_004C23F8((S_004C91C0 *)s, buf, n);
        }
        return n;
    }
f_err:
    func_L39_004C9F50(s, 2, al);
err:
    return -1;
}
/* localdecomp:end func_L39_004C9678 */

INCLUDE_ASM("asm/levels", func_L39_004C9E08);

/* localdecomp:start func_L39_004C9F50 */
extern void func_L39_004CBA18(void *, void *);
extern s32 func_L39_004CA000(void *);

typedef struct SV_004C9F50 {
    u8 pad0[0x50];
    s32 (*f50)(s32);
} SV_004C9F50;

typedef struct SW_004C9F50 {
    u8 pad0[0x54];
    SV_004C9F50 *f54;
} SW_004C9F50;

typedef struct SX_004C9F50 {
    u8 pad0[0xA4];
    s32 fA4;
    u8 padA8[0x10C - 0xA8];
    s32 f10C;
    u8 f110;
    u8 f111;
} SX_004C9F50;

typedef struct S_004C9F50 {
    u8 pad0[8];
    SW_004C9F50 *f8;
    u8 padC[0x54 - 0xC];
    SX_004C9F50 *f54;
    u8 pad58[0xB0 - 0x58];
    void *fB0;
    u8 padB4[0xDC - 0xB4];
    void *fDC;
} S_004C9F50;

s32 func_L39_004C9F50(void *a, s32 arg1, s32 arg2) {
    S_004C9F50 *arg0 = a;
    s32 r = arg0->f8->f54->f50(arg2);
    if (r < 0) {
        return 1;
    }
    if (arg1 == 2 && arg0->fB0 != 0) {
        func_L39_004CBA18(arg0->fDC, arg0->fB0);
    }
    arg0->f54->f10C = 1;
    arg0->f54->f110 = arg1;
    arg0->f54->f111 = r;
    if (arg0->f54->fA4 == 0) {
        return func_L39_004CA000(arg0);
    }
    return -1;
}
/* localdecomp:end func_L39_004C9F50 */

INCLUDE_ASM("asm/levels", func_L39_004CA000);

INCLUDE_ASM("asm/levels", func_L39_004CA180);
