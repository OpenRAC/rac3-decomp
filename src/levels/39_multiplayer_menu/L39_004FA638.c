#include "common.h"

/* localdecomp:start func_L39_004FA638 */
typedef struct {
    s32 num;
    void **data;
} S_STACK_004FA638;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 set;
    s32 size;
} S_ENTRY_004FA638;

typedef struct {
    s32 length;
    u8 *data;
} S_BUF_004FA638;

typedef struct {
    s32 f0;
    S_STACK_004FA638 *entries;
    s32 modified;
    S_BUF_004FA638 *bytes;
} S_NAME_004FA638;

extern s32 func_L39_004FA1A0(s32 constructed, s32 length, s32 tag);
extern void func_L39_004F9FF8(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass);
extern s32 func_L39_0050A648(S_ENTRY_004FA638 *, u8 **);
extern s32 func_L39_004DB1C0(S_BUF_004FA638 *, s32);

/* OpenSSL i2d_X509_NAME_entries */
s32 func_L39_004FA638(S_NAME_004FA638 *a) {
    S_ENTRY_004FA638 *ne, *fe = 0;
    S_STACK_004FA638 *sk;
    S_BUF_004FA638 *buf;
    s32 set = 0, r, ret = 0;
    s32 i;
    u8 *p;
    s32 size = 0;

    sk = a->entries;
    for (i = 0; i < sk->num; i++) {
        ne = sk->data[i];
        if (fe == 0) {
            fe = ne;
            size = 0;
        }
        if (ne->set != set) {
            ret += func_L39_004FA1A0(1, size, 0x11);
            fe->size = size;
            fe = ne;
            size = 0;
            set = ne->set;
        }
        size += func_L39_0050A648(ne, 0);
    }
    ret += func_L39_004FA1A0(1, size, 0x11);
    if (fe != 0) {
        fe->size = size;
    }
    r = func_L39_004FA1A0(1, ret, 0x10);
    buf = a->bytes;
    if (!func_L39_004DB1C0(buf, r)) {
        goto err;
    }
    p = buf->data;
    func_L39_004F9FF8(&p, 1, ret, 0x10, 0);
    set = -1;
    for (i = 0; i < sk->num; i++) {
        ne = sk->data[i];
        if (set != ne->set) {
            set = ne->set;
            func_L39_004F9FF8(&p, 1, ne->size, 0x11, 0);
        }
        func_L39_0050A648(ne, &p);
    }
    a->modified = 0;
    return r;
err:
    return -1;
}
/* localdecomp:end func_L39_004FA638 */

INCLUDE_ASM("asm/levels", func_L39_004FA7F8);

/* localdecomp:start func_L39_004FAAB0 */
typedef struct { s32 a; s32 b; s32 ok; s32 c; } S_004FAAB0;
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004CC228(s32);
extern s32 func_L39_004DB110(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
/* same error-record shape as func_L39_004FB5C8 */
S_004FAAB0 *func_L39_004FAAB0(void) {
    S_004FAAB0 *p;
    s32 err[12];

    p = func_L39_004BEED8(0x18);
    if (p == 0) {
        err[11] = 0xDB;
        goto fail;
    }
    p->a = 0;
    p->b = func_L39_004CC228(0);
    if (p->b == 0) {
        err[11] = 0xDE;
        goto fail;
    }
    p->c = func_L39_004DB110();
    if (p->c == 0) {
        return 0;
    }
    p->ok = 1;
    return p;
fail:
    func_L39_004BC6C8(0xD, 0xD4, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004FAAB0 */

INCLUDE_ASM("asm/levels", func_L39_004FAB48);

/* localdecomp:start func_L39_004FAB88 */
typedef struct ASN1_CTX_004FAB88 {
    u8 *p;
    s32 eos;
    s32 error;
    s32 inf;
    s32 tag;
    s32 xclass;
    s64 slen;
    u8 *max;
    u8 *q;
    u8 **pp;
    s32 line;
} ASN1_CTX_004FAB88;

typedef struct S_004FAB88 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004FAB88;
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004FA460(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

S_004FAB88 *func_L39_004FAB88(void)
{
    S_004FAB88 *ret = 0;
    ASN1_CTX_004FAB88 c;

    ret = func_L39_004BEED8(0x14);
    if (ret != 0) {
        ret->f0 = 0;
        ret->f4 = 0;
        ret->fC = 0;
        ret->f8 = func_L39_004FA460();
        return ret->f8 ? ret : 0;
    }
    c.line = 0xEE;
    func_L39_004BC6C8(0xD, 0xD3, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004FAB88 */

INCLUDE_ASM("asm/levels", func_L39_004FAC00);
