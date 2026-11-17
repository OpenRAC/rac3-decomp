#include "common.h"

/* declared by functions of L39_004C6BA0.c, which this file was cut from */
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
extern s32 func_L39_004E5090(void);
extern void func_L39_004E4FC8(s32, u8 *, s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004CA180(SSL_004C6BA0 *, s32);
extern long func_L39_004EB540(void *, s32, s32, s32, long, s32 *);
extern void func_L39_004C9F50(void *, s32, s32);
extern void *func_L39_004BBDE0(void *);
extern void func_L39_004DD250(void *);

/* localdecomp:start func_L39_004C8068 */
extern s32 func_L39_004BBE70(void *, void *);

s32 func_L39_004C8068(void **a, void **b) {
    return func_L39_004BBE70(*a, *b);
}
/* localdecomp:end func_L39_004C8068 */

/* localdecomp:start func_L39_004C8088 */
s32 func_L39_004C8088(void *a) {
    s32 out;
    long r;
    r = func_L39_004EB540(a, 0x1160, 0x1161, 14, 30, &out);
    if (out == 0) {
        return r;
    }
    if (r > 0) {
        func_L39_004C9F50(a, 2, 50);
        func_L39_004BC6C8(20, 145, 159, 0, 0);
    }
    return 1;
}
/* localdecomp:end func_L39_004C8088 */

/* localdecomp:start func_L39_004C8110 */
/* OpenSSL ssl3_send_client_key_exchange-like (RSA and DH branches) */
typedef struct { s32 type; u8 pad4[8]; void *rsa; } PKEY_004C8110;
typedef struct { u8 pad0[0x20]; void *f20; void *f24; void *f28; void *f2C; void *f30; u8 pad34[0xC]; void *f40; } CERT_004C8110;
typedef struct { u8 pad0[0x10]; s32 master_key_length; u8 master_key[0x7C]; CERT_004C8110 *cert; } SESS_004C8110;
typedef struct { u8 pad0[0xC]; s32 (*generate_master_secret)(void *, u8 *, u8 *, s32); } ENC_004C8110;
typedef struct { u8 pad0[0x54]; ENC_004C8110 *enc; } METHOD_004C8110;
typedef struct { u8 pad0[0x10]; unsigned long algorithms; unsigned long algorithm2; } CIPHER_004C8110;
typedef struct { u8 pad0[0x15C]; CIPHER_004C8110 *cipher; } S3_004C8110;
typedef struct { s32 length; u8 *data; s32 max; } BUF_004C8110;
typedef struct {
    s32 version;
    u8 pad4[4];
    METHOD_004C8110 *method;
    u8 pad0C[0x1C];
    s32 new_session;
    u8 pad2C[4];
    s32 state;
    u8 pad34[8];
    BUF_004C8110 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 pad48[0xC];
    S3_004C8110 *s3;
    u8 pad58[0x58];
    SESS_004C8110 *session;
    u8 padB4[0x4C];
    unsigned long options;
    u8 pad108[4];
    s32 client_version;
} SSL_004C8110;

extern void func_L39_004C9F50(void *, s32, s32);
extern s32 func_L39_004CA180(SSL_004C6BA0 *, s32);
extern void *func_L39_004BBDE0(void *);
extern s32 func_L39_004E5090(void);
extern void func_L39_004E4FC8(s32, u8 *, s32);
extern s32 func_L39_004EA8A0(s32, u8 *, u8 *, void *, s32);
extern void *func_L39_004DD5E0(void *);
extern s32 func_L39_004DD4C0(void *);
extern s32 func_L39_004DD378(void *, s32, u8 **, s32 *);
extern s32 func_L39_004DD520(u8 *, s32 *, s32, u8 *, s32, void *);
extern void func_L39_004DD250(void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_0011D534(u8 *, s32, s32);
extern void *func_0011D380(void *, const void *, u32);

s32 func_L39_004C8110(SSL_004C8110 *s) {
    u8 *p;
    u8 *d;
    u8 *q;
    u8 *a;
    s32 b;
    s32 n;
    unsigned long l;
    s32 max;
    unsigned long l2;
    void *dh_srvr;
    void *dh_clnt = 0;
    void *rsa;
    PKEY_004C8110 *pkey;
    u8 tmp_buf[0x30];

    if (s->state == 0x1180) {
        l = s->s3->cipher->algorithms;
        l2 = s->s3->cipher->algorithm2;
        d = s->init_buf->data;
        max = s->init_buf->max;
        p = d + 4;
        if (l & 1) {
            if ((l & 0x100000) && (s32)(l2 & 0xFF00) == 0x400 && s->session->cert->f28 != 0) {
                rsa = s->session->cert->f28;
            } else if ((l & 0x100000) && s->session->cert->f24 != 0) {
                rsa = s->session->cert->f24;
            } else if (!(l & 0x100000) && s->session->cert->f20 != 0) {
                rsa = s->session->cert->f20;
            } else {
                pkey = (PKEY_004C8110 *)func_L39_004BBDE0(s->session->cert->f40);
                if (pkey == 0 || pkey->type != 6 || pkey->rsa == 0) {
                    func_L39_004BC6C8(0x14, 0x99, 0x9D, 0, 0);
                    goto err;
                }
                rsa = pkey->rsa;
            }
            q = p;
            tmp_buf[0] = s->client_version >> 8;
            tmp_buf[1] = s->client_version;
            func_L39_004E4FC8(func_L39_004E5090(), &tmp_buf[2], 0x2E);
            s->session->master_key_length = 0x30;
            if (s->version > 0x300) {
                p += 2;
            }
            n = func_L39_004EA8A0(0x30, tmp_buf, p, rsa, 1);
            if (s->options & 0x8000000) {
                p[1]++;
            }
            if (s->options & 0x10000000) {
                tmp_buf[0] = 0x70;
            }
            if (n <= 0) {
                func_L39_004BC6C8(0x14, 0x99, 0x77, 0, 0);
                goto err;
            }
            if (s->version > 0x300) {
                q[0] = n >> 8;
                q[1] = n;
                n += 2;
            }
            s->session->master_key_length = s->method->enc->generate_master_secret(s, s->session->master_key, tmp_buf, sizeof(tmp_buf));
            if (s->session->master_key_length == 0) {
                goto err;
            }
            func_0011D534(tmp_buf, 0, 0x30);
        } else if (l & 0x16) {
            if ((l & 0x100000) && s->session->cert->f30 != 0) {
                dh_srvr = s->session->cert->f30;
            } else if (!(l & 0x100000) && s->session->cert->f2C != 0) {
                dh_srvr = s->session->cert->f2C;
            } else {
                func_L39_004C9F50(s, 2, 0x28);
                func_L39_004BC6C8(0x14, 0x99, 0xEE, 0, 0);
                goto err;
            }
            dh_clnt = func_L39_004DD5E0(dh_srvr);
            if (dh_clnt == 0) {
                func_L39_004BC6C8(0x14, 0x99, 0x805, 0, 0);
                goto err;
            }
            if (func_L39_004DD4C0(dh_clnt) == 0) {
                func_L39_004BC6C8(0x14, 0x99, 0x805, 0, 0);
                goto err;
            }
            func_L39_004DD378(dh_srvr, 3, &a, &b);
            if (func_L39_004DD520(p, &n, max - (p - d), a, b, dh_clnt) <= 0) {
                func_L39_004BC6C8(0x14, 0x99, 0x805, 0, 0);
                goto err;
            }
            s->session->master_key_length = s->method->enc->generate_master_secret(s, s->session->master_key, p, n);
            if (s->session->master_key_length == 0) {
                goto err;
            }
            func_0011D534(p, 0, n);
            func_L39_004DD378(dh_clnt, 3, &a, &n);
            p[0] = n >> 8;
            p[1] = n;
            func_0011D380(p + 2, a, n);
            n += 2;
            func_L39_004DD250(dh_clnt);
        } else {
            func_L39_004C9F50(s, 2, 0x28);
            func_L39_004BC6C8(0x14, 0x99, 0x9D, 0, 0);
            goto err;
        }
        *(d++) = 0x10;
        d[0] = n >> 16;
        d[1] = n >> 8;
        d[2] = n;
        s->state = 0x1181;
        s->init_off = 0;
        s->init_num = n + 4;
    }
    return func_L39_004CA180((SSL_004C6BA0 *)s, 0x16);
err:
    if (dh_clnt != 0) {
        func_L39_004DD250(dh_clnt);
    }
    return -1;
}
/* localdecomp:end func_L39_004C8110 */
