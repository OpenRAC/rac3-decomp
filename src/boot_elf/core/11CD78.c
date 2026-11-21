#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 116F80.c's earlier functions */
extern void func_0011B240(s32);
extern void func_0013AFE8(s32) __attribute__((noreturn));

typedef struct Reent_116F98 {
    u8 pad0[0xC];
    void *err;
} Reent_116F98;
extern void *D_0013D770[];
extern char D_00150080[];
extern s32 func_00118950(void *, char *, ...);
extern void func_00116F80(void);

typedef struct At_116FD0 {
    struct At_116FD0 *next;
    s32 ind;
    void (*fns[32])(void);
} At_116FD0;
typedef struct {
    u8 pad148[0x148];
    At_116FD0 *atexit;
    At_116FD0 atexit0;
} Reent_116FD0;
extern void *D_0013D770[];
extern void *func_001194E8(u32);

extern long func_0011BFD8(s32, s32, s32);

extern s32 func_0011A160();

typedef struct Bigint_1171C8 {
    struct Bigint_1171C8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_1171C8;
extern s32 func_0011ABB8(Bigint_1171C8 *, Bigint_1171C8 *);

/* func_00118660: returns the global pointer stored at D_0013D770.
   Retail reaches D_0013D770 through lui/%lo, so the global is declared as an
   unsized array (never small data) and read at offset 0. */

extern void *D_0013D770[];

typedef struct Reent_00118720 {
    u8 pad0[0x38];
    void *cleanup;
} Reent_00118720;
typedef struct File_00118720 {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    s32 lbfsize;
    void *cookie;
    void *read;
    s32 (*write)(void *, u8 *, s32);
    void *seek;
    void *close;
    u8 pad30[0x24];
    Reent_00118720 *data;
} File_00118720;
extern void *D_0013D770[];
extern void func_001188C0(Reent_00118720 *);
extern s32 func_00119258(void *, void *);

typedef struct { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *read; void *write; void *seek; void *close; u8 pad[0x24]; void *data; } F_118838;
extern s32 func_0011B378();
extern s32 func_0011B3E0();
extern long func_0011B460();
extern s32 func_0011B4C8();

extern s32 func_00118720(File_00118720 *);

extern s32 func_0011C108();

typedef struct Chunk_001189B0 {
    u32 prev_size;
    u32 size;
    struct Chunk_001189B0 *fd;
    struct Chunk_001189B0 *bk;
} Chunk_001189B0;
extern Chunk_001189B0 *D_0013D778[];
extern unsigned long D_0013DB80;
extern unsigned long D_0013DB88;
extern void func_0011A328(void *);
extern void func_0011A3A8(void *);
extern s32 func_00118CA8(void *, u32);

extern s32 func_0011F5A8();
extern s32 D_1D48C0[];

typedef struct {
    u8 *base;
    u32 len;
} Iov_118E78;
typedef struct {
    Iov_118E78 *iov;
    s32 iovcnt;
    s32 resid;
} Uio_118E78;
typedef struct {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    s32 lbfsize;
    void *cookie;
    void *read;
    s32 (*write)(void *, u8 *, s32);
} F_118E78;
extern s32 func_0011E8C0(F_118E78 *);
extern u8 *func_00119F3C(u8 *, s32, u32);

typedef struct {
    u8 pad0[0xC];
    s16 flags;
    u8 padE[0x58 - 0xE];
} F_119258;
typedef struct G_119258 {
    struct G_119258 *next;
    s32 niobs;
    F_119258 *iobs;
} G_119258;
typedef struct {
    u8 pad0[0x1D8];
    G_119258 glue;
} R_119258;

extern void *D_0013D770[];
extern void *func_001192F8(void *);

extern long func_0011B460();
typedef struct {
    u8 pad0[0x3C];
    void *cleanup;
} R_119390;
typedef struct {
    u8 *p;
    s32 r;
    s32 w;
    u16 flags;
    s16 file;
    u8 *base;
    s32 size;
    s32 lbfsize;
    void *cookie;
    void *read;
    void *write;
    void *seek;
    void *close;
    u8 pad30[0x40 - 0x30];
    u8 ubuf[3];
    u8 nbuf[1];
    u8 pad44[0x4C - 0x44];
    s32 blksize;
    s32 offset;
    R_119390 *data;
} F_119390;
typedef struct {
    s16 st_dev;
    u16 st_ino;
    u32 st_mode;
    u8 rest[0x70 - 8];
} St_119390;
extern s32 func_00118E18();
extern void *func_001197E0();
extern void func_00118898();
extern s32 func_0011F5A0();

extern void *D_0013D770[];
extern void func_0011A328(void *);
extern void *func_001197E0(void *, u32);
extern void func_0011A3A8(void *);

extern void func_0011A328();
extern void func_001189B0();
extern void func_0011A3A8();

extern s32 D_0013DBD0;
extern s32 D_0013DBD4;
extern s32 D_0013E310;
extern s32 func_0011ED10(void);
extern void func_0011EE60(s32);

extern s32 D_0013DBD0;
extern s32 D_0013DBD4;
extern s32 D_0013E310;
extern void func_0011EE40(s32);

typedef struct Big_11A3F8 {
    struct Big_11A3F8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11A3F8;
typedef struct {
    u8 pad[0x4C];
    Big_11A3F8 **freelist;
} Reent_11A3F8;
extern void *func_001170B8();

typedef struct N_11A4A0 { struct N_11A4A0 *next; s32 idx; } N_11A4A0;
typedef struct { u8 pad[0x4C]; N_11A4A0 **tab; } S_11A4A0;

typedef struct Big_11A718 {
    struct Big_11A718 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11A718;
extern void *func_0011A3F8();

typedef struct Bigint_0011A750 {
    struct Bigint_0011A750 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_0011A750;
extern void *func_0011A3F8();

typedef struct Bigint_0011AA60 {
    struct Bigint_0011AA60 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_0011AA60;
extern void *func_0011A3F8();
extern void func_0011A4A0();

typedef struct Bigint_0011AC20 {
    struct Bigint_0011AC20 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_0011AC20;
extern s32 func_0011ABB8();
extern void *func_0011A3F8();

typedef struct Big_11ADB0 {
    struct Big_11ADB0 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11ADB0;
typedef union {
    double d;
    u32 L[2];
} Dbl_11ADB0;

typedef struct Reent_11AF48 {
    u8 pad0[8];
    F_118838 *out;
} Reent_11AF48;
typedef __builtin_va_list va_list_11AF48;
extern void *D_0013D770[];
extern s32 func_0011CE78(F_118838 *, const char *, va_list_11AF48);

extern s32 D_1D48C0[];
extern s32 func_0011F468();

typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} Dbl_11B018;

typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} Dbl_11B060;

extern s32 func_0011F4F0();
extern s32 D_1D48C0[];

typedef struct {
    u8 pad0[0x1D4];
    u32 *freelist;
} R_11B0F8;
extern void *func_001197E0();

typedef void (*SigFn_11B168)(s32);
typedef struct {
    s32 err;
    u8 pad4[0x1D0];
    SigFn_11B168 *sig_func;
} Reent_11B168;
extern s32 func_0011B0F8();
extern s32 func_0011B2D0(void *);
extern s32 func_0011B270(s32 *, s32, s32);

extern s32 func_0011B168(void *, s32);

extern s32 func_0011F5C8(s32, s32);
extern s32 D_1D48C0[];

extern s32 func_0011F5C0(void);

typedef struct {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    u8 pad18[0x54 - 0x18];
    void *data;
} F_11B2E8;
extern void *D_0013D770[];
extern s32 func_0011CE78();

typedef struct {
    u8 pad0[0xC];
    u16 flags;
    s16 file;
    u8 pad10[0x40];
    s32 off;
    void *reent;
} F_11B378;
extern long func_0011AFB8(void *, s32, void *, s32);

typedef struct {
    u8 pad0[0xC];
    u16 flags;
    s16 file;
    u8 pad10[0x44];
    void *reent;
} F_11B3E0;
extern long func_00119330(void *, s32, s32, s32);
extern long func_0011E860(void *, s32, char *, s32);

extern s32 func_00117170(void *, s32);

extern void *D_0013D770[];
extern long func_0011BDA0(void *, s32, s32, s32);

extern s32 func_0011C180(void *, F_118838 *, const char *, va_list_11AF48);

extern void *D_0013D770[];
extern s32 D_0013D774[];
extern char D_00150390[];
extern char D_001503A0[];
extern char D_001503B0[];
extern char D_001503C8[];
extern char D_001503D0[];
extern char D_001503E8[];
extern s32 func_0011C050();
extern s32 func_0011B868();

/* localdecomp:start func_0011CD78 */
s32 func_0011CD78(F_118E78 *a, Uio_118E78 *p) {
    s32 r;
    if (p->resid == 0) {
        p->iovcnt = 0;
        return 0;
    }
    r = func_00118E78(a, p);
    p->resid = 0;
    p->iovcnt = 0;
    return r;
}
/* localdecomp:end func_0011CD78 */

/* localdecomp:start func_0011CDC0 */
typedef struct Sbuf_0011CDC0 {
    u8 *_base;
    int _size;
} Sbuf_0011CDC0;
typedef struct File_0011CDC0 {
    u8 *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    Sbuf_0011CDC0 _bf;
    int _lbfsize;
    void *_cookie;
    int (*_read)();
    int (*_write)();
    int (*_seek)();
    int (*_close)();
    Sbuf_0011CDC0 _ub;
    u8 *_up;
    int _ur;
    u8 _ubuf[3];
    u8 _nbuf[1];
    Sbuf_0011CDC0 _lb;
    int _blksize;
    int _offset;
    Reent_00118720 *_data;
} File_0011CDC0;

s32 func_0011CDC0(File_0011CDC0 *fp, const char *fmt, va_list_11AF48 ap)
{
    s32 ret;
    File_0011CDC0 fake;
    u8 buf[1024];

    fake._data = fp->_data;
    fake._flags = fp->_flags & ~2;
    fake._file = fp->_file;
    fake._cookie = fp->_cookie;
    fake._write = fp->_write;
    fake._bf._base = fake._p = buf;
    fake._bf._size = fake._w = sizeof(buf);
    fake._lbfsize = 0;
    ret = func_0011CE78((F_118838 *)&fake, fmt, ap);
    if (ret >= 0 && func_00118720((File_00118720 *)&fake)) {
        ret = -1;
    }
    if (fake._flags & 0x40) {
        fp->_flags |= 0x40;
    }
    return ret;
}
/* localdecomp:end func_0011CDC0 */

/* localdecomp:start func_0011CE78 */
extern s32 func_0011CEF0(void *, F_118838 *, const char *, va_list_11AF48);

s32 func_0011CE78(F_118838 *fp, const char *fmt, va_list_11AF48 ap)
{
    do {
        if (fp->data == 0) {
            fp->data = D_0013D770[0];
        }
        if (((Reent_00118720 *)fp->data)->cleanup == 0) {
            func_001188C0(fp->data);
        }
    } while (0);
    return func_0011CEF0(fp->data, fp, fmt, ap);
}
/* localdecomp:end func_0011CE78 */

/* localdecomp:start func_0011CEF0 */
extern char D_00150580[];
extern char D_00150590[];
extern char D_001505A0[];
extern char D_001505A8[];
extern char D_001505B0[];
extern char D_001505C8[];
extern char D_001505D0[];
extern char D_001505E8[];
extern char D_00150608[];
extern char D_00150610[];

s32 func_0011CEF0(void *data, F_118838 *fp, const char *fmt0, va_list_11AF48 ap)
{
    extern void *func_00119310(void);
    extern s32 func_00119F08();
    extern s32 func_0011B868();
    extern s32 func_0011B018(double);
    extern s32 func_0011B060(double);
    extern char *func_0011E560(void *, double, s32, s32, char *, s32 *, s32, s32 *);
    extern s32 func_0011E720(char *, s32, s32);
    extern u64 func_00128580();
    extern u64 func_00127FB0();
    char *fmt;
    s32 ch;
    s32 n;
    s32 m;
    char *cp;
    Iov_118E78 *iovp;
    s32 flags;
    s32 ret;
    s32 width;
    s32 prec;
    char softsign;
    char sign;
    s32 wc;
    s32 state;
    char *decimal_point;
    double _double;
    s32 expt;
    s32 expsize;
    s32 ndig;
    char expstr[7];
    u64 uquad;
    enum { OCT, DEC, HEX } base;
    s32 dprec;
    s32 realsz;
    s32 size;
    char *xdigs;
    Uio_118E78 uio;
    Iov_118E78 iov[8];
    char buf[348];
    char ox[2];

    decimal_point = *(char **)func_00119310();
    state = 0;
    if (!(fp->flags & 8) || fp->base == 0) {
        if (func_0011E8C0((F_118E78 *)fp)) {
            return -1;
        }
    }
    if ((fp->flags & 0x1A) == 0xA && fp->file >= 0) {
        return func_0011CDC0((File_0011CDC0 *)fp, fmt0, ap);
    }
    fmt = (char *)fmt0;
    uio.iov = iovp = iov;
    uio.resid = 0;
    uio.iovcnt = 0;
    ret = 0;
    for (;;) {
        cp = fmt;
        while ((n = func_00119F08(D_0013D770[0], &wc, fmt, D_0013D774[0], &state)) > 0) {
            fmt += n;
            if (wc == '%') {
                fmt--;
                break;
            }
        }
        if ((m = fmt - cp) != 0) {
            {
                iovp->base = (u8 *)(cp);
                iovp->len = (m);
                uio.resid += (m);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
            ret += m;
        }
        if (n <= 0) {
            goto done;
        }
        fmt++;
        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';
rflag:
        ch = *fmt++;
reswitch:
        switch (ch) {
        case ' ':
            if (!sign) {
                sign = ' ';
            }
            goto rflag;
        case '#':
            flags |= 1;
            goto rflag;
        case '*':
            width = __builtin_va_arg(ap, s32);
            if (width >= 0) {
                goto rflag;
            }
            width = -width;
        case '-':
            flags |= 4;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *fmt++) == '*') {
                n = __builtin_va_arg(ap, s32);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while ((u32)(ch - '0') <= 9) {
                n = 10 * n + (ch - '0');
                ch = *fmt++;
            }
            prec = n < 0 ? -1 : n;
            goto reswitch;
        case '0':
            flags |= 0x80;
            goto rflag;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            n = 0;
            do {
                n = 10 * n + (ch - '0');
                ch = *fmt++;
            } while ((u32)(ch - '0') <= 9);
            width = n;
            goto reswitch;
        case 'L':
            flags |= 8;
            goto rflag;
        case 'h':
            flags |= 0x40;
            goto rflag;
        case 'l':
            if (*fmt == 'l') {
                fmt++;
                flags |= 0x20;
            } else {
                flags |= 0x10;
            }
            goto rflag;
        case 'q':
            flags |= 0x20;
            goto rflag;
        case 'c':
            cp = buf;
            *cp = __builtin_va_arg(ap, s32);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= 0x10;
        case 'd':
        case 'i':
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, long);
            } else if (flags & 0x40) {
                uquad = (short)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, s32);
            }
            if ((long)uquad < 0) {
                uquad = -uquad;
                sign = '-';
            }
            base = DEC;
            goto number;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            if (prec == -1) {
                prec = 6;
            } else if ((ch == 'g' || ch == 'G') && prec == 0) {
                prec = 1;
            }
            if (flags & 8) {
                _double = (double)__builtin_va_arg(ap, long double);
            } else {
                _double = __builtin_va_arg(ap, double);
            }
            if (func_0011B018(_double)) {
                if (_double < 0) {
                    sign = '-';
                }
                cp = D_001505A0;
                size = 3;
                break;
            }
            if (func_0011B060(_double)) {
                cp = D_001505A8;
                size = 3;
                break;
            }
            flags |= 0x100;
            cp = func_0011E560(data, _double, prec, flags, &softsign, &expt, ch, &ndig);
            if (ch == 'g' || ch == 'G') {
                if (expt <= -4 || expt > prec) {
                    ch = (ch == 'g') ? 'e' : 'E';
                } else {
                    ch = 'g';
                }
            }
            if (ch <= 'e') {
                --expt;
                expsize = func_0011E720(expstr, expt, ch);
                size = expsize + ndig;
                if (ndig > 1 || flags & 1) {
                    ++size;
                }
            } else if (ch == 'f') {
                if (expt > 0) {
                    size = expt;
                    if (prec || flags & 1) {
                        size += prec + 1;
                    }
                } else {
                    size = prec + 2;
                }
            } else if (expt >= ndig) {
                size = expt;
                if (flags & 1) {
                    ++size;
                }
            } else {
                size = ndig + (expt > 0 ? 1 : 2 - expt);
            }
            if (softsign) {
                sign = '-';
            }
            break;
        case 'n':
            if (flags & 0x10) {
                *__builtin_va_arg(ap, long *) = ret;
            } else if (flags & 0x40) {
                *__builtin_va_arg(ap, short *) = ret;
            } else {
                *__builtin_va_arg(ap, s32 *) = ret;
            }
            continue;
        case 'O':
            flags |= 0x10;
        case 'o':
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, u64);
            } else if (flags & 0x40) {
                uquad = (u16)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, u32);
            }
            base = OCT;
            goto nosign;
        case 'p':
            uquad = (u64)(long)__builtin_va_arg(ap, void *);
            base = HEX;
            xdigs = D_001505B0;
            flags |= 2;
            ch = 'x';
            goto nosign;
        case 's':
            if ((cp = __builtin_va_arg(ap, char *)) == 0) {
                cp = D_001505C8;
            }
            if (prec >= 0) {
                char *p = (char *)func_00119F3C((u8 *)cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec) {
                        size = prec;
                    }
                } else {
                    size = prec;
                }
            } else {
                size = func_0011B868(cp);
            }
            sign = '\0';
            break;
        case 'U':
            flags |= 0x10;
        case 'u':
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, u64);
            } else if (flags & 0x40) {
                uquad = (u16)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, u32);
            }
            base = DEC;
            goto nosign;
        case 'X':
            xdigs = D_001505D0;
            goto hex;
        case 'x':
            xdigs = D_001505B0;
