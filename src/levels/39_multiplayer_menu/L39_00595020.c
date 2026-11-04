#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00595020);

INCLUDE_ASM("asm/levels", func_L39_00595098);

INCLUDE_ASM("asm/levels", func_L39_00595248);

INCLUDE_ASM("asm/levels", func_L39_005953D8);

INCLUDE_ASM("asm/levels", func_L39_00595430);

/* localdecomp:start func_L39_00595570 */
extern void func_L39_00595020(void);
extern s32 func_0038E0A8(u8 *p, s32 off, s32 *out);
extern s32 func_L39_005953D8(s32 v);

void func_L39_00595570(u8 *src, u8 *dst) {
    s32 tmp = 0;
    s32 i = 0;
    s32 o = 0;
    s32 r;

    func_L39_00595020();
    if (src[0] != 0) {
        do {
            i += func_0038E0A8(src, i, &tmp);
            i++;
            r = func_L39_005953D8(tmp);
            dst[o] = r >> 8;
            o++;
            dst[o] = r;
            o++;
        } while (src[i] != 0);
    }
    dst[o] = 0;
    o++;
    dst[o] = 0;
}
/* localdecomp:end func_L39_00595570 */

INCLUDE_ASM("asm/levels", func_L39_00595628);

/* localdecomp:start func_L39_005956D0 */
extern void func_L39_00595098(u8 *, u8 *);
extern s32 func_00120884(u8 *);

void func_L39_005956D0(u8 *src, u8 *dst) {
    s32 n = 0;
    u8 *p;

    if (src[0] | src[1]) {
        p = src;
        do {
            func_L39_00595098(p, dst + n);
            p += 2;
            n += func_00120884(dst + n);
        } while (p[0] | p[1]);
    }
    dst[n] = 0;
}
/* localdecomp:end func_L39_005956D0 */

/* localdecomp:start func_L39_00595760 */
extern s32 func_L39_00595248(u8 *s, s32 *pos);

void func_L39_00595760(u8 *s, u8 *d) {
    s32 pos = 0;
    s32 n = 0;
    s32 v;

    if (*s != 0) {
        do {
            v = func_L39_00595248(s, &pos);
            d[n] = v >> 8;
            n++;
            d[n] = v;
            n++;
        } while (s[pos] != 0);
    }
    do {
        d[n++] = 0;
        d[n] = 0;
    } while (0);
}
/* localdecomp:end func_L39_00595760 */

/* localdecomp:start func_L39_005957F0 */
extern void func_0011D534(void *, s32, s32);
extern void func_L39_00595570(u8 *, u8 *);
extern void func_L39_005956D0(u8 *, u8 *);

void func_L39_005957F0(void *a0, void *a1) {
    u8 local[0x800];
    func_0011D534(local, 0, 0x800);
    func_L39_00595570(a0, local);
    func_L39_005956D0(local, a1);
}
/* localdecomp:end func_L39_005957F0 */

/* localdecomp:start func_L39_00595848 */
extern void func_0011D534(void *, s32, s32);
extern void func_L39_00595760(u8 *, u8 *);
extern void func_L39_00595628(void *, void *);

void func_L39_00595848(void *a0, void *a1) {
    u8 local[0x800];
    func_0011D534(local, 0, 0x800);
    func_L39_00595760(a0, local);
    func_L39_00595628(local, a1);
}
/* localdecomp:end func_L39_00595848 */

/* localdecomp:start func_L39_005958A0 */
extern u8 D_L39_00481D00[];
extern void func_00120D28(void *, s32, s32);
extern void func_L39_005957F0(void *, void *);

void func_L39_005958A0(s32 a0, s32 a1, s32 a2) {
    s32 off;
    off = a2;
    func_00120D28(D_L39_00481D00, a1, a2);
    D_L39_00481D00[off] = 0;
    func_L39_005957F0(D_L39_00481D00, a0);
}
/* localdecomp:end func_L39_005958A0 */

/* localdecomp:start func_L39_005958F8 */
extern u8 D_L39_00482100[];
extern void func_00120D28(void *, s32, s32);
extern void func_L39_00595848(void *, void *);

void func_L39_005958F8(s32 a0, s32 a1, s32 a2) {
    func_00120D28(D_L39_00482100, a1, a2);
    D_L39_00482100[a2] = 0;
    func_L39_00595848(D_L39_00482100, a0);
}
/* localdecomp:end func_L39_005958F8 */
