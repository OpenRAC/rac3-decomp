#include "common.h"

/* localdecomp:start func_L39_0058B9F8 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L39_0024CAD0;
__asm__(".extern D_L39_0024CAD0, 16");
extern u8 D_L39_00244440[];
extern s32 D_L39_00240310;
extern s32 D_L39_00240314;
__asm__(".extern D_L39_00240310, 16");
__asm__(".extern D_L39_00240314, 16");

/* from rac2-decomp's func_0027E018 (float x/y/w/h variant) */
void func_L39_0058B9F8(s32 x, s32 y, s32 w, s32 h, unsigned long rgba, unsigned long tex, f32 fx, f32 fy, f32 fw, f32 fh) {
    int x0 = (s32)(fx * 16.0f) + D_L39_00240310 - 8;
    int yt = (s32)(fy * 16.0f) + D_L39_00240314;
    int yb = (s32)((fy + fh) * 16.0f) + D_L39_00240314;
    int x1 = (s32)((fx + fw) * 16.0f) + D_L39_00240310 - 8;
    int s1 = (x + w) * 16;
    int s0 = x * 16;
    int y0 = yt - 8;
    int y1 = yb - 8;
    int vb = y + h;
    long *p;
    int *base;

    ((int *)D_L39_0024CAD0)[0] = 0x10000007;
    ((int *)D_L39_0024CAD0)[1] = 0;
    ((int *)D_L39_0024CAD0)[2] = 0;
    ((int *)D_L39_0024CAD0)[3] = 0x50000007;
    base = (int *)D_L39_0024CAD0;
    D_L39_0024CAD0 += 16;
    *(u128_t *)(base + 4) = *(u128_t *)D_L39_00244440;
    p = (long *)(D_L39_0024CAD0 + 16);
    D_L39_0024CAD0 = (s32)p;
    p[0] = tex;
    p[1] = 0x154;
    p[2] = rgba;
    p[3] = (y << 20) + s0;
    p[4] = x0 | ((long)y0 << 16) | ((long)0xFFFFF0 << 32);
    p[5] = (y << 20) + s1;
    p[6] = x1 | ((long)y0 << 16) | ((long)0xFFFFF0 << 32);
    p[7] = (vb << 20) + s0;
    p[8] = x0 | ((long)y1 << 16) | ((long)0xFFFFF0 << 32);
    p[9] = (vb << 20) + s1;
    p[10] = x1 | ((long)y1 << 16) | ((long)0xFFFFF0 << 32);
    p[11] = 0;
    D_L39_0024CAD0 += 0x60;
}
/* localdecomp:end func_L39_0058B9F8 */