hex:
            if (flags & 0x10) {
                uquad = __builtin_va_arg(ap, u64);
            } else if (flags & 0x40) {
                uquad = (u16)__builtin_va_arg(ap, s32);
            } else {
                uquad = __builtin_va_arg(ap, u32);
            }
            base = HEX;
            if (flags & 1 && uquad != 0) {
                flags |= 2;
            }
nosign:
            sign = '\0';
number:
            if ((dprec = prec) >= 0) {
                flags &= ~0x80;
            }
            cp = buf + 348;
            if (uquad != 0 || prec != 0) {
                switch (base) {
                case OCT:
                    do {
                        *--cp = (uquad & 7) + '0';
                        uquad >>= 3;
                    } while (uquad);
                    if (flags & 1 && *cp != '0') {
                        *--cp = '0';
                    }
                    break;
                case DEC:
                    while (uquad >= 10) {
                        *--cp = func_00128580(uquad, 10) + '0';
                        uquad = func_00127FB0(uquad, 10);
                    }
                    *--cp = uquad + '0';
                    break;
                case HEX:
                    do {
                        *--cp = xdigs[uquad & 15];
                        uquad >>= 4;
                    } while (uquad);
                    break;
                default:
                    cp = D_001505E8;
                    size = func_0011B868(cp);
                    goto skipsize;
                }
            }
            size = buf + 348 - cp;
