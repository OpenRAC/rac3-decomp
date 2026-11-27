/* func_L39_0058ACE0: matches in level 39 but differs at +0x2C in the multiplayer maps (levels 40-52): their copy needs its own row (config/levels/split_places.tsv) (reverted from src/levels/shared/L39_0058A5D0.c, 2026-11-27). */
#include "common.h"
/* localdecomp:start func_L39_0058ACE0 */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L39_0024B9E0_0058ACE0, 4");
extern s32 D_L39_0024B9E0_0058ACE0;
__asm__(".extern D_L39_0024CAD0_0058ACE0, 4");
extern u32 *D_L39_0024CAD0_0058ACE0;
extern s32 D_L39_0024B9DC;
extern s32 D_L39_0024B9E0;
extern s32 D_L39_0024B9E0_b;
extern u8 D_1A58BD __attribute__((section(".data")));
extern u128_t D_L39_00244420;
extern u128_t D_L39_00244430;
extern s32 D_L39_00240310;
extern s32 D_L39_00240314;
extern s32 D_L39_00240318;
extern s32 D_L39_0024031C;

void func_L39_0058ACE0(void) {
    s32 x;
    u32 *tmp;
    u32 *p;
    long *tmp2;
    long *q;
    long *n;
    long *q2;
    if (D_L39_0024B9DC != 0) {
        if (D_L39_0024B9E0_0058ACE0 < 0x34) {
            D_L39_0024B9E0_0058ACE0++;
        }
    } else {
        if (D_L39_0024B9E0 == 0) return;
        D_L39_0024B9E0_b = D_L39_0024B9E0 - 1;
    }
    x = D_L39_0024B9E0;
    if (x == 0) return;
    if (D_1A58BD != 0) return;
    D_L39_0024CAD0_0058ACE0[0] = 0x10000007;
    D_L39_0024CAD0[1] = 0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000007;
    p = D_L39_0024CAD0;
    D_L39_0024CAD0_b = p + 4;
    *(u128_t *)(p + 4) = D_L39_00244420;
    *(short *)D_L39_0024CAD0 = -0x7FFF;
    q2 = (long *)D_L39_0024CAD0;
    tmp2 = q2 + 2;
    n = tmp2;
    D_L39_0024CAD0_b = (u32 *)n;
    q2[2] = 0x104;
    n[1] = 0x80000000L;
    tmp = D_L39_0024CAD0;
    p = tmp;
    D_L39_0024CAD0_b = p + 4;
    *(u128_t *)(p + 4) = D_L39_00244430;
    *(short *)D_L39_0024CAD0 = -0x7FF8;
    q = (long *)D_L39_0024CAD0;
    n = q + 2;
    D_L39_0024CAD0_b = (u32 *)n;
    q[2] = (long)D_L39_00240310 | ((long)D_L39_00240314 << 16) | 0xFFFFF300000000L;
    n[1] = (long)D_L39_00240310 | ((long)(D_L39_00240314 + (x << 4)) << 16) | 0xFFFFF300000000L;
    n[2] = (long)D_L39_00240318 | ((long)D_L39_00240314 << 16) | 0xFFFFF300000000L;
    n[3] = (long)D_L39_00240318 | ((long)(D_L39_00240314 + (x << 4)) << 16) | 0xFFFFF300000000L;
    n[4] = (long)D_L39_00240318 | ((long)D_L39_0024031C << 16) | 0xFFFFF300000000L;
    n[5] = (long)D_L39_00240318 | ((long)(D_L39_0024031C - (x << 4)) << 16) | 0xFFFFF300000000L;
    n[6] = (long)D_L39_00240310 | ((long)D_L39_0024031C << 16) | 0xFFFFF300000000L;
    n[7] = (long)D_L39_00240310 | ((long)(D_L39_0024031C - (x << 4)) << 16) | 0xFFFFF300000000L;
    D_L39_0024CAD0_b = D_L39_0024CAD0 + 0x10;
}
/* localdecomp:end func_L39_0058ACE0 */
