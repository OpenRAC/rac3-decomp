#include "common.h"

/* localdecomp:start func_L39_004BF3A0 */
typedef struct C_004BF3A0 {
    s32 pad0;
    u8 *buf;
} C_004BF3A0;
typedef struct D_004BF3A0 {
    u8 pad0[0x80];
    s32 (*cb)(void *, s32, s32, s32);
    s32 arg;
} D_004BF3A0;
typedef struct R_004BF3A0 {
    u8 pad0[0x64];
    u8 client_random[32];
} R_004BF3A0;
typedef struct S_004BF3A0 {
    u8 pad0[0x30];
    s32 state;
    u8 pad34[0x3C - 0x34];
    C_004BF3A0 *c;
    s32 f40;
    s32 f44;
    u8 pad48[0x54 - 0x48];
    R_004BF3A0 *f54;
    u8 pad58[0xC4 - 0x58];
    s32 (*cb)(void *, s32, s32, s32);
    s32 arg;
    u8 padCC[0xDC - 0xCC];
    D_004BF3A0 *fDC;
    u8 padE0[0x100 - 0xE0];
    unsigned long flags;
    u8 pad108[0x10C - 0x108];
    s32 f10C;
} S_004BF3A0;
extern s32 func_L39_004E5090(void);
extern s32 func_L39_004E4FC8(s32, u8 *, s32);
extern s32 func_L39_004C4168(S_004BF3A0 *);
extern s32 func_L39_004C41D0(S_004BF3A0 *, s32, u8 *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004C23F8(S_004BF3A0 *, u8 *, s32);
extern s32 func_L39_004BFE20(S_004BF3A0 *);
extern void func_11D534(void *, s32, s32);
extern void *func_11D380(void *, void *, s32);

s32 func_L39_004BF3A0(S_004BF3A0 *s) {
    s32 (*cb)(void *, s32, s32, s32) = 0;
    s32 arg = 0;
    u8 *buf;
    u8 *p;
    u8 *d;
    s32 i;
    s32 ch;

    if (s->cb) {
        cb = s->cb;
        arg = s->arg;
    } else if (s->fDC->cb) {
        cb = s->fDC->cb;
        arg = s->fDC->arg;
    }
    buf = s->c->buf;
    if (s->state == 0x1210) {
        p = s->f54->client_random;
        func_L39_004E4FC8(func_L39_004E5090(), p, 0x20);
        d = buf + 2;
        p = buf + 11;
        *(d++) = 1;
        if ((s->flags & 0x4000000) == 0) {
            *(d++) = 3;
            *(d++) = 1;
            s->f10C = 0x301;
        } else if ((s->flags & 0x2000000) == 0) {
            *(d++) = 3;
            *(d++) = 0;
            s->f10C = 0x300;
        } else if ((s->flags & 0x1000000) == 0) {
            *(d++) = 0;
            *(d++) = 2;
            s->f10C = 2;
        } else {
            if (cb) {
                cb(s, 0x4008, 0, arg);
            }
            func_L39_004BC6C8(0x14, 0x74, 0xBF, 0, 0);
            return -1;
        }
        i = func_L39_004C41D0(s, func_L39_004C4168(s), p);
        if (i == 0) {
            if (cb) {
                cb(s, 0x4004, 1, arg);
            }
            func_L39_004BC6C8(0x14, 0x74, 0xB5, 0, 0);
            return -1;
        }
        d[1] = i;
        d[0] = i >> 8;
        d += 2;
        p += i;
        d[0] = 0;
        d[1] = 0;
        d += 2;
        if (s->flags & 2) {
            ch = 16;
        } else {
            ch = 32;
        }
        if (32 < ch) {
            i = 32;
        } else {
            i = ch;
        }
        d[1] = i;
        d[0] = 0;
        d += 2;
        func_11D534(s->f54->client_random, 0, 0x20);
        func_L39_004E4FC8(func_L39_004E5090(), &s->f54->client_random[32 - i], i);
        func_11D380(p, &s->f54->client_random[32 - i], i);
        p += i;
        i = p - (buf + 2);
        buf[1] = i;
        buf[0] = (i >> 8) | 0x80;
        s->state = 0x1211;
        s->f40 = i + 2;
        s->f44 = 0;
        func_L39_004C23F8(s, buf + 2, i);
    }
    return func_L39_004BFE20(s);
}
/* localdecomp:end func_L39_004BF3A0 */

/* localdecomp:start func_L39_004BF630 */
/* OpenSSL's ssl23_get_server_hello (s23_clnt.c) */
typedef struct S2_004BF630 {
    u8 pad0[0xC];
    s32 ssl2_rollback;
    u8 pad10[0x28 - 0x10];
    s32 rbuf_left;
    s32 rbuf_offs;
    u8 *rbuf;
    u8 pad34[0x6C - 0x34];
    s32 challenge_length;
    u8 challenge[32];
    u8 pad90[0xE0 - 0x90];
    unsigned long write_sequence;
} S2_004BF630;
typedef struct S3_004BF630 {
    u8 pad0[0x64];
    u8 client_random[32];
    u8 pad84[0x8C - 0x84];
    s32 rbuf_left;
    s32 rbuf_offset;
    u8 *rbuf_buf;
} S3_004BF630;
typedef struct X_004BF630 {
    u8 pad0[0x7C];
    void (*info_callback)(void *, s32, s32);
    s32 (*cb)(void *, s32, s32, s32);
    s32 arg;
} X_004BF630;
typedef struct S_004BF630 {
    s32 version;
    u8 pad4[0x8 - 0x4];
    void *method;
    u8 padC[0x18 - 0xC];
    s32 rwstate;
    s32 in_handshake;
    s32 (*handshake_func)(void *);
    u8 pad24[0x30 - 0x24];
    s32 state;
    u8 pad34[0x38 - 0x34];
    s32 rstate;
    void *init_buf;
    s32 init_num;
    u8 pad44[0x48 - 0x44];
    u8 *packet;
    s32 packet_length;
    S2_004BF630 *s2;
    S3_004BF630 *s3;
    u8 pad58[0xC0 - 0x58];
    void (*info_callback)(void *, s32, s32);
    s32 (*cb)(void *, s32, s32, s32);
    s32 arg;
    u8 padCC[0xDC - 0xCC];
    X_004BF630 *ctx;
    u8 padE0[0x100 - 0xE0];
    unsigned long options;
    s32 first_packet;
} S_004BF630;
extern s32 func_L39_004BFEC8(S_004BF630 *, s32);
extern s32 func_L39_004C1C60(S_004BF630 *);
extern void func_L39_004C1D38(S_004BF630 *);
extern void func_L39_004C2588(S_004BF630 *);
extern s32 func_L39_004DB1C0(void *, s32);
extern s32 func_L39_004C2068(void *);
extern int func_L39_004C2118(void *, int);
extern void *func_L39_004BFF90(void);
extern s32 func_L39_004C3CC0(void *);
extern s32 func_L39_004C4D48(S_004BF630 *, s32);
extern void *func_L39_004C6250(void);
extern void *func_L39_004CC5B8(void);
extern s32 func_L39_004CB730(S_004BF630 *, s32);

s32 func_L39_004BF630(S_004BF630 *s) {
    u8 buf[8];
    u8 *p;
    s32 i;
    s32 n;
    s32 ch_len;
    s32 (*cb)(void *, s32, s32, s32) = 0;
    s32 arg = 0;

    if (s->cb) {
        cb = s->cb;
        arg = s->arg;
    } else if (s->ctx->cb) {
        cb = s->ctx->cb;
        arg = s->ctx->arg;
    }
    n = func_L39_004BFEC8(s, 7);
    if (n != 7) {
        return n;
    }
    p = s->packet;
    func_11D380(buf, p, n);

    if ((p[0] & 0x80) && p[2] == 4 && p[5] == 0 && p[6] == 2) {
        if (s->options & 0x1000000) {
            if (cb) {
                cb(s, 0x4004, 0, arg);
            }
            func_L39_004BC6C8(0x14, 0x77, 0x102, 0, 0);
            goto err;
        }
        if (s->s2 == 0) {
            if (!func_L39_004C1C60(s)) {
                goto err;
            }
        } else {
            func_L39_004C1D38(s);
        }
        if (s->options & 2) {
            ch_len = 16;
        } else {
            ch_len = 32;
        }
        i = (32 < ch_len) ? 32 : ch_len;
        s->s2->challenge_length = i;
        func_11D380(s->s2->challenge, &s->s3->client_random[32 - i], i);
        if (s->s3 != 0) {
            func_L39_004C2588(s);
        }
        if (!func_L39_004DB1C0(s->init_buf, 0x800)) {
            if (cb) {
                cb(s, 0x4004, 0, arg);
            }
            func_L39_004BC6C8(0x14, 0x77, 0x807, 0, 0);
            goto err;
        }
        s->state = 0x1020;
        s->s2->ssl2_rollback = 1;
        if (!func_L39_004C2068(s)) {
            goto err;
        }
        if (!func_L39_004C2118(s, n + 0x12C)) {
            goto err;
        }
        s->rstate = 0xF0;
        s->packet_length = n;
        s->packet = s->s2->rbuf;
        func_11D380(s->packet, buf, n);
        s->s2->rbuf_left = n;
        s->s2->rbuf_offs = 0;
        s->s2->write_sequence = 1;
        s->method = func_L39_004BFF90();
        s->handshake_func = func_L39_004C3CC0;
    } else if (p[0] == 0x16 && p[1] == 3 && (p[2] == 0 || p[2] == 1) && p[5] == 2) {
        if (!func_L39_004C4D48(s, 1)) {
            goto err;
        }
        s->state = 0x1120;
        s->rstate = 0xF0;
        s->packet_length = n;
        s->packet = s->s3->rbuf_buf;
        func_11D380(s->packet, buf, n);
        s->s3->rbuf_left = n;
        s->s3->rbuf_offset = 0;
        if (p[2] == 0 && !(s->options & 0x2000000)) {
            s->version = 0x300;
            s->method = func_L39_004C6250();
        } else if (p[2] == 1 && !(s->options & 0x4000000)) {
            s->version = 0x301;
            s->method = func_L39_004CC5B8();
        } else {
            if (cb) {
                cb(s, 0x4004, 0, arg);
            }
            func_L39_004BC6C8(0x14, 0x77, 0x102, 0, 0);
            goto err;
        }
        s->handshake_func = func_L39_004C3CC0;
    } else if (p[0] == 0x15 && p[1] == 3 && (p[2] == 0 || p[2] == 1) && p[3] == 0 && p[4] == 2) {
        void (*info)(void *, s32, s32) = 0;
        s32 j;

        if (s->info_callback != 0) {
            info = s->info_callback;
        } else {
            info = s->ctx->info_callback;
        }
        i = p[5];
        if (info != 0) {
            j = (i << 8) | p[6];
            info(s, 0x4004, j);
        }
        if (cb) {
            cb(s, 0x4004, (i << 8) | p[6], arg);
        }
        s->rwstate = 1;
        func_L39_004BC6C8(0x14, 0x77, 1000 + p[6], 0, 0);
        goto err;
    } else {
        func_L39_004BC6C8(0x14, 0x77, 0xFC, 0, 0);
        goto err;
    }
    s->init_num = 0;
    if (!func_L39_004CB730(s, 0)) {
        goto err;
    }
    s->first_packet = 1;
    return func_L39_004C3CC0(s);
err:
    return -1;
}
/* localdecomp:end func_L39_004BF630 */

/* localdecomp:start func_L39_004BFAD0 */
typedef struct S_004BFAD0 {
    u8 pad0[0x54];
    s32 f54;
} S_004BFAD0;
extern S_004BFAD0 D_L39_004648C0;
extern s32 func_L39_004CBF60(void);

void func_L39_004BFAD0(void) {
    s32 r = func_L39_004CBF60();
    if (D_L39_004648C0.f54 == 0) {
        D_L39_004648C0.f54 = r + 0x10;
    }
}
/* localdecomp:end func_L39_004BFAD0 */

/* localdecomp:start func_L39_004BFB08 */
s32 func_L39_004BFB08(void) {
    return 0;
}
/* localdecomp:end func_L39_004BFB08 */

/* localdecomp:start func_L39_004BFB10 */
s32 func_L39_004BFB10(void) {
    return 300;
}
/* localdecomp:end func_L39_004BFB10 */

/* localdecomp:start func_L39_004BFB18 */
extern void func_L39_004BFAD0(void);

S_004BFAD0 *func_L39_004BFB18(void) {
    func_L39_004BFAD0();
    return &D_L39_004648C0;
}
/* localdecomp:end func_L39_004BFB18 */

/* localdecomp:start func_L39_004BFB40 */
extern u32 func_L39_004C2468(void);
extern u32 func_L39_004C1C10(void);

u32 func_L39_004BFB40(void) {
    u32 n = func_L39_004C2468();
    return n + func_L39_004C1C10();
}
/* localdecomp:end func_L39_004BFB40 */

/* localdecomp:start func_L39_004BFB70 */
extern u32 func_L39_004C2468(void);
extern u32 func_L39_004C2470(u32);
extern u32 func_L39_004C1C18(u32);

s32 func_L39_004BFB70(u32 n) {
    u32 m = func_L39_004C2468();
    if (n < m) {
        return func_L39_004C2470(n);
    }
    return func_L39_004C1C18(n - m);
}
/* localdecomp:end func_L39_004BFB70 */

/* localdecomp:start func_L39_004BFBC0 */
/* OpenSSL's ssl23_get_cipher_by_char: func_L39_004C2468 is ssl3_num_ciphers, func_L39_004C2C10
   ssl3_get_cipher_by_char, func_L39_004C1DC8 ssl2_get_cipher_by_char */
typedef struct C_004BFBC0 {
    s32 valid;
    const char *name;
    unsigned long id;
    u8 pad10[0x30 - 0x10];
} C_004BFBC0;
extern u32 func_L39_004C2468(void);
extern C_004BFBC0 *func_L39_004C2C10(const u8 *);
extern C_004BFBC0 *func_L39_004C1DC8(const u8 *);

C_004BFBC0 *func_L39_004BFBC0(const u8 *p) {
    C_004BFBC0 c, *cp;
    unsigned long id;
    s32 n;

    n = func_L39_004C2468();
    id = 0x03000000 | ((unsigned long)p[0] << 16) | ((unsigned long)p[1] << 8) | (unsigned long)p[2];
    c.id = id;
    cp = func_L39_004C2C10(p);
    if (cp == 0) {
        cp = func_L39_004C1DC8(p);
    }
    return cp;
}
/* localdecomp:end func_L39_004BFBC0 */

/* localdecomp:start func_L39_004BFC28 */
typedef struct S_004BFC28 { u8 pad0[8]; long v; } S_004BFC28;
s32 func_L39_004BFC28(S_004BFC28 *s, u8 *out) {
    long v;
    if (out) {
        v = s->v;
        out[0] = v >> 16;
        out[1] = v >> 8;
        out[2] = v;
    }
    return 3;
}
/* localdecomp:end func_L39_004BFC28 */

/* localdecomp:start func_L39_004BFC60 */
/* OpenSSL's ssl23_read/ssl23_write with a handshake_func check: func_L39_004C4EE0 is SSL_state,
   func_L39_004C4BF8 ssl_undefined_function */
typedef struct S_004BFC60 {
    u8 pad0[0x1C];
    s32 in_handshake;
    s32 (*handshake_func)(struct S_004BFC60 *);
} S_004BFC60;
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004C4EE0(void *);
extern s32 func_L39_004C4BF8(void *);
extern s32 func_L39_004C3D20(void *, u8 *, s32);

s32 func_L39_004BFC60(S_004BFC60 *s, u8 *buf, s32 len) {
    s32 n;

    *func_0011A6E0() = 0;
    if ((func_L39_004C4EE0(s) & 0x3000) && !s->in_handshake) {
        if (s->handshake_func == 0) {
            func_L39_004BC6C8(0x14, 0x78, 0x44D, 0, 0);
            return -1;
        }
        n = s->handshake_func(s);
        if (n < 0) {
            return n;
        }
        if (n == 0) {
            func_L39_004BC6C8(0x14, 0x78, 0xE5, 0, 0);
            return -1;
        }
        return func_L39_004C3D20(s, buf, len);
    } else {
        func_L39_004C4BF8(s);
        return -1;
    }
}
/* localdecomp:end func_L39_004BFC60 */

/* localdecomp:start func_L39_004BFD40 */
/* OpenSSL's ssl23_read/ssl23_write with a handshake_func check: func_L39_004C4EE0 is SSL_state,
   func_L39_004C4BF8 ssl_undefined_function */
typedef struct S_004BFD40 {
    u8 pad0[0x1C];
    s32 in_handshake;
    s32 (*handshake_func)(struct S_004BFD40 *);
} S_004BFD40;
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004C4EE0(void *);
extern s32 func_L39_004C4BF8(void *);
extern s32 func_L39_004C3D60(void *, u8 *, s32);

s32 func_L39_004BFD40(S_004BFD40 *s, u8 *buf, s32 len) {
    s32 n;

    *func_0011A6E0() = 0;
    if ((func_L39_004C4EE0(s) & 0x3000) && !s->in_handshake) {
        if (s->handshake_func == 0) {
            func_L39_004BC6C8(0x14, 0x79, 0x44D, 0, 0);
            return -1;
        }
        n = s->handshake_func(s);
        if (n < 0) {
            return n;
        }
        if (n == 0) {
            func_L39_004BC6C8(0x14, 0x79, 0xE5, 0, 0);
            return -1;
        }
        return func_L39_004C3D60(s, buf, len);
    } else {
        func_L39_004C4BF8(s);
        return -1;
    }
}
/* localdecomp:end func_L39_004BFD40 */
