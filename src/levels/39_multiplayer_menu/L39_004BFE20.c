#include "common.h"

/* localdecomp:start func_L39_004BFE20 */
typedef struct B_004BFE20 {
    s32 pad0;
    u8 *buf;
} B_004BFE20;
typedef struct S_004BFE20 {
    u8 pad0[0x10];
    s32 wbio;
    u8 pad14[0x18 - 0x14];
    s32 rwstate;
    u8 pad1C[0x3C - 0x1C];
    B_004BFE20 *init_buf;
    s32 init_num;
    s32 init_off;
} S_004BFE20;

extern s32 func_L39_004DACB0(s32, u8 *, s32);

s32 func_L39_004BFE20(S_004BFE20 *s) {
    s32 i, num, tot;
    u8 *buf;

    buf = s->init_buf->buf;
    tot = s->init_off;
    num = s->init_num;
    for (;;) {
        s->rwstate = 2;
        i = func_L39_004DACB0(s->wbio, &buf[tot], num);
        if (i <= 0) {
            s->init_off = tot;
            s->init_num = num;
            return i;
        }
        s->rwstate = 1;
        if (i == num) {
            return tot + i;
        }
        num -= i;
        tot += i;
    }
}
/* localdecomp:end func_L39_004BFE20 */

INCLUDE_ASM("asm/levels", func_L39_004BFEC8);

INCLUDE_ASM("asm/levels", func_L39_004BFF90);

