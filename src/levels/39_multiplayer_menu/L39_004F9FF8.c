#include "common.h"

/* localdecomp:start func_L39_004F9FF8 */
extern void func_L39_004FA100(u8 **pp, s32 length);

/* OpenSSL ASN1_put_object */
void func_L39_004F9FF8(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass) {
    u8 *p = *pp;
    s32 i;

    i = (constructed) ? 0x20 : 0;
    i |= (xclass & 0xC0);
    if (tag < 31) {
        *(p++) = i | (tag & 0x1F);
    } else {
        *(p++) = i | 0x1F;
        while (tag > 0x7F) {
            *(p++) = (tag & 0x7F) | 0x80;
            tag >>= 7;
        }
        *(p++) = (tag & 0x7F);
    }
    if (constructed == 2 && length == 0) {
        *(p++) = 0x80;
    } else {
        func_L39_004FA100(&p, length);
    }
    *pp = p;
}
/* localdecomp:end func_L39_004F9FF8 */

INCLUDE_ASM("asm/levels", func_L39_004FA100);

/* localdecomp:start func_L39_004FA1A0 */
/* from OpenSSL's ASN1_object_size (public library code) */
s32 func_L39_004FA1A0(s32 constructed, s32 length, s32 tag) {
    s32 ret;

    ret = length;
    ret++;
    if (tag >= 31) {
        while (tag > 0) {
            tag >>= 7;
            ret++;
        }
    }
    if (length == 0 && constructed == 2) {
        ret += 2;
    }
    ret++;
    if (length > 127) {
        while (length > 0) {
            length >>= 8;
            ret++;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004FA1A0 */

/* localdecomp:start func_L39_004FA228 */
/* OpenSSL asn1_Finish, ee29 library code */
typedef struct {
    u8 *p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    long slen;
} S_004FA228;

extern s32 func_L39_0050A5A0(u8 **, long);

s32 func_L39_004FA228(S_004FA228 *c) {
    if ((c->inf == 0x21) && (!c->eos)) {
        if (!func_L39_0050A5A0(&c->p, c->slen)) {
            c->error = 9;
            return 0;
        }
    }
    if (((c->slen != 0) && !(c->inf & 1)) || ((c->slen < 0) && (c->inf & 1))) {
        c->error = 8;
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_004FA228 */

/* localdecomp:start func_L39_004FA2A8 */
typedef struct {
    u8 *p;      /* 0x00 */
    s32 done;   /* 0x04 */
    s32 err;    /* 0x08 */
    s32 tag;    /* 0x0C */
    s32 cls;    /* 0x10 */
    s32 cons;   /* 0x14 */
    s64 len;    /* 0x18 */
    s32 f20;    /* 0x20 */
    s32 f24;    /* 0x24 */
    s32 *base;  /* 0x28 */
} S_004FA2A8;

extern s32 func_L39_004F9E08(S_004FA2A8 *, s64 *, s32 *, s32 *, s64);

s32 func_L39_004FA2A8(S_004FA2A8 *s, s64 *left) {
    u8 *start;

    start = s->p;
    s->tag = func_L39_004F9E08(s, &s->len, &s->cls, &s->cons, *left);
    if (s->tag & 0x80) {
        s->err = 6;
        return 0;
    }
    if (s->cls != 0x10) {
        s->err = 7;
        return 0;
    }
    *left -= s->p - start;
    if (s->f20 != 0 && *left < 0) {
        s->err = 8;
        return 0;
    }
    if (s->tag == 0x21) {
        s->len = *s->base + (s32)*left - (s32)s->p;
    }
    s->done = 0;
    return 1;
}
/* localdecomp:end func_L39_004FA2A8 */

INCLUDE_ASM("asm/levels", func_L39_004FA380);
