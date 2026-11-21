#include "common.h"

/* declared by functions of L39_00517120.c, which this file was cut from */
extern void func_L39_00517510(void *, s32);
extern void *func_L39_004F7510(void *, void *, u32);

/* localdecomp:start func_L39_00517308 */
typedef struct {
    char _p0[0x30];
    s32 f30;
    u32 f34;
    s32 f38;
    char _p3C[4];
    s32 (**vt)(void *, s32 *, s32);
} S_00517308;

extern s32 func_L39_0050C690(void *, s32, s32 *, s32, s32, s32, s32, s32);
extern s32 func_L39_0050C720(void *, s32, s32 *, s32, s32, s32);
extern void *func_L39_004F7510(void *, void *, u32);

s32 func_L39_00517308(S_00517308 *p, void *dst, u32 *len, u32 max, s32 a4, s32 a5) {
    s32 hdr[2];
    s32 x;
    s32 y;
    s32 r;

    r = func_L39_0050C690(p, p->f30, &x, p->f34, p->f30, p->f38, 0, a5);
    if (r != 0) {
        return r;
    }
    r = func_L39_0050C720(p, 0, &y, 0, 0, a5);
    if (r != 0) {
        return r;
    }
    p->f38 = 0;
    r = p->vt[1](p, hdr, x);
    if (r != 0) {
        return r;
    }
    if ((u32)hdr[1] > p->f34 - 11) {
        return 0x20C;
    }
    *len = hdr[1];
    if ((u32)hdr[1] > max) {
        return 0x218;
    }
    func_L39_004F7510(dst, (void *)hdr[0], hdr[1]);
    return 0;
}
/* localdecomp:end func_L39_00517308 */

/* localdecomp:start func_L39_00517408 */
typedef struct {
    s32 ptr;
    u32 len;
} S_00517408;

typedef struct {
    s32 f0;
    s32 (*f4)(void *, S_00517408 *, s32);
} V_00517408;

typedef struct {
    u8 _p0[0x30];
    s32 f30;
    u32 f34;
    s32 f38;
    s32 f3C;
    V_00517408 *f40;
} T_00517408;

extern s32 func_L39_0050C690(void *, s32, s32 *, s32, s32, s32, s32, s32);
extern s32 func_L39_0050C720(void *, s32, s32 *, s32, s32, s32);
extern void *func_L39_004F7510(void *, void *, u32);

s32 func_L39_00517408(T_00517408 *p, void *buf, u32 *len, u32 max, s32 a4, s32 a5) {
    S_00517408 hdr;
    s32 n;
    s32 m;
    s32 r;

    n = *len;
    r = func_L39_0050C690(p, (s32)buf, &n, p->f34, p->f30, p->f38, 0, a5);
    if (r != 0) {
        return r;
    }
    func_L39_004F7510((void *)p->f30, buf, n);
    r = func_L39_0050C720(p, 0, &m, 0, 0, a5);
    if (r != 0) {
        return r;
    }
    p->f38 = 0;
    r = p->f40->f4(p, &hdr, n);
    if (r != 0) {
        return r;
    }
    if (hdr.len > p->f34 - 11) {
        return 0x20C;
    }
    *len = hdr.len;
    if (hdr.len > max) {
        return 0x218;
    }
    func_L39_004F7510(buf, (void *)hdr.ptr, hdr.len);
    return 0;
}
/* localdecomp:end func_L39_00517408 */

INCLUDE_ASM("asm/levels", func_L39_00517510);
