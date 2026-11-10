#include "common.h"

/* localdecomp:start func_L39_004F9B58 */
extern int func_L39_0050A178(int, int, int, int, int);
extern void func_L39_004BC6C8(int, int, int, int, int);
extern s32 func_L39_004F9C00(s32);
extern void func_L39_004FA4E8(s32);
s32 func_L39_004F9B58(s32 *a0, s32 a1, s32 a2) {
    s32 p;

    p = func_L39_0050A178((s32)a0, a1, a2, 0x17, 0);
    if (p == 0) {
        func_L39_004BC6C8(0xD, 0x87, 4, 0, 0);
        return 0;
    }
    if (func_L39_004F9C00(p) != 0) {
        return p;
    }
    func_L39_004BC6C8(0xD, 0x87, 0x7B, 0, 0);
    if (a0 != 0 && *a0 == p) {
        return 0;
    }
    func_L39_004FA4E8(p);
    return 0;
}
/* localdecomp:end func_L39_004F9B58 */

INCLUDE_ASM("asm/levels", func_L39_004F9C00);

/* localdecomp:start func_L39_004F9E08 */
extern s32 func_L39_004F9F38(u8 **pp, s32 *outp, long *out, s32 n);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* OpenSSL ASN1_get_object */
s32 func_L39_004F9E08(u8 **pp, long *plength, s32 *ptag, s32 *pclass, long omax) {
    s32 i, ret;
    long l;
    u8 *p = *pp;
    s32 tag, xclass, inf;
    long max = omax;

    if (!max) {
        goto err;
    }
    ret = (*p & 0x20);
    xclass = (*p & 0xC0);
    i = *p & 0x1F;
    if (i == 0x1F) {
        p++;
        if (--max == 0) {
            goto err;
        }
        l = 0;
        while (*p & 0x80) {
            l <<= 7L;
            l |= *(p++) & 0x7F;
            if (--max == 0) {
                goto err;
            }
        }
        l <<= 7L;
        l |= *(p++) & 0x7F;
        tag = (s32)l;
    } else {
        tag = i;
        p++;
        if (--max == 0) {
            goto err;
        }
    }
    *ptag = tag;
    *pclass = xclass;
    if (!func_L39_004F9F38(&p, &inf, plength, (s32)max)) {
        goto err;
    }
    *pp = p;
    return ret | inf;
err:
    func_L39_004BC6C8(0xD, 0x6B, 0x78, 0, 0);
    return 0x80;
}
/* localdecomp:end func_L39_004F9E08 */
