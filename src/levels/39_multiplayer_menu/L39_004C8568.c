#include "common.h"

/* localdecomp:start func_L39_004C8568 */
typedef struct M_004C8568 { char pad[0x1C]; s32 (*fn)(void *, s32, u8 *); } M_004C8568;
typedef struct T_004C8568 { char pad[0x54]; M_004C8568 *m; } T_004C8568;
typedef struct K_004C8568 { s32 type; s32 f4; char pad[4]; s32 fC; } K_004C8568;
typedef struct C_004C8568 {
    char pad0[8]; T_004C8568 *meth;
    char pad1[0x24]; s32 state;
    char pad2[8]; struct { s32 f0; u8 *data; } *buf;
    s32 f40; s32 f44;
    char pad3[0xC]; char *s3;
    char pad4[0x2C]; struct { s32 f0; struct { s32 f0; K_004C8568 *key; } *p; } *cert;
} C_004C8568;
extern s32 func_L39_004EA938(s32, u8 *, u8 *, s32 *, s32);
extern s32 func_L39_004DD938(s32, u8 *, s32, u8 *, s32 *, s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004CA180(C_004C8568 *, s32);
s32 func_L39_004C8568(C_004C8568 *s) {
    u8 data[0x30];
    s32 j;
    u8 *p;
    u8 *d;
    K_004C8568 *pkey;
    s32 i;
    u64 n;

    if (s->state == 0x1190) {
        d = s->buf->data;
        p = d + 4;
        pkey = s->cert->p->key;
        if (s->meth->m->fn(s, *(s32 *)(s->s3 + 0xFC), &data[0x10]) == 0) goto err;
        if (pkey->type == 6) {
            if (s->meth->m->fn(s, *(s32 *)(s->s3 + 0xF8), data) == 0) goto err;
            i = func_L39_004EA938(0x24, data, d + 6, (s32 *)pkey->fC, 1);
            if (i <= 0) {
                func_L39_004BC6C8(0x14, 0x9A, 0x804, 0, 0);
                goto err;
            }
            d[4] = i >> 8;
            p[1] = i;
            n = i + 2;
        } else if (pkey->type == 0x74) {
            if (!func_L39_004DD938(pkey->f4, &data[0x10], 0x14, d + 6, &j, pkey->fC)) {
                func_L39_004BC6C8(0x14, 0x9A, 0x80A, 0, 0);
                goto err;
            }
            d[4] = j >> 8;
            p[1] = j;
            n = j + 2;
        } else {
            func_L39_004BC6C8(0x14, 0x9A, 0x9D, 0, 0);
            goto err;
        }
        *d++ = 0xF;
        d[0] = (u8)((n >> 16) & 0xFF);
        d[1] = (u8)((n >> 8) & 0xFF);
        d[2] = (u8)(n & 0xFF);
        s->f40 = (s32)n + 4;
        s->f44 = 0;
    }
    return func_L39_004CA180(s, 0x16);
err:
    return -1;
}
/* localdecomp:end func_L39_004C8568 */

/* localdecomp:start func_L39_004C8748 */
typedef struct K_004C8748 {
    void *x509;
    void *privatekey;
} K_004C8748;

typedef struct C_004C8748 {
    s32 f0;
    K_004C8748 *key;
} C_004C8748;

typedef struct S3_004C8748 {
    char _p0[0x16C];
    s32 cert_req;
} S3_004C8748;

struct S_004C8748;

typedef struct X_004C8748 {
    char _p0[0xDC];
    s32 (*client_cert_cb)(struct S_004C8748 *, void **, void **);
} X_004C8748;

typedef struct S_004C8748 {
    s32 version;
    char _p4[0x18 - 0x4];
    s32 rwstate;
    char _p1C[0x30 - 0x1C];
    s32 state;
    char _p34[0x40 - 0x34];
    s32 init_num;
    s32 init_off;
    char _p48[0x54 - 0x48];
    S3_004C8748 *s3;
    char _p58[0x84 - 0x58];
    C_004C8748 *cert;
    char _p88[0xDC - 0x88];
    X_004C8748 *ctx;
} S_004C8748;

extern s32 func_L39_004C4F48(S_004C8748 *, void *);
extern s32 func_L39_004C5000(S_004C8748 *, void *);
extern void func_L39_004BBBA0(void *);
extern void func_L39_004BC420(void *);
extern unsigned long func_L39_004EB100(S_004C8748 *, void *);

s32 func_L39_004C8748(S_004C8748 *s) {
    void *x509 = 0;
    void *pkey = 0;
    s32 i;
    unsigned long l;

    if (s->state == 0x1170) {
        if (s->cert == 0 || s->cert->key->x509 == 0 || s->cert->key->privatekey == 0) {
            s->state = 0x1171;
        } else {
            s->state = 0x1172;
        }
    }
    if (s->state == 0x1171) {
        i = 0;
        if (s->ctx->client_cert_cb != 0) {
            i = s->ctx->client_cert_cb(s, &x509, &pkey);
        }
        if (i < 0) {
            s->rwstate = 4;
            return -1;
        }
        s->rwstate = 1;
        if (i == 1 && pkey != 0 && x509 != 0) {
            s->state = 0x1171;
            if (!func_L39_004C4F48(s, x509) || !func_L39_004C5000(s, pkey)) {
                i = 0;
            }
        } else if (i == 1) {
            i = 0;
            func_L39_004BC6C8(0x14, 0x98, 0x6A, 0, 0);
        }
        if (x509 != 0) {
            func_L39_004BBBA0(x509);
        }
        if (pkey != 0) {
            func_L39_004BC420(pkey);
        }
        if (i == 0) {
            if (s->version == 0x300) {
                s->s3->cert_req = 0;
                func_L39_004C9F50(s, 1, 0x29);
                return 1;
            } else {
                s->s3->cert_req = 2;
            }
        }
        s->state = 0x1172;
    }
    if (s->state == 0x1172) {
        s->state = 0x1173;
        l = func_L39_004EB100(s, (s->s3->cert_req == 2) ? 0 : s->cert->key->x509);
        s->init_num = (s32)l;
        s->init_off = 0;
    }
    return func_L39_004CA180((C_004C8568 *)s, 0x16);
}
/* localdecomp:end func_L39_004C8748 */

/* localdecomp:start func_L39_004C8950 */
/* OpenSSL ssl3_check_cert_and_algorithm (s3_clnt.c), older layout */
typedef struct {
    void *x509;
    void *privatekey;
} PK_004C8950;

typedef struct {
    s32 peer_cert_type;
    u8 pad4[0x1C];
    void *rsa_a;
    void *rsa_b;
    void *rsa_c;
    void *dh_a;
    void *dh_b;
    u8 pad34[0xC];
    PK_004C8950 peer_pkeys[1];
} SC_004C8950;

typedef struct {
    u8 pad0[0x90];
    SC_004C8950 *sess_cert;
} SESS_004C8950;

typedef struct {
    u8 pad0[0x10];
    long algorithms;
    long algo_strength;
} CIPH_004C8950;

typedef struct {
    u8 pad0[0x15C];
    CIPH_004C8950 *new_cipher;
} S3_004C8950;

typedef struct {
    u8 pad0[0x54];
    S3_004C8950 *s3;
    u8 pad58[0x58];
    SESS_004C8950 *session;
} SSL_004C8950;

extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BBD08(void *);
extern void *func_L39_004BBDE0(void *);
extern s32 func_L39_004CC0B0(void *, void *);
extern u32 func_L39_004EA5A8(void *);
extern u32 func_L39_004DD2D8(void *);
extern void func_L39_004C9F50(SSL_004C8950 *, s32, s32);

s32 func_L39_004C8950(SSL_004C8950 *s) {
    s32 i;
    s32 idx;
    long algs;
    long strength;
    SC_004C8950 *sc;
    void *rsa = 0;
    void *dh;

    sc = s->session->sess_cert;
    if (sc == 0) {
        func_L39_004BC6C8(0x14, 0x82, 0x9D, 0, 0);
        return 0;
    }

    algs = s->s3->new_cipher->algorithms;
    strength = s->s3->new_cipher->algo_strength;

    if (algs & 0x300) {
        return 1;
    }

    if (algs & 0x100000) {
        if ((s32)(strength & 0xFF00) == 0x400) {
            rsa = sc->rsa_c;
        }
        if (rsa == 0) {
            rsa = sc->rsa_b;
        }
        dh = sc->dh_b;
    } else {
        rsa = sc->rsa_a;
        dh = sc->dh_a;
    }

    idx = sc->peer_cert_type;
    i = func_L39_004CC0B0(func_L39_004BBD08(sc->peer_pkeys[idx].x509),
                          func_L39_004BBDE0(sc->peer_pkeys[idx].x509));

    if ((algs & 0x20) && (i & 0x11) != 0x11) {
        func_L39_004BC6C8(0x14, 0x82, 0xAA, 0, 0);
        goto f_err;
    } else if ((algs & 0x40) && (i & 0x12) != 0x12) {
        func_L39_004BC6C8(0x14, 0x82, 0xA5, 0, 0);
        goto f_err;
    }
    if ((algs & 0x1) && !((i & 0x21) == 0x21 || rsa != 0)) {
        func_L39_004BC6C8(0x14, 0x82, 0xA9, 0, 0);
        goto f_err;
    }
    if ((algs & 0x10) && !((i & 0x44) == 0x44 || dh != 0)) {
        func_L39_004BC6C8(0x14, 0x82, 0xA3, 0, 0);
        goto f_err;
    } else if ((algs & 0x2) && (i & 0x104) != 0x104) {
        func_L39_004BC6C8(0x14, 0x82, 0xA4, 0, 0);
        goto f_err;
    } else if ((algs & 0x4) && (i & 0x204) != 0x204) {
        func_L39_004BC6C8(0x14, 0x82, 0xA2, 0, 0);
        goto f_err;
    }

    if ((algs & 0x100000) && !(i & 0x1000)) {
        if (algs & 0x1) {
            if (rsa == 0 || func_L39_004EA5A8(rsa) > (s32)(strength & 0xFF00)) {
                func_L39_004BC6C8(0x14, 0x82, 0xA7, 0, 0);
                goto f_err;
            }
        } else if (algs & 0x16) {
            if (dh == 0 || func_L39_004DD2D8(dh) > (s32)(strength & 0xFF00)) {
                func_L39_004BC6C8(0x14, 0x82, 0xA6, 0, 0);
                goto f_err;
            }
        } else {
            func_L39_004BC6C8(0x14, 0x82, 0xFA, 0, 0);
            goto f_err;
        }
    }
    return 1;
f_err:
    func_L39_004C9F50(s, 2, 0x28);
    return 0;
}
/* localdecomp:end func_L39_004C8950 */

INCLUDE_ASM("asm/levels", func_L39_004C8C10);

INCLUDE_ASM("asm/levels", func_L39_004C8E30);
