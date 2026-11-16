/* NTSC-U draft (Claude wave E): C of func_00120908 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 828 words differ on NTSC-U with the file's flags (NTSC-U twin "func_00120908").
 * Worker's note: Sony libc printf core (3352 B): put(cookie, &arg3, ch) callback, flags 1/2/4/8/0x10/0x20/0x40/0x80/0x100, width/precision parse, o x X p d i u e f s c conversions, common pad/prefix/zeros/digits tail; calls func_00120730 for %e/%f. NOT matched: 828 diff with ...
 */
#include "common.h"

/* localdecomp:start func_00120908 */
extern char D_00150880[];
extern char D_00150898[];
extern long func_001278E0();
extern long func_001260F0();
extern unsigned long func_00128580();
extern unsigned long func_00127FB0();
extern float func_00129728();
extern double func_00129A18();

#define PUT(c) (cnt += put(cookie, &arg3, (c)))
#define PAD(n, c) do { for (i = (n); i > 0; i--) PUT(c); } while (0)

s32 func_00120908(Out_00120730 put, s32 cookie, s32 arg3, char *fmt, char *ap)
{
    char buf[32];
    char pre[2];
    int cnt = 0;
    int flags, width, prec, prelen, i, len, zeros;
    int ch, padc;
    char *cp, *ep, *start, *nfmt;
    unsigned long n;
    long sn;
    int ladj, notnum;
    int w;

    if (*fmt == 0) goto done;
    for (;;) {
        ch = *(unsigned char *)fmt;
        flags = 0; width = 0; prec = 0; prelen = 0;
        if ((char)ch != '%') {
            if ((char)ch == 0) goto next0;
            nfmt = fmt + 1;
            cnt += put(cookie, &arg3, (char)ch);
            goto cont;
        }
        for (;;) {
            fmt++;
            ch = *(unsigned char *)fmt;
            switch ((char)ch) {
            case ' ': flags |= 8; continue;
            case '#': flags |= 0x10; continue;
            case '+': flags |= 2; continue;
            case '-': flags |= 1; continue;
            case '0': flags |= 4; continue;
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                w = 0;
                do {
                    w = w * 10 + ((char)ch - '0');
                    fmt++;
                    ch = *(unsigned char *)fmt;
                } while ((unsigned)(ch - '0') < 10);
                width = w;
                goto redo;
            case '.':
                fmt++;
                flags |= 0x20;
                if (*fmt == '*') {
                    ap += 8;
                    w = *(int *)(ap - 8);
                    prec = -1;
                    if (w > -2) prec = w;
                    continue;
                }
                ch = *(unsigned char *)fmt;
                w = 0;
                if ((unsigned)(ch - '0') < 10) {
                    do {
                        w = w * 10 + ((char)ch - '0');
                        fmt++;
                        ch = *(unsigned char *)fmt;
                    } while ((unsigned)(ch - '0') < 10);
                }
                prec = -1;
                if (w > -2) prec = w;
                goto redo;
            case 'l': flags |= 0x40; continue;
            case 'h': flags |= 0x80; continue;
            case 'o':
                if (flags & 0x40) { ap += 8; n = *(unsigned long *)(ap - 8); }
                else if (flags & 0x80) { ap += 8; n = *(unsigned short *)(ap - 8); }
                else { ap += 8; n = *(unsigned int *)(ap - 8); }
                ep = &buf[31];
                cp = ep;
                if (n == 0) {
                    if ((flags & 0x20) && prec == 0) { ; } else { *cp-- = '0'; }
                } else {
                    do { *cp-- = (n & 7) + '0'; n >>= 3; } while (n);
                    if (flags & 0x10) *cp-- = '0';
                }
                nfmt = fmt + 1;
                start = cp + 1;
                len = ep - cp;
                goto emit;
            case 'x': case 'X': case 'p':
                {
                    char *tab = D_00150880;
                    if ((char)ch == 'X') tab = D_00150898;
                    if ((char)ch != 'p' && (flags & 0x10)) { pre[0] = '0'; pre[1] = (char)ch; prelen = 2; }
                    if (flags & 0x40) { ap += 8; n = *(unsigned long *)(ap - 8); }
                    else if (flags & 0x80) { ap += 8; n = *(unsigned short *)(ap - 8); }
                    else { ap += 8; n = *(unsigned int *)(ap - 8); }
                        ep = &buf[31];
                cp = ep;
                    if (n == 0) {
                        if ((flags & 0x20) && prec == 0) { ; } else { *cp-- = '0'; }
                    } else {
                        do { *cp-- = tab[n & 0xF]; n >>= 4; } while (n);
                    }
                    nfmt = fmt + 1;
                    start = cp + 1;
                    len = ep - cp;
                    goto emit;
                }
            case 'd': case 'i':
                if (flags & 0x40) { ap += 8; sn = *(long *)(ap - 8); }
                else if (flags & 0x80) { ap += 8; sn = *(short *)(ap - 8); }
                else { ap += 8; sn = *(int *)(ap - 8); }
                if (sn >= 0) {
                    if (flags & 2) { pre[0] = '+'; prelen = 1; }
                    else if (flags & 8) { pre[0] = ' '; prelen = 1; }
                } else {
                    pre[0] = '-'; prelen = 1;
                }
                ep = &buf[31];
                cp = ep;
                if (sn == 0) {
                    if ((flags & 0x20) && prec == 0) { ; } else { *cp-- = '0'; }
                } else {
                    if (sn < 0) sn = -sn;
                    do { *cp-- = func_001278E0(sn, 10) + '0'; sn = func_001260F0(sn, 10); } while (sn);
                }
                nfmt = fmt + 1;
                start = cp + 1;
                len = ep - cp;
                goto emit;
            case 'u':
                if (flags & 0x40) { ap += 8; n = *(unsigned long *)(ap - 8); }
                else if (flags & 0x80) { ap += 8; n = *(unsigned short *)(ap - 8); }
                else { ap += 8; n = *(unsigned int *)(ap - 8); }
                ep = &buf[31];
                cp = ep;
                if (n == 0) {
                    if ((flags & 0x20) && prec == 0) { ; } else { *cp-- = '0'; }
                } else {
                    do { *cp-- = func_00128580(n, 10) + '0'; n = func_00127FB0(n, 10); } while (n);
                }
                nfmt = fmt + 1;
                start = cp + 1;
                len = ep - cp;
                goto emit;
            case 'e': case 'f':
                {
                    float f;
                    ap += 8;
                    f = func_00129728(*(double *)(ap - 8));
                    nfmt = fmt + 1;
                    if (f == 0.0f) {
                        cnt += put(cookie, &arg3, '0');
                    } else {
                        cnt += func_00120730(put, cookie, &arg3, func_00129A18(f));
                    }
                    goto next;
                }
            case 's':
                ap += 8;
                cp = *(char **)(ap - 8);
                if (cp == 0) {
                    nfmt = fmt + 1;
                    put(cookie, &arg3, '(');
                    put(cookie, &arg3, 'n');
                    put(cookie, &arg3, 'u');
                    put(cookie, &arg3, 'l');
                    put(cookie, &arg3, 'l');
                    put(cookie, &arg3, ')');
                    goto next;
                }
                nfmt = fmt + 1;
                start = cp;
                if (flags & 0x20) {
                    len = 0;
                    if (prec > 0) {
                        while (*cp++) {
                            if (++len >= prec) break;
                        }
                    }
                } else {
                    len = 0;
                    while (*cp) { cp++; len++; }
                }
                goto emit;
            case 'c':
                ap += 8;
                buf[31] = *(char *)(ap - 8);
                flags |= 0x100;
                prec = 1;
                nfmt = fmt + 1;
                ep = &buf[31];
                start = ep;
                len = 1;
                goto emit;
            default:
                if ((char)ch == 0) { nfmt = fmt + 1; goto next0; }
                flags |= 0x100;
                prec = 1;
                nfmt = fmt + 1;
                buf[31] = (char)ch;
                start = &buf[31];
                len = 1;
                goto emit;
            }
        redo:
            if (ch == 0) { nfmt = fmt + 1; goto next0; }
            fmt--;
        }
    emit:
        ladj = flags & 1;
        notnum = flags & 0x100;
        zeros = prec > len ? prec - len : 0;
        i = width - len - prelen - zeros;
        width = i;
        padc = ' ';
        if (notnum) {
            if (flags & 4) padc = i > 0 ? '0' : ' ';
        } else if ((flags & 0x24) == 4) {
            padc = i > 0 ? '0' : ' ';
        }
        if (ladj) {
            for (i = 0; i < prelen; i++) PUT(pre[i]);
            PAD(zeros, '0');
            for (cp = start; cp < start + len; cp++) PUT(*cp);
            PAD(width, ' ');
        } else if (flags & 4) {
            if (padc == '0') {
                for (i = 0; i < prelen; i++) PUT(pre[i]);
                PAD(width, padc);
                PAD(zeros, '0');
            } else {
                PAD(width, padc);
                for (i = 0; i < prelen; i++) PUT(pre[i]);
                PAD(zeros, '0');
            }
            for (cp = start; cp < start + len; cp++) PUT(*cp);
        } else {
            PAD(width, padc);
            for (i = 0; i < prelen; i++) PUT(pre[i]);
            PAD(zeros, '0');
            for (cp = start; cp < start + len; cp++) PUT(*cp);
        }
    next:
        ch = *(unsigned char *)fmt;
    next0:
    cont:
        if (ch) fmt = nfmt;
        ch = *(unsigned char *)fmt;
        if (ch == 0) break;
    }
done:
    put(cookie, &arg3, 0);
    return cnt;
}
/* localdecomp:end func_00120908 */
