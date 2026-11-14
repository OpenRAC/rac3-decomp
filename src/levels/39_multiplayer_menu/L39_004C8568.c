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

/* localdecomp:start func_L39_004C8C10 */
typedef struct S3_004C8C10 {
    char pad[0x8C];
    s32 left;
    s32 offset;
    u8 *buf;
    s32 len;
} S3_004C8C10;
typedef struct S_004C8C10 {
    char pad0[0xC];
    void *rbio;
    char pad10[8];
    s32 rwstate;
    char pad1C[0x2C];
    u8 *packet;
    u32 packet_length;
    char pad50[4];
    S3_004C8C10 *s3;
    s32 read_ahead;
} S_004C8C10;
extern void *func_0011D380(void *, const void *, unsigned int);
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004DAB90(void *, u8 *, s32);

s32 func_L39_004C8C10(S_004C8C10 *s, s32 n, s32 max, s32 extend) {
    s32 i, off, newb;

    if (s->s3->left >= n) {
        if (extend) {
            s->packet_length += n;
        } else {
            s->packet = &s->s3->buf[s->s3->offset];
            s->packet_length = n;
        }
        s->s3->left -= n;
        s->s3->offset += n;
        return n;
    }

    if (!s->read_ahead) max = n;
    if (max > s->s3->len) max = s->s3->len;

    off = 0;
    if (s->s3->left != 0 || (s->packet_length != 0 && extend)) {
        newb = s->s3->left;
        if (extend) {
            off = s->packet_length;
            if (s->packet != s->s3->buf)
                func_0011D380(s->s3->buf, s->packet, newb + off);
        } else if (s->s3->offset != 0) {
            func_0011D380(s->s3->buf, &s->s3->buf[s->s3->offset], newb);
            s->s3->offset = 0;
        }
        s->s3->left = 0;
    } else {
        newb = 0;
    }

    s->packet = s->s3->buf;

    while (newb < n) {
        *func_0011A6E0() = 0;
        if (s->rbio != 0) {
            s->rwstate = 3;
            i = func_L39_004DAB90(s->rbio, &s->s3->buf[off + newb], max - newb);
        } else {
            func_L39_004BC6C8(0x14, 0x96, 0xD3, 0, 0);
            i = -1;
        }
        if (i <= 0) {
            s->s3->left += newb;
            return i;
        }
        newb += i;
    }

    if (newb > n) {
        s->s3->offset = n + off;
        s->s3->left = newb - n;
    } else {
        s->s3->offset = 0;
        s->s3->left = 0;
    }

    if (extend)
        s->packet_length += n;
    else
        s->packet_length += n;
    s->rwstate = 1;
    return n;
}
/* localdecomp:end func_L39_004C8C10 */

/* localdecomp:start func_L39_004C8E30 */
/* OpenSSL ssl3_get_record (s3_pkt.c), 0.9.6 layout */
typedef struct E_004C8E30 { s32 (*enc)(void *, s32); s32 (*mac)(void *, u8 *, s32); } E_004C8E30;
typedef struct M_004C8E30 { char pad[0x54]; E_004C8E30 *ssl3_enc; } M_004C8E30;
typedef struct R_004C8E30 { s32 type; u32 length; u32 off; u8 *data; u8 *input; } R_004C8E30;
typedef struct S3_004C8E30 { char pad[0x98]; u32 rbuf_len; char pad2[0x18]; R_004C8E30 rrec; } S3_004C8E30;
typedef struct S_004C8E30 {
    s32 version; char pad4[4]; M_004C8E30 *method; char pad0C[0x2C];
    s32 rstate; char pad3C[0xC]; u8 *packet; u32 packet_length; char pad50[4];
    S3_004C8E30 *s3; char pad58[0x10];
    u32 mac_size; s32 expand; s32 read_hash; char pad74[0x3C];
    void *session; char padB4[0x4C]; u64 options; s32 first_packet;
} S_004C8E30;
struct S_004C8C10;
extern s32 func_L39_004C8C10(struct S_004C8C10 *, s32, s32, s32);
extern s32 func_L39_004C22B0(void *, u32);
extern s32 func_0011D2EC(const void *, const void *, u32);

