#include "common.h"

typedef struct { int n; int *items; } L;

INCLUDE_ASM("asm/levels", func_L39_004DEB90);

INCLUDE_ASM("asm/levels", func_L39_004DEBB8);

INCLUDE_ASM("asm/levels", func_L39_004DEC08);

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

INCLUDE_ASM("asm/levels", func_L39_004DF010);

INCLUDE_ASM("asm/levels", func_L39_004DF0E0);
