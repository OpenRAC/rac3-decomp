#include "common.h"

/* NTSC-U counterpart of func_L39_0058ACE0 (src/levels/shared/L39_0058A5D0.c) */
extern u32 *D_L39_0024CBD0;
extern u32 *D_L39_0024CBD0_b;

/* localdecomp:start func_L39_00589B10 */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L39_0024BAE0_00589B10, 4");
extern s32 D_L39_0024BAE0_00589B10;
__asm__(".extern D_L39_0024CBD0_00589B10, 4");
extern u32 *D_L39_0024CBD0_00589B10;
extern s32 D_L39_0024BADC;
extern s32 D_L39_0024BAE0;
extern s32 D_L39_0024BAE0_b;
extern u8 D_001A5A3D __attribute__((section(".data")));
extern u128_t D_L39_002445A0;
extern u128_t D_L39_002445B0;
extern s32 D_L39_00240490;
extern s32 D_L39_00240494;
extern s32 D_L39_00240498;
extern s32 D_L39_0024049C;

void func_L39_00589B10(void) {
    s32 x;
    u32 *tmp;
    u32 *p;
    long *tmp2;
    long *q;
    long *n;
    long *q2;
    if (D_L39_0024BADC != 0) {
        if (D_L39_0024BAE0_00589B10 < 0x34) {
            D_L39_0024BAE0_00589B10++;
        }
    } else {
        if (D_L39_0024BAE0 == 0) return;
        D_L39_0024BAE0_b = D_L39_0024BAE0 - 1;
    }
    x = D_L39_0024BAE0;
    if (x == 0) return;
    if (D_001A5A3D != 0) return;
    D_L39_0024CBD0_00589B10[0] = 0x10000007;
    D_L39_0024CBD0[1] = 0;
    D_L39_0024CBD0[2] = 0;
    D_L39_0024CBD0[3] = 0x50000007;
    p = D_L39_0024CBD0;
    D_L39_0024CBD0_b = p + 4;
    *(u128_t *)(p + 4) = D_L39_002445A0;
    *(short *)D_L39_0024CBD0 = -0x7FFF;
    q2 = (long *)D_L39_0024CBD0;
    tmp2 = q2 + 2;
    n = tmp2;
    D_L39_0024CBD0_b = (u32 *)n;
    q2[2] = 0x104;
    n[1] = 0x80000000L;
    tmp = D_L39_0024CBD0;
    p = tmp;
    D_L39_0024CBD0_b = p + 4;
    *(u128_t *)(p + 4) = D_L39_002445B0;
    *(short *)D_L39_0024CBD0 = -0x7FF8;
    q = (long *)D_L39_0024CBD0;
    n = q + 2;
    D_L39_0024CBD0_b = (u32 *)n;
    q[2] = (long)D_L39_00240490 | ((long)D_L39_00240494 << 16) | 0xFFFFF300000000L;
    n[1] = (long)D_L39_00240490 | ((long)(D_L39_00240494 + (x << 4)) << 16) | 0xFFFFF300000000L;
    n[2] = (long)D_L39_00240498 | ((long)D_L39_00240494 << 16) | 0xFFFFF300000000L;
    n[3] = (long)D_L39_00240498 | ((long)(D_L39_00240494 + (x << 4)) << 16) | 0xFFFFF300000000L;
    n[4] = (long)D_L39_00240498 | ((long)D_L39_0024049C << 16) | 0xFFFFF300000000L;
    n[5] = (long)D_L39_00240498 | ((long)(D_L39_0024049C - (x << 4)) << 16) | 0xFFFFF300000000L;
    n[6] = (long)D_L39_00240490 | ((long)D_L39_0024049C << 16) | 0xFFFFF300000000L;
    n[7] = (long)D_L39_00240490 | ((long)(D_L39_0024049C - (x << 4)) << 16) | 0xFFFFF300000000L;
    D_L39_0024CBD0_b = D_L39_0024CBD0 + 0x10;
}
/* localdecomp:end func_L39_00589B10 */
