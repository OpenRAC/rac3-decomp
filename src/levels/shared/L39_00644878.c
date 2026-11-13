#include "common.h"

/* localdecomp:start func_L39_00644878 */
#include "vu0.h"
typedef int u128_00644878 __attribute__((mode(TI)));

extern u8 D_L39_004997E0[];
extern void func_0038D590(void *, void *);
extern void func_L01_00448E10(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern f32 func_L39_00644820(void *a0, f32 *a, f32 *b);

typedef struct {
    u128_00644878 row[3];
} M_00644878;

typedef struct {
    u8 pad0[0x2040];
    M_00644878 ring[16];
} G_00644878;

void func_L39_00644878(u8 *g, u8 *a1, void *a2, s32 a3)
{
    u128_00644878 acc[4];
    u32 buf[2];
    f32 score[16];
    u8 *p;
    s32 x;
    s32 n;
    s32 i, j;
    s32 k;
    s32 cnt;
    f32 max;
    long t;

    func_0038D590(g + 0x2040 + *(s32 *)(g + 0x2350) * 0x30, a2);
    func_L01_00448E10(g + 0x2040 + *(s32 *)(g + 0x2350) * 0x30);
    *(s32 *)(g + 0x2350) = (*(s32 *)(g + 0x2350) + 1) % 16;
    *(s32 *)(g + 0x2354) += 1;
    if (*(s32 *)(g + 0x2354) > 16) {
        *(s32 *)(g + 0x2354) = 16;
    }
    if (a3 == 0) {
        return;
    }
    for (j = 0; j < 3; j++) {
        qzero(&acc[j]);
    }
    p = g + 0x19E4;
    x = 0;
    t = *p;
    if (t != 0) {
        s32 m;
        s32 kk;
        s32 nn = *p;
        u8 *b;
        s32 q;
        m = nn + 1;
        kk = ((s32)p - nn) & 7;
        b = (u8 *)buf;
        for (q = 0; q < 40; q += 5) {
            *b++ = D_L39_004997E0[m + ((kk + q) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        x = buf[1];
    }
    if ((x ^ 2) == 0) {
        *(s32 *)(g + 0x24B4) = 5;
    } else {
        *(s32 *)(g + 0x24B4) = 11;
    }
    if (*(s32 *)(g + 0x24B4) > *(s32 *)(g + 0x24B0)) {
        *(s32 *)(g + 0x24B0) = *(s32 *)(g + 0x24B0) + 1;
    } else if (*(s32 *)(g + 0x24B4) < *(s32 *)(g + 0x24B0)) {
        *(s32 *)(g + 0x24B0) = *(s32 *)(g + 0x24B0) - 1;
    }
    n = *(s32 *)(g + 0x24B0);
    if (n < 2) {
        n = 2;
    }
    if (g[0x1A07] != 0 && *(s32 *)(g + 0x30C) < 8) {
        if (n > 3) {
            n = 3;
        }
    }
    if (*(s32 *)(g + 0x2354) < n) {
        return;
    }
    k = 0;
    for (i = 0; i < n; i++) {
        s32 r = (*(s32 *)(g + 0x2350) + 15 - i) % 16;
        for (j = 0; j < n; j++) {
            if (i != j) {
                s32 r2 = (*(s32 *)(g + 0x2350) + 15 - j) % 16;
                score[i] += func_L39_00644820(g, (f32 *)&((G_00644878 *)g)->ring[r], (f32 *)&((G_00644878 *)g)->ring[r2]);
            }
        }
    }
    max = 0.0f;
    for (i = 0; i < n; i++) {
        if (max < score[i]) {
            max = score[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (max * 0.2f < score[i]) {
            k++;
        }
    }
    cnt = 0;
    for (i = 0; i < n; i++) {
        if (!(max * 0.2f < score[i]) || k <= 0 || k >= 3) {
            s32 r = (*(s32 *)(g + 0x2350) + 15 - i) % 16;
            cnt++;
            for (j = 0; j < 3; j++) {
                vec_add_ab(&acc[j], &acc[j], &((G_00644878 *)g)->ring[r].row[j]);
            }
        }
    }
    for (j = 0; j < 3; j++) {
        func_0038CE20(&acc[j], &acc[j], 1.0f / (f32)cnt);
    }
    func_003C48A8(acc, a1 + 0xF0);
}
/* localdecomp:end func_L39_00644878 */
