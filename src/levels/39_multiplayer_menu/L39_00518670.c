#include "common.h"

/* localdecomp:start func_L39_00518670 */
typedef struct {
    u8 _p0[0x16];
    u8 f16;
} T_00518670;

extern u8 D_L39_00479A98[];
extern void *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);
extern void func_L39_005177C0(void *, s32, s32, u8 *, s32, s32, s32);

s32 func_L39_00518670(T_00518670 *a0, long v, u8 *buf) {
    s32 alloc;
    s32 neg;
    u32 u;
    u8 *p;
    s32 n;
    s32 i;

    a0->f16 &= ~4;
    if (v == 0) {
        func_L39_005177C0(a0, 0, 2, D_L39_00479A98, 1, 0, 0);
        return 0;
    }
    neg = 0;
    if (v < 0) {
        neg = 1;
        u = -v;
    } else {
        u = v;
    }
    alloc = 0;
    if (buf == 0) {
        buf = func_L39_004BEED8(8);
        if (buf == 0) {
            return 2;
        }
        alloc = 1;
    }
    func_0011D534(buf, 0, 8);
    n = 1;
    p = buf + 6;
    *p = u;
    while (u >= 0x80) {
        u >>= 8;
        p--;
        n++;
        *p = u;
    }
    for (i = 0; i < n; i++) {
        buf[i] = p[i];
    }
    if (neg) {
        buf[0] |= 0x80;
    }
    func_L39_005177C0(a0, 0, 2, buf, n, 0, alloc);
    return 0;
}
/* localdecomp:end func_L39_00518670 */
