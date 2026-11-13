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

/* localdecomp:start func_L39_004C9368 */
struct S_004C9368;
struct S3_004C9368;

typedef struct E_004C9368 {
    s32 (*enc)(struct S_004C9368 *, s32);
    s32 (*mac)(struct S_004C9368 *, u8 *, s32);
} E_004C9368;

typedef struct M_004C9368 {
    char _p0[0x54];
    E_004C9368 *enc;
} M_004C9368;

typedef struct S_004C9368 {
    s32 version;
    s32 f4;
    M_004C9368 *method;
    char _pC[0x54 - 0xC];
    struct S3_004C9368 *s3;
    char _p58[0x74 - 0x58];
    s32 mac_size;
    void *write_hash;
    void *enc_write_ctx;
    char _p80[0xB0 - 0x80];
    void *session;
} S_004C9368;

typedef struct B_004C9368 {
    char _p0[8];
    s32 left;
    s32 offset;
    u8 *buf;
} B_004C9368;

typedef struct R_004C9368 {
    s32 type;
    u32 length;
    s32 f8;
    u8 *data;
    u8 *input;
} R_004C9368;

typedef struct S3_004C9368 {
    char _p0[0x9C];
    B_004C9368 wbuf;
    char _pB0[0xCC - 0xB0];
    R_004C9368 wrec;
    char _pE0[0xE8 - 0xE0];
    u32 wpend_tot;
    s32 wpend_type;
    s32 wpend_ret;
    u8 *wpend_buf;
    char _pF8[0x10C - 0xF8];
    s32 alert_dispatch;
} S3_004C9368;

struct S_004C9568;
extern s32 func_L39_004C9568(struct S_004C9568 *, s32, s32, s32);
extern s32 func_L39_004CA000(void *);
extern void *func_0011D380(void *, const void *, unsigned int);

s32 func_L39_004C9368(S_004C91C0 *arg0, s32 type, s32 arg2, s32 len) {
    S_004C9368 *s = (S_004C9368 *)arg0;
    u8 *buf = (u8 *)arg2;
    u8 *p;
    u8 *plen;
    s32 i;
    s32 mac_size;
    s32 clear = 0;
    R_004C9368 *wr;
    B_004C9368 *wb;
    void *sess;

    if (s->s3->wbuf.left != 0) {
        return func_L39_004C9568((struct S_004C9568 *)s, type, (s32)buf, len);
    }
    if (s->s3->alert_dispatch) {
        i = func_L39_004CA000(s);
        if (i <= 0) {
            return i;
        }
    }
    if (len == 0) {
        return len;
    }
    wr = &s->s3->wrec;
    wb = &s->s3->wbuf;
    sess = s->session;
    if (sess == 0 || s->enc_write_ctx == 0 || s->write_hash == 0) {
        clear = 1;
    }
    if (clear) {
        mac_size = 0;
    } else {
        mac_size = s->mac_size;
    }
    p = wb->buf;
    *(p++) = type & 0xFF;
    wr->type = type;
    *(p++) = s->version >> 8;
    *(p++) = s->version & 0xFF;
    plen = p;
    p += 2;
    wr->data = p;
    wr->length = len;
    wr->input = buf;
    func_0011D380(wr->data, wr->input, wr->length);
    wr->input = wr->data;
    if (mac_size != 0) {
        if (s->method->enc->mac(s, &p[wr->length], 1) <= 0) {
            goto err;
        }
        wr->length += mac_size;
        wr->input = p;
        wr->data = p;
    }
    s->method->enc->enc(s, 1);
    plen[0] = wr->length >> 8;
    plen[1] = wr->length & 0xFF;
    wr->type = type;
    wr->length += 5;
    wb->left = wr->length;
    wb->offset = 0;
    s->s3->wpend_tot = len;
    s->s3->wpend_buf = buf;
    s->s3->wpend_type = type;
    s->s3->wpend_ret = len;
    return func_L39_004C9568((struct S_004C9568 *)s, type, (s32)buf, len);
err:
    return -1;
}
/* localdecomp:end func_L39_004C9368 */

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

/* localdecomp:start func_L39_004C9E08 */
typedef struct ENC_004C9E08 {
    u8 pad0[8];
    s32 (*setup_key_block)(void *);
    u8 padC[4];
    s32 (*change_cipher_state)(void *, s32);
    s32 (*final_finish_mac)(void *, s32, s32, u8 *, s32, u8 *);
    u8 pad18[8];
    u8 client_label[0x14];
    s32 client_len;
    u8 server_label[0x14];
    s32 server_len;
} ENC_004C9E08;

typedef struct METH_004C9E08 {
    u8 pad0[0x54];
    ENC_004C9E08 *enc;
} METH_004C9E08;

