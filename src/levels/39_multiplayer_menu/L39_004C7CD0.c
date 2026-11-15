#include "common.h"

/* declared by functions of L39_004C6BA0.c, which this file was cut from */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern long func_L39_004EB540(void *, s32, s32, s32, long, s32 *);
extern void func_L39_004C9F50(void *, s32, s32);
extern void *func_L39_004CC228(s32);
extern s32 func_L39_004CC3E0(void *, void *);
extern void func_L39_004CC510(void *, void (*)(void *));

/* localdecomp:start func_L39_004C7CD0 */
/* OpenSSL ssl3_get_certificate_request (s3_clnt.c) */
typedef struct {
    u8 pad0[0x10];
    unsigned long algorithms;
} CIPH_004C7CD0;

typedef struct {
    u8 pad0[0x158];
    s32 message_type;
    CIPH_004C7CD0 *new_cipher;
    u8 pad160[8];
    s32 reuse_message;
    s32 cert_req;
    s32 ctype_num;
    u8 ctype[8];
    void *ca_names;
} S3_004C7CD0;

typedef struct {
    s32 length;
    u8 *data;
} BUF_004C7CD0;

typedef struct {
    s32 version;
    u8 pad4[0x38];
    BUF_004C7CD0 *init_buf;
    u8 pad40[0x14];
    S3_004C7CD0 *s3;
    u8 pad58[0x100 - 0x58];
    unsigned long options;
    u8 pad108[0x120 - 0x108];
    long max_cert_list;
} SSL_004C7CD0;

extern s32 func_L39_004C8068(void **, void **);
extern void *func_L39_004BBEB8(void *, u8 **, long);
extern void func_L39_004BBE28(void *);
extern void func_L39_004DE0C8(void);

s32 func_L39_004C7CD0(SSL_004C7CD0 *s) {
    s32 ok;
    s32 ret;
    unsigned long n, nc, l;
    u32 llen, ctype_num, i;
    void *xn;
    u8 *p, *d, *q;
    void *ca_sk;

    ret = 0;
    ca_sk = 0;
    l = 0x19000;
    if (s->max_cert_list) {
        l = s->max_cert_list;
    }
    n = func_L39_004EB540(s, 0x1150, 0x1151, -1, l, &ok);
    if (!ok) {
        return (s32)n;
    }

    s->s3->cert_req = 0;

    if (s->s3->message_type == 0xE) {
        s->s3->reuse_message = 1;
        return 1;
    }

    if (s->s3->message_type != 0xD) {
        func_L39_004C9F50(s, 2, 10);
        func_L39_004BC6C8(20, 135, 262, 0, 0);
        goto err;
    }

    if (s->version > 0x300) {
        l = s->s3->new_cipher->algorithms;
        if (l & 0x100) {
            func_L39_004C9F50(s, 2, 10);
            func_L39_004BC6C8(20, 135, 232, 0, 0);
            goto err;
        }
    }

    d = p = s->init_buf->data;

    if ((ca_sk = func_L39_004CC228((s32)func_L39_004C8068)) == 0) {
        func_L39_004BC6C8(20, 135, 33, 0, 0);
        goto err;
    }

    ctype_num = *(p++);
    if (ctype_num > 7) {
        ctype_num = 7;
    }
    for (i = 0; i < ctype_num; i++) {
        s->s3->ctype[i] = p[i];
    }
    p += ctype_num;

    llen = (p[0] << 8) | p[1];
    p += 2;

    if ((llen + ctype_num + 2 + 1) != n) {
        func_L39_004C9F50(s, 2, 50);
        func_L39_004BC6C8(20, 135, 159, 0, 0);
        goto err;
    }

    for (nc = 0; nc < llen;) {
        l = (((u32)p[0]) << 8) | ((u32)p[1]);
        p += 2;
        if ((l + nc + 2) > llen) {
            if (s->options & 0x20000000) {
                goto cont;
            }
            func_L39_004C9F50(s, 2, 50);
            func_L39_004BC6C8(20, 135, 132, 0, 0);
            goto err;
        }

        q = p;

        if ((xn = func_L39_004BBEB8(0, &q, l)) == 0) {
            if (s->options & 0x20000000) {
                goto cont;
            } else {
                func_L39_004C9F50(s, 2, 50);
                func_L39_004BC6C8(20, 135, 0x80D, 0, 0);
                goto err;
            }
        }

        if (q != (p + l)) {
            func_L39_004C9F50(s, 2, 50);
            func_L39_004BC6C8(20, 135, 131, 0, 0);
            goto err;
        }
        if (!func_L39_004CC3E0(ca_sk, xn)) {
            func_L39_004BC6C8(20, 135, 33, 0, 0);
            goto err;
        }

        p += l;
        nc += l + 2;
    }

    if (0) {
cont:
        func_L39_004DE0C8();
    }

    s->s3->cert_req = 1;
    s->s3->ctype_num = ctype_num;
    if (s->s3->ca_names != 0) {
        func_L39_004CC510(s->s3->ca_names, func_L39_004BBE28);
    }
    s->s3->ca_names = ca_sk;
    ca_sk = 0;

    ret = 1;
err:
    if (ca_sk != 0) {
        func_L39_004CC510(ca_sk, func_L39_004BBE28);
    }
    return ret;
}
/* localdecomp:end func_L39_004C7CD0 */
