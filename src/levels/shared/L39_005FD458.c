#include "common.h"

/* localdecomp:start func_L39_005FD458 */
#include "vu0.h"
/* from boot_elf's func_003A9BE8 */
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_0024CAD0_b, 4");
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
extern void func_00139EA0(void *, short, short, int, int, int, short, short);

unsigned long func_L39_005FD458(u32 src, s32 dst, s32 w, s32 h) {
    s32 n;
    s32 lw;
    s32 lh;
    s32 step;
    s32 off;
    s32 t, t2, t3;

    t = plzcw_asm(w);
    lw = 30 - t;
    if (w & (w - 1)) lw++;
    step = w << 7;
    t2 = plzcw_asm(h);
    lh = 30 - t2;
    if (h & (h - 1)) lh++;
    n = w * (h << 2);
    t3 = n - 1;
    n = (t3 + step) & -step;
    for (off = 0; n > 0; off += step) {
        D_L39_0024CAD0[0] = 0x10000006;
        D_L39_0024CAD0[1] = 0;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000006;
        n -= step;
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;
        func_00139EA0(D_L39_0024CAD0_b, (dst + off) >> 8, w >> 6, 0, 0, 0, w, 32);
        D_L39_0024CAD0 += 0x18;
        D_L39_0024CAD0[0] = 0x30000000 | (step >> 4);
        D_L39_0024CAD0[1] = src + off;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000000 | (step >> 4);
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;
    }
    return (unsigned long)(dst >> 8) | ((unsigned long)(w >> 6) << 14) | ((unsigned long)lw << 26) | ((unsigned long)lh << 30) | ((unsigned long)1 << 34);
}
/* localdecomp:end func_L39_005FD458 */

/* localdecomp:start func_L39_005FD668 */
extern s32 D_L39_0024CAE8;
extern s32 D_L39_0024CAEC;
__asm__(".extern D_L39_0024CAE8, 16");
__asm__(".extern D_L39_0024CAEC, 16");
extern void func_003A9B40(void);
extern void func_003A9C40(void);
extern s32 func_00125F70(s32, void (*)(void), s32);
extern void func_00126E38(s32);

void func_L39_005FD668(void)
{
    if (D_L39_0024CAE8 == 0 && D_L39_0024CAEC == 0) {
        if ((*(volatile u32 *)0x1000E010 & 0x20000) == 0) { /* D_STAT */
            *(u32 *)0x1000E010 = 0x20000;
        }
        D_L39_0024CAE8 = func_00125F70(1, func_003A9B40, 0);
        D_L39_0024CAEC = func_00125F70(0xF, func_003A9C40, 0);
        func_00126E38(1);
    }
}
/* localdecomp:end func_L39_005FD668 */