s32 func_L39_004C8E30(S_004C8E30 *s) {
    R_004C8E30 *rr;
    void *sess;
    u8 *p;
    u8 md[0x20];
    s16 version;
    s32 n, i, ret = -1, al, clear = 0;
    u32 extra;
    u32 mac_size;
    s32 ssl_major, ssl_minor;

    rr = &s->s3->rrec;
    sess = s->session;
    if (s->options & 0x20) extra = 0x4000; else extra = 0;
again:
    if (s->rstate != 0xF1 || s->packet_length < 5) {
        n = func_L39_004C8C10((struct S_004C8C10 *)s, 5, 0x4805, 0);
        if (n <= 0) return n;
        s->rstate = 0xF1;
        p = s->packet;
        rr->type = *(p++);
        ssl_major = *(p++);
        ssl_minor = *(p++);
        version = (ssl_major << 8) | ssl_minor;
        rr->length = (p[0] << 8) | p[1];
        if (s->first_packet) {
            s->first_packet = 0;
        } else if (version != s->version) {
            func_L39_004BC6C8(0x14, 0x8F, 0x10B, 0, 0);
            s->version = version;
            al = 0x46;
            goto f_err;
        }
        if ((version >> 8) != 3) {
            func_L39_004BC6C8(0x14, 0x8F, 0x10B, 0, 0);
            goto err;
        }
        if (rr->length > 0x4800 + extra) {
            al = 0x16;
            func_L39_004BC6C8(0x14, 0x8F, 0xC6, 0, 0);
            goto f_err;
        }
        if (rr->length > s->s3->rbuf_len - 5) {
            if (!func_L39_004C22B0(s, rr->length + 5)) {
                func_L39_004BC6C8(0x14, 0x8F, 0x21, 0, 0);
                al = 0x50;
                goto f_err;
            }
        }
        s->rstate = 0xF1;
    }
    if (s->rstate == 0xF1) {
        if (rr->length > s->packet_length - 5) {
            i = rr->length;
            n = func_L39_004C8C10((struct S_004C8C10 *)s, i, i, 1);
            if (n <= 0) return n;
        }
        s->rstate = 0xF0;
    }
    rr->input = s->packet + 5;
    s->rstate = 0xF0;
    if (rr->length > 0x4800 + extra) {
        al = 0x16;
        func_L39_004BC6C8(0x14, 0x8F, 0x96, 0, 0);
        goto f_err;
    }
    rr->data = rr->input;
    if (!s->method->ssl3_enc->enc(s, 0)) {
        al = 0x33;
        goto f_err;
    }
    if (sess == 0 || s->read_hash == 0 || s->expand == 0) clear = 1;
    if (!clear) {
        mac_size = s->mac_size;
        if (rr->length > 0x4400 + extra + mac_size) {
            al = 0x16;
            func_L39_004BC6C8(0x14, 0x8F, 0xCD, 0, 0);
            goto f_err;
        }
        if (rr->length < mac_size) {
            al = 0x32;
            func_L39_004BC6C8(0x14, 0x8F, 0xA0, 0, 0);
            goto f_err;
        }
        rr->length -= mac_size;
        i = s->method->ssl3_enc->mac(s, md, 0);
        if (func_0011D2EC(md, rr->data + rr->length, mac_size) != 0) {
            al = 0x14;
            func_L39_004BC6C8(0x14, 0x8F, 0x71, 0, 0);
            ret = -1;
            goto f_err;
        }
    }
    if (rr->length > 0x4000 + extra) {
        al = 0x16;
        func_L39_004BC6C8(0x14, 0x8F, 0x92, 0, 0);
        goto f_err;
    }
    rr->off = 0;
    s->packet_length = 0;
    if (rr->length == 0) goto again;
    return 1;
f_err:
    func_L39_004C9F50((void *)s, 2, al);
err:
    return ret;
}
/* localdecomp:end func_L39_004C8E30 */
