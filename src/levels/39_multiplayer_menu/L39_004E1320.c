#include "common.h"

/* localdecomp:start func_L39_004E1320 */
typedef struct M_004E1320 {
    s32 f0;
    s32 _p4[5];
    s32 (*f18)(s32, u8 *, s32, s32, s32 *, s32);
    s32 _p1C;
    s32 f20[4];
} M_004E1320;

typedef struct K_004E1320 {
    s32 f0;
    s32 _p4[2];
    s32 fC;
} K_004E1320;

extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004DE940(void);
extern void func_L39_00505120(void *, M_004E1320 **);
extern void func_L39_004DD7A8(void *, u8 *, s32 *);
extern void func_L39_004DE9B8(void *);

s32 func_L39_004E1320(M_004E1320 **arg0, s32 arg1, s32 *arg2, K_004E1320 *arg3) {
    u8 buf[32];
    s32 n;
    void *ctx;
    M_004E1320 *m;
    s32 found;
    s32 i;

    found = 0;
    *arg2 = 0;
    ctx = func_L39_004DE940();
    if (ctx == 0) {
        return 0;
    }
    func_L39_00505120(ctx, arg0);
    func_L39_004DD7A8(ctx, buf, &n);
    m = *arg0;
    for (i = 0; i < 4 && m->f20[i] != 0; i++) {
        if (arg3->f0 == m->f20[i]) {
            found = 1;
            break;
        }
    }
    if (!found) {
        func_L39_004BC6C8(6, 0x7A, 0x7A, 0, 0);
    } else if (m->f18 == 0) {
        func_L39_004BC6C8(6, 0x7A, 0x76, 0, 0);
    } else {
        func_L39_004DE9B8(ctx);
        return (*arg0)->f18((*arg0)->f0, buf, n, arg1, arg2, arg3->fC);
    }
    if (ctx != 0) {
        func_L39_004DE9B8(ctx);
    }
    return 0;
}
/* localdecomp:end func_L39_004E1320 */

INCLUDE_ASM("asm/levels", func_L39_004E1478);
