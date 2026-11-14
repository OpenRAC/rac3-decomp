#include "common.h"

/* localdecomp:start func_L39_004D9CA0 */
typedef struct S_004D9CA0 {
    /* 0x00 */ s32 pad0[3];
    /* 0x0C */ s32 len;
    /* 0x10 */ u8 *data;
} S_004D9CA0;

extern s32 func_L39_004E0C88(S_004D9CA0 *);
extern u8 *func_L39_004E0BC8(s32);
extern u8 *func_L39_004E0B10(s32);
extern long func_00130760(long, long);
extern s32 func_00120048(void *, void *, ...);
extern s32 func_00120884(void *);
extern void func_00120D28(void *, void *, s32);
extern u8 D_L39_00476188[];
extern u8 D_L39_00476190[];

s32 func_L39_004D9CA0(u8 *dst, s32 n, S_004D9CA0 *src) {
    u8 buf[0x30];
    s32 r;
    s32 total;
    s32 i;
    s32 len;
    long x;
    u8 *p;

    if (n <= 0) {
        return 0;
    }
    if (src == 0 || src->data == 0) {
        *dst = 0;
        return 0;
    }
    r = func_L39_004E0C88(src);
    if (r == 0) {
        i = 0;
        len = src->len;
        p = src->data;
        x = 0;
        if (len > 0) {
            x = *p & 0x7F;
            if (*p & 0x80) {
                do {
                    i++;
                    x <<= 7;
                    if (i >= len) {
                        break;
                    }
                    x |= p[i] & 0x7F;
                } while (p[i] & 0x80);
            }
        }
        r = func_00130760(x, 0x28);
        i++;
        if (r > 2) {
            r = 2;
        }
        func_00120048(buf, D_L39_00476188, r, x - r * 0x28);
        x = 0;
        r = func_00120884(buf);
        func_00120D28(dst, buf, n);
        n -= r;
        dst += r;
        total = r;
        if (i < len) {
            do {
                x |= p[i] & 0x7F;
                if ((p[i] & 0x80) == 0) {
                    func_00120048(buf, D_L39_00476190, x);
                    r = func_00120884(buf);
                    if (n > 0) {
                        func_00120D28(dst, buf, n);
                    }
                    n -= r;
                    dst += r;
                    total += r;
                    x = 0;
                }
                i++;
                x <<= 7;
            } while (i < len);
        }
    } else {
        u8 *s = func_L39_004E0BC8(r);
        if (s == 0) {
            s = func_L39_004E0B10(r);
        }
        func_00120D28(dst, s, n);
        total = func_00120884(s);
    }
    dst[n - 1] = 0;
    return total;
}
/* localdecomp:end func_L39_004D9CA0 */

/* localdecomp:start func_L39_004D9ED8 */
extern char D_L39_0046A330[];

void *func_L39_004D9ED8(void) {
    return D_L39_0046A330;
}
/* localdecomp:end func_L39_004D9ED8 */

INCLUDE_ASM("asm/levels", func_L39_004D9EE8);

/* localdecomp:start func_L39_004D9F90 */
extern void func_L39_004BEF28(void *);

typedef struct S20_004D9F90 {
    u8 pad0[0x8];
    void *f8;
    u8 padC[0x14 - 0xC];
    void *f14;
} S20_004D9F90;

typedef struct S_004D9F90 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0x14 - 0x10];
    s32 f14;
    u8 pad18[0x20 - 0x18];
    S20_004D9F90 *f20;
} S_004D9F90;

s32 func_L39_004D9F90(S_004D9F90 *s) {
    S20_004D9F90 *t;

    if (s == 0) {
        return 0;
    }
    t = s->f20;
    if (t->f8 != 0) {
        func_L39_004BEF28(t->f8);
    }
    if (t->f14 != 0) {
        func_L39_004BEF28(t->f14);
    }
    func_L39_004BEF28(s->f20);
    s->f20 = 0;
    s->fC = 0;
    s->f14 = 0;
    return 1;
}
/* localdecomp:end func_L39_004D9F90 */

INCLUDE_ASM("asm/levels", func_L39_004DA008);

INCLUDE_ASM("asm/levels", func_L39_004DA180);

INCLUDE_ASM("asm/levels", func_L39_004DA368);

INCLUDE_ASM("asm/levels", func_L39_004DA7B0);

/* localdecomp:start func_L39_004DA920 */
extern s32 func_L39_004DACB0(void *, const char *, s32);

s32 func_L39_004DA920(void *arg0, const char *arg1) {
    return func_L39_004DACB0(arg0, arg1, func_00120884(arg1));
}
/* localdecomp:end func_L39_004DA920 */
