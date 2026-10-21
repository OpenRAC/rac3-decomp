#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D6DD8 */
void func_003D6DD8(s32 *p, s32 n) { s32 t = *p; t = (t + 0x1FFF) & -0x2000; *p = t + n; }
/* localdecomp:end func_003D6DD8 */

/* localdecomp:start func_003D6DF8 */
void func_003D6DF8(long **pp, s32 x0, s32 y0, s32 x1, s32 y1, s32 z) {
    s32 n, step, i, d;
    unsigned long *p, *q;
    s32 x;
    d = x1 - x0;
    x = x0;
    n = d >> 9;
    step = d / n;
    p = (unsigned long *)*pp;
    *p = (unsigned long)(n | 0x8000) | 0x2400000000000000UL;
    p += 1;
    *pp = (long *)p;
    *p = 0x55;
    *pp = (long *)(p + 1);
    for (i = 0; i < n; i++) {
        q = (unsigned long *)*pp;
        *q = (unsigned long)x | ((long)y0 << 16) | ((long)z << 32);
        q += 1;
        *pp = (long *)q;
        x += step;
        *q = (unsigned long)x | ((long)y1 << 16) | ((long)z << 32);
        *pp = (long *)(q + 1);
    }
}
/* localdecomp:end func_003D6DF8 */

/* localdecomp:start func_003D6E98 */
void func_003D6E98(long **pp, s32 x0, s32 y0, s32 u0, s32 v0, s32 x1, s32 y1, s32 u1, s32 v1) {
    s32 n, dx, du, i;
    unsigned long *p, *q;
    s32 x, u, nu, nx;
    dx = x1 - x0;
    du = u1 - u0;
    x = x0;
    u = u0;
    n = dx >> 9;
    dx = dx / n;
    du = du / n;
    p = (unsigned long *)*pp;
    *p = (unsigned long)(n | 0x8000) | 0x4400000000000000UL;
    p += 1;
    *pp = (long *)p;
    *p = 0x5353;
    *pp = (long *)(p + 1);
    for (i = 0; i < n; i++) {
        q = (unsigned long *)*pp;
        *q = (unsigned long)u | ((long)v0 << 16);
        q += 1;
        *pp = (long *)q;
        *q = (unsigned long)x | ((long)y0 << 16);
        *pp = (long *)(q + 1);
        nu = u + du;
        *(q + 1) = (unsigned long)nu | ((long)v1 << 16);
        *pp = (long *)(q + 2);
        nx = x + dx;
        *(q + 2) = (unsigned long)nx | ((long)y1 << 16);
        *pp = (long *)(q + 3);
        u = nu;
        x = nx;
    }
}
/* localdecomp:end func_003D6E98 */
