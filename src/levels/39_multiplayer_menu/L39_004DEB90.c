#include "common.h"

typedef struct { int n; int *items; } L;

INCLUDE_ASM("asm/levels", func_L39_004DEB90);

INCLUDE_ASM("asm/levels", func_L39_004DEBB8);

/* localdecomp:start func_L39_004DEC08 */
typedef struct S_004DEC08 {
    long argl;
    void *argp;
    void *new_func;
    void *free_func;
    void *dup_func;
} S_004DEC08;

extern L *func_L39_004CC228(int);
extern void func_L39_004BC6C8(int, int, int, int, int);
extern int func_L39_004CC3E0(L *, int);
extern void *func_L39_004BEED8_004DEC08(s32);
extern void func_L39_004BEF28(void *);

int func_L39_004DEC08(int idx, L **skp, long argl, void *argp, void *new_func, void *dup_func, void *free_func) {
    int ret = -1;
    S_004DEC08 *a;

    if (*skp == 0) {
        *skp = func_L39_004CC228(0);
    }
    if (*skp == 0) {
        func_L39_004BC6C8(0x26, 0x64, 0x21, 0, 0);
        goto err;
    }
    a = func_L39_004BEED8_004DEC08(sizeof(S_004DEC08));
    if (a == 0) {
        func_L39_004BC6C8(0x26, 0x64, 0x21, 0, 0);
        goto err;
    }
    a->argl = argl;
    a->argp = argp;
    a->new_func = new_func;
    a->dup_func = dup_func;
    a->free_func = free_func;
    while ((*skp)->n <= idx) {
        if (!func_L39_004CC3E0(*skp, 0)) {
            func_L39_004BC6C8(0x26, 0x64, 0x21, 0, 0);
            func_L39_004BEF28(a);
            goto err;
        }
    }
    (*skp)->items[idx] = (int)a;
    ret = idx;
err:
    return ret;
}
/* localdecomp:end func_L39_004DEC08 */

/* localdecomp:start func_L39_004DED48 */
extern L *func_L39_004CC228(int);
extern void func_L39_004BC6C8(int, int, int, int, int);
extern int func_L39_004CC3E0(L *, int);

int func_L39_004DED48(L **a, int idx, int val) {
    int i;
    if (*a == 0) {
        *a = func_L39_004CC228(0);
        if (*a == 0) {
            func_L39_004BC6C8(0x26, 0x65, 0x21, 0, 0);
            return 0;
        }
    }
    if (idx < 0) idx = 0;
    for (i = (*a)->n; i <= idx; i++) {
        if (!func_L39_004CC3E0(*a, 0)) {
            func_L39_004BC6C8(0x26, 0x65, 0x21, 0, 0);
            return 0;
        }
    }
    (*a)->items[idx] = val;
    return 1;
}
/* localdecomp:end func_L39_004DED48 */

/* localdecomp:start func_L39_004DEE38 */
int func_L39_004DEE38(L **a, int idx) {
    L *l = *a;
    if (l == 0 || idx >= l->n) return 0;
    return l->items[idx];
}
/* localdecomp:end func_L39_004DEE38 */

/* localdecomp:start func_L39_004DEE70 */
typedef struct {
    long f0;
    s32 f8;
    s32 pad;
    void (*f10)(s32, s32, L **, s32, long, s32);
} E_004DEE70;
typedef struct { s32 n; E_004DEE70 **items; } T_004DEE70;
extern void func_L39_004CC538(L *);

void func_L39_004DEE70(T_004DEE70 *list, s32 arg1, L **arg2) {
    s32 i;
    s32 n;
    E_004DEE70 *e;

    if (list != 0) {
        n = list->n;
        for (i = 0; i < n; i++) {
            e = list->items[i];
            if (e != 0 && e->f10 != 0) {
                e->f10(arg1, func_L39_004DEE38(arg2, i), arg2, i, e->f0, e->f8);
            }
        }
    }
    if (*arg2 != 0) {
        func_L39_004CC538(*arg2);
        *arg2 = 0;
    }
}
/* localdecomp:end func_L39_004DEE70 */

INCLUDE_ASM("asm/levels", func_L39_004DEF48);

/* localdecomp:start func_L39_004DF010 */
typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    char _p10[0x48];
} S_004DF010;
extern S_004DF010 *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);
extern void *func_L39_004DE940(void);
extern void func_L39_004DE9B8(void *);

S_004DF010 *func_L39_004DF010(void) {
    S_004DF010 *o = func_L39_004BEED8(0x58);
    if (o != 0) {
        func_0011D534(o, 0, 0x58);
        if ((o->f4 = func_L39_004DE940()) != 0
            && (o->f8 = func_L39_004DE940()) != 0
            && (o->fC = func_L39_004DE940()) != 0) {
            return o;
        }
        if (o->f4 != 0) func_L39_004DE9B8(o->f4);
        if (o->f8 != 0) func_L39_004DE9B8(o->f8);
        if (o->fC != 0) func_L39_004DE9B8(o->fC);
        func_L39_004BC6C8(24, 100, 33, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L39_004DF010 */

INCLUDE_ASM("asm/levels", func_L39_004DF0E0);
