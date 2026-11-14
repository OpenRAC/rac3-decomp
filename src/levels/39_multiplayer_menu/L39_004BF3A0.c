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

INCLUDE_ASM("asm/levels", func_L39_004BF630);

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

INCLUDE_ASM("asm/levels", func_L39_004BFB18);

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

INCLUDE_ASM("asm/levels", func_L39_004BFC60);

INCLUDE_ASM("asm/levels", func_L39_004BFD40);