typedef struct S3_004C9E08 {
    unsigned long flags;
    u8 pad8[0xF0];
    s32 fF8;
    s32 fFC;
    u8 pad100[0x28];
    u8 finish_md[4];
    u8 pad12C[0x30];
    s32 new_cipher;
    u8 pad160[0x28];
    s32 key_block;
} S3_004C9E08;

typedef struct SESS_004C9E08 {
    u8 pad0[0xAC];
    s32 cipher;
} SESS_004C9E08;

typedef struct CTX_004C9E08 {
    u8 pad0[0x7C];
    void (*info_callback)(void *, s32, s32);
} CTX_004C9E08;

typedef struct S_004C9E08 {
    u8 pad0[8];
    METH_004C9E08 *method;
    u8 padC[0x24];
    s32 state;
    u8 pad34[0x20];
    S3_004C9E08 *s3;
    u8 pad58[0x58];
    SESS_004C9E08 *session;
    u8 padB4[0xC];
    void (*info_callback)(void *, s32, s32);
    u8 padC4[0x18];
    CTX_004C9E08 *ctx;
} S_004C9E08;

s32 func_L39_004C9E08(void *arg) {
    S_004C9E08 *s = arg;
    s32 saved = s->state;
    s32 n;
    s32 newstate;
    void (*cb)(void *, s32, s32);
    u8 *label;
    s32 llen;

    if (saved & 0x2000) {
        n = 0x21;
        newstate = 0x11A0;
    } else {
        n = 0x11;
        newstate = 0x11C0;
    }
    cb = 0;
    if (s->info_callback != 0) {
        cb = s->info_callback;
    } else if (s->ctx->info_callback != 0) {
        cb = s->ctx->info_callback;
    }
    if (cb != 0) {
        s->state = newstate;
        cb(s, 0x1001, 1);
        s->state = saved;
    }
    if (s->s3->key_block == 0) {
        s->session->cipher = s->s3->new_cipher;
        if (!s->method->enc->setup_key_block(s)) {
            return 0;
        }
    }
    if (!s->method->enc->change_cipher_state(s, n)) {
        return 0;
    }
    if ((s->state & 0x1000) || (s->s3->flags & 0x10)) {
        label = s->method->enc->server_label;
        llen = s->method->enc->server_len;
    } else {
        label = s->method->enc->client_label;
        llen = s->method->enc->client_len;
    }
    return s->method->enc->final_finish_mac(s, s->s3->fF8, s->s3->fFC, label, llen, s->s3->finish_md) != 0;
}
/* localdecomp:end func_L39_004C9E08 */

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

/* localdecomp:start func_L39_004CA000 */
typedef void (*Fn_004CA000)();
typedef struct P_004CA000 {
    char p0[0x10C];
    s32 f10C;
    s8 f110;
    s8 f111;
} P_004CA000;
typedef struct V_004CA000 {
    char p0[0x7C];
    Fn_004CA000 f7C;
    Fn_004CA000 f80;
    s32 f84;
} V_004CA000;
typedef struct S_004CA000 {
    char p0[0x10];
    s32 f10;
    char p14[4];
    s32 f18;
    char p1C[0x38];
    P_004CA000 *f54;
    char p58[0x68];
    Fn_004CA000 fC0;
    Fn_004CA000 fC4;
    s32 fC8;
    char pCC[0x10];
    V_004CA000 *fDC;
    s32 fE0;
} S_004CA000;
extern s64 func_L39_004DAE48(s32, s32, s32, s32);
extern s32 func_L39_004BB460(s32);

s32 func_L39_004CA000(void *arg0) {
    S_004CA000 *s = arg0;
    s32 ret;
    Fn_004CA000 fn;
    s32 arg = 0;

    s->f54->f10C = 0;
    ret = func_L39_004C9368(arg0, 0x15, (s32)&s->f54->f110, 2);
    if (ret <= 0) {
        s->f54->f10C = 1;
    } else {
        if (s->f54->f110 == 2) {
            func_L39_004DAE48(s->f10, 0xB, 0, 0);
        }
        if (s->fE0 != 0) {
            s->f18 = 2;
            if ((s32)func_L39_004DAE48(s->f10, 0xB, 0, 0) < 0) {
                if (func_L39_004BB460(s->f10) != 0) {
                    s->f54->f10C = 1;
                }
                return -1;
            }
            s->f18 = 1;
        }
        if (s->fC0 != 0) {
            fn = s->fC0;
        } else {
            fn = s->fDC->f7C;
        }
        if (fn != 0) {
            fn(s, 0x4008, (s->f54->f110 << 8) | s->f54->f111);
        }
        fn = 0;
        if (s->fC4 != 0) {
            fn = s->fC4;
            arg = s->fC8;
        } else if (s->fDC->f80 != 0) {
            arg = s->fDC->f84;
            fn = s->fDC->f80;
        }
        if (fn != 0) {
            fn(s, 0x4008, (s->f54->f110 << 8) | s->f54->f111, arg);
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004CA000 */

INCLUDE_ASM("asm/levels", func_L39_004CA180);
