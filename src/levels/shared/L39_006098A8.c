#include "common.h"

/* localdecomp:start func_L39_006098A8 */
extern void func_1262A0(s32 a0);
extern void func_126280(s32 a0);

void func_L39_006098A8(s32 *a0, s32 *a1, s32 *a2, s32 *a3, s32 *a4) {
    s32 pos, left;
    func_1262A0(a0[16]);
    left = (s32)((long)a0[2] - (long)(a0[4]+2)) * 2048 - a0[5];
    pos = ((a0[3] + a0[4]) * 2048 + a0[5]) % a0[6];
    if (left <= a0[6]-pos) {
        *a1 = a0[0]+pos;
        *a2 = left;
        *a3 = 0;
        *a4 = 0;
    } else {
        *a1 = a0[0]+pos;
        *a2 = a0[6]-pos;
        *a3 = a0[0];
        *a4 = left - (a0[6]-pos);
    }
    func_126280(a0[16]);
}
/* localdecomp:end func_L39_006098A8 */

INCLUDE_ASM("asm/levels", func_L39_00609998);

INCLUDE_ASM("asm/levels", func_L39_006099F0);

/* localdecomp:start func_L39_00609BD8 */
extern void func_1262A0(int);
extern void func_126280(int);
extern void func_L39_00609638(int);
extern void func_L39_006095C8(int);

int func_L39_00609BD8(int *p)
{
    func_1262A0(p[16]);
    p[17] = 0;
    func_L39_00609638(5);
    p[7] = *(volatile int *)0x1000B410;
    p[8] = *(volatile int *)0x1000B430;
    p[9] = *(volatile int *)0x1000B420;
    p[10] = *(volatile int *)0x1000B400;
    if (*(volatile int *)0x10002010 & 0xF0)
        while (*(volatile int *)0x10002010 & 0xF0)
            ;
    func_L39_006095C8(0);
    p[11] = *(volatile int *)0x1000B010;
    p[12] = *(volatile int *)0x1000B020;
    p[13] = *(volatile int *)0x1000B000;
    p[14] = *(volatile int *)0x10002020;
    p[15] = *(volatile int *)0x10002010;
    func_126280(p[16]);
    return 1;
}
/* localdecomp:end func_L39_00609BD8 */

INCLUDE_ASM("asm/levels", func_L39_00609CE8);

INCLUDE_ASM("asm/levels", func_L39_00609FF8);

/* localdecomp:start func_L39_0060A050 */
void func_00126280(s32);
void func_001262A0(s32);

s32 func_L39_0060A050(void *arg0) {
    s32 temp_s1;

    func_001262A0((*(s32 *)((u8 *)arg0 + 0x40)));
    temp_s1 = ((*(s32 *)((u8 *)arg0 + 0x10)) << 0xB) + (*(s32 *)((u8 *)arg0 + 0x14));
    func_00126280((*(s32 *)((u8 *)arg0 + 0x40)));
    return temp_s1;
}
/* localdecomp:end func_L39_0060A050 */

INCLUDE_ASM("asm/levels", func_L39_0060A0A0);
