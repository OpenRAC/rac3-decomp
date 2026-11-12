#include "common.h"

/* localdecomp:start func_L39_004C6BA0 */
/* OpenSSL ssl3_client_hello (s3_clnt.c) */
typedef struct {
    s32 ssl_version;
    u8 pad4[0x40];
    u32 session_id_length;
    u8 session_id[0x20];
    u8 pad68[0x24];
    s32 not_resumable;
} SESS_004C6BA0;

typedef struct {
    u8 pad0[0x64];
    u8 client_random[0x20];
} S3_004C6BA0;

typedef struct {
    s32 length;
    u8 *data;
} BUF_004C6BA0;

typedef struct {
    s32 version;
    u8 pad4[0x24];
    s32 new_session;
    u8 pad2C[0x4];
    s32 state;
    u8 pad34[0x8];
    BUF_004C6BA0 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 pad48[0xC];
    S3_004C6BA0 *s3;
    u8 pad58[0x58];
    SESS_004C6BA0 *session;
    u8 padB4[0x58];
    s32 client_version;
} SSL_004C6BA0;

extern void *func_0011D380(void *, const void *, unsigned int);
extern s32 func_L39_004CB730(SSL_004C6BA0 *, s32);
extern s32 func_L39_004E5108(void);
extern s32 func_L39_004E5260(s32, s32, u8 *, s32);
extern s32 func_L39_004E5090(void);
extern void func_L39_004E4FC8(s32, u8 *, s32);
extern void func_L39_004E5168(s32);
extern void *func_L39_004C4168(SSL_004C6BA0 *);
extern s32 func_L39_004C41D0(SSL_004C6BA0 *, void *, u8 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004CA180(SSL_004C6BA0 *, s32);

s32 func_L39_004C6BA0(SSL_004C6BA0 *s) {
    u8 *buf;
    u8 *p;
    u8 *d;
    s32 i;
    unsigned long l;
    s32 t;
    S3_004C6BA0 *s3;

    buf = s->init_buf->data;
    if (s->state == 0x1110) {
        if (s->session == 0 || s->session->ssl_version != s->version ||
            s->session->not_resumable) {
            if (!func_L39_004CB730(s, 0)) {
                goto err;
            }
        }
        d = buf + 4;
        s3 = s->s3;
        p = s3->client_random;
        t = func_L39_004E5108();
        func_L39_004E5260(t, 3, p, 8);
        p[0] = p[4];
        p[1] = p[5];
        p[2] = p[6];
        p[3] = p[7];
        p += 4;
        func_L39_004E4FC8(func_L39_004E5090(), p, 0x1C);
        func_L39_004E5168(t);

        p = d;
        *(p++) = s->version >> 8;
        *(p++) = s->version;
        s->client_version = s->version;

        memcpy(p, s->s3->client_random, 0x20);
        p += 0x20;

        if (s->new_session) {
            i = 0;
        } else {
            i = s->session->session_id_length;
        }
        *(p++) = i;
        if (i != 0) {
            func_0011D380(p, s->session->session_id, i);
            p += i;
        }

        i = func_L39_004C41D0(s, func_L39_004C4168(s), &p[2]);
        if (i == 0) {
            func_L39_004BC6C8(0x14, 0x83, 0xB5, 0, 0);
            goto err;
        }
        p[0] = i >> 8;
        p[1] = i;
        p += 2;
        p += i;

        *(p++) = 1;
        *(p++) = 0;

        l = p - d;
        d = buf;
        *(d++) = 1;
        (d[0] = (u8)((l >> 16) & 0xff), d[1] = (u8)((l >> 8) & 0xff),
         d[2] = (u8)(l & 0xff)), d += 3;

        s->state = 0x1111;
        s->init_num = p - buf;
        s->init_off = 0;
    }
    return func_L39_004CA180(s, 0x16);
err:
    return -1;
}
/* localdecomp:end func_L39_004C6BA0 */

INCLUDE_ASM("asm/levels", func_L39_004C6E08);

INCLUDE_ASM("asm/levels", func_L39_004C70F8);

/* localdecomp:start func_L39_004C74F8 */
typedef struct SC_004C74F8 {
    u8 pad0[0x20];
    void *rsa_a;
    void *rsa_b;
    void *rsa_c;
    void *dh_a;
    void *dh_b;
    u8 pad34[0xC];
    struct {
        void *x509;
        void *privatekey;
    } peer_pkeys[3];
} SC_004C74F8;

typedef struct SESS_004C74F8 {
    u8 pad0[0x90];
    SC_004C74F8 *sess_cert;
} SESS_004C74F8;

typedef struct CIPH_004C74F8 {
    u8 pad0[0x10];
    long algorithms;
    long algo_strength;
} CIPH_004C74F8;

typedef struct S3_004C74F8 {
    u8 pad0[0x44];
    u8 server_random[0x20];
    u8 client_random[0x20];
    u8 pad84[0x158 - 0x84];
    s32 message_type;
    CIPH_004C74F8 *new_cipher;
    u8 pad160[8];
    s32 reuse_message;
} S3_004C74F8;

typedef struct BUF_004C74F8 {
    s32 length;
    u8 *data;
} BUF_004C74F8;

typedef struct CTX_004C74F8 {
    u8 pad0[0x104];
    void *md5;
    void *sha1;
    void *dss1;
} CTX_004C74F8;

typedef struct SSL_004C74F8 {
    u8 pad0[0x3C];
    BUF_004C74F8 *init_buf;
    u8 pad40[0x54 - 0x40];
    S3_004C74F8 *s3;
    u8 pad58[0xB0 - 0x58];
    void *session;
    u8 padB4[0xDC - 0xB4];
    CTX_004C74F8 *ctx;
    u8 padE0[0x120 - 0xE0];
    long max_cert_list;
    void *md_ctx;
} SSL_004C74F8;

typedef struct PKEY_004C74F8 {
    s32 type;
    u8 pad4[8];
    void *rsa;
} PKEY_004C74F8;

extern long func_L39_004EB540(void *, s32, s32, s32, long, s32 *);
extern void func_L39_004EA410(void *);
extern void func_L39_004DD250(void *);
extern void *func_L39_004C3428(void);
extern void *func_L39_004EA4A8(void);
extern s32 func_L39_004EA570(void *, s32, void *, s32);
extern void *func_L39_004BBDE0(void *);
extern void *func_L39_004DD210(void);
extern s32 func_L39_004DD340(void *, s32, void *, s32);
extern s32 func_L39_004CBF70(s32 *);
extern s32 func_L39_004DD690(void *, void *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, void *, s32 *);
extern s32 func_L39_004EA9D0(s32, u8 *, u8 *, void *, s32);
extern s32 func_0011D2EC(void *, void *, s32);
extern s32 func_L39_004E1478(void *, u8 *, s32, void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004C9F50(void *, s32, s32);

s32 func_L39_004C74F8(SSL_004C74F8 *s) {
    u8 md_buf[40];
    u8 *param, *p, *q;
    s32 al, i, j, param_len, ok, num;
    long n, alg, strength;
    PKEY_004C74F8 *pkey = 0;
    void *rsa = 0;
    void *dh = 0;

    n = func_L39_004EB540(s, 0x1140, 0x1141, -1, s->max_cert_list ? s->max_cert_list : 0x19000, &ok);
    if (!ok) {
        return (s32)n;
    }
    if (s->s3->message_type != 0xC) {
        s->s3->reuse_message = 1;
        return 1;
    }

    param = p = s->init_buf->data;

    if (((SESS_004C74F8 *)s->session)->sess_cert != 0) {
        if (((SESS_004C74F8 *)s->session)->sess_cert->rsa_a != 0) {
            func_L39_004EA410(((SESS_004C74F8 *)s->session)->sess_cert->rsa_a);
            ((SESS_004C74F8 *)s->session)->sess_cert->rsa_a = 0;
        }
        if (((SESS_004C74F8 *)s->session)->sess_cert->rsa_b != 0) {
            func_L39_004EA410(((SESS_004C74F8 *)s->session)->sess_cert->rsa_b);
            ((SESS_004C74F8 *)s->session)->sess_cert->rsa_b = 0;
        }
        if (((SESS_004C74F8 *)s->session)->sess_cert->rsa_c != 0) {
            func_L39_004EA410(((SESS_004C74F8 *)s->session)->sess_cert->rsa_c);
            ((SESS_004C74F8 *)s->session)->sess_cert->rsa_c = 0;
        }
        if (((SESS_004C74F8 *)s->session)->sess_cert->dh_a != 0) {
            func_L39_004DD250(((SESS_004C74F8 *)s->session)->sess_cert->dh_a);
            ((SESS_004C74F8 *)s->session)->sess_cert->dh_a = 0;
        }
        if (((SESS_004C74F8 *)s->session)->sess_cert->dh_b != 0) {
            func_L39_004DD250(((SESS_004C74F8 *)s->session)->sess_cert->dh_b);
            ((SESS_004C74F8 *)s->session)->sess_cert->dh_b = 0;
        }
    } else {
        ((SESS_004C74F8 *)s->session)->sess_cert = func_L39_004C3428();
    }

    param_len = 0;
    alg = s->s3->new_cipher->algorithms;
    strength = s->s3->new_cipher->algo_strength;

    if (alg & 0x1) {
        rsa = func_L39_004EA4A8();
        if (rsa == 0) {
            func_L39_004BC6C8(0x14, 0x8D, 0x21, 0, 0);
            goto err;
        }
        i = (p[0] << 8) | p[1];
        p += 2;
        param_len = i + 2;
        if (param_len > n) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8D, 0x79, 0, 0);
            goto f_err;
        }
        if (!func_L39_004EA570(rsa, 0x10, p, i)) {
            func_L39_004BC6C8(0x14, 0x8D, 0x803, 0, 0);
            goto err;
        }
        p += i;
        i = (p[0] << 8) | p[1];
        p += 2;
        param_len += i + 2;
        if (param_len > n) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8D, 0x78, 0, 0);
            goto f_err;
        }
        if (!func_L39_004EA570(rsa, 0x11, p, i)) {
            func_L39_004BC6C8(0x14, 0x8D, 0x803, 0, 0);
            goto err;
        }
        p += i;
        n -= param_len;

        if (alg & 0x20) {
            pkey = func_L39_004BBDE0(((SESS_004C74F8 *)s->session)->sess_cert->peer_pkeys[0].x509);
        } else {
            func_L39_004BC6C8(0x14, 0x8D, 0x9D, 0, 0);
            goto err;
        }
        if (alg & 0x100000) {
            if ((s32)(strength & 0xFF00) == 0x400) {
                ((SESS_004C74F8 *)s->session)->sess_cert->rsa_c = rsa;
            } else {
                ((SESS_004C74F8 *)s->session)->sess_cert->rsa_b = rsa;
            }
        } else {
            ((SESS_004C74F8 *)s->session)->sess_cert->rsa_a = rsa;
        }
        rsa = 0;
    } else if (alg & 0x10) {
        dh = func_L39_004DD210();
        if (dh == 0) {
            func_L39_004BC6C8(0x14, 0x8D, 0x805, 0, 0);
            goto err;
        }
        i = (p[0] << 8) | p[1];
        p += 2;
        param_len = i + 2;
        if (param_len > n) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8D, 0x6E, 0, 0);
            goto f_err;
        }
        if (func_L39_004DD340(dh, 1, p, i)) {
            func_L39_004BC6C8(0x14, 0x8D, 0x803, 0, 0);
            goto err;
        }
        p += i;
        i = (p[0] << 8) | p[1];
        p += 2;
        param_len += i + 2;
        if (param_len > n) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8D, 0x6C, 0, 0);
            goto f_err;
        }
        if (func_L39_004DD340(dh, 2, p, i)) {
            func_L39_004BC6C8(0x14, 0x8D, 0x803, 0, 0);
            goto err;
        }
        p += i;
        i = (p[0] << 8) | p[1];
        p += 2;
        param_len += i + 2;
        if (param_len > n) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8D, 0x6D, 0, 0);
            goto f_err;
        }
        if (func_L39_004DD340(dh, 3, p, i)) {
            func_L39_004BC6C8(0x14, 0x8D, 0x803, 0, 0);
            goto err;
        }
        p += i;
        n -= param_len;

        if (alg & 0x20) {
            pkey = func_L39_004BBDE0(((SESS_004C74F8 *)s->session)->sess_cert->peer_pkeys[0].x509);
        }
        if (alg & 0x40) {
            pkey = func_L39_004BBDE0(((SESS_004C74F8 *)s->session)->sess_cert->peer_pkeys[2].x509);
        }
        if (alg & 0x100000) {
            ((SESS_004C74F8 *)s->session)->sess_cert->dh_b = dh;
        } else {
            ((SESS_004C74F8 *)s->session)->sess_cert->dh_a = dh;
        }
        dh = 0;
    } else if (alg & 0x6) {
        al = 0x2F;
        func_L39_004BC6C8(0x14, 0x8D, 0xEB, 0, 0);
        goto f_err;
    }
    if (alg & 0x80) {
        al = 0x28;
        func_L39_004BC6C8(0x14, 0x8D, 0xEB, 0, 0);
        goto f_err;
    }

    if (pkey != 0) {
        i = (p[0] << 8) | p[1];
        p += 2;
        n -= 2;
        j = func_L39_004CBF70((s32 *)pkey);
        if (i != n || n > j || n <= 0) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8D, 0x108, 0, 0);
            goto f_err;
        }
        if (pkey->type == 6) {
            j = 0;
            q = md_buf;
            for (num = 2; num > 0; num--) {
                if (!func_L39_004DD690(s->md_ctx, num == 2 ? s->ctx->md5 : s->ctx->sha1)) {
                    al = 0x50;
                    goto f_err;
                }
                func_L39_004DD778(s->md_ctx, s->s3->client_random, 0x20);
                func_L39_004DD778(s->md_ctx, s->s3->server_random, 0x20);
                func_L39_004DD778(s->md_ctx, param, param_len);
                func_L39_004DD7A8(s->md_ctx, q, &i);
                q += i;
                j += i;
            }
            i = func_L39_004EA9D0(n, p, p, pkey->rsa, 1);
            if (i <= 0) {
                al = 0x33;
                func_L39_004BC6C8(0x14, 0x8D, 0x76, 0, 0);
                goto f_err;
            }
            if (j != i || func_0011D2EC(p, md_buf, i) != 0) {
                al = 0x33;
                func_L39_004BC6C8(0x14, 0x8D, 0x7B, 0, 0);
                goto f_err;
            }
        } else if (pkey->type == 0x74) {
            if (!func_L39_004DD690(s->md_ctx, s->ctx->dss1)) {
                func_L39_004BC6C8(0x14, 0x8D, 0x806, 0, 0);
                al = 0x50;
                goto f_err;
            }
            func_L39_004DD778(s->md_ctx, s->s3->client_random, 0x20);
            func_L39_004DD778(s->md_ctx, s->s3->server_random, 0x20);
            func_L39_004DD778(s->md_ctx, param, param_len);
            if (func_L39_004E1478(s->md_ctx, p, n, pkey) <= 0) {
                al = 0x33;
                func_L39_004BC6C8(0x14, 0x8D, 0x7B, 0, 0);
                goto f_err;
            }
        } else {
            func_L39_004BC6C8(0x14, 0x8D, 0x9D, 0, 0);
            goto err;
        }
    } else {
        if (!(alg & 0x100)) {
            func_L39_004BC6C8(0x14, 0x8D, 0x9D, 0, 0);
            goto err;
        }
        if (n != 0) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8D, 0x99, 0, 0);
            goto f_err;
        }
    }
    return 1;
f_err:
    func_L39_004C9F50(s, 2, al);
err:
    if (dh != 0) {
        func_L39_004DD250(dh);
    }
    return -1;
}
/* localdecomp:end func_L39_004C74F8 */

INCLUDE_ASM("asm/levels", func_L39_004C7CD0);

INCLUDE_ASM("asm/levels", func_L39_004C8088);

INCLUDE_ASM("asm/levels", func_L39_004C8110);
