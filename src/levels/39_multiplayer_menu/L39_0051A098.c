#include "common.h"

/* localdecomp:start func_L39_0051A098 */
typedef struct N_0051A098 N_0051A098;
struct N_0051A098 {
    N_0051A098 *next;
    N_0051A098 *prev;
    s32 id;
    s32 fC;
    char p10[0x44];
    N_0051A098 *f54;
    char p58[0x14];
    s32 f6C;
};
typedef struct C_0051A098 { char p0[0x14]; char f14[0x40]; s32 f54; } C_0051A098;
extern N_0051A098 *D_L39_0046F550 __attribute__((section(".data")));
extern N_0051A098 *D_L39_0046F554 __attribute__((section(".data")));
extern C_0051A098 *func_L39_005190E8(s32);
extern N_0051A098 *func_L39_00519388(s32);
extern void func_L39_005190C8(void);
extern s32 func_1488A8(void *, s32, s32, s32);
extern s32 func_L39_00519058(void);
extern void func_L39_00519018(void *);
extern s32 func_L39_00519468(s32);
extern s32 func_L39_005192A8(C_0051A098 *, s32);

s32 func_L39_0051A098(s32 arg0) {
    C_0051A098 *ctx;
    N_0051A098 *node;
    N_0051A098 *c;
    N_0051A098 *next;
    N_0051A098 *prev;
    s32 err;

    ctx = func_L39_005190E8(0);
    if (ctx == 0) {
        return -1;
    }
    node = func_L39_00519388(arg0);
    if (node == 0) {
        return func_L39_005192A8(ctx, 9);
    }
    err = 0;
    if (node->fC != 0) {
        func_L39_005190C8();
        err = func_1488A8(ctx->f14, ctx->f54, node->fC, node->f6C);
        if (func_L39_00519058() < 0) {
            return func_L39_005192A8(ctx, -1);
        }
    }
    prev = node->prev;
    next = node->next;
    if (next != 0) {
        next->prev = prev;
        prev = node->prev;
        next = node->next;
    } else {
        D_L39_0046F554 = prev;
    }
    if (prev != 0) {
        prev->next = next;
    } else {
        D_L39_0046F550 = next;
    }
    while ((c = node->f54) != 0) {
        s32 fc = c->fC;
        node->f54 = c->next;
        if (fc != 0) {
            func_L39_005190C8();
            func_1488A8(ctx->f14, ctx->f54, c->fC, 0);
            if (func_L39_00519058() < 0) {
                return func_L39_005192A8(ctx, -1);
            }
        }
        func_L39_00519018(c);
    }
    func_L39_00519018(node);
    if (err < 0) {
        return func_L39_005192A8(ctx, func_L39_00519468(err));
    }
    return func_L39_005192A8(ctx, 0);
}
/* localdecomp:end func_L39_0051A098 */

LINKER_REMNANT("asm/levels", func_L39_0051A210);
