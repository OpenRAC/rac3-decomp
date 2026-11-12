#include "common.h"

/* localdecomp:start func_L39_004BFE20 */
typedef struct B_004BFE20 {
    s32 pad0;
    u8 *buf;
} B_004BFE20;
typedef struct S_004BFE20 {
    u8 pad0[0x10];
    s32 wbio;
    u8 pad14[0x18 - 0x14];
    s32 rwstate;
    u8 pad1C[0x3C - 0x1C];
    B_004BFE20 *init_buf;
    s32 init_num;
    s32 init_off;
} S_004BFE20;

extern s32 func_L39_004DACB0(s32, u8 *, s32);

s32 func_L39_004BFE20(S_004BFE20 *s) {
    s32 i, num, tot;
    u8 *buf;

    buf = s->init_buf->buf;
    tot = s->init_off;
    num = s->init_num;
    for (;;) {
        s->rwstate = 2;
        i = func_L39_004DACB0(s->wbio, &buf[tot], num);
        if (i <= 0) {
            s->init_off = tot;
            s->init_num = num;
            return i;
        }
        s->rwstate = 1;
        if (i == num) {
            return tot + i;
        }
        num -= i;
        tot += i;
    }
}
/* localdecomp:end func_L39_004BFE20 */

INCLUDE_ASM("asm/levels", func_L39_004BFEC8);

INCLUDE_ASM("asm/levels", func_L39_004BFF90);

INCLUDE_ASM("asm/levels", func_L39_004C04D0);

INCLUDE_ASM("asm/levels", func_L39_004C09B0);

/* localdecomp:start func_L39_004C0BD8 */
typedef struct M_004C0BD8 {
    u8 pad0[0x3C];
    s32 (*put_cipher_by_char)(void *cipher, u8 *p);
} M_004C0BD8;

typedef struct B_004C0BD8 {
    s32 length;
    u8 *data;
} B_004C0BD8;

typedef struct R_004C0BD8 {
    u8 pad0[0xC];
    s32 ssl2_rollback;
} R_004C0BD8;

typedef struct C_004C0BD8 {
    u8 pad0[0x18];
    unsigned long f18;
} C_004C0BD8;

typedef struct E_004C0BD8 {
    u8 pad0[4];
    s32 key_arg_length;
    u8 key_arg[8];
    s32 master_key_length;
    u8 master_key[0x7C];
    void *f90;
    u8 pad94[0xAC - 0x94];
    C_004C0BD8 *cipher;
} E_004C0BD8;

typedef struct S_004C0BD8 {
    u8 pad0[8];
    M_004C0BD8 *method;
    u8 pad0C[0x30 - 0xC];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C0BD8 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 pad48[0x50 - 0x48];
    R_004C0BD8 *s2;
    u8 pad54[0xB0 - 0x54];
    E_004C0BD8 *session;
    u8 padB4[0x100 - 0xB4];
    long options;
} S_004C0BD8;

extern void *func_L39_004E5090(void);
extern s32 func_L39_004CA3D0(void *, void **, void **);
extern void func_L39_004C6100(S_004C0BD8 *, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L01_004CC758(void *);
extern s32 func_L39_004DE8F8(void *);
extern s32 func_L39_004E4FC8(void *, void *, s32);
extern void *func_0011D380(void *, void *, s32);
extern s32 func_L39_004C18B8(void *, s32, void *, void *, s32);
extern s32 func_L39_004C6020(S_004C0BD8 *);

s32 func_L39_004C0BD8(S_004C0BD8 *s) {
    void *rng = func_L39_004E5090();
    u8 *buf = s->init_buf->data;
    u8 *p;
    u8 *d;
    E_004C0BD8 *sess;
    void *c;
    void *md;
    s32 i;
    s32 clear;
    s32 enc;
    s32 karg;

    p = buf;
    if (s->state == 0x1030) {
        if (!func_L39_004CA3D0(s->session->cipher, &c, &md)) {
            func_L39_004C6100(s, 1);
            func_L39_004BC6C8(0x14, 0x66, 0xCE, 0, 0);
            return -1;
        }
        sess = s->session;
        *(p++) = 2;
        d = p + 9;
        i = s->method->put_cipher_by_char(sess->cipher, p);
        p += i;

        i = func_L01_004CC758(c);
        sess->key_arg_length = i;
        if (i > 0) {
            func_L39_004E4FC8(rng, sess->key_arg, i);
        }

        i = func_L39_004DE8F8(c);
        sess->master_key_length = i;
        if (i > 0) {
            func_L39_004E4FC8(rng, sess->master_key, i);
        }

        enc = sess->cipher->f18 & 0xFF;
        if (enc == 0) {
            enc = i;
        }
        if (i < enc) {
            func_L39_004C6100(s, 0);
            func_L39_004BC6C8(0x14, 0x66, 0x8B, 0, 0);
            return -1;
        }
        clear = i - enc;
        p[1] = clear;
        p[0] = clear >> 8;
        p += 2;
        func_0011D380(d, sess->master_key, clear);
        d += clear;

        enc = func_L39_004C18B8(sess->f90, enc, &sess->master_key[clear], d, s->s2->ssl2_rollback ? 2 : 1);
        if (enc <= 0) {
            func_L39_004C6100(s, 0);
            func_L39_004BC6C8(0x14, 0x66, 0xD0, 0, 0);
            return -1;
        }
        if (s->options & 0x8000000) {
            d[1]++;
        }
        if (s->options & 0x10000000) {
            sess->master_key[clear]++;
        }
        p[1] = enc;
        p[0] = enc >> 8;
        p += 2;
        d += enc;
        karg = sess->key_arg_length;
        p[1] = karg;
        p[0] = karg >> 8;
        p += 2;
        func_0011D380(d, sess->key_arg, karg);
        d += karg;

        s->state = 0x1031;
        s->init_num = d - buf;
        s->init_off = 0;
    }
    return func_L39_004C6020(s);
}
/* localdecomp:end func_L39_004C0BD8 */
