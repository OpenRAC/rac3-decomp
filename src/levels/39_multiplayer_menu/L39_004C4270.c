#include "common.h"

/* localdecomp:start func_L39_004C4270 */
typedef struct {
    char _p0[0x38];
    void *(*f38)(u8 *);
    s32 (*f3C)(void *, void *);
} M_004C4270;
typedef struct {
    char _p0[8];
    M_004C4270 *f8;
} C_004C4270;
extern void func_L39_004BC6C8(s32, s32, s32, void *, s32);
extern void *func_L39_004CC228(void *);
extern void func_L39_004CC440(void *);
extern s32 func_L39_004CC3E0(void *, void *);
extern void func_L39_004CC538(void *);

void *func_L39_004C4270(C_004C4270 *ctx, u8 *p, s32 len, void **a) {
    s32 i, n;
    void *ret;
    void *obj;

    i = ctx->f8->f3C(0, 0);
    if (len % i != 0) {
        func_L39_004BC6C8(0x14, 0xA2, 0x97, 0, 0);
        return 0;
    }
    if (a == 0 || *a == 0) {
        ret = func_L39_004CC228(0);
    } else {
        ret = *a;
        func_L39_004CC440(ret);
    }
    for (n = 0; n < len; n += i) {
        obj = ctx->f8->f38(p);
        p += i;
        if (obj != 0 && func_L39_004CC3E0(ret, obj) == 0) {
            func_L39_004BC6C8(0x14, 0xA2, 0x21, 0, 0);
            if (a != 0 && *a != 0) {
                goto fail;
            }
            goto err;
        }
    }
    if (a != 0) {
        *a = ret;
    }
    return ret;
err:
    func_L39_004CC538(ret);
fail:
    return 0;
}
/* localdecomp:end func_L39_004C4270 */

/* localdecomp:start func_L39_004C43D8 */
/* Best: ee29check.sh 155 diff, but all of it is one shifted instruction: retail loads arg0->f50
 * (lw $v0,0x50($s1)) after the first stores to p and leaves jalr with a nop delay slot; ours hoists
 * the load above the stores into the jalr delay. Everything else lines up (gotos fail/cleanup
 * are the original error-macro shape). Tried p->f0->f50, an s32 field with a cast (worse). */
typedef struct {
    char _p0[0x50];
    u64 (*f50)(void);
} A_004C43D8;
typedef struct {
    A_004C43D8 *f0;
    char _p4[0x10 - 0x4];
    s32 *f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    u64 f20;
    s32 f28;
    s32 f2C;
    s32 f30;
    char _p34[0x38 - 0x34];
    u64 f38;
    s32 f40;
    s32 f44;
    s32 f48;
    char f4C[0x78 - 0x4C];
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    s32 fA4;
    s32 fA8;
    s32 fAC;
    s32 fB0;
    char _pB4[0xD8 - 0xB4];
    s32 fD8;
    s32 fDC;
    void *fE0;
    char _pE4[0xF8 - 0xE4];
    char fF8[0x100 - 0xF8];
    s32 f100;
    s32 f104;
    s32 f108;
    s32 f10C;
    s32 f110;
    s32 f114;
    s32 f118;
    char _p11C[0x120 - 0x11C];
} S_004C43D8;
typedef struct {
    char _p0[0x8];
    s32 f8;
} G_004C43D8;

extern char D_L39_004EC800[];
extern char D_L39_004EC830[];
extern char D_L39_00475B80[];
extern char D_L39_00475BB0[];
extern char D_L39_00475BC0[];
extern char D_L39_00475BD0[];
extern char D_L39_00475BE0[];
extern G_004C43D8 *func_L39_004CBF60(void);
extern void func_L39_004BC6C8(s32, s32, s32, void *, s32);
extern void *func_L39_004CC228(void *);
extern void *func_L39_004BEED8(s32);
extern void * func_0011D534(void *, s32, s32);
extern s32 func_L39_004C3428(void);
extern s32 func_L39_004BCA88(void *, void *);
extern s32 func_L39_004BC090(void);
extern s32 func_L39_004EC768(void);
extern void func_L39_004CA5D0(A_004C43D8 *, s32 **, s32 *, char *);
extern s32 func_L01_00353880(char *);
extern s32 func_L39_004C4F30(s32);
extern void func_L39_004DEF48(s32, S_004C43D8 *, void *);
extern void func_L39_004C46A8(S_004C43D8 *);

