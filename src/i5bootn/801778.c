#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 8010A8.c's earlier functions (tools/port_from_us.py) */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);
extern int func_008014A0(int);
typedef int (*putc_fn_8015A0)(void *, int *, int);
extern int func_008024B8_008015A0(void *, void *, int *, const char *, ...);
extern int func_00801510_008015A0(unsigned long);

/* localdecomp:start func_00801778 */
/* Sony 2.9-ee library code: the printf core behind func_008024B8 and func_00802508. out is
   called with ctx, &size and each character. Three things here look odd but are what gives
   retail's code:
   - The loop test reads *fmt into t and copies it to c in one expression, with the first read
     of c before the loop and a statement in between (cse keeps t for the test and for ch).
   - After a conversion or a plain character the next character is re-read at "reload:", which
     is written inside the 'e'/'f' case where retail has that block; the paths that already
     have it in c (an unknown conversion character of 0, a field width that ran into the end
     of the string) go to "next:" directly.
   - In the default case an empty asm on c keeps gcc's global copy propagation from replacing
     ch with c there (retail tests ch, the copy made before the switch). It emits nothing. */
typedef int (*putc_fn_801778)(void *, int *, int);
typedef char *va_list_801778;
extern int func_008015A0(putc_fn_801778, void *, int *, double);
#define VA_ARG_801778(ap, T) (*(T *)((ap += 8) - 8))
#define ISDIGIT_801778(c) ((unsigned)((unsigned char)(c) - '0') < 10)

