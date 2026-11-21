#include "common.h"

/* localdecomp:start func_L39_0066CB78 */
typedef union {
    u8 b[8];
    u32 w[2];
} U_0066CB78;
typedef struct { s32 f0; s32 f4; } O_0066CB78;
typedef struct { u8 p0[0x19E4]; u8 b19E4; u8 p19E5[0x2558 - 0x19E5]; O_0066CB78 *f2558; } P_0066CB78;
extern P_0066CB78 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern u8 D_L39_004997E0[];

static __inline__ u32 Dec_0066CB78(u8 *q) {
    U_0066CB78 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ s32 DecEq_0066CB78(u8 *q, s32 v) {
    return Dec_0066CB78(q) == v;
}

s32 func_L39_0066CB78(void *a0) {
    u32 r;
    u32 v;
    s32 cnt = -1;
    s32 n = 0;
    s32 i;
    u8 ok;

    r = *(u32 *)a0;
    v = r & 0xFFF;
    if ((r & 0xF0000000) != 0xF0000000) {
        v += r >> 28;
    }
    for (i = 0; i < 8; i++) {
        P_0066CB78 *p = D_L39_0024CE20[i];
        if (p != 0) {
            if ((ok = !DecEq_0066CB78(&p->b19E4, 0x92) && p->f2558 != 0 && p->f2558->f4 != 0)) {
                n++;
            }
        }
    }
    v = v % n;
    for (i = 0; i < 8; i++) {
        P_0066CB78 *p = D_L39_0024CE20[i];
        if (p != 0) {
            if ((ok = !DecEq_0066CB78(&p->b19E4, 0x92) && p->f2558 != 0 && p->f2558->f4 != 0)) {
                cnt++;
                if (cnt == v) {
                    break;
                }
            }
        }
    }
    return D_L39_0024CE20[i]->f2558->f0;
}
/* localdecomp:end func_L39_0066CB78 */
