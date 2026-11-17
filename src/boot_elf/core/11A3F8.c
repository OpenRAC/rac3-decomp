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

/* localdecomp:start func_0011A3F8 */
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
void *func_0011A3F8(Reent_11A3F8 *ptr, s32 k) {
    s32 x;
    Big_11A3F8 *rv;
    if (ptr->freelist == 0) {
        ptr->freelist = (Big_11A3F8 **)func_001170B8(ptr, 4, 16);
        if (ptr->freelist == 0) {
            return 0;
        }
    }
    if ((rv = ptr->freelist[k]) != 0) {
        ptr->freelist[k] = rv->next;
    } else {
        x = 1 << k;
        rv = (Big_11A3F8 *)func_001170B8(ptr, 1, 0x18 + (x - 1) * 4);
        if (rv == 0) {
            return 0;
        }
        rv->k = k;
        rv->maxwds = x;
    }
    rv->sign = rv->wds = 0;
    return rv;
}
/* localdecomp:end func_0011A3F8 */

/* localdecomp:start func_0011A4A0 */
typedef struct N_11A4A0 { struct N_11A4A0 *next; s32 idx; } N_11A4A0;
typedef struct { u8 pad[0x4C]; N_11A4A0 **tab; } S_11A4A0;
void func_0011A4A0(S_11A4A0 *p, N_11A4A0 *n) {
    if (n != 0) {
        N_11A4A0 **f = p->tab;
        n->next = f[n->idx];
        f[n->idx] = n;
    }
}
/* localdecomp:end func_0011A4A0 */

/* localdecomp:start func_0011A4D0 */
typedef struct Big_11A4D0 {
    struct Big_11A4D0 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11A4D0;
Big_11A4D0 *func_0011A4D0(void *ptr, Big_11A4D0 *b, s32 m, s32 a) {
    extern void *func_0011A0B0();
    s32 i, wds;
    u32 *x;
    u32 xi, y, z;
    Big_11A4D0 *b1;

    wds = b->wds;
    x = b->x;
    i = 0;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + a;
        z = (xi >> 16) * m + (y >> 16);
        a = (s32)(z >> 16);
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (a) {
        if (wds >= b->maxwds) {
            b1 = (Big_11A4D0 *)func_0011A3F8(ptr, b->k + 1);
            func_0011A0B0((char *)&b1->sign, (char *)&b->sign, b->wds * sizeof(s32) + 2 * sizeof(int));
            func_0011A4A0((S_11A4A0 *)ptr, (N_11A4A0 *)b);
            b = b1;
        }
        b->x[wds++] = a;
        b->wds = wds;
    }
    return b;
}
/* localdecomp:end func_0011A4D0 */

/* localdecomp:start func_0011A5D8 */
s32 func_0011A5D8(u32 x)
{
    s32 k = 0;

    if (!(x & 0xffff0000)) {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xff000000)) {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xf0000000)) {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xc0000000)) {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000)) {
            return 32;
        }
    }
    return k;
}
/* localdecomp:end func_0011A5D8 */

/* localdecomp:start func_0011A658 */
s32 func_0011A658(u32 *y) {
    s32 k;
    u32 x = *y;
    if (x & 7) {
        if (x & 1) {
            return 0;
        }
        if (x & 2) {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xffff)) {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xff)) {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xf)) {
        k += 4;
        x >>= 4;
    }
    if (!(x & 0x3)) {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1)) {
        k++;
        x >>= 1;
        if (!x & 1) {
            return 32;
        }
    }
    *y = x;
    return k;
}
/* localdecomp:end func_0011A658 */

