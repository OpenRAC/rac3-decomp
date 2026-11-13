#include "common.h"

/* localdecomp:start func_L39_004DA968 */
void *func_L39_004BEED8(s32);
void func_L39_004BEF28(void *);
void func_L39_004BC6C8(s32, s32, s32, s32, s32);
s32 func_L39_004DA9E8(void *, s32);
void *func_L39_004DA968(s32 arg0) {
    void *p = func_L39_004BEED8(0x48);
    if (p == 0) {
        func_L39_004BC6C8(0x20, 0x67, 0x21, 0, 0);
        return 0;
    }
    if (func_L39_004DA9E8(p, arg0) == 0) {
        func_L39_004BEF28(p);
        p = 0;
    }
    return p;
}
/* localdecomp:end func_L39_004DA968 */

/* localdecomp:start func_L39_004DA9E8 */
extern void *func_L39_004DBA08(void);
extern void func_L39_004DEF48(s32, void *, void *);

typedef struct {
    s32 a0, a4, a8, aC, a10, a14, a18, a1C, a20, a24, a28, a2C;
    s64 a30, a38;
    void *a40;
} S_004DA9E8;

typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(S_004DA9E8 *);
} S_004DA9E8_Arg;

s32 func_L39_004DA9E8(void *arg0, s32 arg1) {
    S_004DA9E8 *o = arg0;
    S_004DA9E8_Arg *a = (S_004DA9E8_Arg *)arg1;
    s32 h = *(s32 *)func_L39_004DBA08();
    void *p;
    s32 r;

    o->a0 = arg1;
    o->a4 = 0;
    o->a8 = 0;
    o->aC = 0;
    o->a14 = 0;
    o->a18 = 0;
    o->a1C = 0;
    o->a20 = 0;
    o->a28 = 0;
    o->a24 = 0;
    o->a30 = 0;
    o->a38 = 0;
    o->a10 = 1;
    o->a2C = 1;
    p = func_L39_004BEED8(8);
    o->a40 = (void *)p;
    if (p == 0) {
        return 0;
    }
    func_L39_004DEF48(h, o, p);
    if (a->f1C != 0) {
        r = a->f1C(o);
        if (r == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004DA9E8 */

/* localdecomp:start func_L39_004DAAB0 */
extern char D_L39_004761A0[];
extern void *func_L39_004DBA08(void);
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004DEE70(s32, void *, s32);

typedef struct {
    char _p0[0x20];
    s32 (*f20)(void *);
} M_004DAAB0;

typedef struct {
    M_004DAAB0 *f0;
    long (*f4)(void *, s32, s32, s32, s32, s32);
    char _p8[0x2C - 0x8];
    char f2C[0x14];
    void *f40;
} S_004DAAB0;

s32 func_L39_004DAAB0(S_004DAAB0 *arg0) {
    s32 i;
    s32 *g = (s32 *)func_L39_004DBA08();
    s32 g0 = *g;

    if (arg0 == 0) {
        return 0;
    }
    if (func_L39_004BECF0(arg0->f2C, -1, 0x12, D_L39_004761A0, 0x7F) > 0) {
        return 1;
    }
    if (arg0->f4 != 0 && (i = (s32)arg0->f4(arg0, 1, 0, 0, 0, 1)) <= 0) {
        return i;
    }
    if (arg0->f40 != 0) {
        func_L39_004DEE70(g0, arg0, (s32)arg0->f40);
        func_L39_004BEF28(arg0->f40);
    }
    if (arg0->f0 != 0) {
        if (arg0->f0->f20 != 0) {
            arg0->f0->f20(arg0);
            func_L39_004BEF28(arg0);
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004DAAB0 */

INCLUDE_ASM("asm/levels", func_L39_004DAB90);

/* localdecomp:start func_L39_004DACB0 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_L39_004DAE48(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);

typedef struct S_004DACB0 S_004DACB0;
typedef struct {
    s32 f0;
    char *f4;
    s32 (*f8)(S_004DACB0 *, const char *, s32);
} M_004DACB0;
struct S_004DACB0 {
    M_004DACB0 *f0;
    long (*f4)();
    char *f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    void *f20;
    S_004DACB0 *f24;
    S_004DACB0 *f28;
    s32 f2C;
    unsigned long f30;
    unsigned long f38;
};

/* OpenSSL's BIO_write (public source), with this build's extra flush and reference checks */
s32 func_L39_004DACB0(S_004DACB0 *b, const char *in, s32 inl) {
    s32 i;
    long (*cb)();

    if (b == 0) {
        return 0;
    }
    cb = b->f4;
    if ((b->f0 == 0) || (b->f0->f8 == 0)) {
        func_L39_004BC6C8(0x20, 0x6A, 0x6F, 0, 0);
        return -2;
    }
    if ((cb != 0) && ((i = (s32)cb(b, 3, in, inl, 0L, 1L)) <= 0)) {
        return i;
    }
    if (!b->fC) {
        func_L39_004BC6C8(0x20, 0x6A, 0x6E, 0, 0);
        return -2;
    }
    i = b->f0->f8(b, in, inl);
    if (i > 0) {
        b->f38 += (unsigned long)i;
    }
    if (b->f14 & 0x10) {
        i = (s32)((long (*)(S_004DACB0 *, s32, long, void *))func_L39_004DAE48)(b, 0xB, 0, 0);
        if (i <= 0) {
            return i;
        }
    }
    if (b->f2C <= 0) {
        func_L39_004BC6C8(0x20, 0x6A, 0x2A, 0, 0);
        return 0;
    }
    if (cb != 0) {
        i = (s32)cb(b, 0x83, in, inl, 0L, (long)i);
    }
    return i;
}
/* localdecomp:end func_L39_004DACB0 */
