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

INCLUDE_ASM("asm/levels", func_L39_004C43D8);

INCLUDE_ASM("asm/levels", func_L39_004C46A8);

INCLUDE_ASM("asm/levels", func_L39_004C47C0);

INCLUDE_ASM("asm/levels", func_L39_004C47D0);

INCLUDE_ASM("asm/levels", func_L39_004C47F8);

INCLUDE_ASM("asm/levels", func_L39_004C4908);

INCLUDE_ASM("asm/levels", func_L39_004C4998);
