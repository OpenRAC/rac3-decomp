#include "common.h"

/* localdecomp:start func_L39_00517120 */
typedef struct { char _p0[4]; s32 f4; } S4_00517120;
typedef struct { char _p0[4]; S4_00517120 *f4; char _p8[0x38]; s32 *f40; } S_00517120;
extern s32 func_L39_0050C5A8(void *);
extern void func_L39_00517510(void *, s32);
void func_L39_00517120(S_00517120 *a0) {
    s32 v;
    a0->f4->f4 = 0;
    if (func_L39_0050C5A8(a0) != 0) {
        return;
    }
    v = a0->f4->f4;
    if (v != 0) {
        a0->f40[0] = v;
    }
    func_L39_00517510(a0, 1);
}
/* localdecomp:end func_L39_00517120 */

/* localdecomp:start func_L39_00517180 */
typedef struct { char _p0[4]; s32 f4; } S4_00517180;
typedef struct { char _p0[4]; S4_00517180 *f4; char _p8[0x38]; s32 *f40; } S_00517180;
extern s32 func_L39_0050C5F8(void *);
extern void func_L39_00517510(void *, s32);
void func_L39_00517180(S_00517180 *a0) {
    s32 v;
    a0->f4->f4 = 0;
    if (func_L39_0050C5F8(a0) != 0) {
        return;
    }
    v = a0->f4->f4;
    if (v != 0) {
        a0->f40[1] = v;
    }
    func_L39_00517510(a0, 0);
}
/* localdecomp:end func_L39_00517180 */

/* localdecomp:start func_L39_005171E0 */
typedef struct {
    char _p0[0x30];
    u8 *buf;
    s32 f34;
    u32 used;
    u32 cap;
} S_005171E0;
extern void *func_L39_004F7510(void *, void *, u32);

s32 func_L39_005171E0(S_005171E0 *p, s32 a1, s32 *out, s32 a3, void *src, u32 n) {
    *out = 0;
    if (p->used + n > p->cap) {
        return 0x20D;
    }
    func_L39_004F7510(p->buf + p->used, src, n);
    p->used += n;
    return 0;
}
/* localdecomp:end func_L39_005171E0 */

/* localdecomp:start func_L39_00517250 */
typedef struct {
    char _p0[0x30];
    s32 f30;
    s32 f34;
    s32 f38;
    char _p3C[4];
    s32 (**vt)(void *, s32, s32);
} S_00517250;

extern s32 func_L39_0050C648(S_00517250 *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L39_0050C6D8(S_00517250 *, s32, s32 *, s32, s32, s32);

s32 func_L39_00517250(S_00517250 *p, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 buf[2];
    s32 e1;
    s32 e2;
    s32 e3;
    e1 = (*p->vt)(p, a4, a5);
    if (e1 != 0) {
        return e1;
    }
    e2 = func_L39_0050C648(p, a1, a2, a3, p->f30, p->f34, 0, a5);
    if (e2 != 0) {
        return e2;
    }
    e3 = func_L39_0050C6D8(p, 0, buf, 0, 0, a5);
    if (e3 == 0) {
        p->f38 = 0;
    }
    return e3;
}
/* localdecomp:end func_L39_00517250 */

INCLUDE_ASM("asm/levels", func_L39_00517308);

INCLUDE_ASM("asm/levels", func_L39_00517408);

INCLUDE_ASM("asm/levels", func_L39_00517510);