S_004C43D8 *func_L39_004C43D8(A_004C43D8 *arg0) {
    S_004C43D8 *p;
    s32 g;

    g = func_L39_004CBF60()->f8;
    if (arg0 == 0) {
        func_L39_004BC6C8(0x14, 0xA8, 0xC4, 0, 0);
        return 0;
    }
    p = func_L39_004BEED8(sizeof(S_004C43D8));
    if (p == 0) {
        goto fail;
    }
    func_0011D534(p, 0, sizeof(S_004C43D8));
    p->f30 = 2;
    p->f20 = 0x5000;
    p->f0 = arg0;
    p->f18 = 0;
    p->f28 = 0;
    p->f2C = 0;
    p->f38 = p->f0->f50();
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = 0;
    func_0011D534(p->f4C, 0, sizeof(p->f4C));
    p->f7C = 0;
    p->f80 = 0;
    p->f84 = 0;
    p->f88 = 0;
    p->f8C = 0;
    p->f90 = 0;
    p->f94 = 0;
    p->f98 = 0;
    p->f9C = 0;
    p->fA4 = 0;
    p->fAC = 0;
    p->fB0 = 0;
    p->f78 = 1;
    p->fA8 = -1;
    if ((p->fA0 = func_L39_004C3428()) == 0) {
        goto fail;
    }
    p->fD8 = 0;
    p->fDC = 0;
    if ((p->f1C = func_L39_004BCA88(D_L39_004EC800, D_L39_004EC830)) == 0) {
        goto fail;
    }
    if ((p->f18 = func_L39_004BC090()) != 0) {
        if (func_L39_004EC768() < 0) {
            func_L39_004BC6C8(0x14, 0xA8, 0x10D, 0, 0);
            goto fail;
        }
    }
    func_L39_004CA5D0(p->f0, &p->f10, &p->f14, D_L39_00475B80);
    if (p->f10 == 0 || *p->f10 <= 0) {
        func_L39_004BC6C8(0x14, 0xA8, 0xA1, 0, 0);
        goto cleanup;
    }
    if ((p->f100 = func_L01_00353880(D_L39_00475BB0)) == 0) {
        func_L39_004BC6C8(0x14, 0xA8, 0xF1, 0, 0);
        goto cleanup;
    }
    if ((p->f104 = func_L01_00353880(D_L39_00475BC0)) == 0) {
        func_L39_004BC6C8(0x14, 0xA8, 0xF2, 0, 0);
        goto cleanup;
    }
    if ((p->f108 = func_L01_00353880(D_L39_00475BD0)) == 0) {
        func_L39_004BC6C8(0x14, 0xA8, 0xF3, 0, 0);
        goto cleanup;
    }
    if (func_L39_004C4F30(2)) {
        if ((p->f10C = func_L01_00353880(D_L39_00475BE0)) == 0) {
            func_L39_004BC6C8(0x14, 0xA8, 0x44E, 0, 0);
            goto cleanup;
        }
    } else {
        p->f10C = 0;
    }
    if ((p->fE0 = func_L39_004CC228(0)) == 0) {
        goto fail;
    }
    func_L39_004DEF48(g, p, p->fF8);
    p->f118 = 0x1000;
    p->f114 = 0x4000;
    p->f110 = 0;
    return p;
fail:
    func_L39_004BC6C8(0x14, 0xA8, 0x21, 0, 0);
cleanup:
    if (p != 0) {
        func_L39_004C46A8(p);
    }
    return 0;
}
/* localdecomp:end func_L39_004C43D8 */

INCLUDE_ASM("asm/levels", func_L39_004C46A8);

INCLUDE_ASM("asm/levels", func_L39_004C47C0);

INCLUDE_ASM("asm/levels", func_L39_004C47D0);