/* localdecomp:start func_0011A718 */
typedef struct Big_11A718 {
    struct Big_11A718 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11A718;
extern void *func_0011A3F8();
Big_11A718 *func_0011A718(void *ptr, s32 i) {
    Big_11A718 *b;
    b = (Big_11A718 *)func_0011A3F8(ptr, 1);
    b->x[0] = i;
    b->wds = 1;
    return b;
}
/* localdecomp:end func_0011A718 */

/* localdecomp:start func_0011A750 */
typedef struct Bigint_0011A750 {
    struct Bigint_0011A750 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_0011A750;
extern void *func_0011A3F8();

Bigint_0011A750 *func_0011A750(void *ptr, Bigint_0011A750 *a, Bigint_0011A750 *b)
{
    Bigint_0011A750 *c;
    s32 k;
    s32 wa;
    s32 wb;
    s32 wc;
    u32 carry;
    u32 y;
    u32 z;
    u32 *x;
    u32 *xa;
    u32 *xae;
    u32 *xb;
    u32 *xbe;
    u32 *xc;
    u32 *xc0;
    u32 z2;

    if (a->wds < b->wds) {
        c = a;
        a = b;
        b = c;
    }
    k = a->k;
    wa = a->wds;
    wb = b->wds;
    wc = wa + wb;
    if (wc > a->maxwds) {
        k++;
    }
    c = (Bigint_0011A750 *)func_0011A3F8(ptr, k);
    for (x = c->x, xa = x + wc; x < xa; x++) {
        *x = 0;
    }
    xa = a->x;
    xae = xa + wa;
    xb = b->x;
    xbe = xb + wb;
    xc0 = c->x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xffff) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                ((u16 *)xc)[1] = (u16)z2;
                ((u16 *)xc)[0] = (u16)z;
                xc++;
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                ((u16 *)xc)[1] = (u16)z;
                ((u16 *)xc)[0] = (u16)z2;
                xc++;
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc) {
    }
    c->wds = wc;
    return c;
}
/* localdecomp:end func_0011A750 */

/* localdecomp:start func_0011A960 */
typedef struct Big_11A960 {
    struct Big_11A960 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Big_11A960;
typedef struct {
    u8 pad[0x48];
    Big_11A960 *p5s;
} Reent_11A960;
extern s32 D_00150268[];
Big_11A960 *func_0011A960(Reent_11A960 *ptr, Big_11A960 *b, s32 k) {
    Big_11A960 *b1, *p5, *p51;
    s32 i;

    if ((i = k & 3)) {
        b = (Big_11A960 *)func_0011A4D0(ptr, (void *)b, D_00150268[i - 1], 0);
    }
    if (!(k >>= 2)) {
        return b;
    }
    if (!(p5 = ptr->p5s)) {
        p5 = ptr->p5s = (Big_11A960 *)func_0011A718(ptr, 625);
        p5->next = 0;
    }
    for (;;) {
        if (k & 1) {
            b1 = (Big_11A960 *)func_0011A750(ptr, (void *)b, (void *)p5);
            func_0011A4A0((void *)ptr, (void *)b);
            b = b1;
        }
        if (!(k >>= 1)) {
            break;
        }
        if (!(p51 = p5->next)) {
            p51 = p5->next = (Big_11A960 *)func_0011A750(ptr, (void *)p5, (void *)p5);
            p51->next = 0;
        }
        p5 = p51;
    }
    return b;
}
/* localdecomp:end func_0011A960 */

/* localdecomp:start func_0011AA60 */
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

Bigint_0011AA60 *func_0011AA60(void *ptr, Bigint_0011AA60 *b, s32 k)
{
    s32 i;
    s32 k1;
    s32 n;
    s32 n1;
    Bigint_0011AA60 *b1;
    u32 *x;
    u32 *x1;
    u32 *xe;
    u32 z;

    n = k >> 5;
    k1 = b->k;
    n1 = n + b->wds + 1;
    for (i = b->maxwds; n1 > i; i <<= 1) {
        k1++;
    }
    b1 = (Bigint_0011AA60 *)func_0011A3F8(ptr, k1);
    x1 = b1->x;
    for (i = 0; i < n; i++) {
        *x1++ = 0;
    }
    x = b->x;
    xe = x + b->wds;
    if ((k &= 0x1f) != 0) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z) != 0) {
            ++n1;
        }
    } else {
        do {
            *x1++ = *x++;
        } while (x < xe);
    }
    b1->wds = n1 - 1;
    func_0011A4A0(ptr, b);
    return b1;
}
/* localdecomp:end func_0011AA60 */

/* localdecomp:start func_0011ABB8 */
s32 func_0011ABB8(Bigint_1171C8 *a, Bigint_1171C8 *b)
{
    u32 *xa;
    u32 *xa0;
    u32 *xb;
    u32 *xb0;
    s32 i;
    s32 j;

    i = a->wds;
    j = b->wds;
    if ((i -= j) != 0) {
        return i;
    }
    xa0 = a->x;
    xa = xa0 + j;
    xb0 = b->x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb) {
            return *xa < *xb ? -1 : 1;
        }
        if (xa <= xa0) {
            break;
        }
    }
    return 0;
}
/* localdecomp:end func_0011ABB8 */

/* localdecomp:start func_0011AC20 */
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