/* localdecomp:start func_L39_004C04D0 */
typedef struct B_004C04D0 {
    s32 pad0;
    u8 *buf;
} B_004C04D0;
typedef struct X_004C04D0 {
    s32 f0;
} X_004C04D0;
typedef struct Y_004C04D0 {
    s32 pad0;
    X_004C04D0 *f4;
} Y_004C04D0;
typedef struct N_004C04D0 {
    u8 pad0[0x44];
    s32 f44;
    u8 pad48[0x90 - 0x48];
    Y_004C04D0 *f90;
    s32 f94;
    u8 pad98[0xAC - 0x98];
    s32 fAC;
    u8 padB0[0xB8 - 0xB0];
    s32 fB8;
} N_004C04D0;
typedef struct T_004C04D0 {
    u8 pad0[0x90];
    s32 f90;
    u8 conn_id[0xE8 - 0x94];
    s32 fE8;
    s32 fEC;
    s32 fF0;
    s32 fF4;
} T_004C04D0;
typedef struct D_004C04D0 {
    u8 pad0[0x80];
    s32 (*cb)(void *, s32, s32, s32);
    s32 arg;
} D_004C04D0;
typedef struct L_004C04D0 {
    s32 n;
    s32 *d;
} L_004C04D0;
typedef struct S_004C04D0 {
    s32 f0;
    u8 pad4[0x30 - 4];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C04D0 *init_buf;
    s32 f40;
    s32 f44;
    u8 pad48[0x50 - 0x48];
    T_004C04D0 *s2;
    u8 pad54[0x5C - 0x54];
    s32 hit;
    u8 pad60[0xB0 - 0x60];
    N_004C04D0 *sess;
    u8 padB4[0xC4 - 0xB4];
    s32 (*cb)(void *, s32, s32, s32);
    s32 arg;
    u8 padCC[0xDC - 0xCC];
    D_004C04D0 *fDC;
    u8 padE0[0x100 - 0xE0];
    unsigned long flags;
} S_004C04D0;
struct S_004C0BD8;
extern void func_L39_004C6100(struct S_004C0BD8 *, s32);
extern s32 D_L39_004C4130[];
extern s32 func_L39_004C52B0(S_004C04D0 *, u8 *, s32);
extern s32 func_L39_004C5F70(S_004C04D0 *, s32, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004DB1C0(B_004C04D0 *, s32);
extern s32 func_L39_004CB730(S_004C04D0 *, s32);
extern s32 func_L39_004C1660(S_004C04D0 *, s32, s32, u8 *);
extern void *func_L39_004C4270(S_004C04D0 *, u8 *, s32, s32 *);
extern void func_L39_004CC178(void *, s32 *);
extern s32 func_L39_004CC2C8(void *, s32);
extern void func_L39_004BBBA0(s32);
extern void func_L39_004BBCC0(s32);
extern L_004C04D0 *func_L39_004C4198(S_004C04D0 *);
extern void func_11D380(void *, void *, s32);

s32 func_L39_004C04D0(S_004C04D0 *s) {
    s32 (*cb)(void *, s32, s32, s32) = 0;
    s32 arg = 0;
    u8 *buf;
    u8 *p;
    s32 i;
    u32 j;
    s32 k;
    s32 len;
    void *sk;
    L_004C04D0 *cl;

    if (s->cb) {
        cb = s->cb;
        arg = s->arg;
    } else if (s->fDC->cb) {
        cb = s->fDC->cb;
        arg = s->fDC->arg;
    }
    p = s->init_buf->buf;
    if (s->state == 0x1020) {
        i = func_L39_004C52B0(s, p + s->f40, 11 - s->f40);
        if (i < 11 - s->f40) {
            return func_L39_004C5F70(s, 0x6D, i);
        }
        if (*(p++) != 4) {
            if (p[-1] != 0) {
                func_L39_004C6100((struct S_004C0BD8 *)s, 0);
                func_L39_004BC6C8(0x14, 0x6D, 0xD4, 0, 0);
            } else {
                func_L39_004BC6C8(0x14, 0x6D, 0xC8, 0, 0);
            }
            return -1;
        }
        s->hit = (*(p++)) ? 1 : 0;
        s->s2->fEC = *(p++);
        i = (p[0] << 8) | p[1];
        p += 2;
        if (i < s->f0) {
            s->f0 = i;
        }
        j = (p[0] << 8) | p[1];
        p += 2;
        s->s2->fF0 = j;
        j = (p[0] << 8) | p[1];
        p += 2;
        s->s2->fF4 = j;
        j = (p[0] << 8) | p[1];
        p += 2;
        if (j > 16) {
            func_L39_004BC6C8(0x14, 0x6D, 0x456, 0, 0);
            return -1;
        }
        s->s2->fE8 = j;
        s->state = 0x1021;
        s->f40 = 0;
    }
    len = s->s2->fF0 + s->s2->fF4 + s->s2->fE8;
    k = len - s->f40;
    if (!func_L39_004DB1C0(s->init_buf, k + s->f40)) {
        return -1;
    }
    buf = s->init_buf->buf;
    i = func_L39_004C52B0(s, buf + s->f40, k);
    if (i != k) {
        return func_L39_004C5F70(s, 0x6D, i);
    }
    p = buf;
    if (s->hit) {
        if (s->s2->fF0 != 0) {
            if (cb) {
                cb(s, 0x4004, 0, arg);
            }
            func_L39_004BC6C8(0x14, 0x6D, 0xD8, 0, 0);
            return -1;
        }
        if (s->s2->fEC != 0 && !(s->flags & 0x10)) {
            if (cb) {
                cb(s, 0x4004, 0, arg);
            }
            func_L39_004BC6C8(0x14, 0x6D, 0xD9, 0, 0);
            return -1;
        }
        if (s->s2->fF4 != 0) {
            if (cb) {
                cb(s, 0x4004, 0, arg);
            }
            func_L39_004BC6C8(0x14, 0x6D, 0xDA, 0, 0);
            return -1;
        }
    } else {
        if (s->sess->f44 != 0) {
            if (func_L39_004CB730(s, 0) == 0) {
                func_L39_004C6100((struct S_004C0BD8 *)s, 0);
                return -1;
            }
        }
        if (func_L39_004C1660(s, s->s2->fEC, s->s2->fF0, buf) <= 0) {
            func_L39_004C6100((struct S_004C0BD8 *)s, 4);
            return -1;
        }
        p = buf + s->s2->fF0;
        if (s->s2->fF4 == 0) {
            func_L39_004C6100((struct S_004C0BD8 *)s, 1);
            func_L39_004BC6C8(0x14, 0x6D, 0xB8, 0, 0);
            return -1;
        }
        sk = func_L39_004C4270(s, p, s->s2->fF4, &s->sess->fB8);
        p += s->s2->fF4;
        if (sk == 0) {
            func_L39_004C6100((struct S_004C0BD8 *)s, 0);
            func_L39_004BC6C8(0x14, 0x6D, 0x21, 0, 0);
            return -1;
        }
        func_L39_004CC178(sk, D_L39_004C4130);
        cl = func_L39_004C4198(s);
        for (i = 0; i < cl->n; i++) {
            if (func_L39_004CC2C8(sk, cl->d[i]) >= 0) {
                break;
            }
        }
        if (i >= cl->n) {
            func_L39_004C6100((struct S_004C0BD8 *)s, 1);
            func_L39_004BC6C8(0x14, 0x6D, 0xB9, 0, 0);
            return -1;
        }
        s->sess->fAC = cl->d[i];
        if (s->sess->f94 != 0) {
            func_L39_004BBBA0(s->sess->f94);
        }
        func_L39_004BBCC0(s->sess->f90->f4->f0);
        s->sess->f94 = s->sess->f90->f4->f0;
    }
    s->s2->f90 = s->s2->fE8;
    func_11D380(s->s2->conn_id, p, s->s2->fE8);
    return 1;
}
/* localdecomp:end func_L39_004C04D0 */

/* localdecomp:start func_L39_004C09B0 */
/* OpenSSL SSLv2 client_hello (s2_clnt.c), with an info-callback on the error path */
typedef struct SSL_004C09B0 SSL_004C09B0;
typedef void (*CB_004C09B0)(SSL_004C09B0 *, s32, s32, s32);

typedef struct {
    s32 ssl_version;
    u8 pad4[0x40];
    u32 session_id_length;
    u8 session_id[0x20];
    u8 pad68[0x24];
    s32 not_resumable;
} SESS_004C09B0;

typedef struct {
    u8 pad0[0x6C];
    s32 challenge_length;
    u8 challenge[0x10];
} S2_004C09B0;

typedef struct {
    s32 length;
    u8 *data;
} BUF_004C09B0;

typedef struct {
    u8 pad0[0x80];
    CB_004C09B0 info_callback;
    s32 info_arg;
} CTX_004C09B0;

struct SSL_004C09B0 {
    s32 version;
    u8 pad4[0x2C];
    s32 state;
    u8 pad34[0x8];
    BUF_004C09B0 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 pad48[0x8];
    S2_004C09B0 *s2;
    u8 pad54[0x5C];
    SESS_004C09B0 *session;
    u8 padB4[0x10];
    CB_004C09B0 info_callback;
    s32 info_arg;
    u8 padCC[0x10];
    CTX_004C09B0 *ctx;
};

extern void *func_0011D380(void *, void *, s32);
extern void *memcpy(void *, const void *, unsigned int);
extern void *func_L39_004C4168(SSL_004C09B0 *);
extern s32 func_L39_004C41D0(SSL_004C09B0 *, void *, u8 *);
extern void *func_L39_004E5090(void);
extern s32 func_L39_004E4FC8(void *, void *, s32);
extern s32 func_L39_004C6020(struct S_004C0BD8 *);

s32 func_L39_004C09B0(SSL_004C09B0 *s) {
    u8 *buf;
    u8 *p;
    u8 *d;
    s32 i;
    s32 n;
    CB_004C09B0 cb = 0;
    s32 arg = 0;

    buf = s->init_buf->data;
    if (s->state == 0x1010) {
        if (s->session == 0 || s->session->ssl_version != s->version ||
            s->session->not_resumable) {
            if (!func_L39_004CB730((S_004C04D0 *)s, 0)) {
                func_L39_004C6100((struct S_004C0BD8 *)s, 0);
                return -1;
            }
        }

        p = buf;
        d = p + 9;
        *(p++) = 1;
        (p[0] = (u8)((2 >> 8) & 0xff), p[1] = (u8)(2 & 0xff)), p += 2;

        n = func_L39_004C41D0(s, func_L39_004C4168(s), d);
        d += n;

        if (n == 0) {
            if (s->info_callback != 0) {
                cb = s->info_callback;
                arg = s->info_arg;
            } else if (s->ctx->info_callback != 0) {
                cb = s->ctx->info_callback;
                arg = s->ctx->info_arg;
            }
            if (cb != 0) {
                cb(s, 0x4008, 1, arg);
            }
            func_L39_004BC6C8(0x14, 0x65, 0xB5, 0, 0);
            return -1;
        }

        (p[0] = (u8)((n >> 8) & 0xff), p[1] = (u8)(n & 0xff)), p += 2;

        if (s->session->session_id_length > 0 && s->session->session_id_length <= 0x20) {
            i = s->session->session_id_length;
            (p[0] = (u8)((i >> 8) & 0xff), p[1] = (u8)(i & 0xff)), p += 2;
            func_0011D380(d, s->session->session_id, i);
            d += i;
        } else {
            (p[0] = (u8)((0 >> 8) & 0xff), p[1] = (u8)(0 & 0xff)), p += 2;
        }

        s->s2->challenge_length = 0x10;
        (p[0] = (u8)((0x10 >> 8) & 0xff), p[1] = (u8)(0x10 & 0xff)), p += 2;
        func_L39_004E4FC8(func_L39_004E5090(), s->s2->challenge, 0x10);
        memcpy(d, s->s2->challenge, 0x10);
        d += 0x10;

        s->state = 0x1011;
        s->init_num = d - buf;
        s->init_off = 0;
    }
    return func_L39_004C6020((struct S_004C0BD8 *)s);
}
/* localdecomp:end func_L39_004C09B0 */

/* localdecomp:start func_L39_004C0BD8 */
typedef struct M_004C0BD8 {
    u8 pad0[0x3C];
    s32 (*put_cipher_by_char)(void *cipher, u8 *p);
} M_004C0BD8;

typedef struct B_004C0BD8 {
    s32 length;
    u8 *data;
} B_004C0BD8;

typedef struct R_004C0BD8 {
    u8 pad0[0xC];
    s32 ssl2_rollback;
} R_004C0BD8;

typedef struct C_004C0BD8 {
    u8 pad0[0x18];
    unsigned long f18;
} C_004C0BD8;

typedef struct E_004C0BD8 {
    u8 pad0[4];
    s32 key_arg_length;
    u8 key_arg[8];
    s32 master_key_length;
    u8 master_key[0x7C];
    void *f90;
    u8 pad94[0xAC - 0x94];
    C_004C0BD8 *cipher;
} E_004C0BD8;

typedef struct S_004C0BD8 {
    u8 pad0[8];
    M_004C0BD8 *method;
    u8 pad0C[0x30 - 0xC];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C0BD8 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 pad48[0x50 - 0x48];
    R_004C0BD8 *s2;
    u8 pad54[0xB0 - 0x54];
    E_004C0BD8 *session;
    u8 padB4[0x100 - 0xB4];
    long options;
} S_004C0BD8;

extern void *func_L39_004E5090(void);
extern s32 func_L39_004CA3D0(void *, void **, void **);
extern void func_L39_004C6100(S_004C0BD8 *, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L01_004CC758(void *);
extern s32 func_L39_004DE8F8(void *);
extern s32 func_L39_004E4FC8(void *, void *, s32);
extern void *func_0011D380(void *, void *, s32);
extern s32 func_L39_004C18B8(void *, s32, void *, void *, s32);
extern s32 func_L39_004C6020(S_004C0BD8 *);

s32 func_L39_004C0BD8(S_004C0BD8 *s) {
    void *rng = func_L39_004E5090();
    u8 *buf = s->init_buf->data;
    u8 *p;
    u8 *d;
    E_004C0BD8 *sess;
    void *c;
    void *md;
    s32 i;
    s32 clear;
    s32 enc;
    s32 karg;

    p = buf;
    if (s->state == 0x1030) {
        if (!func_L39_004CA3D0(s->session->cipher, &c, &md)) {
            func_L39_004C6100(s, 1);
            func_L39_004BC6C8(0x14, 0x66, 0xCE, 0, 0);
            return -1;
        }
        sess = s->session;
        *(p++) = 2;
        d = p + 9;
        i = s->method->put_cipher_by_char(sess->cipher, p);
        p += i;

        i = func_L01_004CC758(c);
        sess->key_arg_length = i;
        if (i > 0) {
            func_L39_004E4FC8(rng, sess->key_arg, i);
        }

        i = func_L39_004DE8F8(c);
        sess->master_key_length = i;
        if (i > 0) {
            func_L39_004E4FC8(rng, sess->master_key, i);
        }

        enc = sess->cipher->f18 & 0xFF;
        if (enc == 0) {
            enc = i;
        }
        if (i < enc) {
            func_L39_004C6100(s, 0);
            func_L39_004BC6C8(0x14, 0x66, 0x8B, 0, 0);
            return -1;
        }
        clear = i - enc;
        p[1] = clear;
        p[0] = clear >> 8;
        p += 2;
        func_0011D380(d, sess->master_key, clear);
        d += clear;

        enc = func_L39_004C18B8(sess->f90, enc, &sess->master_key[clear], d, s->s2->ssl2_rollback ? 2 : 1);
        if (enc <= 0) {
            func_L39_004C6100(s, 0);
            func_L39_004BC6C8(0x14, 0x66, 0xD0, 0, 0);
            return -1;
        }
        if (s->options & 0x8000000) {
            d[1]++;
        }
        if (s->options & 0x10000000) {
            sess->master_key[clear]++;
        }
        p[1] = enc;
        p[0] = enc >> 8;
        p += 2;
        d += enc;
        karg = sess->key_arg_length;
        p[1] = karg;
        p[0] = karg >> 8;
        p += 2;
        func_0011D380(d, sess->key_arg, karg);
        d += karg;

        s->state = 0x1031;
        s->init_num = d - buf;
        s->init_off = 0;
    }
    return func_L39_004C6020(s);
}
/* localdecomp:end func_L39_004C0BD8 */