/* localdecomp:start func_L39_004C47F8 */
/* OpenSSL ssl_update_cache (ssl_lib.c) */
typedef struct {
    char _p0[0x30];
    s32 f30;
    char _p34[0x40 - 0x34];
    s32 (*f40)(void *, void *);
    char _p44[0x54 - 0x44];
    s32 f54;
    char _p58[0x60 - 0x58];
    s32 f60;
} Ctx_004C47F8;
typedef struct {
    char _p0[0x44];
    s32 f44;
    char _p48[0x98 - 0x48];
    s32 f98;
} Sess_004C47F8;
typedef struct {
    char _p0[0x5C];
    s32 f5C;
    char _p60[0xB0 - 0x60];
    Sess_004C47F8 *fB0;
    char _pB4[0xDC - 0xB4];
    Ctx_004C47F8 *fDC;
} S_004C47F8;

extern char D_L39_00475C08[];
extern s32 func_L39_004CB8D0(Ctx_004C47F8 *, Sess_004C47F8 *);
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004CBB38();
extern void func_L39_004CBCF0(Ctx_004C47F8 *, s32);

void func_L39_004C47F8(S_004C47F8 *s, s32 mode) {
    s32 i;

    if (s->fB0->f44 == 0) {
        return;
    }
    if ((s->fDC->f30 & mode) && !s->f5C && func_L39_004CB8D0(s->fDC, s->fB0)
        && s->fDC->f40 != 0) {
        func_L39_004BECF0(&s->fB0->f98, 1, 0xE, D_L39_00475C08, 0x71F);
        if (!s->fDC->f40(s, s->fB0)) {
            func_L39_004CBB38(s->fB0);
        }
    }
    i = s->fDC->f30;
    if (!(i & 0x80) && (i & mode) == mode) {
        if ((((mode & 1) ? s->fDC->f54 : s->fDC->f60) & 0xFF) == 0xFF) {
            func_L39_004CBCF0(s->fDC, 1);
        }
    }
}
/* localdecomp:end func_L39_004C47F8 */

INCLUDE_ASM("asm/levels", func_L39_004C4908);

/* localdecomp:start func_L39_004C4998 */
/* OpenSSL SSL_get_error (ssl_lib.c) */
typedef struct {
    char _p0[0x104];
    s32 f104;
} T_004C4998;
typedef struct {
    s32 f0;
    char _p4[0x2C - 0x4];
    s32 f2C;
    char _p30[0x54 - 0x30];
    T_004C4998 *f54;
} S_004C4998;

extern unsigned long func_L39_004DE120(void);
extern s32 func_L39_004C4EF0(void *);
extern s32 func_L39_004EC7B8(void *);
extern s32 func_L39_004EC7C0(void *);
extern s32 func_L39_004BB450(void *);
extern s32 func_L39_004BB460(void *);
extern s32 func_L39_004BB470(void *);
extern s32 func_L39_004DB038(void *);

s32 func_L39_004C4998(S_004C4998 *s, s32 i) {
    s32 reason;
    unsigned long l;
    void *bio;

    if (i > 0) {
        return 0;
    }
    l = func_L39_004DE120();
    if (l != 0) {
        if ((s32)((l >> 24) & 0xFF) == 2) {
            return 5;
        } else {
            return 1;
        }
    }
    if (i < 0 && func_L39_004C4EF0(s) == 3) {
        bio = (void *)func_L39_004EC7B8(s);
        if (func_L39_004BB450(bio)) {
            return 2;
        } else if (func_L39_004BB460(bio)) {
            return 3;
        } else if (func_L39_004BB470(bio)) {
            reason = func_L39_004DB038(bio);
            if (reason == 2) {
                return 7;
            } else {
                return 5;
            }
        }
    }
    if (i < 0 && func_L39_004C4EF0(s) == 2) {
        bio = (void *)func_L39_004EC7C0(s);
        if (func_L39_004BB460(bio)) {
            return 3;
        } else if (func_L39_004BB450(bio)) {
            return 2;
        } else if (func_L39_004BB470(bio)) {
            reason = func_L39_004DB038(bio);
            if (reason == 2) {
                return 7;
            } else {
                return 5;
            }
        }
    }
    if (i < 0 && func_L39_004C4EF0(s) == 4) {
        return 4;
    }
    if (i == 0) {
        if (s->f0 == 2) {
            return 6;
        } else {
            if ((s->f2C & 2) && s->f54->f104 == 0) {
                return 6;
            }
        }
    }
    return 5;
}
/* localdecomp:end func_L39_004C4998 */
