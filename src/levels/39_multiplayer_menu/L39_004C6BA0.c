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

/* localdecomp:start func_L39_004C6E08 */
typedef struct { u8 b[32]; } V32_004C6E08;
typedef struct {
    char _p0[0x38];
    s32 (*f38)(void *);
    s32 (*f3C)(void *, void *);
} T8_004C6E08;
typedef struct {
    char _p0[0x44];
    s32 f44;
    u8 f48[0xAC - 0x48];
    s32 fAC;
} TB0_004C6E08;
typedef struct {
    char _p0[0x44];
    V32_004C6E08 f44;
    char _p64[0x15C - 0x64];
    s32 f15C;
} T54_004C6E08;
typedef struct { s32 f0; u8 *f4; } T3C_004C6E08;
typedef struct {
    s32 f0;
    char _p4[4];
    T8_004C6E08 *f8;
    char _pC[0x3C - 0xC];
    T3C_004C6E08 *f3C;
    char _p40[0x54 - 0x40];
    T54_004C6E08 *f54;
    char _p58[4];
    s32 f5C;
    char _p60[0xB0 - 0x60];
    s32 fB0;
    char _pB4[0x100 - 0xB4];
    s64 f100;
} S_004C6E08;
extern s32 func_L39_004C4198(S_004C6E08 *);
extern s32 func_L39_004CC2C8(s32, s32);
s32 func_L39_004C6E08(S_004C6E08 *a) {
    s32 out;
    long r;
    u8 *p;
    u8 *start;
    u32 len;
    u32 res;
    u32 err;

    r = func_L39_004EB540(a, 0x1120, 0x1121, 2, 0x400, &out);
    if (out == 0) {
        return r;
    }
    p = a->f3C->f4;
    start = p;
    if (p[0] != (a->f0 >> 8) || p[1] != (a->f0 & 0xFF)) {
        func_L39_004BC6C8(20, 0x92, 0x10A, 0, 0);
        err = 0x46;
        a->f0 = (a->f0 & 0xFF00) | p[1];
        goto fail;
    }
    p += 2;
    a->f54->f44 = *(V32_004C6E08 *)p;
    p += 0x20;
    len = *p++;
    if (len > 0x20) {
        err = 0x2F;
        func_L39_004BC6C8(20, 0x92, 0x451, 0, 0);
        goto fail;
    }
    if (len != 0 && len == ((TB0_004C6E08 *)a->fB0)->f44 && func_0011D2EC(p, ((TB0_004C6E08 *)a->fB0)->f48, len) == 0) {
        a->f5C = 1;
    } else {
        a->f5C = 0;
        if (((TB0_004C6E08 *)a->fB0)->f44 != 0) {
            if (func_L39_004CB730((void *)a, 0) == 0) {
                err = 0x50;
                goto fail;
            }
        }
        ((TB0_004C6E08 *)a->fB0)->f44 = len;
        func_0011D380(((TB0_004C6E08 *)a->fB0)->f48, p, len);
    }
    p += len;
    res = a->f8->f38(p);
    if (res == 0) {
        err = 0x2F;
        func_L39_004BC6C8(20, 0x92, 0xF8, 0, 0);
        goto fail;
    }
    p += a->f8->f3C(0, 0);
    if (func_L39_004CC2C8(func_L39_004C4198(a), res) < 0) {
        err = 0x2F;
        func_L39_004BC6C8(20, 0x92, 0x105, 0, 0);
        goto fail;
    }
    if (a->f5C != 0 && ((TB0_004C6E08 *)a->fB0)->fAC != res && (a->f100 & 8) == 0) {
        err = 0x2F;
        func_L39_004BC6C8(20, 0x92, 0xC5, 0, 0);
        goto fail;
    }
    a->f54->f15C = res;
    res = *p++;
    if (res != 0) {
        err = 0x2F;
        func_L39_004BC6C8(20, 0x92, 0x101, 0, 0);
        goto fail;
    }
    if (p != start + (s32)r) {
        func_L39_004BC6C8(20, 0x92, 0x73, 0, 0);
        return -1;
    }
    return 1;
fail:
    func_L39_004C9F50(a, 2, err);
    return -1;
}
/* localdecomp:end func_L39_004C6E08 */

