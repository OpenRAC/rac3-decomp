#include "common.h"

/* localdecomp:start func_L39_0059D6B0 */
__asm__(".extern D_L39_0024CAD0, 16");
extern int *D_L39_0024CAD0;
extern int *D_L39_0024CAD0_sda;
extern void func_00139EA0(void *, short, short, int, int, int, short, short);
extern void func_001264E0(int);
extern void func_0013A1C8(void *, int);

void func_L39_0059D6B0(int a0, int a1, int a2, int a3, int a4, int a5)
{
    char buf[96];
    void *work;
    int t4;
    int s2;
    s2 = 1 << (a3 + a4 - 4);
    t4 = (1 << a3) >> 6;
    if (t4 <= 0)
        t4 = 1;
    if (a5 == 0) {
        D_L39_0024CAD0[0] = 0x10000006;
        D_L39_0024CAD0[1] = 0;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000006;
        work = D_L39_0024CAD0 + 4;
        D_L39_0024CAD0_sda = D_L39_0024CAD0 + 28;
    } else {
        work = buf;
    }
    func_00139EA0(work, (short)a1, (short)t4, (short)a2, 0, 0,
            (short)(1 << a3), (short)(1 << a4));
    if (a5 == 0) {
        D_L39_0024CAD0_sda[0] = 0x30000000 | s2;
        D_L39_0024CAD0[1] = a0;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000000 | s2;
        D_L39_0024CAD0_sda = D_L39_0024CAD0 + 4;
    } else {
        func_001264E0(0);
        func_0013A1C8(work, a0);
    }
}
/* localdecomp:end func_L39_0059D6B0 */

LINKER_REMNANT("asm/levels", func_L39_0059D820);
