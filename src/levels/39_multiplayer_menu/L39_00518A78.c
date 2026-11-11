#include "common.h"

/* localdecomp:start func_L39_00518A78 */
/* newlib-style _strtoul_r (args: nptr, endptr, base, errno ptr) */
u32 func_L39_00518A78(const char *nptr, char **endptr, s32 base, s32 *err) {
    const char *s = nptr;
    u32 acc;
    u8 c;
    u32 cutoff;
    s32 neg = 0, any, cutlim;

    do {
        c = (u8)*s++;
    } while ((u32)(c - 9) < 5 || c == ' ');
    if (c == '-') {
        neg = 1;
        c = (u8)*s++;
    } else if (c == '+') {
        c = (u8)*s++;
    }
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = (u8)s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = (u32)0xFFFFFFFF / (u32)base;
    cutlim = (u32)0xFFFFFFFF % (u32)base;
    for (acc = 0, any = 0; (s8)c >= 0; c = *s++) {
        if ((u8)(c - '0') < 10)
            c -= '0';
        else if ((u8)(c - 'A') < 26 || (u8)(c - 'a') < 26)
            c -= (u8)(c - 'A') < 26 ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = 0xFFFFFFFF;
        *err = 0x22;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);
    return acc;
}
/* localdecomp:end func_L39_00518A78 */
