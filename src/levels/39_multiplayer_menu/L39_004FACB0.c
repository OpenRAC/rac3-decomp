#include "common.h"

/* localdecomp:start func_L39_004FACB0 */
typedef struct {
    s32 num;
    u8 **data;
} S_004FACB0;

extern s32 func_L39_004FA1A0(s32 constructed, s32 length, s32 tag);
extern void func_L39_004F9FF8(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass);

/* OpenSSL i2d_ASN1_SET */
s32 func_L39_004FACB0(S_004FACB0 *a, u8 **pp, s32 (*func)(u8 *, u8 **), s32 ex_tag, s32 ex_class) {
    s32 ret = 0, r;
    s32 i;
    u8 *p;

    if (a == 0) {
        return 0;
    }
    for (i = a->num - 1; i >= 0; i--) {
        ret += func(a->data[i], 0);
    }
    r = func_L39_004FA1A0(1, ret, ex_tag);
    if (pp == 0) {
        return r;
    }
    p = *pp;
    func_L39_004F9FF8(&p, 1, ret, ex_tag, ex_class);
    for (i = 0; i < a->num; i++) {
        func(a->data[i], &p);
    }
    *pp = p;
    return r;
}
/* localdecomp:end func_L39_004FACB0 */

INCLUDE_ASM("asm/levels", func_L39_004FADD8);

INCLUDE_ASM("asm/levels", func_L39_004FB050);

INCLUDE_ASM("asm/levels", func_L39_004FB2A0);
