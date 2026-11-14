#include "common.h"

/* localdecomp:start func_L39_004EAB38 */
/* log: v1 natural OpenSSL-like dup */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T_004EAB38;

typedef struct {
    s32 f0;
    s32 f4;
    void *f8;
    s32 fC;
    s32 f10;
    s32 f14;
    T_004EAB38 *f18;
} S_004EAB38;

extern void *func_L39_005059C0(void *);
s32 func_L39_004E4688(s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004EA410(void *);

S_004EAB38 *func_L39_004EAB38(S_004EAB38 *arg0) {
    S_004EAB38 *p;

    if ((p = func_L39_005059C0(arg0->f8)) == 0) {
        return 0;
    }
    if (!func_L39_004E4688(p->f4, arg0->f4, 0x12)) {
        goto err;
    }
    if (arg0->f18 != 0) {
        p->f18 = func_L39_004BEED8(sizeof(T_004EAB38));
        if (p->f18 == 0) {
            goto err;
        }
        p->f18->a = arg0->f18->a;
        p->f18->b = arg0->f18->b;
        p->f18->c = arg0->f18->c;
    }
    return p;
err:
    if (p != 0) {
        func_L39_004EA410(p);
    }
    return 0;
}
/* localdecomp:end func_L39_004EAB38 */

INCLUDE_ASM("asm/levels", func_L39_004EABF0);

INCLUDE_ASM("asm/levels", func_L39_004EAC08);
