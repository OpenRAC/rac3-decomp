#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004C0E50 */
typedef struct C_004C0E50 {
    s32 length;
    u8 *data;
} C_004C0E50;
typedef struct E_004C0E50 {
    u8 _00[0x90];
    s32 conn_id_length;
    u8 conn_id[16];
} E_004C0E50;
typedef struct S_004C0E50 {
    u8 _00[0x30];
    s32 state;
    u8 _34[0x3C - 0x34];
    C_004C0E50 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 _48[0x50 - 0x48];
    E_004C0E50 *s2;
} S_004C0E50;
extern void *func_0011D380(void *, const void *, unsigned int);
extern s32 func_L39_004C6020(S_004C0E50 *);

s32 func_L39_004C0E50(S_004C0E50 *s) {
    u8 *p;

    if (s->state == 0x1040) {
        p = s->init_buf->data;
        *(p++) = 3;
        func_0011D380(p, s->s2->conn_id, (unsigned int)s->s2->conn_id_length);

        s->state = 0x1041;
        s->init_num = s->s2->conn_id_length + 1;
        s->init_off = 0;
    }
    return func_L39_004C6020(s);
}
/* localdecomp:end func_L39_004C0E50 */

/* localdecomp:start func_L39_004C0EC8 */
typedef struct PK_004C0EC8 {
    void *x509;
    void *pkey;
} PK_004C0EC8;
typedef struct CR_004C0EC8 {
    s32 pad0;
    u8 *key;
} CR_004C0EC8;
typedef struct SS_004C0EC8 {
    u8 pad0[0x90];
    CR_004C0EC8 *sess_cert;
} SS_004C0EC8;
typedef struct S2_004C0EC8 {
    u8 pad0[0xA4];
    s32 key_len;
    u8 key[1];
} S2_004C0EC8;
typedef struct XC_004C0EC8 {
    u8 pad0[0x80];
    void (*cb)(void *, s32, s32, void *);
    void *arg;
    u8 pad88[0xDC - 0x88];
    s32 (*client_cert_cb)(void *, void **, void **);
    u8 pade0[0x100 - 0xE0];
    void *md;
} XC_004C0EC8;
typedef struct B_004C0EC8 {
    s32 pad0;
    u8 *data;
} B_004C0EC8;
typedef struct T_004C0EC8 {
    u8 pad0[0x18];
    s32 rwstate;
    u8 pad1C[0x30 - 0x1C];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C0EC8 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 pad48[0x50 - 0x48];
    S2_004C0EC8 *s2;
    u8 pad54[0x84 - 0x54];
    CR_004C0EC8 *cert;
    u8 pad88[0xB0 - 0x88];
    SS_004C0EC8 *session;
    u8 padB4[0xC4 - 0xB4];
    void (*msg_cb)(void *, s32, s32, void *);
    void *msg_arg;
    u8 padCC[0xDC - 0xCC];
    XC_004C0EC8 *ctx;
    u8 padE0[0x128 - 0xE0];
    void *sign_ctx;
} T_004C0EC8;

struct S_004C1318;
extern s32 func_L39_004C52B0(struct S_004C1318 *, u8 *, s32);
extern s32 func_L39_004C5F70(struct S_004C1318 *, s32, s32);
extern void func_L39_004C6100(struct S_004C1318 *, s32);
extern s32 func_L39_004C4F48(T_004C0EC8 *, void *);
extern s32 func_L39_004C5000(T_004C0EC8 *, void *);
extern void func_L39_004BBBA0(void *);
extern void func_L39_004BC420(void *);
extern s32 func_L39_004DD690(void *, void *);
extern void func_L39_004DD778(void *, void *, s32);
extern s32 func_L39_004BBC30(void *, u8 **);
extern s32 func_L39_004E1320(void *, u8 *, u32 *, void *);

