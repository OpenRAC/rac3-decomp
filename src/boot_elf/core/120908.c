#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 120668.c's earlier functions */
typedef s32 (*Out_00120730)(s32, s32 *, s32);
extern s32 func_00120730(Out_00120730 out, s32 a1, s32 *a2, double value);

/* localdecomp:start func_00120908 */
extern char D_00150880[];
extern char D_00150898[];

s32 func_00120908(Out_00120730 put, s32 cookie, s32 arg3, const char *fmt, char *ap)
{
    char buf[32];
    char pre[32];
    char *ep = &buf[31];
    s32 flags, width, prec, prelen;
    s32 cnt = 0;
    s32 len, i;
    s32 padc;
    u64 n;
    s64 sn;
    char *cp, *start, *tab;
    float f;

    while (*fmt) {
        flags = 0;
        width = 0;
        prec = 0;
        prelen = 0;
        if (*fmt == '%') {
        reswitch:
            switch (*++fmt) {
            case '-':
                flags |= 1;
                goto reswitch;
            case '+':
                flags |= 2;
                goto reswitch;
            case '0':
                flags |= 4;
                goto reswitch;
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                i = 0;
                do {
                    i = i * 10 + (*fmt - '0');
                    fmt++;
                } while (*fmt >= '0' && *fmt <= '9');
                width = i;
                if (*fmt == 0) goto next;
                fmt--;
                goto reswitch;
            case '.':
                fmt++;
                flags |= 0x20;
                if (*fmt == '*') {
                    i = (ap += 8, *(s32 *)(ap - 8));
                    prec = i >= -1 ? i : -1;
                    goto reswitch;
                }
                i = 0;
                if (*fmt >= '0' && *fmt <= '9') {
                    do {
                        i = i * 10 + (*fmt - '0');
                        fmt++;
                    } while (*fmt >= '0' && *fmt <= '9');
                }
                prec = i >= -1 ? i : -1;
                if (*fmt == 0) goto next;
                fmt--;
                goto reswitch;
            case ' ':
                flags |= 8;
                goto reswitch;
            case '#':
                flags |= 0x10;
                goto reswitch;
            case 'l':
                flags |= 0x40;
                goto reswitch;
            case 'h':
                flags |= 0x80;
                goto reswitch;
            case 'o':
                if (flags & 0x40) {
                    n = (ap += 8, *(u64 *)(ap - 8));
                } else if (flags & 0x80) {
                    n = (u16)(ap += 8, *(u32 *)(ap - 8));
                } else {
                    n = (ap += 8, *(u32 *)(ap - 8));
                }
                cp = ep;
                if (n == 0) {
                    if (!(flags & 0x20) || prec != 0) {
                        *cp-- = '0';
                    }
                } else {
                    do {
                        *cp-- = (n & 7) + '0';
                        n >>= 3;
                    } while (n);
                    if (flags & 0x10) {
                        *cp-- = '0';
                    }
                }
                start = cp + 1;
                len = ep - cp;
                break;
            case 'x':
                tab = D_00150880;
                if (flags & 0x10) {
                    pre[0] = '0';
                    pre[1] = 'x';
                    prelen = 2;
                }
                goto hex;
            case 'X':
                tab = D_00150898;
                if (flags & 0x10) {
                    pre[0] = '0';
                    pre[1] = 'X';
                    prelen = 2;
                }
            hex:
                if (flags & 0x40) {
                    n = (ap += 8, *(u64 *)(ap - 8));
                } else if (flags & 0x80) {
                    n = (u16)(ap += 8, *(u32 *)(ap - 8));
                } else {
                    n = (ap += 8, *(u32 *)(ap - 8));
                }
                cp = ep;
                if (n == 0) {
                    prelen = 0;
                    if (!(flags & 0x20) || prec != 0) {
                        *cp-- = '0';
                    }
                } else {
                    do {
                        *cp-- = tab[(s32)(n & 0xF)];
                        n >>= 4;
                    } while (n);
                }
                start = cp + 1;
                len = ep - cp;
                break;
            case 'd':
            case 'i':
                if (flags & 0x40) {
                    sn = (ap += 8, *(s64 *)(ap - 8));
                } else if (flags & 0x80) {
                    sn = (s16)(ap += 8, *(s32 *)(ap - 8));
                } else {
                    sn = (ap += 8, *(s32 *)(ap - 8));
                }
                cp = ep;
                if (sn >= 0) {
                    if (flags & 2) {
                        pre[0] = '+';
                        prelen = 1;
                    } else if (flags & 8) {
                        pre[0] = ' ';
                        prelen = 1;
                    }
                } else {
                    pre[0] = '-';
                    prelen = 1;
                }
                if (sn == 0) {
                    if (!(flags & 0x20) || prec != 0) {
                        *cp-- = '0';
                    }
                } else {
                    if (sn < 0) {
                        sn = -sn;
                    }
                    while (sn) {
                        *cp-- = sn % 10 + '0';
                        sn = sn / 10;
                    }
                }
                start = cp + 1;
                len = ep - cp;
                break;
            case 'u':
                if (flags & 0x40) {
                    n = (ap += 8, *(u64 *)(ap - 8));
                } else if (flags & 0x80) {
                    n = (u16)(ap += 8, *(u32 *)(ap - 8));
                } else {
                    n = (ap += 8, *(u32 *)(ap - 8));
                }
                cp = ep;
                if (n == 0) {
                    if (!(flags & 0x20) || prec != 0) {
                        *cp-- = '0';
                    }
                } else {
                    do {
                        *cp-- = n % 10 + '0';
                        n = n / 10;
                    } while (n);
                }
                start = cp + 1;
                len = ep - cp;
                break;
            case 'e':
            case 'f':
                f = (ap += 8, *(double *)(ap - 8));
                if (f == 0.0f) {
                    cnt += put(cookie, &arg3, '0');
                } else {
                    cnt += func_00120730(put, cookie, &arg3, f);
                }
                goto next;
            case 's': {
                char *str = (ap += 8, *(char **)(ap - 8));

                if (str == 0) {
                    put(cookie, &arg3, '(');
                    put(cookie, &arg3, 'n');
                    put(cookie, &arg3, 'u');
                    put(cookie, &arg3, 'l');
                    put(cookie, &arg3, 'l');
                    put(cookie, &arg3, ')');
                    goto next;
                }
                cp = str;
                if (flags & 0x20) {
                    for (i = 0; i < prec && *cp++; i++) {
                    }
                    len = i;
                } else {
                    len = 0;
                    while (*cp) {
                        cp++;
                        len++;
                    }
                }
                start = str;
                break;
            }
            case 'c':
                cp = ep;
                n = (char)(ap += 8, *(s32 *)(ap - 8));
                flags |= 0x100;
                prec = 1;
                *cp-- = n;
                start = cp + 1;
                len = ep - cp;
                break;
            case 'p':
                n = (ap += 8, *(u32 *)(ap - 8));
                tab = D_00150880;
                cp = ep;
                if (n == 0) {
                    if (!(flags & 0x20) || prec != 0) {
                        *cp-- = '0';
                    }
                } else {
                    do {
                        *cp-- = tab[(s32)(n & 0xF)];
                        n >>= 4;
                    } while (n);
                }
                pre[0] = '0';
                pre[1] = 'x';
                start = cp + 1;
                len = ep - cp;
                prelen = 2;
                break;
            default:
                if (*fmt == 0) goto next;
                cp = ep;
                flags |= 0x100;
                prec = 1;
                *cp-- = *fmt;
                start = cp + 1;
                len = ep - cp;
                break;
            }

            if (len < prec) {
                prec -= len;
            } else {
                prec = 0;
            }
            width = width - len - prelen - prec;
            cp = start + len;
            if (flags & 0x100) {
                padc = ((flags & 4) && width > 0) ? '0' : ' ';
            } else {
                padc = ((flags & 0x24) == 4 && width > 0) ? '0' : ' ';
            }
            if (flags & 1) {
                for (i = 0; i < prelen; i++) cnt += put(cookie, &arg3, pre[i]);
                for (i = 0; i < prec; i++) cnt += put(cookie, &arg3, '0');
                while (start < cp) cnt += put(cookie, &arg3, *start++);
                for (i = 0; i < width; i++) cnt += put(cookie, &arg3, ' ');
            } else if (flags & 4) {
                if (padc == '0') {
                    for (i = 0; i < prelen; i++) cnt += put(cookie, &arg3, pre[i]);
                    for (i = 0; i < width; i++) cnt += put(cookie, &arg3, padc);
                } else {
                    for (i = 0; i < width; i++) cnt += put(cookie, &arg3, padc);
                    for (i = 0; i < prelen; i++) cnt += put(cookie, &arg3, pre[i]);
                }
                for (i = 0; i < prec; i++) cnt += put(cookie, &arg3, '0');
                while (start < cp) cnt += put(cookie, &arg3, *start++);
            } else {
                for (i = 0; i < width; i++) cnt += put(cookie, &arg3, padc);
                for (i = 0; i < prelen; i++) cnt += put(cookie, &arg3, pre[i]);
                for (i = 0; i < prec; i++) cnt += put(cookie, &arg3, '0');
                while (start < cp) cnt += put(cookie, &arg3, *start++);
            }
        } else if (*fmt != 0) {
            cnt += put(cookie, &arg3, *fmt);
        }
    next:
        if (*fmt) fmt++;
    }
    put(cookie, &arg3, 0);
    return cnt;
}
/* localdecomp:end func_00120908 */