Bigint_0011AC20 *func_0011AC20(void *ptr, Bigint_0011AC20 *a, Bigint_0011AC20 *b)
{
    s32 i;
    s32 wa;
    s32 wb;
    s32 borrow;
    s32 y;
    s32 z;
    u32 *xa;
    u32 *xae;
    u32 *xb;
    u32 *xbe;
    u32 *xc;
    Bigint_0011AC20 *c;

    i = func_0011ABB8(a, b);
    if (!i) {
        c = (Bigint_0011AC20 *)func_0011A3F8(ptr, 0);
        c->wds = 1;
        c->x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else {
        i = 0;
    }
    c = (Bigint_0011AC20 *)func_0011A3F8(ptr, a->k);
    c->sign = i;
    wa = a->wds;
    xa = a->x;
    xae = xa + wa;
    wb = b->wds;
    xb = b->x;
    xbe = xb + wb;
    xc = c->x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16 *)xc)[1] = (u16)z;
        ((u16 *)xc)[0] = (u16)y;
        xc++;
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16 *)xc)[1] = (u16)z;
        ((u16 *)xc)[0] = (u16)y;
        xc++;
    }
    while (!*--xc) {
        wa--;
    }
    c->wds = wa;
    return c;
}
/* localdecomp:end func_0011AC20 */

/* localdecomp:start func_0011ADB0 */
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
Big_11ADB0 *func_0011ADB0(void *ptr, double _d, s32 *e, s32 *bits) {
    extern void *func_0011A3F8();
    extern s32 func_0011A658();
    extern s32 func_0011A5D8();
    Dbl_11ADB0 d;
    Big_11ADB0 *b;
    s32 de, i, k;
    u32 *x, y, z;
    d.d = _d;
    b = (Big_11ADB0 *)func_0011A3F8(ptr, 1);
    x = b->x;
    z = d.L[1] & 0xFFFFF;
    d.L[1] &= 0x7FFFFFFF;
    if ((de = (s32)(d.L[1] >> 20))) {
        z |= 0x100000;
    }
    if (d.L[0]) {
        y = d.L[0];
        if ((k = func_0011A658(&y))) {
            x[0] = y | z << (32 - k);
            z >>= k;
        } else {
            x[0] = y;
        }
        i = b->wds = (x[1] = z) ? 2 : 1;
    } else {
        k = func_0011A658(&z);
        x[0] = z;
        i = b->wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - 1075 + k;
        *bits = 53 - k;
    } else {
        *e = de - 1075 + 1 + k;
        *bits = 32 * i - func_0011A5D8(x[i - 1]);
    }
    return b;
}
/* localdecomp:end func_0011ADB0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF38);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011AF40);

/* localdecomp:start func_0011AF48 */
typedef struct Reent_11AF48 {
    u8 pad0[8];
    F_118838 *out;
} Reent_11AF48;
typedef char *va_list_11AF48;
extern void *D_0013D770[];
extern s32 func_0011CE78(F_118838 *, const char *, va_list_11AF48);

s32 func_0011AF48(const char *fmt, ...) {
    s32 ret;
    va_list_11AF48 ap;
    Reent_11AF48 *ptr;
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    ptr = D_0013D770[0];
    ptr->out->data = ptr;
    ret = func_0011CE78(ptr->out, fmt, ap);
    return ret;
}
/* localdecomp:end func_0011AF48 */

/* localdecomp:start func_0011AFB8 */
extern s32 D_1D48C0[];
extern s32 func_0011F468();

long func_0011AFB8(void *ptr, s32 fd, void *buf, s32 cnt)
{
    long ret;

    D_1D48C0[0] = 0;
    if ((ret = func_0011F468(fd, buf, cnt)) == -1 && D_1D48C0[0] != 0) {
        *(s32 *)ptr = D_1D48C0[0];
    }
    return ret;
}
/* localdecomp:end func_0011AFB8 */

/* localdecomp:start func_0011B018 */
typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} Dbl_11B018;

int func_0011B018(double x)
{
    s32 hx, lx;
    do {
        Dbl_11B018 ew_u;
        ew_u.value = x;
        hx = ew_u.parts.msw;
        lx = ew_u.parts.lsw;
    } while (0);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (int)((u32)(hx | (-hx)) >> 31);
}
/* localdecomp:end func_0011B018 */

/* localdecomp:start func_0011B060 */
typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} Dbl_11B060;
int func_0011B060(double x) {
    s32 hx, lx;
    do {
        Dbl_11B060 ew_u;
        ew_u.value = x;
        hx = ew_u.parts.msw;
        lx = ew_u.parts.lsw;
    } while (0);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (int)(((u32)hx) >> 31);
}
/* localdecomp:end func_0011B060 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011B09C);