s32 func_L39_004C0EC8(T_004C0EC8 *s) {
    u8 *buf = s->init_buf->data;
    u8 *cert_ch = buf + 2;
    s32 cert_ch_len = 0;
    s32 i;
    s32 no_cert = 0;
    void (*cb)(void *, s32, s32, void *) = 0;
    void *cb_arg = 0;
    u8 *p;
    u8 *d;
    u32 n;
    void *x509;
    void *pkey;

    if (s->state == 0x1050) {
        i = func_L39_004C52B0((struct S_004C1318 *)s, buf + s->init_num, 0x21 - s->init_num);
        if (i < 0x11 - s->init_num) {
            return func_L39_004C5F70((struct S_004C1318 *)s, 0x64, i);
        }
        if (buf[1] != 1) {
            func_L39_004C6100((struct S_004C1318 *)s, 6);
            func_L39_004BC6C8(0x14, 0x64, 0x66, 0, 0);
            return -1;
        }
        cert_ch_len = i - 1;
        if (s->cert == 0 || ((PK_004C0EC8 *)s->cert->key)->x509 == 0 || ((PK_004C0EC8 *)s->cert->key)->pkey == 0) {
            s->state = 0x1090;
        } else {
            s->state = 0x1052;
        }
    }

    if (s->state == 0x1090) {
        i = 0;
        x509 = 0;
        pkey = 0;
        if (s->ctx->client_cert_cb != 0) {
            i = s->ctx->client_cert_cb(s, &x509, &pkey);
        }
        if (i < 0) {
            s->rwstate = 4;
            return -1;
        }
        s->rwstate = 1;
        if (i == 1 && pkey != 0 && x509 != 0) {
            s->state = 0x1052;
            if (!func_L39_004C4F48(s, x509) || !func_L39_004C5000(s, pkey)) {
                i = 0;
            }
            func_L39_004BBBA0(x509);
            func_L39_004BC420(pkey);
        } else if (i == 1) {
            if (x509 != 0) {
                func_L39_004BBBA0(x509);
            }
            if (pkey != 0) {
                func_L39_004BC420(pkey);
            }
            func_L39_004BC6C8(0x14, 0x64, 0x6A, 0, 0);
            i = 0;
        }
        if (i == 0) {
            p = buf;
            s->state = 0x1051;
            *(p++) = 0;
            p[0] = 0;
            p[1] = 2;
            p += 2;
            s->init_num = 3;
            s->init_off = 0;
            no_cert = 1;
        }
    }

    if (s->state == 0x1051) {
        i = func_L39_004C6020((S_004C0E50 *)s);
        if (no_cert == 1) {
            if (s->msg_cb != 0) {
                cb = s->msg_cb;
                cb_arg = s->msg_arg;
            } else if (s->ctx->cb != 0) {
                cb = s->ctx->cb;
                cb_arg = s->ctx->arg;
            }
            if (cb != 0) {
                cb(s, 0x4008, 2, cb_arg);
            }
        }
        return i;
    }

    if (s->state == 0x1052) {
        if (func_L39_004DD690(s->sign_ctx, s->ctx->md) == 0) {
            return -1;
        }
        func_L39_004DD778(s->sign_ctx, s->s2->key, s->s2->key_len);
        func_L39_004DD778(s->sign_ctx, cert_ch, cert_ch_len);
        p = buf;
        n = func_L39_004BBC30(((PK_004C0EC8 *)s->session->sess_cert->key)->x509, &p);
        func_L39_004DD778(s->sign_ctx, buf, n);
        p = buf;
        d = p + 6;
        *(p++) = 8;
        *(p++) = 1;
        n = func_L39_004BBC30(((PK_004C0EC8 *)s->cert->key)->x509, &d);
        p[0] = (n >> 8) & 0xff;
        p[1] = n & 0xff;
        p += 2;
        if (func_L39_004E1320(s->sign_ctx, d, &n, ((PK_004C0EC8 *)s->cert->key)->pkey) <= 0) {
            goto fail;
        }
        p[0] = (n >> 8) & 0xff;
        p[1] = n & 0xff;
        p += 2;
        d += n;
        s->init_num = d - buf;
        s->init_off = 0;
        s->state = 0x1053;
    }
    return func_L39_004C6020((S_004C0E50 *)s);
fail:
    return -1;
}
/* localdecomp:end func_L39_004C0EC8 */

