#include "common.h"

/* localdecomp:start func_L39_004C4F48 */
extern void *func_L39_004C3428(void);
extern void func_L39_004C3498(void *);
extern s32 func_L39_004C50B8(void *, void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

typedef struct S_004C4F48B { s32 pad[0x28]; void *fA0; } S_004C4F48B;
typedef struct S_004C4F48 {
    s32 pad0[0x21];
    void *f84;
    s32 pad1[0x15];
    S_004C4F48B *fDC;
} S_004C4F48;

s32 func_L39_004C4F48(S_004C4F48 *arg0, void *arg1) {
    void *v;
    if (arg1 == 0) {
        func_L39_004BC6C8(0x14, 0xC7, 0x23, 0, 0);
        return 0;
    }
    if (arg0->f84 == 0 || arg0->f84 == arg0->fDC->fA0) {
        v = func_L39_004C3428();
        if (v == 0) {
            func_L39_004BC6C8(0x14, 0xC7, 0x21, 0, 0);
            return 0;
        }
        if (arg0->f84 != 0) {
            func_L39_004C3498(arg0->f84);
        }
        arg0->f84 = v;
        return func_L39_004C50B8(v, arg1);
    }
    return func_L39_004C50B8(arg0->f84, arg1);
}
/* localdecomp:end func_L39_004C4F48 */

/* localdecomp:start func_L39_004C5000 */
extern s32 func_L39_004EC870(void *, void *);

s32 func_L39_004C5000(S_004C4F48 *arg0, void *arg1) {
    void *v;
    if (arg1 == 0) {
        func_L39_004BC6C8(0x14, 0xCA, 0x23, 0, 0);
        return 0;
    }
    if (arg0->f84 == 0 || arg0->f84 == arg0->fDC->fA0) {
        v = func_L39_004C3428();
        if (v == 0) {
            func_L39_004BC6C8(0x14, 0xCA, 0x21, 0, 0);
            return 0;
        }
        if (arg0->f84 != 0) {
            func_L39_004C3498(arg0->f84);
        }
        arg0->f84 = v;
        return func_L39_004EC870(v, arg1);
    }
    return func_L39_004EC870(arg0->f84, arg1);
}
/* localdecomp:end func_L39_004C5000 */

INCLUDE_ASM("asm/levels", func_L39_004C50B8);

/* localdecomp:start func_L39_004C52B0 */
typedef struct {
    s32 three_byte_header;  /* 0x00 */
    s32 clear_text;         /* 0x04 */
    s32 escape;             /* 0x08 */
    u8 pad0C[0x24];
    u8 *rbuf;               /* 0x30 */
    u8 pad34[0xC];
    s32 padding;            /* 0x40 */
    u32 rlength;            /* 0x44 */
    s32 ract_data_length;   /* 0x48 */
    u8 pad4C[0x8];
    u8 *ract_data;          /* 0x54 */
    u8 pad58[0x4];
    u8 *mac_data;           /* 0x5C */
    u8 *pad_data;           /* 0x60 */
    u8 pad64[0x74];
    u64 read_sequence;      /* 0xD8 */
} S2_004C52B0;

typedef struct {
    u8 pad0[0x88];
    void (*cb)(void *, s32, void *);  /* 0x88 */
    void *cb_arg;                     /* 0x8C */
} CTX_004C52B0;

typedef struct S_004C52B0 {
    u8 pad0[0x18];
    s32 rwstate;                    /* 0x18 */
    s32 in_handshake;               /* 0x1C */
    s32 (*handshake_func)(struct S_004C52B0 *); /* 0x20 */
    u8 pad24[0x14];
    s32 rstate;                     /* 0x38 */
    u8 pad3C[0xC];
    u8 *packet;                     /* 0x48 */
    s32 packet_length;              /* 0x4C */
    S2_004C52B0 *s2;                /* 0x50 */
    u8 pad54[0x14];
    s32 mac_size;                   /* 0x68 */
    u8 pad6C[0x4];
    void *read_ctx;                 /* 0x70 */
    u8 pad74[0x58];
    void (*msg_cb)(struct S_004C52B0 *, s32, void *); /* 0xCC */
    void *msg_cb_arg;               /* 0xD0 */
    u8 padD4[0x8];
    CTX_004C52B0 *ctx;              /* 0xDC */
    u8 padE0[0x28];
    s32 first_packet;               /* 0x108 */
    u8 pad10C[0x8];
    s32 max_len;                    /* 0x114 */
} S_004C52B0;

extern s32 func_L39_004C2068(S_004C52B0 *);
extern s32 func_L39_004C4EE0(S_004C52B0 *);
extern int func_L39_004C2118(void *, int);
extern s32 func_L39_004C57B0(S_004C52B0 *, s32, u32, s32);
extern void func_L39_004EAD18(S_004C52B0 *, s32);
extern void func_L39_004EADC0(S_004C52B0 *, u8 *, s32);
extern u32 func_L39_004DE908(void *);
extern s32 func_0011D2EC(void *, void *, s32);
extern s32 *func_0011A6E0(void);
extern void *func_0011D380(void *, const void *, unsigned int);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004C52B0(S_004C52B0 *, u8 *, s32);

s32 func_L39_004C52B0(S_004C52B0 *s, u8 *buf, s32 len) {
    s32 n, i;
    u32 mac_size = 0;
    u8 *p;
    u8 mac[32];
    void (*cb)(S_004C52B0 *, s32, void *) = 0;
    void *cb_arg = 0;

    if (s->s2->rbuf == 0) {
        if (!func_L39_004C2068(s))
            return -1;
    }
    if (func_L39_004C4EE0(s) & 0x3000) {
        if (!s->in_handshake) {
            if (s->handshake_func == 0) {
                func_L39_004BC6C8(0x14, 0x7D, 0x44D, 0, 0);
                return -1;
            }
            n = s->handshake_func(s);
            if (n < 0)
                return n;
            if (n == 0) {
                func_L39_004BC6C8(0x14, 0x7D, 0xE5, 0, 0);
                return -1;
            }
        }
    }
    *func_0011A6E0() = 0;
    s->rwstate = 1;
    if (len <= 0)
        return len;

    if (s->s2->ract_data_length != 0) {
        if (len > s->s2->ract_data_length)
            n = s->s2->ract_data_length;
        else
            n = len;
        func_0011D380(buf, s->s2->ract_data, n);
        s->s2->ract_data_length -= n;
        s->s2->ract_data += n;
        if (s->s2->ract_data_length == 0)
            s->rstate = 0xF0;
        return n;
    }

    if (s->rstate == 0xF0) {
        if (s->first_packet) {
            if (s->s2->rbuf == 0) {
                if (!func_L39_004C2118(s, s->max_len))
                    return -1;
            }
            n = func_L39_004C57B0(s, 5, s->max_len, 0);
            if (n <= 0)
                return n;
            p = s->packet;
            s->first_packet = 0;
            if (!((p[0] & 0x80) && (p[2] == 1 || p[2] == 4))) {
                func_L39_004BC6C8(0x14, 0x7D, 0xAF, 0, 0);
                return -1;
            }
        } else {
            n = func_L39_004C57B0(s, 2, s->max_len, 0);
            if (n <= 0)
                return n;
        }
        s->rstate = 0xF1;
        p = s->packet;
        s->s2->escape = 0;
        s->s2->rlength = (p[0] << 8) | p[1];
        if (p[0] & 0x80) {
            s->s2->three_byte_header = 0;
            s->s2->rlength &= 0x7FFF;
        } else {
            s->s2->three_byte_header = 1;
            s->s2->rlength &= 0x3FFF;
            s->s2->escape = (p[0] & 0x40) ? 1 : 0;
        }
    }

    if (s->rstate == 0xF1) {
        n = s->s2->rlength + 2 + s->s2->three_byte_header;
        if (n > s->max_len) {
            if (!func_L39_004C2118(s, n))
                return -1;
        }
        if (n > s->packet_length) {
            n -= s->packet_length;
            i = func_L39_004C57B0(s, n, n, 1);
            if (i <= 0)
                return i;
        }
        s->rstate = 0xF0;
        p = s->packet + 2;
        if (s->s2->three_byte_header) {
            s->s2->padding = *(p++);
        } else {
            s->s2->padding = 0;
        }
        if (s->s2->clear_text) {
            s->s2->mac_data = p;
            s->s2->ract_data = p;
            s->s2->pad_data = 0;
        } else {
            mac_size = s->mac_size;
            s->s2->mac_data = p;
            s->s2->ract_data = p + mac_size;
            s->s2->pad_data = &p[mac_size + s->s2->rlength - s->s2->padding];
        }
        s->s2->ract_data_length = s->s2->rlength;
        if (!s->s2->clear_text && s->s2->rlength >= mac_size) {
            func_L39_004EAD18(s, 0);
            s->s2->ract_data_length -= mac_size;
            func_L39_004EADC0(s, mac, 0);
            s->s2->ract_data_length -= s->s2->padding;
            if (func_0011D2EC(mac, s->s2->mac_data, mac_size) != 0
                || s->s2->rlength % func_L39_004DE908(s->read_ctx) != 0) {
                func_L39_004BC6C8(0x14, 0x7D, 0x71, 0, 0);
                return -1;
            }
        }
        s->s2->read_sequence = (s->s2->read_sequence + 1) & 0xFFFFFFFF;
        if (s->s2->ract_data_length == 0)
            return 0;
        n = func_L39_004C52B0(s, buf, len);
        if (!s->in_handshake) {
            if (s->msg_cb != 0) {
                cb = s->msg_cb;
                cb_arg = s->msg_cb_arg;
            } else if (s->ctx->cb != 0) {
                cb = s->ctx->cb;
                cb_arg = s->ctx->cb_arg;
            }
            if (cb != 0)
                cb(s, 4, cb_arg);
        }
        return n;
    }
    func_L39_004BC6C8(0x14, 0x7D, 0x7E, 0, 0);
    return -1;
}
/* localdecomp:end func_L39_004C52B0 */

/* localdecomp:start func_L39_004C57B0 */
typedef struct {
    u8 pad0[0x28];
    s32 left;
    s32 offset;
    u8 *buf;
} R_004C57B0;

typedef struct {
    u8 pad0[0xC];
    void *rbio;
    u8 pad10[0x8];
    s32 rwstate;
    u8 pad1C[0x2C];
    u8 *packet;
    s32 packet_length;
    R_004C57B0 *s3;
    u8 pad54[0x4];
    s32 read_ahead;
    u8 pad5C[0xB8];
    u32 limit;
} S_004C57B0;

extern void *func_0011D380(void *, const void *, unsigned int);
extern s32 *func_0011A6E0(void);
extern s32 func_L39_004DAB90(void *, char *, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004C57B0(S_004C52B0 *arg0, s32 n, u32 max, s32 extend) {
    s32 i, off, left;
    R_004C57B0 *rb;

    left = ((S_004C57B0 *)arg0)->s3->left;
    if (left >= n) {
        if (extend) {
            ((S_004C57B0 *)arg0)->packet_length += n;
        } else {
            ((S_004C57B0 *)arg0)->packet = ((S_004C57B0 *)arg0)->s3->buf + ((S_004C57B0 *)arg0)->s3->offset;
            ((S_004C57B0 *)arg0)->packet_length = n;
        }
        ((S_004C57B0 *)arg0)->s3->left -= n;
        ((S_004C57B0 *)arg0)->s3->offset += n;
        return n;
    }
    off = 0;
    if (!((S_004C57B0 *)arg0)->read_ahead)
        max = n;
    if (((S_004C57B0 *)arg0)->limit < max)
        max = ((S_004C57B0 *)arg0)->limit;
    if (left != 0 || (((S_004C57B0 *)arg0)->packet_length != 0 && extend)) {
        i = left;
        if (extend) {
            off = ((S_004C57B0 *)arg0)->packet_length;
            if (((S_004C57B0 *)arg0)->packet != ((S_004C57B0 *)arg0)->s3->buf)
                func_0011D380(((S_004C57B0 *)arg0)->s3->buf, ((S_004C57B0 *)arg0)->packet, i + off);
        } else {
            if (((S_004C57B0 *)arg0)->s3->offset != 0) {
                func_0011D380(((S_004C57B0 *)arg0)->s3->buf, ((S_004C57B0 *)arg0)->s3->buf + ((S_004C57B0 *)arg0)->s3->offset, i);
                ((S_004C57B0 *)arg0)->s3->offset = 0;
            }
        }
        ((S_004C57B0 *)arg0)->s3->left = 0;
    } else {
        i = 0;
    }
    ((S_004C57B0 *)arg0)->packet = ((S_004C57B0 *)arg0)->s3->buf;
    while (i < n) {
        s32 r;
        *func_0011A6E0() = 0;
        if (((S_004C57B0 *)arg0)->rbio != 0) {
            ((S_004C57B0 *)arg0)->rwstate = 3;
            r = func_L39_004DAB90(((S_004C57B0 *)arg0)->rbio, (char *)((S_004C57B0 *)arg0)->s3->buf + (off + i), max - i);
        } else {
            func_L39_004BC6C8(0x14, 0x70, 0xD3, 0, 0);
            r = -1;
        }
        if (r <= 0) {
            ((S_004C57B0 *)arg0)->s3->left += i;
            return r;
        }
        i += r;
    }
    rb = ((S_004C57B0 *)arg0)->s3;
    if (n < i) {
        rb->offset = n + off;
        ((S_004C57B0 *)arg0)->s3->left = i - n;
    } else {
        rb->offset = 0;
        ((S_004C57B0 *)arg0)->s3->left = 0;
    }
    if (extend) {
        ((S_004C57B0 *)arg0)->packet_length += n;
    } else {
        ((S_004C57B0 *)arg0)->packet_length = n;
    }
    ((S_004C57B0 *)arg0)->rwstate = 1;
    return n;
}
/* localdecomp:end func_L39_004C57B0 */
