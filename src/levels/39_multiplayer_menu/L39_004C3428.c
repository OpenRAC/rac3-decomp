#include "common.h"

/* localdecomp:start func_L39_004C3428 */
s32 func_0011D534();
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
void *func_L39_004BEED8(s32);

void *func_L39_004C3428(void) {
    void *p;
    p = func_L39_004BEED8(0x70);
    if (p == 0) {
        func_L39_004BC6C8(0x14, 0xA3, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(p, 0, 0x70);
    *(void **)((u8 *)p + 4) = (u8 *)p + 0x40;
    *(s32 *)((u8 *)p + 0x6C) = 1;
    return p;
}
/* localdecomp:end func_L39_004C3428 */

/* localdecomp:start func_L39_004C3498 */
/* OpenSSL ssl_cert_free (ssl_cert.c) */
typedef struct {
    void *x509;
    void *privatekey;
} K_004C3498;
typedef struct {
    char _p0[0x20];
    void *f20;
    void *f24;
    void *f28;
    void *f2C;
    void *f30;
    char _p34[0x40 - 0x34];
    K_004C3498 pkeys[5];
    void *extra_certs;
    s32 references;
} S_004C3498;

extern char D_L39_00475A40[];
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004EA410(void *);
extern void func_L39_004DD250(void *);
extern void func_L39_004BBBA0(void *);
extern void func_L39_004BC420(void *);
extern void func_L39_004CC510(void *, void (*)(void *));
extern void func_L39_004BEF28(void *);

void func_L39_004C3498(void *arg0) {
    S_004C3498 *c = arg0;
    s32 i;

    i = func_L39_004BECF0(&c->references, -1, 0xD, D_L39_00475A40, 0x4F);
    if (i > 0) {
        return;
    }
    if (c->f20 != 0) {
        func_L39_004EA410(c->f20);
    }
    if (c->f24 != 0) {
        func_L39_004EA410(c->f24);
    }
    if (c->f28 != 0) {
        func_L39_004EA410(c->f28);
    }
    if (c->f2C != 0) {
        func_L39_004DD250(c->f2C);
    }
    if (c->f30 != 0) {
        func_L39_004DD250(c->f30);
    }
    for (i = 0; i < 5; i++) {
        if (c->pkeys[i].x509 != 0) {
            func_L39_004BBBA0(c->pkeys[i].x509);
        }
        if (c->pkeys[i].privatekey != 0) {
            func_L39_004BC420(c->pkeys[i].privatekey);
        }
    }
    if (c->extra_certs != 0) {
        func_L39_004CC510(c->extra_certs, func_L39_004BBBA0);
    }
    func_L39_004BEF28(c);
}
/* localdecomp:end func_L39_004C3498 */

/* localdecomp:start func_L39_004C35C8 */
s32 func_L39_004C35C8(s32 *p, s32 v) {
    *p = v;
    return 1;
}
/* localdecomp:end func_L39_004C35C8 */

/* localdecomp:start func_L39_004C35D8 */
typedef struct S_004C35D8_B {
    s32 f0;
} S_004C35D8_B;

typedef struct S_004C35D8_T {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1c[0x74];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
} S_004C35D8_T;

typedef struct S_004C35D8 {
    u8 pad0[0xDC];
    S_004C35D8_T *fDC;
    u8 padE0[8];
    long fE8;
} S_004C35D8;

extern s32 func_L39_004BC348(void *, void *, s32, s32, void *);
extern s32 func_L39_004BC390(void *, void *, s32, s32, s32, void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004DE0C8(void);

s32 func_L39_004C35D8(S_004C35D8 *arg0, S_004C35D8_B *arg1) {
    S_004C35D8_T *t;
    s32 r;

    if (arg1 == 0 || arg1->f0 == 0) {
        return 0;
    }
    t = arg0->fDC;
    if (t->f98 != 0) {
        r = func_L39_004BC348(arg0, arg1, t->f98, t->f9C, &arg0->fE8);
    } else {
        r = func_L39_004BC390(arg0, arg1, t->f18, t->f90, t->f94, &arg0->fE8);
    }
    if (arg0->fE8 == 0x32) {
        func_L39_004BC6C8(0x14, 0xD0, 0xC2, 0, 0);
    }
    if (r != 0) {
        func_L39_004DE0C8();
    }
    return r;
}
/* localdecomp:end func_L39_004C35D8 */
