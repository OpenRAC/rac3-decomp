#include "common.h"

/* localdecomp:start func_L39_004F9870 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    void *f10;
    s32 f14;
} S_004F9870;

extern void *func_L39_004F9A20(void);
extern void func_L39_004F9A88(S_004F9870 *);
extern s32 func_L39_004F9E08(u8 **, long *, s32 *, s32 *, long);
extern void func_L39_004BEF28(void *);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_11D380(void *, void *, s32);

/* OpenSSL's d2i_ASN1_OBJECT */
S_004F9870 *func_L39_004F9870(S_004F9870 **a, u8 **pp, long length) {
    S_004F9870 *ret = 0;
    u8 *p;
    u8 *data;
    u8 *buf;
    long len;
    s32 inf, tag, xclass;
    s32 i = 0;

    if (a == 0 || *a == 0 || !((*a)->f14 & 1)) {
        if ((ret = func_L39_004F9A20()) == 0)
            return 0;
    } else {
        ret = *a;
    }
    p = *pp;
    inf = func_L39_004F9E08(&p, &len, &tag, &xclass, length);
    if (inf & 0x80) {
        i = 0x65;
        goto err;
    }
    if (len > length - (p - *pp)) {
        i = 0x65;
        goto err;
    }
    if (tag != 6) {
        i = 0x72;
        goto err;
    }
    data = ret->f10;
    if (data == 0 || ret->fC < len) {
        if (data != 0)
            func_L39_004BEF28(data);
        buf = func_L39_004BEED8(len);
        ret->f10 = buf;
        ret->f14 |= 8;
        if (buf == 0) {
            i = 0x21;
            goto err;
        }
        data = buf;
    }
    func_11D380(data, p, len);
    ret->fC = len;
    ret->f0 = 0;
    ret->f4 = 0;
    p += len;
    if (a != 0)
        *a = ret;
    *pp = p;
    return ret;
err:
    func_L39_004BC6C8(0xD, 0x81, i, 0, 0);
    if (ret != 0 && (a == 0 || *a != ret))
        func_L39_004F9A88(ret);
    return 0;
}
/* localdecomp:end func_L39_004F9870 */
