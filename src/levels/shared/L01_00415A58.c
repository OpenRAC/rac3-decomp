#include "common.h"

/* localdecomp:start func_L01_00415A58 */
extern int *D_L01_001E1068;
extern void func_003A9440(unsigned int, unsigned long);
extern void func_L01_004C5B48(int);
/* from rac2-decomp's func_00285548 */
void func_L01_00415A58(int x0, int y0, int x1, int y1, int w, int h, unsigned int rgba) {
    long *q;
    int ax, ay, bx, by;
    int hw, hh;
    func_L01_004C5B48(0x13000000);
    func_003A9440(0x42, 0x64);
    *(int *)((char *)D_L01_001E1068 + 0) = 0x10000006;
    *(int *)((char *)D_L01_001E1068 + 4) = 0;
    *(int *)((char *)D_L01_001E1068 + 8) = 0;
    *(int *)((char *)D_L01_001E1068 + 12) = 0x50000006;
    ax = (x0 << 4) + 0x8000;
    ay = (y0 << 4) + 0x8000;
    bx = (x1 << 4) + 0x8000;
    by = (y1 << 4) + 0x8000;
    hw = w << 3;
    hh = h << 3;
    D_L01_001E1068 += 4;
    q = (long *)D_L01_001E1068;
    *(long *)((char *)q + 0) = 0x1000000000000001L;
    *(long *)((char *)q + 8) = 0xE;
    *(long *)((char *)q + 16) = 0x33003;
    *(long *)((char *)q + 24) = 0x47;
    *(long *)((char *)q + 32) = 0x2400000000000001L;
    *(long *)((char *)q + 40) = 0x10;
    *(long *)((char *)q + 48) = 0x106;
    *(long *)((char *)q + 56) = rgba;
    *(long *)((char *)q + 64) = 0x2400000000008001L;
    *(long *)((char *)q + 72) = 0x44;
    {
        long X1 = bx - hw;
        long X0 = ax - hw;
        long Y0 = ay - hh;
        long Y1 = by - hh;
        *(long *)((char *)q + 80) = X0 | (Y0 << 16);
        *(long *)((char *)q + 88) = X1 | (Y1 << 16);
    }
    D_L01_001E1068 += 0x18;
    func_003A9440(0x42, 0x8000000044L);
    func_L01_004C5B48(0x13000000);
}
/* localdecomp:end func_L01_00415A58 */

INCLUDE_ASM("asm/levels", func_L01_00415C18);

/* localdecomp:start func_L01_00415C98 */
extern int D_L01_001EA6C0[];

void func_L01_00415C98(int a0, int a1)
{
    int x = 64;
    int y = 16;
    if (a0) x = a0;
    if (a1) y = a1;
    D_L01_001EA6C0[35] = x;
    D_L01_001EA6C0[36] = y;
}
/* localdecomp:end func_L01_00415C98 */

/* localdecomp:start func_L01_00415CC0 */
extern s32 D_L01_001D655C;
s32 func_L01_00415CC0(void) {
    return D_L01_001D655C;
}
/* localdecomp:end func_L01_00415CC0 */
