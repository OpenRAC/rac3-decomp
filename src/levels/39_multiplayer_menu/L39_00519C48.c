#include "common.h"

/* localdecomp:start func_L39_00519C48 */
extern s32 func_0011D534(void *, s32, s32);
extern s32 func_001487E8(void *, s32, void *);
extern s32 func_00148860(void *, s32, s32, s32);
extern s32 func_L39_00519468(s32);

typedef struct {
    u8 pad0[0x14];
    u8 f14[0x40];
    s32 f54;
} A_00519C48;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[4];
    s32 f14;
    s32 f18;
    u8 f1C[0x10];
    s32 f2C;
} B_00519C48;

s32 func_L39_00519C48(A_00519C48 *a, B_00519C48 *b) {
    s32 r;
    s32 k;

    if (b->fC != 0) {
        return 0;
    }
    if (b->f14 != 0 && b->f14 != 3) {
        return 0x80;
    }
    func_0011D534(b->f1C, 0, 0x10);
    b->f2C = 0;
    if (b->f18 == 0) {
        b->f18 = -1;
    }
    r = func_001487E8(a->f14, a->f54, &b->f14);
    if (r <= 0) {
        return func_L39_00519468(r);
    }
    k = a->f54;
    b->fC = r;
    r = func_00148860(a->f14, k, r, -1);
    if (r < 0) {
        return func_L39_00519468(r);
    }
    return 0;
}
/* localdecomp:end func_L39_00519C48 */

/* localdecomp:start func_L39_00519D08 */
/* log: callee s32 + s32 return: 89 diff (ee29). Key: retail's `move v0,v0` after the error calls = sign extension
   s32 -> long, so func_L39_00519D08 returns long; that also lets crossjump merge the error tails. */
typedef struct N_00519D08 { s32 p0[3]; s32 c; s32 p10; s32 f14; s32 pad[0x14]; s32 f68; } N_00519D08;
typedef struct P_00519D08 { s32 p0[5]; s32 f14[0x10]; s32 f54; s32 f58; } P_00519D08;
extern P_00519D08 *func_L39_005190E8(s32);
extern N_00519D08 *func_L39_00519388(s32);
extern s32 func_L39_005192A8(P_00519D08 *, s32);
extern void func_L39_005190C8(void);
extern s32 func_L39_00519058(void);
extern s32 func_L39_00519468(s32);
extern s32 func_1489B8(void *, s32, s32, s32, s32, s32 *, s32);
long func_L39_00519D08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    P_00519D08 *p;
    N_00519D08 *n;
    s32 r;
    s32 chunk;
    s32 total;
    s32 flag;

    total = 0;
    p = func_L39_005190E8(0);
    if (p == 0) return -1;
    n = func_L39_00519388(arg0);
    if (n == 0) return func_L39_005192A8(p, 9);
    if ((n->f14 == 0 || n->f14 == 3) && (u32)p->f58 < (u32)arg2) return func_L39_005192A8(p, 0x16);
    r = func_L39_00519C48((A_00519C48 *)p, (B_00519C48 *)n);
    if (r != 0) return func_L39_005192A8(p, r);
    if (arg3 & 1) flag = 2; else flag = 0;
    while (arg2 != 0) {
        chunk = (p->f58 < arg2) ? p->f58 : arg2;
        func_L39_005190C8();
        r = func_1489B8(p->f14, p->f54, n->c, arg1, chunk, &flag, n->f68);
        if (func_L39_00519058() < 0) return func_L39_005192A8(p, -1);
        if (r < 0) return func_L39_005192A8(p, func_L39_00519468(r));
        arg1 += r;
        arg2 -= r;
        total += r;
        if (r < chunk) break;
    }
    if (total == 0 && n->f68 >= 0) return func_L39_005192A8(p, 0xB);
    func_L39_005192A8(p, 0);
    return total;
}
/* localdecomp:end func_L39_00519D08 */

INCLUDE_ASM("asm/levels", func_L39_00519EB8);
