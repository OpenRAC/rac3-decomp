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

INCLUDE_ASM("asm/levels", func_L39_004D9ED8);

INCLUDE_ASM("asm/levels", func_L39_004D9F28);

INCLUDE_ASM("asm/levels", func_L39_004DA054);

INCLUDE_ASM("asm/levels", func_L39_004DA068);
