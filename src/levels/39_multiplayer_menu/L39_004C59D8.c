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

/* localdecomp:start func_L39_004C5B80 */
typedef struct S2_004C5B80 {
    u8 pad0[0x14];
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    u8 pad28[0x10];
    s32 x38;
} S2_004C5B80;

typedef struct S_004C5B80 {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[4];
    s32 x18;
    u8 pad1C[0x34];
    S2_004C5B80 *p50;
} S_004C5B80;

extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004DACB0(s32, s32, s32);

s32 func_L39_004C5B80(S_004C5B80 *a, s32 a1, s32 a2) {
    s32 r;
    if (a2 < a->p50->x14 || a->p50->x18 != a1) {
        func_L39_004BC6C8(0x14, 0xD5, 0x7F, 0, 0);
        return -1;
    }
    for (;;) {
        *func_0011A6E0() = 0;
        if (a->x10 != 0) {
            a->x18 = 2;
            r = func_L39_004DACB0(a->x10, a->p50->x38 + a->p50->x1C, a->p50->x20);
        } else {
            func_L39_004BC6C8(0x14, 0xD5, 0x104, 0, 0);
            r = -1;
        }
        if (r == a->p50->x20) {
            a->p50->x20 = 0;
            a->x18 = 1;
            return a->p50->x24;
        }
        if (r <= 0) {
            return r;
        }
        a->p50->x1C += r;
        a->p50->x20 -= r;
    }
}
/* localdecomp:end func_L39_004C5B80 */

/* localdecomp:start func_L39_004C5C88 */
typedef struct S2_004C5C88 {
    /* 0x00 */ s32 three_byte_header;
    /* 0x04 */ s32 clear_text;
    /* 0x08 */ s32 escape;
    /* 0x0C */ u8 pad0C[0x8];
    /* 0x14 */ u32 wpend_tot;
    /* 0x18 */ const u8 *wpend_buf;
    /* 0x1C */ s32 wpend_off;
    /* 0x20 */ s32 wpend_len;
    /* 0x24 */ s32 wpend_ret;
    /* 0x28 */ u8 pad28[0xC];
    /* 0x34 */ u8 *wbuf;
    /* 0x38 */ u8 *write_ptr;
    /* 0x3C */ u8 pad3C[0x4];
    /* 0x40 */ u32 padding;
    /* 0x44 */ u8 pad44[0x8];
    /* 0x4C */ u32 wlength;
    /* 0x50 */ u32 wact_data_length;
    /* 0x54 */ u8 pad54[0x4];
    /* 0x58 */ u8 *wact_data;
    /* 0x5C */ u8 *mac_data;
    /* 0x60 */ u8 pad60[0x80];
    /* 0xE0 */ unsigned long write_sequence;
} S2_004C5C88;

typedef struct SSL_004C5C88 {
    /* 0x00 */ u8 pad0[0x50];
    /* 0x50 */ S2_004C5C88 *s2;
    /* 0x54 */ u8 pad54[0x1C];
    /* 0x70 */ void *enc_ctx;
    /* 0x74 */ u32 mac_size;
    /* 0x78 */ u8 pad78[0x98];
    /* 0x110 */ u32 max_record;
} SSL_004C5C88;

extern void *func_11D380(void *, const void *, u32);
extern u32 func_L39_004DE908(void *);
extern void func_L39_004EADC0(SSL_004C5C88 *, u8 *, s32);
extern void func_L39_004EAD18(SSL_004C5C88 *, s32);

/* OpenSSL's do_ssl_write (s2_pkt.c) */
s32 func_L39_004C5C88(S_004C59D8 *arg0, s32 arg1, s32 arg2) {
    SSL_004C5C88 *s = (SSL_004C5C88 *)arg0;
    const u8 *buf = (const u8 *)arg1;
    u32 len = arg2;
    u32 j, k, olen, p, mac_size, bs, hdr;
    u8 *pp;

    olen = len;
    if (s->s2->wpend_len != 0) {
        return func_L39_004C5B80((S_004C5B80 *)s, (s32)buf, len);
    }
    if (s->s2->clear_text) {
        mac_size = 0;
    } else {
        mac_size = s->mac_size;
    }
    if (s->s2->clear_text) {
        if (len > s->max_record - 2) {
            len = s->max_record - 2;
        }
        p = 0;
        s->s2->three_byte_header = 0;
    } else {
        bs = func_L39_004DE908(s->enc_ctx);
        j = len + mac_size;
        if (j > s->max_record - 3 && !s->s2->escape) {
            if (j > s->max_record - 2) {
                j = s->max_record - 2;
            }
            k = j - (j % bs);
            len = k - mac_size;
            s->s2->three_byte_header = 0;
            p = 0;
        } else if (bs <= 1 && !s->s2->escape) {
            s->s2->three_byte_header = 0;
            p = 0;
        } else {
            p = j % bs;
            p = (p == 0) ? 0 : (bs - p);
            if (s->s2->escape) {
                s->s2->three_byte_header = 1;
                if (j > s->max_record - 3) {
                    j = s->max_record - 3;
                }
            } else {
                s->s2->three_byte_header = (p == 0) ? 0 : 1;
            }
        }
    }
    hdr = (s->s2->three_byte_header == 1) ? 3 : 2;
    s->s2->wlength = len;
    s->s2->padding = p;
    s->s2->mac_data = &s->s2->wbuf[hdr];
    s->s2->wact_data = &s->s2->wbuf[hdr + mac_size];
    func_11D380(s->s2->wact_data, buf, len);
    if (!s->s2->clear_text) {
        s->s2->wact_data_length = len + p;
        func_L39_004EADC0(s, s->s2->mac_data, 1);
        s->s2->wlength += p + mac_size;
        func_L39_004EAD18(s, 1);
    }
    s->s2->wpend_len = s->s2->wlength;
    if (s->s2->three_byte_header) {
        pp = s->s2->mac_data;
        pp -= 3;
        pp[0] = (s->s2->wlength >> 8) & 0x3F;
        if (s->s2->escape) {
            pp[0] |= 0x40;
        }
        pp[1] = s->s2->wlength & 0xFF;
        pp[2] = s->s2->padding;
        s->s2->wpend_len += 3;
    } else {
        pp = s->s2->mac_data;
        pp -= 2;
        pp[0] = ((s->s2->wlength >> 8) & 0x7F) | 0x80;
        pp[1] = s->s2->wlength & 0xFF;
        s->s2->wpend_len += 2;
    }
    s->s2->write_ptr = pp;
    s->s2->write_sequence = (s->s2->write_sequence + 1) & 0xFFFFFFFF;
    s->s2->wpend_tot = olen;
    s->s2->wpend_buf = buf;
    s->s2->wpend_ret = len;
    s->s2->wpend_off = 0;
    return func_L39_004C5B80((S_004C5B80 *)s, (s32)buf, olen);
}
/* localdecomp:end func_L39_004C5C88 */