/* localdecomp:start func_L39_004C1318 */
typedef struct P_004C1318 {
    u8 pad0[0x6C];
    s32 len;
    u8 data[1];
} P_004C1318;

typedef struct B_004C1318 {
    s32 pad0;
    u8 *buf;
} B_004C1318;

typedef struct S_004C1318 {
    u8 pad0[0x30];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C1318 *b;
    s32 pos;
    u8 pad44[0x50 - 0x44];
    P_004C1318 *p;
} S_004C1318;

extern s32 func_L39_004C52B0(S_004C1318 *, u8 *, s32);
extern s32 func_L39_004C5F70(S_004C1318 *, s32, s32);
extern void func_L39_004C6100(S_004C1318 *, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_11D2EC(void *, void *, s32);

s32 func_L39_004C1318(S_004C1318 *s) {
    u8 *buf = s->b->buf;
    s32 n;

    if (s->state == 0x1060) {
        n = func_L39_004C52B0(s, buf + s->pos, 1 - s->pos);
        if (n < 1 - s->pos) {
            return func_L39_004C5F70(s, 0x6E, n);
        }
        s->pos = 0;
        s->state = 0x1061;
        if (buf[0] != 5) {
            if (buf[0] != 0) {
                func_L39_004C6100(s, 0);
                func_L39_004BC6C8(0x14, 0x6E, 0xD4, 0, 0);
            } else {
                func_L39_004BC6C8(0x14, 0x6E, 0xC8, 0, 0);
            }
            return -1;
        }
    }
    n = func_L39_004C52B0(s, buf + s->pos, s->p->len - s->pos);
    if (n < s->p->len - s->pos) {
        return func_L39_004C5F70(s, 0x6E, n);
    }
    if (func_11D2EC(buf, s->p->data, s->p->len)) {
        func_L39_004C6100(s, 0);
        func_L39_004BC6C8(0x14, 0x6E, 0x88, 0, 0);
        return -1;
    }
    return 1;
}
/* localdecomp:end func_L39_004C1318 */

/* localdecomp:start func_L39_004C1478 */
typedef struct V_004C1478 {
    u8 b[16];
} V_004C1478;

typedef struct P_004C1478 {
    u8 pad0[0x44];
    s32 len;
    V_004C1478 data;
} P_004C1478;

typedef struct B_004C1478 {
    s32 pad0;
    u8 *buf;
} B_004C1478;

struct S_004C1478;
typedef void (*CB_004C1478)(struct S_004C1478 *, s32, s32);

typedef struct D_004C1478 {
    u8 pad0[0x7C];
    CB_004C1478 cb;
} D_004C1478;

typedef struct S_004C1478 {
    u8 pad0[0x30];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C1478 *b;
    s32 pos;
    u8 pad44[0x5C - 0x44];
    s32 x5C;
    u8 pad60[0xB0 - 0x60];
    s32 p;
    u8 padB4[0xC0 - 0xB4];
    CB_004C1478 cb;
    u8 padC4[0xDC - 0xC4];
    D_004C1478 *d;
    u8 padE0[0x100 - 0xE0];
    unsigned long flags;
} S_004C1478;

s32 func_L39_004C1478(S_004C1478 *s) {
    u8 *buf = s->b->buf;
    s32 n;
    CB_004C1478 cb;

    if (s->state == 0x1070) {
        n = func_L39_004C52B0((S_004C1318 *)s, buf + s->pos, 1 - s->pos);
        if (n < 1 - s->pos) {
            return func_L39_004C5F70((S_004C1318 *)s, 0x6C, n);
        }
        s->pos = n;
        if (buf[0] == 7) {
            s->state = 0x1091;
            if (s->cb != 0) {
                cb = s->cb;
            } else {
                cb = s->d->cb;
            }
            if (cb) {
                cb(s, 0x1001, 1);
            }
            s->state = 0x1050;
            return 1;
        }
        if (buf[0] != 6) {
            if (buf[0] != 0) {
                func_L39_004C6100((S_004C1318 *)s, 0);
                func_L39_004BC6C8(0x14, 0x6C, 0xD4, 0, 0);
            } else {
                func_L39_004BC6C8(0x14, 0x6C, 0xC8, 0, 0);
            }
            return -1;
        }
        s->pos = 0;
        s->state = 3;
    }
    n = func_L39_004C52B0((S_004C1318 *)s, buf + s->pos, 16 - s->pos);
    if (n < 16 - s->pos) {
        return func_L39_004C5F70((S_004C1318 *)s, 0x6C, n);
    }
    if (s->x5C != 0) {
        if (!(s->flags & 1)) {
            if (func_11D2EC(buf, &((P_004C1478 *)s->p)->data, ((P_004C1478 *)s->p)->len)) {
                func_L39_004C6100((S_004C1318 *)s, 0);
                func_L39_004BC6C8(0x14, 0x6C, 0xE7, 0, 0);
                return -1;
            }
        }
    } else {
        ((P_004C1478 *)s->p)->len = 16;
        ((P_004C1478 *)s->p)->data = *(V_004C1478 *)buf;
    }
    return 1;
}
/* localdecomp:end func_L39_004C1478 */

/* localdecomp:start func_L39_004C1660 */
typedef struct PK_004C1660 {
    void *x509;
    void *pkey;
} PK_004C1660;
typedef struct SC_004C1660 {
    u8 pad0[4];
    PK_004C1660 *peer_key;
    u8 pad8[0x40 - 0x8];
    PK_004C1660 peer_pkeys[1];
} SC_004C1660;
typedef struct SESS_004C1660 {
    u8 pad0[0x90];
    void *sess_cert;
} SESS_004C1660;
typedef struct CTX_004C1660 {
    u8 pad0[0x80];
    void (*cb)(void *, s32, s32, void *);
    void *arg;
} CTX_004C1660;
typedef struct PKEY_004C1660 {
    s32 type;
} PKEY_004C1660;
typedef struct S_004C1660 {
    u8 pad0[0xB0];
    SESS_004C1660 *session;
    s32 verify_mode;
    u8 padB8[0xC4 - 0xB8];
    void (*cb)(void *, s32, s32, void *);
    void *arg;
    u8 padCC[0xDC - 0xCC];
    CTX_004C1660 *ctx;
} S_004C1660;

extern void *func_L39_004BBC78(void *, u8 **, long);
extern void *func_L39_004CC228(void *);
extern s32 func_L39_004CC3E0(void *, void *);
extern s32 func_L39_004C35D8(S_004C1660 *, void *);
extern SC_004C1660 *func_L39_004C3428(void);
extern void func_L39_004C3498(void *);
extern PKEY_004C1660 *func_L39_004BBDE0(void *);
extern s32 func_L39_004C35C8(SC_004C1660 *, s32);
extern void func_L39_004CC538(void *);
extern void func_L39_004BBBA0(void *);

s32 func_L39_004C1660(S_004C1660 *s, s32 a1, s32 len, u8 *data) {
    void (*cb)(void *, s32, s32, void *) = 0;
    void *cb_arg = 0;
    void *sk = 0;
    void *x509 = 0;
    PKEY_004C1660 *pkey;
    SC_004C1660 *sc;
    s32 ret = 0;
    s32 i;

    if (s->cb != 0) {
        cb = s->cb;
        cb_arg = s->arg;
    } else if (s->ctx->cb != 0) {
        cb = s->ctx->cb;
        cb_arg = s->ctx->arg;
    }

    x509 = func_L39_004BBC78(0, &data, len);
    if (x509 == 0) {
        if (cb != 0) {
            cb(s, 0x4004, 0, cb_arg);
        }
        func_L39_004BC6C8(0x14, 0x7E, 0x80B, 0, 0);
        goto err;
    }

    sk = func_L39_004CC228(0);
    if (sk == 0 || !func_L39_004CC3E0(sk, x509)) {
        if (cb != 0) {
            cb(s, 0x4004, 0, cb_arg);
        }
        func_L39_004BC6C8(0x14, 0x7E, 0x21, 0, 0);
        goto err;
    }

    i = func_L39_004C35D8(s, sk);
    if (s->verify_mode != 0 && i == 0) {
        if (cb != 0) {
            cb(s, 0x4004, 0, cb_arg);
        }
        func_L39_004BC6C8(0x14, 0x7E, 0x86, 0, 0);
        goto err;
    }

    sc = func_L39_004C3428();
    if (sc == 0) {
        ret = -1;
        goto err;
    }
    if (s->session->sess_cert != 0) {
        func_L39_004C3498(s->session->sess_cert);
    }
    s->session->sess_cert = sc;

    sc->peer_pkeys[0].x509 = x509;
    sc->peer_key = &sc->peer_pkeys[0];

    pkey = func_L39_004BBDE0(x509);
    x509 = 0;
    if (pkey == 0) {
        if (cb != 0) {
            cb(s, 0x4004, 0, cb_arg);
        }
        func_L39_004BC6C8(0x14, 0x7E, 0xED, 0, 0);
        goto err;
    }
    if (pkey->type != 6) {
        if (cb != 0) {
            cb(s, 0x4004, 0, cb_arg);
        }
        func_L39_004BC6C8(0x14, 0x7E, 0xD2, 0, 0);
        goto err;
    }
    ret = func_L39_004C35C8(sc, 1) != 0;

err:
    if (sk != 0) {
        func_L39_004CC538(sk);
    }
    if (x509 != 0) {
        func_L39_004BBBA0(x509);
    }
    return ret;
}
/* localdecomp:end func_L39_004C1660 */

/* localdecomp:start func_L39_004C18B8 */
typedef struct P_004C18B8 {
    s32 f0;
    char _p4[0x8];
    s32 fC;
} P_004C18B8;
typedef struct A_004C18B8 {
    char _p0[4];
    void **f4;
} A_004C18B8;

extern s32 func_L39_004EA8A0(s32, s32, s32, s32, s32);

s32 func_L39_004C18B8(A_004C18B8 *arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 ret;
    P_004C18B8 *p;

    ret = -1;
    if (arg0 == 0 || *arg0->f4 == 0 || (p = (P_004C18B8 *)((void *(*)(void *))func_L39_004BBDE0)(*arg0->f4)) == 0) {
        func_L39_004BC6C8(20, 188, 192, 0, 0);
        return -1;
    }
    if (p->f0 != 6) {
        func_L39_004BC6C8(20, 188, 209, 0, 0);
    } else {
        ret = func_L39_004EA8A0(a1, a2, a3, p->fC, a4);
        if (ret < 0) {
            func_L39_004BC6C8(20, 188, 2052, 0, 0);
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004C18B8 */

/* localdecomp:start func_L39_004C19B8 */
typedef struct X_004C19B8 { s32 f0; s32 f4; s32 f8; } X_004C19B8;
typedef struct K_004C19B8 { char pad[0x64]; u8 *read_key; u8 *write_key; char pad2[0x38]; s32 key_len; u8 key[1]; } K_004C19B8;
typedef struct E_004C19B8 { char pad[8]; u8 master[0xA4]; s32 cipher; } E_004C19B8;
typedef struct S_004C19B8 {
    char pad0[0x50]; u8 *s2;
    char pad1[0x14]; X_004C19B8 read; X_004C19B8 write;
    void *f80;
    char pad3[0x2C]; E_004C19B8 *session;
} S_004C19B8;
extern s32 func_L39_004CA3D0(s32, void **, void **);
extern s32 func_L39_004DE940(void);
extern s32 func_L01_00494120(void *p);
extern s32 func_L39_004DE550(void);
extern s32 func_L39_004DE458(s32);
extern void func_L39_004DE9B8(void);
extern s32 func_L39_004DE8F8(void *);
extern void func_L39_004C1F40(S_004C19B8 *);
extern s32 func_L39_004DE5D0(void *, void *, u8 *, u8 *);
extern s32 func_L39_004DE650(void *, void *, u8 *, u8 *);
s32 func_L39_004C19B8(S_004C19B8 *s, s32 client) {
    s32 ctx[2];
    void *c;
    void *md;
    s32 i;
    s32 num;
    s32 rs;
    s32 ws;

    if (!func_L39_004CA3D0(s->session->cipher, &c, &md)) {
        func_L39_004C6100((S_004C1318 *)s, 1);
        func_L39_004BC6C8(0x14, 0x7C, 0xCE, 0, 0);
        return 0;
    }
    ctx[0] = (s32)&s->read;
    ctx[1] = (s32)&s->write;
    for (i = 0; i < 2; i++) {
        if (((X_004C19B8 *)ctx[i])->f4 == 0) {
            if ((((X_004C19B8 *)ctx[i])->f4 = func_L39_004DE940()) == 0) goto err;
        }
        if (!((s32 (*)(s32, void *))func_L39_004DD690)(((X_004C19B8 *)ctx[i])->f4, md)) goto err;
        ((X_004C19B8 *)ctx[i])->f0 = func_L01_00494120(md);
        if (((X_004C19B8 *)ctx[i])->f8 == 0) {
            if ((((X_004C19B8 *)ctx[i])->f8 = func_L39_004DE550()) == 0) goto err;
        }
        if (!func_L39_004DE458(((X_004C19B8 *)ctx[i])->f8)) goto err;
    }
    rs = s->write.f8;
    ws = s->read.f8;
    s->f80 = func_L39_004DE9B8;
    num = func_L39_004DE8F8(c);
    ((K_004C19B8 *)s->s2)->key_len = num * 2;
    func_L39_004C1F40(s);
    {
        u8 *k = ((K_004C19B8 *)s->s2)->key;
        if (!func_L39_004DE5D0((void *)rs, c, client ? k + num : k, s->session->master)) goto err;
    }
    {
        u8 *k = ((K_004C19B8 *)s->s2)->key;
        if (!func_L39_004DE650((void *)ws, c, client ? k : k + num, s->session->master)) goto err;
    }
    {
        u8 *k = ((K_004C19B8 *)s->s2)->key;
        ((K_004C19B8 *)s->s2)->read_key = client ? k : k + num;
    }
    {
        u8 *k = ((K_004C19B8 *)s->s2)->key;
        ((K_004C19B8 *)s->s2)->write_key = client ? k + num : k;
    }
    return 1;
err:
    func_L39_004BC6C8(0x14, 0x7C, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004C19B8 */

/* localdecomp:start func_L39_004C1BA8 */
typedef struct S_004C1BA8 {
    u8 _00[0x54];
    s32 *p54;
} S_004C1BA8;
extern s32 *func_L39_004CBF60(void);
extern S_004C1BA8 D_L39_00464A68;

void func_L39_004C1BA8(void) {
    s32 *v = func_L39_004CBF60();
    S_004C1BA8 *s = &D_L39_00464A68;

    if (s->p54 == 0) {
        s->p54 = v + 4;
    }
}
/* localdecomp:end func_L39_004C1BA8 */

/* localdecomp:start func_L39_004C1BE0 */
s32 func_L39_004C1BE0(void) {
    return 300;
}
/* localdecomp:end func_L39_004C1BE0 */