skipsize:
            break;
        default:
            if (ch == '\0') {
                goto done;
            }
            cp = buf;
            *cp = ch;
            size = 1;
            sign = '\0';
            break;
        }
        realsz = dprec > size ? dprec : size;
        if (sign) {
            realsz++;
        } else if (flags & 2) {
            realsz += 2;
        }
        if ((flags & 0x84) == 0) {
            if ((n = (width - realsz)) > 0) {
                while (n > 16) {
                    {
                        iovp->base = (u8 *)(D_00150580);
                        iovp->len = (16);
                        uio.resid += (16);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    n -= 16;
                }
                {
                    iovp->base = (u8 *)(D_00150580);
                    iovp->len = (n);
                    uio.resid += (n);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        if (sign) {
            {
                iovp->base = (u8 *)(&sign);
                iovp->len = (1);
                uio.resid += (1);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        } else if (flags & 2) {
            ox[0] = '0';
            ox[1] = ch;
            {
                iovp->base = (u8 *)(ox);
                iovp->len = (2);
                uio.resid += (2);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        }
        if ((flags & 0x84) == 0x80) {
            if ((n = (width - realsz)) > 0) {
                while (n > 16) {
                    {
                        iovp->base = (u8 *)(D_00150590);
                        iovp->len = (16);
                        uio.resid += (16);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    n -= 16;
                }
                {
                    iovp->base = (u8 *)(D_00150590);
                    iovp->len = (n);
                    uio.resid += (n);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        if ((n = (dprec - size)) > 0) {
            while (n > 16) {
                {
                    iovp->base = (u8 *)(D_00150590);
                    iovp->len = (16);
                    uio.resid += (16);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
                n -= 16;
            }
            {
                iovp->base = (u8 *)(D_00150590);
                iovp->len = (n);
                uio.resid += (n);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        }
        if ((flags & 0x100) == 0) {
            {
                iovp->base = (u8 *)(cp);
                iovp->len = (size);
                uio.resid += (size);
                iovp++;
                if (++uio.iovcnt >= 8) {
                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                        goto error;
                    }
                    iovp = iov;
                }
            }
        } else {
            if (ch >= 'f') {
                if (_double == 0) {
                    {
                        iovp->base = (u8 *)(D_00150608);
                        iovp->len = (1);
                        uio.resid += (1);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    if (expt < ndig || (flags & 1) != 0) {
                        {
                            iovp->base = (u8 *)(decimal_point);
                            iovp->len = (1);
                            uio.resid += (1);
                            iovp++;
                            if (++uio.iovcnt >= 8) {
                                if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                    goto error;
                                }
                                iovp = iov;
                            }
                        }
                        if ((n = (ndig - 1)) > 0) {
                            while (n > 16) {
                                {
                                    iovp->base = (u8 *)(D_00150590);
                                    iovp->len = (16);
                                    uio.resid += (16);
                                    iovp++;
                                    if (++uio.iovcnt >= 8) {
                                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                            goto error;
                                        }
                                        iovp = iov;
                                    }
                                }
                                n -= 16;
                            }
                            {
                                iovp->base = (u8 *)(D_00150590);
                                iovp->len = (n);
                                uio.resid += (n);
                                iovp++;
                                if (++uio.iovcnt >= 8) {
                                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                        goto error;
                                    }
                                    iovp = iov;
                                }
                            }
                        }
                    }
                } else if (expt <= 0) {
                    {
                        iovp->base = (u8 *)(D_00150608);
                        iovp->len = (1);
                        uio.resid += (1);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    if (expt || ndig) {
                        {
                            iovp->base = (u8 *)(decimal_point);
                            iovp->len = (1);
                            uio.resid += (1);
                            iovp++;
                            if (++uio.iovcnt >= 8) {
                                if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                    goto error;
                                }
                                iovp = iov;
                            }
                        }
                        if ((n = (-expt)) > 0) {
                            while (n > 16) {
                                {
                                    iovp->base = (u8 *)(D_00150590);
                                    iovp->len = (16);
                                    uio.resid += (16);
                                    iovp++;
                                    if (++uio.iovcnt >= 8) {
                                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                            goto error;
                                        }
                                        iovp = iov;
                                    }
                                }
                                n -= 16;
                            }
                            {
                                iovp->base = (u8 *)(D_00150590);
                                iovp->len = (n);
                                uio.resid += (n);
                                iovp++;
                                if (++uio.iovcnt >= 8) {
                                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                        goto error;
                                    }
                                    iovp = iov;
                                }
                            }
                        }
                        {
                            iovp->base = (u8 *)(cp);
                            iovp->len = (ndig);
                            uio.resid += (ndig);
                            iovp++;
                            if (++uio.iovcnt >= 8) {
                                if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                    goto error;
                                }
                                iovp = iov;
                            }
                        }
                    }
                } else if (expt >= ndig) {
                    {
                        iovp->base = (u8 *)(cp);
                        iovp->len = (ndig);
                        uio.resid += (ndig);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    if ((n = (expt - ndig)) > 0) {
                        while (n > 16) {
                            {
                                iovp->base = (u8 *)(D_00150590);
                                iovp->len = (16);
                                uio.resid += (16);
                                iovp++;
                                if (++uio.iovcnt >= 8) {
                                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                        goto error;
                                    }
                                    iovp = iov;
                                }
                            }
                            n -= 16;
                        }
                        {
                            iovp->base = (u8 *)(D_00150590);
                            iovp->len = (n);
                            uio.resid += (n);
                            iovp++;
                            if (++uio.iovcnt >= 8) {
                                if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                    goto error;
                                }
                                iovp = iov;
                            }
                        }
                    }
                    if (flags & 1) {
                        {
                            iovp->base = (u8 *)(D_00150610);
                            iovp->len = (1);
                            uio.resid += (1);
                            iovp++;
                            if (++uio.iovcnt >= 8) {
                                if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                    goto error;
                                }
                                iovp = iov;
                            }
                        }
                    }
                } else {
                    {
                        iovp->base = (u8 *)(cp);
                        iovp->len = (expt);
                        uio.resid += (expt);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    cp += expt;
                    {
                        iovp->base = (u8 *)(D_00150610);
                        iovp->len = (1);
                        uio.resid += (1);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    {
                        iovp->base = (u8 *)(cp);
                        iovp->len = (ndig - expt);
                        uio.resid += (ndig - expt);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                }
            } else {
                if (ndig > 1 || flags & 1) {
                    ox[0] = *cp++;
                    ox[1] = '.';
                    {
                        iovp->base = (u8 *)(ox);
                        iovp->len = (2);
                        uio.resid += (2);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    if (_double || flags & 1 == 0) {
                        {
                            iovp->base = (u8 *)(cp);
                            iovp->len = (ndig - 1);
                            uio.resid += (ndig - 1);
                            iovp++;
                            if (++uio.iovcnt >= 8) {
                                if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                    goto error;
                                }
                                iovp = iov;
                            }
                        }
                    } else {
                        if ((n = (ndig - 1)) > 0) {
                            while (n > 16) {
                                {
                                    iovp->base = (u8 *)(D_00150590);
                                    iovp->len = (16);
                                    uio.resid += (16);
                                    iovp++;
                                    if (++uio.iovcnt >= 8) {
                                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                            goto error;
                                        }
                                        iovp = iov;
                                    }
                                }
                                n -= 16;
                            }
                            {
                                iovp->base = (u8 *)(D_00150590);
                                iovp->len = (n);
                                uio.resid += (n);
                                iovp++;
                                if (++uio.iovcnt >= 8) {
                                    if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                        goto error;
                                    }
                                    iovp = iov;
                                }
                            }
                        }
                    }
                } else {
                    {
                        iovp->base = (u8 *)(cp);
                        iovp->len = (1);
                        uio.resid += (1);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                }
                {
                    iovp->base = (u8 *)(expstr);
                    iovp->len = (expsize);
                    uio.resid += (expsize);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        if (flags & 4) {
            if ((n = (width - realsz)) > 0) {
                while (n > 16) {
                    {
                        iovp->base = (u8 *)(D_00150580);
                        iovp->len = (16);
                        uio.resid += (16);
                        iovp++;
                        if (++uio.iovcnt >= 8) {
                            if (func_0011CD78((F_118E78 *)fp, &uio)) {
                                goto error;
                            }
                            iovp = iov;
                        }
                    }
                    n -= 16;
                }
                {
                    iovp->base = (u8 *)(D_00150580);
                    iovp->len = (n);
                    uio.resid += (n);
                    iovp++;
                    if (++uio.iovcnt >= 8) {
                        if (func_0011CD78((F_118E78 *)fp, &uio)) {
                            goto error;
                        }
                        iovp = iov;
                    }
                }
            }
        }
        ret += width > realsz ? width : realsz;
        if (uio.resid && func_0011CD78((F_118E78 *)fp, &uio)) {
            goto error;
        }
        uio.iovcnt = 0;
        iovp = iov;
    }
done:
    if (uio.resid && func_0011CD78((F_118E78 *)fp, &uio)) {
        goto error;
    }
    uio.iovcnt = 0;
    iovp = iov;
error:
    return (fp->flags & 0x40) ? -1 : ret;
}
/* localdecomp:end func_0011CEF0 */

/* localdecomp:start func_0011E560 */
typedef union {
    double d;
    struct {
        s32 lo;
        s32 hi;
    } w;
} Dbl_11E560;
extern char *func_001173F8();

char *func_0011E560(void *data, double value, s32 ndigits, s32 flags, char *sign, s32 *decpt, s32 ch, s32 *length)
{
    Dbl_11E560 u;
    s32 mode;
    s32 dsgn;
    char *digits;
    char *bp;
    char *rve;

    if (ch == 'f') {
        mode = 3;
    } else {
        if (ch == 'e' || ch == 'E') {
            ndigits++;
        }
        mode = 2;
    }
    u.d = value;
    if (u.w.hi < 0) {
        value = -value;
        *sign = '-';
    } else {
        *sign = 0;
    }
    digits = func_001173F8(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || (flags & 1)) {
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && value) {
                *decpt = -ndigits + 1;
            }
            bp += *decpt;
        }
        if (value == 0) {
            rve = bp;
        }
        while (rve < bp) {
            *rve++ = '0';
        }
    }
    *length = rve - digits;
    return digits;
}
/* localdecomp:end func_0011E560 */

/* localdecomp:start func_0011E720 */
s32 func_0011E720(char *p0, s32 exp, s32 fmtch)
{
    char *p;
    char *t;
    char expbuf[308];

    p = p0;
    *p++ = fmtch;
    if (exp < 0) {
        exp = -exp;
        *p++ = '-';
    } else {
        *p++ = '+';
    }
    t = expbuf + 308;
    if (exp > 9) {
        do {
            *--t = exp % 10 + '0';
        } while ((exp /= 10) > 9);
        *--t = exp + '0';
        for (; t < expbuf + 308; *p++ = *t++) {
        }
    } else {
        *p++ = '0';
        *p++ = exp + '0';
    }
    return p - p0;
}
/* localdecomp:end func_0011E720 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011E7FC);
