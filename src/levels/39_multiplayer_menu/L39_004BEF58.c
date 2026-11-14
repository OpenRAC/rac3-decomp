#include "common.h"

/* localdecomp:start func_L39_004BEF58 */
/* OpenSSL's ssl23 get-method by version: SSL2_VERSION, SSL3_VERSION, TLS1_VERSION */
extern void *func_L39_004BFF90(void);
extern void *func_L39_004C6250(void);
extern void *func_L39_004CC5B8(void);

void *func_L39_004BEF58(s32 ver) {
    if (ver == 2) {
        return func_L39_004BFF90();
    } else if (ver == 0x300) {
        return func_L39_004C6250();
    } else if (ver == 0x301) {
        return func_L39_004CC5B8();
    } else {
        return 0;
    }
}
/* localdecomp:end func_L39_004BEF58 */

/* localdecomp:start func_L39_004BEFB8 */
typedef struct S_004BEFB8 {
    s32 version;
    void *f04[4];
    s32 (*ssl_connect)();
    void *f18[13];
    void *(*get_ssl_method)();
    void *f50[3];
} S_004BEFB8;

extern s32 D_L39_004648B0 __attribute__((section(".data")));
extern S_004BEFB8 D_L39_00443630;
extern S_004BEFB8 *func_L39_004BFB18(void);
extern s32 func_L39_004BF110();
extern void *func_L39_004BEF58();

/* OpenSSL's SSLv23_client_method */
S_004BEFB8 *func_L39_004BEFB8(void) {
    if (D_L39_004648B0) {
        D_L39_004648B0 = 0;
        D_L39_00443630 = *func_L39_004BFB18();
        D_L39_00443630.ssl_connect = func_L39_004BF110;
        D_L39_00443630.get_ssl_method = func_L39_004BEF58;
    }
    return &D_L39_00443630;
}
/* localdecomp:end func_L39_004BEFB8 */

/* localdecomp:start func_L39_004BF110 */
typedef struct S_004BF110_ctx {
    u8 pad0[0x4C];
    s32 sess_connect;
    u8 pad50[0x7C - 0x50];
    void (*info_callback)();
} S_004BF110_ctx;

typedef struct S_004BF110 {
    u8 pad0[0x4];
    s32 type;
    u8 pad8[0x10 - 0x8];
    void *wbio;
    u8 pad14[0x1C - 0x14];
    s32 in_handshake;
    u8 pad20[0x24 - 0x20];
    s32 server;
    u8 pad28[0x2C - 0x28];
    s32 shutdown;
    s32 state;
    u8 pad34[0x3C - 0x34];
    void *init_buf;
    s32 init_num;
    u8 pad44[0xB0 - 0x44];
    void *session;
    u8 padB4[0xC0 - 0xB4];
    void (*info_callback)();
    u8 padC4[0xDC - 0xC4];
    S_004BF110_ctx *ctx;
    s32 debug;
} S_004BF110;

extern s32 func_L39_004E5090(void);
extern void func_L39_004E5058(s32, s32);
extern void func_L39_004DE0C8(void);
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004C4EE0(S_004BF110 *);
extern void func_L39_004C3688(S_004BF110 *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004DB110(void);
extern s32 func_L39_004DB1C0(void *, s32);
extern s32 func_L39_004C21E0(S_004BF110 *);
extern s32 func_L39_004C23A0(S_004BF110 *);
extern s32 func_L39_004BF3A0(S_004BF110 *);
extern s32 func_L39_004BF630(S_004BF110 *);
extern s32 func_L39_004DAE48(void *, s32, s32, s32);

/* OpenSSL's ssl23_connect */
s32 func_L39_004BF110(S_004BF110 *s) {
    void *buf;
    void (*cb)() = 0;
    s32 ret = -1;
    s32 new_state, state;

    func_L39_004E5058(func_L39_004E5090(), 2);
    func_L39_004DE0C8();
    *func_0011A6E0() = 0;

    if (s->info_callback != 0) {
        cb = s->info_callback;
    } else if (s->ctx->info_callback != 0) {
        cb = s->ctx->info_callback;
    }

    if (!(func_L39_004C4EE0(s) & 0x3000) || (func_L39_004C4EE0(s) & 0x4000)) {
        func_L39_004C3688(s);
    }
    s->in_handshake++;

    for (;;) {
        state = s->state;

        switch (s->state) {
        case 0x4000:
        case 0x1000:
        case 0x5000:
        case 0x1003:
            if (s->session != 0) {
                func_L39_004BC6C8(0x14, 0x75, 0xDD, 0, 0);
                ret = -1;
                goto end;
            }
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
            if (!func_L39_004C23A0(s)) {
                ret = -1;
                goto end;
            }
            s->state = 0x1210;
            s->ctx->sess_connect++;
            s->init_num = 0;
            break;

        case 0x1210:
        case 0x1211:
            s->shutdown = 0;
            ret = func_L39_004BF3A0(s);
            if (ret <= 0) {
                goto end;
            }
            s->state = 0x1220;
            s->init_num = 0;
            break;

        case 0x1220:
        case 0x1221:
            ret = func_L39_004BF630(s);
            if (ret >= 0) {
                cb = 0;
            }
            goto end;

        default:
            func_L39_004BC6C8(0x14, 0x75, 0xFF, 0, 0);
            ret = -1;
            goto end;
        }

        if (s->debug) {
            func_L39_004DAE48(s->wbio, 0xB, 0, 0);
        }

        if (cb != 0 && s->state != state) {
            new_state = s->state;
            s->state = state;
            cb(s, 0x1001, 1);
            s->state = new_state;
        }
    }
end:
    s->in_handshake--;
    if (cb != 0) {
        cb(s, 0x1002, ret);
    }
    return ret;
}
/* localdecomp:end func_L39_004BF110 */
