#include "common.h"

/* localdecomp:start func_L39_004C6100 */
typedef struct S_004C6100 {
    u8 pad[0xD4];
    s32 fD4;
    s32 fD8;
} S_004C6100;

extern void func_L39_004C6120(S_004C6100 *);

void func_L39_004C6100(S_004C6100 *s, s32 arg1) {
    if (s->fD4 == 0) {
        s->fD8 = arg1;
        s->fD4 = 3;
        func_L39_004C6120(s);
    }
}
/* localdecomp:end func_L39_004C6100 */

/* localdecomp:start func_L39_004C6120 */
typedef void (*Cb_004C6120)(void *, s32, s32, s32);
typedef struct S2_004C6120 {
    u8 pad0[0x80];
    Cb_004C6120 f80;
    s32 f84;
} S2_004C6120;
typedef struct S_004C6120 {
    u8 pad0[0x10];
    void *f10;
    u8 pad14[0x4];
    s32 f18;
    u8 pad1C[0xC4 - 0x1C];
    Cb_004C6120 fC4;
    s32 fC8;
    u8 padCC[0xD4 - 0xCC];
    s32 fD4;
    s32 fD8;
    S2_004C6120 *fDC;
    s32 fE0;
} S_004C6120;
extern s32 func_L39_004C59D8(void *, u8 *, s32);
extern long func_L39_004DAE48(void *, s32, long, void *);

void func_L39_004C6120(S_004C6100 *arg0) {
    S_004C6120 *s = (S_004C6120 *)arg0;
    u8 buf[3];
    u8 *p;
    s32 len;
    s32 r;
    Cb_004C6120 fn = 0;
    s32 arg = 0;

    len = s->fD4;
    s->fD4 = 0;
    p = buf;
    *p++ = 0;
    *p++ = s->fD8 >> 8;
    *p++ = s->fD8;
    r = func_L39_004C59D8(s, p - len, len);
    if (r < 0) {
        s->fD4 = len;
        return;
    }
    if (r == s->fD4) {
        return;
    }
    s->fD4 = len - r;
    if (s->fE0 != 0) {
        s->f18 = 2;
        func_L39_004DAE48(s->f10, 0xB, 0, 0);
        s->f18 = 1;
    }
    if (s->fC4 != 0) {
        fn = s->fC4;
        arg = s->fC8;
    } else if (s->fDC->f80 != 0) {
        fn = s->fDC->f80;
        arg = s->fDC->f84;
    }
    if (fn != 0) {
        fn(s, 0x4008, s->fD8, arg);
    }
}
/* localdecomp:end func_L39_004C6120 */

/* localdecomp:start func_L39_004C6220 */
extern void *func_L39_004C6250(void);

