#include "common.h"

/* localdecomp:start func_L39_004F9F38 */
s32 func_L39_004F9F38(u8 **pp, s32 *outp, long *out, s32 n) {
    u8 *p;
    long v;
    s32 len;
    s32 c;
    s32 c2;
    long c3;

    p = *pp;
    v = 0;
    if (n-- <= 0) {
        return 0;
    }
    c = *p;
    if (c == 0x80) {
        *outp = 1;
        p++;
        goto done;
    }
    *outp = 0;
    c2 = *p++;
    len = c2 & 0x7F;
    if (c2 & 0x80) {
        if ((u32)len >= 9) {
            return 0;
        }
        n--;
        if (n == -1) {
            return 0;
        }
        if (len-- > 0) {
            do {
                v <<= 8;
                c3 = *p++;
                v |= c3;
                n--;
                if (n == -1) {
                    return 0;
                }
            } while (len-- > 0);
        }
    } else {
        v = len;
    }
done:
    if (v >= 0) {
        *pp = p;
        *out = v;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004F9F38 */