int func_00801778(putc_fn_801778 out, void *ctx, int size, const unsigned char *fmt, va_list_801778 ap) {
    char buf[32];
    char pfx[32];
    char *bufend;
    int width;
    int plen;
    int count;
    char *cp;
    char *start;
    char *digits;
    int flags;
    int prec;
    int len;
    int i;
    int n;
    int t;
    unsigned char c;
    int ch;
    char pad;
    unsigned long uv;
    long sv;
    float f;
    char *s;

    bufend = &buf[31];
    c = *fmt;
    count = 0;
    for (; (t = c) != 0; t = c = *fmt) {
        flags = 0;
        width = 0;
        prec = 0;
        plen = 0;
        ch = (char)t;

        if (ch == '%') {
        again:
            c = *++fmt;
            ch = c;
            switch ((char)c) {
            case '-':
                flags |= 1;
                goto again;
            case '+':
                flags |= 2;
                goto again;
            case '0':
                flags |= 4;
                goto again;
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                i = 0;
                do {
                    i = i * 10 + ((char)c - '0');
                    c = *++fmt;
                } while (ISDIGIT_801778(c));
                width = i;
            check:
                if (c == 0)
                    goto next;
                fmt--;
                goto again;
            case '.':
                fmt++;
                flags |= 0x20;
                n = *(char *)fmt;
                c = *fmt;
                if (n == '*') {
                    i = VA_ARG_801778(ap, int);
                    prec = i < 0 ? -1 : i;
                    goto again;
                }

                i = 0;
                while (ISDIGIT_801778(c)) {
                    i = i * 10 + ((char)c - '0');
                    c = *++fmt;
                }
                prec = i < 0 ? -1 : i;
                goto check;
            case ' ':
                flags |= 8;
                goto again;
            case '#':
                flags |= 0x10;
                goto again;
            case 'l':
                flags |= 0x40;
                goto again;
            case 'h':
                flags |= 0x80;
                goto again;
            case 'o':
                if (flags & 0x40)
                    uv = VA_ARG_801778(ap, unsigned long);
                else if (flags & 0x80)
                    uv = VA_ARG_801778(ap, unsigned short);
                else
                    uv = VA_ARG_801778(ap, unsigned int);
                cp = bufend;
                if (uv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = (uv & 7) + '0';
                        uv >>= 3;
                    }
                    if (flags & 0x10)
                        *cp-- = '0';
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'x':
                digits = "0123456789abcdef";
                if (flags & 0x10) {
                    pfx[0] = '0';
                    pfx[1] = 'x';
                    plen = 2;
                }
                goto hex;
            case 'X':
                digits = "0123456789ABCDEF";
                if (flags & 0x10) {
                    pfx[0] = '0';
                    pfx[1] = 'X';
                    plen = 2;
                }
            hex:
                if (flags & 0x40)
                    uv = VA_ARG_801778(ap, unsigned long);
                else if (flags & 0x80)
                    uv = VA_ARG_801778(ap, unsigned short);
                else
                    uv = VA_ARG_801778(ap, unsigned int);
                cp = bufend;
                if (uv == 0) {
                    plen = 0;
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = digits[uv & 0xF];
                        uv >>= 4;
                    }
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'd':
            case 'i':
                if (flags & 0x40)
                    sv = VA_ARG_801778(ap, long);
                else if (flags & 0x80)
                    sv = VA_ARG_801778(ap, short);
                else
                    sv = VA_ARG_801778(ap, int);
                cp = bufend;
                if (sv >= 0) {
                    if (flags & 2) {
                        pfx[0] = '+';
                        plen = 1;
                    } else if (flags & 8) {
                        pfx[0] = ' ';
                        plen = 1;
                    }
                } else {
                    pfx[0] = '-';
                    plen = 1;
                }
                if (sv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    if (sv < 0)
                        sv = -sv;
                    while (sv) {
                        *cp-- = sv % 10 + '0';
                        sv /= 10;
                    }
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'u':
                if (flags & 0x40)
                    uv = VA_ARG_801778(ap, unsigned long);
                else if (flags & 0x80)
                    uv = VA_ARG_801778(ap, unsigned short);
                else
                    uv = VA_ARG_801778(ap, unsigned int);
                cp = bufend;
                if (uv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = uv % 10 + '0';
                        uv /= 10;
                    }
                }
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'e':
            case 'f':
                f = VA_ARG_801778(ap, double);
                if (f == 0.0f)
                    count += out(ctx, &size, '0');
                else
                    count += func_008015A0(out, ctx, &size, f);
            reload:
                c = *fmt;
                goto next;
            case 's':
                s = VA_ARG_801778(ap, char *);
                if (s == 0) {
                    out(ctx, &size, '(');
                    out(ctx, &size, 'n');
                    out(ctx, &size, 'u');
                    out(ctx, &size, 'l');
                    out(ctx, &size, 'l');
                    out(ctx, &size, ')');
                    goto reload;
                }
                cp = s;
                if (flags & 0x20) {
                    for (i = 0; i < prec && *cp++; i++)
                        ;
                    len = i;
                } else {
                    len = 0;
                    while (*cp) {
                        cp++;
                        len++;
                    }
                }
                start = s;
                break;
            case 'c':
                uv = VA_ARG_801778(ap, char);
                flags |= 0x100;
                prec = 1;
                cp = bufend;
                *cp-- = uv;
                start = cp + 1;
                len = bufend - cp;
                break;
            case 'p':
                uv = VA_ARG_801778(ap, unsigned int);
                digits = "0123456789abcdef";
                cp = bufend;
                if (uv == 0) {
                    if (!(flags & 0x20) || prec != 0)
                        *cp-- = '0';
                } else {
                    while (uv) {
                        *cp-- = digits[uv & 0xF];
                        uv >>= 4;
                    }
                }
                pfx[0] = '0';
                pfx[1] = 'x';
                plen = 2;
                start = cp + 1;
                len = bufend - cp;
                break;
            default:
                __asm__ ("" : "+r" (c));
                if ((char)ch == 0)

                    goto next;
                flags |= 0x100;
                prec = 1;
                cp = bufend;
                *cp-- = c;
                start = cp + 1;
                len = bufend - cp;
                break;
            }
            if (len < prec) prec -= len; else prec = 0;
            cp = start + len;
            width = width - len - plen - prec;
            if (flags & 0x100) {
                pad = ' ';
                if (flags & 4)
                    pad = width > 0 ? '0' : ' ';
            } else {
                pad = ' ';
                if ((flags & 0x24) == 4)
                    pad = width > 0 ? '0' : ' ';
            }
            if (flags & 1) {
                for (i = 0; i < plen; i++)
                    count += out(ctx, &size, pfx[i]);
                for (i = 0; i < prec; i++)
                    count += out(ctx, &size, '0');
                while (start < cp)
                    count += out(ctx, &size, *start++);
                for (i = 0; i < width; i++)
                    count += out(ctx, &size, ' ');
            } else if (flags & 4) {
                if (pad == '0') {
                    for (i = 0; i < plen; i++)
                        count += out(ctx, &size, pfx[i]);
                    for (i = 0; i < width; i++)
                        count += out(ctx, &size, pad);
                } else {
                    for (i = 0; i < width; i++)
                        count += out(ctx, &size, pad);
                    for (i = 0; i < plen; i++)
                        count += out(ctx, &size, pfx[i]);
                }
                for (i = 0; i < prec; i++)
                    count += out(ctx, &size, '0');
                while (start < cp)
                    count += out(ctx, &size, *start++);
            } else {
                for (i = 0; i < width; i++)
                    count += out(ctx, &size, pad);
                for (i = 0; i < plen; i++)
                    count += out(ctx, &size, pfx[i]);
                for (i = 0; i < prec; i++)
                    count += out(ctx, &size, '0');
                while (start < cp)
                    count += out(ctx, &size, *start++);
            }
            goto reload;
        } else if (ch) {
            count += out(ctx, &size, ch);
            goto reload;
        }
    next:
        if (c)
            fmt++;
    }
    out(ctx, &size, 0);
    return count;
}
/* localdecomp:end func_00801778 */