void *func_L39_004C6220(s32 id) {
    void *r;
    if (id == 0x300) {
        r = func_L39_004C6250();
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_004C6220 */

INCLUDE_ASM("asm/levels", func_L39_004C6250);

/* localdecomp:start func_L39_004C63A8 */
/* OpenSSL ssl3_connect (s3_clnt.c), DNAS variant */
typedef void (*Cb_004C63A8)(void *, s32, s32);
typedef struct {
    u8 pad0[0x10];
    s64 algorithms;
} CIPHER_004C63A8;
typedef struct {
    s64 flags;
    s32 delay_buf_pop_ret;
    u8 padC[0x100 - 0xC];
    s32 change_cipher_spec;
    u8 pad104[0x15C - 0x104];
    CIPHER_004C63A8 *new_cipher;
    u8 pad160[0x4];
    s32 next_state;
    s32 reuse_message;
    s32 cert_req;
} S3_004C63A8;
typedef struct {
    u8 pad0[0x8];
    s32 (*setup_key_block)(void *);
    u8 padC[0x4];
    s32 (*change_cipher_state)(void *, s32);
    u8 pad14[0xC];
    char client_finished_label[0x14];
    s32 client_finished_label_len;
} ENC_004C63A8;
typedef struct {
    u8 pad0[0x54];
    ENC_004C63A8 *ssl3_enc;
} METHOD_004C63A8;
typedef struct {
    u8 pad0[0xAC];
    CIPHER_004C63A8 *cipher;
} SESS_004C63A8;
typedef struct {
    u8 pad0[0x4C];
    s32 sess_connect;
    s32 sess_connect_renegotiate;
    s32 sess_connect_good;
    u8 pad58[0x70 - 0x58];
    s32 sess_hit;
    u8 pad74[0x7C - 0x74];
    Cb_004C63A8 info_callback;
} CTX_004C63A8;
typedef struct {
    s32 version;
    s32 type;
    METHOD_004C63A8 *method;
    void *rbio;
    void *wbio;
    void *bbio;
    s32 rwstate;
    s32 in_handshake;
    void *handshake_func;
    s32 server;
    s32 new_session;
    s32 shutdown;
    s32 state;
    s32 prev_state;
    u8 pad38[0x4];
    void *init_buf;
    s32 init_num;
    u8 pad44[0x10];
    S3_004C63A8 *s3;
    u8 pad58[0x4];
    s32 hit;
    u8 pad60[0xB0 - 0x60];
    SESS_004C63A8 *session;
    u8 padB4[0xC];
    Cb_004C63A8 info_callback;
    u8 padC4[0xDC - 0xC4];
    CTX_004C63A8 *ctx;
    s32 nbio;
    u8 padE4[0x100 - 0xE4];
    s64 options;
} SSL_004C63A8;

extern s32 func_L39_004E5090(void);
extern void func_L39_004E5058(s32, s32);
extern void func_L39_004DE0C8(void);
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004C6BA0(SSL_004C63A8 *);
extern void *func_L39_004DAF40(void *, void *);
extern s32 func_L39_004C70F8(SSL_004C63A8 *);
extern s32 func_L39_004C7CD0(SSL_004C63A8 *);
extern s32 func_L39_004C8748(SSL_004C63A8 *);
extern s32 func_L39_004C8568(SSL_004C63A8 *);
extern s32 func_L39_004EAED8(SSL_004C63A8 *, s32, s32, char *, s32);
extern void *func_L39_004DB110(void);
extern s32 func_L39_004DB1C0(void *, s32);
extern s32 func_L39_004C21E0(SSL_004C63A8 *);
extern s32 func_L39_004C4D48(SSL_004C63A8 *, s32);
extern s32 func_L39_004C23A0(SSL_004C63A8 *);
extern s32 func_L39_004C6E08(SSL_004C63A8 *);
extern s32 func_L39_004C74F8(SSL_004C63A8 *);
extern s32 func_L39_004C8950(SSL_004C63A8 *);
extern s32 func_L39_004C8088(SSL_004C63A8 *);
extern s32 func_L39_004C8110(SSL_004C63A8 *);
extern s32 func_L39_004EB0B0(SSL_004C63A8 *, s32, s32);
extern s32 func_L39_004EAFA8(SSL_004C63A8 *, s32, s32);
extern long func_L39_004DAE48(void *, s32, long, void *);
extern void func_L39_004EBF88(SSL_004C63A8 *);
extern void func_L39_004DB168(void *);
extern void func_L39_004C4E68(SSL_004C63A8 *);
extern void func_L39_004C47F8(SSL_004C63A8 *, s32);
extern s32 func_L39_004C3CC0();
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004BB460(void *);

s32 func_L39_004C63A8(SSL_004C63A8 *s) {
    void *buf;
    long num1;
    Cb_004C63A8 cb;
    s32 ret = -1;
    s32 new_state, state, skip = 0;

    func_L39_004E5058(func_L39_004E5090(), 2);
    func_L39_004DE0C8();
    *func_0011A6E0() = 0;

    if (s->info_callback != 0) {
        cb = s->info_callback;
    } else {
        cb = s->ctx->info_callback;
    }

    s->in_handshake++;

    for (;;) {
        state = s->state;

        switch (s->state) {
        case 0x3004:
            s->new_session = 1;
            s->state = 0x1000;
            s->ctx->sess_connect_renegotiate++;
        case 0x4000:
        case 0x1000:
        case 0x5000:
        case 0x1003:
            s->server = 0;
            if (cb != 0) {
                cb(s, 0x10, 1);
            }
            s->type = 0x1000;
            if (s->init_buf == 0) {
                if ((buf = func_L39_004DB110()) == 0) {
                    ret = -1;
                    goto end;
                }
                if (!func_L39_004DB1C0(buf, 0x800)) {
                    ret = -1;
                    goto end;
                }
                s->init_buf = buf;
            }
            if (!func_L39_004C21E0(s)) {
                ret = -1;
                goto end;
            }
            if (!func_L39_004C4D48(s, 0)) {
                ret = -1;
                goto end;
            }
            if (!func_L39_004C23A0(s)) {
                ret = -1;
                goto end;
            }
            s->state = 0x1110;
            s->ctx->sess_connect++;
            s->init_num = 0;
            break;

        case 0x1110:
        case 0x1111:
            s->shutdown = 0;
            ret = func_L39_004C6BA0(s);
            if (ret <= 0) {
                goto end;
            }
            s->state = 0x1120;
            s->init_num = 0;
            if (s->bbio != s->wbio) {
                s->wbio = func_L39_004DAF40(s->bbio, s->wbio);
            }
            break;

        case 0x1120:
        case 0x1121:
            ret = func_L39_004C6E08(s);
            if (ret <= 0) {
                goto end;
            }
            if (s->hit) {
                s->state = 0x11D0;
            } else {
                s->state = 0x1130;
            }
            s->init_num = 0;
            break;

        case 0x1130:
        case 0x1131:
            if (!(s->s3->new_cipher->algorithms & 0x100)) {
                ret = func_L39_004C70F8(s);
                if (ret <= 0) {
                    goto end;
                }
            } else {
                skip = 1;
            }
            s->state = 0x1140;
            s->init_num = 0;
            break;

        case 0x1140:
        case 0x1141:
            ret = func_L39_004C74F8(s);
            if (ret <= 0) {
                goto end;
            }
            s->state = 0x1150;
            s->init_num = 0;
            if (!func_L39_004C8950(s)) {
                ret = -1;
                goto end;
            }
            break;

        case 0x1150:
        case 0x1151:
            ret = func_L39_004C7CD0(s);
            if (ret <= 0) {
                goto end;
            }
            s->state = 0x1160;
            s->init_num = 0;
            break;

        case 0x1160:
        case 0x1161:
            ret = func_L39_004C8088(s);
            if (ret <= 0) {
                goto end;
            }
            if (s->s3->cert_req) {
                s->state = 0x1170;
            } else {
                s->state = 0x1180;
            }
            s->init_num = 0;
            break;

        case 0x1170:
        case 0x1171:
        case 0x1172:
            ret = func_L39_004C8748(s);
            if (ret <= 0) {
                goto end;
            }
            s->state = 0x1180;
            s->init_num = 0;
            break;

        case 0x1180:
        case 0x1181:
            ret = func_L39_004C8110(s);
            if (ret <= 0) {
                goto end;
            }
            if (s->s3->cert_req == 1) {
                s->state = 0x1190;
            } else {
                s->state = 0x11A0;
                s->s3->change_cipher_spec = 0;
            }
            s->init_num = 0;
            break;

        case 0x1190:
        case 0x1191:
            ret = func_L39_004C8568(s);
            if (ret <= 0) {
                goto end;
            }
            s->state = 0x11A0;
            s->init_num = 0;
            s->s3->change_cipher_spec = 0;
            break;

        case 0x11A0:
        case 0x11A1:
            ret = func_L39_004EB0B0(s, 0x11A0, 0x11A1);
            if (ret <= 0) {
                goto end;
            }
            s->state = 0x11B0;
            s->init_num = 0;
            s->session->cipher = s->s3->new_cipher;
            if (!s->method->ssl3_enc->setup_key_block(s)) {
                ret = -1;
                goto end;
            }
            if (!s->method->ssl3_enc->change_cipher_state(s, 0x12)) {
                ret = -1;
                goto end;
            }
            break;

        case 0x11B0:
        case 0x11B1:
            ret = func_L39_004EAED8(s, 0x11B0, 0x11B1,
                                    s->method->ssl3_enc->client_finished_label,
                                    s->method->ssl3_enc->client_finished_label_len);
            if (ret <= 0) {
                goto end;
            }
            if (!s->nbio) {
                s->state = 0x1100;
            }
            s->s3->flags &= ~4;
            if (s->hit) {
                if (!s->nbio) {
                    s->s3->next_state = 3;
                } else {
                    s->state = 3;
                }
                if (s->options & 0x400000) {
                    s->state = 3;
                    s->s3->flags |= 4;
                    s->s3->delay_buf_pop_ret = 0;
                }
            } else {
                if (!s->nbio) {
                    s->s3->next_state = 0x11D0;
                } else {
                    s->state = 0x11D0;
                }
                if (s->options & 0x800000) {
                    s->state = 3;
                    s->s3->flags |= 0x14;
                    s->s3->delay_buf_pop_ret = 0;
                }
            }
            s->init_num = 0;
            break;

        case 0x11D0:
        case 0x11D1:
            ret = func_L39_004EAFA8(s, 0x11D0, 0x11D1);
            if (ret <= 0) {
                goto end;
            }
            if (s->hit) {
                s->state = 0x11A0;
            } else {
                s->state = 3;
            }
            s->init_num = 0;
            break;

        case 0x1100:
            num1 = func_L39_004DAE48(s->wbio, 3, 0, 0);
            if (num1 > 0) {
                s->rwstate = 2;
                num1 = (s32)func_L39_004DAE48(s->wbio, 0xB, 0, 0);
                if (num1 <= 0) {
                    ret = -1;
                    goto end;
                }
                s->rwstate = 1;
            }
            if (s->nbio) {
                state = s->prev_state;
            }
            s->state = s->s3->next_state;
            break;

        case 3:
            if (!(s->s3->flags & 0x10)) {
                func_L39_004EBF88(s);
                if (s->init_buf != 0) {
                    func_L39_004DB168(s->init_buf);
                    s->init_buf = 0;
                }
                if (!(s->s3->flags & 4)) {
                    func_L39_004C4E68(s);
                }
                s->init_num = 0;
                s->new_session = 0;
                func_L39_004C47F8(s, 1);
                if (s->hit) {
                    s->ctx->sess_hit++;
                }
                s->ctx->sess_connect_good++;
            }
            ret = 1;
            s->handshake_func = func_L39_004C3CC0;
            if (cb != 0) {
                cb(s, 0x20, 1);
            }
            goto end;

        default:
            func_L39_004BC6C8(0x14, 0x84, 0xFF, 0, 0);
            ret = -1;
            goto end;
        }

        if (!s->s3->reuse_message && !skip) {
            if (s->nbio) {
                s->rwstate = 2;
                ret = (s32)func_L39_004DAE48(s->wbio, 0xB, 0, 0);
                if (ret <= 0) {
                    if (func_L39_004BB460(s->wbio)) {
                        s->s3->next_state = s->state;
                        s->prev_state = state;
                        s->state = 0x1100;
                    }
                    goto end;
                }
                s->rwstate = 1;
            }
            if (cb != 0 && s->state != state) {
                new_state = s->state;
                s->state = state;
                cb(s, 0x1001, 1);
                s->state = new_state;
            }
        }
        skip = 0;
    }
end:
    if (cb != 0) {
        cb(s, 0x1002, ret);
    }
    s->in_handshake--;
    return ret;
}
/* localdecomp:end func_L39_004C63A8 */
