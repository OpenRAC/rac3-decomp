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

/* localdecomp:start func_L39_004EABF0 */
typedef struct S_004EABF0 {
    u8 pad0[0x14];
    s32 f14;
} S_004EABF0;

s32 func_L39_004EABF0(S_004EABF0 *arg0) {
    s32 ret = 0;
    if (arg0 != 0) {
        ret = arg0->f14;
    }
    return ret;
}
/* localdecomp:end func_L39_004EABF0 */

/* localdecomp:start func_L39_004EAC08 */
typedef struct S_004EAC08 {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ void *fC;
} S_004EAC08;

extern s32 func_L39_004BECC0(s32, s32, char *, s32);
extern void *func_L39_004E2D20(void);
extern s32 func_L39_004E2DD0(void *, s32, s32, s32, s32);
extern void func_L39_004E2D68(void *);
extern char D_L39_00477598[];

void *func_L39_004EAC08(S_004EAC08 *a) {
    void *ret;

    if (a->fC == 0) {
        func_L39_004BECC0(9, 9, D_L39_00477598, 0x352);
        if (a->fC == 0) {
            ret = func_L39_004E2D20();
            if (ret != 0) {
                if (func_L39_004E2DD0(ret, a->f8, a->f4, 0, 0) != 0) {
                    func_L39_004E2D68(ret);
                    ret = 0;
                } else {
                    a->fC = ret;
                }
            }
        } else {
            ret = a->fC;
        }
        func_L39_004BECC0(10, 9, D_L39_00477598, 0x367);
    } else {
        ret = a->fC;
    }
    return ret;
}
/* localdecomp:end func_L39_004EAC08 */
