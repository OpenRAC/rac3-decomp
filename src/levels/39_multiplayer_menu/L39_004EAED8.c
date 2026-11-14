#include "common.h"

/* localdecomp:start func_L39_004EAED8 */
/* log: v1 ssl3_send_finished shape */
typedef struct {
    u8 _p0[0x14];
    s32 (*final_finish_mac)(void *, s32, s32, s32, s32, u8 *);
} ENC_004EAED8;

typedef struct {
    u8 _p0[0x54];
    ENC_004EAED8 *ssl3_enc;
} METH_004EAED8;

typedef struct {
    u8 _p0[0xF8];
    s32 finish_dgst1;
    s32 finish_dgst2;
} S3_004EAED8;

typedef struct {
    s32 length;
    u8 *data;
} BUF_004EAED8;

typedef struct {
    u8 _p0[8];
    METH_004EAED8 *method;
    u8 _pC[0x30 - 0xC];
    s32 state;
    u8 _p34[0x3C - 0x34];
    BUF_004EAED8 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 _p48[0x54 - 0x48];
    S3_004EAED8 *s3;
} SSL_004EAED8;

extern s32 func_L39_004CA180(void *, s32);

s32 func_L39_004EAED8(SSL_004EAED8 *s, s32 a, s32 b, s32 sender, s32 slen) {
    u8 *p, *d;
    s32 i;
    unsigned long l;

    if (s->state == a) {
        d = s->init_buf->data;
        p = &d[4];

        i = s->method->ssl3_enc->final_finish_mac(s, s->s3->finish_dgst1, s->s3->finish_dgst2, sender, slen, p);
        if (i == 0) {
            return -1;
        }
        l = i;
        *(d++) = 0x14;
        d[0] = (u8)((l >> 16) & 0xff);
        d[1] = (u8)((l >> 8) & 0xff);
        d[2] = (u8)(l & 0xff);
        s->init_num = (s32)l + 4;
        s->init_off = 0;
        s->state = b;
    }
    return func_L39_004CA180(s, 0x16);
}
/* localdecomp:end func_L39_004EAED8 */

/* localdecomp:start func_L39_004EAFA8 */
/* log: v1 ssl3_get_finished shape */
typedef struct {
    u8 _p0[0x18];
    s32 finish_mac_length;
} ENC_004EAFA8;

typedef struct {
    u8 _p0[0x54];
    ENC_004EAFA8 *ssl3_enc;
} METH_004EAFA8;

typedef struct {
    u8 _p0[0x100];
    s32 change_cipher_spec;
    u8 _p104[0x128 - 0x104];
    u8 finish_md[1];
} S3_004EAFA8;

typedef struct {
    s32 length;
    u8 *data;
} BUF_004EAFA8;

typedef struct {
    u8 _p0[8];
    METH_004EAFA8 *method;
    u8 _pC[0x3C - 0xC];
    BUF_004EAFA8 *init_buf;
    u8 _p40[0x54 - 0x40];
    S3_004EAFA8 *s3;
} SSL_004EAFA8;

extern long func_L39_004EB540(void *, s32, s32, s32, long, s32 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_0011D2EC(void *, void *, s32);
extern void func_L39_004C9F50(void *, s32, s32);

s32 func_L39_004EAFA8(SSL_004EAFA8 *s, s32 a, s32 b) {
    s32 al, i, ok;
    long n;
    u8 *p;

    n = func_L39_004EB540(s, a, b, 0x14, 0x40, &ok);
    if (!ok) {
        return (s32)n;
    }

    if (!s->s3->change_cipher_spec) {
        al = 10;
        func_L39_004BC6C8(20, 140, 154, 0, 0);
        goto f_err;
    }
    s->s3->change_cipher_spec = 0;

    p = s->init_buf->data;
    i = s->method->ssl3_enc->finish_mac_length;

    if (i != n) {
        al = 50;
        func_L39_004BC6C8(20, 140, 111, 0, 0);
        goto f_err;
    }

    if (func_0011D2EC(p, s->s3->finish_md, i) != 0) {
        al = 51;
        func_L39_004BC6C8(20, 140, 149, 0, 0);
        goto f_err;
    }

    return 1;
f_err:
    func_L39_004C9F50(s, 2, al);
    return -1;
}
/* localdecomp:end func_L39_004EAFA8 */