/* localdecomp:start func_L39_004C70F8 */
typedef struct { void *f0; void *f4; } E_004C70F8;
typedef struct { s32 f0; u8 *f4; } T3C_004C70F8;
typedef struct { void *f0; } T4_004C70F8;
typedef struct { char _p0[4]; void *f4; } T22_004C70F8;
typedef struct {
    s32 f0;
    void *f4;
    char _p8[0x40 - 0x8];
    E_004C70F8 f40[1];
} O_004C70F8;
typedef struct {
    char _p0[0x68];
    void *f68;
} O68_004C70F8;
typedef struct {
    char _p0[0x90];
    void *f90;
    void *f94;
} TB0_004C70F8;
typedef struct {
    char _p0[0x158];
    s32 f158;
    char _p15C[0x168 - 0x15C];
    s32 f168;
} T54_004C70F8;
typedef struct {
    char _p0[0x3C];
    T3C_004C70F8 *f3C;
    char _p40[0x54 - 0x40];
    T54_004C70F8 *f54;
    char _p58[0xB0 - 0x58];
    void *fB0;
    s32 fB4;
    char _pB8[0xE8 - 0xB8];
    s64 fE8;
    char _pF0[0x120 - 0xF0];
    s64 f120;
} S_004C70F8;
extern long func_L39_004EB540(void *, s32, s32, s32, long, s32 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004C9F50(void *, s32, s32);
extern void *func_L39_004CC228(s32);
extern void *func_L39_004BBC78(s32, u8 **, u64);
extern s32 func_L39_004CC3E0(void *, void *);
extern void *func_L39_004C35D8(void *, void *);
extern s32 func_L39_004EB840(s64);
extern void *func_L39_004C3428(void);
extern void func_L39_004C3498(void *);
extern void *func_L39_004BBDE0(void *);
extern s32 func_L39_004CC018(void *);
extern s32 func_L39_004EB798(void *, void *);
extern void func_L39_004BBCC0(void *);
extern void func_L39_004BBBA0(void *);
extern void func_L39_004CC510(void *, void (*)(void *));
s32 func_L39_004C70F8(S_004C70F8 *a) {
    s32 out;
    s64 r;
    s32 ret;
    T22_004C70F8 *l22;
    void *l20;
    u8 *cur;
    u8 *p;
    u64 total;
    u64 chunk;
    u64 i;
    s32 err;
    O_004C70F8 *obj;
    void *h;
    E_004C70F8 *slot;
    s32 off;
    E_004C70F8 *tab;

    ret = -1;
    l20 = 0;
    l22 = 0;
    chunk = 0x19000;
    r = func_L39_004EB540(a, 0x1130, 0x1131, -1, a->f120 ? a->f120 : chunk, &out);
    if (out == 0) {
        return r;
    }
    if (a->f54->f158 == 0xC) {
        a->f54->f168 = 1;
        return 1;
    }
    if (a->f54->f158 != 0xB) {
        err = 0xA;
        func_L39_004BC6C8(20, 0x90, 0x72, 0, 0);
        goto fail;
    }
    p = a->f3C->f4;
    l22 = func_L39_004CC228(0);
    if (l22 == 0) {
        func_L39_004BC6C8(20, 0x90, 0x21, 0, 0);
        goto cleanup;
    }
    total = ((u64)p[0] << 16) | ((u64)p[1] << 8) | p[2];
    p += 3;
    if (total + 3 != r) {
        err = 0x32;
        func_L39_004BC6C8(20, 0x90, 0x9F, 0, 0);
        goto fail;
    }
    for (i = 0; i < total; i += 3 + chunk) {
        chunk = ((u64)p[0] << 16) | ((u64)p[1] << 8) | p[2];
        p += 3;
        if (total < chunk + i + 3) {
            err = 0x32;
            func_L39_004BC6C8(20, 0x90, 0x87, 0, 0);
            goto fail;
        }
        cur = p;
        l20 = func_L39_004BBC78(0, &cur, chunk);
        if (l20 == 0) {
            err = 0x2A;
            func_L39_004BC6C8(20, 0x90, 0x80D, 0, 0);
            goto fail;
        }
        if (cur != p + (s32)chunk) {
            err = 0x32;
            func_L39_004BC6C8(20, 0x90, 0x87, 0, 0);
            goto fail;
        }
        if (func_L39_004CC3E0(l22, l20) == 0) {
            func_L39_004BC6C8(20, 0x90, 0x21, 0, 0);
            goto cleanup;
        }
        l20 = 0;
        p = cur;
    }
    h = func_L39_004C35D8(a, l22);
    if (a->fB4 != 0 && h == 0) {
        err = func_L39_004EB840(a->fE8);
        func_L39_004BC6C8(20, 0x90, 0x86, 0, 0);
        goto fail;
    }
    obj = func_L39_004C3428();
    if (obj == 0) {
        goto cleanup;
    }
    if (((TB0_004C70F8 *)a->fB0)->f90 != 0) {
        func_L39_004C3498(((TB0_004C70F8 *)a->fB0)->f90);
    }
    ((TB0_004C70F8 *)a->fB0)->f90 = obj;
    ((O68_004C70F8 *)obj)->f68 = l22;
    l20 = ((T4_004C70F8 *)l22->f4)->f0;
    l22 = 0;
    h = func_L39_004BBDE0(l20);
    if (h == 0 || func_L39_004CC018(h) != 0) {
        l20 = 0;
        err = 2;
        func_L39_004BC6C8(20, 0x90, 0xEF, 0, 0);
        goto fail;
    }
    err = func_L39_004EB798(l20, h);
    if (err < 0) {
        l20 = 0;
        err = 2;
        func_L39_004BC6C8(20, 0x90, 0xF7, 0, 0);
        goto fail;
    }
    obj->f0 = err;
    func_L39_004BBCC0(l20);
    tab = obj->f40;
    off = err * 8;
    slot = (E_004C70F8 *)((char *)tab + off);
    if (slot->f0 != 0) {
        func_L39_004BBBA0(slot->f0);
    }
    slot->f0 = l20;
    obj->f4 = (char *)obj + (off + 0x40);
    if (a->fB0 != 0 && ((TB0_004C70F8 *)a->fB0)->f94 != 0) {
        func_L39_004BBBA0(((TB0_004C70F8 *)a->fB0)->f94);
    }
    func_L39_004BBCC0(l20);
    ret = 1;
    ((TB0_004C70F8 *)a->fB0)->f94 = l20;
    l20 = 0;
    goto cleanup;
fail:
    func_L39_004C9F50(a, 2, err);
cleanup:
    if (l20 != 0) {
        func_L39_004BBBA0(l20);
    }
    if (l22 != 0) {
        func_L39_004CC510(l22, func_L39_004BBBA0);
    }
    return ret;
}
/* localdecomp:end func_L39_004C70F8 */

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
