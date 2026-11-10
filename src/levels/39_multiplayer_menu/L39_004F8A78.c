#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004F8A78);

INCLUDE_ASM("asm/levels", func_L39_004F8B88);

INCLUDE_ASM("asm/levels", func_L39_004F8D78);

INCLUDE_ASM("asm/levels", func_L39_004F8E00);

INCLUDE_ASM("asm/levels", func_L39_004F8EB8);

/* localdecomp:start func_L39_004F9158 */
extern void *func_L39_004DE940(void);
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004DD690(void *, s32);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, s32, s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_004DE9B8(void *);

s32 func_L39_004F9158(s32 (*fn)(s32, void **), s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *h;
    void *buf;
    s32 size;
    s32 ret;
    void *local;

    ret = 0;
    buf = 0;
    h = func_L39_004DE940();
    if (h != 0) {
        size = fn(arg2, 0);
        if (size > 0) {
            buf = func_L39_004BEED8(size);
            if (buf == 0) {
                goto close;
            }
        }
        local = buf;
        fn(arg2, &local);
        if (func_L39_004DD690(h, arg1) != 0) {
            ret = 1;
            func_L39_004DD778(h, buf, size);
            func_L39_004DD7A8(h, arg3, arg4);
        }
    }
    if (buf != 0) {
        func_L39_004BEF28(buf);
    }
close:
    if (h != 0) {
        func_L39_004DE9B8(h);
    }
    return ret;
}
/* localdecomp:end func_L39_004F9158 */

/* localdecomp:start func_L39_004F9278 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);

char *func_L39_004F9278(s32 (*i2d)(), char *(*d2i)(), char *x) {
    u8 *b, *p;
    long i;
    char *ret;

    if (x == 0) {
        return 0;
    }
    i = (long)i2d(x, 0);
    b = (u8 *)func_L39_004BEED8((u32)i + 10);
    if (b == 0) {
        func_L39_004BC6C8(13, 106, 33, 0, 0);
        return 0;
    }
    p = b;
    i = i2d(x, &p);
    p = b;
    ret = d2i(0, &p, i);
    func_L39_004BEF28(b);
    return ret;
}
/* localdecomp:end func_L39_004F9278 */

INCLUDE_ASM("asm/levels", func_L39_004F9340);

INCLUDE_ASM("asm/levels", func_L39_004F94F0);

INCLUDE_ASM("asm/levels", func_L39_004F9728);

/* localdecomp:start func_L39_004F97C0 */
typedef struct S_004F97C0 { const char *sn; const char *ln; s32 nid; s32 length; u8 *data; } S_004F97C0;
extern s32 func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);
extern void *func_0011D380(void *, const void *, unsigned int);

s32 func_L39_004F97C0(S_004F97C0 *a, s32 *pp) {
    u8 *p;

    if (a == 0 || a->data == 0) {
        return 0;
    }
    if (pp == 0) {
        return func_L39_004FA1A0(0, a->length, 6);
    }
    p = (u8 *)*pp;
    func_L39_004F9FF8(&p, 0, a->length, 6, 0);
    func_0011D380(p, a->data, a->length);
    p += a->length;
    *pp = (s32)p;
    return a->length;
}
/* localdecomp:end func_L39_004F97C0 */
